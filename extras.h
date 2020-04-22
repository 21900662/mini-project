#ifndef _EXTRAS_H_
#define _EXTRAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "record.h"

// function prototypes
void print_record(); // print whole list of members
void search_name(); // search/print according to last name of member
void search_city(); // search/print according to city of member
void load_file(); // load "members.txt" to program
void save_file(); // save members list made in program to "members.txt"

#endif