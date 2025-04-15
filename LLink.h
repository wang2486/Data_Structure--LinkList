/**
  * @file name:LLink.h
  * @brief    :Functional interface design
  * @author   :i33akq@163.com
  * @date     :2025/04/14
  * @version  :1.0
  * @note     :None
  * @CopyRight (C)   2024-2025   i33akq@163.com   ALL Right Reseverd
*/

#ifndef _LLINK_H
#define _LLINK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype_t;
typedef struct LNode
{
	Elemtype_t data; // 数据域
	struct LNode* next; // 指针域
} LNode_t;

/**
  * @function name:LList_Creat
  * @brief        :Create a linked list and initialize it
  * @param        :none
  * @retval       :void
  * @version      :1.0
  * @note         :none
*/
LNode_t* LList_Creat();

/**
  * @function name:LList_NewNode
  * @brief        :Create a new node and initialize it
  * @param        :
  *                @data:the data field of a linked list
  * @retval       :Returns the list header address
  * @version      :1.0
  * @note         :None
*/
LNode_t *LList_NewNode(Elemtype_t data);

/**
  * @function name:LList_Length
  * @brief        :Calculate the linked list length
  * @param        :
  *                @Head:the list header address
  * @retval       :Returns the length of the linked list 
  * @version      :1.0
  * @note         :None
*/
int LList_Length(LNode_t *Head);

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
bool LList_In(LNode_t *Head,Elemtype_t data);

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
bool LList_InDest_Place(LNode_t *Head,Elemtype_t data,int dest);

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
bool LList_InDest_Value(LNode_t *Head,Elemtype_t data,int dest);

/**
  * @function name:LList_Del
  * @brief        :Delete node
  * @param        :
  *                @Head:the list header address
  * @retval       :Delete successful return true otherwise return false 
  * @version      :1.0
  * @note         :None
*/
bool LList_Del(LNode_t *Head);

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
bool LList_DelDest_Place(LNode_t *Head,int dest);

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
bool LList_DelDest_Value(LNode_t *Head,Elemtype_t data,int dest);

/**
  * @function name:LList_Traverse
  * @brief        :Traverse the linked list
  * @param        :
  *                @Head:the list header address
  * @retval       :void 
  * @version      :1.0
  * @note         :None
*/
void LList_Traverse(LNode_t *Head);



#endif