//http://acm.hdu.edu.cn/showproblem.php?pid=1016
/*
素数环，DFS
*/

#include <cstdio>
#include <cstring>

using namespace std;

// visit用于标志是否访问过,path用于顺序输出
int visit[21];
int path[21];

bool isPrimeNumber(int n){
    if(n==2 || n==3 || n==5 || n==7) return true;
    if(n%2==0 || n%3==0 || n%5==0 || n%7==0) return false;
    else return true;
}

void dfs(int num,int arr[21][21],int n){
    if(num==n && arr[1][path[num]]==1){
        for(int i=1;i<=n;i++){
            if(i!=n)printf("%d ",path[i]);
            if(i==n)printf("%d\n",path[i]);
        }
    }
    else{
        for(int i=2;i<=n;i++){
            if(arr[path[num]][i]==1 && visit[i]==0){
                // 回退出去的时候，把访问过的结点visit置为0，便于接着这里继续往下访问
                visit[i] = 1;
                path[++num] = i;
                dfs(num,arr,n);
                visit[i]=0;
                num--;
            }
        }
    }
}

int main(){
    int n,i,j,cnt=0;
    int arr[21][21];
    // 初始化邻接矩阵
    for(i=1;i<=20;i++){
            for(j=1;j<=20;j++){
                if(isPrimeNumber(i+j)){
                    arr[i][j]=1;
                    arr[j][i]=1;
                }
                else {
                    arr[i][j]=0;
                    arr[j][i]=0;
                }
            }
        }
    while(scanf("%d",&n)==1){
        cnt++;
        path[1]=1;
        memset(visit,0,sizeof(visit));
        printf("Case %d:\n",cnt);
        dfs(1,arr,n);
        printf("\n");
    }
    return 0;
}
