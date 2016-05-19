#ifndef _PCLIST_H_
#define _PCLIST_H_
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
class List{
public:
	List();
	int Insert(T,int);
	int Erase();
	int Delete(int);
	int isEmpty();
	int Show();
	T Least();
	int Search(T);
	int length;
protected:
	struct listNode{
		T data;
		int key;
		struct listNode *next;
	}*head,*tail,*p,*ptr;
};
template<class T>
List<T>::List(){
	this->length=0;
	this->head=this->tail=this->p=this->ptr=NULL;
}
template<class T>
int List<T>::Insert(T value,int n){
	this->ptr=(struct listNode*)malloc(sizeof(struct listNode));

	if(this->ptr!=NULL){
		this->ptr->data=value;
		if(this->head==NULL || this->tail==NULL){
			this->ptr->key=n;
			this->ptr->next=NULL;
			this->p=this->head=this->tail=this->ptr;
			this->length++;
			return 1;
		}else{
			if(n>this->tail->key){
				this->tail->next=this->ptr;
				this->ptr->key=this->tail->key+1;
				this->ptr->next=NULL;
				this->tail=this->ptr;
				this->p=this->head;
				this->length++;
				return 1;
			}else if(n<this->head->key){
				this->ptr->key=this->head->key-1;
				this->ptr->next=this->head;
				this->p=this->head=this->ptr;
				this->length++;
				return 1;
			}else{
				this->p=this->head;
				while(this->p!=NULL){
					if(this->p->key==n){
						this->ptr->key=this->p->key+1;
						this->ptr->next=this->p->next;
						this->p->next=this->tail=this->ptr;
						this->p=this->ptr->next;
						while(this->p!=NULL){
							this->p->key=this->p->key+1;
							this->tail=this->p;
							this->p=this->p->next;
						}
						this->p=this->head;
						this->length++;
						return 1;
					}
					this->p=this->p->next;
				}
				return 0;
			}
		}
	}else{
		return 0;
	}
}
template<class T>
int List<T>::Erase(){
	if(this->head!=NULL || this->tail!=NULL){
		free(this->head);
		this->ptr=this->p=this->tail=this->head=NULL;
		this->length=0;
		return 1;
	}else{
		return 0;
	}
}
template<class T>
int List<T>::Delete(int n){
	if(this->head!=NULL && this->tail!=NULL){
		if(this->head->key==n){
			this->p=this->head;
			this->head=this->head->next;
			this->p->next=NULL;
			free(this->p);
			this->p=this->head;
			while(this->p!=NULL){
				this->p->key=this->p->key-1;
				this->p=this->p->next;
			}
			this->p=this->head;
			this->length--;
			return 1;
		}else{
			while(this->p!=NULL){
				this->ptr=this->p;
				this->p=this->p->next;

				if(this->p->key==n){
					this->ptr->next=this->p->next;
					this->p->next=NULL;			
					free(this->p);
					this->p=this->ptr->next;
					while(this->p!=NULL){
						this->p->key=this->p->key-1;
						this->p=this->p->next;
					}
					this->p=this->head;
					this->length--;
					return 1;
				}
			}
		}
		return 0;
	}else{
		return 0;
	}
}
template<class T>
int List<T>::isEmpty(){
	if(this->head==NULL || this->tail==NULL){
		return 1;
	}else{
		return 0;
	}
}
template<class T>
int List<T>::Show(){
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
T List<T>::Least(){
	if(this->p!=NULL){
		return this->p->data;
	}else{
		return (T)NULL;
	}
}
template<class T>
int List<T>::Search(T x){
	while(this->p!=NULL){
		if(this->p->data==x){
			this->p=this->head;
			return this->p->key;
		}
		this->p=this->p->next;
	}
	return -1;
}
#endif //_PCLIST_H_