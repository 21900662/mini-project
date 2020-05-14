#include <string.h>
#include "base.h"

MEMBER* members[MAX_MEMBERS];
int _count = 0;

int available(){
  int i;
  for(i=0; i<MAX_MEMBERS; i++){
    if(members[i]==NULL) return 1;
  }
  return 0;
}
int firstAvailable(){
  int i;
  for(i=0; i<MAX_MEMBERS; i++){
    if(members[i]==NULL) return i;
  }
  return -1;
}
int count(){
  return _count;
}
void create(char* n, char* ph, int b, char* c){
  int index = firstAvailable();
  members[index] = (MEMBER*)malloc(sizeof(MEMBER));
  MEMBER* p = members[index];
  strcpy(p->firstName, n);
  strcpy(p->lastName, ph);
  p->dob = b;
  strcpy(p->city, c);
  _count++;
}
MEMBER* searchFirstName(char* n){
  int i;
  for(i=0; i<MAX_MEMBERS; i++){
    if(members[i]!=NULL && strcmp(members[i]->firstName, n)==0) return members[i];
  }
  return NULL;
}
void updateMember(MEMBER* p, char* ph, int b, char* c){
  strcpy(p->lastName, ph);
  p->dob = b;
  strcpy(p->city, c);
}
void deleteMember(MEMBER* p){
  int i, index;
  for(i=0; i<MAX_MEMBERS; i++)
    if(members[i]==p) {
      index=i;
      break;
    }
  free(p);
  members[index] = NULL;
  _count--;
}
void deleteAll(){
	int index = firstAvailable();
	char condition[20];
	printf("\nChoose condition to remain(Name of City): ");
	getchar();
	scanf("%s",condition);
	for(int i=0; i<index; i++){
		printf("%d",strcmp(condition,members[i]->city));
		if(strcmp(condition,members[i]->city)!=0){
			free(members[i]);
			members[i] = NULL;
			_count--;
		}
	}
	printf("\nDelete Complete!\n");
}
char* toString(MEMBER* p){
  static char str[80];
  sprintf(str, " %-15s %-12s %06d   %s", p->firstName, p->lastName, p->dob, p->city);
  return str;
}
void getAll(MEMBER* a[]){
  int i, c=0;
  for(i=0; i<MAX_MEMBERS; i++){
    if(members[i]!=NULL){
      a[c]=members[i];
      c++;
    }
  }
}
char* getFirstName(MEMBER* p){
  return p->firstName;
}
char* getLastName(MEMBER* p){
  return p->lastName;
}
int getDOB(MEMBER* p){
  return p->dob;
}
char* getCity(MEMBER* p){
  return p->city;
}
int getAll_lastName(MEMBER* a[], char* n){  
  int i, c=0;
  for(i=0; i<MAX_MEMBERS; i++){
    if(members[i]!=NULL && strstr(members[i]->lastName, n)){
      a[c]=members[i];
      c++;
    }
  }
  return c;
} 
int getAll_city(MEMBER* a[], char* n){
  int i, c=0;
  for(i=0; i<MAX_MEMBERS; i++){
    if(members[i]!=NULL && (strcmp(members[i]->city, n)==0)){
      a[c]=members[i];
      c++;
    }
  }
  return c;
}
void clearFile(){  
  int i;
  for(i=0; i<MAX_MEMBERS; i++){
    if(members[i]!=NULL) {
      free(members[i]);
    }
    members[i] = NULL;
  }
  _count = 0;
} 
char* toStringSave(MEMBER* p){
  static char str[80];
  sprintf(str, "%s %s %06d %s", p->firstName, p->lastName, p->dob, p->city);
  return str;
}
void for_debug(MEMBER* a[]){
  int i, c=0;
  for(i=0; i<MAX_MEMBERS; i++){
    if(members[i]!=NULL)
      a[c]=members[i];
  }
}
