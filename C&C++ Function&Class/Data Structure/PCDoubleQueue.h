#ifndef _PCDOUBLEQUEUE_H_
#define _PCDOUBLEQUEUE_H_
#ifndef _IOSTREAM_H_
	#include <iostream>
	using std::cout;
	#define _IOSTREAM_
#endif
#ifndef _STDLIB_H_
	#include <stdlib.h>
	#define _STDLIB_H_
#endif

template<class T>
class DoubleQueue{
public:
	DoubleQueue();
	int Insert(T,int);
	int Erase();
	int Delete(int);
	int isEmpty();
	int Show(int);
	T Least(int);
	int Search(T,int);
	int length;
protected:
	struct queueNode{
		T data;
		int key;
		struct queueNode *next;
		struct queueNode *prev;
	}*head,*p,*tail,*ptr;
};
template<class T>
DoubleQueue<T>::DoubleQueue(){
	this->length=0;
	this->head=NULL;
	this->tail=NULL;
	this->p=NULL;
	this->ptr=NULL;
}
template<class T>
int DoubleQueue<T>::Insert(T value,int n){
	this->length++;

	this->p=(struct queueNode*)malloc(sizeof(struct queueNode));
	if(this->p!=NULL){
		this->p->data=value;
		if(n==1){
			this->p->prev=NULL;
			this->p->key=0;
			if(this->tail==NULL){
				this->tail=this->p;
			}else{
				this->head->prev=this->p;
			}
			this->p->next=this->head;
			this->head=this->p;
			while(this->p!=NULL){
				this->p->key=this->p->key-1;
				this->p=this->p->next;
			}
			this->p=this->head;
		}else if(n==2){
			this->p->next=NULL;
			if(this->head==NULL){
				this->head=this->p;
				this->head->key=0;
			}else{
				this->tail->next=this->p;
				this->p->key=this->tail->key+1;
			}
			this->p->prev=this->tail;
			this->tail=this->p;
		}
		return 1;
	}else{
		return 0;
	}
}
template<class T>
int DoubleQueue<T>::Erase(){
	if(this->head!=NULL || this->tail!=NULL){
		free(this->p);
		this->head=this->tail=this->p=NULL;
		this->length=0;
		return 1;
	}else{
		return 0;
	}
}
template<class T>
int DoubleQueue<T>::Delete(int n){
	if(n==1){
		this->p=this->head;
	}else if(n==2){
		this->p=this->tail;
	}else{
		return 0;
	}
	if(this->p!=NULL){
		if(n==1){
			this->p=this->p->next;
			if(this->p!=NULL){
				this->ptr=this->p->prev;
				this->ptr->next=NULL;
				free(this->ptr);
				this->ptr=NULL;
			}else{
				free(this->p);
				this->tail=NULL;
			}
			this->head=this->p;
		}else if(n==2){
			this->p=this->p->prev;
			if(this->p!=NULL){
				this->ptr=this->p->next;
				this->ptr->prev=NULL;
				free(this->ptr);
				this->ptr=NULL;
			}else{
				free(this->p);
				this->head=NULL;
			}
			this->tail=this->p;
		}
		this->length--;
		return 1;
	}else{
		return 0;
	}
}
template<class T>
int DoubleQueue<T>::isEmpty(){
	if(this->head==NULL || this->tail==NULL){
		return 1;
	}else{
		return 0;
	}
}
template<class T>
int DoubleQueue<T>::Show(int n){
	if(n==1){
		this->p=this->head;
	}else if(n==2){
		this->p=this->tail;
	}else{
		return 0;
	}
	if(this->p!=NULL){
		while(this->p!=NULL){
			cout<<this->p->data<<" ";
			if(n==1){
				this->p=this->p->next;
			}else if(n==2){
				this->p=this->p->prev;
			}
		}
		cout<<endl;
		return 1;
	}else{
		return 0;
	}
}
template<class T>
T DoubleQueue<T>::Least(int n){
	if(n==1){
		this->p=this->head;
	}else if(n==2){
		this->p=this->tail;
	}else{
		return (T)NULL;
	}
	if(this->p!=NULL){
		return this->p->data;
	}else{
		return (T)NULL;
	}
}
template<class T>
int DoubleQueue<T>::Search(T x,int n){
	if(n==1){
		this->p=this->head;
		while(this->p!=NULL){
			if(this->p->data==x){
				return this->p->key;
			}
			this->p=this->p->next;
		}
	}else if(n==2){
		this->p=this->tail;
		while(this->p!=NULL){
			if(this->p->data==x){
				return this->p->key;
			}
			this->p=this->p->prev;
		}
	}else{
		return 0;
	}

	return -1;
}
#endif //_PCDOUBLEQUEUE_H_