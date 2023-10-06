#include"Animation.h"

Animation::Animation(IntRect* rect, int framesNumber)
{
	bounds = rect;
	frames = framesNumber;
	resetValue = rect->left;
}

void Animation::changeFrame(float _speed)
{
	if (clock.getElapsedTime().asSeconds() >= _speed)
	{
		if (bounds->left >= (resetValue + 70 * (frames - 1)))
		{
			bounds->left = resetValue;
		}
		else
		{
			bounds->left += 70;
		}
		clock.restart();
	}
}

void Animation::changeBoomFrame(float _speed)
{
	if (clock.getElapsedTime().asSeconds() >= _speed)
	{
		if (bounds->left >= (resetValue + 200 * (frames - 1)))
		{
			bounds->left = resetValue;
		}
		else
		{
			bounds->left += 200;
		}
		clock.restart();
	}
}

IntRect Animation::getBounds()
{
	return *bounds;
}
