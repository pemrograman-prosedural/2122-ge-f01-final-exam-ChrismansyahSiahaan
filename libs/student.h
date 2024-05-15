#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */
typedef struct {
    char id[10];
    char name[50];
    int year;
    Gender gender;
    char dorm[50];
} Student;

Student create_student(char* input);
void print_student(Student student);
void print_student_detail(Student student);
void assign_student(Dorm* dorms, Student* students, char* nim, char* asrama, int num_students, int num_dorms, int (find_id)(Student, int, char*), int (find_dorm)(Dorm, int, char*));
void move_student(Dorm* dorms, Student* students, char* nim, char* asrama, int num_students, int num_dorms, int (find_id)(Student, int, char*), int (find_dorm)(Dorm, int, char*));
void student_leave(Student* students, int num_students, char* nim);

#endif