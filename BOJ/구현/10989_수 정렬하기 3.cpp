#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int n;
int main(){
    v.resize(10001);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        v[num]++;
    }
    for(int i=1;i<=10000;i++){
        for(int j=1;j<=v[i];j++){
            printf("%d\n",i);
        }
    }
    return 0;
}
