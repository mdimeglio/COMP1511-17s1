//By Matthew Di Meglio, 22/03/13
//This program sorts 3 numbers

//tests
//"8 5 9" -> "5\n8\n9"
//"8 9 5" -> "5\n8\n9"
//"9 5 8" -> "5\n8\n9"
//"9 8 5" -> "5\n8\n9"
//"5 8 9" -> "5\n8\n9"
//"5 9 8" -> "5\n8\n9"
//"9 9 9" -> "9\n9\n9"
//"9 8 9" -> "8\n9\n9"
//"3.7 2 5" -> assert error
//"c d e" -> assert error

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char *argv[]) {
	
	int a, b, c, temp;
	
	//get input and check that three integers were input
	assert(scanf("%d %d %d", &a, &b, &c) == 3);
	
	if (a > b) {
		temp = a;
		a = b;
		b = temp;
	}

	if (b > c) {
		temp = b;
		b = c;
		c = temp;
	}

	if (a > b) {
		temp = a;
		a = b;
		b = temp;
	}

	printf("%d %d %d", a, b, c);

	return EXIT_SUCCESS;

}
	
	