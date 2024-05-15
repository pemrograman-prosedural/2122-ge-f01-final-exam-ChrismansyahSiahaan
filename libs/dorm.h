#ifndef DORM_H
#define DORM_H

#include "gender.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */


typedef struct {
    char name[50];
    int capacity;
    Gender gender;
    int num_students;
    Student* students;
} Dorm;

Dorm create_dorm(char* input);
void print_dorm(Dorm dorm);
void print_dorm_detail(Dorm dorm);
int find_dorm(Dorm* dorms, int num_dorms, char* name);
void dorm_empty(char* asrama, int num_students, int num_dorms, Student* students, Dorm* dorms, int (find_dorm)(Dorm, int, char*));

#endif