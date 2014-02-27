//原型模式

#include "maze.h"

//工厂方法
class MazeFactory
{
public:
	//四个工厂方法
	virtual Maze* MakeMaze() const
	{
		return new Maze;
	}

	virtual Room* MakeRoom(int n) const
	{
		return new Room(n);
	}

	virtual Wall* MakeWall() const
	{
		return new Wall;
	}

	virtual Door* MakeDoor(Room* r1, Room* r2)
	{
		return new Door(r1, r2);
	}
};

//用一个以原型为参数的构造器来扩充MazeFactory
class MazePrototypeFactory : public MazeFactory
{
public:
	MazePrototypeFactory(Maze* m, Wall* w, Room* r, Door* d)
		: _prototypeMaze(m), _prototypeRoom(r), _prototypeWall(w), _prototypeDoor(d)
	{
	}

	virtual Maze* MakeMaze() const
	{
		return _prototypeMaze->clone();
	}

	virtual Room* MakeRoom(int n) const
	{
		Room* room = _prototypeRoom->clone();
		room->Initialize(n);
		return room;
	}

	virtual Wall* MakeWall() const
	{
		return _prototypeWall->clone();
	}

	virtual Door* MakeDoor(Room* r1, Room* r2) const
	{
		Door* door = _prototypeDoor->clone();
		door->Initialize(r1, r2);
		return door;
	}
private:
	Maze* _prototypeMaze;
	Room* _prototypeRoom;
	Wall* _prototypeWall;
	Door* _prototypeDoor;
};

class MazeGame
{
public:
	Maze* CreateMaze(MazeFactory& factory)
	{
		Maze* aMaze = factory.MakeMaze();

		Room* r1 = factory.MakeRoom(1);
		Room* r2 = factory.MakeRoom(2);
		Door* theDoor = factory.MakeDoor(r1, r2);

		aMaze->AddRoom(r1);
		aMaze->AddRoom(r2);

		r1->SetSide(North, factory.MakeWall());
		r1->SetSide(East, theDoor);
		r1->SetSide(South, factory.MakeWall());
		r1->SetSide(West, factory.MakeWall());

		r2->SetSide(North, factory.MakeWall());
		r2->SetSide(East, factory.MakeWall());
		r2->SetSide(South, factory.MakeWall());
		r2->SetSide(West, theDoor);

		return aMaze;
	}
};

int main()
{
	Maze* aMaze;
	MazeGame game;

	MazePrototypeFactory simpleMazeFactory(new Maze, new Wall, new Room, new Door);
	aMaze = game.CreateMaze(simpleMazeFactory);

	MazePrototypeFactory bombedMazeFactory(new Maze, new BombdeWall, new RoomWithBomb, new Door);
	aMaze = game.CreateMaze(bombedMazeFactory);

	system("pause");
	return 0;
}