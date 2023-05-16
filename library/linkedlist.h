#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct user{
    char name[50];
    int id;
    int password;
    char borrowed_book[50];
    struct user *next;
}_user;

typedef struct books{
    char book_name[50];
    char author_name[50];
    int book_id;
    char avalible; //0 means the book is not available 1 means is available
    struct books *_next;
}_books;

 //prototypes of used functions
void append_user_node(char *_name,int _id,int _password,char _borrowed_book[50]);
void show_all_users_details();
void append_book_nood(char*_book_name, char*_author_name,int _book_id,char _avalible);
void show_books_details();
void make_avalible();
void make_notavalible();
void add_user();
int login_user(int user_password);
void show_books_available();
void show_borrowed_books();
int check_id(int _id);
int check_passwoord(int _pass);

#endif // LIBRARY_SYSTEM_H

