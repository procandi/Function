#ifndef _PCSORT_H_
#define _PCSORT_H_

template<class T>
inline void swap(T *x,T *y){
	T t;
	t=*x;
	*x=*y;
	*y=t;
}
template<class T>
void Bubble(T *data,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(data[j-1]>data[j])
				swap(&data[j-1],&data[j]);
		}
	}
}
template<class T>
void Selection(T *data,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(data[i]>data[j])
				swap(&data[i],&data[j]);
		}
	}
}
#endif //_PCSORT_H_
