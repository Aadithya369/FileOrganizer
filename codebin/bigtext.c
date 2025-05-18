
#include <stdio.h>

int main() {
    FILE *file = fopen("output.html", "w");
    fprintf(file, "<html><body><h1 style='font-size:50px;'>Big Text</h1></body></html>");
    fclose(file);
    printf("HTML file with large text created!\n");
    return 0;
}
