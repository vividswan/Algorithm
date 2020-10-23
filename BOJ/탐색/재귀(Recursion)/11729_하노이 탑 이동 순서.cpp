#include <iostream>
#include <queue>
using namespace std;
queue <pair<int,int>> q;
void recursion(int idx, int st, int ed);
int main() {
    int n;
    cin >> n;
    recursion(n, 1, 3);
    cout << q.size() << '\n';
    while (!q.empty()) {
        cout << q.front().first << ' ' << q.front().second << '\n';
        q.pop();
    }
    return 0;
}
void recursion(int idx, int st, int ed){
    if(idx==1){
        q.push({st,ed});
        return;
    }
    int mid = 6-st-ed;
    recursion(idx-1,st,mid);
    q.push({st,ed});
    recursion(idx-1,mid,ed);
}
