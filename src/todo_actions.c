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

int prompt_add_task(Task **head){
    char taskName[256];
    char hours[10];
    int urgency[4];
    printf("enter a name for your task: ");
    fgets(taskName, sizeof(taskName),stdin);
    taskName[strcspn(taskName,'\n')] = '\0';
    printf("enter how many hours it will take: ");
    fgets(hours, sizeof(hours), stdin);
    hours[strcspn(hours,'\n')] = '\0';
    printf("on a scale to 1 to 10 how urgent is it: ");
    fgets(urgency, sizeof(urgency), stdin);
    urgency[strcspn(urgency,'\n')] = '\0';
    return add_task(taskName, hours, urgency, head);
    
}

int remove_task(Task **head, int taskNum){
    //less 1 to make it "programming counting" idk bro its late
    taskNum --;
    //handle removing the head
    if (taskNum == 0){
        if (*head == NULL){
            return 0;
        }
        Task *currentTask = *head;
        *head = (*head)->next;
        free(currentTask);
        return 0;
    }
    // iterate task num times to remove the nth task
    Task *currentTask = (*head);
    for (int i = 1; i < taskNum; i++){
        if (currentTask->next == NULL){
            return 0;
        }
        currentTask = currentTask -> next;
    }
    //ensure the task to remove exists
    if (currentTask->next == NULL){
        return 0;
    }
    //remove the node
    Task *temp = currentTask -> next;
    currentTask->next = currentTask->next->next;
    free(temp);
    return 1;
}