#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/file_manager.h"
#include "../include/todo_actions.h"

void print_tasks(Task **head){
    if (*head == NULL){
        printf("Your have no tasks to do");
        return;
    }
    float total = 0;
    int iter = 0;
    Task *currentNode = *head;
    printf("YOUR CURRENT TASK LIST\n");
    //iterates through linked list and prints the tasks in it
    while (currentNode != NULL){
        printf("%d. %s (%.2f hours)\n",++iter,currentNode->name, currentNode->hours);
        total += currentNode->hours;
        currentNode = currentNode -> next;
    }
    printf("TOTAL: %.2f",total);
    
}

int add_task(char *name, char *hours, char *urgency, Task **head){
    //allocate memory to the task
    Task *currentTask = malloc(sizeof(Task));
    if (currentTask == NULL){
        return -1;
    }
    //put the information into the task
    strcpy(currentTask->name, name);
    currentTask -> hours = atof(hours);
    currentTask ->urgency = atoi(urgency);
    currentTask->next = NULL;
    //put the task in order of urgency into the linked list
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

int clear_list(Task **head){
    while (*head != NULL){
        Task *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    
    return 1;
}