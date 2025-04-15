#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_TASK 100
#define MAX_LENGTH 100

void list();
void write();
void modify();
void delete_task();
void finish_task();

int completed_tasks = 0;

int main(){
    FILE *usr_name = popen("whoami","r");
    char name[50];    
    if (fgets(name, sizeof(name), usr_name) != NULL) {
        name[strcspn(name, "\n")] = '\0'; 
    }
    pclose(usr_name);
    char time_str[20];
    FILE *op = popen("date +%H:%M:%S", "r");
    if (op == NULL) {
        perror("popen failed miserably :(");
        return 1;
    }
    fgets(time_str, sizeof(time_str), op);
    pclose(op);
    
    printf("Time: %s", time_str);
    
    char hr[3];
    strncpy(hr, time_str, 2);
    hr[2] = '\0';
    int hour = atoi(hr);
    
    if (hour > 0 && hour <= 12) {
        printf("Hello %s, Good Morning!\n", name);
    } else if (hour > 12 && hour < 18) {
        printf("Hello %s, Good Afternoon!\n", name);
    } else {
        printf("Hello %s, Good Night!\n", name);
    }
    
    int input;
    printf("Welcome to TO DO LIST\n");
    while (1) {
        printf("1.List  2.Add  3.Modify  4.Delete  5.Finish Task  6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &input);
        while (getchar() != '\n');
        
        switch (input) {
            case 1:
                list();
                break;
            case 2:
                write();
                break;
            case 3:
                modify();
                break;
            case 4:
                delete_task();
                break;
            case 5:
                finish_task();
                break;
            case 6:
                exit(0);
            default:
                printf("Please choose the right option\n");
        }
    }
}

void list() {
    char line_buffer[200];
    int line_count = 0;
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("No tasks available.\n");
        return;
    }
    
    while (fgets(line_buffer, sizeof(line_buffer), file)) {
        line_count++;
        printf("%d. %s", line_count, line_buffer);
    }
    
    if (line_count == 0) {
        printf("No tasks available.\n");
    }
    fclose(file);
}

void write() {
    char write_buffer[100];
    FILE *file = fopen("tasks.txt", "a");
    if (file == NULL) {
        perror("File opening failed miserably :(");
        return;
    }
    printf("Enter the task: ");
    if (fgets(write_buffer, sizeof(write_buffer), stdin) != NULL) {
        fputs(write_buffer, file);
        printf("Task has been added successfully!\n");
    } else {
        printf("Error in reading input.\n");
    }
    fclose(file);
}

void modify() {
    int task_number, line_no = 0;
    char read_buffer[200], write_buffer[200];
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("No tasks available to modify.\n");
        return;
    }
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        perror("Temporary file creation failed :(");
        fclose(file);
        return;
    }
    printf("Enter the task number to modify: ");
    scanf("%d", &task_number);
    while (getchar() != '\n');
    
    while (fgets(read_buffer, sizeof(read_buffer), file)) {
        line_no++;
        if (line_no == task_number) {
            printf("Enter the new task: ");
            fgets(write_buffer, sizeof(write_buffer), stdin);
            fprintf(temp_file, "%s", write_buffer);
        } else {
            fputs(read_buffer, temp_file);
        }
    }
    fclose(file);
    fclose(temp_file);
    remove("tasks.txt");
    rename("temp.txt", "tasks.txt");
    printf("Task %d has been modified successfully.\n", task_number);
}

void delete_task() {
    int task_number, line_no = 0;
    char read_buffer[200];
    printf("Enter the task number to delete: ");
    scanf("%d", &task_number);
    while (getchar() != '\n');
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("No tasks available to delete.\n");
        return;
    }
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        perror("Temporary file creation failed :(");
        fclose(file);
        return;
    }
    while (fgets(read_buffer, sizeof(read_buffer), file)) {
        line_no++;
        if (line_no != task_number) {
            fputs(read_buffer, temp_file);
        }
    }
    fclose(file);
    fclose(temp_file);
    remove("tasks.txt");
    rename("temp.txt", "tasks.txt");
    printf("Task %d has been deleted successfully.\n", task_number);
}

void finish_task() {
    int task_no, current_line = 0;
    char read_buffer[200];
    printf("Enter the task number to mark as completed: ");
    scanf("%d", &task_no);
    while (getchar() != '\n');
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("No tasks available to complete.\n");
        return;
    }
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        perror("Temporary file creation failed :(");
        fclose(file);
        return;
    }
    while (fgets(read_buffer, sizeof(read_buffer), file)) {
        current_line++;
        if (current_line == task_no) {
            fprintf(temp_file, "[Completed] %s", read_buffer);
            completed_tasks++;
        } else {
            fputs(read_buffer, temp_file);
        }
    }
    fclose(file);
    fclose(temp_file);
    remove("tasks.txt");
    rename("temp.txt", "tasks.txt");
    printf("Task %d has been marked as completed.\n", task_no);
}

