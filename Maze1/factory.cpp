//#include "Maze.h"
//
////�������
//class EnchantedRoom : public Room
//{
//public:
//	EnchantedRoom(int n) : Room(n)
//	{
//		/*cout << "����һ��EnchantedRoom, �����Ϊ��" 
//			 << n << endl;*/
//	}
//
//    void Enter()
//    {
//        cout << "����EnchantedRoom..." << endl;
//    }
//};
//
//class RoomWithBomb : public Room
//{
//public:
//	RoomWithBomb(int n) : Room(n)
//	{
//		//cout << "����һ��RoomWithBomb,�����Ϊ " << n << endl;
//	}
//    void Enter()
//	{
//        cout << "����RoomWithBomb..." << endl;
//	}
//};
//
//class BombdeWall : public Wall
//{
//public:
//	//BombdeWall()
//	//{
//	//	cout << "����һ��BombdeWall..." << endl;
//	//}
//
//    void Enter()
//	{
//        cout << "���Ǹ�ը����ǽ��BombdeWall" << endl;
//	}
//};
//
//class DoorNeedingSpell : public Door
//{
//public:
//	DoorNeedingSpell(Room* room1, Room* room2) : Door(room1, room2)
//	{
//        //cout << "����һ��DoorNeedingSpell..." << endl;
//	}
//
//    void Enter()
//	{
//		cout << "������������Ҫ����: DoorNeedingSpell" << endl;
//	}
//};
//
////�Թ������������Թ�������һ������Ĺ���Ҳ��һ������Ĺ���
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
////����Ĺ���
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
//		cout << "ʩħ��..." << endl;
//	}
//};
////����Ĺ���
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
////���ù����๹���Թ����ͻ����ٵ���
//class MazeGame
//{
//public:
//    Maze* CreateMaze(MazeFactory& factory)
//	{
//		//�����Թ�����ɲ���
//         Maze* aMaze = factory.MakeMaze();
//		 Room* r1 = factory.MakeRoom(1);
//		 Room* r2 = factory.MakeRoom(2);
//		 Door* aDoor = factory.MakeDoor(r1, r2);
//
//		 aMaze->AddRoom(r1);
//		 aMaze->AddRoom(r2);
//
//		 //���췿����ĸ���
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
