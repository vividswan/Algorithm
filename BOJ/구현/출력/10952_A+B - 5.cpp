#include <iostream>
using namespace std;
int main(void){
    while (true){
        int a,b;
        cin >> a >> b;
        if(a==0 && b == 0) break;
        cout << a+b << '\n';
    }
    return 0;
}
