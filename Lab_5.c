#include<stdio.h>
#define MAX 10

void top(int ad[MAX][MAX], int n){
	int f,count=0,flag=1,i,j,k;
	int torder[100],in=1;
	
	while(flag){
		count++;
		for(i=1;i<=n;i++){
			f=0;
			for(j=1;j<=n;j++){
				if(ad[j][i]!=0 || torder[j]==i){
					f=1;
					break;
				}
			}
			if(f!=1){
				torder[in++] = i;
				for(k=1;k<=n;k++)
					ad[i][k] = 0;
			}
		}
		if(count==n || in>n )
			flag = 0;
	}
	if(in<=n)
		printf("No topological order \n");
	else {
		printf("Topological sequence order\n");
		for(i=1;i<=n;i++)
			printf("%d\t",torder[i]);
	}
}

void main() {
	int ad[MAX][MAX],n,i,j;
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	printf("Enter the matrix of digraph : \n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&ad[i][j]);
	top(ad,n);
}
	
