/*********** File: HashTable_promptFind.c ***********************************************************/
/*  Purpose: Defines HashTable_promptFind() to Prompt the User for a Key and Print the Key,Value    */
/*            Pair for that Key if Found or Print a Message if not Found                            */
/*                                                                                                  */
/*  Author: jedi453                                                                                 */
/****************************************************************************************************/


#include <stdio.h>  /* fgets(), printf(), stdin */
#include <string.h> /* strlen() */

#include "HashTable.h"  /* HashTable type Stuff */


/****************************************************************************************************/
/*          Function HashTable_promptFind                                                           */
/*                                                                                                  */
/*  Purpose: Prompts the User for a Key and Prints the Associated Key,Value Pair if Found           */
/*            - if Not Found, a Message is Printed                                                  */
/*                                                                                                  */
/*  Arguments:  table - HashTable** to the Head of the Table                                        */
/*                                                                                                  */
/*  Returns:  int, 0 - if Found, non-Zero if not Found                                              */
/*                                                                                                  */
/*  Author: jedi453                                                                                 */
/****************************************************************************************************/
int HashTable_promptFind( HashTable** table )
{
  HashTable* foundTable = (HashTable*) NULL;  /* Place to Put Reference to the Found Table ( if Any ) */
  char keyBuffer[HASH_TABLE_KEY_LEN+2];
  int keyBufferLen;

  /* Prompt for + Get Key to Search for */
  printf("Please Enter a Key to Search for:\n");
  fgets( keyBuffer, HASH_TABLE_KEY_LEN+1, stdin );
  /* Remove Trailing Newline */
  keyBufferLen = strlen( keyBuffer );
  if ( keyBuffer[keyBufferLen-1] == '\n' )
    keyBuffer[keyBufferLen-1] = '\0';

  
  HASH_FIND_STR( *table, keyBuffer, foundTable );
  
  if ( foundTable )
  {
    /* Found Entry */
    printf("Entry with Key \"%s\" Found:\n", keyBuffer);
    printf("     KEY    |        VALUE         \n");
    printf(" %10s | %-10s\n", foundTable->key, foundTable->value );

    return 0;
  }

  /* Entry Not Found */
  printf("Entry with Key \"%s\" Not Found.\n", keyBuffer);
  return 1;
}
