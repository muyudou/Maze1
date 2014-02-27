//MapSite:�����Թ��齨�Ĺ��������࣬�������Թ��й���֮�����Ҫ��ϵ
//Room��һ����������࣬��ָ��MapSite��������ã���������һ�������
//Wall,Door���������࣬������һ�������ÿһ�������ֵ�ǽ�ں���
//Maze:��ʾ���伯�ϵ���

#ifndef MAZE_H
#define MAZE_H
#include <iostream>
using namespace std;

//��ʾ����
enum Direction {North, South, East, West};

//�Թ�����Ļ���
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
		//cout << "������һ����ͨ�ķ���, �����Ϊ��" 
		//	 << _roomNumber << endl;
		for (int i = 0; i < 4; i++)
		{
			_sides[i] = NULL;
		}
	}

	//�������캯����ʵ��ԭ��ģʽ
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
		cout << "���� " << _roomNumber << " �ŷ���" << endl;
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
		//cout << "������һ����ͨ��ǽ" << endl;
	}

    virtual Wall* clone()
	{
		return new Wall(*this);
	}

	virtual void Enter()
	{
		cout << "�����һ��ǽ��������һ��ǽ" << endl;
	}
};

class Door : public MapSite
{
public:

	Door(Room* room1= 0, Room* room2= 0) : 
	  _room1(room1), _room2(room2), _isOpen(false)
	{
          //cout << "������һ����ͨ���ţ������ߵķ���ŷֱ�Ϊ��"
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
		cout << "����һ���ţ�������һ����" << endl;
	}

	Room* OtherSideFrom(Room* )
	{
        cout << _room1->GetRoomId() << " �ŷ������һ���� " 
			 << _room2->GetRoomId() << " �ŷ���" << endl;
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
		cout << "��ʼ����һ���Թ�" << endl;
	}

	Maze* clone()
	{
		return new Maze(*this);
	}

	void AddRoom(Room* room)
	{
		cout << "������һ�����䣬�����Ϊ��" << room->GetRoomId() << endl;
        
	}
	Room* RoomNo(int n) const
	{
        cout << n << " �ŷ���" << endl;
	}
};

//�������
class EnchantedRoom : public Room
{
public:
	EnchantedRoom(int n) : Room(n)
	{
		cout << "����һ��EnchantedRoom, �����Ϊ��" 
			 << n << endl;
	}

	virtual Room* clone()
	{
		return new Room(*this);
	}

    void Enter()
    {
        cout << "����EnchantedRoom..." << endl;
    }
};

class RoomWithBomb : public Room
{
public:
	RoomWithBomb(int n = 0) : Room(n)
	{
		//cout << "����һ��RoomWithBomb,�����Ϊ " << n << endl;
	}

	virtual Room* clone()
	{
		return new Room(*this);
	}

    void Enter()
	{
        cout << "����RoomWithBomb..." << endl;
	}
};

class BombdeWall : public Wall
{
public:
	BombdeWall()
	{
		cout << "����һ��BombdeWall..." << endl;
	}

	virtual Wall* clone()
	{
		return new Wall(*this);
	}

    void Enter()
	{
        cout << "���Ǹ�ը����ǽ��BombdeWall" << endl;
	}
};

class DoorNeedingSpell : public Door
{
public:
	DoorNeedingSpell(Room* room1, Room* room2) : Door(room1, room2)
	{
        cout << "����һ��DoorNeedingSpell..." << endl;
	}

	virtual Door* clone()
	{
		return new Door(*this);
	}

    void Enter()
	{
		cout << "������������Ҫ����: DoorNeedingSpell" << endl;
	}
};
#endif