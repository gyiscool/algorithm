#include <stdio.h>
#include<stdlib.h>

//����ڵ�ָ������� 
typedef struct PolyNode *Polynomial;

//����ڵ�ṹ 
struct PolyNode{
	int coef;
	int expon;
	Polynomial link; 
};

//����ͷ��ָ�� 
Polynomial CreateQueue(){
	Polynomial head;
	head = (Polynomial) malloc(sizeof(struct PolyNode));
	
	head->coef = 1;
	head->expon = 1;
	return head;
} 


Polynomial add(Polynomial head){
	Polynomial next;
	
	//�����͵ĵ�ַ�ռ佻���� 
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
	
	printf("The char is %d -- %#x\n",q->link->coef); //�����ӡ����ַ������ļ�ֵ
	
	return 0;
}


