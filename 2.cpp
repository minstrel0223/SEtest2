
#include<iostream> 
#include<cmath> 
#include<set> 
#include<algorithm> 
#include<vector> 
#include<cstdio> 
#include<time.h>
#define PI acos(-1)
using namespace std;
int matrix[100][100];
int po=0;
struct point
{
	int x, y;
};
point blocks[3];
struct circle
{
	point m;
	double r;
};
circle Tcircle[6];

void InitTcirlce()
{
	for (int i = 0; i < 6; i++)
	{
		Tcircle[i].m.x = 120;
		Tcircle[i].m.y = 120;
		Tcircle[i].r = 1;
	}
}

double GetDistance(point p1, point p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

point GetMid(point p1, point p2)
{
	point theMid;
	theMid.x = (p1.x + p2.x) / 2;
	theMid.y = (p1.y + p2.y) / 2;
	return theMid;
}

void MakeBlocks()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 3; i++)
	{
		blocks[i].x = rand() % 100;
		blocks[i].y = rand() % 100;

	}
}

bool IfCircle(point m,int r)
{
	if (r <= m.x&&m.x <= 100 - r)
	{
		for (int i = 0; i < 3; i++)
		{
			if (GetDistance(blocks[i], m) < r)
				return false;
		}
		for (int j = 0; j < 6; j++)
		{
			if (GetDistance(Tcircle[j].m, m) < r)
				return false;
		}
		circle c;
		c.m = m;
		c.r = r;
		Tcircle[po]=c;
		po++;
		return true;
	}
	else return false;
}

int Max(int x, int y, int s)
{
	int z = x;   
	if (z<y) z = y;
	if (z<s) z = s;
	return z;
}

int main()
{
	MakeBlocks();
	InitTcirlce();
	int max = 0;
	max = Max(GetDistance(blocks[0], blocks[1]), GetDistance(blocks[]));


}
