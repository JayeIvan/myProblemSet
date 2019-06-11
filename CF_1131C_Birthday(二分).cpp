// http://codeforces.com/problemset/problem/1131/C
// 降序排列，由大到小，从中间开始往两边排（一左一右）
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int child[105];
int order[105];

int main()
{
    int n,i,r,l,mid;
    while(cin >> n)
    {
        memset(order,0,sizeof(order));
        for(i=0;i<n;i++)
        {
            scanf("%d",&child[i]);
        }

        sort(child,child+n,greater<int>());

        if(n%2==0) mid = n/2;
        else mid = (n-1)/2;
        l = mid-1;
        r = mid+1;
        i = 1;
        order[mid] = child[0];
        while(l>=0 || r<n)
        {
            order[l--] = child[i];
            order[r++] = child[++i];
            i++;
        }

        for(i=0;i<n;i++)
            printf("%d ",order[i]);
        printf("\n");
    }
    return 0;
}


