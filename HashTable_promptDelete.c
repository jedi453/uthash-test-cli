/*********** File: HashTable_promptDelete() *********************************************************/
/*  Purpose: Defines HashTable_promptDelete() to Prompt for an Entry in the Hash Table and Delete it*/
/*            if it Exists                                                                          */
/*                                                                                                  */
/*  Author: jedi453                                                                                 */
/****************************************************************************************************/


#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* free */
#include <string.h>     /* strlen */
#include "uthash.h"     /* Hash Basic Functionality */
#include "HashTable.h"  /* HashTable Type */



/****************************************************************************************************/
/*          Function HashTable_promptDelete                                                         */
/*                                                                                                  */
/*  Purpose: Prompts for a Key in Given HashTable and Deletes the Associated Entry if it Exists     */
/*                                                                                                  */
/*  Arguments:  table - HashTable** to the HashTable to Manipulate                                  */
/*                                                                                                  */
/*  Returns:  int - 0 Upon Success, non-zero Upon Failure or Key Doesn't Exist                      */
/*              0 - Success                                                                         */
/*              1 - Key Doesn't Exist in Given Table                                                */
/*                                                                                                  */
/*  Author: jedi453                                                                                 */
/****************************************************************************************************/
int HashTable_promptDelete( HashTable** table )
{
  char keyBuffer[HASH_TABLE_KEY_LEN+2];
  HashTable* deleteThis;   /* The Entry to Delete */
  int keyLen;

  /* Prompt for + get Key Name */
  printf("Enter Key to Remove:\n");
  fgets( keyBuffer, HASH_TABLE_KEY_LEN+1, stdin );
  /* Remove Trailing Newline */
  keyLen = strlen(keyBuffer);
  if ( keyLen > 0 )
    keyBuffer[keyLen-1] = '\0';

  /* Find Value Corresponding with Key ( if Any ) */
  HASH_FIND_STR( *table, keyBuffer, deleteThis );

  /* Exit if Key Doesn't Exist */
  if ( deleteThis == NULL )
  {
    printf("Key \"%s\" Doesn't Exist in Table!\n\n", keyBuffer);
    return 1;
  }

  /* Remove Entry from Table and Free Memory */
  HASH_DEL( *table, deleteThis );
  free( deleteThis );

  return 0;
}
