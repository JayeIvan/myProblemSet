// https://codeforces.com/problemset/problem/1174/B
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#define inf 0x3f3f3f3f
typedef long long  ll;

using namespace std;

int arr[100005];

int main()
{
    int i,f,x,y,z,n;
    while(cin >> n)
    {
        f = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]%2==1) f++;
        }
        if(f<n && f) sort(arr,arr+n);
        for(i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    return 0;
}
