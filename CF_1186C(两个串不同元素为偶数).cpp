// https://codeforces.com/contest/1186/problem/C

/*
考虑两个等长的0/1串,a中有sa个1 11,b中有sb个1
那么这两个串不相同的位置的个数的就行就是sa+sb的奇偶性
为什么？
先考虑只有0和1匹配,和0和0匹配，显然正确，并且不同的个数就是sa+sb的奇偶性
因为如果有多个1匹配1，那么不同的个数就是sa+sb−k∗2
减掉的数是2的倍数，不改变奇偶性。
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>

using namespace std;

string a,b;

int main()
{
    int sa,sb,res,cnt;
    while(cin >> a >> b)
    {
        int lenb = b.size();
        sa = sb = 0;
        res = 0;
        for(int i=0;i<lenb;i++)
        {
            if(b[i]=='1') sb++;
            if(a[i]=='1') sa++;
        }

        if((sa+sb)%2==0) res++;
        for(int i=1;i<=a.size()-lenb;i++)
        {
            if(a[i-1]=='1') sa--;
            if(a[i+lenb-1]=='1') sa++;
            //cout << "sa:" << sa << "  sb:" << sb << endl;
            if((sa+sb)%2==0) res++;
        }

        printf("%d\n",res);
    }
    return 0;
}
