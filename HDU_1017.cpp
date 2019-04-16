// http://acm.hdu.edu.cn/showproblem.php?pid=1017
#include <iostream>

using namespace std;

int main()
{
    int m,n,T,cnt,num;
    cin >> T;
    while(T--){
        num=0;
        cin >> n >> m;
        // m可能为0，不能用 m && n
        while(m+n){
            cnt = 0;
            for(int i=1;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if((i*i+j*j+m)%(i*j)==0) cnt++;
                }
            }
            cout << "Case " << ++num << ": " << cnt << endl;
            cin >> n >> m;
        }

        if(T) cout << endl;
    }
    return 0;
}