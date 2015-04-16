#include "test.h"
#include "functions.h"


void main()
{
	test_replace_ext();
	test_delete_ext();
	test_is_a_file();
}

void test_replace_ext()
{
	char file[]="men.amt";
	char file2[]="men.worksaf";
	
	printf("Test replace_ext\n");
	
	printf("Test 1\n");
	replace_ext(file, ".txt");
	printf("%s\n",file);
	assert(strcmp(file,"men.txt"));

	
	printf("test 2\n");
	replace_ext(file2, ".ast");
	assert(strcmp(file2,"men.ast"));
	
	printf("Tests Passed\n\n");
}

void test_delete_ext()
{
	char file[]="file.txt";
	
	printf("Test delete_ext");
	
	printf("Test 1\n");
	delete_ext(file);
	assert(strcmp(file,"file"));
	
	printf("Tests Passed\n\n");
}

void test_is_a_file()
{
	char file[]= "file.txt";
	char file2[]= "file";
	
	printf("Test is_a_file");
	
	printf("Test 1\n");
	assert(is_a_file(file)==1);
	
	printf("Test2\n");
	assert(is_a_file(file2)==0);
	
	printf("Tests Passed\n\n");
	
}