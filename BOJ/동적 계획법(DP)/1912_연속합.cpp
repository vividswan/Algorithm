#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int arr[MAX];
int n, sum;
int maxx = -99999;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		sum += num;
		maxx = max(maxx, sum);
		if (sum < 0) sum = 0;
	}
	printf("%d\n", maxx);
}