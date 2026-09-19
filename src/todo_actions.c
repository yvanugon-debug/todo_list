#include <string.h>
#include <stdio.h>
#include "../include/file_manager.h"
#include "../include/todo_actions.h"

void print_tasks(){
    
}

int add_task(char *name, char *hours, char *urgency, Task **head){
    Task *currentTask = malloc(sizeof(Task));
    if (currentTask == NULL){
        return -1;
    }
    strcpy(currentTask->name, name);
    currentTask -> hours = atof(hours);
    currentTask ->urgency = atoi(urgency);
    currentTask->next = NULL;

    if (*head == NULL || currentTask->urgency < (*head)->urgency){
        currentTask->next = *head;
        *head = currentTask;        
    }else{
        Task *taskNode = *head;

        while ((taskNode->next != NULL) && (currentTask->urgency > taskNode->next->urgency)){
            taskNode = taskNode->next;

        }
        currentTask->next = taskNode->next;
        taskNode->next = currentTask;

    }
    return 0;
}