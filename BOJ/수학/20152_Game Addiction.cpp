#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m;
long long map[32][32];
int main(){
    memset(map,0,sizeof(map));
    cin >> n >> m;
    if(n==m){
        cout << 1 << '\n';
        return 0;
    }
    int si = abs(n-m)+1;
    for(int i=1;i<si;i++) map[i][0]=1;
    for(int i=1;i<si;i++){
        for(int j =1;j<si;j++){
            if(j>i) continue;
            map[i][j]=map[i-1][j]+map[i][j-1];
        }
    }
    cout << map[si-1][si-1] << '\n';
    return 0;
}
