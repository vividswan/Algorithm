#include <iostream>
#include <vector>
using namespace std;
int fir[11];
int sec[11];
vector<int> vec;
int posi[201];
int nega[201];
int main(void) {
	vec.push_back(0);
	for (int i = 1; i <= 10; i++) scanf("%d", &fir[i]);
	for (int i = 1; i <= 10; i++) scanf("%d", &sec[i]);
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			for (int k = 0; k <= 10; k++) {
				for (int l = 0; l <= 10; l++) {
					int ans = 0;
					ans -= fir[i];
					sec[0] = fir[i];
					ans += sec[j];
					fir[0] = sec[j];
					if (i == k) continue;
					ans -= fir[k];
					if (j == l) continue;
					ans += sec[l];
					if (ans > 0) {
						if (posi[ans] == 0) {
							posi[ans] = 1;
							vec.push_back(ans);
						}
					}
					else if (ans < 0) {
						if (nega[-ans] == 0) {
							nega[-ans] = 1;
							vec.push_back(ans);
						}
					}
				}
			}
		}
	}
	printf("%d\n", vec.size());
}