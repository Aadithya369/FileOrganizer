#define _GNU_SOURCE_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_TASK 100
#define MAX_LENGTH 100
void list();
void write();
void modify();
void delete();
void finish_task();
void quit();
int main()
{
	char name[20] = "Aadithya";
	char time[20];
	FILE *op = popen("date +%H:%M:%S", "r");
	if (op == NULL)
	{
		perror("popen failed miserably :(");
		return 1;
	}
	fgets(time, sizeof(time), op);
	printf("Time: %s", time);
	char hr[2];
	hr[0] = time[0];
	hr[1] = time[1];
	if (atoi(hr) > 0 && atoi(hr) <= 12)
	{
		printf("Hello %s, Good Morning!\n", name);
	}
	else if (atoi(hr) > 12 && atoi(hr) < 18)
	{
		printf("Hello %s, Good Afternoon!\n", name);
	}
	else
	{
		printf("Hello %s, Good Night!\n", name);
	}
	int input;
	printf("Welcome to TO DO LIST\n");
	while (1)
	{
		printf("1.List  2.Add  3.Modify  4.Delete  5.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &input);
		while (getchar() != '\n')
			; // Consume and discard the newline
		switch (input)
		{
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
			delete ();
			break;
		case 5:
			exit(1);
		default:
			printf("Please choose the right option\n");
			break;
		}
	}
}
void list()
{
	char line_buffer[200];
	int line_count = 0;
	FILE *file = fopen("tasks.txt", "r");
	if (file == NULL)
	{
		perror("File opening failed miserably :(");
		return;
	}
	while ((fgets(line_buffer, sizeof(line_buffer), file)) != NULL)
	{
		line_count++;
		printf("Tasks: ");
		printf("%d. %s", line_count, line_buffer);
	}
	fclose(file);
}
void write()
{
	int line_count = 0;
	char write_buffer[100];
	char task_number[100];
	int line;
	FILE *file = fopen("tasks.txt", "a+");
	if (file == NULL)
	{
		perror("file opening failed miserably :(");
		return;
	}
	printf("Enter the task: ");
	fflush(stdout);
	if (fgets(write_buffer, sizeof(write_buffer), stdin) != NULL)
	{
		fseek(file, 0, SEEK_SET);
		while ((line = fgetc(file)) != EOF)
		{
			if (line == '\n')
			{
				line_count++;
			}
		}
		fputs(write_buffer, file);
		printf("Task has been added succesfully!\n");
	}
	else
	{
		printf("error in reading input");
	}
	fclose(file);
}
void modify()
{
	int task_number, line_no = 0;
	char read_buffer[200];
	char write_buffer[200];
	FILE *file = fopen("tasks.txt", "r");

	if (file == NULL)
	{
		perror("File opening failed miserably :(");
		return;
	}

	// Open a temporary file for writing.
	FILE *temp_file = fopen("temp.txt", "w");
	if (temp_file == NULL)
	{
		perror("Temporary file creation failed :(");
		fclose(file);
		return;
	}

	// Get the task number to modify.
	printf("Enter the task number to modify: ");
	scanf("%d", &task_number);
	while (getchar() != '\n')
		; // Clear input buffer.

	// Loop through the file line by line.
	while (fgets(read_buffer, sizeof(read_buffer), file) != NULL)
	{
		line_no++; // Increment line number.

		if (line_no == task_number)
		{
			// Prompt the user to enter the new task.
			printf("Enter the new task: ");
			fgets(write_buffer, sizeof(write_buffer), stdin);

			// Write the modified task to the temp file.
			fprintf(temp_file, "%s", write_buffer);
		}
		else
		{
			// Copy the original line to the temp file.
			fputs(read_buffer, temp_file);
		}
	}
	printf("The task %d is modified succesfully\n", task_number);
	fclose(file);
	fclose(temp_file);

	// Replace the original file with the temporary file.
	remove("tasks.txt");
	rename("temp.txt", "tasks.txt");

	printf("Task %d has been modified successfully.\n", task_number);
}
void delete()
{
	char read_buffer[200];
	char write_buffer[200];
	int line_no = 0;
	int task_number;
	printf("Enter the task number to delete:");
	scanf("%d", &task_number);
	while (getchar() != '\n')
		;
	FILE *file = fopen("tasks.txt", "r+");
	FILE *temp_file = fopen("temp.txt", "w");
	if (file == NULL || temp_file == NULL)
	{
		printf("file opening failed miserably :(");
	}
	while (fgets(read_buffer, sizeof(read_buffer), file) != NULL)
	{
		line_no++;
		if (line_no != task_number)
		{
			fprintf(temp_file, "%s", read_buffer);
		}
	}
	fclose(file);
	fclose(temp_file);
	remove("tasks.txt");
	rename("temp.txt", "tasks.txt");
	printf("Task %d has been deleted successfully.\n", task_number);
}
void finish_task()
{
}
