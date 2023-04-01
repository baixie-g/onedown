#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 75;
const int INF = 0x3f3f3f3f;//��ʾ�����·��

int n, m, k, q;
int dp[N][N][N];//dp[i][j][k]��ʾ��i��j����k���ߵ����·��

int main()
{
    cin >> n >> m;//n���ռ�վ��m��ͨ��

    // ��ʼ��
    memset(dp, 0x3f, sizeof dp);//�������
    for (int i = 1; i <= n; i++)//���пռ�վ�Լ����Լ�����0
        dp[i][i][1] = 0;

    // ����̫��վ֮���ͨ����Ϣ
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b][1] = min(dp[a][b][1], c);//
    }

    cin >> k >> q;//���ͨ�� k ����ͬ��ͨ���Ͳ�ѯ����

    // floyd�Ż���ö����ת�㡢�����ı����������յ�
    for (int h = 2; h <= k; h++)//h�����ı���
        for (int l = 1; l <= n; l++)//l��ת��
            for (int i = 1; i <= n; i++)//i���
                for (int j = 1; j <= n; j++)//j�յ�
                    for (int r = 1; r <= h; r++)//r�м�
                        dp[i][j][h] = min(dp[i][j][h], dp[i][r][h-r] + dp[r][j][r]);

    // �����ѯ
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (a == b) puts("0");
        else
        {
            int res = INF;
            for (int i = 1; i <= k; i++) res = min(res, dp[a][b][i]);
            if (res == INF) puts("-1");
            else printf("%d\n", res);
        }
    }

    return 0;
}
