/**
 * File: drz2pet_utils.h
 * Header file for the code in "drz2pet_utils.c"
 *
 * @author  Martin Kuemmel
 * @package drz2pet
 * @version $Revision: 1.2 $
 * @date    $Date: 2009-06-18 09:50:07 $
 */
#ifndef _DRZ2PET_UTILS_H
#define _DRZ2PET_UTILS_H

#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include "aXe_grism.h"
#include <math.h>
#include <string.h>

ap_pixel *
make_spc_drztable(observation * const obs, observation * const wobs,
                  const object *ob, const double lambda0,
                  const double dlambda);

extern char *
get_ID_num(char *grism_image,char *extname);

extern void
normalize_weight(observation * wobs, object *ob,
                 const int opt_extr);

extern gsl_matrix *
comp_equ_weight(gsl_matrix *exp_map, const object *ob);

gsl_matrix *
comp_exp_weight(gsl_matrix *exp_map, const object *ob);

gsl_matrix *
comp_opt_weight(gsl_matrix *mod_map,
                gsl_matrix *var_map, const object *ob);
#endif /* !_DRZ2PET_UTILS_H */
