#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
struct Node
{
    DataType data;
    struct Node *next; 
};
typedef struct Node Node;

//1
Node* InitList()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

//2
void HeadInsert(Node* head, DataType val)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = head->next;
    head->next = newnode;
}

//3
void TailInsert(Node* head, DataType val)
{
    Node* p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;
    p->next = newnode;
}

//4
int IsEmpty(Node* head)
{
    if(head->next == NULL)
        return 1;
    else
        return 0;
}

//5
int GetLength(Node* head)
{
    int len = 0;
    Node* p = head->next;
    while(p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

//6
void PrintList(Node* head)
{
    Node* p = head->next;
    if(IsEmpty(head))
    {
        printf("链表为空！\n");
        return;
    }
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


int main()
{
    Node* L = InitList();
    printf("====尾插建立链表 1 2 3 4====\n");
    TailInsert(L,1);
    TailInsert(L,2);
    TailInsert(L,3);
    TailInsert(L,4);
    PrintList(L);

    printf("链表长度：%d\n",GetLength(L));
    printf("是否为空(1空0非空):%d\n",IsEmpty(L));

    printf("\n====头插入 99====\n");
    HeadInsert(L,99);
    PrintList(L);
    printf("链表长度：%d\n",GetLength(L));

    return 0;
}