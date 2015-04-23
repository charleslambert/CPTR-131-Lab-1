#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>

FILE *open_file(char file[], char ext[], char rorw[]);
int check_file_validity(char file_name[]);
void print_header(FILE *file);
int delete_ext(char file_name[]);
char *replace_ext(char file[], char ext[]);
char *trans_opcode(char opcode[], char machine_code[]);
int assemble_line(char current_line[], int address,char output_line[]);
void object_machine_code(char current_line[], char machine_code[]);
void create_comment_string(char *current_line, int address,char output_line[]);
void create_empty_line_string(int address, char output_line[]);
void create_formatted_line_string(char current_line[], int address, char output_line[]);

#define MAXBUF 1024
#define MACH_MAX 7
#define FILE_N_MAX 20

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