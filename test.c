#include "test.h"
#include "functions.h"


int main()
{
	test_check_file_validity();
	//test_replace_ext();
	test_delete_ext();
	//test_is_a_file();
	test_trans_opcode();
	//test_assemble_line();
	return 0;
}

void test_check_file_validity()
{
	char file1[9] = "test.c";
	char file2[5] = "file";
	char file3[1] = "";

	printf("Test check_file_validity\n");
	
	printf("Test 1\n");
	assert(check_file_validity(file1)==1);
	
	printf("Test 2\n");
	assert(check_file_validity(file2)==0);

	printf("Test 3\n");
	assert(check_file_validity(file3)==0);
	
	printf("All Tests Passed\n\n");
}

void test_delete_ext()
{
	char file1[20] = "file.txt";
	char file2[20] = "file.txt.asm";
	char file3[20] = "file";
	
	printf("Test delete_ext\n");
	
	printf("Test 1\n");
	assert(delete_ext(file1)==0);
	assert(strcmp(file3,"file    "));

	printf("Test 2\n");
	assert(delete_ext(file2)==0);
	assert(strcmp(file1,"file.txt    "));

	/*printf("Test 3\n");
	assert(delete_ext(file3)==1);
	printf("su");
	assert(strcmp(file3,"file"));
	*/
	printf("All Tests Passed\n\n");
}

void test_replace_ext()
{
	char file[20]="men.amt";
	char file2[20]="men.stf";
	
	printf("\nTest replace_ext\n");
	
	printf("Test 1\n");
	assert(strcmp(replace_ext(file, ".txt"),"men.txt"));
	
	printf("test 2\n");
	assert(strcmp(replace_ext(file2, ".ast"),"men.ast "));
	
	printf("All Tests Passed\n\n");
}

void test_trans_opcode()
{
	char op1[4]="NOP";
	char op2[4]="OR";
	char op3[4]="DDD";
	char M[10];
	
	printf("Test trans_opcode\n");
	
	printf("Test 1\n");
	trans_opcode(op1, M);
	assert(strcmp(M,"00 00  "));

	printf("Test 2\n");
	trans_opcode(op2, M);
	assert(strcmp(M,"75 3F  "));

	printf("Test 3\n");
	trans_opcode(op3, M);
	assert(strcmp(M,"DDD "));

	printf("All Tests Passed\n\n");
}

void test_create_comment_string()
{

}

void test_create_empty_line_string()
{

}

void test_create_formatted_line_string()
{

}