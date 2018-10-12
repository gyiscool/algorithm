#include <stdio.h>
#include<stdlib.h>

//����ڵ�ָ������� 
typedef struct PolyNode *Polynomial;

//����ڵ�ṹ 
struct PolyNode{
	int coef;//ϵ�� 
	int expon;//ָ�� 
	Polynomial link; 
};

//����ͷ��ָ�� 
Polynomial CreateQueue(){
	PolyNode *head;
	head = (Polynomial) malloc(sizeof(struct PolyNode));
	
	head->coef = 0;
	head->expon = 0;
	head->link = NULL;
	
	return head;
} 

void printNode(PolyNode *head){

	do{
		//�Ƿ��������ʽ 
		if(head->coef == 0 && head->expon ==0 && head->link == NULL  ){
			printf("0 0");
			break;
		}
		if(head->coef != 0 || head->expon !=0){
			printf("%d %d",head->coef,head->expon);
			if(head->link != NULL) printf(" ");
		}
		head = head->link;
	}while(head != NULL);	

} 

//����׷�ӽṹ��Ԫ�� ϵ���Ӵ�С �Զ���˳�� �ϲ���ָͬ����� ϵ�� 
PolyNode *push(PolyNode *head,int coef,int expon){
	Polynomial now,pre = head ,p = head;
	
	if (coef ==0 && expon == 0){
		return head;
	} 
	//��ȡ���һ��Ԫ�ص�ָ�� ��ϵ����ķź��� ϵ���Ӵ�С  pre  
	while(   pre != NULL &&(pre->expon > expon || (pre->expon == 0 && pre->coef == 0))){
		p = pre;
		pre = pre->link; 
	}

	//��ϵ����ͬ����� ������ 
	if(pre != NULL && (pre->expon == expon)){
		 pre->coef = pre->coef+coef; 
		 
		 //��� 
		 if(pre->coef == 0){
		 	p->link = pre->link; 
		 
		 }
		 
		 return head;
	}
		
	//�����͵ĵ�ַ�ռ佻���� 
	now = ( PolyNode *) malloc(sizeof(struct PolyNode));
	now->coef = coef;
	now->expon = expon;
	now->link = NULL;
	
	if(p->link != NULL){
		now->link = p->link;
	}
	
	p->link = now ;

	return head;
}

Polynomial CopyNodes(PolyNode *copy){
	PolyNode *head;
	head = CreateQueue();
	
	copy = copy->link;
	
	while(copy != NULL){
		push(head,copy->coef,copy->expon);
		copy = copy->link;
	}
	
	return head;
} 

//׷�� 
PolyNode *pushNodes(PolyNode *head,PolyNode *next){
	
	//��ȡ���һ��Ԫ�ص�ָ�� ��ϵ����ķź��� ϵ���Ӵ�С  pre  
	while(next != NULL){
		push(head,next->coef,next->expon);
		next= next->link;
		
	}
	

	return head;
} 



//�����������
PolyNode *Add(PolyNode *head1,PolyNode *head2) {

	//p1,p2�������ڱ���newHead �·��ص�ͷ�� 
	PolyNode *p1,*p2,*newHead;
	p1 = head1;
	p2 = head2; 
	newHead = CreateQueue();
	int coef,expon;
	
	
	//ѭ���Ա�  
	while(p2 != NULL && p1 !=NULL) {
		
		//���ָ����� 
		if(p1->expon == p2->expon){
			expon = p1->expon; 
			coef = p1->coef+p2->coef;
			
			//�ƶ�ָ�� 
			p2 = p2->link;
			p1 = p1->link;
			
			if(coef == 0 ) continue;
			
		}else if(p1->expon > p2->expon){ //��һ��ָ���� 
			coef = p1->coef;
			expon = p1->expon;
			
			//�ƶ�ָ��
			p1 = p1->link;
			
		}else{//�ڶ���ָ���� 
			coef = p2->coef;
			expon = p2->expon;
			
			//�ƶ�ָ��
			p2 = p2->link;
			
		}
		 
		 //Ϊ ������ ׷��Ԫ��
		push(newHead,coef,expon);
		
	}
	
	
	if(p2 == NULL || p1 != NULL){
		pushNodes(newHead,p1);
	}
	
	
	if(p1 == NULL || p2 != NULL){
		pushNodes(newHead,p2);
	}
		
	
	return newHead;
	
}

//��ȡ���� 
PolyNode *ReadPoly(){
	PolyNode *p1;
	p1  =CreateQueue();
	int N,c,e;
	
	scanf("%d",&N);
	
	while(N--){
		scanf("%d %d",&c,&e);
		push(p1,c,e);
	}
	
	return  p1;
} 

//�˷� 
PolyNode *Mult(PolyNode *head1,PolyNode *head2){
	PolyNode *newNodes,*temp,*head3,*temp1;
	
	newNodes = CreateQueue();
	
	temp   = CopyNodes(head2);
	temp1 = temp;
	
	
	while(head1 != NULL ){
		head3 = head2;
		temp = temp1;
		
		if(head1->coef == 0) {
			head1 = head1->link;
			continue;
		};
		
		while(head3 != NULL){

			temp->coef = (head3->coef*head1->coef);
			temp->expon = (head3->expon+head1->expon);
			if(head3->coef == 0 && head3->expon == 0) {
				temp->coef = 0;
				temp->expon = 0;	
			}
		
			head3 = head3->link;
			temp = temp->link;	
		}

	   
		
		newNodes =Add(newNodes,temp1);
		
		
		head1 = head1->link;
		
	} 
	
	
	return  newNodes;
} 

int main(){
	
	Polynomial P1,P2,PS,PM;
	//printf("�����룺")	;
	P1 = ReadPoly();
	P2 = ReadPoly();


	PS = Add(P1,P2); 
	PM = Mult(P1,P2);

	printNode(PM);
	printf("\n");
	printNode(PS);
	 

	return 0;
}
