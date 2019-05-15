// http://acm.hdu.edu.cn/showproblem.php?pid=1071
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int t;
    double x1,y1,x2,y2,x3,y3,area;
    double a,b,c,k,m,x;

    cin >> t;
    while(t--){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        a = (y2-y1)/((x1-x2)*(x1-x2));
        b = -2*a*x1;
        c = y1 + a*x1*x1;
        k = (y2 - y3)/(x2 - x3);
        m = y2 - k*x2;
        area = (a/3)*x3*x3*x3 + (b-k)*x3*x3/2 + (c-m)*x3 - ((a/3)*x2*x2*x2 + (b-k)*x2*x2/2 + (c-m)*x2) ;
        cout<< setiosflags(ios::fixed) << setprecision(2);
        cout << area << endl;
    }
    return 0;
}
