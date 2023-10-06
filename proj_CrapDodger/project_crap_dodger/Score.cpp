#include "Score.h"

Score::Score()
{
	score = 0;
}

void Score::upScore()
{
	score += 1;
}

int Score::update()
{
	return score;	
}