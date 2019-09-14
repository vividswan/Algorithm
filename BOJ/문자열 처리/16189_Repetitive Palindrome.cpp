#include <iostream>
#include <cstring>
using namespace std;
char str[250001];
char rev_str[250001];
long long int a;
int main(void) {
	scanf("%s", str);
	scanf("%d", &a);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		rev_str[i] = str[len - i - 1];
	}
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (rev_str[i] == str[i]) cnt++;
	}
	if (cnt == len) printf("YES\n");
	else printf("NO\n");
	return 0;
}