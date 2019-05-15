// http://acm.hdu.edu.cn/showproblem.php?pid=1062
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char str[1005],revse[50];
    int n,i,j;
    cin >> n;
    getchar();
    while(n--)
    {
        memset(str,0,sizeof(char)*1005);
        memset(revse,0,sizeof(char)*50);
        gets(str);
        int len = strlen(str);
        j = 0;
        for(i=0;i<len;i++)
        {
            if(str[i]!=' ')
            {
                revse[j++] = str[i];
            }
            else
            {
                for(j-=1;j>=0;j--)
                {
                    cout << revse[j];
                }
                cout << " ";
                j = 0;
            }
        }
        for(j=j-1;j>=0;j--)
        {
            cout << revse[j];
        }
        cout << endl;
    }

    return 0;
}
