#include <stdio.h>

int main(){
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
            case '1': printf("����Ա��¼"); getchar();break;
            case '2': printf("ѧ����¼");break;
            case '3': printf("��������");break;
            case '4': printf("�˳�ϵͳ");break;
            default: printf("û�����ѡ��"); printf("�����������"); getchar();
        }
    }while(  1 );


    return 0;
}
