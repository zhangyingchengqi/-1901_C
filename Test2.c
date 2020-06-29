#include <stdio.h>

int main(){
    do{
        system("cls");     // system(char *command);
        printf("\n********************\n");
        printf("\n湖南工学院图书管理系统\n");
        printf("\t1.管理员登录\n");
        printf("\t2.学生登录\n");
        printf("\t3.关于我们\n");
        printf("\t4.退出\n");
        printf("\n********************\n");
        printf("\n请输入菜单选项（1，2，3，4）\n");

        char choice;       //  int ch ;  为什么 不用  int.
        //input
        //switch( ch )
        //getchar();    //    解决吞回车的问题

        scanf("%c",&choice);   // '1'  ne 1
        fflush(   stdin );
        switch( choice ){
            case '1': printf("管理员登录"); getchar();break;
            case '2': printf("学生登录");break;
            case '3': printf("关于我们");break;
            case '4': printf("退出系统");break;
            default: printf("没有这个选项"); printf("按任意键继续"); getchar();
        }
    }while(  1 );


    return 0;
}
