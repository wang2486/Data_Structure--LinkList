/**
  * @file name:LinkList.c
  * @brief    :function test
  * @date     :2025/04/14
  * @version  :1.0
  * @note     :None
  * @CopyRight (C)   2024-2025   i33akq@163.com   ALL Right Reseverd
*/
#include "LLink.h"

int main(int argc,char const *argv[])
{
    LNode_t *Head = LList_Creat();
    LList_In(Head,5);
    LList_In(Head,4);
    LList_In(Head,3);
    LList_In(Head,2);
    LList_In(Head,1);
    LList_Traverse(Head);

    //LList_InDest_Place(Head,100,3);
    //LList_InDest_Value(Head,100,4);
    
    //LList_Del(Head);
    //LList_DelDest(Head,5);
    LList_DelDest_Place(Head,4);

    LList_Traverse(Head);
    return 0;
}