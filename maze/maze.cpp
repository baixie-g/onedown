//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include <utility>
//using namespace std;
//
//int maze[4][6] = { {1, 1, 0, 0, 0, 0},
// {0, 1, 1, 1, 0, 0},
// {1, 1, 0, 1, 0, 0},
// {0, 0, 0, 1, 0, 0} };
//vector<pair<int, int> > path;
//int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
//void search(vector<pair<int, int> > tpath, int x, int y)
//{
//	if (x < 0 || y < 0 || x > 3 || y > 5)//越界返回 
//		return;
//	if (x == 3 && y == 3)
//	{
//			path = tpath; //如果找到了出口,则记录下路径
//		return;
//	}
//	for (int ix = 0; ix < 4; ix++)//四个方向搜索 
//	{
//		if (maze[x + dir[ix][0]][y + dir[ix][1]] == 1)
//		{
//			
//			tpath.push_back(make_pair(x, y));
//			search(tpath, x + dir[ix][0], y + dir[ix][1]);
//			tpath.pop_back();
//		}
//	}
//}
//int main()
//{
//	vector<pair<int, int> > tpath;
//	search(tpath, 0, 0);//从开始点找起 .
//	cout << "Path found: " << endl;
//	for (int i = 0; i < path.size(); i++)
//	{
//		cout << "(" << path[i].first << ", " << path[i].second << ") ";
//	}
//	cout << endl;
//}
////此外，在这段代码中，没有处理迷宫无解的情况，
////如果迷宫无解，则程序将一直执行下去，
////直到所有路径都被尝试过后结束，
////此时 path 中记录的是最后一条被尝试的路径。
////如果需要判断迷宫是否有解，可以在主函数中判断 path 是否为空，
////如果为空则表示迷宫无解。

#include<iostream>
#include<algorithm>
#include<vector>
#include <utility>
using namespace std;

int maze[4][6] = { {1, 1, 1, 1, 0, 0},
                   {0, 0, 0, 1, 0, 0},
                   {1, 1, 1, 1, 0, 0},
                   {0, 1, 0, 0, 0, 0} };
vector<pair<int, int> > path;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
bool visited[4][6] = { false }; // 记录每个位置是否已经访问过

void search(vector<pair<int, int> > tpath, int x, int y)
{
    if (x < 0 || y < 0 || x >= 4 || y >= 6 || visited[x][y] || maze[x][y] == 0) // 越界、已访问过或为墙
        return;

    if (x == 3 && y == 1)
    {
        path = tpath;
        return;
    }

    

    for (int ix = 0; ix < 4; ix++)
    {
        tpath.push_back(make_pair(x, y)); visited[x][y] = true; // 标记当前位置为已访问
        search(tpath, x + dir[ix][0], y + dir[ix][1]); visited[x][y] = false; // 回溯时将当前位置的标记重置为未访问
        tpath.pop_back();
    }

    
}

int main()
{
    vector<pair<int, int> > tpath;
    search(tpath, 0, 0);

    if (path.empty())
    {
        cout << "No path found!" << endl;
    }
    else
    {
        cout << "Path found: " << endl;
        for (int i = 0; i < path.size(); i++)
        {
            cout << "(" << path[i].first << ", " << path[i].second << ") ";
        }
        cout << endl;
    }

    return 0;
}
