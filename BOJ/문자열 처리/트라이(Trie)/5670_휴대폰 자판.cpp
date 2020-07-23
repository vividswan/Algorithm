#include <iostream>
using namespace std;
struct Trie {
	Trie* childTrie[26];
	bool isWord;
	int childCnt;
	Trie() {
		for (int i = 0; i < 26; i++) childTrie[i] = nullptr;
		isWord = false;
		childCnt = 0;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (childTrie[i]) delete childTrie[i];
		}
	}
	void insert(char* word) {
		if (*word == '\0') {
			isWord = true;
			return;
		}
		int nextNum = *word - 'a';
		if (childTrie[nextNum] == NULL) {
			childTrie[nextNum] = new Trie();
			childCnt++;
		}
		childTrie[nextNum]->insert(word + 1);
	}
	int check(char* word, int cnt) {
		if (*word == '\0') return cnt;
		if (childCnt > 1 || isWord) cnt++;
		int nextNum = *word - 'a';
		return childTrie[nextNum]->check(word + 1, cnt);
	}
};
int N;
char word[100001][81];
int main(void) {
	while (scanf("%d", &N) != EOF) {
		Trie* trie = new Trie();
		for (int i = 0; i < N; i++) {
			scanf("%s", word[i]);
			trie->insert(word[i]);
		}
		int result = 0;
		if (trie->childCnt == 1) result += N;
		for (int i = 0; i < N; i++) {
			result += trie->check(word[i], 0);
		}
		printf("%.2f\n", (double)result / N);
		delete trie;
	}
	return 0;
}