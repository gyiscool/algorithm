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

//补足零 
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

//追加一个元素 
void pushLastNode(numNode *head,int nowAddress,int nowData,int nowNum){
	
	numNode *lastNode,*newNode;
	
	//找到最后一个元素 
	lastNode = findLastNode(head);
	 
	//创建一个新节点元素 
	newNode = createNode(nowAddress,  nowData, nowNum);
	
	lastNode->link = newNode;
	
}

//Push 入栈 返回 入栈元素的指针  并且修改上一个地址数值 
numNode *push(numNode *stack,int nowAddress,int nowData,int nowNum){
	
	//临时变量存放头指针  stack可能是空  
	numNode *temp,*newNode;
	
	temp = stack;
	 
	//指向新节点
	newNode = createNode(nowAddress,  nowData, nowNum);
	
	newNode->link = stack->link;
	
/*	if(stack->link != NULL){
		newNode->nextAddress = stack->link->nextAddress; 
	}
	*/
	stack->link= newNode;
	//新节点放在 TOP 
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
		
		//如果是第一个 过滤 
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

//顺序化 头指针的位置 O(n^2)
numNode *sourceNodes(numNode *head,int firstAddress){
	numNode *newHead,*newList,*oldHead,*newNode;
	
	oldHead = head;
	newList = newHead = createHead();
	
	head =head->link;
	while(head != NULL){
		
		
		newNode = findByAddress(oldHead,firstAddress);
		
		//如果没有找到  
		if(newNode == NULL){
				break; 
		}
		
		newHead->link = newNode;
		firstAddress = 	newHead->link->nextAddress;
		
		newHead = newHead->link;

		//printf("--Address:%d Data:%d nextAddress:%d 地址：%p\n",head->address,head->data,head->nextAddress,head->link);
		head = head->link;
		
	}
	
	
	
	
	return newList;
}


//num是反转的除数 
numNode *sloveNodes(numNode *head,int num){
	
	// stackTop记录每四次堆栈的指针 
	numNode *newHead,*stackTop,*lastCycleFisrtNode,*newLastNode;
	stackTop = createHead(); 
	//记录堆栈的栈底 
	numNode *tempLast,*lastCycleLastNode;
	int isBottom=1;
	int interval = 0; 
	newHead = createHead();
	newHead->address;
	newLastNode = newHead;
	
	//过滤头部空白指针  循环链表  每num次处理一次堆栈 
	head =head->link;
	
	while(head != NULL){
		interval++;
		
		//入栈  如果是空栈 记录栈底 (是最后一个元素)
		if(isBottom == 1){
			//printf("栈底\n"); 
			isBottom = 0;
			lastCycleLastNode = push(stackTop,head->address,head->data,head->nextAddress);
			 
		} else{
			push(stackTop,head->address,head->data,head->nextAddress);
		}
		
		//readNodes(stackTop);
		//1、链表遍历完毕 2、没有遍历完毕，并且到了最后一个数字 ,重置 
		/*
							遍历   <<  <<  <<	<<	<<	^
							||             				^
							V             				^
						遍 历 完 毕       				^
					  /            \      				^ 
					 是             否  				^
			（处理最后一个周期）    ||				  	^
			                        V                  	^
								是一个完整周期         	^
							   /              \        	^ 
						      是              否 ====>	^ 
						(堆栈处理) ===================>	^ 
		*/ 
		if(head->link == NULL){ //遍历结束 （出栈还是） 
			//readNodes(stackTop);
			if(interval >= num){
				newLastNode->link = stackTop->link ;
			}else{
				newLastNode->link = lastCycleFisrtNode ;
			}
		}else if(interval >= num){ //完整周期 堆栈处理 
			interval = 0;
			
			newLastNode->link = stackTop->link ;
			//readNodes(newHead);
			stackTop->link = NULL;
			isBottom = 1;
		//	lastCycleLastNode = newLastNode->
			
			//移动到最后一个 
			newLastNode = lastCycleLastNode;
			lastCycleFisrtNode = head->link;  
		} 
		
		head = head->link;
		
	}	
	
	//读取更正 nextAddress 
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
	
	//声明变量 保存原始输入数据得指针  oldHead 原始输入 head顺序化的 newHead结果链表 
	int oldFirstAddress, oldFirstData,oldFirstNum,readNum;
	int nowAddress, nowData,nowNextNum;
	numNode *oldHead,*head,*newHeads;
	oldHead =  createHead();
	
	//1-读取输入  
	scanf("%d %d %d",&oldFirstAddress,&oldFirstData,&oldFirstNum); 
	
	readNum = oldFirstData;
	
	while(readNum-- >0){
		scanf("%d %d %d",&nowAddress,&nowData,&nowNextNum); 
		pushLastNode(oldHead,nowAddress,nowData,nowNextNum); 
	} 
	
	//2-处理数据
	
	//2-1原始数据 顺序化
	head = sourceNodes(oldHead,oldFirstAddress);
	mfree(oldHead);
	//2-2顺序化数据  反转处理 利用链表做堆栈处理 
	newHeads = sloveNodes(head,oldFirstNum);
	//mfree(head);
		
	//3-输出 
	
	/*printf("原始数据\n"); 
	readNodes(oldHead);
	 
	printf("整理后数据\n"); 
	readNodes(head);
	printf("结果数据\n");*/ 
	readNodes_v2(newHeads);
	
	
	return 0; 
	
} 
