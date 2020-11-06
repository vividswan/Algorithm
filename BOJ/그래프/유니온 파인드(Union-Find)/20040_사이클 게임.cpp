#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> parent;
vector<int> level;
int find(int u){
    if(u==parent[u]) return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return;

    if (level[u] > level[v]) swap(u, v);

    parent[u] = v;

    if (level[u] == level[v]) ++level[v];
}

int main(){
    cin >> n >> m;
    parent.resize(n+1);
    level.resize(n+1);
    for(int i=1;i <=n;i++){
        parent[i]=i;
        level[i]=1;
    }
    int swc = 0;
    for(int i=1;i<=m;i++){
        int st, ed;
        cin >> st >> ed;
        if(find(st) == find(ed)) {
            swc=i;
            break;
        }
        merge(st,ed);
    }
    cout << swc << '\n';
}
