#include <iostream>
#include <algorithm>
using namespace std;
int maxResult=1;
int N;
int arr[51][51];
void searchMax();
int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char str;
			scanf(" %c", &str);
			if (str == 'C') arr[i][j] = 1;
			else if (str == 'P') arr[i][j] = 2;
			else if (str == 'Z') arr[i][j] = 3;
			else arr[i][j] = 4;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j < N - 1) {
				swap(arr[i][j], arr[i][j + 1]);
				searchMax();
				swap(arr[i][j], arr[i][j + 1]);
			}
			if (i < N - 1) {
				swap(arr[i][j], arr[i+1][j]);
				searchMax();
				swap(arr[i][j], arr[i+1][j]);
			}
		}
	}
	printf("%d\n", maxResult);
	return 0;
}
void searchMax() {
	for (int i = 0; i < N; i++) {
		int bef;
		int nowVal = 1;
		for (int j = 0; j < N; j++) {
			if (j == 0) {
				bef = arr[i][j];
				continue;
			}
			if (bef == arr[i][j]) nowVal++;
			else {
				maxResult = max(maxResult, nowVal);
				nowVal = 1;
				bef = arr[i][j];
			}
			if (j == N - 1) maxResult = max(maxResult, nowVal);
		}
	}
	for (int j = 0; j < N; j++) {
		int bef;
		int nowVal = 1;
		for (int i = 0; i < N; i++) {
			if (i == 0) {
				bef = arr[i][j];
				continue;
			}
			if (bef == arr[i][j]) nowVal++;
			else {
				maxResult = max(maxResult, nowVal);
				nowVal = 1;
				bef = arr[i][j];
			}
			if(i==N-1) maxResult = max(maxResult, nowVal);
		}
	}
}