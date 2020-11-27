#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
vector<string> v[201];
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int age;
        string name;
        cin >> age >> name;
        v[age].push_back(name);
    }
    for(int i =1 ; i<= 200; i++){
        for(int j=0;j<v[i].size();j++){
            cout << i << ' ' << v[i][j] << '\n';
        }
    }
}
