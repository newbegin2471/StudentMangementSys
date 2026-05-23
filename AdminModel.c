#include "AdminModel.h"
#include <string.h>
/*修改管理员密码*/
int changePass_A(struct Admin *admin,char *password){
    strcpy(admin->password,password);
    return 0;
}