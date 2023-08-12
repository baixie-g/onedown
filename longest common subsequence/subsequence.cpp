#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ���庯�������������ַ��������������������
string LCS(const string& s1, const string& s2) {
    int n1 = s1.size(), n2 = s2.size();
    // �����ά����dp��dp[i][j]��ʾs1ǰi���ַ���s2ǰj���ַ�������������г���
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    // ����s1��s2�����dp����
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // ���s1[i-1]��s2[j-1]��ȣ���dp[i][j]����dp[i-1][j-1]+1
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // ���s1[i-1]��s2[j-1]����ȣ���dp[i][j]����dp[i-1][j]��dp[i][j-1]�����ֵ
            }
        }
    }
    string result;
    // ��dp�����л�ȡ�����������
    for (int i = n1, j = n2; i > 0 && j > 0;) {
        if (s1[i - 1] == s2[j - 1]) {
            result = s1[i - 1] + result; // ���s1[i-1]��s2[j-1]��ȣ���s1[i-1]���뵽result��
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; // ���dp[i-1][j]����dp[i][j-1]����i��1
        }
        else {
            j--; // ����j��1
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
    cout << "The longest common subsequence is: " << lcs << endl; // ��������������
    return 0;
}
