#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int>> map;
int nextMove[4][3][2] = {{{0,0},{1,0},{1,1}},{{0,0},{1,0},{1,-1}},{{0,0},{0,1},{1,1}},{{0,0},{0,1},{1,0}}};
bool isOk(vector<vector<int>>& map, int y, int x, int type ,int value );
int chkMap(vector<vector<int>>& map);
int c, h, w;
int main(){
    cin >> c;
    while(c--){
        map.clear();
        cin >> h >> w;
        map.resize(h+1);
        for(int i=1;i<=h;i++){
            map[i].push_back(0);
            for(int j=1; j<=w;j++){
                char nowLot;
                cin >> nowLot;
                if(nowLot=='#') map[i].push_back(1);
                else map[i].push_back(0);
            }
        }
        int result = chkMap(map);
        cout << result << '\n';
    }
    return 0;
}
bool isOk(vector<vector<int>>& map, int y, int x, int type ,int value ){
    bool isOk = true;
    for(int i=0;i<3;i++){
        int ny = y + nextMove[type][i][0];
        int nx = x + nextMove[type][i][1];
        if(ny<1||nx<1||ny>h||nx>w) isOk = false;
        else if((map[ny][nx]+=value) > 1) isOk = false;
    }
    return isOk;
}
int chkMap(vector<vector<int>>& map){
    int y = -1;
    int x = -1;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(map[i][j]==0){
                y=i;
                x=j;
                break;
            }
        }
        if(y!=-1) break;
    }
    if(y ==-1) return 1;
    int ret = 0;
    for(int i=0;i<4;i++){
        if(isOk(map, y,x,i,1)) ret += chkMap(map);
        isOk(map,y,x,i,-1);
    }
    return ret;
}
