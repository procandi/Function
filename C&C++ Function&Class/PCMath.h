#ifndef _PCMATH_H_
#define _PCMATH_H_
#ifndef _MALLOC_H_
	#include <malloc.h>
	#define _MALLOC_H_
#endif
#ifndef _PCSTRING_H_
	#include "PCString.h"
	#define _PCSTRING_H_
#endif

/* 
	1+2+3+...+n
	
	(n*(n+1))/2 
*/
/*
	if a Point(x,y) in a Circle(a,b,r) then
	num1=x-a
	num2=y-b
	(num1*num1)+(num2*num2)<(r*r) is Currect!
*/
template<class T1,class T2>
inline double log(T1 x,T2 n){
	int ans=0;
	if(x%n==0 && n>1){
		while(x/n>1){
			x/=n;
			ans++;
		}
		return ans+1;
	}else if(x==1 && n==1){
		return -8;
	}else if(x==1){
		return 0;
	}else{
		return -1;
	}
}
template<class T>
inline T abs(T n){
	if(n>0)
		return n;
	else 
		return -n;
}
template<class T>
inline T sqrt(T n){
	T mid,x=0,y=n;
	while(1){
		mid=(x+y)/2;
		if(abs(mid*mid-n)<0.1)
			break;
		if(mid*mid>n)
			y=mid;
		else if(mid*mid<n)
			x=mid;
	}
	return mid;
}
template<class T>
inline T MAX(T x,T y){
	if(x>y)
		return x;
	else
		return y;
}
template<class T>
inline T MIN(T a,T b){
	if(a<b)
		return a;
	else
		return b;
}
inline int ctoi(char c){
	if(c>='0' && c<='9')
		return c-'0';
	else
		return 0;
}
inline char itoc(int i){
	if(i>=0 && i<=9)
		return i+'0';
	else
		return 0;
}
char *itoca(int n,int len){
	int i,x;
	for(x=n,i=0;x>0;i++){
		num[n][i]=itoc(x%10);
		x/=10;
	}
	num[n][i]='\0';
	len=i;
	return reverse(num[n],i);
}
int *IBigAdd(char *x,char *y,int xlen,int ylen){
	int anslen=MAX(xlen,ylen),i;
	int *ans=(int*)malloc((anslen+1)*sizeof(int));
	int temp=0;
	
	x=reverse(x,xlen);
	y=reverse(y,ylen);

	for(i=0;i<anslen;i++){
		temp=ctoi(x[i])+ctoi(y[i])+temp;
		ans[i]=temp%10;
		temp/=10;
	}
	if(temp>0){
		ans[anslen]=temp;
		anslen++;
	}

	return reverse(ans,anslen);
}
int *IBigAdd(int *x,int *y,int xlen,int ylen){
	int anslen=MAX(xlen,ylen),i;
	int *ans=(int*)malloc((anslen+1)*sizeof(int));
	int temp=0;
	
	x=reverse(x,xlen);
	y=reverse(y,ylen);

	for(i=0;i<anslen;i++){
		temp=x[i]+y[i]+temp;
		ans[i]=temp%10;
		temp/=10;
	}
	if(temp>0){
		ans[anslen]=temp;
		anslen++;
	}

	return reverse(ans,anslen);
}
char *CBigAdd(char *x,char *y,int xlen,int ylen){
	int anslen=MAX(xlen,ylen),i;
	char *ans=(char*)malloc((anslen+1)*sizeof(char));
	int temp=0;
	
	x=reverse(x,xlen);
	y=reverse(y,ylen);

	for(i=0;i<anslen;i++){
		temp=ctoi(x[i])+ctoi(y[i])+temp;
		ans[i]=itoc(temp%10);
		temp/=10;
	}
	if(temp>0){
		ans[anslen]=itoc(temp);
		anslen++;
	}
	ans[anslen]='\0';

	return reverse(ans,anslen);
}
char *CBigAdd(int *x,int *y,int xlen,int ylen){
	int anslen=MAX(xlen,ylen),i;
	char *ans=(char*)malloc((anslen+1)*sizeof(char));
	int temp=0;
	
	x=reverse(x,xlen);
	y=reverse(y,ylen);

	for(i=0;i<anslen;i++){
		temp=x[i]+y[i]+temp;
		ans[i]=itoc(temp%10);
		temp/=10;
	}
	if(temp>0){
		ans[anslen]=itoc(temp);
		anslen++;
	}
	ans[anslen]='\0';

	return reverse(ans,anslen);
}
char *CBigMul(char *x,char *y,int xlen,int ylen){
	int anslen=xlen+ylen,i,j;
	char *ans=(char*)malloc((anslen+1)*sizeof(char));
	int temp=0,flag=0;
	
	x=reverse(x,xlen);
	y=reverse(y,ylen);

	for(i=0;i<anslen;i++)
		ans[i]='0';
	ans[anslen]='\0';

	for(i=0;i<xlen;i++){
		for(j=0;j<ylen;j++){
			temp=ctoi(x[i])*ctoi(y[j])+temp;
			ans[i+j]+=itoc((temp%10))-'0';
			temp/=10;
			if(ans[i+j]>'9'){
				ans[i+j]=itoc(ctoi(ans[i+j])%10);
				temp++;
			}
		}
		if(temp>0){
			ans[i+j]=itoc(temp);
			temp=0;
		}
	}
	if(temp>0){
		ans[anslen]=itoc(temp);
		anslen++;
	}
	while(ans[anslen-1]=='0' || ans[anslen-1]=='\0')
		anslen--;
	ans[anslen]='\0';

	return reverse(ans,anslen);
}
char *CBigSub(char *x,char *y,int xlen,int ylen){
	int anslen=MAX(xlen,ylen),i;
	char *ans=(char*)malloc((anslen+1)*sizeof(char));
	int temp=0,big;

	for(i=anslen-1;i>=0;i--){
		if(x[i]==NULL){
			x[i]='0';
		}else if(y[i]==NULL){
			y[i]='0';
		}
	}
	x[anslen]='\0';
	y[anslen]='\0';
	if(anslen!=xlen)
		x=reverse(x,anslen);
	else if(anslen!=ylen)
		y=reverse(y,anslen);
	big=strcmp(x,y);
	x=reverse(x,anslen);
	y=reverse(y,anslen);

	for(i=0;i<anslen;i++){
		if(big==1)
			temp=ctoi(x[i])-ctoi(y[i])+temp;
		else
			temp=ctoi(y[i])-ctoi(x[i])+temp;
		if(temp<0){
			ans[i]=itoc(10+temp);
			temp=-1;
		}else{
			ans[i]=itoc(temp);
			temp=0;
		}
	}

	for(i=anslen-1;i>=0;i--){
		if(ans[i]=='0'){
			anslen--;
		}else{
			break;
		}
	}
	if(big==-1){
		ans[anslen]='-';
		anslen++;
	}
	ans[anslen]='\0';

	return reverse(ans,anslen);
}
char *BASE_CONVERT(int a,int b,char *num,int len){
	int i,sum=0,pow=1,temp;
	
	for(i=len-1;i>=0;i--){
		if(num[i]>='A'){
			sum+=(num[i]-'A'+10)*pow;
		}else{
			sum+=(num[i]-'0')*pow;
		}
		pow*=a;		
	}
	len=0;
	
	while(sum>0){
		temp=sum%b;
		if(temp>=10){
			num[len++]=temp+'A'-10;
		}else{
			num[len++]=temp+'0';
		}
		sum/=b;
	}
	num[len++]='\0';
	
	return reverse(num,len-1);
}
#endif //_PCMATH_H_