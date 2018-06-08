#pragma once
#include <Box2D\Box2D.h>
#include "Brick.h"
class MyContactListener : public b2ContactListener
{
public:
	void BeginContact(b2Contact* contact);
}
;
