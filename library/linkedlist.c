#include <stdio.h>
#include"linkedlist.h"
#include<string.h>


_user *head=NULL;
_user *tail=NULL;

_books *_head=NULL;
_books *_tail=NULL;

void append_user_node(char *_name,int _id,int _password,char _borrowed_book[50]){
    _user* node=(_user*)malloc(sizeof(_user));
   strcpy( node->name,_name);
   node->id=_id;
   node->password=_password;
  strcpy(node->borrowed_book,_borrowed_book);
   if(head==NULL){
    node->next=NULL;
    head=node;
    tail=node;
   }
   else{
    tail->next=node;
    tail=node;
    tail->next=NULL;
   }
}

void show_all_users_details(){
    _user *curr=head;
    while(curr!=NULL){
        printf("----------------------------------------------------\n");
        printf("The name :%s The id :%d The  password:%d The borrowed book :%s\n",curr->name,curr->id,curr->password,curr->borrowed_book);
        curr=curr->next;
    }
        printf("----------------------------------------------------\n");
}



void append_book_nood(char*_book_name, char*_author_name,int _book_id,char _avalible){
  _books* _node=(_books*)malloc(sizeof(_books));
  strcpy(_node->author_name,_author_name);
  strcpy(_node->book_name,_book_name);
  _node->avalible=_avalible;
  _node->book_id=_book_id;
    if(_head==NULL){
        _node->_next=NULL;
        _head=_node;
        _tail=_node;
        }
    else{
       _tail->_next=_node;
       _tail=_node;
       _tail->_next=NULL;
       }
}

void show_books_details(){
      _books *_curr=_head;
    while(_curr!=NULL){
        printf("----------------------------------------------------\n");
        printf("The book name %s \n",_curr->book_name);
        printf("The author name %s \n",_curr->author_name);
        printf("The id %d\n",_curr->book_id);
        _curr=_curr->_next;
    }
        printf("----------------------------------------------------\n");
}

void make_avalible(){
    _books *temp=_head;
    _user *curr=head;
    int id;
    printf("Enter the id to make the book available\n");
    scanf("%d",&id);
    while(temp!=NULL){
        if(temp->book_id==id){
          temp->avalible=1;
           while(curr!=NULL){
        if(strcmp(curr->borrowed_book,temp->book_name)==0){
            strcpy(curr->borrowed_book,"Non");
          }
            curr=curr->next;
        }

            }
             temp=temp->_next;
        }

    }

void make_notavalible(){
    _books *temp=_head;
    _user *ptr=head;
    int id,_id;

    printf("Enter the id to reserve the book \n");
    scanf("%d",&id);
    printf("Enter the id of the user\n");
    scanf("%d",&_id);
    while(temp!=NULL){
        if(temp->book_id==id){
          temp->avalible=0;
           while(ptr!=NULL){
         if(ptr->id==_id){
       strcpy(ptr->borrowed_book,temp->book_name);
    }
      ptr=ptr->next;
   }
            }
        temp=temp->_next;
}
}

void add_user(){
    _user usernode;
    _user *ptr=head;
    printf("Enter the username\n");
    scanf("%s",usernode.name);
    yy:
    printf("Enter the password\n");
    scanf("%d",&usernode.password);
    int y=check_passwoord(usernode.password);
    switch(y){
    case 1:
        goto yy;
        break;
    }
    xx:
    printf("Enter the id\n");
    scanf("%d",&usernode.id);
    int x=check_id(usernode.id);
    switch(x){
    case 1:
        goto xx;
        break;

    }
    printf("Enter the borrowed book if not enter Non\n");
    scanf("%s",usernode.borrowed_book);
     append_user_node(usernode.name,usernode.id,usernode.password,usernode.borrowed_book);
}

int login_user(int user_password){
    _user *ptr=head;
    while(ptr!=NULL){
        if(ptr->password==user_password){
            printf("Welcome %s !\n",ptr->name);
            printf("The id %d\n",ptr->id);
            printf("The password %d\n",ptr->password);
            return 1;
        }
        ptr=ptr->next;
    }
}

void show_books_available(){
    _books *curr=_head;
    printf("The available books to borrow:\n");
    while(curr!=NULL){
        if(curr->avalible==1){
            printf("%s\tThe id %d \n",curr->book_name,curr->book_id);
        }
         curr=curr->_next;
    }
    printf("****************************************\n");
}
void show_borrowed_books(){
    _books *curr=_head;
    printf("The borrowed books:\n");
    while(curr!=NULL){
        if(curr->avalible==0){
            printf("%s is not available to borrow \t The id %d \n",curr->book_name,curr->book_id);
        }
         curr=curr->_next;
    }
    printf("****************************************\n");
}


int check_passwoord(int _pass){
    _user *i='\0';
    for(i=head;i!=NULL;i=i->next){
        if(i->password==_pass){
            printf("Invalid password ! Try another password \n");
             return 1;
        }
    }
     return 0;
}

 int check_id(int _id){
    _user *i='\0';
    for(i=head;i!=NULL;i=i->next){
        if(i->id==_id){
            printf("Invalid ! Try another id\n");
            return 1;
        }
     }
     return 0;
}

