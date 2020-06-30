#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define STUDENTLENGTH 100000

void  pressKey(   );     /*  ����������� */
void aboutUs();    /*  �������� */
int  logout();    /* ����0��ʾ�˳�������1��ʾ���� */
void adminLogin();   /*  ����Ա��¼ */
void adminMenu();    /*  ����Ա �˵�*/
void showAll();        /* ��ʾ ����ͼ�� */

void addBook();   /*  ����鼮 */

void addStudent();   /*  ���ѧ�� */



//��ʾ�鼮����Ϣ
struct Book{
	int  bno;
	char   bname[10];
	double   price;
	char  author[10];
};
//��ʾѧ������Ϣ
struct Student{
	int  sno;
	char   sname[50];
	char  *spwd;
};

struct Student students[STUDENTLENGTH];
int studentIndex=0;   //ѧ��������




char username[10]="admin";
char pwd[10]="aaaaaa";
struct Book  books[100];   //�ṹ������     ��   �ṹ���� ������[����];
int bookIndex=0;      //�鼮������  Ҳ���Ա�ʾ�ܹ��ж��ٱ���


int main(){
    int flag=1;
    do{
        system("cls");     // system(char *command);
        printf("\n********************\n");
        printf("\n���Ϲ�ѧԺͼ�����ϵͳ\n");
        printf("\t1.����Ա��¼\n");
        printf("\t2.ѧ����¼\n");
        printf("\t3.��������\n");
        printf("\t4.�˳�\n");
        printf("\n********************\n");
        printf("\n������˵�ѡ�1��2��3��4��\n");
        char choice;       //  int ch ;  Ϊʲô ����  int.
        //input
        //switch( ch )
        //getchar();    //    ����̻س�������

        scanf("%c",&choice);   // '1'  ne 1
        fflush(   stdin );
        switch( choice ){
            case '1': adminLogin(); getchar();break;
            case '2': printf("ѧ����¼");break;
            case '3': aboutUs(); pressKey(); break;
            case '4':   flag=logout();    break;
            default: printf("û�����ѡ��"); pressKey();
        }
    }while(  flag );
    printf("\n���������˳���������\n");
    return 0;
}

void adminMenu(){
    int flag=1;
    do{
        system("cls");     // system(char *command);
        printf("\n*********ͼ�����ϵͳ��̨����***********\n");
        printf("\t1. ͼ�����\n");
        printf("\t2.��ѯͼ��\n");
        printf("\t3.�û�ע��\n");
        printf("\t4.��ѯ�û�\n");
        printf("\t5.�˳�����\n");
        printf("\n********************\n");
        printf("\n������˵�ѡ�1��2��3��4��5��\n");
        char choice;       //  int ch ;  Ϊʲô ����  int.
        scanf("%c",&choice);   // '1'  ne 1
        fflush(   stdin );
        switch( choice ){
            case '1': addBook(); pressKey();break;
            case '2': showAll(); pressKey();  break;
            case '3':  addStudent(); pressKey(); break;
            case '4':  pressKey();   break;
            case '5':   flag=0;    break;
            default: printf("û�����ѡ��"); pressKey();
        }
    }while(  flag );
}

void addStudent(){
    //1. ��¼ѧ��������  studentIndex
    int i=1;
    char flag='y';
    int sno;
    //ѭ������   int  %d     %lf  double     %s  ����ȡ��ַ
    do{
        system("cls");
        printf("\n¼���%dѧ��\n",i);
        //1. bno �������λ��
        time_t t;
        srand((unsigned) time(&t));
        //printf("%d\n", rand() % 1000000);
        sno=rand() % STUDENTLENGTH;
        //TODO: sno�����ظ�
        students[  studentIndex  ].sno=sno;

        printf("\n������ѧ����:\n");
        //2. bname ��������      %s
        scanf("%s",   students[studentIndex].sname    );
        fflush(stdin);
        //2. Ĭ������
        students[studentIndex].spwd="a";    //TODO:    md5   sha   -> ����


        //�������
        printf("\n������û���ϢΪ:\n");   //   10.00
        printf("\n%d\t%s\n", students[studentIndex].sno,  students[studentIndex].sname );

        printf("�Ƿ����¼����һλ(y for yes, others for no): ");
        scanf("%c",&flag);
        fflush( stdin );
        i++;
        studentIndex++;
    }while(    flag=='y'||flag=='Y'  );
    //ͳ�� ���ܣ� �ܹ��ж����飬 ���������˶�����
    printf("\n����¼��%d��ѧ��,����%dλѧ��\n",i-1,studentIndex);
    pressKey();
}

void showAll(){
    system("cls");
    if(  bookIndex==0 ){
        printf("\nϵͳ�����κ�ͼ�顣\n");
        return;
    }
    printf("\n============��ʾ���е�ͼ��=============\n");
    printf("\n���\t����\t�۸�\t����\n");
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
    printf("\n����%d����,�ܼ�%10.2lf,���ۣ�%10.2lf\n",bookIndex);
}

void addBook(){
    //1. ��¼�������  bookIndex
    int i=1;
    char flag='y';
    int bno;
    //ѭ������   int  %d     %lf  double     %s  ����ȡ��ַ
    do{
        system("cls");
        printf("\n¼���%d����\n",i);
        //1. bno �������λ��
        time_t t;
        srand((unsigned) time(&t));
        //printf("%d\n", rand() % 1000000);
        books[  bookIndex  ].bno=rand() % 1000000;
        printf("\n����������:\n");
        //2. bname ��������      %s
        scanf("%s",   books[bookIndex].bname    );    //TODO�� char   bname[10];    ����������������׵�ַ     scanf¼�� %s ���Կո�ָ��ַ���������
        fflush(stdin);
        //3. price �۸�   %lf
        printf("\n�������鼮�۸�:\n");
        scanf("%lf",     &books[bookIndex].price );

        //4. author ����   %s
        printf("\n�������鼮����:\n");
        scanf("%s",     &books[bookIndex].author );

        //�������
        printf("\n������鼮��ϢΪ:\n");   //   10.00
        printf("\n%d\t%s\t|%5.2lf\t%s\n", books[bookIndex].bno,  books[bookIndex].bname, books[bookIndex].price, books[bookIndex].author  );


        printf("�Ƿ����¼����һ����(y for yes, others for no): ");
        scanf("%c",&flag);
        fflush( stdin );
        i++;
        bookIndex++;
    }while(    flag=='y'||flag=='Y'  );
    //ͳ�� ���ܣ� �ܹ��ж����飬 ���������˶�����
    printf("\n����¼��%d����,����%d����\n",i-1,bookIndex);
    pressKey();

}



// �������ε�¼������Ӧ����ʾ
void adminLogin(){
    char inputName[10];
    char inputPwd[10];
    int i=1;
    do{
        printf("\n���������Ա����:");
        scanf("%s",inputName);
         printf("\n���������Ա����:");
        scanf("%s",inputPwd);
        fflush( stdin );
        // compare strings
        if(  !strcmp( username,inputName)  &&  !strcmp( pwd,inputPwd )  ){
            printf("\n��¼�ɹ�...\n");
            pressKey();
            adminMenu();
            break;    //  return;
        }else{
            printf("\n�û�����������󣬵�%d�ε�¼ʧ��...\n",i);
            printf("\n������%d�λ��ᣬ��������ϧ...\n",(3-i) );
            pressKey();
        }
        i++;
    }while(  i<=3  );
}

int logout(){
    //1.ask to exit
    char choice;
    int i;
    printf("�Ƿ�ȷ���˳�?(y for yes)\n");
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
    printf("���ϻʼҹ�ѧԺͼ�����ϵͳ\n\n");
    Sleep(2000);
    printf("�汾��V1.0\n\n");
    Sleep(2000);
    printf("��ӭ����BUG������\n\n");
    Sleep(2000);
    printf("=======================================\n\n");
}



void pressKey(){
	printf("\n�����������....\n");
    getchar();
}
