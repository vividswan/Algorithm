#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
string b;
int n;
long long result;
int main(){
    cin >> b >> n;
    int size = b.length();
    for(int i=0;i<b.length();i++){
        int now;
        if('0'<=b[i] && b[i]<='9') now = b[i]-'0';
        else now = b[i]-'A'+10;
        result+=(long long)(now*pow(n,size-i-1));
    }
    cout << result << '\n';
    return 0;
}
