#include <stdio.h> 
#include<iostream>
#include <stdlib.h> 

void display(int *arr, int irows, int icols)
{
     for(int i=0;i<irows;++i)
     {
         for(int j=0;j<icols;++j)
         {
             std::cout<<*(arr+i*icols+j)<<" ";   //ע��:(arr+i*icols+j),����(arr+i*irows+j)
         }
         std::cout << std::endl;
     }
     std::cout<<std::endl;
}

//�ж�ÿ���Ƿ��� 
void isOk(int param[],int length,int size){
	
	int stack[size];
	int n,guard = 0,top = -1,isOk =1 ;
	int line[size];
	n = size;
	
	//����
	for(int j =0 ;j < size;j++){
		line[j] = j+1;
	} 
	
	
	//��������б� 
	for (int i = 0; i < length - 1; i++){
		isOk=1;
		
		//1��������ȷ����Ԫ�� ��1��������ջ�����ǵ�һ��  �� 
		if( stack[top] == param[i] ){ //��ջ�ڵ�һ�� 
			//���� 
			top--;
			
		} else if(param[i]-1-guard >=0 && top + 1 + (param[i]-guard) <= 5){ // ������ջ 
			int s= 	param[i] -1-guard;
			for (int k = 0; k <= s; k++){
				top++;//�ƶ� 
				stack[top] = line[guard] ;
				guard++;
			}
			
			top--; 
			guard =  param[i]; //ָ�򵯳�����һ��Ԫ�� 
			
		} else{
			isOk=0;
			break;
		}
		
	//	printf("��� %d  ",i);
	//	std::cout << param[i] << "\t"<<std::endl;
	}
	if(isOk ==1){
		printf("YES\n"); 
	}else{
		printf("NO\n"); 
	}
	

} 



int main(){
	
	int size,N,lineNum,rowNum,eleNums,ele,rowNums;
	
	//������Ϣ��ȡ 
	scanf("%d %d %d",&size,&N,&lineNum);	
	
	if(size >1000){
		size = 1000;
	}
	
	if(N >1000){
		N = 1000;
	}
	
	if(lineNum >1000){
		lineNum = 1000;
	}
	
	int stack[size],pushLine[lineNum][N];
	
	rowNums = rowNum = lineNum;
	eleNums = N;
	
	
	//��ȡϸ������ 
	while(rowNum > 0){
		
		while(eleNums > 0){
			scanf("%d",&pushLine[lineNum-rowNum][N-eleNums]);
			//printf("���� %d��%d \n",lineNum-rowNum,N-eleNums);
			eleNums--;
		}

		eleNums = N;
		rowNum--;
		
	}
	
	/*
	---------------start���� ���� 
	
	lineNum=5;
	N = 7;
	size=5;
	//int stack[5],pushLine[5][7];
	int stack[size];
	//int pushLine[5][7] = {{1,2,3,4,5,6,7},{3,2,1,7,5,6,4},{7,6,5,4,3,2,1},{5,6,4,3,7,2,1},{1,7,6,5,4,3,2}}; 
	int pushLine[5][7] = {{3,1,2,4,5,},{1,3,2,5,4},{5,4,3,2,1},{5,4,3,2,1},{1,4,2,3,5}}; 
	rowNums = lineNum;
	eleNums = N;
	//printf("��ͣ %d��%d \n",lineNum,N);
	
	
	---------------end���� 
	*/
	
	//��������ά 
	//display((int *)pushLine,lineNum,N);
	
	
	//����ÿ���Ƿ��� 
	while(rowNums >0){
		isOk(pushLine[lineNum-rowNums],N,size);
		rowNums--;
	}
	
	return 0;
}
