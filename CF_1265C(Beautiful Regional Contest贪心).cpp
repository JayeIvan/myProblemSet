// https://codeforces.com/contest/1265/problem/C
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<string>

using namespace std;

int num[400005],sum[400005];

int main()
{
    int t,n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> num[i];

        int tmp = 1;
        int k = 0;
        int m = 0;
        for(int i = 0; i < n; i++)
        {
            if(num[i]==num[i+1]) 
                tmp++;
            else
            {
                sum[k++] = tmp;
                m += tmp;
                tmp = 1;
            }

            if(m >= n/2) 
            {
                if(m > n/2) m -= sum[k-1];
                break;
            }
        }

        int g, s, b;
        if(k<3)
        {
            g = 0,s = 0,b = 0;
        }
        else
        {
            g = sum[0],s = sum[1];
            for(int i = 2; i < k && s <= g; i++)
            {
                s += sum[i];
            }
            b = m - s - g;
        }
        if(b <= g) g = 0,s = 0,b = 0;
        cout << g << " " << s << " " << b << endl;
    }
    
    
    return 0;
}
