#include <stdio.h>
#include <stdlib.h>
#include "../include/file_manager.h"
#include "../include/todo_actions.h"

int main(){
    char file_name[] = "storageFile.txt";
    Task **head;
    head = NULL;


    read_file(file_name, head);
    

    
    return 0;
}