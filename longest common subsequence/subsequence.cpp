#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 定义函数，输入两个字符串，返回最长公共子序列
string LCS(const string& s1, const string& s2) {
    int n1 = s1.size(), n2 = s2.size();
    // 定义二维数组dp，dp[i][j]表示s1前i个字符和s2前j个字符的最长公共子序列长度
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    // 遍历s1和s2，填充dp数组
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // 如果s1[i-1]和s2[j-1]相等，则dp[i][j]等于dp[i-1][j-1]+1
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 如果s1[i-1]和s2[j-1]不相等，则dp[i][j]等于dp[i-1][j]和dp[i][j-1]的最大值
            }
        }
    }
    string result;
    // 从dp数组中获取最长公共子序列
    for (int i = n1, j = n2; i > 0 && j > 0;) {
        if (s1[i - 1] == s2[j - 1]) {
            result = s1[i - 1] + result; // 如果s1[i-1]和s2[j-1]相等，则将s1[i-1]加入到result中
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; // 如果dp[i-1][j]大于dp[i][j-1]，则i减1
        }
        else {
            j--; // 否则j减1
        }
    }
    return result;
}

int main() {
    string s1, s2;
    cout << "Please enter the first string: ";
    cin >> s1;
    cout << "Please enter the second string: ";
    cin >> s2;
    string lcs = LCS(s1, s2);
    cout << "The longest common subsequence is: " << lcs << endl; // 输出最长公共子序列
    return 0;
}
