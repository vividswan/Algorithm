#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	long long num = 0;
	for (int i = 0; i < n * n; i++) {
		int nm;
		scanf("%d", &nm);
		num = num + nm;
	}
	printf("%lld", num);
}