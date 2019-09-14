#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <queue>
int roof;
using namespace std;
int main(void) {
	cin >> roof;
	for (int i = 1; i <= roof; i++) {
		map<string, int> m;
		queue<string> q;
		queue<int> q_res;
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			string str;
			cin >> str;
			q.push(str);
		}
		for (int j = 1; j <= n; j++) {
			string str;
			cin >> str;
			m[str] = j;
		}
		for (int j = 1; j <= n; j++) {
			string now = q.front();
			q.pop();
			q_res.push(m[now]);
		}
		map<int, string> res_m;
		for (int j = 1; j <= n; j++) {
			string str;
			cin >> str;
			res_m[j] = str;
		}
		while (!q_res.empty()) {
			int now = q_res.front();
			q_res.pop();
			cout << res_m[now] << ' ';
		}
		printf("\n");
	}
}