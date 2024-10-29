#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// struct of date

struct Date{

    int Year;
    int Month;
    int Day;

};
// struct of Task
typedef struct{
    int Id;
    char Title[30];
    char Description[200];
    // heigh or low
    char priority[1];
    // done or doing
    bool status;
    struct Date Date;
    int added;


}Tasks;

// var
int SizeOfList=0,i,List=0;
char Leave,Selected;
// found for delete seved for save
bool Found,Saved;
// declare task struct as array list as Global to use in inside all the functions i give it access to add 100 task
Tasks Task[100];

void empty(char Title[]){
    if(List!=0){
    if(strcmp(Title,"Read")==0){
            Read();

    }
     else if(strcmp(Title,"UpDate")==0){
            Update();

    }
     else if(strcmp(Title,"Delete")==0){
            Delete();

    }
    else if(strcmp(Title,"Save")==0){
            Save();

    }
    }
    else {
         printf("\n\n\t    *** No Data is Availble To  %s  ***\n",Title);
    }


}
// functions
void Add(){

   printf("\n               ************** Create Task %d *************               \n",SizeOfList+1);



   printf("\n  >> Enter The Title Of The Task : ");
   scanf(" %[^\n]s",&Task[SizeOfList].Title);

    printf("\n  >> Enter The Description Of The Task : ");
   scanf(" %[^\n]s",&Task[SizeOfList].Description);

    printf("\n  >> Enter (H) For  High Priority Or (L) For  Low  Priority : ");
   scanf(" %[^\n]s",&Task[SizeOfList].priority);

   printf("\n   Enter The the Due Date  \n");

printf("\n     >>  Month From (1)To(12) : ");
   scanf("%d",&Task[SizeOfList].Date.Month);

   printf("\n     >> The Day From (1)To(31) : ");
   scanf("%d",&Task[SizeOfList].Date.Day);

    printf("\n     >> The Year From (2024)To(2025) : ");
   scanf("%d",&Task[SizeOfList].Date.Year);
   List=SizeOfList+1;


}

void Update(){
}

void Delete(){
}
void Read(){

    printf("\n               ************** All The  Task  *************               \n");

    for(i=0;i<=SizeOfList;i++){

    printf("\n               ************** Task %d *************               \n",i+1);


   printf("\n Title  : %s ",Task[i].Title);
   printf("\n The Description : %s ",Task[i].Description);

    printf("\n Priority : %s",Task[i].priority);


   printf("\n   The the Due Date mm/dd/yyyy : %d/%d/%d \n",Task[i].Date.Month,Task[i].Date.Day,Task[i].Date.Year);




      }
}
void Save(){
}
int Exit(){

    if(Saved){
                   printf("\n\n Thank You For Using \n");
                    exit(0);
                       }
              else {
                   printf("\n\n Exit Without Saving y/n :  ");
                   scanf(" %[^\n]c",&Leave);
                   if(Leave=='y'||Leave=='Y'){

                          exit(0);

                   }
                   else if(Leave=='n'||Leave=='N'){
                        Menu();

                   }
                   else {
                   }
                    }
}
void Menu(){
    int choice;

    // Menu the select what users want to do more  it comes after add() function
     while(choice!=6){

    // calling costum Title and its also check size if null or no

    CostumTitle("Menu");
    printf("\n\n\t\tEnter (1) To Add  Task  \n\n");
    printf("\t\tEnter (2) To Read  All The Tasks  \n\n");
    printf("\t\tEnter (3) To Update Tasks  \n\n");
    printf("\t\tEnter (4) To Delete Tasks  \n\n");
    printf("\t\tEnter (5) To Save   \n\n");
    printf("\t\tEnter (6) To Exit   \n\n");


    printf("\n\n --> Go To : $ ");
    scanf("%d",&choice);

      // check choix and move to funtions

    switch(choice){


          	case 0:
          	    Exit();

            break;
            case 1:
            CostumTitle("Add");
            Add();



            break;
            case 2:

              CostumTitle("Read");
              empty("Read");


            break;
            case 3:

              CostumTitle("UpDate");
              empty("UpDate");

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


void CostumTitle(char Title[]){

    // Use diffrent style for Menu and normal Title
    if(strcmp(Title,"Menu")==0)
    {
    printf("\n\n|------------------------- MENU ----------------------------|");
    }
    else {
    printf("           --------------------------------------------         \n");
    printf("               **************** %s *************                 \n",Title);
    printf("           --------------------------------------------           \n");

    }


}

// main function
int main(){
// set color to black so i can use color later
// cal the Menu
Menu();

return 0;
}

