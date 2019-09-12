#include <iostream>
#include <algorithm>
using namespace std;
struct Trie {
	Trie* next[26];
	bool finish;
	Trie() {
		fill(next, next + 26, nullptr);
		finish = false;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (next[i]) delete next[i];
		}
	}
	void insert(const char* key) {
		if (*key == '\0') {
			finish = true;
		}
		else {
			int curr = *key - 'a';
			if (next[curr] == NULL) next[curr] = new Trie;
			next[curr]->insert(key + 1);
		}
	}
	bool find(const char* key) {
		if (*key == '\0') {
			if (finish) return true;
		}
		int curr = *key - 'a';
		if (next[curr] == NULL) {
			return false;
		}
		return next[curr]->find(key + 1);
	}
};
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	getchar();
	Trie* root = new Trie;
	for (int i = 0; i < n; i++) {
		char str[501];
		scanf("%s", str);
		root->insert(str);
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		char str[501];
		scanf("%s", str);
		if (root->find(str)) cnt++;
	}
	printf("%d\n", cnt);
}