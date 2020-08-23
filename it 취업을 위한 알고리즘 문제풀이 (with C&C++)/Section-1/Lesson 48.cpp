#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
	vector<vector<int>> adj(10, vector<int>(10));
	vector<int> avg(10);
	for (int i = 1; i <= 9; i++) {
		double tot = 0;
		for (int j = 1; j <= 9; j++) {
			cin >> adj[i][j];
			tot += adj[i][j];
		}
		double chkAvg = tot / 9;
		avg[i] = tot / 9;
		if (chkAvg - double(avg[i]) >= 0.5) avg[i]++;
	}
	for (int i = 1; i <= 9; i++) {
		int maxx = 100;
		int value = 0;
		for (int j = 1; j <= 9; j++) {
			if (abs(avg[i] - adj[i][j]) < maxx) {
				maxx = abs(avg[i] - adj[i][j]);
				value = adj[i][j];
			}
			else if (abs(avg[i] - adj[i][j]) == maxx){
				if(adj[i][j]>avg[i]) value = adj[i][j];
			}
		}
		cout << avg[i] << ' ' << value << '\n';
;	}
	return 0;
}