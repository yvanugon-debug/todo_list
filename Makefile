all: todo

todo: src/main.c
	gcc -Wall -Wextra -g src/main.c src/file_manager.c src/todo_actions.c -I include -o outputs/todo_list.o
	outputs/todo_list.o
