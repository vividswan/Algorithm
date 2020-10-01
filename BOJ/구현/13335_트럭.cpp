#include <iostream>
#include <vector>
using namespace std;
int n,w,l, result;
vector<int> adj;
vector<int> vis;
int st=1;
int ed;
bool cnt=false;
int main(void){
    cin >> n >> w >> l;
    adj.resize(n+1);
    vis.resize(n+1);
    for(int i=1;i<=n;i++) cin >> adj[i];
    int now = 0;
    int size =0;
    while(!cnt){
        now++;
        for(int i=st;i<=ed;i++){
            vis[i]++;
            if(vis[i]>w) {
                st++;
                size-=adj[i];
                if(i==n) {
                    cnt=true;
                    break;
                }
            }
        }
        if(cnt) break;
        if(size+adj[ed+1]<=l){
            ed++;
            vis[ed]=1;
            size+=adj[ed];
        }
    }
    cout << now << '\n';
    return 0;
}
