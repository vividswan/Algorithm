#include <iostream>
#include <algorithm>
using namespace std;
int maxLength;
int N, L;
int arr[1001];
int res;
int nowTape;
int main(void) {
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) {
		int dis;
		scanf("%d", &dis);
		arr[dis]++;
		maxLength = max(maxLength, dis);
	}
	for (int i = 0; i <= maxLength; i++) {
		int swc = 0;
		if (nowTape) {
			nowTape--;
			swc++;
		}
		if (arr[i] && !swc) {
			nowTape = L - 1;
			res++;
		}
	}
	printf("%d\n", res);
	return 0;
}