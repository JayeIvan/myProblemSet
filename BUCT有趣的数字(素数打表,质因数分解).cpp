#include"stdio.h"
#include"math.h"
 
int isSushu(long long b)				//判断是否为素数
{
	long long i=0;
	int j=1;
	if(b==2)
		return 1;		
	for(i=2;i<=(long int)sqrt(b);i++)
		if(b%i==0){
			j=0;
			break;
		}
	return j;
}
 
int main()
{
	long long i=0,j=0,k=0,s[100000],b[100000]={0},n=0,m,count;
	for(i=2;i<=100000;i++)		//创建素数表
		if(isSushu(i))
			s[j++]=i;
	for(i=1;count!=500;i++)
	{
		count=1;
		m=(n+=i);				
		for(k=0;k<j && m>1;k++)
		{		
			while(m%s[k]==0)
			{
				m/=s[k];
				b[k]++;
			} 
			count*=(b[k]+1);
			b[k]=0;
		}
        if(count>=500) printf("%lld : %lld\n",n,count);
	}
	printf("%lld  :  %lld\n",n,count);
    printf("1231469730000");
	return 0;
}