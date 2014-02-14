/***********  File: HashTable.h *********************************************************************/
/*  Purpose: Defines HashTable Type as a Hash Table Entry with a String Key and a String Value      */
/*                                                                                                  */
/*  Author: jedi453                                                                                 */
/****************************************************************************************************/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "uthash.h"

#define HASH_TABLE_KEY_LEN 10
#define HASH_TABLE_VALUE_LEN 30

struct HashTable {
  char key[HASH_TABLE_KEY_LEN+2];     /* Key for Hashing */
  char value[HASH_TABLE_VALUE_LEN+2];
  UT_hash_handle hh;                  /* Make Hashible with uthash */
};
typedef struct HashTable HashTable;

#endif
