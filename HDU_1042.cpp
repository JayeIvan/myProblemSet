// http://acm.hdu.edu.cn/showproblem.php?pid=1042
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int res[50000],m,n,t,i,j,len;
    while(cin >> n){
        memset(res,0,sizeof(int)*50000);
        res[1] = 1;
        len = 1;
        m = 0;
        for(i=1;i<=n;i++){
            m = 0;
            for(j=1;j<=len;j++){
                t = res[j]*i+m;
                res[j] = t%10;
                m = t/10;
            }
            while(m){
                res[++len] = m%10;
                m /= 10;
            }
        }
        for(i=len;i>0;i--){
            cout << res[i];
        }
        cout << endl;
    }
    return 0;
}

//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//int main()
//{
//    int res[50000],temp[50000],n,k,t,i,j,len;
//    while(cin >> n){
//        len = 1;
//        memset(res,0,sizeof(int)*50000);
//        memset(temp,0,sizeof(int)*50000);
//        res[1] = 1;
//        for(i=1;i<=n;i++){
//            for(j=1;j<=len;j++){
//                t = res[j]*i;
//                k = j;
//                while(t){
//                    temp[k] += t%10;
//                    if(temp[k]>9){
//                        temp[k+1] = temp[k]/10;
//                        temp[k] = temp[k]%10;
//                    }
//                    t /= 10;
//                    k++;
//                }
//            }
//            for(int h=0;h<=k;h++){
//                res[h] = temp[h];
//            }
//            len = k-1;
//            memset(temp,0,sizeof(int)*50000);
//        }
//        for(i=len;i>0;i--){
//            cout << res[i];
//        }
//        cout << endl;
//    }
//}
