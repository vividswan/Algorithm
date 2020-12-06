#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string str;
vector<string> v;
int main(){
    cin >> str;
    for(int i=0;i<str.length();i++){
        string now;
        for(int j=i;j<str.length();j++){
            now.push_back(str[j]);
        }
        v.push_back(now);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout << v[i] << '\n';
    }
    return 0;
}
