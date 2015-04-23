#include "functions.h"

int main(int argc, char *argv[])
{
	char file[FILE_N_MAX];
	FILE *file_asm;
	FILE *file_obj;
	FILE *file_lst;
	int address = 0;
	char current_line[MAXBUF];
	char output_line[MAXBUF];
	char machine_code[MACH_MAX];

	//Take in input and check that the input is a valid file_name.
	printf("What file would you like to assemble? :");
	scanf("%s", file);
	if (check_file_validity(file)==0)
	{
		exit(1);
	}
	
	//Open input file and create files to be written in.
	file_asm = open_file(file, ".asm", "r");
	file_obj = open_file(file, ".obj", "w");
	file_lst = open_file(file, ".lst", "w");

	print_header(file_lst);

	//Iterate through each line of text from .asm file and extract the text as string.
	while(fgets(current_line, MAXBUF, file_asm)!=NULL)
	{	
		//Passed text is evaluated and an approriate output string is created.

		//converts opcodes into machine codes and formats given comments and variables into readable format.
		//outputs a string to be printed into .lst file.
		//assemble_line returns the address for the next line in the output.
		address=assemble_line(current_line, address, output_line);

		//object_machine_code converts opcodes into machine code and outputs result as string to be printed into .obj file.
		object_machine_code(current_line, machine_code);

		//Output strings are printed into approriate files.
		fputs(output_line, file_lst);
		fprintf(file_obj, "%s", machine_code);
	}

	//Close all files.
	fclose(file_asm);
	fclose(file_obj);
	fclose(file_lst);

	return 0;
}