#include <stdio.h> 
#include <stdlib.h> 
#include <queue> 
#include <stack> 
#include <string.h>
#include <set>
#include <string>
#define countof( array ) (sizeof( array )/sizeof( array[0] ))

using namespace std;

string *readA(int num1){
	
	static string res[10];
	int resIndex = 0;
	
	char tree1[18] = {0}; 
	char tree2[15] = {0}; 
	//string ss[10] = {0};
	
	int num2,index1=0,index2=0;
	
	int leftInt,rightInt;
	char lefts[2] = {0}; 
	char rights[2] = {0}; 
	
	char isBreak[2] = {"-"}; 
	
	queue<int> pre;
	queue<int> next;
	queue<string> preStr;
	queue<string> nextStr;
	int isPre=1;


	
	pre.push(0);
	printf(tree1);
	string temps,templ,temp;
	for(int i =0;i <num1;i++){
		//printf("\n ���֣�%d��",i);
		if(isPre == 1){ //��ǰ������pre���� �������next 
		
			index1 = pre.front();
			pre.pop(); 
			
			//����·��
			if(index1 ==0){
				temp = templ = temps = "";
			}else{
				temp = templ =temps = preStr.front();
				preStr.pop();
			}
			
			if(i>=num1-1){
				scanf("%c %s %s", &tree1[index1],&lefts,&rights);
			}else{
				scanf("%c %s %s ", &tree1[index1],&lefts,&rights);
			}
			
		//	printf("�����"); printf(tree1);
			//printf("���������");
			if(strcmp(lefts,isBreak)){ //������� 
				
				//sscanf(lefts,"%d",leftInt);//���ַ���ת����
				leftInt = atoi( lefts );
		
				next.push(leftInt);
				
				templ += tree1[index1];
				//printf("-·��-: -%s \n ",templ.c_str());
				nextStr.push(templ);
			}
			
			if(strcmp(rights,isBreak)){ //���Ҷ��� 
				rightInt = atoi( rights );
				//sscanf(rights,"%d",rightInt);//���ַ���ת����
				next.push(rightInt);
				temps += tree1[index1];
				nextStr.push(temps);
			}
			
			//�����Ϊ�� ���
			if( !strcmp(rights,isBreak) && !strcmp(lefts,isBreak)){
				res[resIndex++] = temp+tree1[index1];
				//printf("·��: -%s ",temp.c_str());
				//printf("Ҷ��: -%s \n",&tree1[index1]);
				
			}
			
			if(pre.empty()) isPre=0;

		}else{
			index1 = next.front();
			next.pop(); 
			
			//����·��
			if(index1 ==0){
				temp=templ = temps = "";
			}else{
				temp=templ = temps = nextStr.front();
				nextStr.pop();
			}
			
			
			if(i>=num1-1){
				scanf("%c %s %s", &tree1[index1],&lefts,&rights);
			}else{
				scanf("%c %s %s ", &tree1[index1],&lefts,&rights);
			}
		
			
			if(strcmp(lefts,isBreak)){
			//	sscanf(lefts,"%d",leftInt);//���ַ���ת����
				leftInt = atoi( lefts );
				pre.push(leftInt);
				templ += tree1[index1];
				preStr.push(templ);
				
			}
			
			if(strcmp(rights,isBreak)){
				//sscanf(rights,"%d",rightInt);//���ַ���ת����
				rightInt = atoi( rights );
				pre.push(rightInt);
				temps += tree1[index1];
				preStr.push(temps);
			}
			
			if( !strcmp(rights,isBreak) && !strcmp(lefts,isBreak)){
				res[resIndex++] = temp+tree1[index1];
				//printf("·��: -%s ",temp.c_str());
				//printf("Ҷ��: -%s \n",&tree1[index1]);
			}
			
			if(next.empty()) isPre=1;
		
		}
		/* 
		if(pre.empty()){
			
		}
		
		pre.push();*/ 
	}
	


	
	return res;
	
}

/**
����ͬ���������� �� ���ڵ㵽Ҷ�ӽڵ��Ƿ�����ͬ��·�� �ַ����鱣�� 
*/
int main(){

	set<int>s1;
	set<int>s2;
	int num1, num2;
	scanf("%d ",&num1); 
	//string res[10];
	string *res = readA(num1);
	
	//printf("\n���鳤�ȣ�%s\n",res[0].c_str());
	//printf("\n���鳤�ȣ�%d\n",res->length());
	
	scanf("%d ",&num2); 
	
	if(num1 != num2){
		printf("No");
		return 0;
	}
	.
	return 0; 
	*/
}
