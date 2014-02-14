/*********** File: uthash-test-cli.c ****************************************************************/
/*  Purpose: Provide a CLI based interface to access/test some basic features of uthash             */
/*                                                                                                  */
/*  Author: jedi453                                                                                 */
/****************************************************************************************************/


#define IN_BUFFER_LEN 10



#include <stdio.h>  /* printf, fgets */
#include <stdlib.h> /* strtol */

#include "HashTable.h"

enum {
  OP_PRINT,
  OP_ADD,
  OP_DEL,
  OP_FIND,
  OP_QUIT
};

/****************************************************************************************************/
/*          MAIN                                                                                    */
/*                                                                                                  */
/*  Purpose: Provide a CLI based interface to access/test some basic features of uthash             */
/*                                                                                                  */
/*  Author: jedi453                                                                                 */
/****************************************************************************************************/
int main( int argc, char** argv )
{
  char inBuffer[IN_BUFFER_LEN+1];
  int option = 0;   /* Option Selected in Menu */
  int continueLoop = 1; /* Default to Always Prompting for More Entries */

  void HashTable_print( HashTable** );        /* Print all Entries in the Table */
  int HashTable_promptAdd( HashTable** );     /* Prompt for + Add Entry to the Table */
  int HashTable_promptDelete( HashTable** );  /* Prompt for Key + Delete Corresponding Entry */
  void HashTable_promptFind( HashTable** );   /* Prompt for Key and Print Corresponding Entry */
  void HashTable_free( HashTable** );         /* Completely Free HashTable and all Entries from Memory */

  HashTable* mainTable = (HashTable*) NULL;

  do
  {
    /* Prompt for Option Choice */
    printf("Enter %2d to Print Table.\n", OP_PRINT);
    printf("Enter %2d to Add Entry to Table.\n", OP_ADD);
    printf("Enter %2d to Delete Entry from Table.\n", OP_DEL);
    printf("Enter %2d to Find Entry within Table.\n", OP_FIND);

    printf("Enter %2d to Exit.\n", OP_QUIT);

    /* Get Option Choice */
    fgets( inBuffer, IN_BUFFER_LEN, stdin );
    option = strtol( inBuffer, NULL, 10 );

    /* Do Appropriate Action */
    switch ( option )
    {
      case OP_PRINT:
        HashTable_print( &mainTable );
        break;
      case OP_ADD:
        HashTable_promptAdd( &mainTable );
        break;
      case OP_DEL:
	      HashTable_promptDelete( &mainTable );
        break;
      case OP_FIND:
        HashTable_promptFind( &mainTable );
        break;
      case OP_QUIT:
        continueLoop = 0;
        printf("Quitting...\n\n");
        break;
      default:
        printf("Unrecognized Option: %s\n", inBuffer);
        printf("Please Try Again:\n");
    }

    printf("\n-------------------------------------------------------\n"); /* Seperator */

  } while ( continueLoop );
    
  /* Free mainTable */
  HashTable_free( &mainTable );

  return 0;
}
