#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define STUDENTLENGTH 100000

void  pressKey(   );     /*  按任意键继续 */
void aboutUs();    /*  关于我们 */
int  logout();    /* 返回0表示退出，返回1表示继续 */
void adminLogin();   /*  管理员登录 */
void adminMenu();    /*  管理员 菜单*/
void showAll();        /* 显示 所有图书 */

void addBook();   /*  添加书籍 */

void addStudent();   /*  添加学生 */
void showStudent();  /*   标识符：字母，数字，下划线   */
void saveAndexit();   /*  退出管理界面且保存 */
void initSys();   /* 系统初始化 */



//表示书籍的信息
struct Book{
	int  bno;
	char   bname[10];
	double   price;
	char  author[10];
};
//表示学生的信息
struct Student{
	int  sno;
	char   sname[50];
	char  *spwd;
};


//
struct Student students[STUDENTLENGTH];
int studentIndex=0;   //学生的索引

char username[10]="admin";
char pwd[10]="aaaaaa";
struct Book  books[100];   //结构体数组     ：   结构体名 数组名[长度];
int bookIndex=0;      //书籍的索引  也可以表示总共有多少本书


int main(){
    int flag=1;

    initSys();

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
            case '1': adminLogin(); getchar();break;
            case '2': printf("学生登录");break;
            case '3': aboutUs(); pressKey(); break;
            case '4':   flag=logout();    break;
            default: printf("没有这个选项"); pressKey();
        }
    }while(  flag );
    printf("\n程序正常退出。。。。\n");
    return 0;
}

void initSys(){
     system("cls");
     printf("=========================\n");
     printf("系统初始化.....\n");
     Sleep( 500 );

    FILE *fp;
    if((fp=fopen("books.dat","rt"))==NULL){
        printf("暂无books.dat!\n");
        getch();
    }
    int  i= fread(  books,sizeof(struct Book),100,fp);   //100表示最多从文件 中读取多少个struct Book, 实际读取了  i  .
    //printf(  "读到了%d条book数据\n",i);
    bookIndex=i;
    fclose(  fp );

    if((fp=fopen("students.dat","rt"))==NULL){
        printf("暂无students.dat!\n");
        getch();
    }
    i= fread(  students,sizeof(struct Student),STUDENTLENGTH,fp);
    //printf(  "读到了%d条学生数据\n",i);
    studentIndex=i;
    fclose(  fp );

    //pressKey();
}


void adminMenu(){
    int flag=1;
    do{
        system("cls");     // system(char *command);
        printf("\n*********图书管理系统后台管理***********\n");
        printf("\t1. 图书入库\n");
        printf("\t2.查询图书\n");
        printf("\t3.用户注册\n");
        printf("\t4.查询用户\n");
        printf("\t5.退出管理\n");
        printf("\n********************\n");
        printf("\n请输入菜单选项（1，2，3，4，5）\n");
        char choice;       //  int ch ;  为什么 不用  int.
        scanf("%c",&choice);   // '1'  ne 1
        fflush(   stdin );
        switch( choice ){
            case '1': addBook(); pressKey();break;
            case '2': showAll(); pressKey();  break;
            case '3':  addStudent(); pressKey(); break;
            case '4':  showStudent();  pressKey();   break;
            case '5':   saveAndexit(); flag=0;    break;
            default: printf("没有这个选项"); pressKey();
        }
    }while(  flag );
}


//请自已加入学生信息的保存
void saveAndexit(){
    FILE *fp;

    //1.先保存书，     books.dat     txt     w
    if((fp=fopen("books.dat","wt"))==NULL){
        printf("保存书籍数据失败。。");
        getch();
    }
    //struct Book 求一个结构体元素的大小   字节
    //printf("\n一个 struct book的大小为%d\n", sizeof( struct Book ) );
    fwrite(  books,sizeof(struct Book),bookIndex,fp);
    fclose(  fp );
    printf("\n保存%d条书籍数据到  books.dat成功\n",bookIndex);

    if(  (fp=fopen("students.dat","wt"))==NULL  ){
        printf("保存学生数据文件失败。。");
        getch();
    }
    fwrite(  students,sizeof(struct Student),studentIndex,fp);
    fclose( fp );
    printf("\n保存%d条学生信息数据到 students.txt成功\n",studentIndex);

    pressKey();
}


void showStudent(){
    system("cls");
    if(  studentIndex==0 ){
        printf("\n系统暂无任何学员。\n");
        return;
    }
    printf("\n============显示所有的学员=============\n");
    printf("\n编号\t学生名\n");
    int i=0;
    for(i=0;i<studentIndex;i++){
        struct Student b=students[i];
        printf("\n%d\t%s\n",  b.sno,b.sname  );
    }
    printf("\n=======================================\n");
    printf("\n共有%d人\n",studentIndex);
}

void addStudent(){
    //1. 记录学生的数量  studentIndex
    int i=1;
    char flag='y';
    int sno;
    //循环输入   int  %d     %lf  double     %s  不能取地址
    do{
        system("cls");
        printf("\n录入第%d学生\n",i);
        //1. bno 随机的六位数
        time_t t;
        srand((unsigned) time(&t));
        //printf("%d\n", rand() % 1000000);
        sno=rand() % STUDENTLENGTH;
        //TODO: sno不能重复
        students[  studentIndex  ].sno=sno;

        printf("\n请输入学生名:\n");
        //2. bname 输入书名      %s
        scanf("%s",   students[studentIndex].sname    );
        fflush(stdin);
        //2. 默认密码
        students[studentIndex].spwd="a";    //TODO:    md5   sha   -> 加盐


        //汇总输出
        printf("\n输入的用户信息为:\n");   //   10.00
        printf("\n%d\t%s\n", students[studentIndex].sno,  students[studentIndex].sname );

        printf("是否继续录入下一位(y for yes, others for no): ");
        scanf("%c",&flag);
        fflush( stdin );
        i++;
        studentIndex++;
    }while(    flag=='y'||flag=='Y'  );
    //统计 功能： 总共有多少书， 本次新增了多少书
    printf("\n本次录入%d个学生,共有%d位学生\n",i-1,studentIndex);
    pressKey();


}

void showAll(){
    system("cls");
    if(  bookIndex==0 ){
        printf("\n系统暂无任何图书。\n");
        return;
    }
    printf("\n============显示所有的图书=============\n");
    printf("\n编号\t书名\t价格\t作者\n");
    int i=0;
    double total=0.0;
    double meanPrice=0.0;
    for(i=0;i<bookIndex;i++){
        struct Book b=books[i];
        printf("\n%d\t%s\t%5.2lf\t%s\n",  b.bno, b.bname,b.price,b.author );
        total+= b.price;
    }
    meanPrice=total/bookIndex;
    printf("\n=======================================\n");
    printf("\n共有%d本书,总价%10.2lf,均价：%10.2lf\n",bookIndex,total, meanPrice);
}

void addBook(){
    //1. 记录书的数量  bookIndex
    int i=1;
    char flag='y';
    int bno;
    //循环输入   int  %d     %lf  double     %s  不能取地址
    do{
        system("cls");
        printf("\n录入第%d本书\n",i);
        //1. bno 随机的六位数
        time_t t;
        srand((unsigned) time(&t));
        //printf("%d\n", rand() % 1000000);
        books[  bookIndex  ].bno=rand() % 1000000;
        printf("\n请输入书名:\n");
        //2. bname 输入书名      %s
        scanf("%s",   books[bookIndex].bname    );    //TODO： char   bname[10];    数组名就是数组的首地址     scanf录入 %s 是以空格分隔字符？？？？
        fflush(stdin);
        //3. price 价格   %lf
        printf("\n请输入书籍价格:\n");
        scanf("%lf",     &books[bookIndex].price );

        //4. author 作者   %s
        printf("\n请输入书籍作者:\n");
        scanf("%s",     &books[bookIndex].author );
        fflush(stdin );

        //汇总输出
        printf("\n输入的书籍信息为:\n");   //   10.00
        printf("\n%d\t%s\t|%5.2lf\t%s\n", books[bookIndex].bno,  books[bookIndex].bname, books[bookIndex].price, books[bookIndex].author  );


        printf("是否继续录入下一本书(y for yes, others for no): ");
        scanf("%c",&flag);
        fflush( stdin );
        i++;
        bookIndex++;
    }while(    flag=='y'||flag=='Y'  );
    //统计 功能： 总共有多少书， 本次新增了多少书
    printf("\n本次录入%d本书,共有%d本书\n",i-1,bookIndex);



    pressKey();

}



// 至多三次登录，有相应的提示
void adminLogin(){
    char inputName[10];
    char inputPwd[10];
    int i=1;
    do{
        printf("\n请输入管理员名字:");
        scanf("%s",inputName);
         printf("\n请输入管理员密码:");
        scanf("%s",inputPwd);
        fflush( stdin );
        // compare strings
        if(  !strcmp( username,inputName)  &&  !strcmp( pwd,inputPwd )  ){
            printf("\n登录成功...\n");
            pressKey();
            adminMenu();
            break;    //  return;
        }else{
            printf("\n用户名或密码错误，第%d次登录失败...\n",i);
            printf("\n您还有%d次机会，且行且珍惜...\n",(3-i) );
            pressKey();
        }
        i++;
    }while(  i<=3  );
}

int logout(){
    //1.ask to exit
    char choice;
    int i;
    printf("是否确定退出?(y for yes)\n");
    //2. input your choice
    scanf("%c",&choice);
    fflush( stdin );
    //3. y-> return 0,     n-> return 1
    if(  choice!='y'   ){
        return 1;
    }
    for( i=0;i<10;i++ ){
        printf("\7==");    //   \7
        Sleep( 500  );
    }
    printf("\n");
    return 0;
}

void aboutUs(){
    system("cls");
    printf("=======================================\n\n");
    Sleep(2000);
    printf("湖南皇家工学院图书管理系统\n\n");
    Sleep(2000);
    printf("版本：V1.0\n\n");
    Sleep(2000);
    printf("欢迎来找BUG。。。\n\n");
    Sleep(2000);
    printf("=======================================\n\n");
}



void pressKey(){
	printf("\n按任意键继续....\n");
    getchar();
}
