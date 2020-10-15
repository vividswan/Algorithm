#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<deque<char>> map;
int n;
int main(){
    cin >> n;
    map.resize(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            map[j].push_front(' ');
        }
        bool swc=true;
        for(int j=1;j<=2*i-1;j++){
            if(swc)  map[i].push_back('*');
            else map[i].push_back(' ');
            swc = !swc;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<map[i].size();j++){
            cout << map[i][j];
        }
        cout << '\n';
    }
    return 0;
}
