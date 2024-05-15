// 12S23003 - Chrismansyah T Siahaan
// 12S23012 - Genesis Tombak Dapot Tua Panjaitan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/gender.h"

int main(int argc, char **argv)
{
    char input[75];
    int num_dorms = 0;
    int num_students = 0;
    struct dorm_t *dorms = NULL;
    struct student_t *students = NULL;

    while (1)
    {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n\r")] = '\0'; // remove newline characters

        char *token = strtok(input, "#");
        if (strcmp(token, "---") == 0)
        {
            break;
        }
        else if (strcmp(token, "dorm-add") == 0)
        {
            num_dorms++;
            dorms = realloc(dorms, num_dorms * sizeof(struct dorm_t));
            dorms[num_dorms - 1] = create_dorm(input);
        }
        else if (strcmp(token, "dorm-print-all") == 0)
        {
            for (int i = 0; i < num_dorms; i++)
            {
                print_dorm(dorms[i]);
            }
        }
        else if (strcmp(token, "dorm-print-all-detail") == 0)
        {
            for (int i = 0; i < num_dorms; i++)
            {
                print_dorm_detail(dorms[i]);
            }
        }
        else if (strcmp(token, "student-add") == 0)
        {
            num_students++;
            students = realloc(students, num_students * sizeof(struct student_t));
            students[num_students - 1] = create_student(input);
        }
        else if (strcmp(token, "student-print-all") == 0)
        {
            for (int i = 0; i < num_students; i++)
            {
                print_student(students[i]);
            }
        }
        else if (strcmp(token, "student-print-all-detail") == 0)
        {
            for (int i = 0; i < num_students; i++)
            {
                print_student_detail(students[i]);
            }
        }
        else if (strcmp(token, "assign-student") == 0)
        {
            char *student_id = strtok(NULL, "#");
            char *dorm_name = strtok(NULL, "#");
            assign_student(dorms, students, student_id, dorm_name, num_students, num_dorms, find_id, find_dorm);
        }
        else if (strcmp(token, "move-student") == 0)
        {
            char *student_id = strtok(NULL, "#");
            char *dorm_name = strtok(NULL, "#");
            move_student(dorms, students, student_id, dorm_name, num_students, num_dorms, find_id, find_dorm);
        }
        else if (strcmp(token, "dorm-empty") == 0)
        {
            char *dorm_name = strtok(NULL, "#");
            dorm_empty(dorm_name, num_students, num_dorms, students, dorms, find_dorm);
        }
        else if (strcmp(token, "student-leave") == 0)
        {
            char *student_id = strtok(NULL, "#");
            student_leave(students, num_students, student_id);
        }
    }

    free(dorms);
    free(students);

    return 0;
}