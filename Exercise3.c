/*
*Exercise 3
*Exercise sheet
*Javier Marquez.
*If first chain is larger, not accepted as prefix???.
*ignorin how shitti are the conditions in the loop, it works.
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




int main(int argc, char const *argv[]){
	char s1[20] = "abcdefgha";
	char s2[20] = "abcdefgh";
	int n = 2;
	n = isPrefix(s1,s2);
	printf("%i\n", n);

	return 0;
}