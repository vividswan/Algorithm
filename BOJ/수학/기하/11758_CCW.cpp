#include <iostream>
using namespace std;
typedef struct dot {
	int x;
	int y;
};
int func(dot dot1, dot dot2) {
	return dot1.x * dot2.y - dot2.x * dot1.y;
}
int main(void) {
	dot arr[3];
	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		arr[i].x = x;
		arr[i].y = y;
	}
	dot line[2];
	line[0].x = arr[0].x - arr[1].x;
	line[0].y = arr[0].y - arr[1].y;
	line[1].x = arr[0].x - arr[2].x;
	line[1].y = arr[0].y - arr[2].y;
	int result = func(line[0], line[1]);
	if (result > 0) cout << 1 << '\n';
	else if (result == 0) cout << 0 << '\n';
	else cout << -1 << '\n';
}