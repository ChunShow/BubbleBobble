#include "main.h"

clock_t endTime;

Idle::Idle() {};

void Idle::operate()
{
	endTime = clock();
	if (endTime - startTime > 1000 / 30) {
		if (!gamestart) {
			idleGamestart();
			idlePlayer();
		}
		if (gameover) {
			idleGameover();
		}
		else {
			idleBoard();
			if (!clear) {
				idleItem();
				idlePlayer();
				idleBubbleAlive();
				idleMonster();
				idleBubble();
				idleExplosion();
			}
			else {
				idleStageClear();
			}
		}
		startTime = endTime;
		glutPostRedisplay();
	}
}

void Idle::idleBoard() {
	board.addScoreByTime();
}

void Idle::idleItem()
{
	if (endTime - lastItemCreationTime > 5000) {
		srand((int)clock());
		float x = 1.6 * (float)rand() / RAND_MAX - 0.8; float y = 1.6 * (float)rand() / RAND_MAX - 0.8;
		Item item(ITEM_TYPE(rand() % 5), x, y);
		items.push_back(item);
		lastItemCreationTime = endTime;
	}

	for (auto& item : items) { //controls item position
		float yBottom = item.getPositionY() - item.getSize();
		float xCenter = item.getPositionX();

		bool falling = true;

		for (const auto& border : stages.getBorder()) {
			float borderLeft = border[0]; float borderRight = borderLeft + border[2]; float borderTop = border[1];
			bool xInclude = (borderLeft < xCenter && xCenter < borderRight);
			bool ySupporting = (borderTop - 0.04 < yBottom && yBottom <= borderTop+0.0001f);

			if (xInclude && ySupporting) {
				falling = false;
				item.setPositionY(borderTop + item.getSize());
			}
		}

		if (falling) {
			item.translate(0.0f, -0.01f);
		}
	}

	for (auto& item : items) { //controls getting item and effect of the item
		if (item.collisionDetection(player)) {
			item.makeAchived();
		}

		if (item.isEffective()) { // enable item effect

			if (!item.isDisposable()) {
				switch (item.getType()) { //deals non-disposable items
				case SPEED:
					player.setSpeedScale(1.5f);
					break;
				case DOUBLE:
					player.onDoubleShot();
					break;
				case RAPID:
					player.setDelay(150.0f);
					break;
				}
			}
			else {
				switch (item.getType()) {
				case HEART:
					player.increaseLife();
					break;
				case SCORE:
					board.addScore(10);
					break;
				}
				item.release(); // disable the disposable item
			}
		}
		if (item.isEffectFinished()) { // disable item effect
			switch (item.getType()) {
			case SPEED:
				player.setSpeedScale(1.0f);
				break;
			case DOUBLE:
				player.offDoubleShot();
				break;
			case RAPID:
				player.setDelay(300.0f);
				break;
			}
		}
	}
}

void Idle::idlePlayer()
{
	float scale = player.getSpeedScale();
	float xSpeedGround = 0.025f * scale;
	float xSpeedFall = 0.015f * scale;

	if (keystates[KEY::LEFT]) {
		//  case of player's direction changes from RIGHT to LEFT
		if (player.getDirection() == KEY::RIGHT) player.setDirection(KEY::LEFT);
		else {
			if (player.getState() == FALL) player.translate(-xSpeedFall, 0.0f);
			else player.translate(-xSpeedGround, 0.0f);
			stages.checkLEFT();
		}
	}
	if (keystates[KEY::RIGHT]) {
		//  case of player's direction changes from LEFT to RIGHT
		if (player.getDirection() == KEY::LEFT) player.setDirection(KEY::RIGHT);
		else {
			if (player.getState() == FALL) player.translate(xSpeedFall, 0.0f);
			else player.translate(xSpeedGround, 0.0f);
			stages.checkRIGHT();
		}
	}
	if (keystates[KEY::DOWN]) {
		// case of player's state is JUMP or FALL
		if (player.getState() != STAY) {
			player.setState(FALL);
			player.translate(0.0f, -0.01f);
		}
	}
	if (keystates[KEY::SPACEBAR] && (endTime - lastBubbleCreationTime) > player.getDelay()) {
		Bubble bubble1 = player.shoot();
		bubble_total_num += 1;
		bubbles.insert(make_pair(bubble_total_num, bubble1));

		if (player.isDoubleShot()) {
			Bubble bubble2 = player.shoot();
			bubble2.setDirection((player.getDirection() == LEFT) ? D_RIGHT : D_LEFT);
			bubble_total_num += 1;
			bubbles.insert(make_pair(bubble_total_num, bubble2));
		}

		lastBubbleCreationTime = endTime;
	}

	if (player.getState() == STAY) {
		if (stages.checkFALL()) {
			player.setState(FALL);
		}
	}
	else if (player.getState() == JUMP) {
		if (player.getVelocityY() > 0) {
			player.setVelocityY(player.getVelocityY() - 0.008f);
			player.translate(0.0f, player.getVelocityY());
			stages.checkJUMP();
		}
		else {
			player.translate(0.0f, -0.01f);
			player.setState(FALL);
		}
	}
	else if (player.getState() == FALL) {
		if (stages.checkFALL()) {
			player.translate(0.0f, -0.01f);
		}
	}
	player.updatePosition();
}

void Idle::idleBubbleAlive()
{
	for (auto& pair : bubbles) {
		Bubble& bubble = pair.second;
		if (!bubble.isGrown()) continue;
		if (bubble.collisionDetection(player)) {
			bubble.alive = false;
		}
	}
}

void Idle::idleMonster()
{
	for (auto& monster : monsters) {
		if (monster.isTrapped()) {
			Bubble& bubble = bubbles[monster.getTrappedBubble()];

			if (!bubble.alive && !(clock() - bubble.createdTime > 5000)) {
				board.addScore(30);
				monster.kill();
			}
			else if (clock() - bubble.createdTime > 5000) {
				monster.free();
				bubble.alive = false;
			}

			float bubble_x = bubble.getPositionX(); float bubble_y = bubble.getPositionY();
			monster.setPosition(bubble_x - bubble.max_radius, bubble_y - bubble.max_radius);
			continue;
		}

		switch (monster.getDirection()) {
		case(LEFT):
			if (stages.checkMonster(monster)) monster.translate(-0.015f, 0.0f);
			else {
				monster.setDirection(RIGHT);
				monster.translate(0.015f, 0.0f);
			}
			break;
		case(RIGHT):
			if (stages.checkMonster(monster)) monster.translate(0.015f, 0.0f);
			else {
				monster.setDirection(LEFT);
				monster.translate(-0.015f, 0.0f);
			}
			break;
		case(DOWN):
			if (stages.checkMonster(monster)) monster.translate(0.0f, -0.015f);
			else {
				monster.setDirection(LEFT);
			}
			break;
		}
		monster.updatePosition();
	}
}

void Idle::idleBubble()
{
	for (auto& pair : bubbles) {
		Bubble& bubble = pair.second;
		float speed = bubble.horizontal_speed;
		float size = bubble.size;

		bubble.grow();

		float x = bubble.getPositionX(); float y = bubble.getPositionY();
		if (bubble.direction == D_LEFT) bubble.translate(-speed, 0.0f);
		if (bubble.direction == D_RIGHT) bubble.translate(speed, 0.0f);
		if (bubble.direction == D_UP) bubble.translate(0.0f, speed * 0.1);
		if (bubble.mapCollision(stages.getBorderHard()) || bubble.isGrown()) bubble.direction = D_UP;

		if (bubble.getPositionX() < -1.0f) bubble.setPositionX(1.0f);
		if (bubble.getPositionX() > 1.0f) bubble.setPositionX(-1.0f);
		if (bubble.getPositionY() > 1.0f) bubble.setPositionY(-1.0f);

		for (auto& monster : monsters) {
			if (bubble.collisionDetection(monster) && !monster.isTrapped() && !bubble.isGrown()) {
				bubble.size = 1.0f;
				bubble.mapCollision(stages.getBorderHard());
				bubble.direction = D_UP;
				bubble.trapping = true;
				monster.trap(pair.first);
			}
		}
		if (clock() - bubble.createdTime > 5000) {
			bubble.alive = false;
		}
	}
}

void Idle::idleExplosion()
{
	for (auto& exps : explosions) {
		exps.increase(0.05f);
	}
}

void Idle::idleStageClear()
{
	if (stages.getTime() >= 0.6f) player.initializePosition();
}

void Idle::idleGameover()
{
	if (keystates[KEY::RESTART]) {
		gameover = false;
		restarted = true;
	}
}

void Idle::idleGamestart()
{
	board.reset();
	if (keystates[KEY::SPACEBAR]) {
		gamestart = true;
	}
}