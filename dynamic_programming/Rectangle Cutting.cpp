#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, numeric_limits<int>::max()));
    for (size_t i = 1; i <= a && i <= b; i++) dp[i][i] = 0;
    for (size_t i = 1; i <= a; i++) {
        for (size_t j = 1; j <= b; j++) {
            if (i == j) continue;
            for (size_t k = 1; k < i; k++) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            for (size_t k = 1; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
        }
    }
    cout << dp[a][b] << endl;
}