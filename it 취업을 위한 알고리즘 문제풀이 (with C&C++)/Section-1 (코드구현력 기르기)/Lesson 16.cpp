#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
priority_queue<char, vector<char>> pq1;
priority_queue<char, vector<char>> pq2;
int main(void) {
	char str1[101];
	char str2[101];

	cin >> str1;
	cin >> str2;

	int len = strlen(str1);
	if (len != strlen(str2)) {
		printf("NO\n");
		return 0;
	}

	for (int i = 0; i < len; i++) {
		pq1.push(str1[i]);
		pq2.push(str2[i]);
	}

	while (!pq1.empty()) {
		if(pq1.top()!=pq2.top()){
			printf("NO\n");
			return 0;
		}
		pq1.pop();
		pq2.pop();
	}

	printf("YES\n");
	return 0;
}