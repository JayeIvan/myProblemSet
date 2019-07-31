https://codeforces.com/problemset/problem/1159/B

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#define inf 1000000000

using namespace std;

int num[300000];

int main()
{
   int n,k;
   while(scanf("%d",&n)!=EOF)
   {
       k = inf;
       for(int i=0;i<n;i++)
       {
           scanf("%d",&num[i]);
           int res = num[i]/max(n-i-1,i);
           k = min(k,res);
       }
       cout << k << endl;
   }

    return 0;
}
