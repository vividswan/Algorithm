#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void) {
	char str1[10];
	char str2[10];
	char str3[10];
	char str4[10];
	scanf("%s", str1);
	scanf("%s", str2);
	int roof1 = strlen(str1);
	int roof2 = strlen(str2);
	for (int a = 0; roof1 > a; a++) {
		str3[a] = str1[roof1 - 1 - a];
	}
	for (int a = 0; roof2 > a; a++) {
		str4[a] = str2[roof2 - 1 - a];
	}
	int j = atoi(str3);
	int k = atoi(str4);
	int l = j + k;
	char str5[10];
	char str6[10];
	sprintf(str5, "%d", l);
	for (int a = 0; strlen(str5) > a; a++) {
		str6[a] = str5[strlen(str5) - 1 - a];
	}
	int result = atoi(str6);
	printf("%d", result);
	return 0;
}