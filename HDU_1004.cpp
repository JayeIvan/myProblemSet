// http://acm.hdu.edu.cn/showproblem.php?pid=1004
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n,i,j,k,m;
    int *numb;
    char **strs,str[15];
    scanf("%d",&n);
    while(n){
        // 动态申请内存
        strs = (char **)malloc(n*sizeof(char*));
        for(i=0;i<n;i++){
            strs[i] = (char*)malloc(15*sizeof(char));
        }
        numb = (int *)calloc(n,sizeof(int));

        // 第一个颜色初始化
        k = 1;
        scanf("%s",strs[0]);
        numb[0]=1;

        for(i=1;i<n;i++){
            scanf("%s",str);

            for(j=0;j<k;j++){
                // 一一与之前输入的颜色比较
                // 如果出现过，对应的个数+1
                if(strcmp(strs[j],str)==0){
                    numb[j]++;
                    break;
                }
            }
            // 如果是一个新的颜色，就添加到字符串数组里，然后对应的个数+1
            if(j>=k){
                k++;
                strcpy(strs[k-1],str);
                numb[k-1]=1;
            }


        }
        //for(i=0;i<k;i++) printf("%d : %s\n",numb[i],strs[i]);
        //printf("\n");
        for(i=0,m=0;i<k;i++){
            if(m<numb[i]){
                 m = numb[i];
                 j=i;
            }
        }
        printf("%s\n",strs[j]);
        //释放内存
        for(i=0;i<n;i++){
            free(strs[i]);
        }
        free(strs);
        free(numb);
        scanf("%d",&n);
    }
    return 0;
}