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

#endif //LIST_H_