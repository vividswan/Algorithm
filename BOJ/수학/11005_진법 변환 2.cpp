#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<long long>s;
    long long num , sel;
    cin >> num >> sel;
    while(num){
        s.push(num%sel);
        num/=sel;
    }
    while(!s.empty()){
        long long now = s.top();
        s.pop();
        if(now>=10) cout << char('A'-10+now);
        else cout << now;
    }
    cout << '\n';
    return 0;
}
