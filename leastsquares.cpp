/******************************************************/
/*                                                    */
/* leastsquares.cpp - least-squares adjustment        */
/*                                                    */
/******************************************************/
/* Copyright 2019 Pierre Abbat.
 * This file is part of PerfectTIN.
 *
 * PerfectTIN is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * PerfectTIN is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License and Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License
 * and Lesser General Public License along with PerfectTIN. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include <cmath>
#include "leastsquares.h"

using namespace std;

vector<double> linearLeastSquares(matrix m,vector<double> v)
/* m should be a matrix(a,b) where a>b. If a<b, mtm is singular.
 * There are b things which can be adjusted to best fit a data.
 */
{
  matrix mtm,mt,vmat=columnvector(v),mtv;
  int i;
  mt=m.transpose();
  mtm=mt.transmult();
  mtv=mt*vmat;
  mtm.gausselim(mtv);
  for (i=0;i<mtm.getcolumns();i++)
    if (mtm[i][i]==0)
      mtv[i][0]=NAN;
  return mtv;
}
