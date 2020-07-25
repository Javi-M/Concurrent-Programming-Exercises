/*
 ============================================================================
 Name        : Exercise2.c
 Author      : Javier Márquez
 Version     : 1

 Description : Exercise 2 from topic 2's exercises sheet. 
 Find first occurrence of a character in a string.
 	Return a pointer to the occurrence in the string.
	0 if not found.
This program does not work as expected!
 ============================================================================
 */

#include <stdio.h>

void firstOccurrence(char c, char s[], int *found, void *occurrence){
	char *checker = &s[0];
	*found = 0;
	while (*checker != '\0' && !*found){
		if (*checker == c){
			*found = 1;
			occurrence = checker;
		} else
			checker++;
	}
}

int main(){
	char s[] = "abcdefghijklmnopqrstuvwx";
	int f = 0;
	void *occurrence;
	firstOccurrence('x', s, &f, occurrence);
	printf("Found? : %i\n", f);

	printf("%i\n", occurrence); //Occurence has the addres.

	return 0;
}
