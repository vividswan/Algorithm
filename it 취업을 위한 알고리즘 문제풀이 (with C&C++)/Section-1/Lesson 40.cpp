#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
	int N, M;
	cin >> N;
	vector<int> arr1(N);
	for (int i = 0; i < N; i++) cin >> arr1[i];
	sort(arr1.begin(), arr1.end());
	cin >> M;
	vector<int> arr2(M);
	for (int i = 0; i < M; i++) cin >> arr2[i];
	sort(arr2.begin(), arr2.end());
	vector<int> result;
	int ptr1, ptr2;
	ptr1 = ptr2 = 0;
	while (ptr1 < N && ptr2 < M) {
		if (arr1[ptr1] == arr2[ptr2]) {
			result.push_back(arr1[ptr1]);
			ptr1++;
			ptr2++;
		}
		else if (arr1[ptr1] > arr2[ptr2]) ptr2++;
		else ptr1++;
	}
	int size = result.size();
	for (int i = 0; i < size; i++) cout << result[i] << ' ';
	cout << '\n';
	return 0;
}