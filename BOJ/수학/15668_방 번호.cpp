#include <iostream>
#include <cstring>
using namespace std;
int main(void) {
	int num, vis[10] = { 0, }, sch = 0;
	cin >> num;
	int max, min;
	for (min = 1; min <= 87654; min++) {
		max = num - min;
		if (max <= min) {
			printf("-1");
			return 0;
		}
		char s_max[12], s_min[12];
		sprintf(s_max, "%d", max);
		sprintf(s_min, "%d", min);
		for (int i = 0; i < strlen(s_max); i++) {
			if (vis[s_max[i] - '0'] == 1) break;
			vis[s_max[i] - '0'] = 1;
			if (i == strlen(s_max) - 1) sch++;
		}
		if (sch == 1) {
			for (int i = 0; i < strlen(s_min); i++) {
				if (vis[s_min[i] - '0'] == 1) break;
				vis[s_min[i] - '0'] = 1;
				if (i == strlen(s_min) - 1) sch++;
			}
		}
		if (sch == 2) {
			printf("%s + %s", s_max, s_min);
			return 0;
		}
		sch = 0;
		memset(vis, 0, sizeof(vis));
	}
	printf("-1");
	return 0;
}