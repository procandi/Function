#ifndef _PCSOLVE_H_
#define _PCSOLVE_H_
#ifndef _MALLOC_H_
	#include <malloc.h>
	#define _MALLOC_H_
#endif
#ifndef _PCSTRING_H_
	#include "PCString.h"
	#define _PCSTRING_H_
#endif
#ifndef _PCMATH_H_
	#include "PCMath.h"
	#define _PCMATH_H_
#endif
#ifndef _PCSEARCH_H_
	#include "PCSearch.h"
	#define _PCSEARCH_H_
#endif

void SHORTEST(int **city,int n){
	int i,j,k;
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			if(city[i][k]!=0 && i!=k){
				for(j=0;j<n;j++){
					if(city[k][j]!=0 && k!=j){
						if((city[i][j]==0 || city[i][j]>city[i][k]+city[k][j]) && i!=j){
							city[i][j]=city[i][k]+city[k][j];
						}
					}
				}
			}
		}
	}
}
int *SHORTEST_PATH(int x,int y,int **old_city,int **city,int n){
	int i,sum=0,*path=(int*)malloc(sizeof(int)*n);
	
	path[sum++]=x;

	while(x!=y){
		for(i=1;i<=n;i++){
			if(x!=i && old_city[x][i]!=0 && old_city[x][i]+city[i][y]==city[x][y]){
				x=i;
				break;
			}
		}
		path[sum++]=x;
	}
	path[sum]=-1;

	return path;
}
int MAS(int **data,int n){
	int i,j,x,y,ans=0,temp;
	int **sum=(int**)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++){
		sum[i]=(int*)malloc(sizeof(int)*n);
		for(j=0;j<n;j++){
			for(sum[i][j]=x=0;x<=i;x++){
				for(y=0;y<=j;y++){
					sum[i][j]+=data[x][y];
				}
			}
		 }
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(x=i;x<n;x++){
				for(y=j;y<n;y++){
					if(i>0 && j>0){
						temp=sum[x][y]-sum[x][j-1]-sum[i-1][y]+sum[i-1][j-1];
					}else if(i==0 && j>0){
						temp=sum[x][y]-sum[x][j-1];
					}else if(i>0 && j==0){
						temp=sum[x][y]-sum[i-1][y];
					}else if(i==0 && j==0){
						temp=sum[x][y];
					}
					if(temp>ans)
						ans=temp;
				}
			}
		}
	}
	
	return ans;
}
template<class T>
int MCS(T *data,int len){
	int i,ans=0,temp=0;
	
	for(i=0;i<len;i++){
		if(data[i]>=0){
			temp+=data[i];
		}else{
			if(temp>ans)
				ans=temp;
			temp+=data[i];
			if(temp<0)
				temp=0;
		}
	}
	return MAX(ans,temp);
}
int LCS(char *c1,char *c2){
	int len1=strlen(c1),len2=strlen(c2),i,j;
	int **matrix=(int**)malloc(sizeof(int)*(len1+1));

	for(i=0;i<=len1;i++){
		matrix[i]=(int*)malloc(sizeof(int)*(len2+1));
		matrix[i][0]=0;
	}
	for(i=0;i<=len2;i++)
		matrix[0][i]=0;

	for(i=1;i<=len1;i++){
		for(j=1;j<=len2;j++){
			if(c1[i-1]==c2[j-1]){
				matrix[i][j]=matrix[i-1][j-1]+1;
			}else{
				matrix[i][j]=MAX(matrix[i][j-1],matrix[i-1][j]);
			}
		}
	}

	/*int count=matrix[len1][len2];						//Print Path
	char *reslunt=(*char)malloc(sizeof(char)*count);
	result[count--]='\0';
	for(i=len1,j=len2;i!=0 && j!=0;){
		if(matrix[i][j]==matrix[i-1][j]){
			i--;
		}else if(matrix[i][j]==matrix[i][j-1]){
			j--;
		}else{
			result[count--]=c1[i-1];
			i--;
			j--;
		}
	}
	puts(result);*/

	return matrix[len1][len2];
}
int LIS(char *c,int len){
	int i,max=0,low,high,mid;
	char *val=(char*)malloc(sizeof(char)*len);

	//�Bad Selection
	/*for(i=0;i<len;i++){
		val[i]=1;
		for(j=0;j<i;j++){
			if(c[i]>=c[j] && val[i]>=val[j]){
				val[i]=val[j]+1;
				if(val[i]>max)
					max=val[i];
			}
		}
	}*/
	val[0]=c[0];
	for(i=1;i<len;i++){
		if(c[i]>=val[max]){
			val[++max]=c[i];
		}else if(c[i]<val[0]){
			val[0]=c[i];
		}else{
			for(low=0,high=max;low!=high-1 && low!=high;){
				mid=(low+high)/2;
				if(val[mid]<=c[i]){
					low=mid;
				}else{
					high=mid;
				}
			}
			val[high]=c[i];
		}
	}

	return max+1;
}
/*	Print Road
int LIS(int *c,int len){
	int i,j,max=0,low,high,mid,sum=0,big=0;
	int ansmax=0,**ans=(int**)malloc(sizeof(int)*len);

	ans[sum]=(int*)malloc(sizeof(int)*len);
	ans[sum][0]=c[0];
	for(i=1;i<len;i++){
		if(c[i]>ans[sum][max]){
			ans[sum][++max]=c[i];
		}else if(c[i]<ans[sum][0]){
			if(max>=ansmax){
				big=sum;
				ansmax=max;
			}
			sum++;
			ans[sum]=(int*)malloc(sizeof(int)*len);
			max=0;
			ans[sum][0]=c[i];
		}else{
			for(low=0,high=max;low!=high-1 && low!=high;){
				mid=(low+high)/2;
				if(ans[sum][mid]<=c[i]){
					low=mid;
				}else{
					high=mid;
				}
			}
			if(max>=ansmax){
				big=sum;
				ansmax=max;
			}
			sum++;
			ans[sum]=(int*)malloc(sizeof(int)*len);
			for(j=0;j<high;j++)
				ans[sum][j]=ans[sum-1][j];
			max=high;
			ans[sum][high]=c[i];
		}
	}

	if(max>=ansmax){
		big=sum;
		ansmax=max;
	}

	for(i=0;i<=ansmax;i++)
		printf("%d\n",ans[big][i]);
	return ansmax+1;
}
*/
int STREDIT(char *a,char *b){
	const int INSERT_COST=1;
	const int DELETE_COST=1;
	const int EXCHANGE_COST=2;
	int i,j;
	int insert_b,delete_a,exchange;
	int len_a=strlen(a),len_b=strlen(b);
	char **c=(char**)malloc(sizeof(char)*(len_a+1));

	for(i=0;i<=len_a;i++){
		c[i]=(char*)malloc(sizeof(char)*(len_b+1));
		c[i][0]=i;
	}
	for(i=0;i<=len_b;i++)
		c[0][i]=i;

	for(i=0;i<len_a;i++){
		for(j=0;j<len_b;j++){
			if(a[i]==b[j]){
				c[i+1][j+1]=c[i][j];
			}else{
				insert_b=c[i+1][j]+INSERT_COST;
				delete_a=c[i][j+1]+DELETE_COST;
				exchange=c[i][j]+EXCHANGE_COST;
				c[i+1][j+1]=MIN(MIN(insert_b,delete_a),exchange);
			}
		}
	}
	return c[len_a][len_b];
}
int **Gray(int n,int &max){
	int i,j,k=1,flag,**ans,*code;

	if(n==1)
		max=2;
	else
		max=1;

	for(i=1;i<n;i++)
		max=max*2+1;

	code=(int*)malloc(sizeof(int)*max);
	for(i=0;i<n;i++)
		code[i]=0;

	ans=(int**)malloc(sizeof(int)*max);
	for(i=0;i<max;i++)
		ans[i]=(int*)malloc(sizeof(int)*n);

	for(j=1;j<=max;j++,k++){
		for(i=n-1;i>=0;i--){
			ans[k-1][i]=code[i];
		}

		if(j%2==0){
			switch(k){
			case 2:
			case 6:
				code[1]=1-code[1];
				break;
			case 4:
				code[2]=1-code[2];
				break;
			case 8:
				if(flag>n)
					flag=4;
				code[flag-1]=1-code[flag-1];
				flag++;
				k=0;
				break;
			}
		}else{
			code[0]=1-code[0];
		}
	}

	return ans;
}
char *RPF(char a,char b,char *wd){	//RPF(Reversed Polish Form)
	int len=strlen(wd),sp=1,ap=0,i;
	char *stack,*ans;

	stack=(char*)malloc(sizeof(char)*len+1);
	ans=(char*)malloc(sizeof(char)*len);

	for(i=0;i<len;i++){
		 if(wd[i]=='+' || wd[i]=='-'){
			if(stack[sp-1]=='+' || stack[sp-1]=='-'){
				ans[ap++]=wd[i];
			}else{
				stack[sp++]=wd[i];
			}
		}else if(wd[i]=='*' || wd[i]=='/'){
			 if(stack[sp-1]=='*' || stack[sp-1]=='/'){
				ans[ap++]=wd[i];
			}else{
				stack[sp++]=wd[i];
			}
		}else if(wd[i]>=a && wd[i]<=b){
			ans[ap++]=wd[i];
			if(stack[sp-1]=='*' || stack[sp-1]=='/'){
				sp--;
				ans[ap++]=stack[sp];
			}
		}
	}

	sp--;
	while(sp>0){
		ans[ap++]=stack[sp--];
	}
	ans[ap]='\0';

	return ans;
}
char *RPFX(char a,char b,char *wd){		//RPF(Reversed Polish Form) can solve '(' and ')'
	int len=strlen(wd),sp=1,ap=0,i;
	char *stack,*ans;

	stack=(char*)malloc(sizeof(char)*len+1);
	ans=(char*)malloc(sizeof(char)*len);

	for(i=0;i<len;i++){
		 if(wd[i]=='+' || wd[i]=='-'){
			while(stack[sp-1]=='+' || stack[sp-1]=='-' || stack[sp-1]=='*' || stack[sp-1]=='/'){
				sp--;
				ans[ap++]=stack[sp];
			}
			if(stack[sp-1]=='+' || stack[sp-1]=='-'){
				ans[ap++]=wd[i];
			}else{
				stack[sp++]=wd[i];
			}
		}else if(wd[i]=='*' || wd[i]=='/'){
			 if(stack[sp-1]=='*' || stack[sp-1]=='/'){
				ans[ap++]=wd[i];
			}else{
				stack[sp++]=wd[i];
			}
		}else if(wd[i]>=a && wd[i]<=b){
			ans[ap++]=wd[i];
			if(stack[sp-1]=='*' || stack[sp-1]=='/'){
				sp--;
				ans[ap++]=stack[sp];
				stack[sp]='\0';
			}
		}else if(wd[i]=='('){
			stack[sp++]='(';
		}else if(wd[i]==')'){
			sp--;
			while(stack[sp]!='('){
				ans[ap++]=stack[sp--];
			}
			stack[sp]='\0';
		}
	}

	sp--;
	while(sp>0){
		ans[ap++]=stack[sp--];
	}
	ans[ap]='\0';

	return ans;
}
#endif //_PCSOLVE_H_