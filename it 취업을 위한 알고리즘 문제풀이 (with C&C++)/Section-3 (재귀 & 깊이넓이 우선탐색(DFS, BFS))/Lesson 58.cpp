#include <iostream>
#include <vector>
using namespace std;
int N;
void preOrderFunc(int idx, int level) {
	if (level > N) return;
	cout << idx << ' ';
	preOrderFunc(idx * 2, level + 1);
	preOrderFunc(idx * 2+1, level + 1);
}
void inOrderFunc(int idx, int level) {
	if (level > N) return;
	inOrderFunc(idx * 2, level + 1);
	cout << idx << ' ';
	inOrderFunc(idx * 2 + 1, level + 1);
}
void postOrderFunc(int idx, int level) {
	if (level > N) return;
	postOrderFunc(idx * 2, level + 1);
	postOrderFunc(idx * 2 + 1, level + 1);
	cout << idx << ' ';
}
int main(void) {
	cin >> N;
	cout << "전위 순회 : ";
	preOrderFunc(1,1); 
	cout << '\n';
	cout << "중위 순회 : ";
	inOrderFunc(1,1);
	cout << '\n';
	cout << "후위 순회 : ";
	postOrderFunc(1,1);
	cout << '\n';
	return 0;
}