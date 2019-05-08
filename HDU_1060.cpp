// http://acm.hdu.edu.cn/showproblem.php?pid=1060
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int t;
    double a;
    long long n;

    cin >> t;
    while(t--){
        cin >> n;
        a = n*log10(n);
        a = pow(10,a - floor(a));
        cout << int(a) << endl;
    }
    return 0;
}
