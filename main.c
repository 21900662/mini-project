#include "base.h"
#include "extras.h"
#include "record.h"

// function prototypes
void input_handler(int input);
void display_menu();
void create_record();
void read_record();
void update_record();
void delete_record();

// main function
int main(){
  clearFile();
  int user_input;
  while(1){
    display_menu();
    printf("\nSelect a menu> ");
    scanf("%d", &user_input);
    printf("\n");
    input_handler(user_input);
    if(user_input==0)
      break;
    }
  return 0;
}

// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(int input){
  // TODO: Modify this function as you need
  if(input==1)
    create_record();
  else if(input==2)
    read_record();
  else if(input==3)
    update_record();
  else if(input==4)
    delete_record();
  else if(input==5)
    print_record();
  else if(input==6)
    search_name();
  else if(input==7)
    search_city();
  else if(input==8)
    load_file();
  else if(input==9)
    save_file();
  else if(input==0){
    printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
  }
  else
    printf("Unknown menu: %d \n\n", input);
}

// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){
  // TODO: Modify this function as you need
  printf("******************************\n");
  printf(" Membership management system \n");
  printf("******************************\n");
  printf(" 1.Create member\n");
  printf(" 2.Read member\n");
  printf(" 3.Update member\n");
  printf(" 4.Delete member\n");
  printf(" 5.Print record\n");
  printf(" 6.Search by lastName\n");
  printf(" 7.Search by city\n");
  printf(" 8.Load file\n");
  printf(" 9.Save\n");
  printf(" 0. Quit\n");
}

void create_record(){
  if(!available()) {
    printf("Space unavailable!\n");
    return;
  }
  char firstName[20], lastName[20], city[20];
  int dob;  
  printf("Enter info:\n");
  printf("First Name > ");
  scanf("%s", firstName);
  if(searchFirstName(firstName)) {
    printf("%s already exists\n", firstName);
    return;
  }
  printf("Last Name > ");
  scanf("%s", lastName);
  printf("Date of Birth > ");
  scanf("%06d", &dob);
  printf("City > ");
  scanf("%s", city);
  create(firstName, lastName, dob, city);
  printf("\n");
}

void read_record(){
  char firstName[20];
  printf("Enter First Name > ");
  scanf("%s", firstName);
  MEMBER* p = searchFirstName(firstName);
  if(p) {
    printf("Member info:\n");
    printf("First Name : %s\n", getFirstName(p));
    printf("Last Name : %s\n", getLastName(p));
    printf("Date of Birth : %06d\n", getDOB(p));
    printf("City : %s\n", getCity(p));
  }
  else {
    printf("%s does not exist\n", firstName);
  }
  printf("\n");
}

void update_record(){
  char firstName[20], lastName[20], city[20];
  int dob;  
  printf("Enter a First Name > ");
  scanf("%s", firstName);
  MEMBER* p = searchFirstName(firstName);
  if(p) {
    printf("Update info:\n");
    printf("Last Name > ");
    scanf("%s", lastName);
    printf("Date of Birth > ");
    scanf("%06d", &dob);
    printf("City > ");
    scanf("%s", city);
    updateMember(p, lastName, dob, city);
  }
  else {
    printf("%s does not exist\n", firstName);
  }
  printf("\n");
}

void delete_record(){
  char firstName[20];
  printf("Enter a First Name > ");
  scanf("%s", firstName);
  MEMBER* p = searchFirstName(firstName);
  if(p) {
    deleteMember(p);
    printf("%s is deleted\n", firstName);
  }
  else {
    printf("%s does not exist\n", firstName);
  }
  printf("\n");
}