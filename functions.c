#include "functions.h"

void delete_ext(char file_name[])
{
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

	fprintf(file,"%s\t%s\t%s\t\n",header1,header2,header3);
}

void print_comments_in_file(FILE *file, int address, char *current_line)
{
	fprintf( file,"%02d\t\t\t%s", address, current_line);
}

char *trans_opcode(char opcode[])
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
		char *t_opcode;

	if(strcmp(opcode,op0)==0)
	{
		t_opcode="00 00";
	}
	else if(strcmp(opcode,op1)==0)
	{
		t_opcode="18 3C";
	}
	else if(strcmp(opcode,op2)==0)
	{
		t_opcode="25 3C";
	}
	else if(strcmp(opcode,op3)==0)
	{
		t_opcode="3C D2";
	}
	else if(strcmp(opcode,op4)==0)
	{
		t_opcode="4C 70";
	}
	else if(strcmp(opcode,op5)==0)
	{
		t_opcode="5C 3F";
	}
	else if(strcmp(opcode,op6)==0)
	{
		t_opcode="6B 3F";
	}
	else if(strcmp(opcode,op7)==0)
	{
		t_opcode="75 3F";
	}
	else if(strcmp(opcode,op8)==0)
	{
		t_opcode="8C 26";
	}
	else if(strcmp(opcode,op9)==0)
	{
		t_opcode="9C 3F";
	}
	else if(strcmp(opcode,opA)==0)
	{
		t_opcode="AC 02";
	}
	else if(strcmp(opcode,opB)==0)
	{
		t_opcode="BC D2";
	}
	else if(strcmp(opcode,opC)==0)
	{
		t_opcode="C0 00";
	}
	else if(strcmp(opcode,opD)==0)
	{
		t_opcode="D5 C0";
	}
	else if(strcmp(opcode,opE)==0)
	{
		t_opcode="E5 C0";
	}
	else
	{
		t_opcode=opcode;
	}

	return t_opcode;
}
