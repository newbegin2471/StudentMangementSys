#include "Controller.h"
#ifndef _STUDENTMODEL_H_
#define _STUDENTMODEL_H_
typedef struct Student{
    char name[N];
    char password[N];
    int id;
    int gender;
    BirthDate date;
    float math;
    float chinese;
    float english;
}Stu;
/*定义链表节点*/
typedef struct StuNode{
    Stu data;
    struct StuNode *next;
}StuNode;
/*创建空链表*/
StuNode *newLinkList_s();
/*销毁整个学生链表*/
void delLinkList_s(StuNode *s);
/*创建一个新节点*/
StuNode *newNode_s(Stu data);
/*销毁一个指定节点*/
int delNode_s(StuNode *s,int id);
/*头插法插入节点*/
int insertNodeInHead_s(StuNode *s,Stu data);
/*尾插法插入节点*/
int insertNodeInTail_s(StuNode *s,Stu data);
/*修改登陆密码*/
int changePassword(StuNode *s,int id,char *password);
/*修改姓名*/
int changeName(StuNode *s,int id,char *name);
/*遍历链表*/
void travelList_s(StuNode *s);
#endif