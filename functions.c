#include "functions.h"

void delete_ext(char file_name[])
{
	int i = 0;
	
	*strrchr(file_name, '.') = 0;
}

int is_a_file(char file_name[])
{
	if (strrchr(file_name,'.')!=NULL)
	{
		return 1;
	}
	else
	{
		printf("This is not a proper file name\n");
		return 0;
	}
}


FILE *open_file(char file[], char ext[], char rorw[])
{
	return fopen(replace_ext(file, ext), rorw);
}

char *replace_ext(char file[], char ext[])
{
	delete_ext(file);
	strcat(file,ext);
	
	return file;
}

void print_header(FILE *file)
{
	char header1[] ="Mem";
	char header2[] ="Opcode";
	char header3[] ="Source";
	
	fprintf(file,"%-12s%-12s%-12s\n",header1,header2,header3);
}

void print_comments_in_file(FILE *file, int address, char *current_line)
{
	fprintf( file,"%02d                             %s", address, current_line);
}

void trans_opcode(char opcode[], char *t_opcode)
{
		char op0[]="NOP";
		char op1[]="LDD";
		char op2[]="LDI";
		char op3[]="STO";
		char op4[]="MOV";
		char op5[]="ADI";
		char op6[]="ADF";
		char op7[]="OR";
		char op8[]="AND";
		char op9[]="XOR";
		char opA[]="ROR";
		char opB[]="JMP";
		char opC[]="HLT";
		char opD[]="LDX";
		char opE[]="STX";
	
	if(strcmp(opcode,op0)==0)
	{
		strcmp(t_opcode,"00 00");
	}
	else if(strcmp(opcode,op1)==0)
	{
		strcpy(t_opcode,"18 3C");
	}
	else if(strcmp(opcode,op0)==0)
	{
		strcmp(t_opcode,"25 3C");
	}
	else if(strcmp(opcode,op0)==0)
	{
		strcmp(t_opcode,"3C D2");
	}
	else if(strcmp(opcode,op0)==0)
	{
		strcmp(t_opcode,"4C 70");
	}
	else if(strcmp(opcode,op0)==0)
	{
		strcmp(t_opcode,"5C 3F");
	}
	else if(strcmp(opcode,op0)==0)
	{
		strcmp(t_opcode,"6B 3F");
	}
	else if(strcmp(opcode,op0)==0)
	{
		strcmp(t_opcode,"75 3F");
	}
	else if(strcmp(opcode,op0)==0)
	{
		strcmp(t_opcode,"8C 26");
	}
	else if(strcmp(opcode,op0)==0)
	{
		strcmp(t_opcode,"9C 3F");
	}
	else if(strcmp(opcode,op0)==0)
	{
		strcmp(t_opcode,"AC 02");
	}
	else if(strcmp(opcode,op0)==0)
	{
		strcmp(t_opcode,"BC D2");
	}
	else if(strcmp(opcode,op0)==0)
	{
		strcmp(t_opcode,"C0 00");
	}
	else if(strcmp(opcode,op0)==0)
	{
		strcmp(t_opcode,"D5 C0");
	}
	else if(strcmp(opcode,op0)==0)
	{
		strcmp(t_opcode,"E5 C0");
	}
	else
	{
		strcmp(t_opcode,"FAIL!");
	}
}