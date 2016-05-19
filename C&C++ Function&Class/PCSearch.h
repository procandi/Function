#ifndef _PCSEARCH_H_
#define _PCSEARCH_H_

template<class T>
inline int BinarySearch(int low,int high,T data,T *arr){
	int mid;

	while(low!=high){
		mid=(low+high)/2;
		if(data>arr[mid]){
			low=mid;
		}else if(data<arr[mid]){
			high=mid;
		}else{
			return mid;
		}
	}
	return -1;
}
#endif //_PCSEARCH_H_