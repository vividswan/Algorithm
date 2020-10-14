#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, maxx, minn;
    cin >> n;
    int firstValue;
    cin >> firstValue;
    maxx=firstValue;
    minn=firstValue;
    for(int i=2; i<=n;i++){
        int value;
        cin >> value;
        maxx=max(maxx,value);
        minn=min(minn,value);
    }
    cout << minn << ' ' << maxx << '\n';
    return 0;
}
