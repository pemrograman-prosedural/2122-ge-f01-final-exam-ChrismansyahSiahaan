#ifndef GENDER_H
#define GENDER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

enum gender_t {
    GENDER_MALE,
    GENDER_FEMALE,
    GENDER_UNKNOWN 
};

const char* gender_to_text(enum gender_t gender);
enum gender_t gender_to_value(const char *gender_text);

#endif