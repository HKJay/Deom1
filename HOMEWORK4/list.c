/*
**·Çµİ¹éÉ¾³ıÁĞ±í
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct List
{
    int value;
    struct List *next;
}list_item;

list_item* creat_list()
{
    list_item *head = (list_item*)malloc(sizeof(list_item));
    head->next = NULL;
    head->value = 0;
    return head;
}

int add_list(list_item *head , int val)
{
    list_item *q = head;
    while (q->next != NULL)
    {
        q = q->next;
    } 
    list_item *p = (list_item*)malloc(sizeof(list_item));
    p->next = NULL;
    p->value = val;
    q->next = p;
    return 1;
}

int print_list(list_item *head)
{
    list_item *q = head ->next;
    while(q != NULL)
    {
        printf("%d  " , q->value);
        q = q->next;
    }
    printf("\n");
    return 1;
}

int erase_list(list_item *head)
{
    list_item *q = head;
    list_item *p = head;
    while(q != NULL)
    {
        p = q->next;
        free(q);
        q = p;
    }
    printf("finish\n");
    return 1;
}

int main()
{
    list_item *head = creat_list();
    int val ;
    printf("Input the list:\n");
    while(scanf("%d" , &val))
    {
        add_list(head , val);
    }
    printf("The list:");
    print_list(head);
    erase_list(head);
    return 0;
}