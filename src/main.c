#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <stdlib.h>

#include "common.h"
#include "file.h"
#include "parse.h"

void print_usage(char *argv[]) {

	printf("Usage: %s -n -f <database file>\n", argv[0]);
	printf("\t -n  - create new database file\n");
	printf("\t -f  - (required) path to database file\n");
	
}

int main(int argc, char *argv[]) { 

	char *filePath = NULL;
	bool newFile = false;
	bool list = false;
	int retOption;

	while ((retOption = getopt(argc, argv, "nf:a:l")) != -1) {
		switch (retOption) {
			case 'n':
				newFile = true;
				break;
			case 'f':
				filePath = optarg;
				break;
			case '?':
				printf("Unknown option -%c\n", retOption);
				break;
			default:
				return -1;

		}
	}

	if (filePath == NULL){
		printf("File path is a required argument\n");
		print_usage(argv);

		return 0;
	}

	printf("Newfile %d\n", newFile);
	printf("Filepath %s\n", filePath);
	
	return 0;
}
