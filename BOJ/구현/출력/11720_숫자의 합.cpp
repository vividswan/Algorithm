#include <iostream>
using namespace std;
int main(){
    int n;
    long long result = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        long long num;
        scanf("%1lld",&num);
        result+=num;
    }
    printf("%lld\n",result);
    return 0;
}
