#include <stdio.h>
#include <stdlib.h>
#include "QuickSort.h"

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
    }
    len = ListLength(head);
    arr = (SDataType*)malloc(sizeof(SDataType) * len);
    if(arr == NULL)
    {
        printf("申请内存失败!\n");
    }
    List2Array(head, arr);
    ArrayQuickSort(arr, 0, len - 1);
    head = Array2List(head, arr, len);
    free(arr);
}

