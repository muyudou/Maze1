////工厂方法模式
//#include "maze.h"
//
////工厂方法的基类，构造基本的迷宫
//class MazeGame
//{
//public:
//	//四个工厂方法
//	virtual Maze* MakeMaze() const
//	{
//		return new Maze;
//	}
//
//	virtual Room* MakeRoom(int n) const
//	{
//		return new Room(n);
//	}
//
//	virtual Wall* MakeWall() const
//	{
//		return new Wall;
//	}
//
//	virtual Door* MakeDoor(Room* r1, Room* r2)
//	{
//		return new Door(r1, r2);
//	}
//
//	Maze* CreateMaze()
//	{
//		Maze* aMaze = MakeMaze();
//
//		Room* r1 = MakeRoom(1);
//		Room* r2 = MakeRoom(2);
//		Door* theDoor = MakeDoor(r1, r2);
//
//		aMaze->AddRoom(r1);
//		aMaze->AddRoom(r2);
//
//		r1->SetSide(North, MakeWall());
//		r1->SetSide(East, theDoor);
//		r1->SetSide(South, MakeWall());
//		r1->SetSide(West, MakeWall());
//
//		r2->SetSide(North, MakeWall());
//		r2->SetSide(East, MakeWall());
//		r2->SetSide(South, MakeWall());
//		r2->SetSide(West, theDoor);
//
//		return aMaze;
//	}
//};
////构造一个有房间炸弹的迷宫
//class BombedMazeGame : public MazeGame
//{
//public:
//	BombedMazeGame()
//	{
//		cout << "构造一个BombedMazeGame..." << endl;
//	}
//
//	virtual Wall* MakeWall() const
//	{
//		return new BombdeWall;
//	}
//
//	virtual Room* MakeRoom(int n) const
//	{
//		return new RoomWithBomb(n);
//	}
//};
//
////构造一个需要魔咒的迷宫
//class EnchantedMazeGame : public MazeGame
//{
//public:
//	EnchantedMazeGame()
//	{
//		cout << "构造一个EnchantedMazeGame..." << endl;
//	}
//
//	virtual Door* MakeDoor(Room* r1, Room* r2) const
//	{
//		return new DoorNeedingSpell(r1, r2);
//	}
//
//	virtual Room* MakeRoom(int n) const
//	{
//		return new EnchantedRoom(n);
//	}
//};
//
//int main()
//{
//	Maze* aMaze;
//	MazeGame* mazeGame;
//
//	//构造BombedMazeGame迷宫
//	mazeGame = new BombedMazeGame;
//	aMaze = mazeGame->CreateMaze();
//
//	//构造EnchantedMazeGame迷宫
//	mazeGame = new EnchantedMazeGame;
//	aMaze = mazeGame->CreateMaze();
//
//	system("pause");
//	return 0;
//}