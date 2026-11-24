#ifndef STUDENT_H
#define STUDENT_H
struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
};

extern struct student *head;
void add_student(void);
int generate_rollno(void);
void delete_student(void);
void display_student(void);
void modify_student(void);
void sort_student(void);
void reverse_student(void);
void delete_all(void);
void save_student(void);
void load_student(void);
#endif
