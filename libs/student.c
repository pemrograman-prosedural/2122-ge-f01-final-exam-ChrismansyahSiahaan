#include "student.h"

void student_print_detail(struct student_t *students, unsigned short int size, int is_initial_state) {
    for (int i = 0; i < size; i++) {
        char dorm_name[15];
        if (students[i].dorm == NULL && students[i].flag == 0) {
            strcpy(dorm_name, "unassigned");
        } else if (students[i].dorm == NULL) {
            strcpy(dorm_name, "left");
        } else {
            strcpy(dorm_name, students[i].dorm->name);
        }
        printf("%s|%s|%s|%s|%s\n", students[i].id, students[i].name, students[i].year, gender_to_text(students[i].gender), dorm_name);
    }
}

void student_print_all(struct student_t *students, unsigned short int size) {
    for (int i = 0; i < size; i++) {
        printf("%s|%s|%s|%s\n", students[i].id, students[i].name, students[i].year, gender_to_text(students[i].gender));
    }
}

struct student_t create_student(char *id, char *name, char *year, enum gender_t gender) {
    struct student_t student;
    strcpy(student.id, id);
    strcpy(student.name, name);
    strcpy(student.year, year);
    student.gender = gender;
    student.dorm = NULL;
    student.flag = 0;
    return student;
}

unsigned short int get_index_student(struct student_t *students, unsigned short int size, char *id, int *found) {
    for (unsigned short int i = 0; i < size; i++) {
        if (strcmp(students[i].id, id) == 0) {
            *found = 1;
            return i;
        }
    }
    *found = 0;
    return size; 
}

void assign_student(struct student_t *students, struct dorm_t *dorms, unsigned short int student_idx, unsigned short int dorm_idx) {
    if (dorms[dorm_idx].capacity > dorms[dorm_idx].residents_num && dorms[dorm_idx].gender == students[student_idx].gender) {
        students[student_idx].dorm = &dorms[dorm_idx];
        dorms[dorm_idx].residents_num++;
        students[student_idx].flag = 1;
    }
}

void dorm_empty(struct student_t *students, struct dorm_t *dorms, unsigned short int dorm_idx, unsigned short int student_size) {
    if (dorms == NULL || students == NULL) {
        return;
    }
    dorms[dorm_idx].residents_num = 0;
    for (int i = 0; i < student_size; i++) {
        if (students[i].dorm != NULL && strcmp(students[i].dorm->name, dorms[dorm_idx].name) == 0) {
            students[i].dorm = NULL;
        }
    }
}

void move_student(struct student_t *students, struct dorm_t *dorms, struct dorm_t *new_dorm, unsigned short int student_idx, unsigned short int new_dorm_idx) {
    if (new_dorm->capacity > new_dorm->residents_num) {
        if (students[student_idx].dorm != NULL) {
            students[student_idx].dorm->residents_num--;
        }
        students[student_idx].dorm = new_dorm;
        new_dorm->residents_num++;
        students[student_idx].flag = 1;
    }
}

void student_leave(struct student_t *students, struct dorm_t *dorms, unsigned short int student_idx) {
    if (students[student_idx].dorm != NULL) {
        students[student_idx].dorm->residents_num--;
        students[student_idx].dorm = NULL;
    }
}