#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int k;
int h = 1;
int arr[1024];
queue<int> q;
int main(void) {
	scanf("%d", &k);
	h <<= k;
	q.push(h / 2);
	for (int i = 1; i <= h-1; i++) scanf("%d", &arr[i]);
	while (k) {
		int cnt = q.size();
		while (cnt) {
			int now = q.front();
			q.pop();
			printf("%d ", arr[now]);
			q.push(now - (1<<(k-2)));
			q.push(now + (1<<(k-2)));
			cnt--;
		}
		printf("\n");
		k--;
	}
	return 0;
}