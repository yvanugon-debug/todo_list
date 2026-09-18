

#ifndef TODO_ACTIONS_H
#define TODO_ACTIONS_H

typedef struct{
    char taskName[256];
    float timeHours;
    int urgency;
    struct Task *next;


}Task;

int load_tasks();
void print_tasks();
int add_task();
Task create_task();

int remove_task();
int clear_list();

#endif