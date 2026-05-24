#include "StudentModel.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*创建空链表*/
StuNode *createLinkList_s(){
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
/*根据id查找，找到返回指向节点指针*/
StuNode *findNodeByID_s(StuNode *s,int id){
    if(s==NULL){
        printf("链表为空\n");
        return NULL;
    }
    StuNode *p=s->next;
    while(p!=NULL){
        if(p->data.id==id){
            return p;
        }
        p=p->next;
    }
    return NULL;
}
/*把链表信息写入文件*/
int saveStudentToFile(StuNode *s,const char *filename){
    if(s==NULL){
        printf("链表为空\n");
        return -1;
    }
    FILE *fp=fopen(filename,"w");
    if(fp==NULL){
        printf("open file error\n");
        return -1;
    }
    StuNode *p=s->next;
    while(p!=NULL){
        fwrite(&p->data,sizeof(p->data),1,fp);
        p=p->next;
    }
    fclose(fp);
    fp=NULL;
    return 1;
}
/*从文件中读取信息到链表里面*/
int loadStudentFromFile(StuNode *s,const char *filename){
    if(s==NULL){
        printf("链表为空\n");
        return -1;
    }
    int count =0;
    FILE *fp=fopen(filename,"r");
    if(fp==NULL){
        printf("open file error\n");
        return -1;
    }
    Stu temp;
    while(fread(&temp,sizeof(temp),1,fp)==1){
        insertNodeInTail_s(s,temp);
        count++;
    }
    return count;
}
/*遍历链表*/
void travelLinkList_s(StuNode *s){
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
