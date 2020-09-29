#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int dp[301][2];
vector<int> adj;
int main(){
    cin >> n;
    adj.resize(n+1);
    for(int i=1; i<=n; i++){
        cin >> adj[i];
    }
    dp[1][0]=adj[1];
    dp[1][1]=0;
    for(int i=2;i<=n;i++){
        dp[i][0]=max(dp[i-2][0],dp[i-2][1]);
        dp[i][0]+=adj[i];
        dp[i][1]=dp[i-1][0] + adj[i];
    }
    cout << max(dp[n][0],dp[n][1]) << '\n';
    return 0;
}
