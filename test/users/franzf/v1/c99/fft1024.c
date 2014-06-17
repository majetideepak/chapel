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
  timestamp: Oct 8, 2007; 9:20:38
  transform: DFT(1024, 1)
  performance: 47814 cycles, 2848 Mflop/s
*/

#include "omega64c.h"
static _Complex double D15[496];
static _Complex double D16[496];
static _Complex double D17[28];
static _Complex double D18[28];

void init_fft1024() {
  for(int i1511 = 0; i1511 <= 30; i1511++) {
    for(int i1522 = 0; i1522 <= 3; i1522++) {
      for(int i1549 = 0; i1549 <= 1; i1549++) {
        D15[((i1511*16) + (i1522*4) + (i1549*2))] = omega(1024, ((i1511 + 1)*(i1522 + (i1549*4))));
        D15[((i1511*16) + (i1522*4) + (i1549*2) + 1)] = omega(1024, ((i1511 + 1)*(i1522 + (i1549*4) + 8)));
      }
    }
  }
  for(int i1512 = 0; i1512 <= 30; i1512++) {
    for(int i1530 = 0; i1530 <= 3; i1530++) {
      for(int i1565 = 0; i1565 <= 1; i1565++) {
        D16[((i1512*16) + (i1530*4) + (i1565*2))] = omega(1024, ((33 + i1512)*(i1530 + (i1565*4))));
        D16[((i1512*16) + (i1530*4) + (i1565*2) + 1)] = omega(1024, ((33 + i1512)*(i1530 + (i1565*4) + 8)));
      }
    }
  }
  for(int i1531 = 0; i1531 <= 6; i1531++) {
    for(int i1573 = 0; i1573 <= 1; i1573++) {
      D17[((i1531*4) + (i1573*2))] = omega(64, ((i1531 + 1)*i1573));
      D17[((i1531*4) + (i1573*2) + 1)] = omega(64, ((i1531 + 1)*(i1573 + 2)));
    }
  }
  for(int i1532 = 0; i1532 <= 6; i1532++) {
    for(int i1581 = 0; i1581 <= 1; i1581++) {
      D18[((i1532*4) + (i1581*2))] = omega(64, ((9 + i1532)*i1581));
      D18[((i1532*4) + (i1581*2) + 1)] = omega(64, ((9 + i1532)*(i1581 + 2)));
    }
  }
}

void fft1024(_Complex double  *Y, _Complex double  *X) {
  static _Complex double T437[1024];
  for(int i1513 = 0; i1513 <= 15; i1513++) {
    static _Complex double T438[64];
    for(int i1533 = 0; i1533 <= 3; i1533++) {
      _Complex double s939, s940, t2562, t2563, s941, s942, t2564, 
        t2565, t2566, a2724, t2567, t2568, s943, s944, t2569, 
        t2570, s945, s946, t2571, t2572, s947, a2725, s948, 
        s949, s950, s951, t2573, t2574, s952, s953, t2575, 
        t2576, s954, a2726, s955, s956, s957, s958, t2577, 
        t2578, s959, s960, t2579, t2580, s961, a2727, s962, 
        s963, t2581, t2582, t2583, a2729, t2584, t2585, t2586, 
        a2730, t2587, t2588, t2589, a2731, t2590, t2591, t2592, 
        a2732;
      int a2722;
      _Complex double  *a2723, *a2728;
      a2722 = (16*i1533);
      a2723 = (X + i1513 + a2722);
      s939 = *(a2723);
      s940 = *((a2723 + 512));
      t2562 = (s939 + s940);
      t2563 = (s939 - s940);
      s941 = *((a2723 + 256));
      s942 = *((a2723 + 768));
      t2564 = (s941 + s942);
      t2565 = (t2562 + t2564);
      t2566 = (t2562 - t2564);
      a2724 = (__I__*(s941 - s942));
      t2567 = (t2563 + a2724);
      t2568 = (t2563 - a2724);
      s943 = *((a2723 + 64));
      s944 = *((a2723 + 576));
      t2569 = (s943 + s944);
      t2570 = (s943 - s944);
      s945 = *((a2723 + 320));
      s946 = *((a2723 + 832));
      t2571 = (s945 + s946);
      t2572 = (t2569 + t2571);
      s947 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t2569 - t2571));
      a2725 = (__I__*(s945 - s946));
      s948 = ((0.92387953251128674 + __I__ * 0.38268343236508978)*(t2570 + a2725));
      s949 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t2570 - a2725));
      s950 = *((a2723 + 128));
      s951 = *((a2723 + 640));
      t2573 = (s950 + s951);
      t2574 = (s950 - s951);
      s952 = *((a2723 + 384));
      s953 = *((a2723 + 896));
      t2575 = (s952 + s953);
      t2576 = (t2573 + t2575);
      s954 = (__I__*(t2573 - t2575));
      a2726 = (__I__*(s952 - s953));
      s955 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t2574 + a2726));
      s956 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t2574 - a2726));
      s957 = *((a2723 + 192));
      s958 = *((a2723 + 704));
      t2577 = (s957 + s958);
      t2578 = (s957 - s958);
      s959 = *((a2723 + 448));
      s960 = *((a2723 + 960));
      t2579 = (s959 + s960);
      t2580 = (t2577 + t2579);
      s961 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t2577 - t2579));
      a2727 = (__I__*(s959 - s960));
      s962 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t2578 + a2727));
      s963 = ((-0.92387953251128674 - __I__ * 0.38268343236508978)*(t2578 - a2727));
      t2581 = (t2565 + t2576);
      t2582 = (t2565 - t2576);
      t2583 = (t2572 + t2580);
      a2728 = (T438 + a2722);
      *(a2728) = (t2581 + t2583);
      *((a2728 + 8)) = (t2581 - t2583);
      a2729 = (__I__*(t2572 - t2580));
      *((a2728 + 4)) = (t2582 + a2729);
      *((a2728 + 12)) = (t2582 - a2729);
      t2584 = (t2567 + s955);
      t2585 = (t2567 - s955);
      t2586 = (s948 + s962);
      *((a2728 + 1)) = (t2584 + t2586);
      *((a2728 + 9)) = (t2584 - t2586);
      a2730 = (__I__*(s948 - s962));
      *((a2728 + 5)) = (t2585 + a2730);
      *((a2728 + 13)) = (t2585 - a2730);
      t2587 = (t2566 + s954);
      t2588 = (t2566 - s954);
      t2589 = (s947 + s961);
      *((a2728 + 2)) = (t2587 + t2589);
      *((a2728 + 10)) = (t2587 - t2589);
      a2731 = (__I__*(s947 - s961));
      *((a2728 + 6)) = (t2588 + a2731);
      *((a2728 + 14)) = (t2588 - a2731);
      t2590 = (t2568 + s956);
      t2591 = (t2568 - s956);
      t2592 = (s949 + s963);
      *((a2728 + 3)) = (t2590 + t2592);
      *((a2728 + 11)) = (t2590 - t2592);
      a2732 = (__I__*(s949 - s963));
      *((a2728 + 7)) = (t2591 + a2732);
      *((a2728 + 15)) = (t2591 - a2732);
    }
    _Complex double a2773, a2774, t2609, t2610, a2775, a2776, t2611, 
      a2778;
    _Complex double  *a2777;
    a2773 = *(T438);
    a2774 = *((T438 + 32));
    t2609 = (a2773 + a2774);
    t2610 = (a2773 - a2774);
    a2775 = *((T438 + 16));
    a2776 = *((T438 + 48));
    t2611 = (a2775 + a2776);
    a2777 = (T437 + (64*i1513));
    *(a2777) = (t2609 + t2611);
    *((a2777 + 32)) = (t2609 - t2611);
    a2778 = (__I__*(a2775 - a2776));
    *((a2777 + 16)) = (t2610 + a2778);
    *((a2777 + 48)) = (t2610 - a2778);
    for(int i1531 = 0; i1531 <= 6; i1531++) {
      _Complex double s980, s981, t2628, t2629, s982, s983, t2630, 
        a2826;
      _Complex double  *b488, *a2825, *b489;
      b488 = (T438 + i1531);
      a2825 = (D17 + (4*i1531));
      s980 = (*(a2825)**((b488 + 1)));
      s981 = (*((a2825 + 1))**((b488 + 33)));
      t2628 = (s980 + s981);
      t2629 = (s980 - s981);
      s982 = (*((a2825 + 2))**((b488 + 17)));
      s983 = (*((a2825 + 3))**((b488 + 49)));
      t2630 = (s982 + s983);
      b489 = (T437 + (64*i1513) + i1531);
      *((b489 + 1)) = (t2628 + t2630);
      *((b489 + 33)) = (t2628 - t2630);
      a2826 = (__I__*(s982 - s983));
      *((b489 + 17)) = (t2629 + a2826);
      *((b489 + 49)) = (t2629 - a2826);
    }
    _Complex double a2872, a2873, t2647, t2648, a2874, a2875, s988, 
      s989;
    _Complex double  *b495;
    a2872 = *((T438 + 8));
    a2873 = (__I__**((T438 + 40)));
    t2647 = (a2872 + a2873);
    t2648 = (a2872 - a2873);
    a2874 = *((T438 + 24));
    a2875 = (__I__**((T438 + 56)));
    s988 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(a2874 + a2875));
    s989 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(a2874 - a2875));
    b495 = (T437 + (64*i1513));
    *((b495 + 8)) = (t2647 + s988);
    *((b495 + 40)) = (t2647 - s988);
    *((b495 + 24)) = (t2648 + s989);
    *((b495 + 56)) = (t2648 - s989);
    for(int i1532 = 0; i1532 <= 6; i1532++) {
      _Complex double s1006, s1007, t2665, t2666, s1008, s1009, t2667, 
        a2923;
      _Complex double  *b514, *a2922, *b515;
      b514 = (T438 + i1532);
      a2922 = (D18 + (4*i1532));
      s1006 = (*(a2922)**((b514 + 9)));
      s1007 = (*((a2922 + 1))**((b514 + 41)));
      t2665 = (s1006 + s1007);
      t2666 = (s1006 - s1007);
      s1008 = (*((a2922 + 2))**((b514 + 25)));
      s1009 = (*((a2922 + 3))**((b514 + 57)));
      t2667 = (s1008 + s1009);
      b515 = (T437 + (64*i1513) + i1532);
      *((b515 + 9)) = (t2665 + t2667);
      *((b515 + 41)) = (t2665 - t2667);
      a2923 = (__I__*(s1008 - s1009));
      *((b515 + 25)) = (t2666 + a2923);
      *((b515 + 57)) = (t2666 - a2923);
    }
  }
  _Complex double a3082, a3083, t2796, t2797, a3084, a3085, t2798, 
    t2799, t2800, a3086, t2801, t2802, a3087, a3088, t2803, 
    t2804, a3089, a3090, t2805, t2806, s1028, a3091, s1029, 
    s1030, a3092, a3093, t2807, t2808, a3094, a3095, t2809, 
    t2810, s1031, a3096, s1032, s1033, a3097, a3098, t2811, 
    t2812, a3099, a3100, t2813, t2814, s1034, a3101, s1035, 
    s1036, t2815, t2816, t2817, a3102, t2818, t2819, t2820, 
    a3103, t2821, t2822, t2823, a3104, t2824, t2825, t2826, 
    a3105;
  a3082 = *(T437);
  a3083 = *((T437 + 512));
  t2796 = (a3082 + a3083);
  t2797 = (a3082 - a3083);
  a3084 = *((T437 + 256));
  a3085 = *((T437 + 768));
  t2798 = (a3084 + a3085);
  t2799 = (t2796 + t2798);
  t2800 = (t2796 - t2798);
  a3086 = (__I__*(a3084 - a3085));
  t2801 = (t2797 + a3086);
  t2802 = (t2797 - a3086);
  a3087 = *((T437 + 64));
  a3088 = *((T437 + 576));
  t2803 = (a3087 + a3088);
  t2804 = (a3087 - a3088);
  a3089 = *((T437 + 320));
  a3090 = *((T437 + 832));
  t2805 = (a3089 + a3090);
  t2806 = (t2803 + t2805);
  s1028 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t2803 - t2805));
  a3091 = (__I__*(a3089 - a3090));
  s1029 = ((0.92387953251128674 + __I__ * 0.38268343236508978)*(t2804 + a3091));
  s1030 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t2804 - a3091));
  a3092 = *((T437 + 128));
  a3093 = *((T437 + 640));
  t2807 = (a3092 + a3093);
  t2808 = (a3092 - a3093);
  a3094 = *((T437 + 384));
  a3095 = *((T437 + 896));
  t2809 = (a3094 + a3095);
  t2810 = (t2807 + t2809);
  s1031 = (__I__*(t2807 - t2809));
  a3096 = (__I__*(a3094 - a3095));
  s1032 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t2808 + a3096));
  s1033 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t2808 - a3096));
  a3097 = *((T437 + 192));
  a3098 = *((T437 + 704));
  t2811 = (a3097 + a3098);
  t2812 = (a3097 - a3098);
  a3099 = *((T437 + 448));
  a3100 = *((T437 + 960));
  t2813 = (a3099 + a3100);
  t2814 = (t2811 + t2813);
  s1034 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t2811 - t2813));
  a3101 = (__I__*(a3099 - a3100));
  s1035 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t2812 + a3101));
  s1036 = ((-0.92387953251128674 - __I__ * 0.38268343236508978)*(t2812 - a3101));
  t2815 = (t2799 + t2810);
  t2816 = (t2799 - t2810);
  t2817 = (t2806 + t2814);
  *(Y) = (t2815 + t2817);
  *((Y + 512)) = (t2815 - t2817);
  a3102 = (__I__*(t2806 - t2814));
  *((Y + 256)) = (t2816 + a3102);
  *((Y + 768)) = (t2816 - a3102);
  t2818 = (t2801 + s1032);
  t2819 = (t2801 - s1032);
  t2820 = (s1029 + s1035);
  *((Y + 64)) = (t2818 + t2820);
  *((Y + 576)) = (t2818 - t2820);
  a3103 = (__I__*(s1029 - s1035));
  *((Y + 320)) = (t2819 + a3103);
  *((Y + 832)) = (t2819 - a3103);
  t2821 = (t2800 + s1031);
  t2822 = (t2800 - s1031);
  t2823 = (s1028 + s1034);
  *((Y + 128)) = (t2821 + t2823);
  *((Y + 640)) = (t2821 - t2823);
  a3104 = (__I__*(s1028 - s1034));
  *((Y + 384)) = (t2822 + a3104);
  *((Y + 896)) = (t2822 - a3104);
  t2824 = (t2802 + s1033);
  t2825 = (t2802 - s1033);
  t2826 = (s1030 + s1036);
  *((Y + 192)) = (t2824 + t2826);
  *((Y + 704)) = (t2824 - t2826);
  a3105 = (__I__*(s1030 - s1036));
  *((Y + 448)) = (t2825 + a3105);
  *((Y + 960)) = (t2825 - a3105);
  for(int i1511 = 0; i1511 <= 30; i1511++) {
    _Complex double s1119, s1120, t2955, t2956, s1121, s1122, t2957, 
      t2958, t2959, a3284, t2960, t2961, s1123, s1124, t2962, 
      t2963, s1125, s1126, t2964, t2965, s1127, a3285, s1128, 
      s1129, s1130, s1131, t2966, t2967, s1132, s1133, t2968, 
      t2969, s1134, a3286, s1135, s1136, s1137, s1138, t2970, 
      t2971, s1139, s1140, t2972, t2973, s1141, a3287, s1142, 
      s1143, t2974, t2975, t2976, a3288, t2977, t2978, t2979, 
      a3289, t2980, t2981, t2982, a3290, t2983, t2984, t2985, 
      a3291;
    _Complex double  *b565, *a3283, *b566;
    b565 = (T437 + i1511);
    a3283 = (D15 + (16*i1511));
    s1119 = (*(a3283)**((b565 + 1)));
    s1120 = (*((a3283 + 1))**((b565 + 513)));
    t2955 = (s1119 + s1120);
    t2956 = (s1119 - s1120);
    s1121 = (*((a3283 + 2))**((b565 + 257)));
    s1122 = (*((a3283 + 3))**((b565 + 769)));
    t2957 = (s1121 + s1122);
    t2958 = (t2955 + t2957);
    t2959 = (t2955 - t2957);
    a3284 = (__I__*(s1121 - s1122));
    t2960 = (t2956 + a3284);
    t2961 = (t2956 - a3284);
    s1123 = (*((a3283 + 4))**((b565 + 65)));
    s1124 = (*((a3283 + 5))**((b565 + 577)));
    t2962 = (s1123 + s1124);
    t2963 = (s1123 - s1124);
    s1125 = (*((a3283 + 6))**((b565 + 321)));
    s1126 = (*((a3283 + 7))**((b565 + 833)));
    t2964 = (s1125 + s1126);
    t2965 = (t2962 + t2964);
    s1127 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t2962 - t2964));
    a3285 = (__I__*(s1125 - s1126));
    s1128 = ((0.92387953251128674 + __I__ * 0.38268343236508978)*(t2963 + a3285));
    s1129 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t2963 - a3285));
    s1130 = (*((a3283 + 8))**((b565 + 129)));
    s1131 = (*((a3283 + 9))**((b565 + 641)));
    t2966 = (s1130 + s1131);
    t2967 = (s1130 - s1131);
    s1132 = (*((a3283 + 10))**((b565 + 385)));
    s1133 = (*((a3283 + 11))**((b565 + 897)));
    t2968 = (s1132 + s1133);
    t2969 = (t2966 + t2968);
    s1134 = (__I__*(t2966 - t2968));
    a3286 = (__I__*(s1132 - s1133));
    s1135 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t2967 + a3286));
    s1136 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t2967 - a3286));
    s1137 = (*((a3283 + 12))**((b565 + 193)));
    s1138 = (*((a3283 + 13))**((b565 + 705)));
    t2970 = (s1137 + s1138);
    t2971 = (s1137 - s1138);
    s1139 = (*((a3283 + 14))**((b565 + 449)));
    s1140 = (*((a3283 + 15))**((b565 + 961)));
    t2972 = (s1139 + s1140);
    t2973 = (t2970 + t2972);
    s1141 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t2970 - t2972));
    a3287 = (__I__*(s1139 - s1140));
    s1142 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t2971 + a3287));
    s1143 = ((-0.92387953251128674 - __I__ * 0.38268343236508978)*(t2971 - a3287));
    t2974 = (t2958 + t2969);
    t2975 = (t2958 - t2969);
    t2976 = (t2965 + t2973);
    b566 = (Y + i1511);
    *((b566 + 1)) = (t2974 + t2976);
    *((b566 + 513)) = (t2974 - t2976);
    a3288 = (__I__*(t2965 - t2973));
    *((b566 + 257)) = (t2975 + a3288);
    *((b566 + 769)) = (t2975 - a3288);
    t2977 = (t2960 + s1135);
    t2978 = (t2960 - s1135);
    t2979 = (s1128 + s1142);
    *((b566 + 65)) = (t2977 + t2979);
    *((b566 + 577)) = (t2977 - t2979);
    a3289 = (__I__*(s1128 - s1142));
    *((b566 + 321)) = (t2978 + a3289);
    *((b566 + 833)) = (t2978 - a3289);
    t2980 = (t2959 + s1134);
    t2981 = (t2959 - s1134);
    t2982 = (s1127 + s1141);
    *((b566 + 129)) = (t2980 + t2982);
    *((b566 + 641)) = (t2980 - t2982);
    a3290 = (__I__*(s1127 - s1141));
    *((b566 + 385)) = (t2981 + a3290);
    *((b566 + 897)) = (t2981 - a3290);
    t2983 = (t2961 + s1136);
    t2984 = (t2961 - s1136);
    t2985 = (s1129 + s1143);
    *((b566 + 193)) = (t2983 + t2985);
    *((b566 + 705)) = (t2983 - t2985);
    a3291 = (__I__*(s1129 - s1143));
    *((b566 + 449)) = (t2984 + a3291);
    *((b566 + 961)) = (t2984 - a3291);
  }
  _Complex double a3468, a3469, t3114, t3115, a3470, a3471, s1184, 
    s1185, t3116, t3117, t3118, t3119, a3472, a3473, t3120, 
    t3121, a3474, a3475, s1186, s1187, s1188, s1189, s1190, 
    s1191, a3476, a3477, t3122, t3123, a3478, a3479, s1192, 
    s1193, s1194, s1195, s1196, s1197, a3480, a3481, t3124, 
    t3125, a3482, a3483, s1198, s1199, s1200, s1201, s1202, 
    s1203, t3126, t3127, t3128, a3484, t3129, t3130, t3131, 
    a3485, t3132, t3133, t3134, a3486, t3135, t3136, t3137, 
    a3487;
  a3468 = *((T437 + 32));
  a3469 = (__I__**((T437 + 544)));
  t3114 = (a3468 + a3469);
  t3115 = (a3468 - a3469);
  a3470 = *((T437 + 288));
  a3471 = (__I__**((T437 + 800)));
  s1184 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(a3470 + a3471));
  s1185 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(a3470 - a3471));
  t3116 = (t3114 + s1184);
  t3117 = (t3114 - s1184);
  t3118 = (t3115 + s1185);
  t3119 = (t3115 - s1185);
  a3472 = *((T437 + 96));
  a3473 = (__I__**((T437 + 608)));
  t3120 = (a3472 + a3473);
  t3121 = (a3472 - a3473);
  a3474 = *((T437 + 352));
  a3475 = (__I__**((T437 + 864)));
  s1186 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(a3474 + a3475));
  s1187 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(a3474 - a3475));
  s1188 = ((0.98078528040323043 + __I__ * 0.19509032201612825)*(t3120 + s1186));
  s1189 = ((0.55557023301960218 + __I__ * 0.83146961230254524)*(t3120 - s1186));
  s1190 = ((0.83146961230254524 + __I__ * 0.55557023301960218)*(t3121 + s1187));
  s1191 = ((0.19509032201612825 + __I__ * 0.98078528040323043)*(t3121 - s1187));
  a3476 = *((T437 + 160));
  a3477 = (__I__**((T437 + 672)));
  t3122 = (a3476 + a3477);
  t3123 = (a3476 - a3477);
  a3478 = *((T437 + 416));
  a3479 = (__I__**((T437 + 928)));
  s1192 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(a3478 + a3479));
  s1193 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(a3478 - a3479));
  s1194 = ((0.92387953251128674 + __I__ * 0.38268343236508978)*(t3122 + s1192));
  s1195 = ((-0.38268343236508978 + __I__ * 0.92387953251128674)*(t3122 - s1192));
  s1196 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t3123 + s1193));
  s1197 = ((-0.92387953251128674 + __I__ * 0.38268343236508978)*(t3123 - s1193));
  a3480 = *((T437 + 224));
  a3481 = (__I__**((T437 + 736)));
  t3124 = (a3480 + a3481);
  t3125 = (a3480 - a3481);
  a3482 = *((T437 + 480));
  a3483 = (__I__**((T437 + 992)));
  s1198 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(a3482 + a3483));
  s1199 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(a3482 - a3483));
  s1200 = ((0.83146961230254524 + __I__ * 0.55557023301960218)*(t3124 + s1198));
  s1201 = ((-0.98078528040323043 + __I__ * 0.19509032201612825)*(t3124 - s1198));
  s1202 = ((-0.19509032201612825 + __I__ * 0.98078528040323043)*(t3125 + s1199));
  s1203 = ((-0.55557023301960218 - __I__ * 0.83146961230254524)*(t3125 - s1199));
  t3126 = (t3116 + s1194);
  t3127 = (t3116 - s1194);
  t3128 = (s1188 + s1200);
  *((Y + 32)) = (t3126 + t3128);
  *((Y + 544)) = (t3126 - t3128);
  a3484 = (__I__*(s1188 - s1200));
  *((Y + 288)) = (t3127 + a3484);
  *((Y + 800)) = (t3127 - a3484);
  t3129 = (t3118 + s1196);
  t3130 = (t3118 - s1196);
  t3131 = (s1190 + s1202);
  *((Y + 96)) = (t3129 + t3131);
  *((Y + 608)) = (t3129 - t3131);
  a3485 = (__I__*(s1190 - s1202));
  *((Y + 352)) = (t3130 + a3485);
  *((Y + 864)) = (t3130 - a3485);
  t3132 = (t3117 + s1195);
  t3133 = (t3117 - s1195);
  t3134 = (s1189 + s1201);
  *((Y + 160)) = (t3132 + t3134);
  *((Y + 672)) = (t3132 - t3134);
  a3486 = (__I__*(s1189 - s1201));
  *((Y + 416)) = (t3133 + a3486);
  *((Y + 928)) = (t3133 - a3486);
  t3135 = (t3119 + s1197);
  t3136 = (t3119 - s1197);
  t3137 = (s1191 + s1203);
  *((Y + 224)) = (t3135 + t3137);
  *((Y + 736)) = (t3135 - t3137);
  a3487 = (__I__*(s1191 - s1203));
  *((Y + 480)) = (t3136 + a3487);
  *((Y + 992)) = (t3136 - a3487);
  for(int i1512 = 0; i1512 <= 30; i1512++) {
    _Complex double s1286, s1287, t3266, t3267, s1288, s1289, t3268, 
      t3269, t3270, a3666, t3271, t3272, s1290, s1291, t3273, 
      t3274, s1292, s1293, t3275, t3276, s1294, a3667, s1295, 
      s1296, s1297, s1298, t3277, t3278, s1299, s1300, t3279, 
      t3280, s1301, a3668, s1302, s1303, s1304, s1305, t3281, 
      t3282, s1306, s1307, t3283, t3284, s1308, a3669, s1309, 
      s1310, t3285, t3286, t3287, a3670, t3288, t3289, t3290, 
      a3671, t3291, t3292, t3293, a3672, t3294, t3295, t3296, 
      a3673;
    _Complex double  *b616, *a3665, *b617;
    b616 = (T437 + i1512);
    a3665 = (D16 + (16*i1512));
    s1286 = (*(a3665)**((b616 + 33)));
    s1287 = (*((a3665 + 1))**((b616 + 545)));
    t3266 = (s1286 + s1287);
    t3267 = (s1286 - s1287);
    s1288 = (*((a3665 + 2))**((b616 + 289)));
    s1289 = (*((a3665 + 3))**((b616 + 801)));
    t3268 = (s1288 + s1289);
    t3269 = (t3266 + t3268);
    t3270 = (t3266 - t3268);
    a3666 = (__I__*(s1288 - s1289));
    t3271 = (t3267 + a3666);
    t3272 = (t3267 - a3666);
    s1290 = (*((a3665 + 4))**((b616 + 97)));
    s1291 = (*((a3665 + 5))**((b616 + 609)));
    t3273 = (s1290 + s1291);
    t3274 = (s1290 - s1291);
    s1292 = (*((a3665 + 6))**((b616 + 353)));
    s1293 = (*((a3665 + 7))**((b616 + 865)));
    t3275 = (s1292 + s1293);
    t3276 = (t3273 + t3275);
    s1294 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t3273 - t3275));
    a3667 = (__I__*(s1292 - s1293));
    s1295 = ((0.92387953251128674 + __I__ * 0.38268343236508978)*(t3274 + a3667));
    s1296 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t3274 - a3667));
    s1297 = (*((a3665 + 8))**((b616 + 161)));
    s1298 = (*((a3665 + 9))**((b616 + 673)));
    t3277 = (s1297 + s1298);
    t3278 = (s1297 - s1298);
    s1299 = (*((a3665 + 10))**((b616 + 417)));
    s1300 = (*((a3665 + 11))**((b616 + 929)));
    t3279 = (s1299 + s1300);
    t3280 = (t3277 + t3279);
    s1301 = (__I__*(t3277 - t3279));
    a3668 = (__I__*(s1299 - s1300));
    s1302 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t3278 + a3668));
    s1303 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t3278 - a3668));
    s1304 = (*((a3665 + 12))**((b616 + 225)));
    s1305 = (*((a3665 + 13))**((b616 + 737)));
    t3281 = (s1304 + s1305);
    t3282 = (s1304 - s1305);
    s1306 = (*((a3665 + 14))**((b616 + 481)));
    s1307 = (*((a3665 + 15))**((b616 + 993)));
    t3283 = (s1306 + s1307);
    t3284 = (t3281 + t3283);
    s1308 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t3281 - t3283));
    a3669 = (__I__*(s1306 - s1307));
    s1309 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t3282 + a3669));
    s1310 = ((-0.92387953251128674 - __I__ * 0.38268343236508978)*(t3282 - a3669));
    t3285 = (t3269 + t3280);
    t3286 = (t3269 - t3280);
    t3287 = (t3276 + t3284);
    b617 = (Y + i1512);
    *((b617 + 33)) = (t3285 + t3287);
    *((b617 + 545)) = (t3285 - t3287);
    a3670 = (__I__*(t3276 - t3284));
    *((b617 + 289)) = (t3286 + a3670);
    *((b617 + 801)) = (t3286 - a3670);
    t3288 = (t3271 + s1302);
    t3289 = (t3271 - s1302);
    t3290 = (s1295 + s1309);
    *((b617 + 97)) = (t3288 + t3290);
    *((b617 + 609)) = (t3288 - t3290);
    a3671 = (__I__*(s1295 - s1309));
    *((b617 + 353)) = (t3289 + a3671);
    *((b617 + 865)) = (t3289 - a3671);
    t3291 = (t3270 + s1301);
    t3292 = (t3270 - s1301);
    t3293 = (s1294 + s1308);
    *((b617 + 161)) = (t3291 + t3293);
    *((b617 + 673)) = (t3291 - t3293);
    a3672 = (__I__*(s1294 - s1308));
    *((b617 + 417)) = (t3292 + a3672);
    *((b617 + 929)) = (t3292 - a3672);
    t3294 = (t3272 + s1303);
    t3295 = (t3272 - s1303);
    t3296 = (s1296 + s1310);
    *((b617 + 225)) = (t3294 + t3296);
    *((b617 + 737)) = (t3294 - t3296);
    a3673 = (__I__*(s1296 - s1310));
    *((b617 + 481)) = (t3295 + a3673);
    *((b617 + 993)) = (t3295 - a3673);
  }
}
