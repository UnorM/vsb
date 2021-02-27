#include"head.h"
void ReadFromFile(){
	FILE *fp;
	fp=fopen("C:\vsb.user_login.txt",'r');
	if(fp=NULL){
		printf("文件不存在！");
		printf("请按回车键返回");
		getchar();
		getcahr();
		return ;
	}
PNode p;
char message[LENGTH<<1]	,name[LENGTH];
while(!feof(fp)){
	p=(PNode)malloc(LENGTH);
	fscanf(fp,"%s",message);
	int index=0;
	for(int i=0;i<strlen(message);i++){
		if(message[i]==',')
			break;
			name[index++]=message[i];	
	}
	name[index]='\0';
	strcpy(p->data.name,name);
	p->data.totalcount=1;
	InsertLinkEnd(p);
}
fclose(fp);
printf("读取成功！\n");
printf("请按回车继续！\n");
getchar();
}