#include <iostream>
#include<vector>
using namespace std;
vector<int> memo(100001,-1);
int f(int n,int k) {
    if (memo[n] != -1) return memo[n];
    if (n <= 0)return 1;
    if (n <= k)return n+1;
    return memo[n] = ( f(n - 1-k,k)+f(n - 1,k) )%5000011;
}
int main() {
    int n, k;
    cin >> n>>k;
    for (int i = n/30; i < n&&n>100; i += n / 50)
        f(i, k);
    cout << f(n, k) << endl;

    return 0;
}
