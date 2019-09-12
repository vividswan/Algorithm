#include <iostream>
using namespace std;
char str[8][10];
int main() {
	int arr[8][8] = { 1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1 };
	for (int i = 0; i < 8; i++) {
		scanf("%s", str[i]);
	}
	int result = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] == 1 && str[i][j] == 'F') result++;
		}
	}
	cout << result;
}