/* 
 *
 * File: aXe_errors.h
 * Code to report errors.
 * @author  Martin Kuemmel, Markus Demleitner, Nor Pirzkal
 * @package aXe_error
 * @version $Revision: 1.3 $
 * @date    $Date: 2010-06-15 09:48:34 $ 
 */

#ifndef _aXe_ERRORS_H
#define _aXe_ERRORS_H 1


/* public */

#define aXe_M_FATAL 1
#define aXe_M_ERROR 2
#define aXe_M_WARN1 101
#define aXe_M_WARN2 102
#define aXe_M_WARN3 103
#define aXe_M_WARN4 104

extern void
aXe_message (const int level, const char *const w_file, const int w_line,
	     const char *const msg, ...);

#endif /* !_aXe_ERRORS_H */
