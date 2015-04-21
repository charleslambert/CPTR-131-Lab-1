#include "functions.h"

int main(int argc, char *argv[])
{
	char file[20];
	FILE *file_asm;
	FILE *file_obj;
	FILE *file_lst;
	char *t_opcode;
	int address;
	char *opcode;
	char *source1;
	char *source2;
	char current_line[100];

	
	printf("What file would you like to assemble? :");
	scanf("%s", file);
	if(is_a_file(file)==0)
	{
			exit(1);
	}
	
	file_asm = open_file(file, ".asm", "r");
	file_obj = open_file(file, ".obj", "w");
	file_lst = open_file(file, ".lst", "w");

	print_header(file_lst);
	
	address = 0;
	while(fgets(current_line, 100,file_asm)!=NULL)
	{	
		if(current_line[0]==';')
		{
			print_comments_in_file(file_lst, address, current_line);
		}
		else if(current_line[0]=='\n')
		{
			fprintf(file_lst,"%02X\n",address);
		}
		else
		{
			opcode = strtok(current_line,"\t");
			source1 = strtok(NULL,"\t");
			source2 = strtok(NULL,"\t");
			
			t_opcode=trans_opcode(opcode);

			
			if(strcmp(opcode,"HLT")==0 || strcmp(opcode,"NOP")== 0)
			{
				fprintf(file_lst, "%02X\t%s\t%-19s%s",address,t_opcode,opcode,source1);
			}
			else
			{
				fprintf(file_lst, "%02X\t%s\t%s %-15s%s",address,t_opcode,opcode,source1,source2);
			}
			
			fprintf(file_obj,"%s ",t_opcode);

			address +=2;
		}
	}

	return 0;
}
