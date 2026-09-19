

#ifndef TODO_ACTIONS_H
#define TODO_ACTIONS_H

typedef struct Task{
    char name[256];
    float hours;
    int urgency;
    struct Task *next;


}Task;


void print_tasks(Task **head); //done
int add_task(char *name, char *hours, char *urgency, Task **head); // done
int remove_task(Task **head, int taskNum);//done
int clear_list(Task **head); //done
int prompt_add_task(Task **head);//done
int prompt_remove_task(char *userChoice, Task **head);

#endif