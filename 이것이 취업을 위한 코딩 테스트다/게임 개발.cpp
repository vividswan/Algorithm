#include <iostream>
using namespace std;
int map[51][51];
int vis[51][51];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int main(){
  int n,m;
  cin >> n >> m;
  int x,y,dir;
  cin >> x >> y >> dir;
  vis[x][y] = 1;
  for(int i=0;i<n;i++){
      for(int j=0; j<m; j++){
          cin >> map[i][j];
      }
  }
  int rotateCnt = 0;
  bool exitSwc = true;
  while(exitSwc){
      dir--;
      if(dir == -1) dir=3;
      rotateCnt++;
      int nx = x+dx[dir];
      int ny = y+dy[dir];
      if(nx<0||ny<0||nx>=n||ny>=m){
          continue;
      }
      else if(!vis[nx][ny] && !map[nx][ny]){
          x=nx;
          y=ny;
          vis[nx][ny]=1;
          rotateCnt=0;
          continue;
      }
      else if(rotateCnt==4){
          if(map[x-dx[dir]][y-dy[dir]]) {
              exitSwc=false;
              break;
          }
          else{
              rotateCnt = 0;
              x = x-dx[dir];
              y = y-dy[dir];
          }
      }
  }
  int result = 0;
  for(int i=1; i<=n;i++){
      for(int j=1;j<=m;j++){
          if(vis[i][j]) result++;
      }
  }
  cout <<result << '\n';
  return 0;
}
