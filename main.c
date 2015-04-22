#include "functions.h"
#define MAXBUF 1024
#define MACH_MAX 7
#define FILE_N_MAX 20

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

	//Take in input and check that the input is a valid file_name
	printf("What file would you like to assemble? :");
	scanf("%s", file);
	if(is_a_file(file)==0)
	{
			exit(1);
	}
	
	//Open input file and create files to be written in
	file_asm = open_file(file, ".asm", "r");
	file_obj = open_file(file, ".obj", "w");
	file_lst = open_file(file, ".lst", "w");

	print_header(file_lst);

	//Loop through each line of text and extract the text
	while(fgets(current_line, MAXBUF, file_asm)!=NULL)
	{	
		//Passed text is evaluated and an approriate output string is created
		address=assemble_line(current_line,address, output_line);
		object_machine_code(current_line, machine_code);

		//Output is printed into files
		fputs(output_line,file_lst);
		fprintf(file_obj,"%s", machine_code);
	}

	//Close all files
	fclose(file_asm);
	fclose(file_obj);
	fclose(file_lst);

	return 0;
}