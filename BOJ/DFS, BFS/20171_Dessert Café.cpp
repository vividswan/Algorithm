#include <iostream>
#include <vector>
using namespace std;
bool apt[100001];
bool vis[100001];
int result;
vector<vector<pair<int,int>>> dist;
int childCnt[100001];
int dfs(int idx);
int n, k;
int main(){
    cin >> n >> k;
    dist.resize(n+1);
    result = n;
    for(int x=0;x<n-1;x++){
        int i,j,w;
        cin >> i >> j >> w;
        dist[i].push_back({j,w});
        dist[j].push_back({i,w});
    }
    for(int x=0;x<k;x++){
        int idx;
        cin >> idx;
        apt[idx] = true;
    }
    vis[1]=true;
    childCnt[1] = dfs(1);
    cout << result;
    return 0;
}
int dfs(int idx){
    int cnt = 0;
    if(apt[idx]) cnt++;
    bool swc = false;
    for(int i=0; i < dist[idx].size() ;i++){
        if(!vis[dist[idx][i].first]){
            vis[dist[idx][i].first]=true;
            int now = dfs(dist[idx][i].first);
            cnt += now;
            if(now == k) swc =true;
        }
    }
    if(swc || cnt==0) result--;
    return childCnt[idx] = cnt;
}
