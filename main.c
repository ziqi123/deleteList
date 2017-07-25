//
//  main.c
//  deleteList
//
//  Created by 刘子琪 on 2017/7/25.
//  Copyright © 2017年 LinkList. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef  struct node
{
    int data;
    struct Node* next;
}Node;

Node *get_link(int length,int local,Node** plocal)
{
    Node *temp=NULL;
    Node *phead=NULL;
    Node *tail=NULL;
    
    int i=0;
    for (i=0;i<length;i++)
    {
        temp=(Node *)malloc(sizeof(Node));
        temp->next=NULL;
        temp->data=length-i;
        
        if(phead==NULL)
        {
            tail=temp;
        }
       if(local==length-i)
       {
           *plocal=temp;
       }
      
        temp->next=phead;
        phead=temp;
    }
    return phead;
}

void link_print(Node* temp)
{
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

Node* del_node(Node* phead,Node* local)
{
    if(phead==NULL||local==NULL)
    {
        printf("arg error:\n");
        return NULL;
    }
    
    if(local->next==NULL)
    {
        if(phead==local)
        {
            free(local);
            return NULL;
        }
        Node *prev=phead;
        while(prev!=NULL&&prev->next!=NULL)
        {
            if(prev->next==local)
            {
                Node *temp=prev->next;
                prev->next=temp ->next;
                free(local);
                return phead;
            }
            prev=prev->next;
        }
    }
    else
    {
        Node *temp=local->next;
        local->data=temp ->data;
        local->next=temp->next;
        free(temp);
        return phead;
    }
    return 0;
}


int main(int argc, const char * argv[]) {
    Node *phead=NULL;
    int local=0;
    int number=0;
    
    printf("please input number and local:\n");
    scanf("%d",&number);
    scanf("%d",&local);
    
    if(local>number||local<=0||number<=0)
    {
        printf("please input positive integer\n");
    }
    
    Node *plocal=NULL;
    phead=get_link(number, local, &plocal);
    
    link_print(phead);
    printf("del data:%d\n",plocal->data);
    
    phead=del_node(phead, plocal);
    
    link_print(phead);
    return 0;
}















