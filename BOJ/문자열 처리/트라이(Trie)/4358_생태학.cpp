#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Trie {
	Trie* childTrie[128];
	int isWord;
	Trie() {
		for (int i = 0; i < 128; i++) childTrie[i] = nullptr;
		isWord = 0;
	}
	~Trie() {
		for (int i = 0; i < 128; i++) {
			if (childTrie[i]) childTrie[i] = NULL;
		}
	}
	void insert(char* word) {
		if (*word == '\0') {
			isWord++;
			return;
		}
		int nextNum = *word - ' ';
		if (childTrie[nextNum] == NULL) {
			childTrie[nextNum] = new Trie();
		}
		childTrie[nextNum]->insert(word + 1);
	}
};
void count(Trie* trie, char* word, int N, char* stWord) {
	if (trie->isWord) {
		*word = '\0';
		printf("%s %.4f\n", stWord, (double)100 * trie->isWord / N);
		return;
	}
	else {
		for (int i = 0; i < 128; i++) {
			if (trie->childTrie[i]) {
				*word = i + ' ';
				count(trie->childTrie[i], word + 1, N, stWord);
			}
		}
	}
}
int main(void) {
	Trie* trie = new Trie();
	int N = 0;
	char str[31];
	while (scanf(" %[^\n]s", str) != EOF) {
		trie->insert(str);
		N++;
	}
	for (int i = 0; i < 128; i++) {
		if (trie->childTrie[i]) {
			char word[31];
			word[0] = i + ' ';
			count(trie->childTrie[i], word + 1, N, word);
		}
	}
	delete trie;
	return 0;
}