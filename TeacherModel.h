#include "Controller.h"
#ifndef _TEACHERMODEL_H_
#define _TEACHERMODEL_H_
/*定义老师信息结构体*/
typedef struct Teacher{
    char name[N];
    char passWord[N];
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
// /*头插法插入节点*/
// int insertNodeInHead_t(TeaNode *t,Teacher data);
/*尾插法插入节点*/
int insertNodeInTail_t(TeaNode *t,Teacher data);
/*根据id查找节点*/
TeaNode *findNodeByID_t(TeaNode *t,int id);
/*遍历链表*/
void travelLinkList_t(TeaNode *t);
/*从文件中读取信息到链表里面*/
int loadTeacherFromFile(TeaNode *t,const char *filename);
/*把链表信息写入文件*/
int saveTeacherToFile(TeaNode *t,const char *filename);
#endif