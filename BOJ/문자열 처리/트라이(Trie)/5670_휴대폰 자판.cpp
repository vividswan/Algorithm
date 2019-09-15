#include <iostream>
using namespace std;
char str[100000][81];
bool st;
int res, n;
struct Trie {
	Trie* next[26];
	bool finish;
	int cnt;
	Trie() {
		finish = false;
		cnt = 0;
		for (int i = 0; i < 26; i++) next[i] = nullptr;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (next[i]) delete next[i];
		}
	}
	void insert(char* key) {
		if (*key == '\0') {
			finish = true;
			return;
		}
		else {
			int curr = *key - 'a';
			if (next[curr] == nullptr) {
				cnt++;
				next[curr] = new Trie();
			}
			next[curr]->insert(key + 1);
		}
	}
	void find(char* key) {
		if (*key == '\0') return;
		if (st) {
			st = false;
			res++;
		}
		else {
			if (finish) res++;
			else if (cnt > 1) res++;
		}
		int curr = *key - 'a';
		next[curr]->find(key + 1);
	}
};
int main(void) {
	while (scanf("%d", &n) != -1) {
		res = 0;
		getchar();
		Trie* root = new Trie();
		for (int i = 0; i < n; i++) {
			scanf("%s", str[i]);
			root->insert(str[i]);
		}
		for (int i = 0; i < n; i++) {
			st = true;
			root->find(str[i]);
		}
		printf("%.2lf\n", (double)res / (double)n);
		delete root;
	}
	return 0;
}