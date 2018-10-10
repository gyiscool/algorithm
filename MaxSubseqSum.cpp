#include <stdio.h>
#define countof( array ) (sizeof( array )/sizeof( array[0] ))
int MaxSubseqSumq(int A[],int N);
int MaxSubseqSum1(int A[],int start,int end);
int MaxSubseqSumq2(int A[],int N); 
int main()
{
	char c;
	int d[5] = {22,-20,11,90,80};


	printf("当前序列:");
	int j = countof(d);

	for(int i = 0;i<j;i++){
		printf("%d、",d[i]);
	} 
	
	
	//排序功能
	//int k = MaxSubseqSumq(d,j);
	//int k =MaxSubseqSum1(d,0,j-1);
	int k = MaxSubseqSumq2(d,j);
	
	printf("The char is %d -- %#x\n",k); //否则打印这个字符和它的键值
	 
	//接受输入 
	/*for (;;) //无限循环
	{
		c=getchar(); // 读一字符
		//scanf("%d%s",d,c);
		if (c=='\n'){
			break; //若是 新行键 跳出 循环
		}else{
			printf("The char is %d -- %#x\n",c); //否则打印这个字符和它的键值
			d = (int)c;
		}
	}
	*/
	
	return 0;
}

//在线查找
int MaxSubseqSumq2(int A[],int N){
	
	int i;
	int maxNum = 0; 
	int thisNum = 0; 
	
	//循环计算每一个当前数字 到最后一数字连续的子列值 
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
 

//二分法
int MaxSubseqSum1(int A[],int start,int end){
	
	int midNum = (start+end)/2; 
	int maxSum =0;
	int thisSum = 0;
	
	//输出当前数字 
	if((end-start)<=0)
		return A[start];
		
	//中间参数 
	
	//左边一半 右边一半 
	int leftSum =  MaxSubseqSum1(A,start,midNum); 
	int rightSum =  MaxSubseqSum1(A,midNum+1,end); 
	
	maxSum = leftSum; 
	if(leftSum < rightSum) maxSum = rightSum; 
	 
	
	//循环遍历 获取跨越边界最大值
//	thisSum = A[midNum];
	for(int i=0;i<(end-midNum+1);i++){
		
		if(midNum-i >=start ) thisSum += A[midNum-i];
		
		if(thisSum > maxSum) maxSum=thisSum;
		
		if( (midNum+1+i) <=end ) thisSum += A[midNum+1+i];
		
		if(thisSum > maxSum) maxSum=thisSum;	

	}	

	return maxSum;
	
} 


//莎莎循环 
int MaxSubseqSumq(int A[],int N){
	
	int i,j,k;
	int maxNum = 0; 
	int thisNum = 0; 
	
	//循环计算每一个当前数字 到最后一数字连续的子列值 
	for( i=0;i < N; i++){
		thisNum = 0;// 每一次循环重新设置零 当前和
		
		//循环子列值 
		for( j=i;j < N; j++){
		//	printf("%d、",A[j]);
			thisNum +=A[j]; 
			if(thisNum > maxNum) 
				maxNum = thisNum;
			
		}
		
	}
	
	return maxNum;

} 



























