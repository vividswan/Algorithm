#include <iostream>
#include <vector>
using namespace std;
int j, a, res;
int vis[1000000];
vector<char> arr;
int main() {
	scanf("%d%d", &j, &a);
	arr.resize(j + 1);
	for (int i = 1; i <= j; i++) {
		char s;
		scanf(" %c", &s);
		arr[i] = s;
	}
	for (int i = 1; i <= a; i++) {
		int num;
		char s;
		scanf(" %c %d", &s, &num);
		if (vis[num]) continue;
		else if (arr[num] == 'S') {
			if (s == 'S') {
				res++;
				vis[num] = 1;
				continue;
			}
		}
		else if (arr[num] == 'M') {
			if (s == 'M' || s == 'S') {
				res++;
				vis[num] = 1;
				continue;
			}
		}
		else if (arr[num] == 'L') {
			res++;
			vis[num] = 1;
			continue;
		}
	}
	printf("%d\n", res);
	return 0;
}