#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> adj;
int main(){
    int n,m;
    cin >> n >> m;
    adj.resize(m+1);
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        adj[num]++;
    }
    int result = 0;
    for(int i=1;i<=m;i++) result = max(result,adj[i]);
    cout << result << '\n';
    return 0;
}
