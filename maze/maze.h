//MapSite:所有迷宫组建的公共抽象类，定义了迷宫中构建之间的主要关系
//Room：一个具体的子类，有指向MapSite对象的引用，并保存了一个房间号
//Wall,Door：具体子类，描述了一个房间的每一面所出现的墙壁和门
//Maze:表示房间集合的类

#ifndef MAZE_H
#define MAZE_H
#include <iostream>
using namespace std;

//表示方向
enum Direction {North, South, East, West};

//迷宫组件的基类
class MapSite
{
public:
    virtual void Enter() = 0;
};

class Room : public MapSite
{
public:
	Room(int roomNo = 0) : _roomNumber(roomNo)
	{
		//cout << "构造了一个普通的房间, 房间号为：" 
		//	 << _roomNumber << endl;
		for (int i = 0; i < 4; i++)
		{
			_sides[i] = NULL;
		}
	}

	//拷贝构造函数，实现原型模式
	Room(const Room& r) : _roomNumber(r._roomNumber)
    {
		for(int i = 0; i < 4; i++)
		{
    		_sides[i] = r._sides[i];
		}
	}

	virtual Room* clone()
	{
		return new Room(*this);
	}

	void Initialize(int n)
	{
		_roomNumber = n;
	}

	MapSite* GetSide(Direction direct) const
	{
	    _sides[direct-North]->Enter();
        return _sides[direct-North];
	}

	void SetSide(Direction direct, MapSite* site)
	{
        _sides[direct - North] = site;
	}

	int GetRoomId()
	{
		return _roomNumber;
	}

	virtual void Enter()
	{
		cout << "进入 " << _roomNumber << " 号房间" << endl;
	}
private:
	MapSite* _sides[4];
	int _roomNumber;
};

class Wall : public MapSite
{
public:
	Wall()
	{
		//cout << "构造了一面普通的墙" << endl;
	}

    virtual Wall* clone()
	{
		return new Wall(*this);
	}

	virtual void Enter()
	{
		cout << "这边是一面墙，遇到了一面墙" << endl;
	}
};

class Door : public MapSite
{
public:

	Door(Room* room1= 0, Room* room2= 0) : 
	  _room1(room1), _room2(room2), _isOpen(false)
	{
          //cout << "构造了一扇普通的门，门两边的房间号分别为："
		  //  << room1->GetRoomId() << " " << room2->GetRoomId() << endl;
	}

    Door(const Door& other) : _isOpen(other._isOpen)
	{
		_room1 = other._room1;
		_room2 = other._room2;
	}

	void Initialize(Room* r1, Room* r2)
	{
		_room1 = r1;
		_room2 = r2;
	}

	virtual Door* clone()
	{
	    return new Door(*this);	
	}

	virtual void Enter()
	{
		cout << "这是一扇门，遇到了一扇门" << endl;
	}

	Room* OtherSideFrom(Room* )
	{
        cout << _room1->GetRoomId() << " 号房间的另一边是 " 
			 << _room2->GetRoomId() << " 号房间" << endl;
		return NULL;
	}
private:
	Room* _room1;
	Room* _room2;
	bool _isOpen;
};

class Maze
{
public:
	Maze()
	{
		cout << "开始构造一个迷宫" << endl;
	}

	Maze* clone()
	{
		return new Maze(*this);
	}

	void AddRoom(Room* room)
	{
		cout << "增加了一个房间，房间号为：" << room->GetRoomId() << endl;
        
	}
	Room* RoomNo(int n) const
	{
        cout << n << " 号房间" << endl;
	}
};

//具体的类
class EnchantedRoom : public Room
{
public:
	EnchantedRoom(int n) : Room(n)
	{
		cout << "构造一个EnchantedRoom, 房间号为：" 
			 << n << endl;
	}

	virtual Room* clone()
	{
		return new Room(*this);
	}

    void Enter()
    {
        cout << "进入EnchantedRoom..." << endl;
    }
};

class RoomWithBomb : public Room
{
public:
	RoomWithBomb(int n = 0) : Room(n)
	{
		//cout << "构造一个RoomWithBomb,房间号为 " << n << endl;
	}

	virtual Room* clone()
	{
		return new Room(*this);
	}

    void Enter()
	{
        cout << "进入RoomWithBomb..." << endl;
	}
};

class BombdeWall : public Wall
{
public:
	BombdeWall()
	{
		cout << "构造一个BombdeWall..." << endl;
	}

	virtual Wall* clone()
	{
		return new Wall(*this);
	}

    void Enter()
	{
        cout << "这是个炸坏的墙：BombdeWall" << endl;
	}
};

class DoorNeedingSpell : public Door
{
public:
	DoorNeedingSpell(Room* room1, Room* room2) : Door(room1, room2)
	{
        cout << "构造一个DoorNeedingSpell..." << endl;
	}

	virtual Door* clone()
	{
		return new Door(*this);
	}

    void Enter()
	{
		cout << "进入这扇门需要谜语: DoorNeedingSpell" << endl;
	}
};
#endif