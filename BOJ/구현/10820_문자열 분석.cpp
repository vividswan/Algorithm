#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    while(true){
        getline(cin,str);
        if(str=="") break;
        int a=0,b=0,c=0,d=0;
        for(int i=0;i<str.length();i++){
            if(str[i]<='z'&&'a'<=str[i]) a++;
            else if(str[i]<='Z'&&'A'<=str[i]) b++;
            else if(str[i]<='9'&&'0'<=str[i]) c++;
            else d++;
        }
        cout << a << ' ' <<  b << ' ' << c << ' ' << d << '\n';
    }
    return 0;
}
