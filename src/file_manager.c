#include <string.h>
#include <stdio.h>
#include "../include/file_manager.h"
#include "../include/todo_actions.h"


int read_file(char *fileName, Task **head){
    
    FILE *taskFile = fopen(fileName, "r");
    
    if (taskFile == NULL){
        return -1;
    }
    //read line by line and see if it has opened
    char line[256];
    int isTask = 0;
    while(fgets(line, sizeof(line), taskFile) != NULL){
        isTask = 1;
        //replace the new line character with a null character
        line[strcspn(line, "\n")] = '\0';

        char *name = strtok(line,",");
        char *hours = strtok(NULL, ","); //NULL can be used because strtok starts again where it left off
        char *urgency = strtok(NULL, ",");
        //add the task to the list
        add_task(name, hours, urgency, head);

    }
    fclose(taskFile);
    return isTask;
}

int save_file(char* fileName, Task **head){
    FILE *saveFile = fopen(fileName, "w");
    //check that the file successfully opened
    if (saveFile == NULL){
        printf("file failed to open");
        return -1;
    }
    //print the tasks in the linked list into the text file
    Task *currentTask = *head;
    while(currentTask != NULL){
        fprintf(saveFile,"%s,%f,%d\n",currentTask->name,currentTask->hours,currentTask->urgency);
        currentTask = currentTask->next;
    }
    return 0;
}