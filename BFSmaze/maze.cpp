//#pragma warning(disable:4996)
//#include<cstdio>
//#include<cstdlib>
//#include<ctime>
//#include<iostream>
//
//using namespace std;
//
//long map[10000][10000];
//int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };  //���ߵ��ĸ�����
//
//struct node
//{
//    int x, y;
//};
//
//struct node queue[5000], record[5000][5000];//queue��¼���ߵĵ㣬���ѣ�
////record��¼�ĵ��ǰ��
//
//bool bfs(int column, int row, int startx, int starty, int endpx, int endpy)
//{
//    int head, tail, i;
//    struct node cur, next;//curΪ��ǰλ�ã�nextΪ��һ��λ��
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
//                record[next.x][next.y].y = cur.y;//��¼next��ǰ������next�����꣨��Ϊnext��¼���ǵ�һ������õص��ǰ������󱻱���߹����ʲ��õ��ı�������ǰ�����������ǣ�
//                if (next.x == endpx && next.y == endpy)
//                    return true;
//                else
//                {
//                    map[next.x][next.y] = 1;//����߹�
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
//        cout << "�������к���" << endl;
//        cout << "��Ϊ:  ";
//        cin >> column;
//        cout << "��Ϊ:  ";
//        cin >> row;
//        cout << "��ʼλ��:  ";
//        scanf("%d%d", &startx, &starty);
//        cout << "�յ�:  ";
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
//            printf("��·��!!!\n");
//            flag = 0;
//        }
//        else
//        {
//
//            cur.x = startx;
//            cur.y = starty;
//            map[startx][starty] = 1;
//            queue[0] = cur;//���ߵĵ�Ϊ��ǰ���
//            if (!bfs(column, row, startx, starty, endpx, endpy)) { printf("��·��!!!\n"); flag = 0; }
//            else
//            {
//                k = 0;
//                queue[k].x = endpx;
//                queue[k++].y = endpy;
//                i = endpx;
//                j = endpy;
//                while (i != startx || j != starty)//����record�ļ�¼���Ӻ���ǰ������·����������queue��
//                {
//                    m = i;
//                    n = j;
//                    i = record[m][n].x;
//                    j = record[m][n].y;
//                    queue[k].x = i;
//                    queue[k++].y = j;
//                }
//                for (i = k - 1; i >= 0; i--)//���·��
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
�Թ����⣨��������㷨��
���ߣ�Lumao
�汾��2021/3/28 0.0��
������C++ ���� ջ ���� �ṹ�� ѭ�� ��������㷨
Ŀ�꣺��һ����·������
Ҫ�㣺���е�����step step�����е�preָ��ָ��ǰ�����ҵ�·��
С�᣺�о�����©�����
*/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#define m 6
#define n 8
int theMap[][n + 2] = {//ԭ��ͼ
	{ 1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,1,1,1,0,1,1,1,1 },
	{ 1,1,0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,0,1,1,1,1,1 },
	{ 1,0,1,1,1,0,0,1,1,1 },
	{ 1,1,0,0,1,1,0,0,0,1 },
	{ 1,0,1,1,0,0,1,1,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1 }
};
int maze[m + 2][n + 2];//��ͼ
struct step
{
	int x, y;
	step* pre;
};
struct step Move[8]{
	//step ��������Move����8��ǰ������
	{ 0,1,NULL },
	{ 1,1,NULL },
	{ 1,0,NULL },
	{ 1,-1,NULL},
	{ 0,-1,NULL},
	{ -1,-1,NULL},
	{ -1,0,NULL},
	{ -1,1,NULL}
};
void initialize(int maze[m + 2][n + 2])//��ʼ����ͼ
{
	for (int i = 0; i < m + 2; i++)
		for (int j = 0; j < n + 2; j++)
			maze[i][j] = theMap[i][j];
}
void Restore(int maze[m + 2][n + 2])//�ָ�ԭ��ͼ
{
	initialize(maze);
}
void PrintPath(step* temp1)//��ӡ·��
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
	queue<step*>q;//���ڹ��ѵĶ���
	step* temp1, * temp2;
	int x, y, loop;
	temp1 = new step;
	temp1->x = 1;
	temp1->y = 1;
	temp1->pre = NULL;
	maze[1][1] = -1;//��־����Ѿ������
	q.push(temp1);//���������
	while (!q.empty())//���в��գ���������
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
				temp1->pre = temp2;//����ǰ��ָ��
				maze[x][y] = -1;//��־��λ���ѵ����
				q.push(temp1);
				if ((x == m) && (y == n))//�������
				{
					cout << "The path is:" << endl;
					PrintPath(temp1);//��temp1��ʼ����ָ��Ϊ·��
					Restore(maze);//�ָ��Թ�
					return 1;//�ҵ�·����������
				}
			}
		}
	}
	return 0;//û���ҵ�·��
}
int main()
{
	initialize(maze);
	MazePath();
	system("pause");
	return 0;
}
