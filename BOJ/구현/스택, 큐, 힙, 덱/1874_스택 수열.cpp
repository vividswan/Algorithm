#include <iostream>
#include <stack>
using namespace std;
int arr[100005];
char str[200005];
int a;
stack<int>s;
int n = 1;
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	for (int j = 0; j < num; j++) {
		if (n == arr[j]) {
			s.push(n);
			str[a] = '+';
			a++;
			str[a] = '\n';
			a++;
			n++;
			s.pop();
			str[a] = '-';
			a++;
			str[a] = '\n';
			a++;
		}
		else if (arr[j] > n) {
			for (n; arr[j] > n; n++) {
				s.push(n);
				str[a] = '+';
				a++;
				str[a] = '\n';
				a++;
			}
			j--;
		}
		else if (arr[j] < n) {
			if (s.top() == arr[j]) {
				s.pop();
				str[a] = '-';
				a++;
				str[a] = '\n';
				a++;
			}
			else {
				printf("NO");
				return 0;
			}
		}
	}
	str[a - 1] = '\0';
	printf("%s", str);
	return 0;
}