#include "extras.h"
#include "base.h"
void print_record(){
  printf("id  FirstName\t    LastName\t DOB\t  City\n");
  int size = count();
  MEMBER* records[MAX_MEMBERS];
  getAll(records);
  for(int i=0; i<size; i++){
    MEMBER* p = records[i];
    printf("%d. %s\n", i+1, toString(p));
  }
  printf("\n");
}
void search_name(){
  char lastName[20];
  printf("Enter a last name > ");
  scanf("%s", lastName);
  MEMBER* records[MAX_MEMBERS];
  int size = getAll_lastName(records, lastName);
  printf("%d found.\n", size);
  printf("\nid  FirstName\t    LastName\t DOB\t  City\n");
  for(int i=0; i<size; i++){
    MEMBER* p = records[i];
    printf("%d. %s\n", i+1, toString(p));
  }
  printf("\n");
}
void search_city(){
  char firstName[20];
  printf("Enter a city > ");
  scanf("%s", firstName);
  MEMBER* records[MAX_MEMBERS];
  int size = getAll_city(records, firstName);
  printf("%d found.\n", size);
  printf("id  FirstName\t    LastName\t DOB\t  City\n");
  for(int i=0; i<size; i++){
    MEMBER* p = records[i];
    printf("%d. %s\n", i+1, toString(p));
  }
  printf("\n");
}
void load_file(){
  printf("Current data will be deleted and new data will be loaded.\n");
  printf("(1) Yes | (0 )No > ");
  int cont;
  scanf("%d", &cont);
  if (cont == 0) 
    return;
  clearFile();
  FILE* fp = fopen("members.txt", "r");
  char firstName[20], lastName[20], city[20];
  int dob;
  char line;
  for(;!feof(fp);){
    int next = fscanf(fp,"%s %s %06d %s", firstName, lastName, &dob, city);
    if(searchFirstName(firstName)){
      printf("%s already exists\n", firstName);
      continue;
    }
    create(firstName, lastName, dob, city);
  }
  
  printf("Records on file: %d\n", count());    
  fclose(fp);
  printf("\n");
}
void save_file(){
  FILE* f = fopen("members.txt", "w");
  int size = count();
  MEMBER* records[MAX_MEMBERS];
  getAll(records);
  for(int i=0; i<size; i++){
    MEMBER* p = records[i];
    fprintf(f,"%s\n", toStringSave(p));
  }
  fclose(f);
  printf("Members saved.\n\n");
}
void debug(){
  MEMBER* records[MAX_MEMBERS]={0};
  for_debug(records);
  for(int i=0; i<MAX_MEMBERS; i++){
    printf("%d - %p\n",i, records[i]);
  } 
  printf("\n");
}