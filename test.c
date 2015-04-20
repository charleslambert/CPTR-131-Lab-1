#include "test.h"
#include "functions.h"


void main()
{
	test_replace_ext();
	test_delete_ext();
	test_is_a_file();
	test_trans_opcode();
}

void test_replace_ext()
{
	char file[7]="men.amt";
	char file2[7]="men.stf";
	
	printf("\nTest replace_ext\n");
	
	printf("Test 1\n");
	replace_ext(file, ".txt");
	printf("%s\n",file);
	assert(strcmp(file,"men.txt"));
	
	printf("test 2\n");
	replace_ext(file2, ".ast");
	assert(strcmp(file2,"men.ast "));
	
	printf("Tests Passed\n\n");
}

void test_delete_ext()
{
	char file3[]="file.txt";
	
	printf("Test delete_ext\n");
	
	printf("Test 1\n");
	delete_ext(file3);
	printf("%s\n",file3);
	assert(strcmp(file3,"file    "));
	
	printf("Tests Passed\n\n");
}

void test_is_a_file()
{
	char file4[]= "file.txt";
	char file5[]= "file";
	
	printf("Test is_a_file");
	
	printf("Test 1\n");
	assert(is_a_file(file4)==1);
	
	printf("Test2\n");
	assert(is_a_file(file5)==0);
	
	printf("Tests Passed\n\n");
}

void test_trans_opcode()
{
	char op[3]="NOP";
	char top[5];
	
	printf("Test trans_opcode\n");
	
	printf("Test 1\n");
	trans_opcode(op,top);
	assert(strcmp(top,"00 00"));
	
	printf("Tests Passed\n\n");
}