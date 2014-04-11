/* Copyright (C) 2012 Texas Instruments Incorporated - http://www.ti.com/
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
*
* Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the
* distribution.
*
* Neither the name of Texas Instruments Incorporated nor the names of
* its contributors may be used to endorse or promote products derived
* from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
* A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
* OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/**
 *  @file   paramBlas3.c
 *  @brief  function to input/output BLAS3 parameters and/or results.
 *
 */

#include "paramBlas3.h"
#include "string.h"

// @brief Scratch memory for storing blas3 API name
char paramSt[MAX_LINE_LEN];
// @brief Scratch memory for storing blas3 API arguments values
char valueSt[MAX_LINE_LEN];
// @brief Scratch memory for storing line from parameter file
char sLine[MAX_LINE_LEN];

void readAPIparams(FILE *pFid,  ParamsBlas3_t *pParam_s)
{
    
  char *pParamStr = &paramSt[0];
  char *pSLine = &sLine[0];

  memset(pParam_s, 0, sizeof(ParamsBlas3_t));
  memset(pSLine, 0, MAX_LINE_LEN);

  fgets(pSLine, MAX_LINE_LEN, pFid);
  sscanf(pSLine,"%s",pParamStr);

  if ((strcmp(pParamStr,"sgemm") == 0) ||
      (strcmp(pParamStr,"dgemm") == 0))
  {
    sscanf(pSLine,"%s %c %c %d %d %d %lf %lf",
            pParam_s->blas3Api,
            &pParam_s->transa, &pParam_s->transb,
            &pParam_s->m, &pParam_s->n, &pParam_s->k,
            &pParam_s->alpha, &pParam_s->beta);
  }
  else if ((strcmp(pParamStr,"cgemm") == 0) ||
           (strcmp(pParamStr,"zgemm") == 0))
  {
    sscanf(pSLine,"%s %c %c %d %d %d %lf %lf %lf %lf",
            pParam_s->blas3Api,
            &pParam_s->transa, &pParam_s->transb,
            &pParam_s->m, &pParam_s->n, &pParam_s->k,
            &pParam_s->alpha, &pParam_s->alpha_i,
            &pParam_s->beta, &pParam_s->beta_i);
  }
  else if ((strcmp(pParamStr,"ssymm") == 0) ||
           (strcmp(pParamStr,"dsymm") == 0))
  {
   sscanf(pSLine,"%s %c %c %d %d %lf %lf",
        pParam_s->blas3Api,
        &pParam_s->side, &pParam_s->uplo,
        &pParam_s->m, &pParam_s->n,
        &pParam_s->alpha, &pParam_s->beta);
  }
  else if ((strcmp(pParamStr,"csymm") == 0) ||
           (strcmp(pParamStr,"zsymm") == 0) ||
           (strcmp(pParamStr,"chemm") == 0) ||
           (strcmp(pParamStr,"zhemm") == 0))
  {
   sscanf(pSLine,"%s %c %c %d %d %lf %lf %lf %lf",
        pParam_s->blas3Api,
        &pParam_s->side, &pParam_s->uplo,
        &pParam_s->m, &pParam_s->n,
        &pParam_s->alpha,  &pParam_s->alpha_i,
        &pParam_s->beta, &pParam_s->beta_i);
  }
  else if ((strcmp(pParamStr,"ssyrk") == 0) ||
           (strcmp(pParamStr,"dsyrk") == 0) ||
           (strcmp(pParamStr,"ssyr2k") == 0) ||
           (strcmp(pParamStr,"dsyr2k") == 0) ||
           (strcmp(pParamStr,"cherk") == 0) ||
           (strcmp(pParamStr,"zherk") == 0))
  {
    sscanf(pSLine,"%s %c %c %d %d %lf %lf",
            pParam_s->blas3Api,
            &pParam_s->uplo, &pParam_s->trans,
            &pParam_s->n, &pParam_s->k,
            &pParam_s->alpha, &pParam_s->beta);
  }
  else if ((strcmp(pParamStr,"cher2k") == 0) ||
           (strcmp(pParamStr,"zher2k") == 0))
  {
    sscanf(pSLine,"%s %c %c %d %d %lf %lf %lf",
            pParam_s->blas3Api,
            &pParam_s->uplo, &pParam_s->trans,
            &pParam_s->n, &pParam_s->k,
            &pParam_s->alpha,  &pParam_s->alpha_i,
            &pParam_s->beta);
  }
  else if ((strcmp(pParamStr,"csyrk") == 0) ||
           (strcmp(pParamStr,"zsyrk") == 0) ||
           (strcmp(pParamStr,"csyr2k") == 0) ||
           (strcmp(pParamStr,"zsyr2k") == 0))
  {
    sscanf(pSLine,"%s %c %c %d %d %lf %lf %lf %lf",
            pParam_s->blas3Api,
            &pParam_s->uplo, &pParam_s->trans,
            &pParam_s->n, &pParam_s->k,
            &pParam_s->alpha,  &pParam_s->alpha_i,
            &pParam_s->beta, &pParam_s->beta_i);
  }
  else if ((strcmp(pParamStr,"strmm") == 0) ||
	       (strcmp(pParamStr,"dtrmm") == 0) ||
	       (strcmp(pParamStr,"strsm") == 0) ||
	       (strcmp(pParamStr,"dtrsm") == 0))
  {
    sscanf(pSLine,"%s %c %c %c %c %d %d %lf",
            pParam_s->blas3Api,
            &pParam_s->side, &pParam_s->uplo, 
			&pParam_s->transa, &pParam_s->diag,
            &pParam_s->m, &pParam_s->n,
            &pParam_s->alpha);
  }
  else if ((strcmp(pParamStr,"ctrmm") == 0) ||
	       (strcmp(pParamStr,"ztrmm") == 0) ||
	       (strcmp(pParamStr,"ctrsm") == 0) ||
	       (strcmp(pParamStr,"ztrsm") == 0))
  {
    sscanf(pSLine,"%s %c %c %c %c %d %d %lf %lf",
            pParam_s->blas3Api,
            &pParam_s->side, &pParam_s->uplo, 
			&pParam_s->transa, &pParam_s->diag,
            &pParam_s->m, &pParam_s->n,
            &pParam_s->alpha,  &pParam_s->alpha_i);
  }
}

void writeAPIparams(FILE *pFid,  ParamsBlas3_t *pParam_s)
{
  if ((strcmp(pParam_s->blas3Api,"sgemm") == 0) ||
          (strcmp(pParam_s->blas3Api,"dgemm") == 0))
  {
    fprintf(pFid,"%s %c %c %d %d %d %lf %lf\n",
            pParam_s->blas3Api,
            pParam_s->transa, pParam_s->transb,
            pParam_s->m, pParam_s->n, pParam_s->k,
            pParam_s->alpha, pParam_s->beta);
  }
  else if ((strcmp(pParam_s->blas3Api,"cgemm") == 0) ||
          (strcmp(pParam_s->blas3Api,"zgemm") == 0))
  {
    fprintf(pFid,"%s %c %c %d %d %d %lf %lf %lf %lf\n",
            pParam_s->blas3Api,
            pParam_s->transa, pParam_s->transb,
            pParam_s->m, pParam_s->n, pParam_s->k,
            pParam_s->alpha, pParam_s->alpha_i,
            pParam_s->beta, pParam_s->beta_i);
  }
  else if ((strcmp(pParam_s->blas3Api,"ssymm") == 0) ||
          (strcmp(pParam_s->blas3Api,"dsymm") == 0))
  {
    fprintf(pFid,"%s %c %c %d %d %lf %lf\n",
            pParam_s->blas3Api,
            pParam_s->side, pParam_s->uplo,
            pParam_s->m, pParam_s->n,
            pParam_s->alpha, pParam_s->beta);
  }
  else if ((strcmp(pParam_s->blas3Api,"csymm") == 0) ||
          (strcmp(pParam_s->blas3Api,"zsymm") == 0) ||
          (strcmp(pParam_s->blas3Api,"chemm") == 0) ||
          (strcmp(pParam_s->blas3Api,"zhemm") == 0))
  {
    fprintf(pFid,"%s %c %c %d %d %lf %lf %lf %lf\n",
            pParam_s->blas3Api,
            pParam_s->side, pParam_s->uplo,
            pParam_s->m, pParam_s->n,
            pParam_s->alpha, pParam_s->alpha_i,
            pParam_s->beta, pParam_s->beta_i);
  }
  else if ((strcmp(pParam_s->blas3Api,"ssyrk") == 0) ||
           (strcmp(pParam_s->blas3Api,"dsyrk") == 0) ||
           (strcmp(pParam_s->blas3Api,"ssyr2k") == 0) ||
           (strcmp(pParam_s->blas3Api,"dsyr2k") == 0) ||
           (strcmp(pParam_s->blas3Api,"cherk") == 0) ||
           (strcmp(pParam_s->blas3Api,"zherk") == 0))
  {
    fprintf(pFid,"%s %c %c %d %d %lf %lf\n",
            pParam_s->blas3Api,
            pParam_s->uplo, pParam_s->trans,
            pParam_s->n, pParam_s->k,
            pParam_s->alpha, pParam_s->beta);
  }
  else if ((strcmp(pParam_s->blas3Api,"cher2k") == 0) ||
           (strcmp(pParam_s->blas3Api,"zher2k") == 0))
  {
    fprintf(pFid,"%s %c %c %d %d %lf %lf %lf %lf\n",
            pParam_s->blas3Api,
            pParam_s->uplo, pParam_s->trans,
            pParam_s->n, pParam_s->k,
            pParam_s->alpha, pParam_s->alpha_i, 
			pParam_s->beta, pParam_s->beta_i);
  }
  else if ((strcmp(pParam_s->blas3Api,"csyrk") == 0) ||
           (strcmp(pParam_s->blas3Api,"zsyrk") == 0) ||
           (strcmp(pParam_s->blas3Api,"csyr2k") == 0) ||
           (strcmp(pParam_s->blas3Api,"zsyr2k") == 0))
  {
    fprintf(pFid,"%s %c %c %d %d %lf %lf %lf\n",
            pParam_s->blas3Api,
            pParam_s->uplo, pParam_s->trans,
            pParam_s->n, pParam_s->k,
            pParam_s->alpha, pParam_s->alpha_i, 
			pParam_s->beta);
  }
  else if ((strcmp(pParam_s->blas3Api,"strmm") == 0) ||
	       (strcmp(pParam_s->blas3Api,"dtrmm") == 0) ||
	       (strcmp(pParam_s->blas3Api,"strsm") == 0) ||
	       (strcmp(pParam_s->blas3Api,"dtrsm") == 0))
  {
    fprintf(pFid,"%s %c %c %c %c %d %d %lf\n",
            pParam_s->blas3Api,
            pParam_s->side, pParam_s->uplo, 
			pParam_s->transa, pParam_s->diag,
            pParam_s->m, pParam_s->n,
            pParam_s->alpha);
  }
  else if ((strcmp(pParam_s->blas3Api,"ctrmm") == 0) ||
	       (strcmp(pParam_s->blas3Api,"ztrmm") == 0) ||
	       (strcmp(pParam_s->blas3Api,"ctrsm") == 0) ||
	       (strcmp(pParam_s->blas3Api,"ztrsm") == 0))
  {
    fprintf(pFid,"%s %c %c %c %c %d %d %lf %lf\n",
            pParam_s->blas3Api,
            pParam_s->side, pParam_s->uplo, 
			pParam_s->transa, pParam_s->diag,
            pParam_s->m, pParam_s->n,
            pParam_s->alpha,  pParam_s->alpha_i);
  }

}

