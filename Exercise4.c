/*
 ============================================================================
 Name        : Exercise4.c
 Author      : Javier Márquez
 Version     :
 Copyright   : 
 Description : Exercise 4 from topic 2's exercises sheet. 
 Take two strings as arguments. 
 If the first exists in the second as a substring,
 return a pointer to the first occurrence, otherwise zero
 ============================================================================
 */

#include <stdio.h>

int isPrefix(char s1[], char s2[]){
	int n = 1;
	char *cmp1, *cmp2;
	cmp1 = &s1[0];
	cmp2 = &s2[0];
	while (*cmp1 != '\0' && *cmp2 != '\0' && n){
		n = *cmp1 == *cmp2;
		cmp1++;
		cmp2++;
		if(*cmp1 != '\0' && *cmp2 == '\0')
			n = 0;
	}
	return n;
}


char *firstOccurrence(char s1[], char s2[]){
	int n = 0;
	int found = 0;
	while (!isPrefix(s1,s2+n) && *(s2+n) != '\0'){
		n++;
	}
	if (isPrefix(s1, s2+n))
		return s2+n;
	else
		return NULL;
}



int main(){
	char s3[] = "Cadena de prueba";
	printf("%s\n", s3);
	printf("%s\n", s3+1);
	//Probando "truncar" una cadena. Funciona.

	int found = 1;
	char s1[] = "la mund";
	char s2[] = "Hola mundo";
	char *occ = firstOccurrence(s1,s2);

	//Testing firstOccurrence():
	printf("%s\n", occ);
	printf("%c\n", *occ);
	
	char *l = &s2[2]; 							//Address to first occurrence.
	printf("%i\n", l);							//The number printed (address) must be the same.
	printf("%i\n", firstOccurrence(s1,s2)); 	//Warnings will appear.

	return 0;
}

//I think it works...
