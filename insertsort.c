#include "insertsort.h"
#include "main.h"
#include <stdio.h>

void InsertSort(Element ** Array, int size, CompFunc cmp){
	int i,j,ret;
	if(size == 1)
		return;
	printf("The size of array is %d\n",size);
	for (j=1;j<size;j++){
		Element *key = Array[j];
		printf("selecting Array[%d]=%s\n",j,Array[j]->text);
		i = j-1;
		while (i>=0 && (ret = cmp(Array[i],key))>0){
			printf("\tCompared Array[%d]->text=%s, key[%d]->text=%s -> ret=%d\n",i,Array[i]->text,j,key->text,ret);
			Array[i+1] = Array[i];
			i--;
		}	
		Array[++i] = key;
		printf("\tinserting key %s at %d\n",key->text,i);
	}
}
