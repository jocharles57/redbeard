#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void readHelpfile(FILE *fp, char *command);

int main(void) {

   FILE *infile;
   char *command = "Show All Seas:";

   infile = fopen("helpfile", "r");
   
   readHelpfile(infile, command);
   
   exit(0);
}


/* Reads command explanation from fp (helpfile).
 * Explanations are terminated by a line containing "#". */
void readHelpfile(FILE *fp, char *command) {
   char temp[100];
   fgets(temp, 20, fp);
   temp[strlen(temp) - 1] = '\0';
   
   /* Find the command in the file. */
   while (strcmp(temp, command) != 0 && !feof(fp)) {
      fgets(temp, 20, fp);
      temp[strlen(temp) - 1] = '\0';
   }
   puts(temp);
   
   /* Print the command explanation. */
   fgets(temp, 100, fp);
   temp[strlen(temp) - 1] = '\0';
   
   while (strcmp(temp, "#") != 0 && !feof(fp)) {
      puts(temp);
      fgets(temp, 100, fp);
      temp[strlen(temp) - 1] = '\0';
     
   }
}
      
   
   
