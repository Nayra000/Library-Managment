#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include"linkedlist.h"
#define admin_pass 1234

//Note : only admin who make a reservation or make a book available
//The password of admin is 1234
//when you add a new user , be careful of the upper or lower alphabets of the name of the books for example enter 'Non' not 'non'
void mode(){
      char x;int y,z,user_password;
    printf("Enter 1 if you are an admin 2 if you are a user \n");
    scanf("%d",&x);
    printf("-----------------------------------------------------------------\n");
 switch(x){
     case 1:
        printf("Enter the password please \n");
        scanf("%d",&y);
        if(y!=admin_pass){
            printf("Incorrect password \n");
            printf("Enter any key to clear the screen\n");
            getch();
            system("cls");
           mode();
        }
        else{
            label:
        printf("Enter 1: to view all users data\n");
        printf("Enter 2: to add a new user\n");
        printf("Enter 3: to make a reservation\n");
        printf("Enter 4: to make a reserved book available\n");
        printf("Enter 5: to view all books details\n");
        printf("Enter 6: to back\n");
        scanf("%d",&z);
        printf("*************************************\n");
        printf("\n");
        switch(z){
        case 1:
            show_all_users_details();
            printf("Enter any key to clear the screen\n");
            getch();
            system("cls");
               goto label;
            break;
        case 2:
            add_user();
            printf("Enter any key to clear the screen\n");
            getch();
            system("cls");
             goto label;
            break;
        case 3:
            show_books_available();
            make_notavalible();
            printf("Enter any key to clear the screen\n");
            getch();
            system("cls");
               goto label;
            break;
        case 4:
            show_borrowed_books();
            make_avalible();
            printf("Enter any key to clear the screen\n");
            getch();
            system("cls");
               goto label;
            break;
        case 5:
            show_books_details();
            printf("Enter any key to clear the screen\n");
            getch();
            system("cls");
              goto label;
        case 6:
            printf("Enter any key to clear the screen\n");
            getch();
            system("cls");
       mode();
            break;
        }
        }
        break;
        case 2:
          printf("Enter a password please\n");
          scanf("%d",&user_password);
          printf("*************************************\n");
          int w=login_user(user_password);
          switch(w){
               label2:
          case 1:
           printf("*************************************\n");
           printf("Enter 1: to view all books\n");
           printf("Enter 2: to view all books available to borrow\n");
           printf("Enter 3: to view all borrowed books\n");
           printf("Enter 4: to back\n");
           scanf("%d",&w);
           switch(w){
           case 1:
             show_books_details();
             printf("Enter any key to clear the screen\n");
              getch();
            system("cls");
             goto label2;
             break;
           case 2:
            show_books_available();
            printf("Enter any key to clear the screen\n");
            getch();
            system("cls");
            goto label2;
            break;
           case 3:
            show_borrowed_books();
            printf("Enter any key to clear the screen\n");
             getch();
            system("cls");
            goto label2;
            break;
           case 4:
           mode();
            break;
           }
            break;
          case 0:
            printf("Incorrect password\n");
              printf("Enter any key to clear the screen\n");
             getch();
            system("cls");
           mode();
            break;
          }
            break;
     }
}
 int main()
{

//Initial values
    append_user_node("Hager",10,111,"Math 1");
    append_user_node("Ali",11,222,"Logic");
    append_user_node("Mohamed",12,333,"Non");
    append_book_nood("c programing","unknown",10,1);
    append_book_nood("Math 1","unknown",11,0);
    append_book_nood("Logic","unknown",12,0);
    append_book_nood("Math 2","unknown",13,1);
    append_book_nood("Physics","unknown",14,1);
    mode();

    return 0;
}

