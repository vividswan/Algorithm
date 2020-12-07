#include <iostream>
using namespace std;
int a,b,c;
int main(){
    cin >> a >> b >> c;
    cout << (a+b)%c << '\n';
    cout << ((a%c)+(b%c))%c << '\n';
    cout << (a*b)%c << '\n';
    cout << ((a%c)*(b%c))%c << '\n';
    return 0;
}
