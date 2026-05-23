#ifndef _ADMINMODEL_H_
#define _ADMINMODEL_H_
typedef struct Admin{
    char name[20];
    char password[20];
}Admin;
/*从文件中读取管理员信息*/
int loadAdminFromFile(Admin *a,const char *filename);
/*将管理员信息保存到文件里面*/
int saveAdminToFile(Admin a,const char *filename);
/*修改管理员密码*/
int changePass_A(struct Admin *admin,char *password);
#endif
