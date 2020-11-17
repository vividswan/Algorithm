#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
int value[23];
int numValue[2222223][23];
int powArr[23];
int main(){
    for(int i=0;i<23;i++) powArr[i] = pow(2,i);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        stack<int> s;
        int cnt = 0;
        while(num){
            if(num%2){
                numValue[i][cnt]=1;
                value[cnt] += 1;
            }
            num/=2;
            cnt++;
        }
    }
    for(int i=0;i<22;i++){
        value[i]%=2;
    }
    int result = 0;
    for(int i=22;i>=0;i--){
        if(value[i]) result+=powArr[i];
    }
    int final=result;
    for(int i=0;i<n;i++){
        int nowResult = result;
        for(int j=0;j<22;j++){
            if(numValue[i][j]==0) continue;
            if(value[j]) nowResult -= powArr[j];
            else  nowResult += powArr[j];
        }
        final= max(final,nowResult);
    }
    cout <<final<< final << '\n';
}
