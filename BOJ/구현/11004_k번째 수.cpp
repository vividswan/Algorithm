#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> adj;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        adj.push_back(num);
    }
    sort(adj.begin(),adj.end());
    printf("%d\n",adj[k-1]);
    return 0;
}
