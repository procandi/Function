#ifndef _PCSTRING_H_
#define _PCSTRING_H_

inline int strlen(char *wd){
	int i;
	for(i=0;wd[i]!='\0';i++)
		;
	return i;
}
inline int strsub(char *wd,char *swd){
	int i;
	for(i=0;swd[i]!='\0';i++){
		if(wd[i]!=swd[i])
			return 0;
	}
	return 1;
}
inline int strrep(char *wd,char *swd){
	if(strsub(wd,swd)){
		int i,j=0,slen=strlen(swd);
		for(i=slen;wd[i]!='\0';i++,j++){
			if(j==slen)
				j=0;
			if(wd[i]!=swd[j])
				return 0;
		}
		if(wd[i]=='\0' && swd[j]=='\0')
			return 1;
		else
			return 0;
	}else{
		return 0;
	}
}
inline int intsub(int *wd,int *swd){
	int i,slen=sizeof(swd)/sizeof(int);
	for(i=0;i<slen;i++){
		if(wd[i]!=swd[i])
			return 0;
	}
	return 1;
}
inline int intrep(char *wd,char *swd){
	if(intsub(wd,swd)){
		int i,j=0,len=sizeof(wd)/sizeof(int),slen=sizeof(swd)/sizeof(int);
		for(i=slen;i<len;i++,j++){
			if(j==slen)
				j=0;
			if(wd[i]!=swd[j])
				return 0;
		}
		if(i==len && j==slen)
			return 1;
		else
			return 0;
	}else{
		return 0;
	}
}
template<class T>
inline T *reverse(T *n,int len){
	int i;
	T *ans=(T*)malloc(len*sizeof(T));

	ans[len]=n[len];
	for(len--,i=0;len>=0;i++,len--){
		ans[i]=n[len];
	}
	return ans;
}
#endif //_PCSTRING_H_