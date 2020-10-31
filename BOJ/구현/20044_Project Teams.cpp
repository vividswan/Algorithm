#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> adj;
    adj.resize(2*n+1);
    adj[0]=-1;
    for(int i=1;i<=2*n;i++){
        cin >> adj[i];
    }
    sort(adj.begin(),adj.end());
    int result = (adj[1]+adj[2*n]);
    for(int i=2;i<=n;i++){
        result = min(result, (adj[i]+adj[2*n-i+1]));
    }
    cout << result << '\n';
    return 0;
}
