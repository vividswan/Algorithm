#include <iostream>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int m;
    cin >> m;
    queue<int> q;
    for(int i=0;i<m;i++){
        int num;
        cin >> num;
        q.push(num);
    }
    long long result =0;
    while(!q.empty()){
        result+=(long long)(q.front() * pow(a,q.size()-1));
        q.pop();
    }
    stack<int> s;
    while(result){
        s.push(result%b);
        result/=b;
    }
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout <<'\n';

}
