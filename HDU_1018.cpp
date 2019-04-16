// http://acm.hdu.edu.cn/showproblem.php?pid=1018

#include <iostream>
#include <math.h>

const double e = 2.7182818;
const double pi = 3.1415926;

using namespace std;

int main()
{
    int N,n;
    double res;
    cin >> N;
    while(N--){
        cin >> n;
        res = (0.5*log(2*pi*n) + n*log(n) - n)/log(10);
        cout << (int)res + 1 << endl;

    }
    return 0;
}
