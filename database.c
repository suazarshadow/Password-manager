#ifndef DATABASE_C
#define DATABASE_C
#include "database.h"

list_node *create_database()
{
    list_node *database = malloc(sizeof(userdata));

    database -> head = NULL;
    database -> tail = NULL;
    database -> size = 0;
    
    return database;
}

bool find_password(list_node *database)
{
    char site[64];
    bool exist = false;
    ask_string("Enter site to find password:", "Input Error", site);

    userdata *current  = database -> head;

    for(size_t i = 0; i < database -> size; i++)
    {
        if(!strcmp(site, current -> site))
        {
            exist = true;
            printf("username: %s         |password: %s", current -> username, current -> password); 
        }

        current = current -> next;
    } 
    if(exist)
    {
        return true;
    }

    printf("Error: no such site in database!\n");

    return false;
}

bool add_pasword(list_node *database)
{
    char username[64];
    char password[64];
    char site[64]; 

    ask_string("Enter site to add:", "Input Error", site);
    ask_string("Enter username:", "Input Error", username);
    ask_string("Enter password:", "Input Error", password);   

    userdata *data = malloc(sizeof(userdata));

    strcpy(data -> site, site);
    strcpy(data -> username, username);
    strcpy(data -> password, password);

    data -> next = NULL;

    if (database -> size == 0)
    {
        database -> head = data;
        database -> tail = data;
    }
    else
    {
        database -> tail -> next = data;
        database -> tail = data;
    }

    database -> size ++;

    return true;
}

#endif