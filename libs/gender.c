#include "gender.h"
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 */

const char* gender_to_text(enum gender_t gender) {
    switch (gender) {
        case GENDER_MALE:
            return "male";
        case GENDER_FEMALE:
            return "female";
        default:
            return "unknown";
    }
}

enum gender_t gender_to_value(const char *gender_text) {
    if (strcmp(gender_text, "male") == 0) {
        return GENDER_MALE;
    } else if (strcmp(gender_text, "female") == 0) {
        return GENDER_FEMALE;
    } else {
        return GENDER_UNKNOWN;
    }
}