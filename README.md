# Student Record Management System

## Project Overview

The **Student Record Management System** is a menu-driven application developed using C programming. It uses a **Singly Linked List** to manage student records dynamically and file handling to store and retrieve student information.

The project follows a modular programming approach, with separate source files for different operations.

## Features

1. Add new student records with automatically generated unique roll numbers.
2. Display all student records in a formatted table.
3. Delete student records by roll number or name.
4. Handle duplicate student names by selecting records using roll numbers.
5. Modify student details by searching through roll number, name, or percentage.
6. Sort student records alphabetically by name.
7. Sort student records by percentage in descending order.
8. Reverse the singly linked list.
9. Delete all student records.
10. Save student records into a file named `student.dat`.
11. Automatically load previously saved records when the application starts.
12. Release dynamically allocated memory before program termination.

## Technologies and Concepts Used

- C Programming
- Structures
- Pointers
- Singly Linked Lists
- Dynamic Memory Allocation (`malloc`, `free`)
- File Handling (`fopen`, `fprintf`, `fgets`, `sscanf`, `fclose`)
- Modular Programming
- Makefile and GCC Compiler

## Project Structure

```text
Student-Record-Management-System/
│
├── student.h
├── stud_main.c
├── stud_add.c
├── stud_del.c
├── stud_show.c
├── stud_mod.c
├── stud_sort.c
├── stud_save.c
└── Makefile
```

## Module Description

| File | Description |
|---|---|
| `student.h` | Structure definition and function declarations |
| `stud_main.c` | Main menu and program execution |
| `stud_add.c` | Add student records and generate roll numbers |
| `stud_del.c` | Delete individual or all student records |
| `stud_show.c` | Display and reverse student records |
| `stud_mod.c` | Modify student information |
| `stud_sort.c` | Sort student records |
| `stud_save.c` | Save and load student records |
| `Makefile` | Automate compilation and cleanup |

## Compilation

Make sure GCC and GNU Make are installed.

Compile the project using:

```bash
make
```

To remove generated object files and the executable:

```bash
make clean
```

## Execution

Run the application using:

```bash
./student
```

## Menu Options

| Option | Operation |
|---|---|
| A/a | Add Student |
| D/d | Delete Student |
| S/s | Show Student Records |
| M/m | Modify Student |
| V/v | Save Records |
| T/t | Sort Records |
| L/l | Delete All Records |
| R/r | Reverse Linked List |
| E/e | Exit |

### File Handling

Student records are stored in `student.dat`.

- Existing records are automatically loaded when the application starts.
- The Save option stores the current records.
- Save and Exit saves the records before terminating.
- Exit without Saving terminates without writing the current changes to the file.

## Memory Management

Student records are maintained using dynamically allocated linked-list nodes.

Memory is released when individual records are deleted, all records are deleted, or the application exits.

The application was tested using **Valgrind**.

Memory testing results:

```text
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

## Author

Developed as a C Programming Mini Project.
