#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"

struct student_t {
    char id[12];
    char name[40];
    char year[5];
    enum gender_t gender;
    struct dorm_t *dorm;
    int flag;
};

void student_print_detail(struct student_t *students, unsigned short int size, int is_initial_state);
void student_print_all(struct student_t *students, unsigned short int size);
struct student_t create_student(char *id, char *name, char *year, enum gender_t gender);
void assign_student(struct student_t *students, struct dorm_t *dorms, unsigned short int student_idx, unsigned short int dorm_idx);
unsigned short int get_index_student(struct student_t *students, unsigned short int size, char *id, int *found);
void dorm_empty(struct student_t *students, struct dorm_t *dorms, unsigned short int dorm_idx, unsigned short int student_size);
void move_student(struct student_t *students, struct dorm_t *dorms, struct dorm_t *new_dorm, unsigned short int student_idx, unsigned short int new_dorm_idx);
void student_leave(struct student_t *students, struct dorm_t *dorms, unsigned short int student_idx);

#endif