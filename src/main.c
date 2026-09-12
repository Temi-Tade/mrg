/**
** mrg - A CLI tool for merging source files into a target file
** Usage: mrg <file1> <file2> ... <fileN> <target>
**/

#include <stdio.h>

int check_file(FILE *fp, char *name);
void read_file(FILE *fp, char *name, FILE *out);

int check_file(FILE *fp, char *name) {
	printf("Checking '%s'...\n", name);
	if (fp == NULL) {
		printf("Could not open file: '%s'\n", name);
		return 1;
	}

	return 0;
}

void read_file(FILE *fp, char *name, FILE *out) {
	printf("Reading '%s'...\n", name);

	int c;
	while((c = fgetc(fp)) != EOF) {
		fprintf(out, "%c", c);
	}
}

int main(int argc, char* argv[]) {
	if (argc < 4) {
		printf("Usage: mrg <file1> <file2> ... <fileN> <target>\n");
		return 1;
	}

	FILE *source_files[argc];

	for (int i = 0; i < argc; i++) {
		if (i == 0) {
			printf("Opening target file: '%s'...\n", argv[argc - 1]);
			source_files[argc - 1] = fopen(argv[argc - 1], "w"); // open target file
			check_file(source_files[argc - 1], argv[argc - 1]); // check 

			continue; // skip program
		}

		if (i != argc - 1) {
			printf("Opening '%s'...\n", argv[i]);
			source_files[i] = fopen(argv[i], "r"); // add to array
			check_file(source_files[i], argv[i]); // check
			read_file(source_files[i], argv[i], source_files[argc - 1]); // read and write to target
		}
	}
	
	for (int i = 1; i < argc; i++) {
		if (source_files[i] != NULL) {
			printf("Closing '%s'...\n", argv[i]);
			fclose(source_files[i]);
		}
	}

	return 0;
}