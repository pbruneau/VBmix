// Copyright (C) 2011 Pierrick Bruneau, see README for full notice

#ifndef MPPCA_H
#define MPPCA_H

//#include <QtCore>
#include <iostream>

#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_permutation.h>
#include <gsl/gsl_sf_gamma.h>
#include <gsl/gsl_sf_psi.h>
#include <gsl/gsl_sf_log.h>
#include <gsl/gsl_sf_exp.h>
#include <gsl/gsl_eigen.h>
#include <math.h>
#include <R.h>
#include <Rmath.h>
#include <Rinternals.h>
#include "utils.h"

// declare all variables

extern int K,d,q,i,j,k,interm1,nit,dummy;
extern double val1,val2,val3, val4, val5, val6, lb, newlb, lbvar;
extern double param_alpha, param_nua, param_nub, param_numoment, param_taua, param_taub, param_taumoment, param_nustar;
extern gsl_vector_view varview1;
extern gsl_vector_view varview2;
extern gsl_vector_view facview1;
extern gsl_vector_view facview2;
extern gsl_vector_view indview1;
extern gsl_vector_view indview2;
extern gsl_vector_view grpview1;
extern gsl_vector_view grpview2;
extern gsl_matrix_view tempview1;


extern gsl_matrix *stat_z;
extern gsl_vector *stat_lb;
extern gsl_matrix *stat_trace;
extern gsl_vector *stat_nk;
extern gsl_matrix *stat_yk;
extern gsl_matrix *stat_sk;
extern gsl_matrix **stat_syk;
extern gsl_matrix **stat_Sk;
extern gsl_vector *stat_yk2;

extern gsl_matrix *param_mustar;
extern gsl_vector *model_alpha;
extern gsl_vector *model_nua;
extern gsl_matrix *model_nub;
extern gsl_matrix *model_numoment;
extern gsl_vector *model_taua;
extern gsl_vector *model_taub;
extern gsl_vector *model_taumoment;
extern gsl_matrix *model_mumean;
extern gsl_vector **model_musigma;
extern gsl_matrix **model_wmean;
extern gsl_matrix **model_xsigma;
extern gsl_matrix **model_wsigma;

extern gsl_matrix *temp_mat1;
extern gsl_matrix *temp_mat2;
extern gsl_matrix *temp_mat3;
extern gsl_matrix *temp_mat4;
extern gsl_matrix *temp_mat5;
extern gsl_matrix *temp_mat6;
extern gsl_permutation *temp_perm1;
extern gsl_permutation *temp_perm3;
extern gsl_permutation *temp_perm4;
extern gsl_vector *temp_vec1;
extern gsl_vector *temp_vec2;
extern gsl_vector *temp_vec3;
extern gsl_vector *temp_vec4;
extern gsl_vector *temp_vec5;
extern gsl_eigen_symmv_workspace *temp_symmv1;

extern double *mins;
extern double *maxs;


//unique to mppca
int n,lb_store;
gsl_matrix_view dataview;
gsl_matrix_view tempview2;
gsl_vector *stat_norms;
gsl_matrix **model_xmean;
gsl_matrix *temp_mat7;
gsl_permutation *temp_perm5;
SEXP output;


// functions
extern "C" {
	void alloc(SEXP, SEXP, SEXP);
	void init();
	void initWithPrior(SEXP, SEXP, SEXP);
	//void initWithElements();
	void initWithReadyModel(SEXP);
	void initWithReadyW(SEXP);
	void end();

	SEXP mppca(SEXP, SEXP, SEXP, SEXP, SEXP);

	void updateX();
	void updateZ();
	void updateLB();
	void updateMu();
	void updateW();
	void updateAlpha();
	void updateNu();
	void displayCurModel();
	void displayBound(int);
	void updateSuffStats();

	// remove Qt deps
	//void writeMatrix(gsl_matrix *);

	SEXP getResp(SEXP, SEXP);
}


#endif
