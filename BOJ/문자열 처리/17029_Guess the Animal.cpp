#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
int n, res;
vector<string> v[101];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char str[21];
		scanf(" %s", str);
		int a;
		scanf("%d", &a);
		for (int j = 1; j <= a; j++) {
			char as[21];
			scanf(" %s", as);
			v[i].push_back(as);
		}
	}
	for (int i = 1; i <= n - 1; i++) {
		int i_res = 0;
		for (int j = i + 1; j <= n; j++) {
			int j_cnt = 0;
			for (int k = 0; k < v[i].size(); k++) {
				for (int l = 0; l < v[j].size(); l++) {
					if (v[i][k] == v[j][l]) j_cnt++;
				}
			}
			i_res = max(j_cnt, i_res);
		}
		res = max(i_res, res);
	}
	printf("%d\n", res + 1);
}