#include <iostream>
using namespace std;
int monthValue[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
char str[7][10]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(void){
    int x,y;
    cin >> x >> y;
    int tot=0;
    for(int i=1;i<x;i++){
        tot+=monthValue[i];
    }
    tot+=y-1;
    cout << str[tot%7] << '\n';
    return 0;
}
