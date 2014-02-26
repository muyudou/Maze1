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
	Room(int roomNo) : _roomNumber(roomNo)
	{
		//cout << "������һ����ͨ�ķ���, �����Ϊ��" 
		//	 << _roomNumber << endl;
		for (int i = 0; i < 4; i++)
		{
			_sides[i] = NULL;
		}
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
	void AddRoom(Room* room)
	{
		cout << "������һ�����䣬�����Ϊ��" << room->GetRoomId() << endl;
        
	}
	Room* RoomNo(int n) const
	{
        cout << n << " �ŷ���" << endl;
	}
};
#endif