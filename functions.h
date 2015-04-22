#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>

char *delete_ext(char file_name[]);
void print_header(FILE *file);
FILE *open_file(char file[], char ext[], char rorw[]);
char *replace_ext(char file[], char ext[]);
int is_a_file(char file_name[]);
void print_comments_in_file(char *current_line, int address,char output_line[]);
char *trans_opcode(char opcode[], char machine_code[]);
int assemble_line(char current_line[], int address,char output_line[]);
void object_machine_code(char current_line[], char machine_code[]);

#define OP_0 "NOP"
#define OP_1 "LDD"
#define OP_2 "LDI"
#define OP_3 "STO"
#define OP_4 "MOV"
#define OP_5 "ADI"
#define OP_6 "ADF"
#define OP_7 "OR"
#define OP_8 "AND"
#define OP_9 "XOR"
#define OP_A "ROR"
#define OP_B "JMP"
#define OP_C "HLT"
#define OP_D "LDX"
#define OP_E "STX"