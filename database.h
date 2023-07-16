#ifndef DATABASE_H
#define DATABASE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct UserData
{ 
    char username[64];
    char password[64];
    char site[64];
    userdata *next;

}userdata;

typedef struct list_node
{
    userdata *head;
    userdata *tail;
    int size; 

}list_node;


list_node *create_database();

bool find_password(list_node *database);

char *ask_string();///

bool add_password(list_node *database);

bool delete_password();

bool free_data();

bool display_saved_passwords();

bool save_data();

list_node *read_data(const char *filename, list_node *database);







#endif












