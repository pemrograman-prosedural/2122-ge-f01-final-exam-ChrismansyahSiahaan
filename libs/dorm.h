#ifndef DORM_H
#define DORM_H

#include "gender.h"
#include "student.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct dorm_t {
    char name[20];
    unsigned short capacity;
    enum gender_t gender;
    unsigned short residents_num;
};

void print_dorm_detail(struct dorm_t *dorms, unsigned short int size_dorm);
void print_all_dorm(struct dorm_t *dorms, unsigned short int size_dorm);
struct dorm_t create_dorm(char *name, unsigned short capacity, enum gender_t gender);
unsigned short int get_index_dorm(struct dorm_t *dorms, unsigned short int size_dorm, char *name);

#endif