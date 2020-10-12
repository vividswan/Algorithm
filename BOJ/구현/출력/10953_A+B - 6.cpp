#include <iostream>
#include <string>
using namespace std;
int main(void){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        int num1 = str[0]-'0';
        int num2 = str[2]-'0';
        cout << num1 + num2 << '\n';
    }
    return 0;
}
