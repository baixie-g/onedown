#include<iostream>
#include<cmath>
using namespace std;
#define M 100
#define INF 1000
int n;//ǽ�ĸ���
double A[M][M];//����ͼ�бߵ�Ȩֵ
struct Wall {
    double x;
    double y[4];//�洢�����ŵķ�Χ
}wall[19];
bool isAccess(int i, int j, int n1, int n2) {//�жϵ�i��ǽ�ĵ�n1���㵽��j��ǽ�ĵ�n2�����Ƿ����
    if (i + 1 == j)
        return true;//����ǽ�������������
    //�����������֮���ֱ�� y = kx + b
    double x1 = wall[i].x, x2 = wall[j].x;
    double y1 = wall[i].y[n1], y2 = wall[j].y[n2];//������ĺ�������
    double k = (y1 - y2) / (x1 - x2);       //�������֮���б��
    double b = y1 - k * x1;                 //��ʽ���b

    for (int m = i + 1; m < j; m++) {//����i �� j ǽ֮�������ǽ �۲��Ƿ����
        double mx = wall[m].x;          //��m��ǽ�ĺ�����
        double my = k * mx + b;      //ֱ�߾�����m��ǽʱ��������
        if (!((my >= wall[m].y[0] && my <= wall[m].y[1]) || (my >= wall[m].y[2] && my <= wall[m].y[3])))//�ж�����ֱ���ܷ�˳����ǽ�е���ͨ��
            //��ȻҲ�����ÿ���ʵ���ж��Ƿ��ཻ
            return false;
    }
    return true;
}
void addEdge(int i, int j, int m, int n) {//��i��ǽ�ĵ�m���� ���j��ǽ�ĵ�n���� ����
    if (isAccess(i, j, m, n)) {           //�ж�������֮���Ƿ���Ե���
        double x1 = wall[i].x, x2 = wall[j].x;
        double y1 = wall[i].y[m], y2 = wall[j].y[n];
        double distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); //�������
        A[i * 4 + m][j * 4 + n] = distance;//�����ÿ���㶼�����˱��
    }
}
int main() {
    cout << "���������ǽ�ĸ���: " << endl;
    cin >> n;
    //��ʼ��ͼ
    for (int i = 0; i < 4 * n + 8; i++)
        for (int j = 0; j < 4 * n + 8; j++)
            A[i][j] = INF;      //��ʼ�������б߶���ͨ ��ʼ������ȨֵΪ�����
    wall[0].x = 0, wall[n + 1].x = 10;//�����յ�ǽ�ĺ�����
    for (int i = 0; i < 4; i++)
        wall[0].y[i] = wall[n + 1].y[i] = 5;//�������յ��ŵ������긳ֵ
    cout << "����ǽ�ĺ������ǽ�����ŵ������귶Χ: " << endl;
    for (int i = 1; i <= n; i++) {
        cin >> wall[i].x;//����ǽ�ĺ�����
        for (int j = 0; j < 4; j++)
            cin >> wall[i].y[j];//����ǽ�����ŵ������귶Χ
    }
    for (int i = 0; i <= n; i++) {//��i��ǽ �ӵ�0�¼���� ����n �½��� n+1��Ϊ����
        for (int j = i + 1; j <= n + 1; j++) {//��i��ǽ����j��ǽ����
            for (int m = 0; m < 4; m++) {//��i��ǽ�ĵ�m����
                for (int n = 0; n < 4; n++) {//����j��ǽ�ĵ�n����
                    addEdge(i, j, m, n);//i��ǽ�ĵ�m���˿� ��j��ǽ��n���˿ڽ���
                }
            }
        }
    }
    //Floyd�㷨�����·�� 
    for (int k = 0; k < n * 4 + 8; k++)
        for (int i = 0; i < n * 4 + 8; i++)
            for (int j = 0; j < n * 4 + 8; j++)
                if (A[i][j] > A[i][k] + A[k][j])
                    A[i][j] = A[i][k] + A[k][j];
    cout << "���·�ĳ���Ϊ��" << A[0][n * 4 + 7] << endl;
    return 0;
}
