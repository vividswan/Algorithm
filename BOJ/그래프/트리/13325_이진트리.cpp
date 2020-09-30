#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int k, edgeCnt, edgeSum;
vector<int> edge;
vector<int> minValue;
void dfs(int idx,int sum){
    if(idx*2+1<=edgeCnt) dfs(idx*2+1,sum+edge[idx*2+1]);
    if(idx*2+2<=edgeCnt) dfs(idx*2+2,sum+edge[idx*2+2]);
    edgeSum=max(edgeSum,sum);
}
int recursion(int idx,int sum){
    if(idx*2+1>edgeCnt || idx*2+2>edgeCnt) {
        return minValue[idx] = edgeSum-sum;
    }
    minValue[idx]=min(recursion(idx*2+1,(sum+edge[idx*2+1])),recursion(idx*2+2,(sum+edge[idx*2+2])));
    return minValue[idx];
}
void minFunc(int idx, int value){
    minValue[idx]-=value;
    edge[idx]+=minValue[idx];
    if(idx*2+1>edgeCnt || idx*2+2>edgeCnt) return;
    minFunc(idx*2+1,value+minValue[idx]);
    minFunc(idx*2+2,value+minValue[idx]);
}
int main(){
    cin >> k;
    for(int i =1; i<=k;i++){
        edgeCnt+=pow(2,i);
    }
    minValue.resize(edgeCnt+1);
    edge.resize(edgeCnt+1);
    for(int i=1;i<=edgeCnt;i++){
        cin >> edge[i];
    }
    dfs(1,edge[1]);
    dfs(2,edge[2]);
    recursion(1,edge[1]);
    recursion(2,edge[2]);
    minFunc(1,0);
    minFunc(2,0);
    int result=0;
    for(int i=1;i<=edgeCnt;i++) {
        result+=edge[i];
    }
    cout << result << '\n';
    return 0;
}
