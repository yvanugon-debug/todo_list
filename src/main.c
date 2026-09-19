#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/file_manager.h"
#include "../include/todo_actions.h"

int main(){
    char fileName[] = "storageFile.txt";
    Task *head = NULL;
    

    read_file(fileName, &head);

    int exit = 0;
    print_tasks(&head);
    while (exit == 0){
        
        printf("what would you like to do?\n");
        printf("enter 'add' to add a task\n");
        printf("enter 'clear <num>' to remove a task\n");
        printf("'clear all' to clear list\n");
        printf("enter 'save' to save the current list\n");
        printf("enter 'print' to print the current to do list\n");
        printf("enter 'exit' to exit\n");
        printf("enter your choice: ");
        char userChoice[50];
        fgets(userChoice,sizeof(userChoice),stdin);
        userChoice[strcspn(userChoice,"\n")] = '\0';

        if (strncmp("exit", userChoice, 4) == 0){
            exit = 1;
        }else if(strncmp("add", userChoice, 3) == 0){
            prompt_add_task(&head);
        }else if(strncmp("clear", userChoice, 5) == 0){
            prompt_remove_task(userChoice, &head);
        }else if(strncmp(userChoice, "print", 5) == 0){
            print_tasks(&head);
        }else if(strncmp(userChoice, "save", 4) == 0){
            save_file(fileName,&head);
        }
    
    }
    printf("do you want to save your progress? enter N to not save\n");
    char userInput;
    scanf(" %c", &userInput);
    if (userInput != 'N'){
        save_file(fileName, &head);
    }
    
    clear_list(&head);
    
    return 0;
}