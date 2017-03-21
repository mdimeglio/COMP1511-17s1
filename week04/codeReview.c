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
	
	int inputNumber1, inputNumber2, inputNumber3;
	int outputNumber1, outputNumber2, outputNumber3;
	
	//get input and check that three integers were input
	assert((scanf("%d %d %d", &inputNumber1, &inputNumber2, &inputNumber3)) == 3);
	
	//assign input numbers to output numbers in order
	if (inputNumber1 < inputNumber2) {
		
		if (inputNumber1 < inputNumber3) {
			
			//input number 1 is less than input numbers 2 and 3
			outputNumber1 = inputNumber1;
			
			if (inputNumber2 < inputNumber3) {
				
				//input number 1 < input number 2 < input number 3
				outputNumber2 = inputNumber2;
				outputNumber3 = inputNumber3;
				
			} else {
				
				//input number 1 < input number 3 < input number 2
				outputNumber2 = inputNumber3;
				outputNumber3 = inputNumber2;
			
			}
			
		} else {
			
			//input number 3 < input number 1 < inputNumber2
			outputNumber1 = inputNumber3;
			outputNumber2 = inputNumber1;
			outputNumber3 = inputNumber2;
		
		}
		
	} else {
		
		//inputNumber2 < inputNumber1
		
		if (inputNumber2 < inputNumber3) {
			
			//input number 2 is less than input numbers 1 and 3
			outputNumber1 = inputNumber2;
			
			if (inputNumber1 < inputNumber3) {
				
				//input number 2 < input number 1 < input number 3
				outputNumber2 = inputNumber1;
				outputNumber3 = inputNumber3;
				
			} else {
				
				//input number 2 < input number 3 < input number 1
				outputNumber2 = inputNumber3;
				outputNumber3 = inputNumber1;
			
			}
			
		} else {
			
			//input number 3 < input number 2 < inputNumber1
			outputNumber1 = inputNumber3;
			outputNumber2 = inputNumber2;
			outputNumber3 = inputNumber1;
		
		}
		
	}
	
	printf("%d\n\n%d\n\n%d", outputNumber1, outputNumber2, outputNumber3);
	
	return EXIT_SUCCESS;

}
	
	