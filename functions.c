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

char *trans_opcode(char opcode[], char machine_code[])
{

	if(strcmp(opcode,OP_0)==0)
	{
		strcpy(machine_code,"00 00");
	}
	else if(strcmp(opcode,OP_1)==0)
	{
		strcpy(machine_code,"1    ");
	}
	else if(strcmp(opcode,OP_2)==0)
	{
		strcpy(machine_code,"2    ");
	}
	else if(strcmp(opcode,OP_3)==0)
	{
		strcpy(machine_code,"3    ");
	}
	else if(strcmp(opcode,OP_4)==0)
	{
		strcpy(machine_code,"4    ");
	}
	else if(strcmp(opcode,OP_5)==0)
	{
		strcpy(machine_code,"5    ");
	}
	else if(strcmp(opcode,OP_6)==0)
	{
		strcpy(machine_code,"6    ");
	}
	else if(strcmp(opcode,OP_7)==0)
	{
		strcpy(machine_code,"7    ");
	}
	else if(strcmp(opcode,OP_8)==0)
	{
		strcpy(machine_code,"8    ");
	}
	else if(strcmp(opcode,OP_9)==0)
	{
		strcpy(machine_code,"9    ");
	}
	else if(strcmp(opcode,OP_A)==0)
	{
		strcpy(machine_code,"A    ");
	}
	else if(strcmp(opcode,OP_B)==0)
	{
		strcpy(machine_code,"B    ");
	}
	else if(strcmp(opcode,OP_C)==0)
	{
		strcpy(machine_code,"C0 00");
	}
	else if(strcmp(opcode,OP_D)==0)
	{
		strcpy(machine_code,"D    ");
	}
	else if(strcmp(opcode,OP_E)==0)
	{
		strcpy(machine_code,"E    ");
	}
	else
	{
		strcpy(machine_code,opcode);
	}

	return machine_code;
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
	char *operands;
	char *operand;


	if(current_line[0]!='\n' && current_line[0]!=';')
	{
		opcode = strtok(current_line,"\t");
		printf("%s\n", opcode);
		operands = strtok(NULL,"\t");
		trans_opcode(opcode,machine_code);
		printf("%c\n",machine_code[0]);
		if(machine_code[0]>='5' || machine_code[0]<= '9')
		{
			exit(0);
			operand = strtok(operands,",");
			//printf("%c\n",operand[1]);
			machine_code[1] = operand[1];
			
			operand = strtok(NULL,",");
			//printf("%c\n",operand[1]);
			machine_code[3] = operand[1];

			operand = strtok(NULL,",");
			machine_code[4] = operand[1];
			exit(0);
		}
		else if(machine_code[0]=='4'||machine_code[0]=='D'||machine_code[0]=='E')
		{
			operand = strtok(operands,",");
			machine_code[1] = operand[1];
			
			operand = strtok(operands,",");
			machine_code[3] = operand[2];

			machine_code[4] = '0';
		}
		else if((machine_code[0]>='1'||machine_code[0]<='3')||machine_code[0]=='B')
		{
			operand = strtok(operands,",");
			printf("Face\n");
			machine_code[1] = operand[2];
			printf("%c",operand[2]);

			exit(0);
			operand = strtok(operands,",");
			machine_code[3] = operand[0];

			machine_code[4] = operand[1];
		}
		else
		{
			printf("dumb");
		}

		/*operand = strtok(current_line, "\t");

		reference = strok(operand,",");
		reg_or_val(reference, machine_code);

		while(reference!=NULL)
		{
			reg_or_val(reference, machine_code);
		}
		*/

		sprintf(machine_code,"%s ",machine_code);
	}
	else
	{
		machine_code[0] = '\0';
	}
}

/*
void reg_or_val(char *reference, char machine_code[])
{
	if(*reference[0]=='R')
	{
		machine_code[]
	}
}
*/


void create_comment_string(char *current_line, int address,char output_line[])
{
	sprintf(output_line,"%02X\t\t\t%s", address, current_line);
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
}

