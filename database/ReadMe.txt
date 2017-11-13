Michael Lendino: Description of files, program, and operation for Assignment 2.

    The one major goal to this project was to create a simple database for a small firm, which contained 20 records
for each employee, and each record contained their last name, first and middle names, salary, and the year that
they were hired. The records were held in a fixed array of 20 structures, and the program allowed the user to
display any record, modify any record, both of which the user is prompted for their record number, save the records,
in binary format, to the file "company.db", and retrieve the records from the file "company.db".  At the start of
the program, all of the records were initialized so that the numerical values, such as their salary and the year that
they were hired, were set to -1, and the strings contain the null character as the zeroth character.  The specific
low-level details pertaining to the code can be found in the comments in the code.  However, as a general overview,
in order to accomplish the subgoals of the major goals of this project, the program was further divided into four
functions, one for displaying, one for modifying, one for saving, and one for retrieving.  In the beginning,
a struct called database was declared and contained the two arrays of characters, or strings, to contain the last
name, and the first and middle name of the employee, as well as the float variable for salary and the integer variable
for the year that they were hired.  This type was renamed to DBENTRY, and an array of 20 of these types were created,
one for each employee.  Moving into main(), a for loop was defined to run from i=0 to i=19 in order to initialize
the strings to contain the null character as the zeroth character, and the respective numerical values to -1. Then,
a menu display was created in order to prompt the user and inform them of the different options that they had.  This
menu option was controlled by a while loop, which is automatically true from the initial condition menuOpt = ' ',
the user is then prompted to make a choice, and when they make one it will direct them to the appropriate function.
If they input 1, then they will be taken to the display function, which uses a while() loop that is automatically true
because of the initial condition, then they will be prompted to choose a record number to display, and that number
will be assigned to the address of recNum, which was declared in the beginning of display().  If their input is out
of the bounds of the database, or total number of employees, then they are prompted again, else, the 4 fields are
displayed for them, with the record number being assigned from the number they inputted (recNum), and the respective
string or decimal for the field is represented by assigning that part to the respective element of that employee.
Another while loop is declared, with the initial condition automatically being false so that it runs and prompts
the user whether or not they want to look up another record, whatever they respond will be assigned to the address
of the char again, which was declared in the beginning of the function; if they respond Y then the first while loop
will run again, if they respond N, then it will exit the function, if they respond with anything other than
Y,y,n, or N, then they will be prompted until they make an appropriate choice.  Once they exit and are prompted again,
and if they choose modify, then the modify() function runs, which is very similar to the display() function, except
that it takes the input from the user after they are prompted and assigned it to the respective element they're being
prompted for. for the last name, and the first and middle name, the scanf basically says "read characters until a
new line is encountered", so that they can type a name like James John for a first and middle name.  The same while()
loop runs at the end of the program to give them the option to keep modifying records if they wish, or to go to another
option.  If they pick the save option, then a file pointer is declared to type FILE, and this pointer is set to the
value of the file when it is opened in binary mode,then another pointer to character called arrayBase is declared,
which points to the first element of the array, and is also changed to a pointed to character so that we can read
each byte of the array rather than each entry at a time by casting to char* (i.e. the (char*)).  A for() loop is then
created with true initial conditions in order to get the ith byte of the entries of the array, inside of the loop,
we see that each byte of entry to the file is written as *(arrayBase+i) follows the pointer "arrayBase+i" to get
each byte, once the ith element equals the sizeof(entries), which logically signifies the end of the entry, then
the for loop terminated and the file is closed.  The reading function, retrieve(), is very similar in that the file
pointers are declared, the file is opened in binary mode, the same pointer to character arrayBase in declared, which
does the same thing, the only difference is that in the for() loop, each byte of the file is read in the same order
and is assigned to *(arrayBase+i) byte by byte so the function can be used in the rest of the program.  The file is
then closed and all of the important functions of this program have been covered.