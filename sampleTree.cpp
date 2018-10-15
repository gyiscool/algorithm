#include <stdio.h> 
#include <stdlib.h> 
#include <queue> 
#include <stack> 
#include <string.h>
using namespace std;
/**
树的同构，两条树 的 根节点到叶子节点是否有相同的路径 字符数组保存 
*/
int main(){
	char oldRoutes[10][10] = {0};
	char newRoutes[10][10] = {0};
	
	char tree1[15] = {"1234567891234"}; 
	char tree2[15] = {0}; 
	
	int num1,num2,index1=0,index2=0;
	
	int leftInt,rightInt;
	char lefts[2] = {0}; 
	char rights[2] = {0}; 
	
	char isBreak[2] = {"-"}; 
	
	queue<int> pre;
	queue<int> next;
	int isPre=1;
	
	//读取 数据 
	scanf("%d ",&num1); 
//	printf("%d、",num1);
	
	leftInt = atoi( "123123" );
   

	
	pre.push(0);
	printf(tree1);
	for(int i =0;i <num1;i++){
		
		if(isPre == 1){ //当前出队是pre队列 ，入队是next 
			index1 = pre.front();
			pre.pop(); 
			scanf("%c %s %s ", &tree1[index1],&lefts,&rights);
			printf(tree1);

			if(strcmp(lefts,isBreak)){
				
				//sscanf(lefts,"%d",leftInt);//将字符串转整数
				leftInt = atoi( lefts );
		
				next.push(leftInt);
			}
			
			if(strcmp(rights,isBreak)){
				rightInt = atoi( rights );
				//sscanf(rights,"%d",rightInt);//将字符串转整数
				next.push(rightInt);
			}
			
			if(pre.empty()) isPre=0;

		}else{
			index1 = next.front();
			next.pop(); 
			scanf("%c %s %s ", &tree1[index1],&lefts,&rights);
			
			if(strcmp(lefts,isBreak)){
			//	sscanf(lefts,"%d",leftInt);//将字符串转整数
				leftInt = atoi( lefts );
				pre.push(leftInt);
			}
			
			if(strcmp(rights,isBreak)){
				//sscanf(rights,"%d",rightInt);//将字符串转整数
				rightInt = atoi( rights );
				pre.push(rightInt);
			}
			
			if(next.empty()) isPre=1;
		
		}
		/* 
		if(pre.empty()){
			
		}
		
		pre.push();*/ 
	}
	printf(tree1);
	for(int i=0;i<15;i++)
{
printf("\n -%c \n",&tree1[i]);
}
	
	
	return 0;
}
