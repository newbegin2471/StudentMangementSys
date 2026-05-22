#include "TeacherModel.h"
#include <stdlib.h>
#include <string.h>
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
            TeaNode *temp=t;
            t->next=t->next->next;
            free(temp);
            return 1;
        }
        t=t->next;
    }
    return -1;
}
/*头插法插入节点*/
int insertNode_t(TeaNode *t,Teacher data){
    TeaNode *node=newNode_t(data);
    node->next=t->next;
    t->next=node;
    return 1;
}
/*修改登陆密码*/
int changePassword_t(TeaNode *t,char *password){
    
}
/*修改姓名*/
int changeName_t(TeaNode *t,char *name);