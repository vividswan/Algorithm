#include <iostream>
#include <vector>
using namespace std;
int n, result;
vector<int> adj;
vector<int> dp;
int main(void){
    cin >> n;
    adj.resize(n+1);
    dp.resize(n+1);
    for(int i=1;i<=n;i++) {
        cin >> adj[i];
        dp[i]=adj[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(adj[j]<adj[i]){
                dp[i]=max(dp[i],dp[j]+adj[i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        result = max(result, dp[i]);
    }
    cout << result << '\n';
    return 0;
}
