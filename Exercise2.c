/*	Exercise 2
*	Exercises Sheet. Lesson 2
*	Javier Marquez
*	Find the first occurrence of a specific character in a given string. 
*	Return a pointer to the occurrence in the string, or zero if it is not found.
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
								//IDK what to do with this...

	return 0;
}