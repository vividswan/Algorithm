#include <iostream>
#include <vector>
using namespace std;
vector<int> primeNum;
bool chk[1000001];
bool isPrime[1000001];
void func(int num);
int main(){
    for(int i=2;i<=1000000;i++){
        if(chk[i]) continue;
        func(i);
    }
    while(1){
        int num;
        scanf("%d",&num);
        bool isOk = false;
        if(num==0) break;
        for(int i=0;i<primeNum.size();i++){
            if(primeNum[i]>num) break;
            if(isPrime[num-primeNum[i]]){
                printf("%d = %d + %d\n",num,primeNum[i],num-primeNum[i]);
                isOk = true;
                break;
            }
        }
        if(!isOk) printf("%s\n","Goldbach's conjecture is wrong.");
    }
    return 0;
}
void func(int num){
    primeNum.push_back(num);
    isPrime[num] = true;
    chk[num] = true;
    for(int i =2; ; i++){
        if(num*i > 1000000) break;
        chk[num*i ] = true;
    }
}
