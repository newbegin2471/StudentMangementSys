#include "Controller.h"
#ifndef _TEACHERMODEL_H_
#define _TEACHERMODEL_H_
/*定义老师信息结构体*/
typedef struct Teacher{
    char name[N];
    char passWord[PASS];
    int id;
    int gender;
    BirthDate birth;
}Teacher;
/*定义链表节点*/
typedef struct TeaNode{
    Teacher data;
    struct TeaNode *next;
}TeaNode;
/*创建空链表*/
TeaNode *createLinkList_t();
/*销毁整个教师链表*/
void delLinkList_t(TeaNode *t);
/*创建一个新节点*/
TeaNode *newNode_t(Teacher data);
/*销毁一个指定节点*/
int delNode_t(TeaNode *t,int id);
/*头插法插入节点*/
int insertNode_t(TeaNode *t,Teacher data);
/*修改登陆密码*/
int changePassword_t(TeaNode *t,char *password);
/*修改姓名*/
int changeName_t(TeaNode *t,char *name);
#endif