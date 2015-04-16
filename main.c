#include "functions.h"

int main(int argc, char *argv[])
{
	char file[20];
	FILE *file_asm;
	FILE *file_obj;
	FILE *file_lst;
	char *opcode;
	char *address;
	char *source;
	char current_line[100];
	int count=0;
	
	
	printf("What file would you like to assemble? :");
	scanf("%s", file);
	if(is_a_file(file)==0)
	{
			exit(1);
	}
	
	file_asm = open_file(file, ".asm", "r");
	file_obj = open_file(file, ".obj", "w");
	file_lst = open_file(file, ".lst", "w");
	
	print_header(file_obj);
	print_header(file_lst);
	
	address = "00";
	while(count<20)
	{
		fgets(current_line, 100,file_asm);
		
		if(current_line[0]==';')
		{
			print_comments_in_file(file_lst, address, current_line);
			printf("%s\n",current_line);
		}
		else
		{
			
		}
	count++;
	address++;
	}
}
