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
//	if (x < 0 || y < 0 || x > 3 || y > 5)//Խ�緵�� 
//		return;
//	if (x == 3 && y == 3)
//	{
//			path = tpath; //����ҵ��˳���,���¼��·��
//		return;
//	}
//	for (int ix = 0; ix < 4; ix++)//�ĸ��������� 
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
//	search(tpath, 0, 0);//�ӿ�ʼ������ .
//	cout << "Path found: " << endl;
//	for (int i = 0; i < path.size(); i++)
//	{
//		cout << "(" << path[i].first << ", " << path[i].second << ") ";
//	}
//	cout << endl;
//}
////���⣬����δ����У�û�д����Թ��޽�������
////����Թ��޽⣬�����һֱִ����ȥ��
////ֱ������·���������Թ��������
////��ʱ path �м�¼�������һ�������Ե�·����
////�����Ҫ�ж��Թ��Ƿ��н⣬���������������ж� path �Ƿ�Ϊ�գ�
////���Ϊ�����ʾ�Թ��޽⡣

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
bool visited[4][6] = { false }; // ��¼ÿ��λ���Ƿ��Ѿ����ʹ�

void search(vector<pair<int, int> > tpath, int x, int y)
{
    if (x < 0 || y < 0 || x >= 4 || y >= 6 || visited[x][y] || maze[x][y] == 0) // Խ�硢�ѷ��ʹ���Ϊǽ
        return;

    if (x == 3 && y == 1)
    {
        path = tpath;
        return;
    }

    

    for (int ix = 0; ix < 4; ix++)
    {
        tpath.push_back(make_pair(x, y)); visited[x][y] = true; // ��ǵ�ǰλ��Ϊ�ѷ���
        search(tpath, x + dir[ix][0], y + dir[ix][1]); visited[x][y] = false; // ����ʱ����ǰλ�õı������Ϊδ����
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
