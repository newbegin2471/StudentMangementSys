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
// /*头插法插入节点*/
// int insertNodeInHead_t(TeaNode *t,Teacher data){
//     TeaNode *node=newNode_t(data);
//     node->next=t->next;
//     t->next=node;
//     return 0;
// }
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
/*根据id查找节点*/
TeaNode *findNodeByID_t(TeaNode *t,int id){
    if(t==NULL){
        printf("链表为空\n");
        return NULL;
    }
    TeaNode *p=t->next;
    while(p!=NULL){
        if(p->data.id==id){
            return p;
        }
        p=p->next;
    }
    return NULL;
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
/*从文件中读取信息到链表里面*/
int  loadTeacherFromFile(TeaNode *t,const char *filename){
    if(t==NULL){
        return -1;
    }
    //统计读了几条
    int count=0;
    FILE *fp=fopen(filename,"r");
    if(fp==NULL){
        printf("open file error\n");
        return -1;
    }
    Teacher temp;
    while(fread(&temp,sizeof(Teacher),1,fp)==1){
        insertNodeInTail_t(t,temp);
        count++;
    }
    fclose(fp);
    fp=NULL;
    return count;
}
/*把链表信息写入文件*/
int saveTeacherToFile(TeaNode *t,const char *filename){
    if(t==NULL){
        return -1;
    }
    FILE *fp=fopen(filename,"w");
    if(fp==NULL){
        printf("open file error\n");
        return -1;
    }
    TeaNode *p=t->next;
    while(p!=NULL){
        fwrite(&p->data,sizeof(p->data),1,fp);
        p=p->next;
    }
    fclose(fp);
    fp=NULL;
    return 1;
}