/*********************************************************************
* Filename:   sha256.c
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Performs known-answer tests on the corresponding SHA1
	          implementation. These tests do not encompass the full
	          range of available test vectors, however, if the tests
	          pass it is very, very likely that the code is correct
	          and was compiled properly. This code also serves as
	          example usage of the functions.
*********************************************************************/

/*************************** HEADER FILES ***************************/
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include "sha256.h"

/*********************** FUNCTION DEFINITIONS ***********************/
void sha256_hasher(BYTE text1[])
{
	BYTE buf[SHA256_BLOCK_SIZE];
	SHA256_CTX ctx;

	sha256_init(&ctx);
	sha256_update(&ctx, text1, strlen(text1));
	sha256_final(&ctx, buf);
	//printf("Hash outputed:\n");
	int i = 0;
	for (; i < sizeof(buf); i++) {
		printf("%02X", buf[i]);
	}
	printf("\n");
	
}

int main(int argc, char* argv[])
{	
	//printf("Programe name: %s\n", argv[0]);
	//printf("Introduced parameter: %s\n", argv[1]);
	(argv[1] != NULL ) ? sha256_hasher(argv[1]) : printf("No input text!! :(\n");

	return(0);
}
