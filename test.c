#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

 typedef struct {
char *title;
int completed ;
} task;
task * tasks = NULL;
int length = 0;

void addtask(const char *task){
     tasks = realloc(tasks, (length + 1) * sizeof(task));
     tasks[length].title = (char *)malloc(strlen(task) + 1 );
     tasks[length].completed = 0 ;

     strcpy(tasks[length].title, task);

     length++;
     printf("task added");

}
void listtasks(){
    for (int i = 0; i < lenght; i++){
        status = 'd';

    } else {
        status = 'h';
    }

    printf("%d. %s [%c]\n", i+ 1,tasks[i].task, status);

}

void markcompleted(){

    if (index <= length && index > 0 ){
        tasks[index -1].completed = 1;
        printf("tasck marked as completed\n")

    } else {
        printf("invalid index\n");

    }

}
void deletedtasks(){
    if(index <= length && index > 0){
        index = index - 1;
        free (tasks [index]. task);
        for(int i = index ; i < length; i++){
        tasks[i] = tasks [i + 1];    
        }
  
    
    length --;
    tasks = ( task * )realloc(tasks,(length) * sizeof(task));

} else {
    printf("invalid index\n");
}


void edittask(int index, const char* task){
    if(index <= length && index > 0){
        index = index - 1;


        char *editetask = (char *)realloc(tasks[index]).tasks, strlen(task) + 1);

        if (editetask != NULL ){
        tasks[index].tasks = editedtask ;
        strcpy(tasks[length].task, task);
        printf("task updated sucssfully");
} else {
    printf("memory allocation failed");
}

} else {
    printf("invalid index\n");
} 
    
}
int main() {

    printf("\noptions\n");
    printf("1. Add a task\n");
    printf("2. liste all tasks\n");
     int printf(" cinst char * __restrict__ _form at, ...")
    printf("3. mark as complete\n");
    printf("4. edit task\n");
    printf("5. delete task\n");
    printf("6. exit\n");
    

    return 0;
 
}