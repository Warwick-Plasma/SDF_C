/**
   @internal
   @file sdf_extension_util.h

   @brief Declarations for the SDF C-library.
   @details Routines for reading and writing SDF files.
   @author Dr Keith Bennett
   @date 15/02/2014
*/

#ifndef _SDF_EXTENSION_UTIL_H_
#define _SDF_EXTENSION_UTIL_H_
#include <sdf.h>

#ifdef __cplusplus
extern "C" {
#endif

void sdf_extension_unload(void);
void sdf_extension_free_data(sdf_file_t *h);

#ifdef __cplusplus
}
#endif

#endif
