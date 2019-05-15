// http://acm.hdu.edu.cn/showproblem.php?pid=1159
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int res[2][10005];
char stra[10005],strb[10005];

int main()
{
    int lena,lenb,i,j;
    while(cin >> stra >> strb)
    {
        memset(res,0,sizeof(int)*10005*2);
        lena = strlen(stra);
        lenb = strlen(strb);
        for(i=0;i<strlen(stra);i++)
        {
            for(j=0;j<strlen(strb);j++)
            {
                // 滚动数组（用i%2来回来去倒，（i-1）%2就是i的上一状态记录）
                if(i==0 || j==0)
                {
                    res[i%2][j] = 0;
                }
                if(stra[i]==strb[j])
                {
                    res[(i+1)%2][j+1] = res[i%2][j]+1;
                }
                else
                {
                    res[(i+1)%2][j+1] = max(res[(i+1)%2][j],res[i%2][j+1]);
                }
            }
        }
        cout << res[lena%2][lenb] << endl;
        memset(stra,0,sizeof(char)*10005);
        memset(strb,0,sizeof(char)*10005);
    }
    return 0;
}
