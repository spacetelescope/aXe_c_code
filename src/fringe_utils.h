/**
 * File: fringe_utils.h 
 * Header file for fringe_utils.c.
 *
 * @author  Martin Kuemmel
 * @package fringe_utils
 * @version $Revision: 1.3 $
 * @date    $Date: 2010-06-15 09:48:34 $
 */
#ifndef _FRINGE_UTILS_H
#define _FRINGE_UTILS_H


typedef struct
{
  gsl_vector *lambda_values; // vector with l_min, l_1, l_2, l_max
  double tp_max;             // the maximum throughput value
}
  pixel_tput;

extern void
fringe_correct_PET(const fringe_conf *fconf, const beam act_beam,
		   ap_pixel *obj_pet, ap_pixel *bck_pet);

extern gsl_vector **
evaluate_pixel_throughput(const fringe_conf *fconf,
			  const beam act_beam, const ap_pixel *obj_pix);

gsl_vector **
get_gauss_throughput(const fringe_conf *fconf, const ap_pixel *obj_pix,
		     const double fwhm);

interpolator *
create_interp_tput(const pixel_tput *p_tput);

extern void
compute_pixel_tput(const beam act_beam, const ap_pixel *obj_pix,
		   pixel_tput *p_tput);

extern d_point
compute_tput_angles(const beam act_beam, const ap_pixel *act_pet);

extern pixel_tput *
alloc_pixel_tput();

void
print_pixel_tput(pixel_tput *p_tput);

extern void
free_pixel_tput(pixel_tput *p_tput);
#endif
