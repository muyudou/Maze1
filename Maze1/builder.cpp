//builder模式

#include "Maze.h"

//迷宫生成器基类
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

	//构造迷宫
	virtual void BuilMaze()
	{
        _currentMaze = new Maze;
	}

	//构造房间
	virtual void BuildRoom(int n)
	{
        Room *room = new Room(n);
		_currentMaze->AddRoom(room);

		room->SetSide(North, new Wall);
		room->SetSide(South, new Wall);
		room->SetSide(East, new Wall);
		room->SetSide(West, new Wall);
	}

	//构造门
	virtual void BuildDoor(Room* r1, Room* r2)
	{
        Door *d = new Door(r1, r2);

		r1->SetSide(CommanWall(r1, r2), d);
		r2->SetSide(CommanWall(r2, r1), d);
	}
 
	//返回构造的迷宫
	virtual Maze* GetMaze()
	{
		return _currentMaze;
	}
private:
	//返回r1,r2共同的墙在r1中的位置
	Direction CommanWall(Room* r1, Room* r2)
	{
        return North;
	}
	Maze* _currentMaze;
};

//具体生成器，不创建迷宫，只是对已被创建的不同种类的构建进行计算
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

//创建迷宫
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
	//利用StandardMazeBuilder创建迷宫
	Maze* maze;
	MazeGame game;
    StandardMazeBuilder builder;

	game.CreateMaze(builder);
	maze = builder.GetMaze();

	//利用CountingMazeBuilder对迷宫的部件进行计数
	int rooms, doors;
	CountingMazeBuilder cbuilder;
	game.CreateMaze(cbuilder);
	cbuilder.GetCounts(rooms, doors);

	cout << "The maze has " << rooms << " rooms and " 
		 << doors << " doors" << endl;

	system("pause");
	return 0;
}