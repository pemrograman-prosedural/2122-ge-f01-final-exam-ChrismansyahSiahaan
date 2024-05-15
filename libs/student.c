#include "student.h"
#include "dorm.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

Student.c 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "gender.h"

Student create_student(char* input) {
    Student student;
    char* token = strtok(input, "#");
    token = strtok(NULL, "#");
    strcpy(student.id, token);
    token = strtok(NULL, "#");
    strcpy(student.name, token);
    token = strtok(NULL, "#");
    student.year = atoi(token);
    token = strtok(NULL, "#");
    if (strcmp(token, "male") == 0) {
        student.gender = MALE;
    } else {
        student.gender = FEMALE;
    }
    strcpy(student.dorm, "");
    return student;
}

void print_student(Student student) {
    printf("%s %s %d %s\n", student.id, student.name, student.year, student.dorm);
}

void print_student_detail(Student student) {
    printf("%s %s %d %s %s\n", student.id, student.name, student.year, gender_to_string(student.gender), student.dorm);
}

void assign_student(Dorm* dorms, Student* students, char* nim, char* asrama, int num_students, int num_dorms, int (find_id)(Student, int, char*), int (find_dorm)(Dorm, int, char*)) {
    int id = find_id(students, num_students, nim);
    int dorm_id = find_dorm(dorms, num_dorms, asrama);
    if (id != -1 && dorm_id != -1) {
        strcpy(students[id].dorm, asrama);
        if (dorms[dorm_id].gender == students[id].gender) {
            dorms[dorm_id].students[dorms[dorm_id].num_students] = students[id];
            dorms[dorm_id].num_students++;
        } else {
            printf("Gender tidak sesuai\n");
        }
    } else {
        printf("Data tidak ditemukan\n");
    }
}

void move_student(Dorm* dorms, Student* students, char* nim, char* asrama, int num_students, int num_dorms, int (find_id)(Student, int, char*), int (find_dorm)(Dorm, int, char*)) {
    int id = find_id(students, num_students, nim);
    int dorm_id = find_dorm(dorms, num_dorms, asrama);
    if (id != -1 && dorm_id != -1) {
        for (int i = 0; i < num_dorms; i++) {
            for (int j = 0; j < dorms[i].num_students; j++) {
                if (strcmp(students[id].id, dorms[i].students[j].id) == 0) {
                    strcpy(students[id].dorm, "");
                    for (int k = j; k < dorms[i].num_students - 1; k++) {
                        dorms[i].students[k] = dorms[i].students[k + 1];
                    }
                    dorms[i].num_students--;
                    break;
                }
            }
        }
        assign_student(dorms, students, nim, asrama, num_students, num_dorms, find_id, find_dorm);
    } else {
        printf("Data tidak ditemukan\n");
    }
}

void student_leave(Student* students, int num_students, char* nim) {
    int id = find_id(students, num_students, nim);
    if (id != -1) {
        strcpy(students[id].dorm, "");
    } else {
        printf("Data tidak ditemukan\n");
    }
}