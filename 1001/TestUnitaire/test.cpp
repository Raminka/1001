#include "pch.h"
#include "../MaBibliotheque/Brick.h"
#include "../MaBibliotheque/Rock.h"
#include "../MaBibliotheque/LightSwitch.h"


TEST(TestReadXML, TestBrick) {
	std::string source = R"(<?xml version = "1.0"?>
		<Drawing>
		<Brick x = "1" y = "2"  / >
		< / Drawing>)";  

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_string(source.c_str());
	pugi::xml_node node = doc.child("Drawing").child("Brick");
	b2World world = b2World(b2Vec2(0.0f, 0.0f));
	sf::RenderWindow window;
	
	Brick brick{ node,&world, window };
	EXPECT_EQ(brick.getX(), 1*tailleX);
	EXPECT_EQ(brick.getY(), 2*tailleY);
	EXPECT_EQ(brick.getDimX(),  tailleX);
	EXPECT_EQ(brick.getDimY(),  tailleY);

	EXPECT_EQ(brick.obstacleAction,Obstacle::nothing);
	brick.startContact();
	EXPECT_EQ(brick.obstacleAction, Obstacle::nothing);
	brick.Draw(window);
	EXPECT_EQ(brick.obstacleAction, Obstacle::toDelete);

}

TEST(TestReadXML, TestRock) {
	std::string source = R"(<?xml version = "1.0"?>
		<Drawing>
		<Rock x = "1" y = "2" dimX="3" dimY = "4" / >
		< / Drawing>)";

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_string(source.c_str());
	pugi::xml_node node = doc.child("Drawing").child("Rock");
	b2World world = b2World(b2Vec2(0.0f, 0.0f));
	sf::RenderWindow window;

	Rock rock{ node,&world, window };
	EXPECT_EQ(rock.getX(), 1 * tailleX);
	EXPECT_EQ(rock.getY(), 2 * tailleY);
	EXPECT_EQ(rock.getDimX(), 3 * tailleX);
	EXPECT_EQ(rock.getDimY(), 4 * tailleY);

	EXPECT_EQ(rock.obstacleAction, Obstacle::nothing);
	rock.startContact();
	EXPECT_EQ(rock.obstacleAction, Obstacle::nothing);
	rock.Draw(window);
	EXPECT_EQ(rock.obstacleAction, Obstacle::nothing);
}

TEST(TestReadXML, TestSwitch) {
	std::string source = R"(<?xml version = "1.0"?>
		<Drawing>
		<LightSwitch x = "1" y = "2" / >
		< / Drawing>)";

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_string(source.c_str());
	pugi::xml_node node = doc.child("Drawing").child("LightSwitch");
	b2World world = b2World(b2Vec2(0.0f, 0.0f));
	sf::RenderWindow window;

	LightSwitch lightSwitch{ node,&world, window };
	EXPECT_EQ(lightSwitch.getX(), 1 * tailleX);
	EXPECT_EQ(lightSwitch.getY(), 2 * tailleY);
	EXPECT_EQ(lightSwitch.getDimX(), 3 * tailleX);
	EXPECT_EQ(lightSwitch.getDimY(),  tailleY);

	EXPECT_EQ(lightSwitch.obstacleAction, Obstacle::nothing);
	lightSwitch.startContact();
	EXPECT_EQ(lightSwitch.obstacleAction, Obstacle::switchLight);
	lightSwitch.Draw(window);
	EXPECT_EQ(lightSwitch.obstacleAction, Obstacle::nothing);
}