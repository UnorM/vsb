#include <stdio.h>
#include <stdlib.h>
#include "BubbleSort.c"

void BubbleSort(PNode head) //冒泡排序
{
    PNode htemp;
    SDataType temp;
    int i = 0, j = 0, len = 0;
    if(head == NULL)
    {
        printf("排序失败，链表为空!\n");
    }
    
    len = ListLength(head);
    for(i = 0; i < len - 1; i++)
    {
        htemp = head;
        for(j = len - 1; j > i; j--)
        {
            if(htemp->_data.totalcount < htemp->_PNext->_data.totalcount)
            {
                temp = htemp->_data;
                htemp->_data = htemp->_PNext->_data;
                htemp->_PNext->_data = temp;
            }
            htemp = htemp->_PNext;
        }
    }
}