#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	int swc = 0;
	vector<int> arr1;
	vector<int> arr2;
	vector<int> result;
	int ptr1, ptr2;
	ptr1 = ptr2 = 0;
	int N;
	cin >> N;
	arr1.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr1[i];
	}
	int M;
	cin >> M;
	arr2.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> arr2[i];
	}
	while (1) {
		if (ptr1 == N) {
			swc = -1;
			break;
		}
		else if (ptr2 == M) {
			swc = 1;
			break;
		}
		if (arr1[ptr1] > arr2[ptr2]) {
			result.push_back(arr2[ptr2]);
			ptr2++;
		}
		else {
			result.push_back(arr1[ptr1]);
			ptr1++;
		}
	}
	if (swc == 1) {
		for (int i = ptr1; i < N; i++) {
			result.push_back(arr1[i]);
		}
	}
	else {
		for (int i = ptr2; i < M; i++)
			result.push_back(arr2[i]);
	}
	int size = result.size();
	for (int i = 0; i < size; i++) cout << result[i] << ' ';
	return 0;
}