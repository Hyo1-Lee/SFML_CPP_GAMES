#include"Player.h"

Player::Player(float _x, float _y)
{
	curPos_x = _x;
	curPos_y = _y;
}

void Player::move(float _x, float _y)
{
	curPos_x += _x;
	curPos_y += _y;
}

float Player::getCurPos_x()
{
	return curPos_x;
}

float Player::getCurPos_y()
{
	return curPos_y;
}

bool Player::isMoving()
{
	return moving;
}

void Player::setMoving(bool _b)
{
	moving = _b;
}

float Player::getSpeed()
{
	return speed;
}

void Player::setSpeed(float _speed)
{
	speed = _speed;
}

void Player::SetNPCServive(float _n)
{
	servive = rand() % 100 >= _n;
	return;
}

bool Player::getNPCServive()
{
	return servive;
}

void Player::setNPCDead(bool _d)
{
	dead = _d;
}

bool Player::getNPCDead()
{
	return dead;
}

void Player::setFinished(bool _f)
{
	finished = _f;
}

bool Player::getFinished()
{
	return finished;
}