#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int num){
    if(num==1) return false;
    int boundary = sqrt(num);
    for(int i =2 ;i<=boundary;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int cnt;
    cin >> cnt;
    int result = 0;
    for(int i=0;i<cnt;i++){
        int num;
        cin >> num;
        if(isPrime(num)) result++;
    }
    cout << result << '\n';
    return 0;
}
