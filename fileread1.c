#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_name(const char *line, char* name) //从每行信息中截取名字
{
    int i = 0;
    memset(name, 0, 30);
    for(i = 0; line[i] != '\0'; i++)
    {
        if(line[i] == ',')
        {
            name[i] = '\0';
            break;
        }
        name[i] = line[i];
        
    }
}

PNode read_file(const char *filename, PNode head) //从文件中读取数据并建立出链表
{
    FILE* fin = NULL;
    char line[100] = {0};
    char name[30] = {0};
    SDataType data;

    fin = fopen(filename, "rt");
    if(fin == NULL)
    {
        printf("%s 文件打开失败!\n", filename);
        return NULL;
    }

    while(!feof(fin))
    {
        fscanf(fin, "%s", line);
        get_name(line, name);
        strcpy(data.name, name);
        data.totalcount = 1;
        if(head == NULL)
        {
            head = ListInit(data);
        } else {
            head = ListMergeNode(head, data);
        }
        memset(line, 0, 100);
    }

    return head;
}