/*===========================================================================
*
*                            PUBLIC DOMAIN NOTICE
*               National Center for Biotechnology Information
*
*  This software/database is a "United States Government Work" under the
*  terms of the United States Copyright Act.  It was written as part of
*  the author's official duties as a United States Government employee and
*  thus cannot be copyrighted.  This software/database is freely available
*  to the public for use. The National Library of Medicine and the U.S.
*  Government have not placed any restriction on its use or reproduction.
*
*  Although all reasonable efforts have been taken to ensure the accuracy
*  and reliability of the software and data, the NLM and the U.S.
*  Government do not and cannot warrant the performance or results that
*  may be obtained by using this software or data. The NLM and the U.S.
*  Government disclaim all warranties, express or implied, including
*  warranties of performance, merchantability or fitness for any particular
*  purpose.
*
*  Please cite the author in any work or product based on this material.
*
* ===========================================================================
*
*/

#ifndef _h_cmn_iter_
#define _h_cmn_iter_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _h_klib_rc_
#include <klib/rc.h>
#endif

#ifndef _h_klib_text_
#include <klib/text.h>
#endif

#ifndef _h_kfs_directory_
#include <kfs/directory.h>
#endif

struct cmn_iter;

typedef struct cmn_params
{
    KDirectory * dir;
    const char * acc;
    const char * row_range;
    size_t cursor_cache;
    bool show_progress;
} cmn_params;

void destroy_cmn_iter( struct cmn_iter * iter );

rc_t make_cmn_iter( cmn_params * params, const char * tblname, struct cmn_iter ** iter );

rc_t cmn_iter_add_column( struct cmn_iter * iter, const char * name, uint32_t * id );
rc_t cmn_iter_range( struct cmn_iter * iter, uint32_t col_id );

bool cmn_iter_next( struct cmn_iter * iter, rc_t * rc );
int64_t cmn_iter_row_id( const struct cmn_iter * iter );

uint64_t cmn_iter_row_count( struct cmn_iter * iter );

rc_t cmn_read_uint64( struct cmn_iter * iter, uint32_t col_id, uint64_t *value );
rc_t cmn_read_uint64_array( struct cmn_iter * iter, uint32_t col_id, uint64_t *value, uint32_t num_values );
rc_t cmn_read_uint32( struct cmn_iter * iter, uint32_t col_id, uint32_t *value );
rc_t cmn_read_String( struct cmn_iter * iter, uint32_t col_id, String *value );

#ifdef __cplusplus
}
#endif

#endif