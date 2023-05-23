#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** file handling
 * 1. strean-oriented data files -  the data is stored in the same manner as it appears on the screen
 * 2. system-oriented data files - the data files are mote closely associated with the OS
 */

/** file operators
 * creation of a new file, opening, reading, writing data in a file, closing a file.
 */

/** Steps for processing a file
 * 1. Declare a file pointer variable
 * 2. Open a file using fopen()
 * 3. Process the file using the suitable function
 * 4. Close the file using fclose() function
 */

/**fopen:  
 * fclose:
 * getc: reads character forom file
 * putc: writes character from a file
 * getw: read integer frm file
 * putw: writes integer frm file
 * fprintf: prints formatted output into file
 * fscanf: reads formated input frm a file
 * fgets: reads string of characters frm a file
 * fputs: writes strings of characters into a file 
 * fiof: detects end of file marker in a single file
 */


int main ()
{
        FILE *fp;
        fp = fopen("filename.txt", "w");
        //processing of the files
        fprintf(fp, "%s", "Hello World");
        //end of processing
        fclose(fp);
        return 0;
}

