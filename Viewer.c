#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include "Viewer.h"
#include "Controller.h"
void flushInput() {
    while (getchar() != '\n');  // 一键清回车，超简单
}
/*闰年天数*/
int monthInyear[12]={31,28,31,30,31,30,31,31,30,31,30,31};
// /*创建一个栈*/
// OperationStack *createStack(){
//     OperationStack *s=(OperationStack *)malloc(sizeof(OperationStack));
//     if(s==NULL){
//         perror("stack malloc error\n");
//         return NULL;
//     }
//     s->top=-1;
//     return s;
// }
// /*判断栈是否为空*/
// int isEmpty(OperationStack *s){
//     return s->top==-1;
// }
// /*入栈*/
// int  pushStack(OperationStack *s, OperationData data){
//     if((s->top+1)==stackSize){
//         perror("栈已经满\n");
//         return -1;
//     }
//     s->top++;
//     s->data[s->top]=data;
//     return 1;
// }
// /*出栈*/
// OperationData popStack(OperationStack *s){
//     if(s->top==-1){
//         perror("栈为空\n");
//         return -1;
//     }
//     s->top--;
//     return s->data[s->top+1];
// }
// /*销毁栈*/
// void delStack(OperationStack *s){
//     free(s);
//     s=NULL;
// }
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
// /*按键操作函数*/
// char getOperation(){
//     char ch;
//     ch=(char)_getch();
//     while(1){
//         if(isalnum(ch)){
//             return ch;
//         }
//         ch=(char)_getch();
//     }
// }
/*密码输入函数*/
int getPassword(char *pass){
    int len=0;
    char ch;
    printf("请输入密码:");
    while((ch=(char)_getch())!='\r'&&len<=N-1){
        if(ch=='\b'&&len>0){
            printf("\b \b");
            len--;
            pass[len]='\0';
        }else if(ch!='\b'){
        printf("*");
        pass[len]=ch;
        len++;
        }
    }
    pass[len]='\0';
    printf("\n");
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
    // char ch;
    do{
        int judge=scanf("%19s",str);
        flushInput();
        if(judge==1){
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
        int judge=scanf("%d%d%d",&date->year,&date->month,&date->day);
        flushInput();
        if(judge==3){
            if(date->year<2000||date->year>2026){
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
        int judge=scanf("%f",score);
        flushInput();
        if(judge==1){
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
    (*length)++;
    getName(tea.name);
    getPassword(tea.passWord);
    getGender(&tea.gender);
    getBirthDate(&tea.birth);
    return tea;
}
/*修改教师信息界面*/
char changeTeacherPage(){
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
    printAllNode_t(t);
    printf("请输入教师工号：");
    int id;
    scanf("%d",&id);
    flushInput();
    TeaNode *p=findNodeByID_t(t,id);
    if(p==NULL){
        printf("未找到\n");
        return;
    }
    while(1){
        printOneNode_t(p);
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
// void getID(int *id){
//     while(1){
//         if(scanf("%d",id)==1){
//             if(*id<202600||*id>202699){
//                 printf("请重新输入!\n");
//             }else{
//                 return;
//             }
//         }
//     }
// }
/*教师登陆验证,成功返回教师节点的指针，失败返回NULL*/
TeaNode *teacherLoginJudge(TeaNode *t){
    int id;
    // char password[N];
    TeaNode *p;
    printf("请输入工号:");
    do{
        int judge=scanf("%d",&id);
        flushInput();
        if(judge==1){
            if((p=findNodeByID_t(t,id))==NULL){
                printf("未找到\n");
                getchar();
                return NULL;
            }
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
/*打印单个教师节点*/
void printOneNode_t(TeaNode *t){
    system("cls");
    printf("============================================================\n");
    printf("%-8s%-20s%-4s%-12s%-20s\n","工号","姓名","性别","出生日期","密码");
    printf("%-8d",t->data.id);
    printf("%-20s",t->data.name);
    if(t->data.gender==0){
        printf("%-4s","男");
    }else{
        printf("%-4s","女");
    }
    printf("%4d-%02d-%02d",t->data.birth.year,t->data.birth.month,t->data.birth.day);
    printf("%-20s\n",t->data.passWord);
    printf("============================================================\n");
    getchar();
}
/*打印所有教师节点*/
void printAllNode_t(TeaNode *t){
    system("cls");
    printf("============================================================\n");
    printf("%-8s%-20s%-4s%-12s%-20s\n","工号","姓名","性别","出生日期","密码");
    while(t->next!=NULL){
        t=t->next;
    printf("%-8d",t->data.id);
    printf("%-20s",t->data.name);
    if(t->data.gender==0){
        printf("%-4s","男");
    }else{
        printf("%-4s","女");
    }
    printf("%4d-%02d-%02d",t->data.birth.year,t->data.birth.month,t->data.birth.day);
    printf("  ");
    printf("%-20s\n",t->data.passWord);
}
    printf("============================================================\n");
    _getch();
}
/*打印单个学生节点信息*/
void printOneNode_s(StuNode *s){
    system("cls");
    printf("========================================================================\n");
    printf("%-10s%-20s%-4s%-10s%-20s%-4s%-4s%-4s\n","学号","姓名","性别","出生日期","密码","语文","数学","英语");
    printf("%-10d",s->data.id);
    printf("%-20s",s->data.name);
    if(s->data.gender==0){
        printf("%-4s","男");
    }else{
        printf("%-4s","女");
    }
    printf("%4d-%02d-%02d",s->data.date.year,s->data.date.month,s->data.date.day);
    printf("%-20s",s->data.password);
    printf("%4.1f",s->data.chinese);
    printf("%4.1f",s->data.math);
    printf("%4.1f\n",s->data.english);
    printf("========================================================================\n");
    getchar();
}
/*打印所有学生节点信息*/
void printAllNode_s(StuNode *s){
    system("cls");
    printf("========================================================================\n");
    printf("%-10s%-20s%-4s%-12s%-20s%-4s%-4s%-4s\n","学号","姓名","性别","出生日期","密码","语文","数学","英语");
    while(s->next!=NULL){
        s=s->next;
    printf("%-10d",s->data.id);
    printf("%-20s",s->data.name);
    if(s->data.gender==0){
        printf("%-4s","男");
    }else{
        printf("%-4s","女");
    }
    printf("%4d-%02d-%02d  ",s->data.date.year,s->data.date.month,s->data.date.day);
    printf("%-20s",s->data.password);
    printf("%4.1f",s->data.chinese);
    printf("%4.1f",s->data.math);
    printf("%4.1f\n",s->data.english);
    }
    printf("========================================================================\n");
    _getch();
}
/*添加新学生*/
void addNewStudent(StuNode *s,int *length){
    printf("现有学生\n");
    printAllNode_s(s);
    Stu stu;
    printf("请输入要添加的学生信息\n");
    printf("学号自动分配\n");
    stu.id=2026*10000+*length;
    (*length)++;
    getName(stu.name);
    getGender(&stu.gender);
    getBirthDate(&stu.date);
    getPassword(stu.password);
    getFloat(&stu.chinese,"语文");
    getFloat(&stu.math,"数学");
    getFloat(&stu.english,"英语");
    (*length)++;
    insertNodeInTail_s(s,stu);
}
void printOneStudentByID(StuNode *s){
    system("cls");
    printf("需要输入学号");
    int id;
    while(1){
        scanf("%d",&id);
        flushInput();
        StuNode *p=findNodeByID_s(s,id);
        if(s==NULL){
            printf("未找到\n");
            getchar();
            return;
        }
        printOneNode_s(p);
        break;
    }
}
/*修改学生信息界面及操作*/
char changeStudentPage(){
    system("cls");
    printf("==================================\n");
    printf("1.修改姓名\n");
    printf("2.修改密码\n");
    printf("3.修改性别\n");
    printf("4.修改出生日期\n");
    printf("5.修改语文成绩\n");
    printf("6.修改数学成绩\n");
    printf("7.修改英语成绩\n");
    printf("==================================\n");
    printf("请输入合法的操作数：\n");
    do{
        char ch=(char)_getch();
        if((ch>='1'&&ch<='7')||ch=='q')
            return ch;
        printf("请输入合法的操作!\n");
    }while(1);
}
/*修改学生信息*/
void changeStudentByTeacher(StuNode *s){
    printf("请输入学生的学号:\n");
    int id;
    scanf("%d",&id);
    flushInput();
    while(getchar()!='\n');
    StuNode *p=findNodeByID_s(s,id);
    if(p==NULL){
        printf("未找到\n");
        return;
    }
    while(1){
        char ch=changeStudentPage();
        switch(ch){
        case '1':
        system("cls") ;
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
        strcpy(p->data.password,pass);
        printf("修改成功\n");
        getchar();
        break;
        case '3':
        system("cls");
        int gender;
        getGender(&gender);
        p->data.gender=gender;
        printf("修改成功\n");
        getchar();
        break;
        case '4':
        system("cls");
        BirthDate date;
        getBirthDate(&date);
        p->data.date=date;
        printf("修改成功\n");
        getchar();
        break;
        case '5':
        system("cls");
        float c;
        getFloat(&c,"语文");
        p->data.chinese=c;
        printf("修改成功\n");
        getchar();
        break;
        case '6':
        system("cls");
        float m;
        getFloat(&m,"数学");
        p->data.math=m;
        printf("修改成功\n");
        getchar();
        break;
        case '7':{
        float e;
        getFloat(&e,"英语");
        p->data.english=e;
        printf("修改成功\n");
        getchar();
        }
        break;
        }
        if(ch=='q'){
            break;
        }
    }
}
/*按学号打印输出信息*/
void printStudentByID(StuNode *s,int length){
    Stu stuarray[length];
    for(int i=0;i<length;i++){
        s=s->next;
        stuarray[i]=s->data;
    }
    /*排序*/
    int lable=0;
    Stu temp;
    for(int i=0;i<length-1;i++){
        lable=0;
        for(int j=0;j<length-i-1;j++){
            if(stuarray[j].id>stuarray[j+1].id){
                temp=stuarray[j];
                stuarray[j]=stuarray[j+1];
                stuarray[j+1]=temp;
                lable=1;
            }
        }
        if(lable==0)
            break;
    }
    system("cls");
    printf("==============================================================================\n");
    printf("%-6s%-20s%-4s%-12s%-20s%-4s%-4s%-4s\n","学号","姓名","性别","出生日期","密码","语文","数学","英语");
    for(int i=0;i<length;i++){
    printf("%-6d",stuarray[i].id);
    printf("%-20s",stuarray[i].name);
    if(stuarray[i].gender==0){
        printf("%-4s","男");
    }else{
        printf("%-4s","女");
    }
    printf("%4d-%02d-%02d  ",stuarray[i].date.year,stuarray[i].date.month,stuarray[i].date.day);
    printf("%-20s",stuarray[i].password);
    printf("%4.1f",stuarray[i].chinese);
    printf("%4.1f",stuarray[i].math);
    printf("%4.1f\n",stuarray[i].english);
    }
    printf("==============================================================================\n");
    getchar();
}
/*按总分从高到低查看所有学生信息*/
void printStudentByScore(StuNode *s,int length){
    Stu stuarray[length];
    for(int i=0;i<length;i++){
        s=s->next;
        stuarray[i]=s->data;
    }
    /*排序*/
    int lable=0;
    Stu temp;
    float sum1=0;
    float sum2=0;
    for(int i=0;i<length-1;i++){
        lable=0;
        for(int j=0;j<length-i-1;j++){
            sum1=stuarray[j].chinese+stuarray[j].math+stuarray[j].english;
            sum2=stuarray[j+1].chinese+stuarray[j+1].math+stuarray[j+1].english;
            if(sum1>sum2){
                temp=stuarray[j];
                stuarray[j]=stuarray[j+1];
                stuarray[j+1]=temp;
                lable=1;
            }
        }
        if(lable==0)
            break;
    }
    system("cls");
    printf("========================================================================================\n");
    printf("%-6s%-20s%-4s%-12s%-20s%-4s%-4s%-4s%-4s\n","学号","姓名","性别","出生日期","密码","语文","数学","英语","总分");
    for(int i=length-1;i>=0;i--){
    printf("%-6d",stuarray[i].id);
    printf("%-20s",stuarray[i].name);
    if(stuarray[i].gender==0){
        printf("%-4s","男");
    }else{
        printf("%-4s","女");
    }
    printf("%4d-%02d-%02d  ",stuarray[i].date.year,stuarray[i].date.month,stuarray[i].date.day);
    printf("%-20s",stuarray[i].password);
    printf("%4.1f",stuarray[i].chinese);
    printf("%4.1f",stuarray[i].math);
    printf("%4.1f",stuarray[i].english);
    printf("%4.1f\n",stuarray[i].chinese+stuarray[i].math+stuarray[i].english);
    }
    printf("========================================================================================\n");
    getchar();
}
/*学生登陆验证*/
StuNode *studentLoginJudge(StuNode *s){
    int id;
    StuNode *p;
    printf("请输入工号:");
    do{
        int judge=scanf("%d",&id);
        flushInput();
        if(judge==1){
            if((p=findNodeByID_s(s,id))==NULL){
                printf("未找到\n");
                getchar();
                return NULL;
            }
            if(judgePasword(p->data.password)==1){
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