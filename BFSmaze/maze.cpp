//#pragma warning(disable:4996)
//#include<cstdio>
//#include<cstdlib>
//#include<ctime>
//#include<iostream>
//
//using namespace std;
//
//long map[10000][10000];
//int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };  //可走的四个方向
//
//struct node
//{
//    int x, y;
//};
//
//struct node queue[5000], record[5000][5000];//queue记录可走的点，广搜；
////record记录改点的前驱
//
//bool bfs(int column, int row, int startx, int starty, int endpx, int endpy)
//{
//    int head, tail, i;
//    struct node cur, next;//cur为当前位置，next为下一个位置
//    head = tail = 0;
//    //head = startx - 1;
//    //tail = starty - 1;
//    cur.x = queue[tail].x;
//    cur.y = queue[tail].y;
//    tail++;
//    while (head < tail)
//    {
//        cur = queue[head++];
//        for (i = 0; i < 4; i++)
//        {
//            next.x = cur.x + dir[i][0];
//            next.y = cur.y + dir[i][1];
//            if (next.x >= 0 && next.y >= 0 && next.x < column && next.y < row && map[next.x][next.y] == 0)
//            {
//                record[next.x][next.y].x = cur.x;
//                record[next.x][next.y].y = cur.y;//记录next的前驱，即next的坐标（因为next记录的是第一个到达该地点的前驱，随后被标记走过，故不用担心被后来的前驱坐标所覆盖）
//                if (next.x == endpx && next.y == endpy)
//                    return true;
//                else
//                {
//                    map[next.x][next.y] = 1;//标记走过
//                    queue[tail++] = next;
//                }
//            }
//        }
//    }
//    return false;
//}
//int main()
//{
//    int i, j;
//    int k, m, n, flag = 0;
//    int save, column, row, startx, starty, endpx, endpy;
//    struct node cur;
//    while (!flag)
//    {
//        cout << "请输入行和列" << endl;
//        cout << "行为:  ";
//        cin >> column;
//        cout << "列为:  ";
//        cin >> row;
//        cout << "起始位置:  ";
//        scanf("%d%d", &startx, &starty);
//        cout << "终点:  ";
//        scanf("%d%d", &endpx, &endpy);
//        srand(time(NULL));
//        for (i = 0; i < column; i++)
//        {
//            for (j = 0; j < row; j++)
//            {
//                save = (int)(rand() % 10 > 2 ? 0 : 1);
//                //cin >> save;
//                map[i][j] = save;
//                printf("%2d", save);
//            }
//            cout << endl;
//        }
//        if (map[startx][starty] == 1)
//        {
//            printf("无路径!!!\n");
//            flag = 0;
//        }
//        else
//        {
//
//            cur.x = startx;
//            cur.y = starty;
//            map[startx][starty] = 1;
//            queue[0] = cur;//可走的点为当前结点
//            if (!bfs(column, row, startx, starty, endpx, endpy)) { printf("无路径!!!\n"); flag = 0; }
//            else
//            {
//                k = 0;
//                queue[k].x = endpx;
//                queue[k++].y = endpy;
//                i = endpx;
//                j = endpy;
//                while (i != startx || j != starty)//根据record的记录，从后往前回溯其路径，并存在queue中
//                {
//                    m = i;
//                    n = j;
//                    i = record[m][n].x;
//                    j = record[m][n].y;
//                    queue[k].x = i;
//                    queue[k++].y = j;
//                }
//                for (i = k - 1; i >= 0; i--)//输出路径
//                    printf("(%d, %d)\n", queue[i].x, queue[i].y);
//                flag = 1;
//                return 0;
//
//            }
//
//        }
//    }
//}




/*
迷宫问题（广度优先算法）
作者：Lumao
版本：2021/3/28 0.0版
方法：C++ 队列 栈 数组 结构体 循环 广度优先算法
目标：找一条出路即结束
要点：队列的类型step step类型中的pre指针指向前驱，找到路径
小结：感觉有疏漏的情况
*/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#define m 6
#define n 8
int theMap[][n + 2] = {//原地图
	{ 1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,1,1,1,0,1,1,1,1 },
	{ 1,1,0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,0,1,1,1,1,1 },
	{ 1,0,1,1,1,0,0,1,1,1 },
	{ 1,1,0,0,1,1,0,0,0,1 },
	{ 1,0,1,1,0,0,1,1,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1 }
};
int maze[m + 2][n + 2];//地图
struct step
{
	int x, y;
	step* pre;
};
struct step Move[8]{
	//step 类型数组Move代表8个前进方向
	{ 0,1,NULL },
	{ 1,1,NULL },
	{ 1,0,NULL },
	{ 1,-1,NULL},
	{ 0,-1,NULL},
	{ -1,-1,NULL},
	{ -1,0,NULL},
	{ -1,1,NULL}
};
void initialize(int maze[m + 2][n + 2])//初始化地图
{
	for (int i = 0; i < m + 2; i++)
		for (int j = 0; j < n + 2; j++)
			maze[i][j] = theMap[i][j];
}
void Restore(int maze[m + 2][n + 2])//恢复原地图
{
	initialize(maze);
}
void PrintPath(step* temp1)//打印路径
{
	stack<step>s;
	while (temp1 != NULL)
	{
		s.push(*temp1);
		temp1 = temp1->pre;
	}
	while (!s.empty())
	{
		cout << "(" << s.top().x << "," << s.top().y << ")" << endl;
		s.pop();
	}
	cout << endl;
}
int MazePath()
{
	queue<step*>q;//用于广搜的队列
	step* temp1, * temp2;
	int x, y, loop;
	temp1 = new step;
	temp1->x = 1;
	temp1->y = 1;
	temp1->pre = NULL;
	maze[1][1] = -1;//标志入口已经到达过
	q.push(temp1);//将入口入列
	while (!q.empty())//队列不空，继续广搜
	{
		temp2 = q.front();
		q.pop();
		for (loop = 0; loop < 8; loop++)
		{
			x = temp2->x + Move[loop].x;
			y = temp2->y + Move[loop].y;
			if (maze[x][y] == 0)
			{
				temp1 = new step;
				temp1->x = x;
				temp1->y = y;
				temp1->pre = temp2;//设置前驱指针
				maze[x][y] = -1;//标志该位置已到达过
				q.push(temp1);
				if ((x == m) && (y == n))//到达出口
				{
					cout << "The path is:" << endl;
					PrintPath(temp1);//从temp1开始往回指向即为路径
					Restore(maze);//恢复迷宫
					return 1;//找到路径结束函数
				}
			}
		}
	}
	return 0;//没有找到路径
}
int main()
{
	initialize(maze);
	MazePath();
	system("pause");
	return 0;
}
