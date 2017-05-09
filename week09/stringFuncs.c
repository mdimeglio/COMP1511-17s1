#include <stdio.h>
#include <stdlib.h>

//strncpy
// Copies at most n-1 characters from src to dest
// (or if src is shorter, all characters in src)
// and adds null terminator
// and returns a pointer to the null terminator of the string
char *cpynstr(char *src, char *dest, int n) {
  int i = 0;
  while(i < n) {
    dest[i] = src[i];
    i++;
  }
  return &dest[i];
}

char *dupstr(char *src) {
    int len = strlen(src);
    char dest[len];
    
    int i = 0;
    while(i < len) {
        dest[i] = src[i];
        i++;
    }
    
    return dest;
}

int main(int argc, char*argv[]) {
  int secondSize;
  char str1[20];
  char str2[20];
  int i = 0;
  while(i < 20) {
    str2[i] = 'a';
    i++;
  }
  
  printf("%s\n", str2);
  
  printf("Enter size of second string and then the first string:");
  scanf("%d", &secondSize);
  fgets(str1, 100, stdin);
  
  char *nullT = cpynstr(str1, str2, secondSize);
  
  printf("The last character was %x\n", *nullT);
  printf("The second string:%s\n", str2);
  
  return EXIT_SUCCESS;
}

/*
char *cpynstr(char *src, char *dest, int n) {
    int i = 0;
    while(i < n-1 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    
    dest[i] = '\0';
    return &dest[i];
}*/
/*
char *dupstr(char *src) {
    int len = strlen(src);
    char *dest = malloc(len + 1);
    
    int i = 0;
    while(i < len + 1) {
        dest[i] = src[i];
        i++;
    }
    
    return dest;
}*/
