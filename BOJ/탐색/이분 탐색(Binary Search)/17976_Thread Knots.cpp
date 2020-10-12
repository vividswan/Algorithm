#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n, le, ri,ans;
vector<pair<long long,long long>> adj;
bool isPossible(long long val);
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        long long st,ed;
        cin >> st >> ed;
        adj.push_back({st,st+ed});
        ri=max(ri,st+ed);
    }
    sort(adj.begin(),adj.end());
    while(le<=ri){
        long long mid = (le+ri)/2;
        if(isPossible(mid)) {
            ans=mid;
            le =mid+1;
        }
        else ri = mid-1;
    }
    cout << ans << '\n';
    return 0;
}
bool isPossible(long long val){
    long long now = adj[0].first;
    for(int i=1;i<n;i++){
        if(now+val > adj[i].second) return false;
        else {
            now = max(adj[i].first,now+val);
        }
    }
    return true;
}
