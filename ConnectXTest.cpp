/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"

class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(ConnectXTest, sanityCheck)
{
	ASSERT_TRUE(true);
}


// Test for at(). Input - Valid width and valid height
TEST(ConnectXTest, atTestOne)
{
	ConnectX connect;
  ASSERT_EQ(0,connect.at(2,4));
}

// Test for at(). Input - Valid width and invalid height
TEST(ConnectXTest, atTestTwo)
{
	ConnectX connect;
  ASSERT_EQ(-1,connect.at(2,9));
}

//Test for at(). Input - Invalid width and valid height
// This test fails because of bug in inbound function.
TEST(ConnectXTest, atTestThree)
{
	ConnectX connect;
  ASSERT_EQ(-1,connect.at(11,4));
}

// Test for at(). Input - Invalid width and invalid height
TEST(ConnectXTest, atTestFour)
{
	ConnectX connect;
  ASSERT_EQ(-1,connect.at(12,18));
}

// Test for at(). Input - Invalid width and valid height
// This test fails because of bug in inbound function.
TEST(ConnectXTest, atTestFive)
{
	ConnectX connect;
  ASSERT_EQ(-1,connect.at(-2,4));
}

// Test for at(). Input - Invalid width and invalid height
TEST(ConnectXTest, atTestSix)
{
	ConnectX connect;
  ASSERT_EQ(-1,connect.at(-4,40));
}

// Test for at(). Input - Invalid width and invalid height
TEST(ConnectXTest, atTestSeven)
{
	ConnectX connect;
  ASSERT_EQ(-1,connect.at(-10,-10));
}

// Test for at(). Input - valid width and invalid height
TEST(ConnectXTest, atTestEight)
{
	ConnectX connect;
  ASSERT_EQ(-1,connect.at(3,-7));
}


// Test for whoseTurn()
// Black should be the initial player.
TEST(ConnectXTest, whoseTurnTestOne)
{
	ConnectX connect;
	ASSERT_EQ(2,connect.whoseTurn());
}

// Test for whoseTurn() Test
// Testing to check if the second player is white.
TEST(ConnectXTest, whoseTurnTwo)
{
	ConnectX connect;
	connect.placePiece(4);
	ASSERT_EQ(1,connect.whoseTurn());
}


// Test for placePiece()
// First piece placed should be black.
TEST(ConnectXTest, placePieceTestOne)
{
	ConnectX connect;
	connect.placePiece(4);
	ASSERT_EQ(2,connect.at(4,5));
}

// Test for placePiece()
// The second piece placed on the board should be white.
TEST(ConnectXTest, placePieceTestTwo)
{
	ConnectX connect;
	connect.placePiece(4);
	connect.placePiece(2);
	ASSERT_EQ(1,connect.at(2,5));
}

// Test for placePiece()
// When input is invalid - trying to place piece in a full coulmn.
TEST(ConnectXTest, placePieceBadCol)
{
	ConnectX connect;

	connect.placePiece(3);
	connect.placePiece(3);
	connect.placePiece(3);
	connect.placePiece(3);
	connect.placePiece(3);
	connect.placePiece(3);
	connect.placePiece(3);

	connect.placePiece(6);
	connect.showBoard();
	ASSERT_EQ(2,connect.whoseTurn());
}


// Test for toggleTurn()
TEST(ConnectXTest, toggleTurnTest)
{
	ConnectX connect;
	connect.placePiece(4);
	connect.placePiece(3);
	connect.placePiece(2);
	ASSERT_EQ(2,connect.at(2,5));
}



// Test for showBoard()
// When input is valid
TEST(ConnectXTest, showBoardTest1)
{
	ConnectX connect;
	connect.placePiece(4);
	connect.placePiece(3);
	connect.placePiece(2);
	connect.showBoard();
	ASSERT_EQ(2,connect.at(4,5));
}

// Test for showBoard()
// Input - Empty
TEST(ConnectXTest, showBoardTest2)
{
	ConnectX connect;
	connect.showBoard();
	ASSERT_EQ(0,connect.at(1,2));
}

// Test for showBoard()
// Input - White
TEST(ConnectXTest, showBoardTest3)
{
	ConnectX connect;
	connect.placePiece(4);
	connect.placePiece(4);
	connect.showBoard();
	ASSERT_EQ(1,connect.at(4,4));
}

// Test for showBoard()
// Input Invalid
TEST(ConnectXTest, showBoardTest4)
{
	ConnectX connect;
	connect.placePiece(4);
	connect.placePiece(4);
	connect.showBoard();
	ASSERT_EQ(-1,connect.at(8,9));
}
