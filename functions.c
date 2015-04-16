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
	char header[] ="Mem\tOpcode\tSource";
	
	fprintf(file,"%s\n",header);
}

void print_comments_in_file(FILE *file, char *address, char *current_line)
{
	fprintf( file,"%s\t\t\t\t\t%s", address, current_line);
}