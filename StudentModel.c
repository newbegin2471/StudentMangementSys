#include "StudentModel.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*创建空链表*/
StuNode *newLinkList_s(){
    StuNode *node=(StuNode *)malloc(sizeof(StuNode));
    if(node==NULL){
        perror("Stu node malloc error\n");
        return NULL;
    }
    node->next=NULL;
    return node;
}
/*销毁整个学生链表*/
void delLinkList_s(StuNode *s){
    while(s!=NULL){
        StuNode *temp=s;
        s=s->next;
        free(temp);
    }
}
/*创建一个新节点*/
StuNode *newNode_s(Stu data){
    StuNode *node=(StuNode *)malloc(sizeof(StuNode));
    if(node==NULL){
        perror("node malloc error\n");
        return NULL;
    }
    node->next=NULL;
    strcpy(node->data.name,data.name);
    node->data.id=data.id;
    strcpy(node->data.password,data.password);
    node->data.gender=data.gender;
    node->data.date.year=data.date.year;
    node->data.date.month=data.date.month;
    node->data.date.day=data.date.day;
    node->data.chinese=data.chinese;
    node->data.math=data.math;
    node->data.english=data.english;
    return node;
}
/*销毁一个指定节点*/
int delNode_s(StuNode *s,int id){
    while(s->next!=NULL){
        if(s->next->data.id==id){
            s->next=s->next->next;
            return 0;
        }
        s=s->next;
    }
    return -1;
}
/*头插法插入节点*/
int insertNodeInHead_s(StuNode *s,Stu data){
    StuNode *node=newNode_s(data);
    node->next=s->next;
    s->next=node;
    return 0;
}
/*尾插法插入节点*/
int insertNodeInTail_s(StuNode *s,Stu data){
    StuNode *node=newNode_s(data);
    while(s->next!=NULL){
        s=s->next;
    }
    s->next=node;
    return 1;
}
/*遍历链表*/
void travelList_s(StuNode *s){
    while(s->next!=NULL){
        s=s->next;
        printf("%s ",s->data.name);
        printf("%s ",s->data.password);
        printf("%d ",s->data.gender);
        printf("%d ",s->data.id);
        printf("%d-",s->data.date.year);
        printf("%d-",s->data.date.month);
        printf("%d ",s->data.date.day);
        printf("%f ",s->data.chinese);
        printf("%f ",s->data.math);
        printf("%f\n",s->data.english);
    }
}
// /*修改登陆密码*/
// int changePassword(StuNode *s,int id,char *password){

// }
// /*修改姓名*/
// int changeName(StuNode *s,int id,char *name);