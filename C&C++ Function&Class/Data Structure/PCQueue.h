#ifndef _PCQUEUE_H_
#define _PCQUEUE_H_
#ifndef _IOSTREAM_
	#include <iostream>
	using std::cout;
	#define _IOSTREAM_
#endif
#ifndef _STDLIB_H_
	#include <stdlib.h>
	#define _STDLIB_H_
#endif

template<class T>
class Queue{
public:
	Queue();
	int Insert(T);
	int Erase();
	int Delete();
	int isEmpty();
	int Show();
	T Least();
	int Search(T);
	int length;
protected:
	struct queueNode{
		T data;
		int key;
		struct queueNode *next;
	}*head,*p,*tail;
};
template<class T>
Queue<T>::Queue(){
	this->length=0;
	this->head=NULL;
	this->tail=NULL;
	this->p=NULL;
}
template<class T>
int Queue<T>::Insert(T value){
	this->length++;

	this->p=(struct queueNode*)malloc(sizeof(struct queueNode));
	if(this->p!=NULL){
		this->p->data=value;
		this->p->next=NULL;
		if(this->head==NULL){
			this->p->key=0;
			this->head=this->p;
		}else{
			this->p->key=this->tail->key+1;
			this->tail->next=this->p;
		}
		this->tail=this->p;
		this->p=this->head;
		return 1;
	}else{
		return 0;
	}
}
template<class T>
int Queue<T>::Erase(){
	if(this->head!=NULL || this->tail!=NULL){
		free(this->head);
		this->head=this->p=NULL;
		this->length=0;
		return 1;
	}else{
		return 0;
	}
}
template<class T>
int Queue<T>::Delete(){
	if(this->head!=NULL || this->tail==NULL){
		this->p=this->head;
		this->head=this->head->next;
		this->p->next=NULL;
		free(p);
		this->p=this->head;
		this->length--;
		return 1;
	}else{
		return 0;
	}
}
template<class T>
int Queue<T>::isEmpty(){
	if(this->head==NULL || this->tail==NULL){
		return 1;
	}else{
		return 0;
	}
}
template<class T>
int Queue<T>::Show(){
	if(this->p!=NULL){
		while(this->p!=NULL){
			cout<<this->p->data<<" ";
			this->p=this->p->next;
		}
		cout<<endl;
		this->p=this->head;
		return 1;
	}else{
		return 0;
	}
}
template<class T>
T Queue<T>::Least(){
	if(this->p!=NULL){
		return this->p->data;
	}else{
		return (T)NULL;
	}
}
template<class T>
int Queue<T>::Search(T x){
	this->p=this->head;
	while(this->p!=NULL){
		if(this->p->data==x){
			return this->p->key;
		}
		this->p=this->p->next;
	}
	return -1;
}
#endif //_PCQUEUE_H_