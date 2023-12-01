#include "main.h"

Player player;
Player* playerPointer = &player;

Map stages(0) ;
map<int, Bubble> bubbles;
vector<Monster> monsters;
vector<Explosion> explosions;
vector<Item> items;
Scoreboard board;
Input input;

int bubble_total_num=0;
int level;
bool clear;
bool gameover = false;
bool gamestart = false;
bool restarted = false;
bool win = false;
bool displayHelp = false;
bool displayLeaderboard = false;
bool dataClearedForMoving = false;
bool keystates[6];

Idle idleFunc;
Display displayFunc;
clock_t startTime = clock();
clock_t lastBubbleCreationTime = clock();
clock_t lastItemCreationTime = clock();
clock_t lastClearTime = clock();

Texture gmover(_MAP, _GAMEOVER);
Texture title(_MAP, _TITLE);
Texture gmwin(_MAP, _GAMEWIN);

void initialize(bool restarted)
{
	level = 0;
	player = Player(5);
	clear = false;
	win = false;
	gamestart = false;
	if (!restarted) {
		gmover.initTexture();
		title.initTexture();
		gmwin.initTexture();
	}

	stages = Map(level);
	board = Scoreboard();
}

void idle()
{
	idleFunc.operate();
}

void display()
{
	displayFunc.operate();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(WINDOW_X, WINDOW_Y);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Bubble Bobble");

	initialize(false);

	glutDisplayFunc(display);
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);
	glutIgnoreKeyRepeat(1);
	glutSpecialFunc(specialKeyDown);
	glutSpecialUpFunc(specialKeyUp);
	glutIdleFunc(idle);

	glutMainLoop();

	return 0;
}
