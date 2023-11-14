#include "main.h"

clock_t endTime;

Idle::Idle() {};

void Idle::operate()
{
	endTime = clock();
	if (endTime - startTime > 1000 / 30) {
		if (!clear) {
			idlePlayer();
			idleBubbleAlive();
			idleMonster();
			idleBubble();
		}
		else {
			idleClear();
		}
		startTime = endTime;
		glutPostRedisplay();
	}
}

void Idle::idlePlayer()
{
	if (keystates[KEY::LEFT]) {
		//  case of player's direction changes from RIGHT to LEFT
		if (player.getDirection() == KEY::RIGHT) player.setDirection(KEY::LEFT);
		else {
			if (player.getState() == FALL) player.translate(-0.015f, 0.0f);
			else player.translate(-0.025f, 0.0f);
			stages[level].checkLEFT();
		}
	}

	if (keystates[KEY::RIGHT]) {
		//  case of player's direction changes from LEFT to RIGHT
		if (player.getDirection() == KEY::LEFT) player.setDirection(KEY::RIGHT);
		else {
			if (player.getState() == FALL) player.translate(0.015f, 0.0f);
			else player.translate(0.025f, 0.0f);
			stages[level].checkRIGHT();
		}
	}

	if (keystates[KEY::DOWN]) {
		// case of player's state is JUMP or FALL
		if (player.getState() != STAY) {
			player.setState(FALL);
			player.translate(0.0f, -0.01f);
		}
	}
	if (keystates[KEY::SPACEBAR] && (endTime - lastCreationTime) > 300) {

		Bubble bubble = player.shoot();
		bubbles.push_back(bubble);
		lastCreationTime = endTime;
	}

	if (player.getState() == STAY) {
		if (stages[level].checkFALL()) {
			player.setState(FALL);
		}
	}

	else if (player.getState() == JUMP) {
		if (player.getVelocityY() > 0) {
			player.setVelocityY(player.getVelocityY() - 0.008f);
			player.translate(0.0f, player.getVelocityY());
			stages[level].checkJUMP();
		}
		else {
			player.translate(0.0f, -0.01f);
			player.setState(FALL);
		}
	}

	else if (player.getState() == FALL) {
		if (stages[level].checkFALL()) {
			player.translate(0.0f, -0.01f);
		}
	}

	player.updatePosition();
	player.setFinalPosition();
}

void Idle::idleBubbleAlive()
{
	for (auto& bubble : bubbles) {
		if (!bubble.isGrown()) continue;
		if (bubble.collisionDetection(*playerPointer)) {
			bubble.alive = false;
		}
	}
}

void Idle::idleMonster()
{
	for (auto& monster : monsters) {
		if (monster.isTrapped()) {
			Bubble bubble = *monster.getTrappedBubble();

			if (!bubble.alive && !(clock() - bubble.createdTime > 5000)) {
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
			if (stages[level].checkMonster(monster)) monster.translate(-0.015f, 0.0f);
			else {
				monster.setDirection(RIGHT);
				monster.translate(0.015f, 0.0f);
			}
			break;
		case(RIGHT):
			if (stages[level].checkMonster(monster)) monster.translate(0.015f, 0.0f);
			else {
				monster.setDirection(LEFT);
				monster.translate(-0.015f, 0.0f);
			}
			break;
		case(DOWN):
			if (stages[level].checkMonster(monster)) monster.translate(0.0f, -0.015f);
			else {
				monster.setDirection(LEFT);
			}
			break;
		}
	}
}

void Idle::idleBubble()
{
	for (auto& bubble : bubbles) {
		float speed = bubble.horizontal_speed;
		float size = bubble.size;

		bubble.grow();

		float x = bubble.getPositionX(); float y = bubble.getPositionY();
		if (bubble.direction == D_LEFT) bubble.translate(-speed, 0.0f);
		if (bubble.direction == D_RIGHT) bubble.translate(speed, 0.0f);
		if (bubble.direction == D_UP) bubble.translate(0.0f, speed * 0.1);
		if (bubble.mapCollision(stages[level].getBorderHard()) || bubble.isGrown()) bubble.direction = D_UP;

		if (bubble.getPositionX() < -1.0f) bubble.setPositionX(1.0f);
		if (bubble.getPositionX() > 1.0f) bubble.setPositionX(-1.0f);
		if (bubble.getPositionY() > 1.0f) bubble.setPositionY(-1.0f);

		for (auto& monster : monsters) {
			if (bubble.collisionDetection(monster) && !monster.isTrapped() && !bubble.isGrown()) {
				bubble.direction = D_UP;
				bubble.size = 1.0f;
				bubble.trapping = true;
				monster.trap(bubble);
			}
		}
		if (clock() - bubble.createdTime > 5000) {
			bubble.alive = false;
		}
	}
}

void Idle::idleClear()
{
	if (stages[level].getTime() >= 0.6f) player.initializePosition();
}