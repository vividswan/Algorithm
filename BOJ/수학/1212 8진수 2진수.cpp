#include <iostream>
#include <stack>
using namespace std;
int main(){
    string str;
    cin >> str;
    int  size = str.length();
    long long result = 0;
    int cnt = 0;
    stack<int> s;
    int now = str[0] - '0';
    if(!now){
        cout << 0 << '\n';
        return 0;
    }
    while (now){
        s.push(now%2);
        now/=2;
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    for(int i=1;i<str.length();i++){
        int now = str[i]-'0';
        int arr[3];
        for(int j=2;j>=0;j--) {
            arr[j]=now%2;
            now/=2;
        }
        for(int j=0;j<3;j++) cout << arr[j];
    }
    cout << '\n';
    return 0;
}
