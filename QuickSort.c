#include <stdio.h>
#include <stdlib.h>
#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_
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
PNode Array2List(PNode head, SDataType* datas, int len); //数组转为单链表
#endif //LIST_H_
void QuickSort(PNode head); //快速排序

#endif //QUICK_SORT_H_

void ArrayQuickSort(SDataType* arr, int left, int right) //基于数组的快速排序
{

    int i, j;
    SDataType temp;

    if(left == right)
    {
        return;
    }

    i = left + 1;
    j = right;

    while(i < j)
    {
        while((i < j) && (arr[j].totalcount < arr[left].totalcount))
        {
            j--;
        }
        while((i < j) && (arr[i].totalcount >= arr[left].totalcount))
        {
            i++;
        }

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    if(arr[left].totalcount < arr[i].totalcount)
    {
        temp = arr[left];
        arr[left] = arr[i];
        arr[i] = temp;
    }

    ArrayQuickSort(arr, left, i - 1);
    ArrayQuickSort(arr, i, right);
    
}

void QuickSort(PNode head) //快速排序
{
    int len = 0;
    SDataType* arr = NULL;

    if(head == NULL)
    {
        printf("排序失败，链表为空!\n");
        return;
    }
    len = ListLength(head);
    arr = (SDataType*)malloc(sizeof(SDataType) * len);
    if(arr == NULL)
    {
        printf("申请内存失败!\n");
        return;
    }
    List2Array(head, arr);
    ArrayQuickSort(arr, 0, len - 1);
    head = Array2List(head, arr, len);
    free(arr);

    return;
}