#ifndef _BASE_H_
#define _BASE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "record.h"

// function prototypes
int available(); // checks if there is space
int firstAvailable(); // find the first available space
int count(); //number of current members
void create(char* n, char* ph, int b, char* c); // creates a new member
MEMBER* searchFirstName(char* n); // finds the pointer of member according to firstName
void updateMember(MEMBER* p, char* ph, int b, char* c); // updates a specific member's info
void deleteMember(MEMBER* p); // deletes a member
void deleteAll(); // deletes all members
void getAll(MEMBER* a[]); // creates arry of all record pointers containg member info
char* toString(MEMBER* p); // return contents as string
char* getLastName(MEMBER* p); // get lastName
char* getFirstName(MEMBER* p); // get firstName
int getDOB(MEMBER* p); // get dateofbirth
char* getCity(MEMBER* p); // get city
int getAll_lastName(MEMBER* a[], char* n); // create array of all record pointers that contains the member lastName
int getAll_city(MEMBER* a[], char* n); // create array of all record pointers that contain the city
void clearFile(); // remove all records
char* toStringSave(MEMBER* p); // get contents of a member as saveable string
void for_debug(MEMBER* a[]);  //gets all records for debugging

#endif
