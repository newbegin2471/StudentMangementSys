#ifndef _ADMINMODEL_H_
#define _ADMINMODEL_H_
struct Admin{
    char name[20];
    char password[20];
};
/*修改管理员密码*/
int changePass_A(struct Admin *admin,char *password);
#endif
