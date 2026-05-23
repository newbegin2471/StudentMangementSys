#include "TeacherModel.h"
#ifndef _VIEW_H_
#define _VIEW_H_

/*定义一个栈用于保存操作信息*/
#define stackSize 10
typedef int OperationData;
typedef struct Operation{
    OperationData data[stackSize];
    int top;
}OperationStack;
/*创建一个栈*/
OperationStack *createStack();
/*判断栈是否为空*/
int isEmpty(OperationStack *s);
/*入栈*/
int pushStack(OperationStack *s, OperationData data);
/*出栈*/
OperationData popStack(OperationStack *s);
/*销毁栈*/
void delStack(OperationStack *s);
/*打印主界面*/
void printMainPage();
/*主界面操作输入合法判断*/
char mainPageInputJudge();
/*管理员登陆界面*/
void printAdminPage();
/*管理员界面输入合法性判断*/
char adminPageInputJudge();
/*打印教师登陆界面*/
void printTeacherPage();
/*教师登陆界面合法性判断*/
char teacherPageInputJudge();
/*打印学生登陆界面*/
void printStudentPage();
/*学生登陆界面合法性判断*/
char studentPageInputPage();
/*按键操作函数*/
char getOperation();
/*密码输入函数*/
int getPassword(char *pass);
/*密码判断函数*/
int judgePasword(char *pass);
/*添加教师信息,根据数字length自动分配工号*/
Teacher inputTeacher(int *length);
#endif