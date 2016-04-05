/**
 * File: spc_CD.h
 * @author  Martin Kuemmel, Markus Demleitner, Nor Pirzkal
 * @package spc_CD
 * @version $Revision: 1.3 $
 * @date    $Date: 2010-06-15 09:48:34 $
 */
#ifndef SPC_CD_H
#define SPC_CD_H

#include <fitsio.h>
#include <string.h>
#include "aXe_grism.h"
#include "libwcs/wcs.h"
#include "aXe_errors.h"


/**
    A point in world coordinates.

*/
typedef struct
{
  // RA
  double ra;
  // dec
  double dec;
  // equinox
  char *equinox;
}
sky_coord;

extern sky_coord *
ij_to_radec (struct WorldCoor *wcs, d_point ij);

extern d_point *
radec_to_ij (struct WorldCoor *wcs, sky_coord radec);

extern char *
get_fits_header (char filenamep[], int hdunum);

extern struct WorldCoor *
get_wcs (char filename[], int hdunum);
#endif
