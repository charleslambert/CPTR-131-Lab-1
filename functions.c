#include "functions.h"

FILE *open_file(char file[], char ext[], char rorw[])
{
	return fopen(replace_ext(file, ext), rorw);
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
		return 0;
	}
}

void print_header(FILE *file)
{
	char header1[4] ="Mem";
	char header2[7] ="Opcode";
	char header3[7] ="Source";

	fprintf(file,"%s\t%s\t%s\t\n",header1,header2,header3);
}

int delete_ext(char file_name[])
{
	//Finds the character derefernces the pointer in order to change
	//the actual value of the char in the file_name.
	if (*strrchr(file_name, '.')=='.')
	{
		*strrchr(file_name, '.') = 0;
		return 0;
	}
	else
	{
		printf("Not a proper file name.\n");
		return 1;
	}
}

char *replace_ext(char file[], char ext[])
{
	char *file_ext;

	delete_ext(file);
	file_ext = strcat(file,ext);

	return file_ext;
}

int trans_opcode(char opcode[])
{
	int t_opcode;

	if(strcmp(opcode,OP_0)==0)
	{
		t_opcode=0;
	}
	else if(strcmp(opcode,OP_1)==0)
	{
		t_opcode=1;
	}
	else if(strcmp(opcode,OP_2)==0)
	{
		t_opcode=2;
	}
	else if(strcmp(opcode,OP_3)==0)
	{
		t_opcode=3;
	}
	else if(strcmp(opcode,OP_4)==0)
	{
		t_opcode=4;
	}
	else if(strcmp(opcode,OP_5)==0)
	{
		t_opcode=5;
	}
	else if(strcmp(opcode,OP_6)==0)
	{
		t_opcode=6;
	}
	else if(strcmp(opcode,OP_7)==0)
	{
		t_opcode=7;
	}
	else if(strcmp(opcode,OP_8)==0)
	{
		t_opcode=8;
	}
	else if(strcmp(opcode,OP_9)==0)
	{
		t_opcode=9;
	}
	else if(strcmp(opcode,OP_A)==0)
	{
		t_opcode=10;
	}
	else if(strcmp(opcode,OP_B)==0)
	{
		t_opcode=11;
	}
	else if(strcmp(opcode,OP_C)==0)
	{
		t_opcode=12;
	}
	else if(strcmp(opcode,OP_D)==0)
	{
		t_opcode=13;
	}
	else if(strcmp(opcode,OP_E)==0)
	{
		t_opcode=14;
	}
	else
	{
		t_opcode=-1;
	}

	return t_opcode;
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
		create_formatted_line_string(current_line, address, output_line);
		address += 2;
	}

	return address;
}

void object_machine_code(char current_line[], char machine_code[])
{
	char *opcode;

	if(current_line[0]!='\n' && current_line[0]!=';')
	{
		create_machine_code(current_line, opcode, machine_code);

		sprintf(machine_code,"%s ",machine_code);
	}
	else
	{
		machine_code[0] = '\0';
	}
}

void create_machine_code(char current_line[], char *opcode, char machine_code[])
{
	char a;
	char b;
	char c;
	char *operands;
	int t_opcode;

	opcode = strtok(current_line,"\t");
	operands = strtok(NULL,"\t");
	t_opcode = trans_opcode(opcode);

	if((t_opcode >= 5) && (t_opcode <= 9))
	{
		sscanf(operands,"R%c, R%c, R%c",&a,&b,&c);
		sprintf(machine_code,"%X%c %c%c",t_opcode,a,b,c);
	}
	else if((t_opcode == 4)||(t_opcode == 13)||(t_opcode == 14))
	{
		sscanf(operands,"R%c, R%c",&a,&b);
		sprintf(machine_code,"%X%c %c0",t_opcode,a,b);
	}
	else if(((t_opcode >= 1)&&(t_opcode <= 3))||(t_opcode == 11))
	{
		sscanf(operands,"R%c, %c%c",&a,&b,&c);
		sprintf(machine_code,"%X%c %c%c",t_opcode,a,b,c);
	}
	else if(t_opcode == 10)
	{
		sscanf(operands,"R%c, %c", &a, &b);
		sprintf(machine_code,"%X%c 0%c",t_opcode,a,b);
 	}
 	else if(t_opcode == -1)
 	{
 		sprintf(machine_code,"");
 	}
	else 
	{
		sprintf(machine_code,"%X0 00",t_opcode);
	}
}

void create_comment_string(char *current_line, int address, char output_line[])
{
	*strrchr(current_line,'\n')='\0';
	sprintf(output_line,"%02X\t\t\t%s\n", address, current_line);
}

void create_empty_line_string(int address, char output_line[])
{
	sprintf(output_line,"%02X\n",address);
}

void create_formatted_line_string(char current_line[], int address, char output_line[])
{
	char *opcode;
	char *source1;
	char *source2;
	char machine_code[MACH_MAX];
	char current_line2[MAXBUF];
	int t_opcode;

	strcpy(current_line2, current_line);

	opcode = strtok(current_line,"\t");
	source1 = strtok(NULL,"\t");
	source2 = strtok(NULL,"\t");
	t_opcode = trans_opcode(opcode);
	create_machine_code(current_line2, opcode, machine_code);

	if(t_opcode == -1)
	{
		sprintf(output_line,"");
	}
	else if(t_opcode == 12 || t_opcode == 0)
	{	
		sprintf(output_line,"%02X\t%s\t%-19s\t%s",address,machine_code,opcode,source1);
	}
	else
	{
		sprintf(output_line,"%02X\t%s\t%s\t%-15s%s",address,machine_code,opcode,source1,source2);
	}
}