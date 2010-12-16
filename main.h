#ifndef __MAIN__
#define __MAIN__
typedef int (*CompFunc)(void * L, void *R);

typedef struct tElement {
	char * text;
} Element;

int LoadArray(char *fileName, int maxItems, Element ***Array);
void ShowArray(Element **Array, int items, CompFunc Compare);
#endif

