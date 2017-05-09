#include <stdio.h>

void toggle(int *x);
void bigOrLittleEndian();

int main(int argc, const char * argv[]) {
    int y = 1;
    toggle(&y);
    printf("Y is now %d\n", y);
    bigOrLittleEndian();
    return 0;
}


void toggle(int *x) {
    if (*x) {
        *x = 0;
    } else {
        *x = 1;
    }
}


void bigOrLittleEndian() {
    int x = 0x01234567;
    char c = 0x11;
    char *ptr = &c;
    
    printf("%02x\n", *ptr);
    
    ptr = ptr + 1;
    printf("%02x\n", *ptr);
    
    ptr = ptr + 1;
    printf("%02x\n", *ptr);
    
    ptr = ptr + 1;
    printf("%02x\n", *ptr);
    
    ptr = ptr + 1;
    printf("%02x\n", *ptr);
}

/*
 void first() {
 int x = 0x01234567;
 int y = 0x89abcdef;
 char c = 'a';
 int z = 0x07162534;
 
 int *addressOfAnInt = &y;
 
 printf("Values:\n");
 printf("x == %x\n", x);
 printf("y == %x\n", y);
 printf("c == %x\n", c);
 printf("z == %x\n", z);
 printf("addressOfAnInt == %p\n", addressOfAnInt);
 
 printf("Memory addresses:\n");
 printf("&x == %p\n", &x);
 printf("&y == %p\n", &y);
 printf("&c == %p\n", &c);
 printf("&z == %p\n", &z);
 printf("&addressOfAnInt == %p\n", &addressOfAnInt);
 
 printf("Value stored at address in memory contained in"
 "addressOfAnInt == %x\n", *addressOfAnInt);
 
 y = 0x00000000;
 
 printf("y == %x\n", y);
 printf("Value stored at address in memory contained in"
 "addressOfAnInt == %x\n", *addressOfAnInt);
 
 *addressOfAnInt = 0x11111111;
 
 printf("y == %x\n", y);
 printf("Value stored at address in memory contained in"
 "addressOfAnInt == %x\n", *addressOfAnInt);
 
 addressOfAnInt = addressOfAnInt + 1;
 
 printf("addressOfAnInt == %p\n", addressOfAnInt);
 printf("&addressOfAnInt == %p\n", &addressOfAnInt);
 printf("Value stored at address in memory contained in"
 "addressOfAnInt == %x\n", *addressOfAnInt);
 
 }
 */
