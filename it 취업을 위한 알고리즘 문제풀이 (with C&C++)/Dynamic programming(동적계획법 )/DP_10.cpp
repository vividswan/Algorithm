#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, v;
vector<int>dp;
vector<pair<int,int>> adj;
int main(){
    cin >> n >> v;
    dp.resize(v+1);
    for(int i=0;i<n;i++){
        int weight, value;
        cin >> weight >> value;
        adj.push_back({weight,value});
    }
    for(int i=0; i<adj.size();i++){
        int weight=adj[i].first;
        int value = adj[i].second;
        for(int j=weight;j<=v;j++){
            if(dp[j]<dp[j-weight]+value){
                dp[j]=dp[j-weight]+value;
            }
        }
    }
    cout << dp[v] << '\n';
    return 0;
}
