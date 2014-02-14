/*********** File: HashTable_print.c ****************************************************************/
/*  Purpose: Defines HashTable_print() to Take a HashTable and Print it's Contents                  */
/*                                                                                                  */
/*  Author: jedi453                                                                                 */
/****************************************************************************************************/




#include <stdio.h>      /* printf */
#include "uthash.h"     /* UTHash Functionality */
#include "HashTable.h"  /* HashTable Declaration */



/****************************************************************************************************/
/*          Function HashTable_print                                                                */
/*                                                                                                  */
/*  Purpose: Prints All Entries ( Key, Value Pairs ) in the Given Table One Line at a Time          */
/*                                                                                                  */
/*  Arguments:  table - HashTable** to the HashTable to Print all Values from                       */
/*                                                                                                  */
/*  Returns:  VOID                                                                                  */
/*                                                                                                  */
/*  Author: jedi453                                                                                 */
/****************************************************************************************************/
void HashTable_print( HashTable** table )
{
  HashTable* currentTable;

  printf("     KEY    |        VALUE         \n");
  for( currentTable = *table; currentTable != NULL; currentTable = (HashTable*)currentTable->hh.next )
    printf(" %10s | %-10s\n", currentTable->key, currentTable->value);

  printf("\n");
}
