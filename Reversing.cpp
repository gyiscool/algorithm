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
	
	while(head != NULL){
		
		printf("Address:%d Data:%d nextAddress:%d \n",head->address,head->data,head->nextAddress);
		head = head->link;
	}
	
}



numNode *createNode(int address, int data,int num){
	numNode *nowNode;
	
	nowNode = (numNode *) malloc(sizeof(struct numNode));
	
	nowNode->address = address;
	nowNode->data = data;
	nowNode->nextAddress = num;
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

numNode *findByAddress(numNode *head,int address){

	while(head != NULL){
		if
		
		
	}
	
	return *head;
}

//˳�� ͷָ���λ��
numNode *sourceNodes(numNode *head,int firstAddress){
	numNode *newHead,*newList,*oldHead;
	
	oldHead = head;
	newHead = createHead();
	newList = newHead;
	
	while(head != NULL){
		//O(n^2)
		newHead->link = findByAddress(oldHead,firstAddress);
		newHead = newHead->link;
		head = head->link;
		
		firstAddress =
		
	}
	
	return *newList;
}

int main(){
	
	//�������� ����ԭʼ�������ݵ�ָ�� 
	int oldFirstAddress, oldFirstData,oldFirstNum,readNum;
	int nowAddress, nowData,nowNextNum;
	numNode *oldHead,*head;
	oldHead =  createHead();
	head =  createHead();
	
	//1-��ȡ����  
	scanf("%d %d %d",&oldFirstAddress,&oldFirstData,&oldFirstNum); 
	
	readNum = oldFirstNum;
	
	while(readNum-- >0){
		scanf("%d %d %d",&nowAddress,&nowData,&nowNextNum); 
		pushLastNode(oldHead,nowAddress,nowData,nowNextNum); 
	} 
	
	//2-��������
	//2-1ԭʼ���� ˳��
	
	
	
	
	//2-2˳������  ��ת���� 
	
	
		
	//3-��� 
	printf("ԭʼ����\n"); 
	readNodes(oldHead);
	printf("�������\n"); 
	
	
	return 0; 
	
} 
