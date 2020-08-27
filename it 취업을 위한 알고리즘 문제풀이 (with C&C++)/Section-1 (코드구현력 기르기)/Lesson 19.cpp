#include <iostream>
#include <algorithm>
using namespace std;
int arr[101];
int nowMax[101];
int result;
int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	int maxx = 0;
	for(int i=N-1;i>=0;i--){
		maxx = max(maxx, arr[i]);
		nowMax[i] = maxx;
	}
	for (int i = 0; i < N - 1; i++) {
		if (arr[i] > nowMax[i + 1]) result++;
	}
	cout << result << '\n';
	return 0;
}