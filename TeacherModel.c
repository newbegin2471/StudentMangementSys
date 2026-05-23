#include "TeacherModel.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*创建空链表*/
TeaNode *createLinkList_t(){
    TeaNode *node=(TeaNode *)malloc(sizeof(TeaNode));
    if(node==NULL){
        perror("techer node malloc error\n");
        return NULL;
    }
    node->next=NULL;
    return node;
}
/*销毁整个教师链表*/
void delLinkList_t(TeaNode *t){
    while(t){
        TeaNode *temp=t;
        t=t->next;
        free(temp);
    }
}
/*创建一个新节点*/
TeaNode *newNode_t(Teacher data){
    TeaNode *node=(TeaNode *)malloc(sizeof(TeaNode));
    if(node==NULL){
        perror("teacher node malloc error\n");
        return NULL;
    }
    node->next=NULL;
    node->data.id=data.id;
    strncpy(node->data.name,data.name,sizeof(data.name));
    node->data.birth.year=data.birth.year;
    node->data.birth.month=data.birth.month;
    node->data.birth.day=data.birth.day;
    node->data.gender=data.gender;
    strncpy(node->data.passWord,data.passWord,sizeof(data.passWord));
    return node;
}
/*销毁一个指定节点*/
int delNode_t(TeaNode *t,int id){
    while(t->next!=NULL){
        if(t->next->data.id==id){
            TeaNode *temp=t->next;
            t->next=t->next->next;
            free(temp);
            return 1;
        }
        t=t->next;
    }
    return -1;
}
/*头插法插入节点*/
int insertNodeInHead_t(TeaNode *t,Teacher data){
    TeaNode *node=newNode_t(data);
    node->next=t->next;
    t->next=node;
    return 0;
}
/*尾插法插入节点*/
int insertNodeInTail_t(TeaNode *t,Teacher data){
    TeaNode *node=newNode_t(data);
    TeaNode *p=t;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=node;
    node->next=NULL;
    return 1;
}
/*修改登陆密码*/
int changePassword_t(TeaNode *t,int id,char *password){
    while(t->next!=NULL){
        if(t->data.id==id){
            strcpy(t->data.passWord,password);
            return 0;
        }
        t=t->next;
    }
    return -1;
}
/*修改姓名*/
int changeName_t(TeaNode *t,int id,char *name){
    while(t->next!=NULL){
        if(t->data.id==id){
            strcpy(t->data.name,name);
            return 0;
        }   
    }
    return -1;
}
/*遍历链表*/
void travelLinkList_t(TeaNode *t){
    while(t->next!=NULL){
        t=t->next;
        printf("%s ",t->data.name);
        printf("%s ",t->data.passWord);
        printf("%d ",t->data.id);
        printf("%d ",t->data.gender);
        printf("%d ",t->data.birth.year);
        printf("%d ",t->data.birth.month);
        printf("%d\n",t->data.birth.day);
    }
}