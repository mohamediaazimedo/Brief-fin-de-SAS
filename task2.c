#include <stdio.h>
#include <time.h>
#include <string.h>

struct Date {
    int Year;
    int Month;
    int Day;
};

typedef struct {
    int Id;
    char Title[30];
    char Description[200];
    char Priority[10];
    char Status[10];
    struct Date Date;
} Tasks;

// Variable declarations
int SizeOfList = 0;
Tasks Task[100];

// Date validation function
int DateValidation(int Date, int tracker) {
    int day, year, month;
    time_t t = time(NULL);
    struct tm *currentDate = localtime(&t);
    day = currentDate->tm_mday;
    year = currentDate->tm_year + 1900;
    month = currentDate->tm_mon + 1;

    switch (tracker) {
        case 3:  // Year validation
            if (Date < 2024 || Date > 2030 || Date < year) {
                return 0;
            }
            break;
        case 4:  // Month validation
            if (Date > 12 || Date <= 0 || (Date < month && Task[SizeOfList].Date.Year <= year)) {
                return 0;
            }
            break;
        case 5:  // Day validation
            if (Date > 31 || Date <= 0 || (Date < day && Task[SizeOfList].Date.Month <= month && Task[SizeOfList].Date.Year <= year)) {
                return 0;
            }
            break;
        default:
            break;
    }
    return 1;
}

// Updated Adding function
int Add(char Title[], char *Svalue, int Tracker, int *Nvalue, char Pholder[]) {
    if (Tracker == 3 || Tracker == 4 || Tracker == 5) {
        // Integer input (Year, Month, Day)
        do {
            printf("Enter The %s %s: ", Title, Pholder);
            scanf("%d", Nvalue);  // Read integer directly into Nvalue

            if (*Nvalue == 0) {
                printf("\nYou can't add an empty %s\n", Title);
            } else if (!DateValidation(*Nvalue, Tracker)) {
                printf("\nInvalid %s\n", Title);
                *Nvalue = 0;
            }
        } while (*Nvalue == 0 || !DateValidation(*Nvalue, Tracker));
    } else {
        // String input (Title, Description)
        do {
            printf("Enter The %s %s: ", Title, Pholder);
            scanf(" %[^\n]", Svalue);  // Read string directly into Svalue

            if (strlen(Svalue) == 0) {
                printf("You can't add an empty %s\n", Title);
            }
        } while (strlen(Svalue) == 0);
    }
    return 0;
}

int main() {
   

    // Display the added task for verification
    printf("\nTask Added:\n");
    printf("Title: %s\n", Task[SizeOfList - 1].Title);
    printf("Description: %s\n", Task[SizeOfList - 1].Description);
    printf("Date: %02d/%02d/%04d\n", Task[SizeOfList - 1].Date.Day, Task[SizeOfList - 1].Date.Month, Task[SizeOfList - 1].Date.Year);

    return 0;
}
