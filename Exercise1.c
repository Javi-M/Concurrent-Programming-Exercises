/*	Javier Marquez Ruiz
*	Exercise 1 of the Exercises Sheet
*	Comparing 2 strings for equality.
*	If equal, zero is returned;
*	if not, difference between the 2 first
*	different characters returned.
*	This program works as expected.
*/
#include <stdio.h>

#define CONDITIONS cmp == 0 && *ptr1 != '\0' && *ptr2 != '\0'

int compare(char *s1, char *s2);

int main(){
	char s1[100] = "Hola";
	char s2[100] = "Hla";
	
	printf("%i\n", compare(s1,s2));

	return 0;
}

int compare(char *s1, char *s2){
	int cmp = 0;
	char *ptr1 = &s1[0];
	char *ptr2 = &s2[0];

	//*ptr1 is the first character of the string
	//Strings end in '\0'
	while (CONDITIONS){ //This is totally stupid and unnecesary
		if (*ptr1 != *ptr2){
			cmp = *ptr1-*ptr2;
		} 
		ptr1++;
		ptr2++;
	}

	return cmp;
}