#ifndef _CONTROLLER_C_
#define _CONTROLLER_C_
/*定义名字长度*/
#define N 20
/*定义密码长度*/
#define PASS 20
typedef struct Date{
    int year;
    int month;
    int day;
}BirthDate;

/*读取id函数*/
void GetIDFromFile();
void saveIDToFile();
/*获取ID函数*/
int  getStuID();
int  getTeaID();
#endif
