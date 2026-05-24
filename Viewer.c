#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include "Viewer.h"
#include "Controller.h"
/*闰年天数*/
int monthInyear[12]={31,28,31,30,31,30,31,31,30,31,30,31};
/*创建一个栈*/
OperationStack *createStack(){
    OperationStack *s=(OperationStack *)malloc(sizeof(OperationStack));
    if(s==NULL){
        perror("stack malloc error\n");
        return NULL;
    }
    s->top=-1;
    return s;
}
/*判断栈是否为空*/
int isEmpty(OperationStack *s){
    return s->top==-1;
}
/*入栈*/
int  pushStack(OperationStack *s, OperationData data){
    if((s->top+1)==stackSize){
        perror("栈已经满\n");
        return -1;
    }
    s->top++;
    s->data[s->top]=data;
    return 1;
}
/*出栈*/
OperationData popStack(OperationStack *s){
    if(s->top==-1){
        perror("栈为空\n");
        return -1;
    }
    s->top--;
    return s->data[s->top+1];
}
/*销毁栈*/
void delStack(OperationStack *s){
    free(s);
    s=NULL;
}
/*打印主界面*/
void printMainPage(){
    system("cls");
    printf("==================================\n");
    printf("请选择你的身份:\n");
    printf("1.管理员\n");
    printf("2.教师\n");
    printf("3.学生\n");
    printf("==================================\n");
    printf("请输入合法的操作(1,2,3,q退出):\n");
}
/*主界面操作输入合法判断*/
char mainPageInputJudge(){
    char ch=(char)_getch();
    while(1){
        if(ch>='1'&&ch<='3'){
            return ch;
        }else if(ch=='q'){
            exit(0);
        }
        printf("请按要求输入!\n");
        ch=(char)_getch();
    }
}
/*管理员登陆界面*/
void printAdminPage(){
    system("cls");
    printf("==================================\n");
    printf("1. 修改自身登录密码\n");
    printf("2. 添加新教师\n");
    printf("3. 查看所有教师\n");
    printf("4. 删除教师\n");
    printf("5. 修改教师信息\n");
    printf("==================================\n");
    printf("请输入合法的操作(1-5,q退出):\n");
}
/*管理员界面输入合法性判断*/
char adminPageInputJudge(){
    char ch=(char)_getch();
    while(1){
        if((ch>='1'&&ch<='5')||ch=='q'){
            return ch;
        }
        printf("请按要求输入！\n");
        ch=(char)_getch();
    }
}
/*打印教师登陆界面*/
void printTeacherPage(){
    system("cls");
    printf("==================================\n");
    printf("1. 修改自身登录密码\n");
    printf("2. 查阅自身信息\n");
    printf("3. 添加新学生\n");
    printf("4. 删除学生\n");
    printf("5. 查阅指定学生信息\n");
    printf("6. 修改学生信息（姓名、性别、出生日期、三门功课成绩）\n");
    printf("7. 按学号从低到高查看所有学生信息\n");
    printf("8. 按总分从高到低查看所有学生信息\n");
    printf("==================================\n");
    printf("请输入合法的操作(1-8,q退出):\n");
}
/*教师登陆界面合法性判断*/
char teacherPageInputJudge(){
    do{
        char ch=(char)_getch();
        if((ch>='1'&&ch<='8')||ch=='q')
            return ch;
        printf("请输入合法的操作!\n");
    }while(1);
}
/*打印学生登陆界面*/
void printStudentPage(){
    system("cls");
    printf("==================================\n");
    printf("1. 修改自身登录密码\n");
    printf("2. 查阅自身信息\n");
    printf("==================================\n");
    printf("请输入合法的操作(1-2,q退出):\n");
}
/*学生登陆界面合法性判断*/
char studentPageInputPage(){
    do{
        char ch=(char)_getch();
        if((ch>='1'&&ch<='2')||ch=='q')
            return ch;
        printf("请输入合法的操作!\n");
    }while(1);
}
/*按键操作函数*/
char getOperation(){
    char ch;
    ch=(char)_getch();
    while(1){
        if(isalnum(ch)){
            return ch;
        }
        ch=(char)_getch();
    }
}
/*密码输入函数*/
int getPassword(char *pass){
    int len=0;
    char ch;
    printf("请输入密码\n");
    while((ch=(char)_getch())!='\r'&&len<=N-1){
        printf("*");
        pass[len]=ch;
        len++;
    }
    pass[len]='\0';
    return len;
}
/*输入密码判断函数*/
int judgePasword(char *targetPass){
    char pass[N];
    int timer=0;
    do{
        getPassword(pass);
        if(strcmp(pass,targetPass)==0){
            return 1;
        }
        printf("\n输入错误,请重新输入:");
        timer++;
    }while(timer<3);
    return -1;
}
/*获取姓名，最长不超过19个字符*/
void getName(char *name){
    printf("请输入姓名:\n");
    char str[N];
    char ch;
    do{
        if(scanf("%19s",str)==1){
            while((ch=(char)getchar())!='\n');
            strcpy(name,str);
            break;
        }
        printf("输入错误,请重新输入:\n");
    }while(1);
}
/*获取性别*/
void getGender(int *gender){
    printf("请选择性别:\n");
    printf("1.男\n2.女\n");
    char ch;
    while(1){
        ch=(char)_getch();
        if(ch=='1'){
            *gender=0;
            return;
        }
        if(ch=='2'){
            *gender=1;
            return;
        }
    }
}
/*判断是平年还是闰年*/
int isRun(int year){
    if((year%4==0&&year%100!=0)||year%400==0){
        return 1;
    }
    return 0;
}
/*获取出生日期*/
void getBirthDate(BirthDate *date){
    printf("请输入出生日期(年，月，日，以空格分隔开)\n");
    while(1){
        if(scanf("%d%d%d",&date->year,&date->month,&date->day)==3){
            if(date->year<=2000||date->year>2026){
                printf("请输入年份在合理区间里(2000-2026)\n");
                continue;
            }
            if(date->month<1||date->month>12){
                printf("请输入月份在合理区间里面(1-12)\n");
                continue;
            }
            if(isRun(date->year)){
                monthInyear[2]=29;
                if(date->day<1||date->day>monthInyear[date->month]){
                    printf("请输入合适天数\n");
                    continue;
                }
            }else{
                monthInyear[2]=28;
                if(date->day<1||date->day>monthInyear[date->month]){
                    printf("请输入合适天数\n");
                    continue;
                }
            }
        }
        break;
    }
}
/*获取浮点数*/
void getFloat(float *score,char *str){
    printf("请输入%s成绩\n",str);
    while(1){
        if(scanf("%f",score)==1){
            if(*score<0||*score>100){
                printf("成绩应该在1-100之间\n");
                continue;
            }
        }
        break;
    }
}
/*添加教师信息*/
Teacher inputTeacher(int *length){
    printf("请输入要添加的教师信息：\n");
    printf("工号自动分配\n");
    Teacher tea;
    tea.id=2026*100+*length;
    getName(tea.name);
    getPassword(tea.passWord);
    getGender(&tea.gender);
    getBirthDate(&tea.birth);
    return tea;
}
/*修改教师信息界面*/
char changeTeacherPage(){
    system("cls");
    printf("==================================\n");
    printf("1.修改姓名\n");
    printf("2.修改密码\n");
    printf("3.修改性别\n");
    printf("4.修改出生日期\n");
    printf("==================================\n");
    printf("请输入合法的操作数：\n");
    do{
        char ch=(char)_getch();
        if((ch>='1'&&ch<='2')||ch=='q')
            return ch;
        printf("请输入合法的操作!\n");
    }while(1);
}
/*修改教师信息*/
void changeTeacherByAdmin(TeaNode *t){
    printf("请输入教师工号：\n");
    int id;
    scanf("%d",&id);
    TeaNode *p=findNodeByID_t(t,id);
    if(p==NULL){
        printf("未找到\n");
        return;
    }
    while(1){
    char ch=changeTeacherPage();
        switch(ch){
            case '1':
            system("cls");
            char name[N];
            getName(name);
            strcpy(p->data.name,name);
            printf("修改成功\n");
            getchar();
            break;
            case '2':
            system("cls");
            char pass[N];
            getPassword(pass);
            strcpy(p->data.passWord,pass);
            printf("密码修改成功\n");
            getchar();
            break;
            case '3':
            system("cls");
            int gender;
            getGender(&gender);
            p->data.gender=gender;
            getchar();
            break;
            case '4':
            system("cls");
            BirthDate date;
            getBirthDate(&date);
            p->data.birth=date;
            getchar();
            break;
        }
        if(ch=='q')
            break;
    }
}
/*获取工号或者学号*/
void getID(int *id){
    while(1){
        if(scanf("%d",id)==1){
            if(*id<202600||*id>202699){
                printf("请重新输入!\n");
            }else{
                return;
            }
        }
    }
}
/*教师登陆验证,成功返回教师节点的指针，失败返回NULL*/
TeaNode *teacherLoginJudge(TeaNode *t){
    int id;
    char password[N];
    TeaNode *p;
    printf("请输入工号:");
    do{
        if(scanf("%d",&id)==1){
            if((p=findNodeByID_t(t,id))==NULL){
                printf("未找到\n");
                getchar();
                return NULL;
            }
            printf("请输入密码\n");
            if(judgePasword(p->data.passWord)==1){
                return p;
            }else{
                printf("密码输入错误三次\n");
                getchar();
                return NULL;
            }
        }
        printf("输入格式错误!\n");
        while(getchar()!='\n');
    }while(1);
}