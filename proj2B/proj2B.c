#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	/* abort if incorrect number of args */
	if(argc != 3){
	printf("Usage: proj2B <input file> <output file>");
	return 0;
	}
	
	FILE *input;
	FILE *output;
	/* update to handle argv */
	input = fopen(argv[1], "r");
	output = fopen(argv[2], "w");
	int *array = malloc(sizeof(int)*5);
	int i = 0;
	for(i = 0; i<5; i++){
		fseek(input, i*40, SEEK_SET);
		fread(array, sizeof(int), 5, input);
		int j = 0;
		for(j = 0; j<5; j++){
			fprintf(output, "%d\n", array[j]);
		}
	}
	free(array);
	fclose(input);
	fclose(output);

}
