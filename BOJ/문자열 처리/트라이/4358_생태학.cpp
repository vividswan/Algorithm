#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int tot;
char res[31];
struct Trie {
	Trie* next[128];
	bool finish;
	int cnt;
	Trie() {
		fill(next, next + 128, nullptr);
		finish = false;
		cnt = 0;
	}
	~Trie() {
		for (int i = 0; i < 128; i++) {
			if (next[i]) delete next[i];
		}
	}
	void insert(const char* key) {
		if (*key == '\0') {
			finish = true;
			cnt++;
			return;
		}
		int curr = *key - ' ';
		if (next[curr] == nullptr) {
			next[curr] = new Trie();
		}
		next[curr]->insert(key + 1);
	}
	void chk(int de) {
		if (finish) {
			res[de] = '\0';
			printf("%s %.4lf\n", res, ((double)cnt / double(tot)) * 100);
		}
		for (int i = 0; i < 128; i++) {
			if (next[i]) {
				res[de] = i + ' ';
				next[i]->chk(de + 1);
				res[de] = '\0';
			}
		}
	}
};
int main(void) {
	Trie* root = new Trie();
	char str[31];
	while (scanf(" %[^\n]s", str) != EOF) {
		root->insert(str);
		tot++;
	}
	root->chk(0);
	delete root;
	return 0;
}