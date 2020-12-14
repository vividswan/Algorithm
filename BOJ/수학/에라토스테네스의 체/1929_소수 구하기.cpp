#include <iostream>
#include <cmath>
using namespace std;
bool isPrime[1000001];
bool chk[1000001];
int m,n,k;
void func(int num);
int main(){
    chk[1]=true;
    cin >> m >> n;
    k = sqrt(n);
    for(int i=2;i<=n;i++){
        if(chk[i]) continue;
        isPrime[i] = true;
        func(i);
    }
    for(int i=m;i<=n;i++){
        if(isPrime[i]) cout << i << '\n';
    }
    return 0;
}
void func(int num){
    for(int i=2;;i++){
        if(i*num<=n) chk[i*num] = true;
        else break;
    }
}
