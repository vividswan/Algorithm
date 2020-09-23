#include <iostream>
#include <algorithm>
using namespace std;
int n;
int map[21][21];
int dp[21][21];
int main(){
    cin >> n;
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }
    dp[1][1]=map[1][1];
    for(int i=2;i<=n;i++) {
        dp[1][i] = map[1][i] + dp[1][i - 1];
        dp[i][1] = map[i][1] + dp[i-1][1];
    }
    for(int i=2; i<=n; i++){
        for(int j=2; j<=n ; j++) {
            int minn = min(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j]=minn+map[i][j];
        }
    }
    cout << dp[n][n] << '\n';
    return 0;
}
