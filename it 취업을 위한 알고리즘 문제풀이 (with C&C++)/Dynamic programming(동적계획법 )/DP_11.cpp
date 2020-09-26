#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> adj;
vector<int> dp;
int main(){
    int n;
    cin >> n;
    adj.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> adj[i];
    }
    int value;
    cin >> value;
    dp.resize(value+1);
    fill(dp.begin(),dp.end(),1001);
    for(int i=1;i<=n;i++) dp[adj[i]]=1;
    for(int i=1;i<=n;i++){
        for(int j=adj[i];j<=value;j++){
            dp[j]=min(dp[j],dp[j-adj[i]]+1);
        }
    }
    cout << dp[value] << '\n';
    return 0;
}
