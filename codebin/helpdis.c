#include <stdio.h>

int main()
{
    int soc1, soc2, soc3, mm, dd, yyyy, result = 0;

    printf("Enter your social security number (XXX-XX-XXXX): ");
    do
    {
        result = scanf("%3d-%2d-%4d", &soc1, &soc2, &soc3);
	fflush(stdin);
        if(result != 3)
        {
            printf("Wrong format for SSN please enter again: ");
        }
    } while(result != 3);

    result = 0;

    printf("Enter your birthday (MM/DD/YYYY): ");
    do
    {
        result = scanf("%2d/%2d/%4d", &mm, &dd, &yyyy);
	fflush(stdin);
        if(result != 3)
        {
            printf("Wrong format for birthday please enter again: ");
        }
    } while(result != 3);

    return 0;
}

