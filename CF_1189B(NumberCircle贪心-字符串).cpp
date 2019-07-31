https://codeforces.com/problemset/problem/1189/B

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int num[100005];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        sort(num,num+n);
        // for(int i=0;i<n;i++)
        //     printf("%d ",num[i]);
        // printf("\n");
        if(num[n-1]>=(num[n-2]+num[n-3])) cout << "NO\n";
        else
        {
            // 除了最大的元素外，每个元素必和一个比自己大的元素相邻
            for(int i=n-1;i>=3;i-=3)
            {
                swap(num[i],num[i-1]);
                swap(num[i],num[i-2]);
            }

            printf("YES\n");
            for(int i=n-1;i>=0;i--)
            {
                printf("%d ",num[i]);
            }
            printf("\n");
        }
        
    }
    
    return 0;
}