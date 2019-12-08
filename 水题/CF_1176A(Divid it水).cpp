// https://codeforces.com/problemset/problem/1176/A
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#define inf 0x3f3f3f3f
typedef long long  ll;

using namespace std;

int num[2005];

int main()
{
    int m,n,i,j,k;
    ll sum1=0,sum2=0;
    bool f;
    while(cin >> n)
    {
        f = true;
        for(i=0;i<2*n;i++)
        {
            scanf("%d",&num[i]);
            sum2 += num[i];
            if(i>0 && num[i]!=num[i-1] && f) f = false;
        }
        sort(num,num+2*n);

        for(i=0;i<n;i++)
            sum1 += num[i];
        sum2 = sum2 - sum1;
        if(f) printf("-1\n");
        else
        {
             while(sum1==sum2)
            {
                for(i=0;i<n && sum1==sum2;i++)
                    for(j=n;j<2*n && sum1==sum2;j++)
                        if(num[i]!=num[j])
                        {
                            swap(num[i],num[j]);
                            sum1 = sum1-num[i]+num[j];
                            sum2 = sum2+num[i]-num[j];
                        }
            }
            if(sum1!=sum2)
            {
                for(i=0;i<2*n;i++)
                    printf("%d ",num[i]);
                printf("\n");
            }

        }
    }
    return 0;
}
