#include <iostream>
using namespace std;
int arr[2][11];
int lastWinner;
pair<int, int> score;
int main(void) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 10; i++) {
		if (arr[0][i] > arr[1][i]) {
			score.first += 3;
			lastWinner = 1;
		}
		else if (arr[0][i] < arr[1][i]) {
			score.second += 3;
			lastWinner = 2;
		}
		else {
			score.first++;
			score.second++;
		}
	}
	cout << score.first << ' ' << score.second << '\n';
	if (score.first > score.second) cout << 'A' << '\n';
	else if (score.first < score.second) cout << 'B' << '\n';
	else {
		if (!lastWinner) cout << 'D' << '\n';
		else if(lastWinner == 1) cout << 'A' << '\n';
		else cout << 'B' << '\n';
	}
}