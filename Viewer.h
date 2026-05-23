#ifndef _VIEW_H_
#define _VIEW_H_
/*定义一个栈用于保存操作信息*/
typedef int OperationData;
typedef struct Operation{
    OperationData data[10];
}Operation;
/*打印主界面*/
void printMainPage();
/*管理员登陆界面*/
void printadminPage();
/*打印教师登陆界面*/
void printTeacherPage();
/*打印学生登陆界面*/
void printStudentPage();
/*按键操作函数*/
char getCommand();

#endif