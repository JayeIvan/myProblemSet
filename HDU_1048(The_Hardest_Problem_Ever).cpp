// http://acm.hdu.edu.cn/showproblem.php?pid=1048
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
//    char st[1000];
//    gets(st);
//    while(strcmp(st,"START")==0)
//    {
//        gets(st);
//        cout << st << endl;
//        gets(st);
//    }
    char st[10],en[10],str[200000];
    gets(st);
    while(strcmp(st,"START")==0)
    {
        gets(str);
        gets(en);
        if(strcmp(en,"END")==0){
            for(int i=0;i<strlen(str);i++){
                if(str[i]>='A' && str[i]<='Z'){
                    if(str[i]>'E'){
                        cout << char(str[i]-5);
                    }
                    else{
                        cout << char('Z'+ str[i]-'E');
                    }
                }
                else cout << str[i];
            }
        }
        cout << endl;
        gets(st);
    }
    return 0;
}
