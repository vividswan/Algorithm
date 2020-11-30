#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
vector<ll> v;
int n;
int main(){
    cin >> n;
    for(int i=0;i<n;i++) {
        long long num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    int cnt = 1;
    long long bef = v[0];
    int maxCnt = 0;
    long long best;
    for(int i=1;i<v.size();i++){
        if(v[i]!=bef){
            if(maxCnt<cnt){
                maxCnt=cnt;
                best = bef;
            }
            cnt = 1;
            bef=v[i];
            continue;
        }
        cnt++;
        bef = v[i];
    }
    if(maxCnt<cnt){
        best=bef;
    }
    cout << best << '\n';
    return 0;
}
