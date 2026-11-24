CC = gcc
CFLAGS = -Wall -Wextra

TARGET = student

SRC = stud_main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_sort.c stud_save.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c student.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
