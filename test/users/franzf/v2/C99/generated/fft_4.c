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
	SVN: 5591 (modified)
	language: c.icl.opt
	timestamp: Dec 6, 2007; 13:43:43
	transform: DFT(4, 1)
	source file: "fft_4.c(.c)"
	performance: 34 cycles, 3129 Mflop/s

algorithm: DFT_GT_CT( DFT(4, 1),
  GT_NthLoop( GT(DFT(2, 1), XChain([ 0, 1 ]), XChain([ 0, 1 ]), [ 2 ]),
    GT_Base( GT(DFT(2, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
      DFT_Base( DFT(2, 1) ) ),
    Info_Base( InfoNt(1) ) ),
  GT_NthLoop( GT(DFT(2, 1), XChain([ 0, 1 ]), XChain([ 1, 0 ]), [ 2 ]),
    GT_Base( GT(DFT(2, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
      DFT_Base( DFT(2, 1) ) ),
    Info_Base( InfoNt(1) ) ) )
*/

#include <include/omega64c.h>

void init_fft4() {
}

void fft4(_Complex double  *Y, _Complex double  *X) {
    _Complex double s3, t27, t28, t29;
    t27 = (X[0] + X[2]);
    t28 = (X[0] - X[2]);
    t29 = (X[1] + X[3]);
    Y[0] = (t27 + t29);
    Y[2] = (t27 - t29);
    s3 = (__I__*(X[1] - X[3]));
    Y[1] = (t28 + s3);
    Y[3] = (t28 - s3);
}
