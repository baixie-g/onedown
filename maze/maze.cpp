#include<iostream>
#include<algorithm>
#include<vector>
#include <utility>
using namespace std;

int maze[4][6] = { {1, 1, 0, 0, 0, 0},
 {0, 1, 1, 1, 0, 0},
 {1, 1, 0, 1, 0, 0},
 {0, 0, 0, 1, 0, 0} };
vector<pair<int, int> > path;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
void search(vector<pair<int, int> > tpath, int x, int y)
{
	if (x < 0 || y < 0 || x > 5 || y > 3)//越界返回 
		return;
	if (x == 3 && y == 3)
	{
			path = tpath; //如果找到了出口,则记录下路径
		return;
	}
	for (int ix = 0; ix < 4; ix++)//四个方向搜索 
	{
		if (maze[x + dir[ix][0]][y + dir[ix][1]] == 1)
		{
			
			tpath.push_back(make_pair(x, y));
			search(tpath, x + dir[ix][0], y + dir[ix][1]);
			tpath.pop_back();
		}
	}
}
int main()
{
	vector<pair<int, int> > tpath;
	search(tpath, 0, 0);//从开始点找起 
}