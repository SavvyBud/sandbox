#include "main.h"
#include "insertsort.h"

#define MAX_ITEM_SIZE 500
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "insertsort.h"


int LoadArray(char *fileName, int maxItems, Element ***Array){
	FILE *inFile;
	char buffer[MAX_ITEM_SIZE], *s;
	int i;
	if((inFile = fopen(fileName,"r")) ==NULL){
		fprintf(stderr, "Failed to open file %s\n",fileName);
		return (-1);
	}

	*Array = malloc(sizeof(Element **)*maxItems);
	if (*Array == NULL){
		fprintf(stderr, "Failed to malloc\n");
		return (-1);
	}
	i=0;
	while(fgets(buffer,MAX_ITEM_SIZE,inFile)){
		if ( i >= maxItems) {
			fprintf(stdout, "Entire datafile not loaded\n");
			break;
		}
		/* trim trailing control char*/
		s = buffer + strlen(buffer);
		while(iscntrl(*s))
			*s-- = 0;
		
		/* make space and store it */	
		(*Array)[i] = malloc(sizeof(Element));
		
		if( (*Array)[i] == NULL){
			fprintf(stderr, "Failed to malloc\n");
			return (-1);
		}
		(*Array)[i]->text = malloc((strlen(buffer)+1)*sizeof(char));
		if( (*Array)[i]->text == NULL){
			fprintf(stderr, "Failed to malloc\n");
			return (-1);
		}
		strcpy((*Array)[i++]->text,buffer);
	}

	if( i==1 && *((*Array)[0]->text) == 0)
		i = 0;
	fclose(inFile);
	return i;
}

void ShowArray(Element **Array, int items, CompFunc Compare){
	int i, sorted =1, column =1;
	for (i=0;i<items;i++){
		if(column > 61){
			printf("\n");
			column =1 ;
		}
		else while((column -1)% 20){
			printf(" ");
			column++;
		}
		printf("%3d: %s",i,Array[i]->text);
		column += 5 + strlen(Array[i]->text);
		
		if( i > 0){
			if(Compare(Array[i-1],Array[i])>0)
				sorted = 0;
		}
	}
	if(sorted)
		printf("\n\nThe array is sorted\n");
	else
		printf("\n\nThe array is not sorted\n");
}

int StringCmp(Element *L, Element *R){
	return (strncmp(L->text,R->text,5));
}

int main(int argc, char **argv) {
	Element **Array;
	int items = 2000;
	if(argc != 2 && argc != 3){
		fprintf(stderr,"Usage %s inFile [maxitems]\n",argv[0]);
		return 0;
	}
	if (argc == 3)
		items = atoi(argv[2]);
	
	if(( items = LoadArray(argv[1],items,&Array)) == -1){
		return -1;
	}
	InsertSort(Array,items,(CompFunc)StringCmp);
	ShowArray(Array,items,(CompFunc)StringCmp);
	return 1;
}
