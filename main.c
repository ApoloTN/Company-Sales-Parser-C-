#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for atof and atoi

// Function to clean a number string: keeps only digits and decimal point
float parseNumber(const char *str) {
    char clean[50];
    int k = 0;

    for (int i = 0; str[i]; i++) {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') { //Checks if at index I we have a number or a decimal, if so we keep it
            clean[k++] = str[i];
        }
    }
    clean[k] = '\0';

    return atof(clean);  // convert cleaned string to float
}

int main() {
    char filename[100];
    printf("Please type the file name verbatim: ");
    if (scanf("%99s", filename) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("File could not be opened!\n");
        return 1;
    }

    char line[256];
    float DP, AVG = 0;
    int CUSTOMERS = 0;

    while (fgets(line, sizeof(line), file)) {
        // Remove newline
        line[strcspn(line, "\n")] = 0;

        // DP
        if (strncmp(line, "DP:", 3) == 0) {
            char *p = line + 3;
            while (*p == ' ' || *p == '$') p++; // skip spaces and $
            DP = parseNumber(p);
        }

        // Average Sale per customer
        if (strncmp(line, "AVG:", 4) == 0) {
            char *p = line +4;
            while (*p == ' ' || *p == '$') p++; // skip spaces and $
            AVG = parseNumber(p);
        }

        // Number of customers
        if (strncmp(line, "Number of customers:", 20) == 0) {
            char *p = line + 20;
            while (*p == ' ') p++; // skip spaces
            CUSTOMERS = atoi(p);
        }
    }

    fclose(file);

    printf("\nData recovered successfully!\n");
    printf("Total Sales (DP): $%.2f\n", DP);
    printf("Average Sale per Customer (AVG): $%.4f\n", AVG);
    printf("Number of Customers: %d\n", CUSTOMERS);

    /*Writing the email template for user*/

    char name[12];
    printf("\nWho is writing this email today? : ");
    if (scanf("%11s", name) != 1) {
        printf("Invalid input!\n");
        return 1;
    }



    FILE *email = fopen("day_end_summary.txt", "w");
    if (!email) {
        printf("File could not be opened!\n");
        return 1;
    }

    printf("\nWriting email...");

    fprintf(email,"DP: $%.2f",DP);
    fprintf(email,"\nAVG:$%.2f",AVG );
    fprintf(email,"\nCustomers:%d",CUSTOMERS);
    fprintf(email,"\nSafe: 1854.00");
    fprintf(email,"\nE-Signature:%s",name);

    printf("\n\nEmail Complete!");


     

    fclose(email);




    return 0;
}
