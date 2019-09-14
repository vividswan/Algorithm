#include <stdio.h>
int main(void) {
	char str[105];
	for (int a = 0; 104 >= a; a++) str[a] = 'A';
	int strr[30];
	for (int a = 0; 25 >= a; a++) strr[a] = -1;
	scanf("%s", str);
	for (int a = 0; 100 >= a; a++) {
		if (str[a] == 'a') {
			if (strr[0] == -1) strr[0] = a;
		}
		else if (str[a] == 'b') {
			if (strr[1] == -1) strr[1] = a;
		}
		else if (str[a] == 'c') {
			if (strr[2] == -1) strr[2] = a;
		}
		else if (str[a] == 'd') {
			if (strr[3] == -1) strr[3] = a;
		}
		else if (str[a] == 'e') {
			if (strr[4] == -1) strr[4] = a;
		}
		else if (str[a] == 'f') {
			if (strr[5] == -1) strr[5] = a;
		}
		else if (str[a] == 'g') {
			if (strr[6] == -1) strr[6] = a;
		}
		else if (str[a] == 'h') {
			if (strr[7] == -1) strr[7] = a;
		}
		else if (str[a] == 'i') {
			if (strr[8] == -1) strr[8] = a;
		}
		else if (str[a] == 'j') {
			if (strr[9] == -1) strr[9] = a;
		}
		else if (str[a] == 'k') {
			if (strr[10] == -1) strr[10] = a;
		}
		else if (str[a] == 'l') {
			if (strr[11] == -1) strr[11] = a;
		}
		else if (str[a] == 'm') {
			if (strr[12] == -1) strr[12] = a;
		}
		else if (str[a] == 'n') {
			if (strr[13] == -1) strr[13] = a;
		}
		else if (str[a] == 'o') {
			if (strr[14] == -1) strr[14] = a;
		}
		else if (str[a] == 'p') {
			if (strr[15] == -1) strr[15] = a;
		}
		else if (str[a] == 'q') {
			if (strr[16] == -1) strr[16] = a;
		}
		else if (str[a] == 'r') {
			if (strr[17] == -1) strr[17] = a;
		}
		else if (str[a] == 's') {
			if (strr[18] == -1) strr[18] = a;
		}
		else if (str[a] == 't') {
			if (strr[19] == -1) strr[19] = a;
		}
		else if (str[a] == 'u') {
			if (strr[20] == -1) strr[20] = a;
		}
		else if (str[a] == 'v') {
			if (strr[21] == -1) strr[21] = a;
		}
		else if (str[a] == 'w') {
			if (strr[22] == -1) strr[22] = a;
		}
		else if (str[a] == 'x') {
			if (strr[23] == -1) strr[23] = a;
		}
		else if (str[a] == 'y') {
			if (strr[24] == -1) strr[24] = a;
		}
		else if (str[a] == 'z') {
			if (strr[25] == -1) strr[25] = a;
		}
	}
	for (int a = 0; 25 >= a; a++) printf("%d ", strr[a]);
	return 0;
}