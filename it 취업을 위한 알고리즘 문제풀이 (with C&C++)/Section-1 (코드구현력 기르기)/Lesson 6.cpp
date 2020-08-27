#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
int main(void) {
	int result = 0;
	int cnt = 0;
	queue<int> q;
	char str[51];
	cin >> str;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		char now = str[i];
		if ('0' <= str[i] && str[i] <= '9') q.push(str[i] - '0');
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		result += now * pow(10, q.size());
	}
	for (int i = 1; i <= sqrt(result); i++) {
		if (result % i == 0) {
			if (i != sqrt(result)) cnt += 2;
			else cnt++;
		}
	}
	cout << result << '\n' << cnt << '\n';
	return 0;
}