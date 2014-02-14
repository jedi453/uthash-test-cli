/*********** File: HashTable_free.c *****************************************************************/
/*  Purpose: Defines HashTable_free() to Completely Free a HashTable and All it's Entries           */
/*                                                                                                  */
/*  Author: jedi453                                                                                 */
/****************************************************************************************************/


#include <stdlib.h>   /* free(), NULL */

#include "uthash.h" /* HASH_ITER */
#include "HashTable.h"  /* HashTable type Stuff */

/****************************************************************************************************/
/*          Function HashTable_free                                                                 */
/*                                                                                                  */
/*  Purpose: Frees all Entries from a HashTable and the HashTable itself                            */
/*                                                                                                  */
/*  Arguments:  table - HashTable** to the Table to Free ( Sets *table to NULL when Done )          */
/*                                                                                                  */
/*  Returns:  VOID                                                                                  */
/*                                                                                                  */
/*  Author: jedi453                                                                                 */
/****************************************************************************************************/
void HashTable_free( HashTable** table )
{
  HashTable *currentEntry, *tmp;
  
  /* Iterate Overt the Entries in the HashTable table */
  HASH_ITER( hh, *table, currentEntry, tmp )
  {
    HASH_DEL( *table, currentEntry );
    free( currentEntry );
  }

  *table = (HashTable*) NULL;
}
