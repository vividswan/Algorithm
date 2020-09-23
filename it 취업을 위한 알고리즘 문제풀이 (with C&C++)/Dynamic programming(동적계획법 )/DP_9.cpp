#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int map[21][21];
int dp[21][21];
int recursion(int x, int y);
int main(void){
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    dp[1][1]=map[1][1];
    cout << recursion(n,n) << '\n';
    return 0;
}
int recursion(int x, int y){
    if(dp[x][y]!=-1) return dp[x][y];
    if(x==1) return dp[x][y] = recursion(x,y-1)+map[x][y];
    if(y==1) return dp[x][y] = recursion(x-1,y)+map[x][y];
    int minn = min(recursion(x-1,y),recursion(x,y-1));
    return dp[x][y]=map[x][y]+minn;
}
