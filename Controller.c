#include "Viewer.h"
#include "TeacherModel.h"
#include "StudentModel.h"
#include "AdminModel.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void adminPage();
void teacherLogin();
void studentLogin();
int teaID[100]={0};
int stuID[10000]={0};
int main(){
    GetIDFromFile();
    while(1){
        printMainPage();
        switch(mainPageInputJudge()){
            case '1':
                adminPage();
                break;
            case '2':
                teacherLogin();
                break;
            case '3':
                studentLogin();
                break;
        }
    }
    return 0;
}
void adminPage(){
    /*从文件中读取管理员信息*/
    Admin admintemp;
    TeaNode *t=createLinkList_t();
    int teaLength=loadTeacherFromFile(t,"teacher.txt");
    int id=-1;
    Teacher teatemp;
    loadAdminFromFile(&admintemp,"admin.txt");
    if(judgePasword(admintemp.password)==-1){
        return;
    }
    while(1){
        printAdminPage();
        int lable=adminPageInputJudge();
        switch(lable){
            case '1':
            system("cls");
            printf("需要输入原密码！\n");
            if(judgePasword(admintemp.password)==1){
                printf("设置新密码\n");
                getPassword(admintemp.password);
                printf("密码修改成功\n");
                _getch();
            }
            break;
            case '2':
            teatemp=inputTeacher(&teaLength);
            insertNodeInTail_t(t,teatemp);
            printf("添加完成");
            _getch();
            case '3':
            system("cls");
            printAllNode_t(t);
            break;
            case '4':
            printAllNode_t(t);
            printf("根据工号删除教师,请输入教师的工号:");
            if(scanf("%d",&id)!=1){
                printf("非法输入\n");
                flushInput();
                _getch();
                break;
            }
            flushInput();
            if(delNode_t(t,id)==1){
                teaID[id%100]=0;
                teaLength--;
                printf("销毁成功\n");
            }else{
                printf("未找到\n");
            }
            break;
            case '5':
            changeTeacherByAdmin(t);
            break;
        }
        if(lable=='q')
        break;
    }
    saveTeacherToFile(t,"teacher.txt");
    saveAdminToFile(admintemp,"admin.txt");
    delLinkList_t(t);
}
void teacherLogin(){
    TeaNode *t=createLinkList_t();
    StuNode *s=createLinkList_s();
    loadTeacherFromFile(t,"teacher.txt");
    int stuLength=loadStudentFromFile(s,"student.txt");
    /*登陆验证*/
    /*保存登陆节点*/
    TeaNode *p=teacherLoginJudge(t);
    if(p==NULL){
    delLinkList_s(s);
    delLinkList_t(t);
    return;
    }
    while(1){
        printOneNode_t(p);
        printTeacherPage();
        char ch=teacherPageInputJudge();
        switch(ch){
            case '1':
            system("cls");
            printf("需要原密码\n");
            if(judgePasword(p->data.passWord)==1){
                printf("设置新密码\n");
                getPassword(p->data.passWord);
                printf("密码修改成功\n");
                _getch();
                break;
            }else{
                printf("错误超过3次\n");
                printf("按任意键继续......\n");
                _getch();
            }
            break;
            case '2':
            printOneNode_t(p);
            _getch();
            break;
            case '3':
            addNewStudent(s,&stuLength);
            break;
            case '4':
            system("cls");
            printf("现有学生\n");
            printAllNode_s(s);
            printf("根据学号删除,请输入学生的学号:\n");
            if(s->next==NULL){
                printf("没有学生可删除\n");
                _getch();
                break;
            }
            int id;
            scanf("%d",&id);
            flushInput();
            if(delNode_s(s,id)==1){
                stuLength--;
                stuID[id%10000]=0;
                printf("销毁成功\n");
            }else{
                printf("未找到\n");
            }
            printf("按任意键继续......\n");
            _getch();
            break;
            case '5':
            if(s->next==NULL){
                printf("没有学生\n");
                _getch();
                break;
            }
            printOneStudentByID(s);
            break;
            case '6':           
            changeStudentByTeacher(s);
            break;
            case '7':
            printStudentByID(s);
            break;
            case '8':
            printStudentByScore(s);
            break;
        }
        if(ch=='q')
            break;
    }
    saveStudentToFile(s,"student.txt");
    saveTeacherToFile(t,"teacher.txt");
    delLinkList_s(s);
    delLinkList_t(t);
    p=NULL;
}
/*学生登陆及其操作*/
void studentLogin(){
    StuNode *s=createLinkList_s();
    loadStudentFromFile(s,"student.txt");
    StuNode *p=studentLoginJudge(s);
    if(p==NULL){
        delLinkList_s(s);
        return;
    }
    while(1){
        printStudentPage();
        char ch=studentPageInputPage();
        switch(ch){
            case '1':
            system("cls");
            printf("需要原密码\n");
            if(judgePasword(p->data.password)==1){
                printf("设置新密码\n");
                getPassword(p->data.password);
                printf("密码修改成功\n");
                _getch();
                break;
            }else{
                printf("错误超过3次\n");
                _getch();
            }
            break;
            case '2':
            printOneNode_s(p);
            break;
        }
        if(ch=='q')
            break;
    }
    saveStudentToFile(s,"student.txt");
    free(p);
    p=NULL;
}
/*读取id函数*/
void GetIDFromFile(){
    FILE *fp=fopen("teachaerID","rb");
    if(fp==NULL){
        printf("打开文件失败\n");
        return;
    }
    fread(teaID,sizeof(teaID),4,fp);
    fclose(fp);
    fp=NULL;
    fp=fopen("studentID","rb");
    if(fp==NULL){
        printf("打开文件失败\n");
        return;
    }
    fread(stuID,sizeof(stuID),10000,fp);
    fclose(fp);
    fp=NULL;
}

void saveIDToFile(){
    FILE *fp=fopen("teachaerID","wb");
    if(fp==NULL){
        printf("打开文件失败\n");
        return;
    }
    fwrite(teaID,sizeof(teaID),4,fp);
    fclose(fp);
    fp=NULL;
    fp=fopen("studentID","wb");
    if(fp==NULL){
        printf("打开文件失败\n");
        return;
    }
    fwrite(stuID,sizeof(stuID),10000,fp);
    fclose(fp);
    fp=NULL;
}
/*获取ID函数*/
int  getStuID(){
    for(int i=0;i<10000;i++){
        if(stuID[i]==0){
            return i;
        }
    }   
    return -1;
}
int getTeaID(){
    for(int i=0;i<100;i++){
        if(teaID[i]==0){
            return i;
        }
    }
    return -1;
}