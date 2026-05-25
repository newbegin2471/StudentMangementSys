#include "TeacherModel.h"
#include "StudentModel.h"
#ifndef _VIEW_H_
#define _VIEW_H_
/*刷新函数，用于刷新缓冲区*/
void flushInput();
/*打印主界面*/
void printMainPage();
/*主界面操作输入合法判断*/
char mainPageInputJudge();
/*管理员登陆界面*/
void printAdminPage();
/*管理员界面操作输入合法性判断*/
char adminPageInputJudge();
/*打印教师登陆界面*/
void printTeacherPage();
/*教师登陆界面合法性判断*/
char teacherPageInputJudge();
/*打印学生登陆界面*/
void printStudentPage();
/*学生登陆界面操作合法性判断*/
char studentPageInputPage();
// /*按键操作函数*/
char getOperation();
/*密码输入函数*/
int getPassword(char *pass);
/*密码判断函数*/
int judgePasword(char *pass);
/*添加教师信息,根据数字length自动分配工号*/
Teacher inputTeacher(int *length);
/*修改教师信息*/
void changeTeacherByAdmin(TeaNode *t);
/*获取工号或者学号*/
void getID(int *id);
/*教师登陆验证,成功返回教师节点的指针*/
TeaNode *teacherLoginJudge(TeaNode *t);
/*打印单个教师节点*/
void printOneNode_t(TeaNode *t);
/*打印所有教师节点*/
void printAllNode_t(TeaNode *t);
/*打印单个学生节点信息*/
void printOneNode_s(StuNode *s);
/*打印所有学生节点信息*/
void printAllNode_s(StuNode *s);
/*添加新学生*/
void addNewStudent(StuNode *s,int *length);
/*查阅指定学生信息*/
void printOneStudentByID(StuNode *s);
/*修改学生信息*/
void changeStudentByTeacher(StuNode *s);
/*按总分从高到低查看所有学生信息*/
void printStudentByScore(StuNode *s,int length);
/*按学号打印输出信息*/
void printStudentByID(StuNode *s,int length);
/*学生登陆验证*/
StuNode *studentLoginJudge(StuNode *s);
#endif