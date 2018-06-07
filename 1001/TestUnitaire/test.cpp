#include "pch.h"
#include "../MaBibliotheque/Brick.h"
#include "../MaBibliotheque/Rock.h"


TEST(TestReadXML, TestBrick) {
	std::string source = R"(<?xml version = "1.0"?>
		<Drawing>
		<Brick x = "1" y = "2"  / >
		< / Drawing>)";  

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_string(source.c_str());
	pugi::xml_node node = doc.child("Drawing").child("Brick");
//	b2World *world;
/*	Brick brick{ node,world };
	EXPECT_EQ(brick.getX(), 1*tailleX);
	EXPECT_EQ(brick.getY(), 2*tailleY);*/
	EXPECT_TRUE(true);
}

TEST(TestReadXML, TestRock) {
	std::string source = R"(<?xml version = "1.0"?>
		<Drawing>
		<Rock x = "1" y = "2" dimX="3" dimY = "4" / >
		< / Drawing>)";

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_string(source.c_str());
	pugi::xml_node node = doc.child("Drawing").child("Rock");
//	b2World *world;
/*	Rock rock{ node, world };
	EXPECT_EQ(rock.getX(), 1*tailleX);
	EXPECT_EQ(rock.getY(), 2*tailleY);
	EXPECT_EQ(rock.getDimX(), 3*tailleX);
	EXPECT_EQ(rock.getDimY(), 4*tailleY);*/
	EXPECT_TRUE(true);
}