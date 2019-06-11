// http://codeforces.com/contest/1166/problem/C
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[200005];

int main()
{
    int i,j,n,m,k,first,second;
    long long res;
    while(cin >> k)
    {
        memset(arr,0,sizeof(arr));
        res = 0;
        for(i=0;i<k;i++)
        {
            cin >> arr[i];
            arr[i] = abs(arr[i]);
        }

        sort(arr,arr+k);

        for(i=0;i<k;i++)
        {
            int t = 2*abs(arr[i]);
            int pos=upper_bound(arr,arr+k,t)-arr;
            res+=(pos-i-1);
        }
        cout << res << endl;
    }
    return 0;
}
