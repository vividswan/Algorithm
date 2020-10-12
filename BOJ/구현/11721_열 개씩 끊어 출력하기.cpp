#include <stdio.h>
int main(void){
    char str[101];
    scanf("%s",str);
    int cnt =0;
    for(int i = 0; str[i] !='\0';i++){
        if(cnt==10){
            printf("\n");
            cnt=0;
        }
        printf("%c",str[i]);
        cnt++;
    }
}
