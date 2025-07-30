// London Sheard
// 2025-07-30

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc != 2) {
	fprintf(stderr, "Expected one input file\n");
	return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (!file) {
	char errormsg[256];
	snprintf(errormsg, sizeof errormsg, "Could not open file `%s`", argv[1]);
	perror(errormsg);
	return 1;
    }
    fseek(file, 0, SEEK_END);
    long int fsize = ftell(file);
    rewind(file);

    char* buffer = malloc(fsize + 1);
    if (!buffer) {
	fprintf(stderr, "Failed to allocate enough memory for string\n");
	return 1;
    }

    size_t csize = fread(buffer, 1, fsize, file);

    buffer[csize] = '\0';

    if(buffer[csize -1] == '\n') {
	buffer[csize -1] = '\0';
    }

    printf("%s", buffer);

    return 0;
}
