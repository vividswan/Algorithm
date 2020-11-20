#include <iostream>
#include <cstring>
using namespace std;
int value[] = {3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1};
int main(){
    char str[1000001];
    cin >> str;
    int tot=0;
    for(int i=0;i<strlen(str);i++){
        tot += value[str[i]-'A'];
        tot %= 10;
    }
    if(tot%2) cout << "I'm a winner!" << '\n';
    else cout << "You're the winner?" << '\n';
}
