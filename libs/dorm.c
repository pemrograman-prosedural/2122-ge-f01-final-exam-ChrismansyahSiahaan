#include "dorm.h"
#include "string.h"


void print_dorm_detail(struct dorm_t *dorms, unsigned short int size_dorm) {
    for (int i = 0; i < size_dorm; i++) {
        printf("%s|%d|%s|%d\n", dorms[i].name, dorms[i].capacity, gender_to_text(dorms[i].gender), dorms[i].residents_num);
    }
}


void print_all_dorm(struct dorm_t *dorms, unsigned short int size_dorm) {
    for (int i = 0; i < size_dorm; i++) {
        printf("%s|%d|%s\n", dorms[i].name, dorms[i].capacity, gender_to_text(dorms[i].gender));
    }
}

struct dorm_t create_dorm(char *name, unsigned short capacity, enum gender_t gender) {
    struct dorm_t dorm;
    strcpy(dorm.name, name);
    dorm.capacity = capacity;
    dorm.gender = gender;
    dorm.residents_num = 0;
    return dorm;
}


unsigned short int get_index_dorm(struct dorm_t *dorms, unsigned short int size_dorm, char *name) {
    for (unsigned short int i = 0; i < size_dorm; i++) {
        if (strcmp(dorms[i].name, name) == 0) {
            return i;
        }
    }
    return size_dorm;
}