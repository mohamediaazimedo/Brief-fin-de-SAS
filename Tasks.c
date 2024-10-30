#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <stdbool.h>

struct Date {

        int Year;
        int Month;
        int Day;

};
typedef struct {
        int Id;
        char Title[30];
        char Description[200];
        // heigh or low
        char Priority[30];
        // done or ToDo
        char Status[10];
        //dd/mm8/yyyy
        struct Date Date;

}
Tasks;

// var
int SizeOfList = 0, i,j, List = 0, Find[100];
char Leave, Selected;
bool Found, Saved;
// initi Tasks and give it size max
Tasks Task[100];

// declare all the functions bellow
void Menu();
void Display();
void Add();
void Update();
void Delete();
void Save();
void Exit();
void Filter();

void empty(char Title[]);
void MisAjour(int Tag,int id);
void Remove(char Target[]);
void CustomTitle(char Title[]);





// Main Function
void MisAjour(int Tag,int id){

    // Array index start from 0 so id is +1 while index is 0
    id=id-1;
// we Have 4 Case **Title Desc Prio Status**
    switch(Tag){
    case 1:
        printf("\n\n\tEnter new Title :");
        scanf(" %[^\n]s",Task[id].Title);
        if (Task[id].Description==0)
        {
              printf("\n\n\t        You Cant UpDate With Empty Title           \n\n");
        }
        
       else printf("\n\n\t        Title  UpDate with  Success            \n\n");




    break;
    case 2:
         printf("\n\\tnEnter new Description :");
        scanf(" %[^\n]s",Task[id].Description);
        if (Task[id].Description==0)
        {
              printf("\n\n\t        You Cant UpDate With Empty Description           \n\n");
              return;
        }
        
       else printf("\n\n\t        Description  UpDate with  Success            \n\n");



    break;
    case 3:
        printf("\n\n\tEnter (H)High (L)Low To new Priority  :");
         scanf(" %[^\n]s",Task[id].Priority);
        if (strcmp(Task[SizeOfList].Priority,"L")!=0
         &&strcmp(Task[SizeOfList].Priority,"l")!=0
         &&strcmp(Task[SizeOfList].Priority,"H")!=0
         &&strcmp(Task[SizeOfList].Priority,"h")!=0)
        {
                        printf("\n\n\t * Invalid Entery (H/h)High (L:l)Low *\n\n");

        return;
        }
        else    printf("\n\n\t        Priority  UpDate with  Success            \n\n");

    break;


    case 4:
         printf("Enter new Status (Done) or (ToDo) :");
        scanf(" %[^\n]s",Task[id].Status);
        if (strcmp(Task[SizeOfList].Status,"Done")!=0
          &&strcmp(Task[SizeOfList].Priority,"ToDo")!=0)
        {
                          printf("\n\n\t * Invalid Entery! Enter (Done) Or (ToDo) *\n\n");

        }
        else    printf("\n\n\t        Status  UpDate with  Success            \n\n");

        
        break;


    }
}
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
void Add() {

        printf("\n               ************** Create Task %d *************               \n", SizeOfList + 1);
        printf("\n  >> Enter The Title Of The Task : ");
        scanf(" %[^\n]s", & Task[SizeOfList].Title);

        printf("\n  >> Enter The Description Of The Task : ");
        scanf(" %[^\n]s", & Task[SizeOfList].Description);

        printf("\n  >> Enter (H) For  High Priority Or (L) For  Low  Priority : ");
        scanf("%s", & Task[SizeOfList].Priority);
         if(strcmp(Task[SizeOfList].Priority,"L")!=0
         &&strcmp(Task[SizeOfList].Priority,"l")!=0
         &&strcmp(Task[SizeOfList].Priority,"H")!=0
         &&strcmp(Task[SizeOfList].Priority,"h")!=0)
        {
         printf("\n\n      invalid Entery Enter H/h for high and L/l for low Priority  ");
           return;
        }

        printf("\n   Enter The  Due Date  \n");

        printf("\n\n      >>  Month From (1)To(12) : ");
        scanf("%d", & Task[SizeOfList].Date.Month);
        if(Task[SizeOfList].Date.Month>12||Task[SizeOfList].Date.Month<=0)
        {
         printf("\n\n       invalid Entery You Have to Enter The Month from 1 To 12  ");
            return;
        }

        printf("\n\n      >> The Day From (1)To(31) : ");
        scanf("%d", & Task[SizeOfList].Date.Day);

         if(Task[SizeOfList].Date.Day>31||Task[SizeOfList].Date.Day<=0)
        {
         printf("\n\n       invalid Day  You Have to Enter A Day from 1 To 31  ");

            return;
        }

        printf("\n\n      >> The Year From (2024)To(2030) : ");
        scanf("%d", & Task[SizeOfList].Date.Year);
         if(Task[SizeOfList].Date.Year<2024||Task[SizeOfList].Date.Year>2030)
        {
         printf("\n\n       invalid Year The Year Should Be From (2024)To (2030) ");

            return;
        }
        printf("\n\n\n");

        // add id so to call later to use in  filter and delete and update The id ==[index] +1
        Task[SizeOfList].Id = List + 1;
        // Add By Default That status is ToDo u can change it in update to Done
        strcpy(Task[SizeOfList].Status,"ToDo");


        SizeOfList++;
        List = SizeOfList;

}
void Update() {

    int choice=0,id,Tag=0;
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
    CustomTitle("Update One");
    printf("\n\n\tEnter Id :  ");
    scanf("%d",&id);

    printf("\n\n\t\tEnter (0) To back To The Main Menu ");
    printf("\n\n\t\tEnter (1) To Update Title ");
    printf("\n\n\t\tEnter (2) To Update Description");
    printf("\n\n\t\tEnter (3) To Update Status");
    printf("\n\n\t\tEnter (4) To Update Priority");

    printf("\n\n\tEnter Your Choice :  ");
    scanf("%d",&Tag);
    printf("\n\n\n");
    if(Tag==0){
            // back to Menu No need to Do any think
            break;

    }
    else if(id <=SizeOfList || id>0 && Tag<=4||Tag<=0) {
        MisAjour(Tag,id);
        }
            break;
        case 2:
         CustomTitle("Update All");
          printf("\n\n\tEnter Id :  ");
          scanf("%d",&id);
          id=id-1;

        printf("\n  >> Enter The Title Of The Task : ");
        scanf(" %[^\n]s", & Task[id].Title);

        printf("\n  >> Enter The Description Of The Task : ");
        scanf(" %[^\n]s", & Task[id].Description);

        printf("\n  >> Enter (H) For  High Priority Or (L) For  Low  Priority : ");
        scanf(" %[^\n]s", & Task[id].Priority);
         printf("\n  >> Enter Status (ToDo) or (Done) : ");
        scanf(" %[^\n]s", & Task[id].Status);
                 printf("\n\n\t          UpDate Success            \n");

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
                Remove("Id");
                break;
        case 2:
                Remove("Title");
                break;
        case 3:
                Remove("Priority");

                break;
        case 4:
                Remove("Status");

                break;
        default:
                printf("\n\n     Your Entrey Doesnt Match To Any Label\n\n ");
                break;

        }

}
void Remove(char Target[]) {
        int intTag,ItemFind=0;
        Found=false;
        char strTag[1];

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
                        //  its Accept two value ToDo or Done
                        if (!strcmp(Task[i].Status, strTag)) {
                                Found = true;
                                Find[ItemFind++] = i;

                        }

                } else if (!strcmp(Target, "Priority")) {
                   //  its Accept 4 value H/h for high  and L/l for low priority
                        if (!strcmp(Task[i].Priority, strTag)) {
                                        printf("p2 \n");

                                Found = true;
                                Find[ItemFind++] = i;

                        }

                } else if (!strcmp(Target, "Title")) {
                             // it accept spaces 
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
        printf("\n\n\t      Deleted With Success \n");

        } else {
                printf("\n\n\t   ! The Entered Data dont Match any Task \n");

        }

}
void Display() {

        for (i = 0; i < SizeOfList; i++) {

                printf("\n\n               ************** Task %d *************               \n", Task[i].Id);

                printf("\n\n             Title  : %s ", Task[i].Title);
                printf("\n\n             The Description : %s ", Task[i].Description);
                if (strcmp(Task[i].Priority,"h")==0 || strcmp(Task[i].Priority,"h")==0)
                {
                printf("\n\n             Priority : %s ", "High");
                }
                if (strcmp(Task[i].Priority,"l")==0 || strcmp(Task[i].Priority,"L")==0)
                {
                printf("\n\n             Priority : %s ", "Low");
                }
                
                printf("\n\n             Status : %s ", Task[i].Status);
                printf("\n\n             The the Due Date mm/dd/yyyy : %d/%d/%d \n\n", Task[i].Date.Month, Task[i].Date.Day, Task[i].Date.Year);

        }
}
void Save() {

    FILE* pfile;

   if(SizeOfList==0)
	{
	printf("\n\n\t\t\t * No Tasks to Save Add new  ! * \n ");
    return;
	}
	if(Saved==false){
            // if file is not saved yet create new file
			pfile=fopen("Tasks.txt","w");
	}
	else {
    // if file is  saved  already and we want to add new data to it
    pfile=fopen("Tasks.txt","a");

	}
	if(Saved){
        printf("\n\n\t\t\t * Its Already Saved *   \n ");
	}
	else{

        for(i=0;i<SizeOfList;i++){
            char p[100];
       // Convert integer to string

           fprintf(pfile,
                         "\n\n|------------------------- Task %d ----------------------------|"
                         "\n\n             Id  : %d \n"
                         "\n\n             Title  : %s \n"
                         "\n\n             The Description : %s \n "
                         "\n\n             Priority : %s \n"
                         "\n\n             Status : %s "
                         "\n\n             The the Due Date mm/dd/yyyy : %d/%d/%d \n\n"
                         ,i+1
                         ,Task[i].Id,
                         Task[i].Title,
                         Task[i].Description,
                         Task[i].Priority,
                         Task[i].Status,
                         Task[i].Date.Month,Task[i].Date.Day,Task[i].Date.Year);
        }
        printf("\n\n\t\t  *  Saved With Success *   \n ");
	}

	fclose(pfile);


}
void Exit() {

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

                CustomTitle("Menu");
                printf("\n\n\t\tEnter (1) To Add  Task  \n\n");
                printf("\t\tEnter (2) To Display  All The Tasks  \n\n");
                printf("\t\tEnter (3) To Update Tasks  \n\n");
                printf("\t\tEnter (4) To Delete Tasks  \n\n");
                printf("\t\tEnter (5) To Save   \n\n");
                printf("\t\tEnter (6) Filter   \n\n");
                printf("\t\tEnter (7) To Exit   \n\n");

                printf("\n\n --> Go To :  ");
                scanf("%d", & choice);
                printf("\n\n\n");


                // check choix and move to funtions

                switch (choice) {

                case 0:
                        Exit();

                        break;
                case 1:
                        CustomTitle("Add");
                        Add();

                        break;
                case 2:

                        CustomTitle("Display");
                        empty("Display");

                        break;
                case 3:

                        CustomTitle("Update");
                        empty("Update");

                        break;
                case 4:
                        CustomTitle("Delete");
                        empty("Delete");

                        break;
                case 5:
                        CustomTitle("Save");
                        empty("Save");

                        break;

                case 6:
                        Filter();
                        break;
                        case 7:
                        Exit();
                        break;

                default:
                        printf("\n\n     * You should Enter a number From (1) To (6) *    \n\n");

                }

        }
}
void Filter(){
         int choice,Tag;
    do{
    printf("\n\n\t\tEnter (0) To back To The Main Menu ");
    printf("\n\n\t\tEnter (1) To Filter By Status ");
    printf("\n\n\t\tEnter (2) To Filter By Priority ");
    printf("\n\n\t\tEnter (3) To Filter By The Due Date ");

    printf("\n\n\tEnter Your Choice :  ");
    scanf("%d",&choice);
    printf("\n\n\n");
    switch (choice)
    {
    case 0:
    //  back up to menu
       return;
        break;
         case 1:
         // status
        
        break;
         case 2:
       
        break;
         case 3:
       
        break;
    
    default:
        break;
    }

    

    }while (choice>3||choice<0);
    
    
}


void CustomTitle(char Title[]) {


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

