#include "AdminModel.h"
#include <string.h>
#include <stdio.h>
/*修改管理员密码*/
int changePass_A(struct Admin *admin,char *password){
    strcpy(admin->password,password);
    return 0;
}
/*从文件中读取管理员信息*/
int loadAdminFromFile(Admin *a,const char *filename){
    if(a==NULL)
        return -1;
    FILE *fp=fopen(filename,"rb");
    if(fp==NULL){
        printf("open file error\n");
        return -1;
    }
    if(fread(a,sizeof(Admin),1,fp)==1)
        return 1;
    fclose(fp);
    fp=NULL;
    return -1;
}
/*将管理员信息保存到文件里面*/
int saveAdminToFile(Admin a,const char *filename){
    FILE *fp=fopen(filename,"wb");
    if(fp==NULL){
        printf("open file error\n");
        return -1;
    }
    fwrite(&a,sizeof(a),1,fp);
    fclose(fp);
    fp=NULL;
    return 1;
}