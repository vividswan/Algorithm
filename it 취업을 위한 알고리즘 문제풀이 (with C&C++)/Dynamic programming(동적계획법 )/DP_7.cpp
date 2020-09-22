#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,pair<int,int>>> adj;
vector<int> dp;
int n, result;
int main(){
    cin >> n;
    adj.resize(n+1);
    dp.resize(n+1);
    for(int i=1;i<=n;i++) {
        int area, height, weight;
        cin >> area >> height >> weight;
        adj[i] = {area, {height, weight}};
    }
    sort(adj.begin(),adj.end(),greater<>());
    dp[1]=adj[1].second.first;
    for(int i=1;i<=n;i++){
        int nowMax=0;
        for(int j=1;j<i;j++){
            if(adj[i].second.second<adj[j].second.second){
                nowMax=max(nowMax,dp[j]);
            }
        }
        dp[i]=nowMax+adj[i].second.first;
    }
    for(int i=1;i<=n;i++){
        result = max(result,dp[i]);
    }
    cout << result << '\n';
    return 0;
}
