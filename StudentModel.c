#include "StudentModel.h"
#include <stdlib.h>
#include <stdio.h>
/*创建空链表*/
StuNode *newLinkList_s(){
    StuNode *node=(StuNode *)malloc(sizeof(StuNode));
    if(node==NULL){
        perror("Stu node malloc error\n");
        return NULL;
    }
    
}
/*销毁整个学生链表*/
void delLinkList_s(StuNode *s);
/*创建一个新节点*/
StuNode *newNode_s(Stu data);
/*销毁一个指定节点*/
int delNode_s(StuNode *s,int id);
/*头插法插入节点*/
int insertNodeInHead_s(StuNode *s,Stu data);
/*修改登陆密码*/
int changePassword(StuNode *s,char *password);
/*修改姓名*/
int changeName(StuNode *s,char *name);