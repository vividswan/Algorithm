#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
void recursion(int le, int ri);
	int N;
int main(void) {
	cin >> N;
	arr.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}
	recursion(1,N);
	for (int i = 1; i <= N; i++) cout << arr[i] << ' ';
	return 0;
}
void recursion(int le, int ri) {
	if (le < ri) {
		int mid = (le + ri) / 2;
		recursion(le, mid);
		recursion(mid + 1, ri);
		int ptr1, ptr2, ptr3;
		ptr1 = le;
		ptr2 = mid + 1;
		ptr3 = le;
		vector<int> temp(N + 1);
		while (ptr1 <= mid && ptr2 <= ri) {
			if (arr[ptr1] <= arr[ptr2]) temp[ptr3++] = arr[ptr1++];
			else temp[ptr3++] = arr[ptr2++];
		}
		while(ptr1<=mid) temp[ptr3++] = arr[ptr1++];
		while(ptr2<=ri) temp[ptr3++] = arr[ptr2++];
		for (int i = le; i <= ri; i++) arr[i] = temp[i];
	}
	return;
}