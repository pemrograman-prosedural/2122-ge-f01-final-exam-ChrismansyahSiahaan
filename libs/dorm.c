#include "dorm.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

Dorm.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dorm.h"
#include "student.h"

Dorm create_dorm(char* input) {
    Dorm dorm;
    char* token = strtok(input, "#");
    strcpy(dorm.name, token);
    token = strtok(NULL, "#");
    dorm.capacity = atoi(token);
    token = strtok(NULL, "#");
    if (strcmp(token, "male") == 0) {
        dorm.gender = MALE;
    } else {
        dorm.gender = FEMALE;
    }
    dorm.num_students = 0;
    dorm.students = (Student*) malloc(dorm.capacity * sizeof(Student));
    return dorm;
}

void print_dorm(Dorm dorm) {
    printf("%s %d %s %d\n", dorm.name, dorm.capacity, gender_to_string(dorm.gender), dorm.num_students);
}

void print_dorm_detail(Dorm dorm) {
    printf("%s %d %s %d\n", dorm.name, dorm.capacity, gender_to_string(dorm.gender), dorm.num_students);
    for (int i = 0; i < dorm.num_students; i++) {
        print_student(dorm.students[i]);
    }
}

int find_dorm(Dorm* dorms, int num_dorms, char* name) {
    for (int i = 0; i < num_dorms; i++) {
        if (strcmp(dorms[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void dorm_empty(char* asrama, int num_students, int num_dorms, Student* students, Dorm* dorms, int (find_dorm)(Dorm, int, char*)) {
    int dorm_id = find_dorm(dorms, num_dorms, asrama);
    if (dorm_id != -1) {
        for (int i = 0; i < dorms[dorm_id].num_students; i++) {
            for (int j = 0; j < num_students; j++) {
                if (strcmp(students[j].id, dorms[dorm_id].students[i].id) == 0) {
                    strcpy(students[j].dorm, "");
                }
            }
        }
        dorms[dorm_id].num_students = 0;
    } else {
        printf("Data tidak ditemukan\n");
    }
}