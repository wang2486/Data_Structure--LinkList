/******************************************************************************
 * 
 *  file name: LinkList.c
 *  author   : w6661888@google.com
 *  date     : 2025/4/8
 *  function : LinkList
 *  note     : null
 * 
 * 
 *  Copyright (C) 2025  w6661888@google.com  ALL rights reserved.
 * 
 *******************************************************************************/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//自定义数据类型,可以按需修改
typedef int Elemtype_t;

//构造链表的结点,链表中所有结点的数据类型应该是相同的
typedef struct LNode
{
	Elemtype_t data; // 数据域
	struct LNode* next; // 指针域
} LNode_t;

//创建一个有头结点的链表并初始化
LNode_t* LList_Creat(){
    //1.创建一个头结点并申请内存
    LNode_t *Head = (LNode_t *)calloc(1, sizeof(LNode_t));
    if(NULL == Head)
    {
        printf("Calloc memory for Head is Failed");
        exit(-1);
    }
    //2.初始化，头结点中不存储有效内容
    Head->next = NULL;
    return Head;
}

//创建新的结点，并对新结点进行初始化（数据域 + 指针域）
LNode_t *LList_NewNode(Elemtype_t data)
{
	//1.创建一个新结点并对新结点申请内存
	LNode_t *New = (LNode_t *)calloc(1,sizeof(LNode_t));
	if (NULL == New)
	{
		perror("Calloc memory for NewNode is Failed");
		return NULL;
	}
	//2.对新结点的数据域和指针域进行初始化
	New->data = data;
	New->next = NULL;

	return New;
}

//求表长度
int LList_Length(LNode_t *Head){
    //对链表的头文件的地址进行备份
	LNode_t *Phead = Head;
    int Length=0;
    while(Phead->next!=NULL)
    {
        Phead=Phead->next;
        Length++;
    }
    return Length;
}

//插入结点
bool LList_In(LNode_t *Head,Elemtype_t data){
    //1.创建新节点并申请内存
    LNode_t *New=LList_NewNode(data);
    if(NULL==New)
    {
        printf("can not insert new node\n");
        return false;
    }
    //2.链表判空,为空则直接插入
    if (NULL == Head->next)
	{
		Head->next = New;
		return true;
	}
    //3.选择头插或尾插
    int x=1;
    printf("select mode(Head:1,Tail:2):");
    scanf("%d", &x); // Ensure proper input handling
    switch (x)
    {
    case 1:
        New->next=Head->next;
        Head->next=New;
        break;
    case 2:
        LNode_t *temp = Head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = New;
        New->next=NULL;
        break;
    }

    return true;
}
bool LList_InDest(LNode_t *Head,Elemtype_t data,int dest){
    //对链表的头文件的地址进行备份
	LNode_t *Phead = Head;

    //1.创建新节点并申请内存
    LNode_t *New=LList_NewNode(data);
    if(NULL==New)
    {
        printf("can not insert new node\n");
        return false;
    }
    //2.链表为空则失败
    if (NULL == Head->next)
	{
		printf("LinkList is empty");
		return false;
	}
    //.表长度<dest,则失败
    if(LList_Length(Head)<dest)
    {
        printf("cross the border");
        return false;
    }
    //3.遍历链表找到dest的位置
    int i=0;
    while(i<dest)
    {
        Phead=Phead->next;
        i++;
    }
    //4.前插或后插
    int x=1;
    printf("select mode:(fron:1,later:2)");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        //使用后插，再交换前后数据域的值
        New->next=Phead->next;
        Phead->next=New;
        Elemtype_t temp;
        temp=Phead->data;
        Phead->data=New->data;
        New->data=temp;
        break;
    case 2:
        New->next=Phead->next;
        Phead->next=New;
        break;
    }
    return true;
}

//删除结点
bool LList_Del(LNode_t *Head){
    //对链表的头文件的地址进行备份
	LNode_t *Phead = Head;
    //双指针扫描,p指向要被删除的结点
    LNode_t *p=Phead;

    //1.链表判空
    if(NULL==Head)
    {
        printf("LinkList is empty");
        return false;
    }
    //2.头删或尾删
    int x=1;
    Elemtype_t e;//记录被删除的数据
    printf("select mode(Head:1,Tail:2):");
    scanf("%d",&x);
    switch (x)
    {
    case 1:
        p=p->next;
        Phead->next=p->next;
        e=p->data;
        free(p);
        break;
    case 2:
        p=Head->next;
        while(p->next!=NULL)
        {
            Phead=Phead->next;
            p=p->next;
        }
        Phead->next=NULL;
        p->next=NULL;
        e=p->data;
        free(p);
        break;
    }
    return true;
}
bool LList_DelDest(LNode_t *Head,int dest){
    //对链表的头文件的地址进行备份
	LNode_t *Phead = Head;
    //双指针扫描,p指向要被删除的结点
    LNode_t *p=Phead;

    //1.链表判空
    if(NULL==Head)
    {
        printf("LinkList is empty");
        return false;
    }
    //.表长度<dest,则失败
    if(LList_Length(Head)<dest)
    {
        printf("cross the border");
        return false;
    }
    //2.遍历链表找到dest的位置
    int i=0;
    while(i<dest)
    {   
        p=p->next;
        if(i>=1)
        {
            Phead=Phead->next;
        }
        i++;
    }
    //删除p指向的结点
    Phead->next=p->next;
    Elemtype_t e=p->data;
    p->next=NULL;
    free(p);

    return true;
}

//遍历
void LList_traverse(LNode_t *Head)
{   
    //对链表的头文件的地址进行备份
    LNode_t *Phead = Head->next; // Skip the head node as it does not store valid data
    while(Phead != NULL)
    {
        printf("%d ", Phead->data);
        Phead = Phead->next;
    }
}

int main(int argc,char const *argv[])
{
    LNode_t *Head = LList_Creat();
    LList_In(Head,5);
    LList_In(Head,4);
    LList_In(Head,3);
    LList_In(Head,2);
    LList_In(Head,1);
    LList_traverse(Head);
    printf("\n");

    //LList_InDest(Head,100,3);
    //LList_traverse(Head);

    //LList_Del(Head);
    //LList_traverse(Head);

    LList_DelDest(Head,5);
    LList_traverse(Head);

    return 0;
}