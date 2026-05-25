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
StuNode *createLinkList_s();
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
/*根据id查找，找到返回指向节点指针*/
StuNode *findNodeByID_s(StuNode *s,int id);
/*把链表信息写入文件*/
int saveStudentToFile(StuNode *s,const char *filename);
/*从文件中读取信息到链表里面*/
int loadStudentFromFile(StuNode *s,const char *filename);
/*遍历链表*/
void travelLinkList_s(StuNode *s);
/*冒泡排序*/
void bubbleSortByScore(StuNode *s);
void bubbleSortByID(StuNode *s);
#endif