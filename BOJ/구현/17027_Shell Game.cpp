#include <iostream>
#include <algorithm>
using namespace std;
int n;
int res1, res2, res3;
int arr1[4], arr2[4], arr3[4];
int main(void) {
	scanf("%d", &n);
	arr1[1] = 1;
	arr2[2] = 1;
	arr3[3] = 1;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int temp = 0;
		temp = arr1[a];
		arr1[a] = arr1[b];
		arr1[b] = temp;
		temp = arr2[a];
		arr2[a] = arr2[b];
		arr2[b] = temp;
		temp = arr3[a];
		arr3[a] = arr3[b];
		arr3[b] = temp;
		if (arr1[c]) res1++;
		if (arr2[c]) res2++;
		if (arr3[c]) res3++;
	}
	int res = max(res1, res2);
	res = max(res, res3);
	printf("%d\n", res);
}