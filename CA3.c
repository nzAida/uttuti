#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "functions.h"
#define TRUE 1
#define OUT 0


int main(){
    FILE *acc , *post;
    acc=fopen("acount.txt" , "w");
    post=fopen("post.txt" , "w");
    status s;
    account* head=users_head();
    s.in_out=OUT;
    char* order;//=(char*)malloc(sizeof(char));
    char c;
    int i=0;
    while(TRUE){/*take the order*/
        order=(char*)malloc(sizeof(char));
        i=0;
        while(TRUE){
            scanf("%c" , &c);
            if(c==' ' || c=='\n'){
                order[i]='\0';
                break;
            }
            else{
                order[i]=c;
                order=(char*)realloc(order , (i+2)*sizeof(char));
            }
            i++;
        }
        i=0;
        /*different orders*/
        if(!strcmp(order , "signup")){
            char* username=(char*)malloc(sizeof(char));
            char* password=(char*)malloc(sizeof(char));
            while(TRUE){
                scanf("%c" , &c);
                if(c!=' ' && c!='\n'){
                    username[i]=c;
                    username=(char*)realloc(username , (i+2)*sizeof(char));
                }
                else{
                    username[i]='\0';
                    break;
                }
                i++;
            }
            i=0;
            while(TRUE){
                scanf("%c" , &c);
                if(c!=' ' && c!='\n'){
                    password[i]=c;
                    password=(char*)realloc(password , (i+2)*sizeof(char));
                }
                else{
                    password[i]='\0';
                    break;
                }
                i++;
            }
            signup(username , password , head , &s);
            free(username);
            free(password);
        }
        else if(!strcmp(order , "login")){
            char* username=(char*)malloc(sizeof(char));
            char* password=(char*)malloc(sizeof(char));
            while(TRUE){
                scanf("%c" , &c);
                if(c!=' ' && c!='\n'){
                    username[i]=c;
                    username=(char*)realloc(username , (i+2)*sizeof(char));
                }
                else{
                    username[i]='\0';
                    break;
                }
            }
            i=0;
            while(TRUE){
                scanf("%c" , &c);
                if(c!=' ' && c!='\n'){
                    password[i]=c;
                    password=(char*)realloc(password , (i+2)*sizeof(char));
                }
                else{
                    password[i]='\0';
                    break;
                }
                i++;
            }
            login(username , password , head , &s);
            free(username);
            free(password);
        }
        else if(!strcmp(order , "post")){
            char* post=(char*)malloc(sizeof(char));
            while(TRUE){
                scanf("%c" , &c);
                if(c!='\n' && c!='\0'){
                    post[i]=c;
                    post=(char*)realloc(post , (i+2)*sizeof(char));
                }
                else
                    break;
                i++;
            }
            new_post(&s , post);
            free(post);
        }
        else if(!strcmp(order , "like")){
            int id;
            char* username=(char*)malloc(sizeof(char));
            while(TRUE){
                scanf("%c" , &c);
                if(c!=' ' && c!='\n'){
                    username[i]=c;
                    username=(char*)realloc(username , (i+2)*sizeof(char));
                }
                else{
                    username[i]='\0';
                    break;
                }
                i++;
            }
            scanf("%d" , &id);
            like(username , id , head , &s);
            free(username);
        }
        else if(!strcmp(order , "logout"))
            logout(&s);
        else if(!strcmp(order , "delete")){
            int id;
            scanf("%d" , &id);
            delete_post(id , &s);
        }
        else if(!strcmp(order , "info"))
            info(&s);
        else if(!strcmp(order , "find_user")){
            char* username=(char*)malloc(sizeof(char));
            while(TRUE){
                scanf("%c" , &c);
                if(c!=' ' && c!='\n'){
                    username[i]=c;
                    username=(char*)realloc(username , (i+2)*sizeof(char));
                }
                else{
                    username[i]='\0';
                    break;
                }
                i++;
            }
            find_user(username , &s , head);
            free(username);
        }
        else
            printf("its not a valid order!");
        free(order);
    }
    acc_print(head , acc);
    post_print(head , post);
    fclose(acc);
    fclose(post);
    return 0;
}