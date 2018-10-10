#include <stdio.h>
#include<stdlib.h>

//定义节点指针的类型 
typedef struct PolyNode *Polynomial;

//定义节点结构 
struct PolyNode{
	int coef;
	int expon;
	Polynomial link; 
};

//返回头部指针 
Polynomial CreateQueue(){
	Polynomial head;
	head = (Polynomial) malloc(sizeof(struct PolyNode));
	
	head->coef = 1;
	head->expon = 1;
	return head;
} 


Polynomial add(Polynomial head){
	Polynomial next;
	
	//把类型的地址空间交过来 
	next = (Polynomial) malloc(sizeof(struct PolyNode));
	next->coef = 2;
	next->expon = 2;
	head->link = next ;

	return head;
} 

int main(){
	
	Polynomial P1,P2,PP,PS;
	
	P1 = ReadPoly();
	P2 = ReadPoly();
	PP = Mult(P1,P2); //
	PrintPoly(PP);
	PS = Add(P1,P2)
	
	PrintPoly(PS);
	
	
	Polynomial q= CreateQueue();
	add(q);
	
	printf("The char is %d -- %#x\n",q->link->coef); //否则打印这个字符和它的键值
	
	return 0;
}


