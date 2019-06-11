// http://acm.hdu.edu.cn/showproblem.php?pid=2141
/*
三重循环暴力TLE，Ai+Bj+Ck计算重复过多，先算，然后排序+二分查找
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int A[505],B[505],C[505];
int ab[505*505];

int main()
{
    int l,m,n,i,j,k,s,x,sumab,cnt=0;
    bool flag;
    while(cin >> l >> m >> n)
    {
        cnt++;
        for(i=0;i<l;i++)
            scanf("%d",&A[i]);

        for(i=0;i<m;i++)
            scanf("%d",&B[i]);

        for(i=0;i<n;i++)
            scanf("%d",&C[i]);

        sumab = 0;
        for(i=0;i<l;i++)
        {
            for(j=0;j<m;j++)
            {
                ab[sumab++]=A[i]+B[j];
                //printf("%d ",ab[sumab-1]);
            }
        }

        sort(ab,ab+l*m);
        cin >> s;
        printf("Case %d:\n",cnt);
        while(s--)
        {
            flag = true;
            cin >> x;

            for(j=0;j<n;j++)
            {
                int left=0;
                int r=sumab-1;
                int mid;
                while(left<=r && flag)
                {
                    mid = (left+r)/2;
                    if(ab[mid]>(x-C[j]))
                    {
                        r = mid-1;
                    }
                    else if(ab[mid]<(x-C[j]))
                    {
                        left = mid+1;
                    }
                    else
                        flag = false;
                }
            }

            if(!flag) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
