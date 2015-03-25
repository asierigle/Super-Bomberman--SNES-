#pragma once
#include "List.h"
#include "p2Point.h"

struct step
{
	p2Point<int> position;
	int frame;

	step(int x, int y, int frame)
	{
		this->frame = frame;
		position.x = x;
		position.y = y;
	}
};

class MovingPoint
{
public:
	float speed;
	p2List<step> points;
	int total_frames;

public:
	MovingPoint() : speed(1.0f), total_frames(0)
	{}

	void AddPoint(int x, int y, int frame)
	{
		points.add(step(x, y, frame));
		total_frames += frame;
	}

	p2Point<int> GetCurrentPosition(int currentFrame) const
	{
		p2Point<int> tmp;

		int f = currentFrame % total_frames;
		int current = 0;

		p2List<step>* tmp = points.getFirst();
		while(tmp != NULL && c < f)
		{
			c += tmp.data.frames;
			tmp = tmp->next;
		}

		// now we are between tmp->prev and tmp

		return tmp;
	}
};