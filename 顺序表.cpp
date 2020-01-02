#include<stdio.h>
#include<string.h> 
#define maxn 100 
typedef struct{
	char key[10];
	char name[20];
	int age;
}DATA;
typedef struct{
	DATA ListData[maxn+1];
	int ListLen;
}SLType;
//��ʼ��SLType
void SLInit(SLType *SL)
{
	SL->ListLen=0;
 } 
 //����˳�����
 int SLLength(SLType *SL)
 {
 return SL->ListLen;
}
//������
int SLInsert(SLType *SL,int n,DATA data)
{
	int i;
	if(SL->ListLen>=maxn)
	{
		printf("˳������������ܲ����㣡\n");
		return 0;
	}
	if(n<1||n>=SL->ListLen-1)
	{
		printf("����Ԫ����Ŵ��󣬲��ܲ���Ԫ��!\n");
		return 0;
	}
	for(i=SL->ListLen;i>=n;i--)
	{
		SL->ListData[i+1]=SL->ListData[i];
	}
	SL->ListData[n]=data;
	SL->ListLen++;
	return 1;
 } 
 //׷�ӽ��
 int SLAdd(SLType *SL,DATA data)
 {
 	if(SL->ListLen>=maxn)
	{
		printf("˳������������ܲ����㣡\n");
		return 0;
	}
	SL->ListData[++SL->ListLen]=data;
	return 1;
  } 
  //ɾ�����
  int SLDelete(SLType *SL,int n,DATA data)
  {
  		if(n<1||n>=SL->ListLen-1)
	{
		printf("ɾ��Ԫ����Ŵ��󣬲��ܲ���Ԫ��!\n");
		return 0;
	}
	for(int i=SL->ListLen;i<=n;i++)
	{
		SL->ListData[i]=SL->ListData[i+1];
	}
	SL->ListLen--;
	return 1;
   }
   //����
   //1 ������Ų��� 
DATA *SLFindNum(SLType *SL,int n)
 {
 		if(n<1||n>=SL->ListLen+1)
	{
		printf("�����Ŵ��󣬲��ܷ��ؽ��!\n");
		return NULL;
	}
	return &(SL->ListData[n]);
 }
 //2���չؼ��ֲ��ҽ��
 int SLFindByCont(SLType *SL,char *key)
 {
 	int i;
 	for(int i=1;i<=SL->ListLen;i++)
 	{
 		if(strcmp(SL->ListData[i].key,key)==0)
		 {
		 	return i;
		  } 
	 }
	 return 0;
  } 
  //��ʾ���Խ��
  int SLAll(SLType *SL)
  {
  	int i;
  	for(i=1;i<=SL->ListLen;i++)
  	{
  		printf("%s %s %d",SL->ListData[i].key, SL->ListData[i].name, SL->ListData[i].age);
	  }
   } 
   int main()
   {
   	int i;
   	SLType SL;
   	DATA data;
   	DATA *pdata;
   	char key[10];
   	printf("˳��������ʾ\n");
   	SLInit(&SL);
   	printf("��ʼ��˳������\n");
   	do{
   		printf("������ӵĽ��<ѧ�ţ�����������>:");
   		fflush(stdin);
   		scanf("%s%s%d",&data.key,&data.name,&data.age);
   		if(data.age)
   		{
   			if(!SLAdd(&SL,data))
   			{
   				break;
			   }
		   }
		   else{
		   	break;
		   }
	   }while(1);
	   printf("\n˳����еĽ��˳��Ϊ\n");
	   SLAll(&SL);
	   
	   fflush(stdin);
	   printf("\nҪȡ���������: \n");
	   scanf("%d",&i);
	   pdata=SLFindNum(&SL,i);
	   if(pdata)
	   {
	   	printf("��%d�����Ϊ%s,%s,%d\n",i,pdata->key,pdata->name,pdata->age);
	   }
	   fflush(stdin);
	   printf("\nҪ���ҽ��Ĺؼ���:\n");
	   scanf("%s",key);
	   i=SLFindByCont(&SL,key);
	   pdata=SLFindNum(&SL,i);
	   if(pdata)
	   {
	   	printf("��%d�����Ϊ %s,%s,%d\n",i, pdata->key, pdata->name,pdata->age);
	   }
	   
	   return 0;
   	
   }
  
