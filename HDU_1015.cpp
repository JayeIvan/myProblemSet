// http://acm.hdu.edu.cn/showproblem.php?pid=1015

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char str[13];
int vis[13]={0};
int res[5]={0};
int num,n=0;
bool flag = true;

long long int func(int v,int w,int x,int y,int z){
    return v-w*w+x*x*x-y*y*y*y+z*z*z*z*z;
}

void DFS(int n){
    // 如果flag = false 说明已经找到解了，可以直接退出
    if(n==5 && flag){
        long long int ans = func(res[0],res[1],res[2],res[3],res[4]);
        if(ans == num){
            flag = false;
            for(int i=0;i<5;i++) printf("%c",res[i]+'A'-1);
            printf("\n");
        }
    }
    else if(flag){
        // 从后往前搜索，满足题意，字典排序中最大字符串
        for(int i=strlen(str)-1;i>=0;i--){
            if(vis[i]!=1){
                vis[i] = 1;
                res[n++] = str[i]-'A'+1;
                DFS(n);
                n--;
                vis[i] = 0;
            }
        }
    }
}

int main(){

    scanf("%d %s",&num,str);
    while(num!=0 || strcmp(str,"END")){
        // 排序，提高效率
        sort(str,str+strlen(str));
        flag = true;
        DFS(0);
        // flag=true 说明没有找到解
        if (flag) printf("no solution\n");
        // 重置
        memset(str,'\0',sizeof(char));
        memset(res,0,sizeof(char));
        memset(vis,0,sizeof(char));
        scanf("%d %s",&num,str);
    }
    return 0;
}
