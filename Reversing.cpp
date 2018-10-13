#include <stdio.h>
#include<stdlib.h>

//数据节点构成 
struct numNode{
	int address;
	int data;
	int nextAddress;
	numNode *link;
};

//判断是否是第一个头部空节点 
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

//追加一个元素 
void pushLastNode(numNode *head,int nowAddress,int nowData,int nowNum){
	
	numNode *lastNode,*newNode;
	
	//找到最后一个元素 
	lastNode = findLastNode(head);
	 
	//创建一个新节点元素 
	newNode = createNode(nowAddress,  nowData, nowNum);
	
	lastNode->link = newNode;
	
}

numNode *findByAddress(numNode *head,int address){

	while(head != NULL){
		if
		
		
	}
	
	return *head;
}

//顺序化 头指针的位置
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
	
	//声明变量 保存原始输入数据得指针 
	int oldFirstAddress, oldFirstData,oldFirstNum,readNum;
	int nowAddress, nowData,nowNextNum;
	numNode *oldHead,*head;
	oldHead =  createHead();
	head =  createHead();
	
	//1-读取输入  
	scanf("%d %d %d",&oldFirstAddress,&oldFirstData,&oldFirstNum); 
	
	readNum = oldFirstNum;
	
	while(readNum-- >0){
		scanf("%d %d %d",&nowAddress,&nowData,&nowNextNum); 
		pushLastNode(oldHead,nowAddress,nowData,nowNextNum); 
	} 
	
	//2-处理数据
	//2-1原始数据 顺序化
	
	
	
	
	//2-2顺序话数据  反转处理 
	
	
		
	//3-输出 
	printf("原始数据\n"); 
	readNodes(oldHead);
	printf("结果数据\n"); 
	
	
	return 0; 
	
} 
