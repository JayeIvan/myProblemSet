// https://codeforces.com/contest/1183/problem/C
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int q;
    long long k,diff,n,a,b,r;
    cin >> q;
    while(q--)
    {
        cin >> k >> n >> a >> b;
        if((k-a*n)>0) cout << n << endl;
        else
        {
            // ��Ҫ��ĵ�
            k = -(k-a*n)+1;
            // ÿ���ܳ��ϵĵ�
            diff = a-b;
            // ��Ҫ�伸��
            r = (k+diff-1)/diff;
            // ��Ҫ���Ĵ���>n ����>�治��
            if(r > n) cout << -1 << endl;
            // n-r���ǲ���Ҫ���Ĵ���
            else cout << n-r << endl;
        }
    }
    return 0;
}

//    WA
//    int q;
//    long long k,r,n,a,b,i;
//    cin >> q;
//    while(q--)
//    {
//        cin >> k >> n >> a >> b;
//        if((k-b*n)<=0) cout << -1 << endl;
//        else if((k-a*n)>0) cout << n << endl;
//        else
//        {
//            for(i=n;i>=0;i--)
//            {
//                r = i*a+(n-i)*b;
//                if(k-r>0)
//                {
//                    cout << i << endl;
//                    break;
//                }
//            }
//            if(k-r==0) cout << -1 << endl;
//        }
//    }

