/**
  * @file name:LLink.c
  * @brief    :Linked list basic function realization
  * @author   :i33akq@163.com
  * @date     :2025/04/14
  * @version  :1.0
  * @note     :None
  * @CopyRight (C)   2024-2025   i33akq@163.com   ALL Right Reseverd
*/

#include "LLink.h"

/**
  * @function name:LList_Creat
  * @brief        :Create a linked list and initialize it
  * @param        :none
  * @retval       :void
  * @version      :1.0
  * @note         :none
*/
LNode_t* LList_Creat()
{
    //1.创建一个头结点并申请内存
    LNode_t *Head = (LNode_t *)calloc(1, sizeof(LNode_t));
    //2.判断是否calloc成功
    if(NULL == Head)
    {
        printf("Calloc memory for Head is Failed");
        exit(-1);
    }
    //3.初始化，头结点中不存储有效内容
    Head->next = NULL;
    return Head;
}

/**
  * @function name:LList_NewNode
  * @brief        :Create a new node and initialize it
  * @param        :
  *                @data:the data field of a linked list
  * @retval       :Returns the list header address
  * @version      :1.0
  * @note         :None
*/
LNode_t *LList_NewNode(Elemtype_t data)
{
	//1.创建一个新结点并对新结点申请内存
	LNode_t *New = (LNode_t *)calloc(1,sizeof(LNode_t));
    //2.判断calloc是否成功
	if (NULL == New)
	{
		perror("Calloc memory for NewNode is Failed");
		return NULL;
	}
	//3.对新结点的数据域和指针域进行初始化
	New->data = data;
	New->next = NULL;

	return New;
}

/**
  * @function name:LList_Length
  * @brief        :Calculate the linked list length
  * @param        :
  *                @Head:the list header address
  * @retval       :Returns the length of the linked list 
  * @version      :1.0
  * @note         :None
*/
int LList_Length(LNode_t *Head)
{
    //1.对链表的头文件的地址进行备份
	LNode_t *Phead = Head;
    int Length=0;
    //2.遍历
    while(Phead->next!=NULL)
    {
        Phead=Phead->next;
        Length++;
    }
    return Length;
}

/**
  * @function name:LList_In
  * @brief        :Insertion node
  * @param        :
  *                @Head:the list header address
  *                @data:the data field of a linked list
  * @retval       :Insert successful return true otherwise return false 
  * @version      :1.0
  * @note         :None
*/
bool LList_In(LNode_t *Head,Elemtype_t data)
{
    //对链表的头文件的地址进行备份
	LNode_t *Phead = Head;

    //1.创建新节点并申请内存
    LNode_t *New=LList_NewNode(data);
    //2.查看新结点是否申请成功
    if(NULL==New)
    {
        printf("can not insert new node\n");
        return false;
    }
    //3.链表判空,为空则直接插入
    if (NULL == Head->next)
	{
		Head->next = New;
		return true;
	}
    //4.选择头插或尾插
    int x=1;
    printf("select mode(Head:1,Tail:2):");
    scanf("%d", &x); // Ensure proper input handling
    switch (x)
    {
    case 1:
        //5.头插
        New->next=Head->next;
        Head->next=New;
        break;
    case 2:
        //6.尾插，需要依次找到尾结点
        while(Phead->next != NULL)
        {
            Phead = Phead->next;
        }
        Phead->next = New;
        New->next=NULL;
        break;
    }

    return true;
}


/**
  * @function name:LList_InDest_Place
  * @brief        :Insertion node by place
  * @param        :
  *                @Head:the list header address
  *                @data:the data field of a linked list
  *                @dest:insertion place
  * @retval       :Insert successful return true otherwise return false 
  * @version      :1.0
  * @note         :None
*/
bool LList_InDest_Place(LNode_t *Head,Elemtype_t data,int dest)
{
    //对链表的头文件的地址进行备份
	LNode_t *Phead = Head;

    //1.创建新节点并申请内存
    LNode_t *New=LList_NewNode(data);
    //2.判断新结点是否申请成功
    if(NULL==New)
    {
        printf("can not insert new node\n");
        return false;
    }
    //3.若链表为空则失败
    if (NULL == Head->next)
	{
		printf("LinkList is empty");
		return false;
	}
    //4.若表长度<dest,则失败
    if(LList_Length(Head)<dest)
    {
        printf("cross the border");
        return false;
    }
    //5.遍历链表找到dest的位置
    int i=0;
    while(i<dest)
    {
        Phead=Phead->next;
        i++;
    }
    //6.选择前插或后插
    int x=1;
    printf("select mode:(fron:1,later:2)");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        //前插。实际上是使用后插，再交换前后数据域的值
        New->next=Phead->next;
        Phead->next=New;
        Elemtype_t temp;
        temp=Phead->data;
        Phead->data=New->data;
        New->data=temp;
        break;
    case 2:
        //后插
        New->next=Phead->next;
        Phead->next=New;
        break;
    }
    return true;
}

/**
  * @function name:LList_InDest_Value
  * @brief        :Insertion node by comparing data fields
  * @param        :
  *                @Head:the list header address
  *                @data:the data field of a linked list
  *                @dest:values to be compared
  * @retval       :Insert successful return true otherwise return false 
  * @version      :1.0
  * @note         :None
*/
bool LList_InDest_Value(LNode_t *Head,Elemtype_t data,int dest)
{
    //对链表的头文件的地址进行备份
	LNode_t *Phead = Head;

    //1.创建新节点并申请内存
    LNode_t *New=LList_NewNode(data);
    //2.判断新结点是否申请成功
    if(NULL==New)
    {
        printf("can not insert new node\n");
        return false;
    }
    //3.链表为空则失败
    if (NULL == Head->next)
	{
		printf("LinkList is empty");
		return false;
	}
    //4.遍历链表找到数据域等于dest的结点
    while(Phead->next!=NULL)
    {
        //5.若相等则退出循环，否则继续向后遍历
        if(Phead->data == dest)  break;
        else      Phead=Phead->next;
    }
    //6.遍历完成若没有符合条件的结点，则失败
    if(Phead->next==NULL && Phead->data!=dest) return false;
    //7.选择前插或后插
    int x=1;
    printf("select mode:(fron:1,later:2)");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        //前插。实际上是使用后插，再交换前后数据域的值
        New->next=Phead->next;
        Phead->next=New;
        Elemtype_t temp;
        temp=Phead->data;
        Phead->data=New->data;
        New->data=temp;
        break;
    case 2:
        //后插
        New->next=Phead->next;
        Phead->next=New;
        break;
    }
    return true;
}

/**
  * @function name:LList_Del
  * @brief        :Delete node
  * @param        :
  *                @Head:the list header address
  * @retval       :Delete successful return true otherwise return false 
  * @version      :1.0
  * @note         :None
*/
bool LList_Del(LNode_t *Head)
{
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
    //2.选择头删或尾删
    int x=1;
    Elemtype_t e;//记录被删除的数据
    printf("select mode(Head:1,Tail:2):");
    scanf("%d",&x);
    switch (x)
    {
    case 1:
        //头删
        p=p->next;
        Phead->next=p->next;
        e=p->data;
        free(p);
        break;
    case 2:
        //尾删。遍历完成时，Phead指向尾结点的前驱，p指向尾结点
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

/**
  * @function name:LList_DelDest_Place
  * @brief        :Delete node by place
  * @param        :
  *                @Head:the list header address
  *                @data:the data field of a linked list
  *                @dest:insertion place
  * @retval       :Delete successful return true otherwise return false 
  * @version      :1.0
  * @note         :None
*/
bool LList_DelDest_Place(LNode_t *Head,int dest)
{
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
    //2.表长度<dest,则失败
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

/**
  * @function name:LList_DelDest_Value
  * @brief        :Delete node by comparing data fields
  * @param        :
  *                @Head:the list header address
  *                @data:the data field of a linked list
  *                @dest:values to be compared
  * @retval       :Delete successful return true otherwise return false 
  * @version      :1.0
  * @note         :None
*/
bool LList_DelDest_Value(LNode_t *Head,Elemtype_t data,int dest)
{
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
    //2.遍历链表找到dest的位置
    while(Phead->next!=NULL)
    {
        if(Phead->data == dest)  break;
        else         Phead=Phead->next;
    }
    //3.遍历完成后，若没有符合条件的结点，则失败
     if(Phead->next==NULL && Phead->data!=dest) return false;
    //删除p指向的结点
    Phead->next=p->next;
    Elemtype_t e=p->data;
    p->next=NULL;
    free(p);

    return true;
}

/**
  * @function name:LList_Traverse
  * @brief        :Traverse the linked list
  * @param        :
  *                @Head:the list header address
  * @retval       :void 
  * @version      :1.0
  * @note         :None
*/
void LList_Traverse(LNode_t *Head)
{   
    //对链表的头文件的地址进行备份
    LNode_t *Phead = Head->next; 
    while(Phead != NULL)
    {
        printf("%d ", Phead->data);
        Phead = Phead->next;
    }
    printf("\n");
}