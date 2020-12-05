#include <iostream>
#include <string>
using namespace std;
string a,b,c,d;
string str1, str2;
int main(){
    cin >> a >> b >> c >> d;
    str1 = a+b;
    str2 = c+d;
    long long num1 = stol(str1);
    long long num2 = stol(str2);
    cout << num1+num2 << '\n';
    return 0;
}
