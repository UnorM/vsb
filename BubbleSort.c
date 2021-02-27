#include <stdio.h>
#include <stdlib.h>
#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_
#ifndef LIST_H_
#define LIST_H_
#include "head.h"
PNode ListInit(SDataType data); //初始化单链表
PNode ListAddEnd(PNode head, SDataType data); //从尾部追加结点
PNode ListFindNode(PNode head, char *key); //查找结点
PNode ListInsertNode(PNode head, char *findkey, SDataType data); //从指定位置插入结点
PNode ListMergeNode(PNode head, SDataType data); //合并单链表结点，统计登录次数
int ListDeleteNode(PNode head, char* name); //删除指定结点
int ListLength(PNode head); //计算单链表长度
void ListAllNode(PNode head); //遍历所有结点
void ListDestory(PNode head); //销毁单链表
void List2Array(PNode head, SDataType* datas); //单链表转为数组
PNode Array2List(PNode head, SDataType* datas, int len); //数组转为单链

#endif //LIST_H_



void BubbleSort(PNode head); //冒泡排序

#endif //BUBBLE_SORT_H_

void BubbleSort(PNode head) //冒泡排序
{

    PNode htemp;
    SDataType temp;
    int i = 0, j = 0, len = 0;
    if(head == NULL)
    {

        printf("排序失败，链表为空!\n");
        return;

    }
    
    len = ListLength(head);
    for(i = 0; i < len - 1; i++)
    {

        htemp = head;
        for(j = len - 1; j > i; j--)

        {
            if(htemp->data.totalcount < htemp->PNext->data.totalcount)

            {

                temp = htemp->data;
                htemp->data = htemp->PNext->data;
                htemp->PNext->data = temp;

            }
            htemp = htemp->PNext;

        }
        
    }

} 