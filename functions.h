#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

void delete_ext(char file_name[]);
void print_header(FILE *file);
FILE *open_file(char file[], char ext[], char rorw[]);
char *replace_ext(char file[], char ext[]);
int is_a_file(char file_name[]);