#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <stdbool.h>

// struct of date
struct Date {

        int Year;
        int Month;
        int Day;

};
// struct of Task
typedef struct {
        int Id;
        char Title[30];
        char Description[200];
        // heigh or low
        char Priority[1];
        // done or doing
        char Status;
        struct Date Date;
        int added;

}
Tasks;

// var
int SizeOfList = 0, i,j, List = 0, Find[100];
char Leave, Selected;
// found for delete seved for save
bool Found, Saved;
void Update();
// declare task struct as array list as Global to use in inside all the functions i give it access to add 100 task
Tasks Task[100];

void empty(char Title[]) {
        if (List != 0) {


                if (!strcmp(Title, "Display")) {
                        Display();

                } else if (!strcmp(Title, "Update")) {

                       Update();

                } else if (!strcmp(Title, "Delete")) {
                        Delete();

                } else if (!strcmp(Title, "Save")) {
                        Save();

                }
        } else {
                printf("\n\n\t    *** No Data is Availble To  %s  ***\n", Title);
        }

}
// functions
void Add() {

        printf("\n               ************** Create Task %d *************               \n", SizeOfList + 1);

        printf("\n  >> Enter The Title Of The Task : ");
        scanf(" %[^\n]s", & Task[SizeOfList].Title);

        printf("\n  >> Enter The Description Of The Task : ");
        scanf(" %[^\n]s", & Task[SizeOfList].Description);

        printf("\n  >> Enter (H) For  High Priority Or (L) For  Low  Priority : ");
        scanf(" %[^\n]s", & Task[SizeOfList].Priority);

        printf("\n   Enter The the Due Date  \n");

        printf("\n\n      >>  Month From (1)To(12) : ");
        scanf("%d", & Task[SizeOfList].Date.Month);

        printf("\n\n      >> The Day From (1)To(31) : ");
        scanf("%d", & Task[SizeOfList].Date.Day);

        printf("\n\n      >> The Year From (2024)To(2025) : ");
        scanf("%d", & Task[SizeOfList].Date.Year);
        printf("\n\n\n");

        // add id so to call later to use in  filter and delete and update The id ==[index] +1
        Task[SizeOfList].Id = List + 1;
        Task[SizeOfList].Status="ToDo";

        SizeOfList++;
        List = SizeOfList;

}

void Update() {

    int choice=0,Tag;
    do{
    printf("\n\n\t\tEnter (0) To back To The Main Menu ");
    printf("\n\n\t\tEnter (1) To Update One Item in The Task ");
    printf("\n\n\t\tEnter (2) To Update The All The content Of The Task");
    printf("\n\n\tEnter Your Choice :  ");
    scanf("%d",&choice);
    printf("\n\n\n");

    switch(choice)
    {
        case 0:
        // back to menu
        break;
        case 1:
    CostumTitle("Update One Item");
    printf("\n\n\tEnter Id :  ");
    scanf("%d",&choice);

    printf("\n\n\t\tEnter (0) To back To The Main Menu ");
    printf("\n\n\t\tEnter (1) To Update Title ");
    printf("\n\n\t\tEnter (2) To Update Description");
    printf("\n\n\t\tEnter (3) To Update Status");
    printf("\n\n\t\tEnter (4) To Update Priority");

    printf("\n\n\tEnter Your Choice :  ");
    scanf("%d",&choice);
    printf("\n\n\n");
            break;
        case 2:
         CostumTitle("Update All The Items");

            break;
    }

    }while(choice<0||choice>2);




}

void Delete() {
        int choice;

        printf("\n\t\t Enter O To Back \n");
        printf("\n\t\t Enter 1 To Delete By Id \n");
        printf("\n\t\t Enter 2 To Delete By Title \n");
        printf("\n\t\t Enter 3 To Delete By Priority \n");
        printf("\n\t\t Enter 4 To Delete By Status \n");
        printf("\n\t\t Enter Your Choice :");
        scanf("%d", & choice);
        switch (choice) {
        case 0:
                break;
        case 1:
                Romove("Id");
                break;
        case 2:
                Romove("Title");
                break;
        case 3:
                Romove("Priority");

                break;
        case 4:
                Romove("Status");

                break;
        default:
                printf("Your Entrey Doesnt Match To Any Label ");
                break;

        }

}
void Romove(char Target[]) {
        int intTag,ItemFind=0;
        Found=false;
        char strTag[30];
        printf("\n Enter The %s Of The Table You Want To Delete :", Target);
        if (!strcmp(Target, "Id")) {

                scanf("%d", & intTag);

        } else {

                scanf(" %[^\n]s", & strTag);

        }

        for (i = 0; i < SizeOfList; i++) {

                if (!strcmp(Target, "Id")) {

                        if (Task[i].Id == intTag) {

                                Found = true;
                                Find[ItemFind++] = i;
                        }

                } else if (!strcmp(Target, "Status")) {

                        if (!strcmp(Task[i].Status, strTag)) {
                                Found = true;
                                Find[ItemFind++] = i;

                        }

                } else if (!strcmp(Target, "Priority")) {

                        if (!strcmp(Task[i].Priority, strTag)) {
                                Found = true;
                                Find[ItemFind++] = i;

                        }

                } else if (!strcmp(Target, "Title")) {

                        if (strcmp(Task[i].Title, strTag) == 0) {
                                Found = true;
                                Find[ItemFind++] = i;

                        }

                }
        }
        if (Found == true) {

           for (i = 0; i < ItemFind; i++) {

            for (j = Find[i] - i; j < SizeOfList - 1; j++) {
                Task[j] = Task[j + 1];
            }
            SizeOfList--;
           List=SizeOfList;
        }
        printf("Deleted With Success \n");

        } else {
                printf("The Entered Data dont Match any Task");

        }

}
void Display() {

        for (i = 0; i < SizeOfList; i++) {

                printf("\n\n               ************** Task %d *************               \n", Task[i].Id);

                printf("\n\n             Title  : %s ", Task[i].Title);
                printf("\n\n             The Description : %s ", Task[i].Description);
                printf("\n\n             Priority : %s ", Task[i].Priority);
                printf("\n\n             The the Due Date mm/dd/yyyy : %d/%d/%d \n\n", Task[i].Date.Month, Task[i].Date.Day, Task[i].Date.Year);

        }
}
void Save() {}
int Exit() {

        if (Saved) {
                printf("\n\n Thank You For Using \n");
                exit(0);
        } else {
                printf("\n\n Exit Without Saving y/n :  ");
                scanf(" %[^\n]c", & Leave);
                if (Leave == 'y' || Leave == 'Y') {

                        exit(0);

                } else if (Leave == 'n' || Leave == 'N') {
                        Menu();

                } else {}
        }
}
void Menu() {
        int choice;

        // Menu the select what users want to do more  it comes after add() function
        while (choice != 6) {

                // calling costum Title and its also check size if null or no

                CostumTitle("Menu");
                printf("\n\n\t\tEnter (1) To Add  Task  \n\n");
                printf("\t\tEnter (2) To Display  All The Tasks  \n\n");
                printf("\t\tEnter (3) To Update Tasks  \n\n");
                printf("\t\tEnter (4) To Delete Tasks  \n\n");
                printf("\t\tEnter (5) To Save   \n\n");
                printf("\t\tEnter (6) To Exit   \n\n");

                printf("\n\n --> Go To :  ");
                scanf("%d", & choice);
                printf("\n\n\n");


                // check choix and move to funtions

                switch (choice) {

                case 0:
                        Exit();

                        break;
                case 1:
                        CostumTitle("Add");
                        Add();

                        break;
                case 2:

                        CostumTitle("Display");
                        empty("Display");

                        break;
                case 3:

                        CostumTitle("Update");
                        empty("Update");

                        break;
                case 4:
                        CostumTitle("Delete");
                        empty("Delete");

                        break;
                case 5:
                        CostumTitle("Save");
                        empty("Save");

                        break;

                case 6:
                        Exit();
                        break;

                default:
                        printf("\n\n     * You should Enter a number From (1) To (6) *    \n\n");

                }

        }
}

void CostumTitle(char Title[]) {

        // Use diffrent style for Menu and normal Title
        if (strcmp(Title, "Menu") == 0) {
                printf("\n\n|------------------------- MENU ----------------------------|");
        } else {
                printf("           --------------------------------------------         \n");
                printf("               **************** %s *************                 \n", Title);
                printf("           --------------------------------------------           \n");

        }

}

// main function
int main() {
        // set color to black so i can use color later
        // cal the Menu
        Menu();

        return 0;
}
