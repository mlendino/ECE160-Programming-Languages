#include <stdio.h>

int main(int argc, char *argv[])
{
print1();
print2();
print3();
}

void print1() //its return type is no return type, its a void function, it does things but doesnt return a value
{
char ar[10] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29}; //declare array of 10 characters, initialized with values
char *ptr; //declared pointer
long b = (long)(&ar[3]) - (long)(&ar[0]);//rather than directly using pointer arithmetic, we cast them to longs and then subtract them as integers
ptr = &ar[3]; //set pointer to point to the  address of the third element in the array
printf("%p\n", &ar[0]); //print in hex the address of the zeroth element of ar
printf("%p\n", &ar[3]); //print in hex the address of the third element of ar
printf("%p\n", &ptr); //print in hex the address of ptr
printf("%p\n", ptr); //prints the value OF ptr, which is an address (NOT the value ptr points to)
printf("%d\n", ar[3]); //prints the contents of ar[3] in decimal, not the address, just the value
printf("%d\n", *ptr); //follow (aka dereference) the pointer, which obtains the contents in ar[3]
printf("By my calculation, sizeof(char) is 1. In reality, it is %d.\n\n", b/3); //tells us the number of bytes needed for one character, by taking the size of  three longs and dividing by three
}

void print2() //its return type is no return type, its a void function, it does things but doesnt return a value
{
long ar[10] = {31, 32, 33, 34, 35, 36, 37, 38, 39, 40};
long *ptr; //declared pointer
long b = (long)(&ar[3]) -(long)(&ar[0]);
ptr = &ar[3]; //set pointer to point to the  address of the third element in the array
printf("%p\n", &ar[0]); //print in hex the address of the zeroth element of ar
printf("%p\n", &ar[3]); //print in hex the address of the third element of ar
printf("%p\n", &ptr); //print in hex the address of ptr
printf("%p\n", ptr); //prints the value OF ptr, which is an address (NOT the value ptr points to)
printf("%ld\n", ar[3]); //prints the contents of ar[3] in decimal, not the address, just the value
printf("%ld\n", *ptr); //follow (aka dereference) the pointer, which obtains the contents in ar[3]
printf("By my calculation, sizeof(long) is 8. In reality, it is %d.\n\n", b/3);
}

void print3()
{
long lng = 136792;
long *ptr = &lng; //declaring a long ptr and making it point to long lng = 136792
char *cptr = (char*) ptr; //casting, i.e. interpreting a value to a different type so it points to the same place but youre locating the value differently, theres a location inmemory where a long
// was located originally and now we are pointing there but now the value that is there is interpreted as a char, the long ptr to a char pointer
for(int i=0; i<8; i++) //trivial for loop, start at i=0, go until i=8, increment by 1
	{
	printf("Byte %d of lng: %x\n", i, *(cptr+i)); //prints each byte of the long because we are running this loop 8 times, the %d is just to let us know which byte we are on as we point to the 
//different locations in memory that are part of the long,i.e. it is going byte by byte,  and *(cptr+i) in this printf statement will print the byte located there,
// it is cptr + i additional characters to it, and by dereferencing it, 
//we are able to read the byte that it points to, so now that we can read the byte that it points to, which one of the 8 bytes of the long, itll print the hexademical representation of that byte
	}
printf("We know that 2(256^2)+(22)(256)+(88)=136792, from what is printed above by converting hex to decimal\n");
}
//8 bites to a byte and 2^8 is 256
