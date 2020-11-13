#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
vector<vector<int>> adj;
vector<vector<int>> vis;
int result;
int n, m;
void bfs(int x, int y);
int main(){
    scanf("%d %d",&n,&m);
    adj.resize(n);
    vis.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num;
            scanf("%1d",&num);
            adj[i].push_back(num);
            vis[i].push_back(0);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]) continue;
            if(vis[i][j]) continue;
            result++;
            bfs(i,j);
        }
    }
    printf("%d\n",result);
    return 0;
}
void bfs(int x, int y){
    vis[x][y]=1;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        int nowX=q.front().first;
        int nowY= q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = nowX+dx[i];
            int ny = nowY+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(adj[nx][ny]) continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
}
