#include <stdio.h>
#include"list.c"
#include"fileread.c"
#include"filewrite.c"
#include"BubbleSort.c"
#include"QuickSort.c"

void test_list() 
{
    SDataType data = {"Ryan", 0};
    PNode head = ListInit(data);

    SDataType data2 = {"Jack", 2};
    head = ListAddEnd(head, data2);

    SDataType data3 = {"Ryan", 0};
    head = ListMergeNode(head, data3);

    ListAllNode(head);
    ListDestory(head);

    return;
}

int main()
{
    PNode head = NULL;
    //test_list();
    //读取文件创建单链表
    head = read_file("user_login.txt", head);
    //ListAllNode(head);
    //将统计结果写入文件
    write_file("result.txt", head);

    //采用冒泡排序法排序
    //BubbleSort(head);

    //采用快速排序法排序
    QuickSort(head);

    //将排序结果写入文件
    write_file("sort.txt", head);

    //销毁单链表
    ListDestory(head);

    return 0;
}