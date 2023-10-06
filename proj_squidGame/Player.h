#pragma once
#include<iostream>

class Player
{
private:
	float curPos_x;
	float curPos_y;
	float speed;
	bool moving = false;
	bool servive;
	bool dead = false;
	bool finished = false;

public:
	Player(float _x, float _y);
	float getCurPos_x();
	float getCurPos_y();
	float getSpeed();
	void setSpeed(float _speed);

	void move(float _x, float _y);
	bool isMoving();
	void setMoving(bool _b);

	void SetNPCServive(float _n);
	bool getNPCServive();

	void setNPCDead(bool _d);
	bool getNPCDead();

	void setFinished(bool _f);
	bool getFinished();
};