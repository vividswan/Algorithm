#include <iostream>
#include <vector>
using namespace std;
int t;
int main(){
    cin >> t;
    for(int i=1; i<=t; i++){
        int num;
        cin >> num;
        bool swc=false;
        for(int j=2;j<=64;j++){
            int now = num;
            vector<int> adj;
            while(now){
                adj.push_back(now%j);
                now/=j;
            }
            bool isSuccess=true;
            for(int k=0;k<adj.size()/2;k++){
                if(adj[k]!=adj[adj.size()-k-1]){
                    isSuccess=false;
                    break;
                }
            }
            if(isSuccess) swc= true;
            if(swc) {
                cout << 1 << '\n';
                break;
            }
        }
        if(!swc) cout << 0 << '\n';
    }
    return 0;
}
