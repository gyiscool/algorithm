#include <stdio.h>
#include<stdlib.h>

//���ݽڵ㹹�� 
struct numNode{
	int address;
	int data;
	int nextAddress;
	numNode *link;
};

//�ж��Ƿ��ǵ�һ��ͷ���սڵ� 
bool isFirstNode(numNode *head){
	if(head->address == 0 && head->data ==0 && head->nextAddress == 0){
		return true;
	}
	
	return false;
}

numNode *findLastNode(numNode *head){
	
	while(head->link != NULL){
		head = head->link;
	}
	
	return head;
}

void readNodes(numNode *head){
	
	head = head->link;
	while(head != NULL ){
		
		printf("Address:%d Data:%d nextAddress:%d \n",head->address,head->data,head->nextAddress);
		head = head->link;
	}
	
}

void readNodes_v2(int num){
	
	if(num>=0){
		if(num<10){
			printf("0000");
		} else if(num<100){
			printf("000");
		}else if(num<1000){
			printf("00");
		}else if(num<10000){
			printf("0");
		} 
	}
	
	
	
}

//������ 
void readNodes_v2(numNode *head){
	
	head = head->link;
	while(head != NULL ){
		
		readNodes_v2(head->address);
		printf("%d ",head->address);
		printf("%d ",head->data);
		readNodes_v2(head->nextAddress);
		printf("%d\n",head->nextAddress);
		
		head = head->link;
	}
	
}

numNode *createNode(int address, int data,int nextAddress){
	numNode *nowNode;
	
	nowNode = (numNode *) malloc(sizeof(struct numNode));
	
	nowNode->address = address;
	nowNode->data = data;
	nowNode->nextAddress = nextAddress;
	nowNode->link = NULL;
	
	return  nowNode;
}

numNode *createHead(){
	numNode *head;
	head = createNode(0,  0, 0);
	return  head;
}

//׷��һ��Ԫ�� 
void pushLastNode(numNode *head,int nowAddress,int nowData,int nowNum){
	
	numNode *lastNode,*newNode;
	
	//�ҵ����һ��Ԫ�� 
	lastNode = findLastNode(head);
	 
	//����һ���½ڵ�Ԫ�� 
	newNode = createNode(nowAddress,  nowData, nowNum);
	
	lastNode->link = newNode;
	
}

//Push ��ջ ���� ��ջԪ�ص�ָ��  �����޸���һ����ַ��ֵ 
numNode *push(numNode *stack,int nowAddress,int nowData,int nowNum){
	
	//��ʱ�������ͷָ��  stack�����ǿ�  
	numNode *temp,*newNode;
	
	temp = stack;
	 
	//ָ���½ڵ�
	newNode = createNode(nowAddress,  nowData, nowNum);
	
	newNode->link = stack->link;
	
/*	if(stack->link != NULL){
		newNode->nextAddress = stack->link->nextAddress; 
	}
	*/
	stack->link= newNode;
	//�½ڵ���� TOP 
	//stack->link->link =  temp->link;

	return newNode;
	
}

numNode *findByAddress(numNode *head,int address){

	numNode *next_head;
	
	while(head != NULL){
		
		if(head->address == address && head->data != 0){
			
			next_head = createNode(head->address, head->data,head->nextAddress); 
			return next_head;
			break;
		} 
		
		head = head->link;
		
	}
	
	return NULL;
	
}

void sourcess(numNode *head){
	
	numNode *pre_node;
	
	pre_node = head;
	head= head->link;
	
	while(head != NULL){
		
		//����ǵ�һ�� ���� 
		if(!isFirstNode(pre_node)) {
			pre_node->nextAddress = head->address; 
		} 
		
		if(head->link == NULL){
			head->nextAddress = -1;
		}
		 
		//printf("\n%d\n",pre_node->nextAddress);
		//printf("Address:%d Data:%d nextAddress:%d \n",pre_node->address,pre_node->data,pre_node->nextAddress);
		pre_node = head;
		head = head->link;
		
	}
	
	 
	
}

//˳�� ͷָ���λ�� O(n^2)
numNode *sourceNodes(numNode *head,int firstAddress){
	numNode *newHead,*newList,*oldHead,*newNode;
	
	oldHead = head;
	newList = newHead = createHead();
	
	head =head->link;
	while(head != NULL){
		
		
		newNode = findByAddress(oldHead,firstAddress);
		
		//���û���ҵ�  
		if(newNode == NULL){
				break; 
		}
		
		newHead->link = newNode;
		firstAddress = 	newHead->link->nextAddress;
		
		newHead = newHead->link;

		//printf("--Address:%d Data:%d nextAddress:%d ��ַ��%p\n",head->address,head->data,head->nextAddress,head->link);
		head = head->link;
		
	}
	
	
	
	
	return newList;
}


//num�Ƿ�ת�ĳ��� 
numNode *sloveNodes(numNode *head,int num){
	
	// stackTop��¼ÿ�Ĵζ�ջ��ָ�� 
	numNode *newHead,*stackTop,*lastCycleFisrtNode,*newLastNode;
	stackTop = createHead(); 
	//��¼��ջ��ջ�� 
	numNode *tempLast,*lastCycleLastNode;
	int isBottom=1;
	int interval = 0; 
	newHead = createHead();
	newHead->address;
	newLastNode = newHead;
	
	//����ͷ���հ�ָ��  ѭ������  ÿnum�δ���һ�ζ�ջ 
	head =head->link;
	
	while(head != NULL){
		interval++;
		
		//��ջ  ����ǿ�ջ ��¼ջ�� (�����һ��Ԫ��)
		if(isBottom == 1){
			//printf("ջ��\n"); 
			isBottom = 0;
			lastCycleLastNode = push(stackTop,head->address,head->data,head->nextAddress);
			 
		} else{
			push(stackTop,head->address,head->data,head->nextAddress);
		}
		
		//readNodes(stackTop);
		//1������������ 2��û�б�����ϣ����ҵ������һ������ ,���� 
		/*
							����   <<  <<  <<	<<	<<	^
							||             				^
							V             				^
						�� �� �� ��       				^
					  /            \      				^ 
					 ��             ��  				^
			���������һ�����ڣ�    ||				  	^
			                        V                  	^
								��һ����������         	^
							   /              \        	^ 
						      ��              �� ====>	^ 
						(��ջ����) ===================>	^ 
		*/ 
		if(head->link == NULL){ //�������� ����ջ���ǣ� 
			//readNodes(stackTop);
			if(interval >= num){
				newLastNode->link = stackTop->link ;
			}else{
				newLastNode->link = lastCycleFisrtNode ;
			}
		}else if(interval >= num){ //�������� ��ջ���� 
			interval = 0;
			
			newLastNode->link = stackTop->link ;
			//readNodes(newHead);
			stackTop->link = NULL;
			isBottom = 1;
		//	lastCycleLastNode = newLastNode->
			
			//�ƶ������һ�� 
			newLastNode = lastCycleLastNode;
			lastCycleFisrtNode = head->link;  
		} 
		
		head = head->link;
		
	}	
	
	//��ȡ���� nextAddress 
	sourcess(newHead);
	return newHead;
	
}
void mfree(numNode *head){
	
	numNode *newHead;
	while(head != NULL){
		newHead = head;
		head= head->link;
		free(newHead);
	}
	
}

int main(){
	
	//�������� ����ԭʼ�������ݵ�ָ��  oldHead ԭʼ���� head˳�򻯵� newHead������� 
	int oldFirstAddress, oldFirstData,oldFirstNum,readNum;
	int nowAddress, nowData,nowNextNum;
	numNode *oldHead,*head,*newHeads;
	oldHead =  createHead();
	
	//1-��ȡ����  
	scanf("%d %d %d",&oldFirstAddress,&oldFirstData,&oldFirstNum); 
	
	readNum = oldFirstData;
	
	while(readNum-- >0){
		scanf("%d %d %d",&nowAddress,&nowData,&nowNextNum); 
		pushLastNode(oldHead,nowAddress,nowData,nowNextNum); 
	} 
	
	//2-��������
	
	//2-1ԭʼ���� ˳��
	head = sourceNodes(oldHead,oldFirstAddress);
	mfree(oldHead);
	//2-2˳������  ��ת���� ������������ջ���� 
	newHeads = sloveNodes(head,oldFirstNum);
	//mfree(head);
		
	//3-��� 
	
	/*printf("ԭʼ����\n"); 
	readNodes(oldHead);
	 
	printf("���������\n"); 
	readNodes(head);
	printf("�������\n");*/ 
	readNodes_v2(newHeads);
	
	
	return 0; 
	
} 
