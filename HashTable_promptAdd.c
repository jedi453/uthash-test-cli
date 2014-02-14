/*********** File: HashTable_promptAdd.c ************************************************************/
/*  Purpose: Defines HashTable_promptAdd to Prompt for and Add a Key, Value Pair to the Given       */
/*            HashTable                                                                             */
/*                                                                                                  */
/*  Author: jedi453                                                                                 */
/****************************************************************************************************/

#include <stdio.h>  /* printf, fgets */
#include <stdlib.h> /* malloc, NULL */
#include <string.h> /* strcpy */
#include "uthash.h" /* uthash stuff */
#include "HashTable.h"  /* HashTable Definition */

/****************************************************************************************************/
/*          Function HashTable_promptAdd()                                                          */
/*                                                                                                  */
/*  Purpose: Prompts for a ( Key, Value ) Pair and Adds it to the HashTable if that Key Doesn't     */
/*            Already Exist                                                                         */
/*                                                                                                  */
/*  Arguments:  table - HashTable** to the Hash Table to Add to                                     */
/*                                                                                                  */
/*  Returns:  int - 0 Upon Success, non-zero Upon Failure or if Key Already Exists                  */
/*              0 - Success                                                                         */
/*              1 - Key Already Exists                                                              */
/*              2 - Out of Memory                                                                   */
/*                                                                                                  */
/*  Author: jedi453                                                                                 */
/****************************************************************************************************/
int HashTable_promptAdd( HashTable** table )
{
  HashTable* tmpTable;
  char keyBuffer[HASH_TABLE_KEY_LEN+2];
  int len;  /* Temporary Holder for String Lengths */
  
  /* Prompt for + get Key Name */
  printf("Enter Key to Add. Max %2d Characters:\n", HASH_TABLE_KEY_LEN);
  fgets( keyBuffer, HASH_TABLE_KEY_LEN+1, stdin );
  /* Remove Trailing Newline */
  len = strlen(keyBuffer);
  if ( len > 0 )
    keyBuffer[len-1] = '\0';

  /* Find Value Corresponding with Key ( if Any ) */
  HASH_FIND_STR( *table, keyBuffer, tmpTable );

  /* Exit if Key Already Exists in Table */
  if ( tmpTable )
  {
    printf("Key \"%s\" Already Exists in Table!\n\n", keyBuffer);
    return 1; /* Error 1 - Key Already Exists */
  }
  
  /* Create New Entry */
  tmpTable = (HashTable*) malloc(sizeof(HashTable));
  
  if ( !tmpTable )
  {
    printf("ERROR: Out of Memory! Can't Create Entry!\n\n");
    return 2; /* Error 2 - Out of Memory */
  }

  strcpy( tmpTable->key, keyBuffer );
  /* Prompt for Value */
  printf("Enter Value:\n");
  fgets( tmpTable->value, HASH_TABLE_VALUE_LEN, stdin );
  /* Remove Trailing Newline */
  len = strlen( tmpTable->value );
  if ( len > 0 )
    (tmpTable->value)[len-1] = '\0';

  printf("\n");
  
  /* Add New Entry to Hash Table */
  HASH_ADD_STR( *table, key, tmpTable );

  /* Exit Successfully */
  return 0;
}
