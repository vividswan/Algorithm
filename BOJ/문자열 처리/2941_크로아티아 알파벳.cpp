#include<stdio.h>
#include<string.h>
int main(void) {
	char str[105];
	scanf("%s", str);
	int count;
	count = strlen(str);
	int result = 0;
	for (int a = 0; count > a; a++) {
		if (str[a] == 'l') {
			if (str[a + 1] == 'j') {
				result++;
				a++;
			}
			else result++;
		}
		else if (str[a] == 'n') {
			if (str[a + 1] == 'j') {
				result++;
				a++;
			}
			else result++;
		}
		else if (str[a] == 's') {
			if (str[a + 1] == '=') {
				result++;
				a++;
			}
			else result++;
		}
		else if (str[a] == 'z') {
			if (str[a + 1] == '=') {
				result++;
				a++;
			}
			else result++;
		}
		else if (str[a] == 'd') {
			if (str[a + 1] == 'z') {
				if (str[a + 2] == '=') {
					result++;
					a += 2;
				}
				else result++;
			}
			else if (str[a + 1] == '-') {
				result++;
				a++;
			}
			else result++;
		}
		else if (str[a] == 'c') {
			if (str[a + 1] == '=' || str[a + 1] == '-') {
				result++;
				a++;
			}
			else result++;
		}
		else result++;
	}
	printf("%d", result);
	return 0;
}