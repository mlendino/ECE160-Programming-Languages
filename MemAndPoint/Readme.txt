 Description of files, program, and operation for Assignment 1.

	There were three goals to this first assignment that the code provided executes
successfully.  The overall goal of this assignment was to demonstrate the use of 
pointers to point to specific addresses in memory and to be able to interact with them.  
The specific low-level details pertaining to the code can be found in the
comments in the code.  However, as a general overview, the first part of the program was
to  print, in hex, the addresses of the zeroth element in ar, the third element in ar,
the address of ptr, the address held in ptr, print in decimal, the contents of ar[3],
print, in decimal, the contents of the address held in ptr,and from the address of the
zeroth and the third element in ar, to determine the size of a char. In order to complete
the first part of the program, I declared an array of characters with 10 indices, ar[10],
containing elements with indices 0-9 that were  assigned the values 20-29, respectively.
Then a pointer to char, called ptr, was set to the address of the third element of ar. Lastly,
looking forward to part (g) of part 1, I declared a long variable, rather than using pointer
arithmetic, which consisted of casting &ar[3] and &ar[0] to longs, and subtracting them as 
integers.  Then a series of printf() statements then followed to print out, in hex using %p
or in decimal using %d, the addresses or values wanted, which were previously mentioned 
in this description.  Then for part (g), as mentioned above, we obtained the number of bytes
for one character by taking the size of three longs and dividing by three, and compared this
value to the actual value for the size of a char in order to ensure that the calculated value
was correct.  The second part of the program does the same thing as the first part of the program
except it is done with a long array rather than an array of char, pointers to long rather 
than pointers to char in order, and, by analog, the size of a long for part (g) rather than
determining the size of a char by following the same general procedure from the first part.
The goal of the third part was to show, in hex, the contents of the bytes that make up the long
variable, which was declared as lng in the beginning of this part and assigned to the value of 
136792, by reading the individual bytes from memory using an appropriate pointer.  In order to 
complete this task, the long pointer was declared and I made it point to long lng = 136792.  Then,
I had to cast the long ptr to a char pointer so that it points to the same place but the value is 
located differently, so now the location in memory where a long was located originally is being 
pointed to but the value that is there is being interpreted as a char.  Then a for loop is declared
from i=0 to i=8 in order to point to and print out the different locations in memory that are
part of the long, byte by byte.  After this explanation, and the extra explanation in the comments,
it is clear how the hexadecimal representation of that byte is obtained as we read that byte it
points to.  The third part ends with a printf() statement in order to state that the byte by byte
hexadecimal representations are right.   
