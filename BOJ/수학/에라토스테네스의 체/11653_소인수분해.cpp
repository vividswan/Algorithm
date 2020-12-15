#include <iostream>
#include <vector>
using namespace std;
vector<int> cntVector;
vector<int> prime;
bool chk[10000001];
bool isPrime[10000001];
void func(int num);
int n;
int main(){
    cin >> n;
    cntVector.resize(n+1);
    for(int i=2;i<=n;i++) {
        if (chk[i]) continue;
        func(i);
    }
    for(int i=0;  i<prime.size(); i++){
        while((n%prime[i])==0){
            cout << prime[i] << '\n';
            n /= prime[i];
            cntVector[prime[i]]++;
        }
    }
    return 0;
}
void func(int num){
    chk[num] = true;
    isPrime[num] = true;
    prime.push_back(num);
    for(int i=2;;i++){
        if(num*i>n) break;
        chk[num*i] = true;
    }
}