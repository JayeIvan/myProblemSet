// http://acm.hdu.edu.cn/showproblem.php?pid=1058
#include <iostream>

long long res[6000];

using namespace std;

long long mmin(long long a,long long b,long long c,long long d)
{
    int m = a;
    if(b<m) m = b;
    if(c<m) m = c;
    if(d<m) m = d;
    return m;
}

int main()
{
    int n,a,b,c,d,cnt=2;
    res[1] = 1;
    a = b = c = d = 1;
    while(cnt<=5842)
    {
        res[cnt++] = mmin(2*res[a],3*res[b],5*res[c],7*res[d]);
        if(2*res[a]==res[cnt-1]) a++;
        if(3*res[b]==res[cnt-1]) b++;
        if(5*res[c]==res[cnt-1]) c++;
        if(7*res[d]==res[cnt-1]) d++;
    }

    cin >> n;
    while(n!=0)
    {
        if(n%10==1 && n%100!=11) cout << "The " << n << "st humble number is " << res[n] << "." << endl;
        else if(n%10==2 && n%100!=12) cout << "The " << n << "nd humble number is " << res[n] << "." << endl;
        else if(n%10==3 && n%100!=13) cout << "The " << n << "rd humble number is " << res[n] << "." << endl;
        else cout << "The " << n << "th humble number is " << res[n] << "." << endl;
        cin >> n;
    }
    return 0;
}
