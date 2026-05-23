#include "Viewer.h"
#include "TeacherModel.h"
#include "StudentModel.h"
#include <stdio.h>
int main(){
    /**********************************链表测试 *************************** */
    //创建空教师链表
    // TeaNode *t=createLinkList_t();
    // // Teacher test={"123456","123456",1,1,{2002,10,13}};
    // insertNodeInTail_t(t,(Teacher){"123456","123456",1,1,{2002,10,13}});
    // insertNodeInTail_t(t,(Teacher){"123456","123456",2,1,{2002,10,13}});
    // insertNodeInTail_t(t,(Teacher){"123456","123456",3,1,{2002,10,13}});
    // insertNodeInTail_t(t,(Teacher){"123456","123456",4,1,{2002,10,13}});
    // saveTeacherToFile(t,"teacher.txt");
    // TeaNode *t1=createLinkList_t();
    // loadTeacherFromFile(t1,"teacher.txt");
    // travelLinkList_t(t1);
    // // printf("%s\n",test.name);
    // travelLinkList_t(t);
    // /*销毁一个指定节点*/
    // delNode_t(t,2);
    // travelLinkList_t(t);
    // printf("***********\n");
    // insertNodeInTail_t(t,(Teacher){"234","234",2,1,{2002,10,13}});
    // travelLinkList_t(t);
    // delLinkList_t(t);
    /********************************************************************* */
    /***************************学生链表测试****************************** */
    StuNode *s=newLinkList_s();
    insertNodeInHead_s(s,(Stu){"123456","123456",1,1,{2002,10,13},100,100,100});
    insertNodeInTail_s(s,(Stu){"123456","123456",2,1,{2002,10,13},100,100,100});
    insertNodeInTail_s(s,(Stu){"123456","123456",3,1,{2002,10,13},100,100,100});
    insertNodeInTail_s(s,(Stu){"123456","123456",4,1,{2002,10,13},100,100,100});
    saveStudentToFile(s,"student.txt");
    StuNode *s1=newLinkList_s();
    loadStudentFromFile(s1,"student.txt");
    travelLinkList_s(s1);
    // travelList_s(s);
    // delNode_s(s,2);
    // travelList_s(s);
    // delLinkList_s(s);
    /*********************************************************************** */
    return 0;
}