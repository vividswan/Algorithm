#include <iostream>
using namespace std;
int n, arr1[1000001], arr2[1000001], arr3[1000001];
void push(void);
void rev(void);
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr1[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr2[i]);
	}
	int st = arr2[1];
	int go = 0;
	for (int i = 1; i <= n; i++) {
		if (st == arr1[i]) {
			go = i;
			break;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (arr2[i] == arr1[go]) {
			cnt++;
		}
		else break;
		go++;
		if (go == n + 1) go = 1;
	}
	if (cnt == n) {
		printf("good puzzle");
		return 0;
	}
	rev();
	go = 0;
	for (int i = 1; i <= n; i++) {
		if (st == arr1[i]) {
			go = i;
			break;
		}
	}
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (arr2[i] == arr1[go]) {
			cnt++;
		}
		else break;
		go++;
		if (go == n + 1) go = 1;
	}
	if (cnt == n) {
		printf("good puzzle");
		return 0;
	}
	printf("bad puzzle");
}
void rev(void) {
	for (int i = 1; i <= n; i++) {
		arr3[i] = arr1[i];
	}
	for (int i = 1; i <= n; i++) {
		arr1[i] = arr3[n + 1 - i];
	}
	return;
}