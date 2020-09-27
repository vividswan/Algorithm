#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int dp[101][1001];
vector<pair<int,int>> adj;
int main(void){
    cin >> n >> m;
    adj.resize(n+1);
    for(int i=1;i<=n;i++){
        int score, time;
        cin >> score >> time;
        adj[i]={score,time};
    }
    for(int i=1;i<=n;i++){
        for(int j=adj[i].second; j<=m; j++){
            dp[i][j]=dp[i-1][j];
            dp[i][j]=max(dp[i][j],dp[i-1][j-adj[i].second]+adj[i].first);
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}
