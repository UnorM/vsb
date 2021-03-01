#include <stdio.h>
#include <stdlib.h>
#include "HeapSort.h"

void ArrayHeapSort(SDataType* arr, int len) //基于数组的堆排序
{
    int i, j, k;
    SDataType temp;

    for(i = len/2 - 1; i >= 0; i--) //将arr[0,len-1]建成大根堆
    {
        while(2 * i + 1 < len) //第i个结点有右子树
        {
            j = 2 * i + 1;
            if((j + 1) < len)
            {
                if(arr[j].totalcount > arr[j+1].totalcount) //左子树小于右子树，则需要比较右子树
                {
                    j++;    //序号增加1，指向右子树
                }
            }
            if(arr[i].totalcount > arr[j].totalcount) //比较i与j为序号的数据
            {
                temp = arr[i]; //交换数据
                arr[i] = arr[j];
                arr[j] = temp;
                i = j;         //堆被破坏，需要重新调整
            } else {    //比较左右子树结点均大则堆未破坏，不再需要调整
                break;
            }
        }
    }

    for(i = len - 1; i > 0; i--)
    {
        temp = arr[0];  //与i个记录交换
        arr[0] = arr[i];
        arr[i] = temp;
        k = 0;
        while(2 * k + 1 < i)    //第i个结点有右子树
        {
            j = 2 * k + 1;
            if((j + 1) < i)
            {
                if(arr[j].totalcount > arr[j+1].totalcount) //左子树小于右子树，则需要比较右子树
                {
                    j++;    //序号增加1，指向右子树
                }
            }
            if(arr[k].totalcount > arr[j].totalcount) //比较i与j为序号的数据
            {
                temp = arr[k];  //交换数据
                arr[k] = arr[j];
                arr[j] = temp;
                k = j;  //堆被破坏，需要重新调整
            } else {    //比较左右子结点均大则堆未破坏，不需要调整
                break;
            }
        }
    }
}

void HeapSort(PNode head) //堆排序
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
    ArrayHeapSort(arr, len);
    head = Array2List(head, arr, len);
    free(arr);

    return;
}