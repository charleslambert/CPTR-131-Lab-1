#include "functions.h"
#define MAXBUF 1024

int main(int argc, char *argv[])
{
	char file[20];
	FILE *file_asm;
	FILE *file_obj;
	FILE *file_lst;
	int address;
	char current_line[MAXBUF];
	char output_line[MAXBUF];
	char machine_code[7];

	
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

	while(fgets(current_line, MAXBUF, file_asm)!=NULL)
	{	
		address=assemble_line(current_line,address, output_line);
		object_machine_code(current_line, machine_code);

		fputs(output_line,file_lst);
		fprintf(file_obj,"%s", machine_code);
	}

	fclose(file_asm);
	fclose(file_obj);
	fclose(file_lst);

	return 0;
}