/**
 * File: aper_check.h
 * APER_CHECK - create a FITS image showing the locations of
 *               apertures.
 *
 * @author  Martin Kuemmel, Markus Demleitner, Nor Pirzkal
 * @package aper_check
 * @version $Revision: 1.3 $
 * @date    $Date: 2010-06-15 09:48:34 $ 
 */

#ifndef _APER_CHECK_H
#define _APER_CHECK_H


typedef struct
{
  gsl_matrix *img;
}
aXe_mask;

extern aXe_mask *
aXe_mask_init (observation * ob);

extern void
add_ap_p_to_aXe_mask (ap_pixel * ap_p, aXe_mask * mask);

extern void
mark_trace_in_aXe_mask(ap_pixel * ap_p, aXe_mask *mask);
#endif
