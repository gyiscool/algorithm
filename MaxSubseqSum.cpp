#include <stdio.h>
#define countof( array ) (sizeof( array )/sizeof( array[0] ))
int MaxSubseqSumq(int A[],int N);
int MaxSubseqSum1(int A[],int start,int end);
int MaxSubseqSumq2(int A[],int N); 
int main()
{
	char c;
	int d[5] = {22,-20,11,90,80};


	printf("��ǰ����:");
	int j = countof(d);

	for(int i = 0;i<j;i++){
		printf("%d��",d[i]);
	} 
	
	
	//������
	//int k = MaxSubseqSumq(d,j);
	//int k =MaxSubseqSum1(d,0,j-1);
	int k = MaxSubseqSumq2(d,j);
	
	printf("The char is %d -- %#x\n",k); //�����ӡ����ַ������ļ�ֵ
	 
	//�������� 
	/*for (;;) //����ѭ��
	{
		c=getchar(); // ��һ�ַ�
		//scanf("%d%s",d,c);
		if (c=='\n'){
			break; //���� ���м� ���� ѭ��
		}else{
			printf("The char is %d -- %#x\n",c); //�����ӡ����ַ������ļ�ֵ
			d = (int)c;
		}
	}
	*/
	
	return 0;
}

//���߲���
int MaxSubseqSumq2(int A[],int N){
	
	int i;
	int maxNum = 0; 
	int thisNum = 0; 
	
	//ѭ������ÿһ����ǰ���� �����һ��������������ֵ 
	for( i=0;i < N; i++){
		if(thisNum + A[i] <0 ) {
			thisNum = 0;
			continue;
		}
	
		
		thisNum += A[i];
		
		if(maxNum < thisNum) maxNum=thisNum; 

		
	}
	
	return maxNum;

} 
 

//���ַ�
int MaxSubseqSum1(int A[],int start,int end){
	
	int midNum = (start+end)/2; 
	int maxSum =0;
	int thisSum = 0;
	
	//�����ǰ���� 
	if((end-start)<=0)
		return A[start];
		
	//�м���� 
	
	//���һ�� �ұ�һ�� 
	int leftSum =  MaxSubseqSum1(A,start,midNum); 
	int rightSum =  MaxSubseqSum1(A,midNum+1,end); 
	
	maxSum = leftSum; 
	if(leftSum < rightSum) maxSum = rightSum; 
	 
	
	//ѭ������ ��ȡ��Խ�߽����ֵ
//	thisSum = A[midNum];
	for(int i=0;i<(end-midNum+1);i++){
		
		if(midNum-i >=start ) thisSum += A[midNum-i];
		
		if(thisSum > maxSum) maxSum=thisSum;
		
		if( (midNum+1+i) <=end ) thisSum += A[midNum+1+i];
		
		if(thisSum > maxSum) maxSum=thisSum;	

	}	

	return maxSum;
	
} 


//ɯɯѭ�� 
int MaxSubseqSumq(int A[],int N){
	
	int i,j,k;
	int maxNum = 0; 
	int thisNum = 0; 
	
	//ѭ������ÿһ����ǰ���� �����һ��������������ֵ 
	for( i=0;i < N; i++){
		thisNum = 0;// ÿһ��ѭ������������ ��ǰ��
		
		//ѭ������ֵ 
		for( j=i;j < N; j++){
		//	printf("%d��",A[j]);
			thisNum +=A[j]; 
			if(thisNum > maxNum) 
				maxNum = thisNum;
			
		}
		
	}
	
	return maxNum;

} 



























