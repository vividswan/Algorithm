#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int>> adj;
int dp[101][100001];
int n, k;
int main(){
    cin >> n >> k;
    adj.resize(n+1);
    for(int i=1;i<=n;i++){
        int w,v;
        cin >> w >> v;
        adj[i]={w,v};
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]=dp[i-1][j];
            if(j-adj[i].first>=0){
                int value = dp[i-1][j-adj[i].first]+adj[i].second;
                dp[i][j]=max(dp[i][j],value);
            }
        }
    }
    cout << dp[n][k] << '\n';
    return 0;
}
