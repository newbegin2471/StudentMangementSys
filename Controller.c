#include "Viewer.h"
#include "TeacherModel.h"
#include "StudentModel.h"
#include "AdminModel.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void adminPage();

int main(){
    /**********************************链表测试 *************************** */
    //创建空教师链表
    // TeaNode *t=createLinkList_t();
    // // Teacher test={"123456","123456",1,1,{2002,10,13}};
    // insertNodeInTail_t(t,(Teacher){"123456","123456",1,1,{2002,10,13}});
    // insertNodeInTail_t(t,(Teacher){"123456","123456",2,1,{2002,10,13}});
    // insertNodeInTail_t(t,(Teacher){"123456","123456",3,1,{2002,10,13}});
    // insertNodeInTail_t(t,(Teacher){"123456","123456",4,1,{2002,10,13}});
    // saveTeacherToFile(t,"teacher.txt");
    // TeaNode *t1=createLinkList_t();
    // loadTeacherFromFile(t1,"teacher.txt");
    // travelLinkList_t(t1);
    // // printf("%s\n",test.name);
    // travelLinkList_t(t);
    // /*销毁一个指定节点*/
    // delNode_t(t,2);
    // travelLinkList_t(t);
    // printf("***********\n");
    // insertNodeInTail_t(t,(Teacher){"234","234",2,1,{2002,10,13}});
    // travelLinkList_t(t);
    // delLinkList_t(t);
    /********************************************************************* */
    /***************************学生链表测试****************************** */
    // StuNode *s=newLinkList_s();
    // insertNodeInHead_s(s,(Stu){"123456","123456",1,1,{2002,10,13},100,100,100});
    // insertNodeInTail_s(s,(Stu){"123456","123456",2,1,{2002,10,13},100,100,100});
    // insertNodeInTail_s(s,(Stu){"123456","123456",3,1,{2002,10,13},100,100,100});
    // insertNodeInTail_s(s,(Stu){"123456","123456",4,1,{2002,10,13},100,100,100});
    // saveStudentToFile(s,"student.txt");
    // StuNode *s1=newLinkList_s();
    // loadStudentFromFile(s1,"student.txt");
    // travelLinkList_s(s1);
    // travelList_s(s);
    // delNode_s(s,2);
    // travelList_s(s);
    // delLinkList_s(s);
    /*********************************************************************** */
    /*********************管理员模块测试********************************** */
    // Admin a={"admin","admin123"};
    // saveAdminToFile(a,"admin.txt");
    // loadAdminFromFile(&a,"admin.txt");
    // printf("%s ",a.name);
    // printf("%s ",a.password);
    /*********************************************************************** */
    /****************************view模块测试 *********************************/
    // char ch;
    // while((ch=getOperation())!='q'){
    //     printf("%c\n",ch);
    // }
    // char password[20];
    // getPassword(password);
    // printf("%s\n",password);
    /************************************************************************** */
    /************************************主逻辑 */
    while(1){
        printMainPage();
        switch(mainPageInputJudge()){
            case '1':
                adminPage();
                break;
            case '2':
                printTeacherPage();
                break;
            case '3':
                printStudentPage();
                break;
        }
    
        getchar();
    }
    return 0;
}
void adminPage(){
    /*从文件中读取管理员信息*/
    Admin admintemp;
    TeaNode *t=createLinkList_t();
    int length=loadTeacherFromFile(t,"teacher.txt");
    int id=-1;
    Teacher tea;
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
            printf("请输入原密码:");
            if(judgePasword(admintemp.password)==1){
                printf("设置新密码:");
                getPassword(admintemp.password);
                printf("密码修改成功\n");
            }
            break;
            case '2':
            tea=inputTeacher(&length);
            insertNodeInTail_t(t,tea);
            case '3':
            system("cls");
            travelLinkList_t(t);
            break;
            case '4':
            system("cls");
            printf("根据工号删除教师,请输入教师的工号:\n");
            scanf("%d",&id);
            if(delNode_t(t,id)==1){
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
        getchar();
    }
    saveTeacherToFile(t,"teacher.txt");
    saveAdminToFile(admintemp,"admin.txt");
    delLinkList_t(t);
}
void teacherLogin(){
    TeaNode *t=createLinkList_t();
    StuNode *s=createLinkList_s();
    int teaLength=loadTeacherFromFile(t,"teacher.txt");
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

    }
    saveStudentToFile(s,"student.txt");
    saveTeacherToFile(t,"teacher.txt");
    delLinkList_s(s);
    delLinkList_t(t);
    p=NULL;
}