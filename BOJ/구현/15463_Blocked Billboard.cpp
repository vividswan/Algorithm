#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> arr[7];
int size_1, size_2, size_3, size_4;
int main(void) {
	for (int i = 1; i <= 6; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[i].first = 1000 + a;
		arr[i].second = 1000 + b;
	}
	size_1 = abs((arr[2].second - arr[1].second) * (arr[2].first - arr[1].first));
	size_2 = abs((arr[4].second - arr[3].second) * (arr[4].first - arr[3].first));
	if ((min(arr[2].first, arr[6].first) - max(arr[1].first, arr[5].first)) < 0) size_3 = 0;
	else if ((min(arr[2].second, arr[6].second) - max(arr[1].second, arr[5].second)) < 0) size_3 = 0;
	else size_3 = abs((min(arr[2].first, arr[6].first) - max(arr[1].first, arr[5].first)) * (min(arr[2].second, arr[6].second) - max(arr[1].second, arr[5].second)));
	if ((min(arr[4].first, arr[6].first) - max(arr[3].first, arr[5].first)) < 0) size_4 = 0;
	else if ((min(arr[4].second, arr[6].second) - max(arr[3].second, arr[5].second)) < 0) size_4 = 0;
	else size_4 = abs((min(arr[4].first, arr[6].first) - max(arr[3].first, arr[5].first)) * (min(arr[4].second, arr[6].second) - max(arr[3].second, arr[5].second)));
	printf("%d\n", size_1 + size_2 - size_3 - size_4);
	return 0;
}