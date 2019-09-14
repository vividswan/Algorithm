#include <iostream>
#include <map>
#include <string>
using namespace std;
int n, res, swc;
map <string, int> m;
map <string, int> ans;
int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c, d, e, f;
		cin >> a;
		string id;
		cin >> id;
		cin >> b >> c >> d >> e >> f;
		if (id == "megalusion") continue;
		if (b == 4) {
			if (ans[id] == 0) {
				ans[id] = 1;
				res++;
				swc += m[id];
			}
		}
		else m[id]++;
	}
	if (res == 0) printf("%d\n", 0);
	else printf("%.11lf", (double)100 * ((double)res / ((double)res + (double)swc)));
	return 0;
}