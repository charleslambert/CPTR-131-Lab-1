#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

void delete_ext(char file_name[]);
void print_header(FILE *file);
FILE *open_file(char file[], char ext[], char rorw[]);
char *replace_ext(char file[], char ext[]);
int is_a_file(char file_name[]);
void print_comments_in_file(FILE *file, int address, char *current_line);
void trans_opcode(char opcode[],char t_opcode[]);