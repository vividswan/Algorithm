#include <iostream>
#include <cstring>
using namespace std;
bool isFriend[10][10];
bool isFind[10];
int c, n, m;
int recursion(bool isFind[10]);
int main(){
    cin >> c;
    while(c--){
        memset(isFriend,false,sizeof(isFriend));
        memset(isFind,false,sizeof(isFind));
        cin >> n >> m;
        for(int i=1;i<=m;i++){
            int st, ed;
            cin >> st >> ed;
            isFriend[st][ed] = true;
            isFriend[ed][st] = true;
        }
        int result = recursion(isFind);
        cout << result << '\n';
    }
}
int recursion(bool isFind[10]){
    int firstSearch = - 1;
    for(int i=0;i<n;i++){
        if(!isFind[i]){
            firstSearch = i;
            break;
        }
    }
    if(firstSearch== -1) return 1;
    int ret = 0;
    for(int i=firstSearch+1;  i<n; i++){
        if(!isFind[i] && isFriend[firstSearch][i]){
            isFind[firstSearch] = true;
            isFind[i] = true;
            ret += recursion(isFind);
            isFind[firstSearch] = false;
            isFind[i]=false;
        }
    }
    return ret;
}
