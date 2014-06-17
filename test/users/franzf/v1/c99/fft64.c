/***************************************************************
This code was generated by  Spiral 5.0 beta, www.spiral.net --
Copyright (c) 2005, Carnegie Mellon University
All rights reserved.
The code is distributed under a BSD style license
(see http://www.opensource.org/licenses/bsd-license.php)

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

* Redistributions of source code must retain the above copyright
  notice, reference to Spiral, this list of conditions and the
  following disclaimer.
  * Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the following
  disclaimer in the documentation and/or other materials provided
  with the distribution.
  * Neither the name of Carnegie Mellon University nor the name of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*AS IS* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************/

/*	CPU: Intel Core2Duo at 2660 MHz, 2 cores, SSE3
  OS: Microsoft WindowsXP 32-bit
  SVN: 5262
  language: c.icl.opt
  timestamp: Oct 8, 2007; 9:20:13
  transform: DFT(64, 1)
  performance: 1606 cycles, 3180 Mflop/s
*/

#include "omega64c.h"
static _Complex double D1[28];
static _Complex double D2[28];

void init_fft64() {
  for(int i387 = 0; i387 <= 6; i387++) {
    for(int i397 = 0; i397 <= 1; i397++) {
      D1[((i387*4) + (i397*2))] = omega(64, ((i387 + 1)*i397));
      D1[((i387*4) + (i397*2) + 1)] = omega(64, ((i387 + 1)*(i397 + 2)));
    }
  }
  for(int i388 = 0; i388 <= 6; i388++) {
    for(int i405 = 0; i405 <= 1; i405++) {
      D2[((i388*4) + (i405*2))] = omega(64, ((9 + i388)*i405));
      D2[((i388*4) + (i405*2) + 1)] = omega(64, ((9 + i388)*(i405 + 2)));
    }
  }
}

void fft64(_Complex double  *Y, _Complex double  *X) {
  static _Complex double T115[64];
  for(int i389 = 0; i389 <= 3; i389++) {
    _Complex double s186, s187, t890, t891, s188, s189, t892, 
      t893, t894, a795, t895, t896, s190, s191, t897, 
      t898, s192, s193, t899, t900, s194, a796, s195, 
      s196, s197, s198, t901, t902, s199, s200, t903, 
      t904, s201, a797, s202, s203, s204, s205, t905, 
      t906, s206, s207, t907, t908, s208, a798, s209, 
      s210, t909, t910, t911, a800, t912, t913, t914, 
      a801, t915, t916, t917, a802, t918, t919, t920, 
      a803;
    _Complex double  *a794, *a799;
    a794 = (X + i389);
    s186 = *(a794);
    s187 = *((a794 + 32));
    t890 = (s186 + s187);
    t891 = (s186 - s187);
    s188 = *((a794 + 16));
    s189 = *((a794 + 48));
    t892 = (s188 + s189);
    t893 = (t890 + t892);
    t894 = (t890 - t892);
    a795 = (__I__*(s188 - s189));
    t895 = (t891 + a795);
    t896 = (t891 - a795);
    s190 = *((a794 + 4));
    s191 = *((a794 + 36));
    t897 = (s190 + s191);
    t898 = (s190 - s191);
    s192 = *((a794 + 20));
    s193 = *((a794 + 52));
    t899 = (s192 + s193);
    t900 = (t897 + t899);
    s194 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t897 - t899));
    a796 = (__I__*(s192 - s193));
    s195 = ((0.92387953251128674 + __I__ * 0.38268343236508978)*(t898 + a796));
    s196 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t898 - a796));
    s197 = *((a794 + 8));
    s198 = *((a794 + 40));
    t901 = (s197 + s198);
    t902 = (s197 - s198);
    s199 = *((a794 + 24));
    s200 = *((a794 + 56));
    t903 = (s199 + s200);
    t904 = (t901 + t903);
    s201 = (__I__*(t901 - t903));
    a797 = (__I__*(s199 - s200));
    s202 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t902 + a797));
    s203 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t902 - a797));
    s204 = *((a794 + 12));
    s205 = *((a794 + 44));
    t905 = (s204 + s205);
    t906 = (s204 - s205);
    s206 = *((a794 + 28));
    s207 = *((a794 + 60));
    t907 = (s206 + s207);
    t908 = (t905 + t907);
    s208 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t905 - t907));
    a798 = (__I__*(s206 - s207));
    s209 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t906 + a798));
    s210 = ((-0.92387953251128674 - __I__ * 0.38268343236508978)*(t906 - a798));
    t909 = (t893 + t904);
    t910 = (t893 - t904);
    t911 = (t900 + t908);
    a799 = (T115 + (16*i389));
    *(a799) = (t909 + t911);
    *((a799 + 8)) = (t909 - t911);
    a800 = (__I__*(t900 - t908));
    *((a799 + 4)) = (t910 + a800);
    *((a799 + 12)) = (t910 - a800);
    t912 = (t895 + s202);
    t913 = (t895 - s202);
    t914 = (s195 + s209);
    *((a799 + 1)) = (t912 + t914);
    *((a799 + 9)) = (t912 - t914);
    a801 = (__I__*(s195 - s209));
    *((a799 + 5)) = (t913 + a801);
    *((a799 + 13)) = (t913 - a801);
    t915 = (t894 + s201);
    t916 = (t894 - s201);
    t917 = (s194 + s208);
    *((a799 + 2)) = (t915 + t917);
    *((a799 + 10)) = (t915 - t917);
    a802 = (__I__*(s194 - s208));
    *((a799 + 6)) = (t916 + a802);
    *((a799 + 14)) = (t916 - a802);
    t918 = (t896 + s203);
    t919 = (t896 - s203);
    t920 = (s196 + s210);
    *((a799 + 3)) = (t918 + t920);
    *((a799 + 11)) = (t918 - t920);
    a803 = (__I__*(s196 - s210));
    *((a799 + 7)) = (t919 + a803);
    *((a799 + 15)) = (t919 - a803);
  }
  _Complex double a838, a839, t937, t938, a840, a841, t939, 
    a842;
  a838 = *(T115);
  a839 = *((T115 + 32));
  t937 = (a838 + a839);
  t938 = (a838 - a839);
  a840 = *((T115 + 16));
  a841 = *((T115 + 48));
  t939 = (a840 + a841);
  *(Y) = (t937 + t939);
  *((Y + 32)) = (t937 - t939);
  a842 = (__I__*(a840 - a841));
  *((Y + 16)) = (t938 + a842);
  *((Y + 48)) = (t938 - a842);
  for(int i387 = 0; i387 <= 6; i387++) {
    _Complex double s227, s228, t956, t957, s229, s230, t958, 
      a885;
    _Complex double  *b44, *a884, *b45;
    b44 = (T115 + i387);
    a884 = (D1 + (4*i387));
    s227 = (*(a884)**((b44 + 1)));
    s228 = (*((a884 + 1))**((b44 + 33)));
    t956 = (s227 + s228);
    t957 = (s227 - s228);
    s229 = (*((a884 + 2))**((b44 + 17)));
    s230 = (*((a884 + 3))**((b44 + 49)));
    t958 = (s229 + s230);
    b45 = (Y + i387);
    *((b45 + 1)) = (t956 + t958);
    *((b45 + 33)) = (t956 - t958);
    a885 = (__I__*(s229 - s230));
    *((b45 + 17)) = (t957 + a885);
    *((b45 + 49)) = (t957 - a885);
  }
  _Complex double a926, a927, t975, t976, a928, a929, s235, 
    s236;
  a926 = *((T115 + 8));
  a927 = (__I__**((T115 + 40)));
  t975 = (a926 + a927);
  t976 = (a926 - a927);
  a928 = *((T115 + 24));
  a929 = (__I__**((T115 + 56)));
  s235 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(a928 + a929));
  s236 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(a928 - a929));
  *((Y + 8)) = (t975 + s235);
  *((Y + 40)) = (t975 - s235);
  *((Y + 24)) = (t976 + s236);
  *((Y + 56)) = (t976 - s236);
  for(int i388 = 0; i388 <= 6; i388++) {
    _Complex double s253, s254, t993, t994, s255, s256, t995, 
      a972;
    _Complex double  *b59, *a971, *b60;
    b59 = (T115 + i388);
    a971 = (D2 + (4*i388));
    s253 = (*(a971)**((b59 + 9)));
    s254 = (*((a971 + 1))**((b59 + 41)));
    t993 = (s253 + s254);
    t994 = (s253 - s254);
    s255 = (*((a971 + 2))**((b59 + 25)));
    s256 = (*((a971 + 3))**((b59 + 57)));
    t995 = (s255 + s256);
    b60 = (Y + i388);
    *((b60 + 9)) = (t993 + t995);
    *((b60 + 41)) = (t993 - t995);
    a972 = (__I__*(s255 - s256));
    *((b60 + 25)) = (t994 + a972);
    *((b60 + 57)) = (t994 - a972);
  }
}
