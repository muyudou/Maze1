//#include "Maze.h"
//
////具体的类
//class EnchantedRoom : public Room
//{
//public:
//	EnchantedRoom(int n) : Room(n)
//	{
//		/*cout << "构造一个EnchantedRoom, 房间号为：" 
//			 << n << endl;*/
//	}
//
//    void Enter()
//    {
//        cout << "进入EnchantedRoom..." << endl;
//    }
//};
//
//class RoomWithBomb : public Room
//{
//public:
//	RoomWithBomb(int n) : Room(n)
//	{
//		//cout << "构造一个RoomWithBomb,房间号为 " << n << endl;
//	}
//    void Enter()
//	{
//        cout << "进入RoomWithBomb..." << endl;
//	}
//};
//
//class BombdeWall : public Wall
//{
//public:
//	//BombdeWall()
//	//{
//	//	cout << "构造一个BombdeWall..." << endl;
//	//}
//
//    void Enter()
//	{
//        cout << "这是个炸坏的墙：BombdeWall" << endl;
//	}
//};
//
//class DoorNeedingSpell : public Door
//{
//public:
//	DoorNeedingSpell(Room* room1, Room* room2) : Door(room1, room2)
//	{
//        //cout << "构造一个DoorNeedingSpell..." << endl;
//	}
//
//    void Enter()
//	{
//		cout << "进入这扇门需要谜语: DoorNeedingSpell" << endl;
//	}
//};
//
////迷宫工厂，构建迷宫，既是一个抽象的工厂也是一个具体的工厂
//class MazeFactory
//{
//public:
//	virtual Maze* MakeMaze() const
//	{
//		return new Maze;
//	}
//
//	virtual Wall* MakeWall() const
//	{
//		return new Wall;
//	}
//
//	virtual Room* MakeRoom(int n) const
//	{
//		return new Room(n);
//	}
//
//	virtual Door* MakeDoor(Room* r1, Room* r2) const
//	{
//		return new Door(r1, r2);
//	}
//};
//
////具体的工厂
//class EnchantedMazeFactory : public MazeFactory
//{
//public:
//	virtual Room* MakeRoom(int n) const
//	{
//		return new EnchantedRoom(n);
//	}
//
//	virtual Door* MakeDoor(Room* r1, Room* r2) const
//	{
//		return new DoorNeedingSpell(r1, r2);
//	}
//protected:
//	string CastSpell() const
//	{
//		cout << "施魔法..." << endl;
//	}
//};
////具体的工厂
//class BombdeMazeFactory : public MazeFactory
//{
//public:
//	virtual Room* MakeRoom(int n) const
//	{
//		return new RoomWithBomb(n);
//	}
//
//	virtual Wall* MakeWall() const
//	{
//		return new BombdeWall;
//	}
//};
//
//
////调用工厂类构造迷宫，客户端再调用
//class MazeGame
//{
//public:
//    Maze* CreateMaze(MazeFactory& factory)
//	{
//		//构造迷宫和组成部分
//         Maze* aMaze = factory.MakeMaze();
//		 Room* r1 = factory.MakeRoom(1);
//		 Room* r2 = factory.MakeRoom(2);
//		 Door* aDoor = factory.MakeDoor(r1, r2);
//
//		 aMaze->AddRoom(r1);
//		 aMaze->AddRoom(r2);
//
//		 //构造房间的四个面
//		 r1->SetSide(North, factory.MakeWall());
//		 r1->SetSide(East, aDoor);
//		 r1->SetSide(South, factory.MakeWall());
//		 r1->SetSide(West, factory.MakeWall());
//	
//		 r2->SetSide(North, factory.MakeWall());
//		 r2->SetSide(East, factory.MakeWall());
//		 r2->SetSide(South, factory.MakeWall());
//		 r2->SetSide(West, aDoor);
//
//		 r1->Enter();
//		 r1->GetSide(North);
//		 r1->GetSide(East);
//		 r1->GetSide(South);
//		 r1->GetSide(West);
//
//		 r2->Enter();
//		 r2->GetSide(North);
//		 r2->GetSide(East);
//		 r2->GetSide(South);
//		 r2->GetSide(West);
//		 
//		 aDoor->Enter();
//
//		 return aMaze;
//	}
//};
//
//int main()
//{
//	MazeGame game;
//	BombdeMazeFactory factory;
//
//	game.CreateMaze(factory);
//
//	system("pause");
//	return 0;
//}
//
