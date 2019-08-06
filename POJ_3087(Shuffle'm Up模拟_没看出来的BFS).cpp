// http://poj.org/problem?id=3087
// BFS + 模拟
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <math.h>
#include <iostream>
#define INF 1e9
#define eps 1e-6
#define ll long long

using namespace std;

char s1[205],s2[205];
string vis;

int main()
{
    int n,len;
    string str,fin;
    cin >> n;
    for(int c=1;c<=n;c++)
    {
        cin >> len;
        cin >> str;
        for(int i=1;i<2*len;i+=2)
            s1[i] = str[i/2];
        cin >> str;
        for(int i=0;i<2*len;i+=2)
            s2[i] = str[i/2];
        cin >> fin;

        int ans = 0;
        while(str!=fin)
        {
            str = "";
            for(int i=0;i<2*len;i++)
            {
                if(i%2==0)
                    str += s2[i];
                else
                    str += s1[i];
            }
            // 记录第一个合并好的字符串
            if(ans==0) vis = str;
            //cout << str << endl;
            // 如果第一次合并好了以后有重复出现，break
            if(ans>0 && vis==str)
            {
                ans = -1;
                break;
            }

            for(int i=0;i<2*len;i++)
            {
                if(i<len) s1[i*2+1] = str[i];
                else s2[(i-len)*2] = str[i];

            }
            ans++;
        }
        printf("%d %d\n",c,ans);

    }
    return 0;
}
