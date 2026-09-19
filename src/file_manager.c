#include <string.h>
#include <stdio.h>
#include "../include/file_manager.h"
#include "../include/todo_actions.h"


int read_file(char *fileName, Task **head){
    //open file and check that it has opened correctly
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