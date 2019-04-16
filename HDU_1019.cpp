// http://acm.hdu.edu.cn/showproblem.php?pid=1019
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int LCM(const int& x,const int& y){
    int a=x;
    int b=y;
    int t = a%b;
    while(t){
        a = b;
        b = t;
        t = a%b;
    }
    // 先除后乘，避免溢出
    return x/b*y;
}

int main()
{
    int *arr,N,m,res;
    cin >> N;
    while(N--){
        cin >> m;
        arr = (int*)calloc(m,sizeof(int));

        for(int i=0;i<m;i++) cin >> arr[i];
        sort(arr,arr+m);
        res = arr[0];
        for(int i=1;i<m;i++){
            res = LCM(res,arr[i]);
        }
        cout << res << endl;
        free(arr);
    }
    return 0;
}
