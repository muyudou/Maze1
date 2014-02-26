//builderģʽ

#include "Maze.h"

//�Թ�����������
class MazeBuilder
{
public:
	virtual void BuildMaze() { }
	virtual void BuildRoom(int room) { }
	virtual void BuildDoor(int RoomFrom, int RoomTo) { }

	virtual Maze* GetMaze() 
	{
		return 0;
	}
};

class StandardMazeBuilder : public MazeBuilder 
{
public:
	StandardMazeBuilder() : _currentMaze(NULL) { }

	//�����Թ�
	virtual void BuilMaze()
	{
        _currentMaze = new Maze;
	}

	//���췿��
	virtual void BuildRoom(int n)
	{
        Room *room = new Room(n);
		_currentMaze->AddRoom(room);

		room->SetSide(North, new Wall);
		room->SetSide(South, new Wall);
		room->SetSide(East, new Wall);
		room->SetSide(West, new Wall);
	}

	//������
	virtual void BuildDoor(Room* r1, Room* r2)
	{
        Door *d = new Door(r1, r2);

		r1->SetSide(CommanWall(r1, r2), d);
		r2->SetSide(CommanWall(r2, r1), d);
	}
 
	//���ع�����Թ�
	virtual Maze* GetMaze()
	{
		return _currentMaze;
	}
private:
	//����r1,r2��ͬ��ǽ��r1�е�λ��
	Direction CommanWall(Room* r1, Room* r2)
	{
        return North;
	}
	Maze* _currentMaze;
};

//�������������������Թ���ֻ�Ƕ��ѱ������Ĳ�ͬ����Ĺ������м���
class CountingMazeBuilder : public MazeBuilder
{
public:
	CountingMazeBuilder() : _doors(0), _rooms(0) {}

	virtual void BuildRoom(int)
	{
		_rooms++;
	}

	virtual void BuildDoor(int, int)
	{
		_doors++;
	}

    void GetCounts(int& rooms, int& doors) const
	{
        rooms = _rooms;
		doors = _doors;
	}
protected:
private:
	int _doors;
	int _rooms;
};

//�����Թ�
class MazeGame
{
public:
    Maze* CreateMaze(MazeBuilder& builder)
	{
		builder.BuildMaze();
		builder.BuildRoom(1);
		builder.BuildRoom(2);
		builder.BuildDoor(1, 2);

		return builder.GetMaze();
	}
};

int main()
{
	//����StandardMazeBuilder�����Թ�
	Maze* maze;
	MazeGame game;
    StandardMazeBuilder builder;

	game.CreateMaze(builder);
	maze = builder.GetMaze();

	//����CountingMazeBuilder���Թ��Ĳ������м���
	int rooms, doors;
	CountingMazeBuilder cbuilder;
	game.CreateMaze(cbuilder);
	cbuilder.GetCounts(rooms, doors);

	cout << "The maze has " << rooms << " rooms and " 
		 << doors << " doors" << endl;

	system("pause");
	return 0;
}