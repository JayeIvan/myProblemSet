// http://acm.hdu.edu.cn/showproblem.php?pid=1061
#include <iostream>

using namespace std;

int main()
{
    int a,i,j,res[10][10],t,x;
    long long n;
    for(i=0;i<10;i++){
        j = 1;
        a = i;
        res[i][j++] = i;
        do{
            a = (a*i)%10;
            res[i][j++] = a;
        }while(a != i);
        res[i][0] = j-2;
    }

    cin >> t;
    while(t--){
        cin >> n;
        a = n%10;
        x = n%res[a][0];
        if(x == 0) x = res[a][0];
        cout << res[a][x] << endl;
    }
    return 0;
}
