#include "functions.h"

int delete_ext(char file_name[])
{
	if (access(file_name,F_OK)==0)
	{
		*strrchr(file_name, '.') = 0;
		return 0;
	}
	else
	{
		printf("Not a proper file name.");
		return 1;
	}
	

	return file_name;
}

int check_file_validity(char file_name[])
{
	if (access(file_name,F_OK)==0)
	{
		return 1;
	}
	else
	{
		printf("This is not a proper file name\n");
		exit(1);
		return 0;
	}
}


FILE *open_file(char file[], char ext[], char rorw[])
{
	return fopen(replace_ext(file, ext), rorw);
}

char *replace_ext(char file[], char ext[])
{
	char *file_ext;

	delete_ext(file);
	file_ext = strcat(file,ext);

	return file_ext;
}

void print_header(FILE *file)
{
	char header1[4] ="Mem";
	char header2[7] ="Opcode";
	char header3[7] ="Source";

	fprintf(file,"%s\t%s\t%s\t\n",header1,header2,header3);
}

char *trans_opcode(char opcode[], char machine_code[])
{

	if(strcmp(opcode,OP_0)==0)
	{
		strcpy(machine_code,"00 00");
	}
	else if(strcmp(opcode,OP_1)==0)
	{
		strcpy(machine_code,"18 3C");
	}
	else if(strcmp(opcode,OP_2)==0)
	{
		strcpy(machine_code,"25 3C");
	}
	else if(strcmp(opcode,OP_3)==0)
	{
		strcpy(machine_code,"3C D2");
	}
	else if(strcmp(opcode,OP_4)==0)
	{
		strcpy(machine_code,"4C 70");
	}
	else if(strcmp(opcode,OP_5)==0)
	{
		strcpy(machine_code,"5C 3F");
	}
	else if(strcmp(opcode,OP_6)==0)
	{
		strcpy(machine_code,"6B 3F");
	}
	else if(strcmp(opcode,OP_7)==0)
	{
		strcpy(machine_code,"75 3F");
	}
	else if(strcmp(opcode,OP_8)==0)
	{
		strcpy(machine_code,"8C 26");
	}
	else if(strcmp(opcode,OP_9)==0)
	{
		strcpy(machine_code,"9C 3F");
	}
	else if(strcmp(opcode,OP_A)==0)
	{
		strcpy(machine_code,"AC 02");
	}
	else if(strcmp(opcode,OP_B)==0)
	{
		strcpy(machine_code,"BC D2");
	}
	else if(strcmp(opcode,OP_C)==0)
	{
		strcpy(machine_code,"C0 00");
	}
	else if(strcmp(opcode,OP_D)==0)
	{
		strcpy(machine_code,"D5 C0");
	}
	else if(strcmp(opcode,OP_E)==0)
	{
		strcpy(machine_code,"E5 C0");
	}
	else
	{
		strcpy(machine_code,opcode);
	}

	return machine_code;
}

void create_comment_string(char *current_line, int address,char output_line[])
{
	sprintf(output_line,"%02X\t\t\t%s", address, current_line);
}

void create_empty_line_string(int address, char output_line[])
{
	sprintf(output_line,"%02X\n",address);
}

void create_formated_line_string(char current_line[], int address, char output_line[])
{
	char *opcode;
	char *source1;
	char *source2;
	char machine_code[MACH_MAX];

	opcode = strtok(current_line,"\t");
	source1 = strtok(NULL,"\t");
	source2 = strtok(NULL,"\t");
	
	strcpy(machine_code,trans_opcode(opcode,machine_code));
		
	if(strcmp(opcode,"HLT")== 0 || strcmp(opcode,"NOP")== 0)
	{
		sprintf(output_line,"%02X\t%s\t%-19s%s",address,machine_code,opcode,source1);
	}
	else
	{
		sprintf(output_line,"%02X\t%s\t%s\t%-15s%s",address,machine_code,opcode,source1,source2);
	}

	address += 2;
}

int assemble_line(char current_line[], int address, char output_line[])
{
	if(current_line[0]==';')
	{
		create_comment_string(current_line, address, output_line);
	}
	else if(current_line[0]=='\n')
	{
		create_empty_line_string(address, output_line);
	}
	else
	{
		create_formated_line_string(current_line, address, output_line);
	}

	return address;
}

void object_machine_code(char current_line[], char machine_code[])
{
	char *opcode;

	if(current_line[0]!='\n' && current_line[0]!=';')
	{
		opcode = strtok(current_line,"\t");
		sprintf(machine_code,"%s ",trans_opcode(opcode,machine_code));
	}
	else
	{
		machine_code[0] = '\0';
	}
}