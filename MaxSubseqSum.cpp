#include <stdio.h>
#include<stdlib.h>
#define countof( array ) (sizeof( array )/sizeof( array[0] ))



struct Node{
	int sumNum; 
	int firstNum; 
	int endNum;
}  ;

Node *MaxSubseqSumq2(int A[],int N); 

int main()
{
	int c;
	
	int N ,j ;
	
	scanf("%d",&N);
	
	j = N;
	
	int d[N];
	
	while(N-- > 0){
		scanf("%d",&c);
		d[j-N-1] = c;
	}
	
	Node *k;

	k = MaxSubseqSumq2(d,j);
	
	printf("%d ",k->sumNum);
	printf("%d ",k->firstNum);
	printf("%d",k->endNum);
	
	return 0;
}

//在线查找
Node *MaxSubseqSumq2(int A[],int N){
	
	Node *node;
	int i;
	int endNumbyIndex;
	int maxNum = 0; 
	int thisNum = 0;
	 
	node = ( Node * ) malloc(sizeof(struct Node));
	node->sumNum = 0;
	node->firstNum = 0;
	node->endNum = 0;

	//循环计算每一个当前数字 到最后一数字连续的子列值 
	for( i=0;i < N; i++){
		
		if(thisNum + A[i] <0 ) {
			thisNum = 0; 
			continue;
		}
		
		//没有缩小 
		thisNum += A[i];
		
		//更新 
		if(maxNum < thisNum) {
			endNumbyIndex = i;
			maxNum=thisNum;
		}
		 

	}
	
	node->sumNum = maxNum;
	node->endNum = A[endNumbyIndex];
	
	if(maxNum <=0) {
		int b = 0;
		for( i=0;i < N; i++){
		
			if(A[i] >=0 )  b =1;
		}
	
		node->firstNum = A[0];
		node->endNum = A[N-1];
		printf("");
		if(b != 1){

			return node;
		}else{
			node->firstNum = 0;
			node->endNum = 0 ;
			return node;
		}
		
		
	}
	
	for(int j =0;j<=endNumbyIndex; j++){
		maxNum =  maxNum-A[endNumbyIndex-j];
		
		if(maxNum <= 0){
			node->firstNum = A[endNumbyIndex-j];
			break;
	}
		

	
	} 
	

	
	
	return node;

} 
 

