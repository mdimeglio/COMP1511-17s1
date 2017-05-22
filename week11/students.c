#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096
#define MAX_STUDENT_NAME_LENGTH 128
#define MAX_GRADE_STRING_LENGTH 22
#define MAX_LAB_NAME_LENGTH 32

struct student {
    int              zid;
    char             name[MAX_STUDENT_NAME_LENGTH + 1];
    char             lab_name[MAX_LAB_NAME_LENGTH + 1];
    char             lab_grades[MAX_GRADE_STRING_LENGTH + 1];
    struct student   *next;
};

struct student *read_student(FILE *stream);
struct student *read_students_stream(FILE *stream);

int main (int argc, char *argv[]) {
	FILE *fp;
	if (argc == 2) {
		fp = fopen(argv[1], "r");
		
		if (fp == NULL) {
	        fprintf(stderr,"warning file %s could not  be opened for reading\n", argv[1]);
	        return EXIT_FAILURE;
    	}
	} else {
		fp = stdin;
	}

	struct student *first = read_students_stream(fp);
	for (struct student *cur = first; cur != NULL; cur = cur->next) {
		printf("%7d %s %s %s\n",
			cur->zid,
			cur->name,
			cur->lab_name,
			cur->lab_grades);
	}
    
	return EXIT_SUCCESS;
}


//5099703 Tsun Bordignon thu13-sitar A+A+CABAB..A.
struct student *read_student(FILE *stream) {
    char line[MAX_LINE_LENGTH];

    if (fgets(line, MAX_LINE_LENGTH, stream) == NULL) {
        return NULL;
    }

    struct student *s = malloc(sizeof (struct student));
    assert(s != NULL);


    char *newline_ptr = strchr(line, '\n');
    assert(newline_ptr);
    *newline_ptr = '\0';

    char *space_ptr = strrchr(line, ' ');
    assert(space_ptr);
    strncpy(s->lab_grades, space_ptr + 1, MAX_GRADE_STRING_LENGTH);
    s->lab_grades[MAX_GRADE_STRING_LENGTH] = '\0';
    *space_ptr = '\0';

    space_ptr = strrchr(line, ' ');
    assert(space_ptr);
    strncpy(s->lab_name, space_ptr + 1, MAX_LAB_NAME_LENGTH);
    s->lab_name[MAX_LAB_NAME_LENGTH] = '\0';
    *space_ptr = '\0';

    space_ptr = strchr(line, ' ');
    assert(space_ptr);
    strncpy(s->name, space_ptr + 1, MAX_STUDENT_NAME_LENGTH);
    s->name[MAX_STUDENT_NAME_LENGTH] = '\0';
    *space_ptr = '\0';

    s->zid = atoi(line);
    s->next = NULL;
    return s;
}


struct student *read_students_stream(FILE *fp) {
	struct student *first = NULL;
	struct student *cur;

	cur = read_student(fp);
	while (cur != NULL) {
		// Add cur to the list
		cur->next = first;
		first = cur;

		cur = read_student(fp);
	}

	return first;
}


struct student *read_students_stream(FILE *fp) {
    struct student *first_student = NULL;
    struct student *last_student = NULL;
    struct student *s;

    while ((s = read_student(fp)) != NULL) {
        if (last_student == NULL) {
            first_student = s;
            last_student = s;
        } else {
            last_student->next = s;
            last_student = s;
        }
    }
    return first_student;
}