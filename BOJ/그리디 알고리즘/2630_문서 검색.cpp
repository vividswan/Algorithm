#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int res_st, res_rev;
int main(void) {
	char str[2501];
	char search[51];
	cin.getline(str, 2501);
	cin.getline(search, 51);
	int len_str = strlen(str);
	int len_search = strlen(search);
	int cnt = 0;
	for (int i = 0; i < len_str; i++) {
		if (str[i] != search[cnt]) {
			cnt = 0;
		}
		if (str[i] == search[cnt]) {
			cnt++;
			if (cnt == len_search) {
				cnt = 0;
				res_st++;
			}
		}
	}
	cnt = len_search - 1;
	for (int i = len_str - 1; i >= 0; i--) {
		if (str[i] != search[cnt]) {
			cnt = len_search - 1;
		}
		if (str[i] == search[cnt]) {
			if (cnt == 0) {
				cnt = len_search - 1;
				res_rev++;
			}
			else cnt--;
		}
	}
	cout << max(res_st, res_rev) << "\n";
}