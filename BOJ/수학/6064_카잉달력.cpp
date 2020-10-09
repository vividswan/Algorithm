#include <iostream>
using namespace std;
int t;
int main(void){
    cin >> t;
    while(t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        int ptr1 = 0;
        int ptr2 = 0;
        while (ptr1 * m + m != ptr2 * n + n) {
            if (ptr1 * m + m > ptr2 * n + n) ptr2++;
            else ptr1++;
        }
        int result = ptr1 * m + m;
        ptr1 = 0;
        ptr2 = 0;
        while (ptr1 * m + x != ptr2 * n + y) {
            if(result < ptr1 * m + x) break;
            if((ptr1 * m + x)%m ==m && ( ptr2 * n + y)%n==n) break;
            if (ptr1 * m + x > ptr2 * n + y) ptr2++;
            else ptr1++;
        }
        if(result < ptr1 * m + x) cout << -1 << '\n';
        else cout << ptr1 * m + x << '\n';
    }
    return 0;
}
