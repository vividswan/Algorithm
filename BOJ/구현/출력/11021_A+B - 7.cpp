#include <iostream>
using namespace std;
int main(void){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int num1,num2;
        cin >> num1 >> num2;
        cout << "Case #" << i << ": " << num1+num2 << '\n';
    }
}
