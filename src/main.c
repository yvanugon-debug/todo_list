#include <stdio.h>
#include <stdlib.h>
#include "../include/file_manager.h"
#include "../include/todo_actions.h"

int main(){
    char fileName[] = "storageFile.txt";
    Task **head;
    head = NULL;

    read_file(fileName, head);

    int exit = 0;
    print_tasks(head);
    while (exit == 0){
        
        printf("what would you like to do?\n");
        printf("enter 'add' to add a task\n");
        printf("enter 'clear <num/name>' to remove a task\n");
        printf("'clear all' to clear list\n");
        printf("enter 'save' to save the current list\n");
        printf("enter 'print' to print the current to do list");
        printf("enter 'exit' to exit\n");
    
    }
    printf("do you want to save your progress? enter N to not save\n");
    char userInput;
    scanf(" %c", &userInput);
    if (userInput != 'N'){
        save_list(head, fileName);
    }
    
    clear_list(head);
    
    return 0;
}