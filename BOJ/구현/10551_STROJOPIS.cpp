#include <iostream>
#include <cstring>
using namespace std;
int arr[9];
char str[51];
int main(void) {
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] == '1' || str[i] == 'Q' || str[i] == 'A' || str[i] == 'Z') arr[1]++;
		else if (str[i] == '2' || str[i] == 'W' || str[i] == 'S' || str[i] == 'X') arr[2]++;
		else if (str[i] == '3' || str[i] == 'E' || str[i] == 'D' || str[i] == 'C') arr[3]++;
		else if (str[i] == '4' || str[i] == 'R' || str[i] == 'F' || str[i] == 'V' || str[i] == '5' || str[i] == 'T' || str[i] == 'G' || str[i] == 'B') arr[4]++;
		else if (str[i] == '6' || str[i] == 'Y' || str[i] == 'H' || str[i] == 'N' || str[i] == '7' || str[i] == 'U' || str[i] == 'J' || str[i] == 'M') arr[5]++;
		else if (str[i] == '8' || str[i] == 'I' || str[i] == 'K' || str[i] == ',') arr[6]++;
		else if (str[i] == '9' || str[i] == 'O' || str[i] == 'L' || str[i] == '.') arr[7]++;
		else arr[8]++;
	}
	for (int i = 1; i <= 8; i++) {
		printf("%d\n", arr[i]);
	}
}