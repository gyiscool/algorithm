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

//���߲���
Node *MaxSubseqSumq2(int A[],int N){
	
	Node *node;
	int i;
	int endNumbyIndex = 0;
	int maxNum = 0; 
	int thisNum = 0;
	int b = 0;
	 
	node = ( Node * ) malloc(sizeof(struct Node));
	node->sumNum = 0;
	node->firstNum = 0;
	node->endNum = 0;

	//ѭ������ÿһ����ǰ���� �����һ��������������ֵ 
	for( i=0;i < N; i++){
		
		if(thisNum + A[i] <0 ) {
			thisNum = 0; 
			continue;
		}
		
		//û����С 
		thisNum += A[i];
		
		//���� 
		if(maxNum < thisNum) {
			endNumbyIndex = i;
			maxNum=thisNum;
		}
		 

	}
	
	node->sumNum = maxNum;
	node->endNum = A[endNumbyIndex];
	
	//�������ֵ�����㣬ȥ�ж��Ƿ�ȫ��Ϊ0 
	if(maxNum <=0) {
		
		for( i=0;i < N; i++){
			//�����ڱ�����ȫ�� 
			if(A[i] >=0 ) { b =1;}
		}
	
		node->firstNum = A[0];
		node->endNum = A[N-1];

		if(b != 1){  // ȫ�Ǹ��� 
		
			return node;
		}else{ //���ڷǸ��� 
			node->firstNum = 0;
			node->endNum = 0 ;
			
			return node;
		}
			
	}
	
	node->firstNum = A[endNumbyIndex];
	int c=0;
	for(int j =0;j<=endNumbyIndex; j++){
		maxNum =  maxNum-A[endNumbyIndex-j];
		

		if(maxNum < 0){
			
			break;
		}else if(maxNum == 0){
			
			c=1; 
			node->firstNum = A[endNumbyIndex-j];
		}else if(c == 1 && maxNum >0){
			
	
			
		}
		 
	
	} 
	
	return node;

} 
 

