#include <stdio.h>

int main(void) {
	int whiteSpaceCount;
    int wordMinLength, wordMaxLength, wordCurrentLength;
    int wordCount;
    int ch;

    wordCount = 0;
    whiteSpaceCount = 0;
    wordCurrentLength = 0;

    //Calculate statistics here
    //Use getchar in a loop
    ch = getchar();
    while(ch != EOF) {
    	if (ch == ' ' || ch == '\n' || ch == '\t') {
    		whiteSpaceCount = whiteSpaceCount+1;
    		if (wordCurrentLength > 0) {
    			wordCurrentLength = 0;
    		}
    	} else {
    		if (wordCurrentLength == 0) {
    			wordCount = wordCount + 1;
    		}
    		wordCurrentLength = wordCurrentLength+1;
    	}
    	ch = getchar();
    }



    printf("Input contains %d blanks, tabs and new lines\n", whiteSpaceCount);

    if (wordCount == 0) {
        printf("No word has been input\n");
    } else {
        printf("Number of words: %d\n", wordCount);
        printf("Length of shortest word: %d\n", wordMinLength);
        printf("Length of longest word: %d\n", wordMaxLength);
    }

    return 0;
}