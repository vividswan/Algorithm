#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<deque<char>> map;
int main(){
    int n;
    cin >> n;
    map.resize(n+1);
    for(int i=1;i<n;i++){
        for(int j=1;j<i;j++){
            map[j].push_front(' ');
        }
        for(int j=1;j<=2*i-1;j++){
            if(j==1 || j==2*i-1){
                map[i].push_back('*');
            }
            else {
                map[i].push_back(' ');
            }
        }
    }
    for(int j=1;j<n;j++){
        map[j].push_front(' ');
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<map[i].size();j++){
            cout << map[i][j];
        }
        cout << '\n';
    }

    for(int i=1;i<=2*n-1;i++) cout << '*';
    cout << '\n';
    return 0;
}
