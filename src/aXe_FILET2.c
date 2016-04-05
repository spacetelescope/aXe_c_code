/*
 *   File: aXe_FILET2.c
 *   $Revision: 1.2 $ $Date: 2010-06-15 09:48:34 $
 *   ST-ECF - Space Telescope European Coordinating Facility
 *   Martin Kuemmel
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#include <stdio.h>
#include "fitsio.h"

int main(int argc, char *argv[])
{
  fitsfile *infptr, *outfptr1, *outfptr2, *outfptr3;   /* FITS file pointers defined in fitsio.h */
  int status = 0, ii = 1;       /* status must always be initialized = 0  */
  int hdu_start=0;

  hdu_start = atoi(argv[2]);

  /* Open the input file */
  if ( !fits_open_file(&infptr, argv[1], READONLY, &status) )
    {
      /* Create the output file */
      fits_create_file(&outfptr1, argv[3], &status);
      if (status){
	fits_report_error(stderr, status);
	return(status);}	
      fits_movabs_hdu(infptr, hdu_start, NULL, &status);
      if (status){
	fits_report_error(stderr, status);
	return(status);}
      fits_copy_hdu(infptr, outfptr1, 0, &status);	  
      if (status){
	fits_report_error(stderr, status);
	return(status);}
      fits_close_file(outfptr1,  &status);
      if (status){
	fits_report_error(stderr, status);
	return(status);}

      fits_create_file(&outfptr2, argv[4], &status);
      if (status){
	fits_report_error(stderr, status);
	return(status);}	
      fits_movrel_hdu (infptr, 1, NULL, &status);
      if (status){
	fits_report_error(stderr, status);
	return(status);}
      fits_copy_hdu(infptr, outfptr2, 0, &status);	  
      if (status){
	fits_report_error(stderr, status);
	return(status);}
      fits_close_file(outfptr2,  &status);
      if (status){
	fits_report_error(stderr, status);
	return(status);}

      fits_create_file(&outfptr3, argv[5], &status);
      if (status){
	fits_report_error(stderr, status);
	return(status);}	
      fits_movrel_hdu (infptr, 1, NULL, &status);
      if (status){
	fits_report_error(stderr, status);
	return(status);}
      fits_copy_hdu(infptr, outfptr3, 0, &status);	  
      if (status){
	fits_report_error(stderr, status);
	return(status);}
      fits_close_file(outfptr3,  &status);
      if (status){
	fits_report_error(stderr, status);
	return(status);}

      fits_close_file(infptr, &status);
    }    
  
  /* if error occured, print out error message */
  if (status) fits_report_error(stderr, status);
  return(status);
}
