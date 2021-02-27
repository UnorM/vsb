#include"head.h"
#include <stdlib.h>
#include <string.h>
PNode ListInit(SDataType data) //初始化单链表
{
    PNode head = (PNode)malloc(sizeof(Node));
    if (head == NULL)
    {
        printf("申请内存失败!\n");
        return NULL;
    }
    head->data = data;
    head->PNext = NULL;

    return head;
}

PNode ListAddEnd(PNode head, SDataType data) //从尾部追加结点
{
    PNode node, htemp;
    if(!(node = (PNode)malloc(sizeof(Node))))
    {
        printf("申请内存失败!\n");
        return head;
    }
    node->data = data;
    node->PNext = NULL;
    if (head == NULL)
    {
        head = node;
        return head;
    }
    htemp = head;
    while(htemp->PNext != NULL)
    {
        htemp = htemp->PNext;
    }
    htemp->PNext = node;
    return head;
}

int ListDeleteNode(PNode head, char* name) //删除指定结点
{
    PNode node, htemp;
    htemp = head;
    node = head;
    while(htemp)
    {
        if(strcmp(htemp->data.name, name) == 0)
        {
            node->PNext = htemp->PNext;
            free(htemp);
            return 1;
        } else {
            node = htemp;
            htemp = htemp->PNext;
        }
    }
    return 0;
}

int ListLength(PNode head) //计算单链表长度
{
    PNode htemp;
    int len = 0;
    htemp = head;
    while(htemp)
    {
        len++;
        htemp = htemp->PNext;
    }
    return len;
}

void ListAllNode(PNode head) //遍历所有结点
{
    PNode htemp;
    if(head == NULL)
    {
        printf("链表为空!\n");
        return;
    }
    htemp = head;
    printf("当前链表共有%d个结点。链表所有数据如下：\n", ListLength(head));
    while(htemp)
    {
        printf("%s, %d\n", htemp->data.name, htemp->data.totalcount);
        htemp = htemp->PNext;
    }
}