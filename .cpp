#include <cstddef>
#include <iostream>

class shape
{
public:
	shape();
	virtual ~shape();
	virtual void draw() = 0;
	virtual void move(int dx, int du) = 0;
	virtual int surface() = 0;
};

class triangle : public shape
{
	triangle(int a, int b, int c)
	:shape()
	{


	}

public:
	int a;
	int b;
	int c;
};

class circle : public shape
{
public:

	circle(int x , int y, int r)
		:
		shape(),
		r{r}
	{

	}

	~circle();

	void draw()
	{
		std::cout << "circle" << std::endl;
	}

	void move(int dx, int dy)
	{
		x += dx;
		y += dy;
	}

	int surface()
	{
		return 3.14 * r * r;
	}

private:
	int r;
	int x;
	int y;
};


class ring : public shape
{
public:
	ring(int r1, int r2 , int x , int y)
	:
		inner{x, y, r1},
		outer{x, y, r2}
	{

	}

	int surface()
	{
		return outer.surface() - inner.surface();
	}

private:
	circle inner;
	circle outer;
};

class s : public shape
{
	s(int x, int y);

	void move(int dx, int dy)
	{
		x += dx;
		y += dy;
	}

private:
	int x;
	int y;
};

int main()
{
	int x = 1;
	int y = 1;
	int r = 1;
	shape* p = new circle(x, y, r);

	p->draw();

	delete p;

}