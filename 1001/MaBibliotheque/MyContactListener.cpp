#include "stdafx.h"
#include "MyContactListener.h"

void MyContactListener::BeginContact(b2Contact* contact) {
	/*on s'interesse qu'aux contacts des obstacles*/
		void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
		if (bodyUserData)
			static_cast<Obstacle*>(bodyUserData)->startContact();

		bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
		if (bodyUserData)
			static_cast<Obstacle*>(bodyUserData)->startContact();
	
}