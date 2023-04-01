#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 75;
const int INF = 0x3f3f3f3f;//表示无穷大路径

int n, m, k, q;
int dp[N][N][N];//dp[i][j][k]表示从i到j经过k条边的最短路径

int main()
{
    cin >> n >> m;//n个空间站，m个通道

    // 初始化
    memset(dp, 0x3f, sizeof dp);//均无穷大
    for (int i = 1; i <= n; i++)//所有空间站自己和自己距离0
        dp[i][i][1] = 0;

    // 输入太空站之间的通道信息
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b][1] = min(dp[a][b][1], c);//
    }

    cin >> k >> q;//最多通过 k 条不同的通道和查询次数

    // floyd优化，枚举中转点、经过的边数、起点和终点
    for (int h = 2; h <= k; h++)//h经过的边数
        for (int l = 1; l <= n; l++)//l中转点
            for (int i = 1; i <= n; i++)//i起点
                for (int j = 1; j <= n; j++)//j终点
                    for (int r = 1; r <= h; r++)//r中间
                        dp[i][j][h] = min(dp[i][j][h], dp[i][r][h-r] + dp[r][j][r]);

    // 处理查询
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
