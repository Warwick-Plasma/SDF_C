#include <string.h>
#include <sdf.h>
#include "sdf_util.h"

/**
 * @defgroup utility
 * @brief General helper routines
 * @{
 */

sdf_block_t *sdf_find_block_by_id(sdf_file_t *h, const char *id)
{
    sdf_block_t *b;

    if (!h || !h->blocklist || !id)
        return NULL;

    HASH_FIND_STR(h->hashed_blocks_by_id, id, b);
    return b;
}


sdf_block_t *sdf_find_block_by_name(sdf_file_t *h, const char *name)
{
    sdf_block_t *current, *b;
    size_t len;
    int i;

    if (!h || !h->blocklist || !name)
        return NULL;

    current = h->blocklist;
    len = strlen(name) + 1;
    for (i=0; i < h->nblocks; i++) {
        b = current;
        if (memcmp(name, b->name, len) == 0) return b;
        current = b->next;
    }

    return NULL;
}


void sdf_hash_block(sdf_file_t *h, sdf_block_t *b)
{
   sdf_block_t *bb = NULL;
   HASH_FIND_STR(h->hashed_blocks_by_id, b->id, bb);
   if ( bb != NULL && b != bb ) {
      HASH_DELETE(hh, h->hashed_blocks_by_id, bb);
      bb = NULL;
   }
   if ( !bb )
      HASH_ADD_KEYPTR(hh, h->hashed_blocks_by_id, b->id, strlen(b->id), b);
}


void sdf_hash_block_list(sdf_file_t *h)
{
   sdf_block_t *b, *bb;

   b = h->blocklist;
   while ( b ) {
      sdf_hash_block(h, b);
      b = b->next;
   }
}
/**@}*/
