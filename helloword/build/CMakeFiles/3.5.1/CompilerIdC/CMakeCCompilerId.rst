                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
                                      4 ; This file was generated Mon Sep 18 20:51:48 2017
                                      5 ;--------------------------------------------------------
                                      6 	.module CMakeCCompilerId
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _main_PARM_2
                                     13 	.globl _info_version
                                     14 	.globl _main
                                     15 	.globl _info_language_dialect_default
                                     16 	.globl _info_arch
                                     17 	.globl _info_platform
                                     18 	.globl _info_compiler
                                     19 ;--------------------------------------------------------
                                     20 ; special function registers
                                     21 ;--------------------------------------------------------
                                     22 	.area RSEG    (ABS,DATA)
      000000                         23 	.org 0x0000
                                     24 ;--------------------------------------------------------
                                     25 ; special function bits
                                     26 ;--------------------------------------------------------
                                     27 	.area RSEG    (ABS,DATA)
      000000                         28 	.org 0x0000
                                     29 ;--------------------------------------------------------
                                     30 ; overlayable register banks
                                     31 ;--------------------------------------------------------
                                     32 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                         33 	.ds 8
                                     34 ;--------------------------------------------------------
                                     35 ; internal ram data
                                     36 ;--------------------------------------------------------
                                     37 	.area DSEG    (DATA)
      000008                         38 _info_compiler::
      000008                         39 	.ds 3
      00000B                         40 _info_platform::
      00000B                         41 	.ds 3
      00000E                         42 _info_arch::
      00000E                         43 	.ds 3
      000011                         44 _info_language_dialect_default::
      000011                         45 	.ds 3
                                     46 ;--------------------------------------------------------
                                     47 ; overlayable items in internal ram 
                                     48 ;--------------------------------------------------------
                                     49 	.area	OSEG    (OVR,DATA)
      000014                         50 _main_PARM_2:
      000014                         51 	.ds 3
                                     52 ;--------------------------------------------------------
                                     53 ; Stack segment in internal ram 
                                     54 ;--------------------------------------------------------
                                     55 	.area	SSEG
      000017                         56 __start__stack:
      000017                         57 	.ds	1
                                     58 
                                     59 ;--------------------------------------------------------
                                     60 ; indirectly addressable internal ram data
                                     61 ;--------------------------------------------------------
                                     62 	.area ISEG    (DATA)
                                     63 ;--------------------------------------------------------
                                     64 ; absolute internal ram data
                                     65 ;--------------------------------------------------------
                                     66 	.area IABS    (ABS,DATA)
                                     67 	.area IABS    (ABS,DATA)
                                     68 ;--------------------------------------------------------
                                     69 ; bit data
                                     70 ;--------------------------------------------------------
                                     71 	.area BSEG    (BIT)
                                     72 ;--------------------------------------------------------
                                     73 ; paged external ram data
                                     74 ;--------------------------------------------------------
                                     75 	.area PSEG    (PAG,XDATA)
                                     76 ;--------------------------------------------------------
                                     77 ; external ram data
                                     78 ;--------------------------------------------------------
                                     79 	.area XSEG    (XDATA)
                                     80 ;--------------------------------------------------------
                                     81 ; absolute external ram data
                                     82 ;--------------------------------------------------------
                                     83 	.area XABS    (ABS,XDATA)
                                     84 ;--------------------------------------------------------
                                     85 ; external initialized ram data
                                     86 ;--------------------------------------------------------
                                     87 	.area XISEG   (XDATA)
                                     88 	.area HOME    (CODE)
                                     89 	.area GSINIT0 (CODE)
                                     90 	.area GSINIT1 (CODE)
                                     91 	.area GSINIT2 (CODE)
                                     92 	.area GSINIT3 (CODE)
                                     93 	.area GSINIT4 (CODE)
                                     94 	.area GSINIT5 (CODE)
                                     95 	.area GSINIT  (CODE)
                                     96 	.area GSFINAL (CODE)
                                     97 	.area CSEG    (CODE)
                                     98 ;--------------------------------------------------------
                                     99 ; interrupt vector 
                                    100 ;--------------------------------------------------------
                                    101 	.area HOME    (CODE)
      000000                        102 __interrupt_vect:
      000000 02 00 06         [24]  103 	ljmp	__sdcc_gsinit_startup
                                    104 ;--------------------------------------------------------
                                    105 ; global & static initialisations
                                    106 ;--------------------------------------------------------
                                    107 	.area HOME    (CODE)
                                    108 	.area GSINIT  (CODE)
                                    109 	.area GSFINAL (CODE)
                                    110 	.area GSINIT  (CODE)
                                    111 	.globl __sdcc_gsinit_startup
                                    112 	.globl __sdcc_program_startup
                                    113 	.globl __start__stack
                                    114 	.globl __mcs51_genXINIT
                                    115 	.globl __mcs51_genXRAMCLEAR
                                    116 	.globl __mcs51_genRAMCLEAR
                                    117 ;	CMakeCCompilerId.c:275: char const* info_compiler = "INFO" ":" "compiler[" COMPILER_ID "]";
      00005F 75 08 69         [24]  118 	mov	_info_compiler,#___str_0
      000062 75 09 01         [24]  119 	mov	(_info_compiler + 1),#(___str_0 >> 8)
      000065 75 0A 80         [24]  120 	mov	(_info_compiler + 2),#0x80
                                    121 ;	CMakeCCompilerId.c:500: char const* info_platform = "INFO" ":" "platform[" PLATFORM_ID "]";
      000068 75 0B 7D         [24]  122 	mov	_info_platform,#___str_1
      00006B 75 0C 01         [24]  123 	mov	(_info_platform + 1),#(___str_1 >> 8)
      00006E 75 0D 80         [24]  124 	mov	(_info_platform + 2),#0x80
                                    125 ;	CMakeCCompilerId.c:501: char const* info_arch = "INFO" ":" "arch[" ARCHITECTURE_ID "]";
      000071 75 0E 8D         [24]  126 	mov	_info_arch,#___str_2
      000074 75 0F 01         [24]  127 	mov	(_info_arch + 1),#(___str_2 >> 8)
      000077 75 10 80         [24]  128 	mov	(_info_arch + 2),#0x80
                                    129 ;	CMakeCCompilerId.c:506: const char* info_language_dialect_default = "INFO" ":" "dialect_default["
      00007A 75 11 99         [24]  130 	mov	_info_language_dialect_default,#___str_3
      00007D 75 12 01         [24]  131 	mov	(_info_language_dialect_default + 1),#(___str_3 >> 8)
      000080 75 13 80         [24]  132 	mov	(_info_language_dialect_default + 2),#0x80
                                    133 	.area GSFINAL (CODE)
      000083 02 00 03         [24]  134 	ljmp	__sdcc_program_startup
                                    135 ;--------------------------------------------------------
                                    136 ; Home
                                    137 ;--------------------------------------------------------
                                    138 	.area HOME    (CODE)
                                    139 	.area HOME    (CODE)
      000003                        140 __sdcc_program_startup:
      000003 02 00 86         [24]  141 	ljmp	_main
                                    142 ;	return from main will return to caller
                                    143 ;--------------------------------------------------------
                                    144 ; code
                                    145 ;--------------------------------------------------------
                                    146 	.area CSEG    (CODE)
                                    147 ;------------------------------------------------------------
                                    148 ;Allocation info for local variables in function 'main'
                                    149 ;------------------------------------------------------------
                                    150 ;argv                      Allocated with name '_main_PARM_2'
                                    151 ;argc                      Allocated to registers r6 r7 
                                    152 ;require                   Allocated to registers r3 r5 
                                    153 ;------------------------------------------------------------
                                    154 ;	CMakeCCompilerId.c:522: int main(int argc, char* argv[])
                                    155 ;	-----------------------------------------
                                    156 ;	 function main
                                    157 ;	-----------------------------------------
      000086                        158 _main:
                           000007   159 	ar7 = 0x07
                           000006   160 	ar6 = 0x06
                           000005   161 	ar5 = 0x05
                           000004   162 	ar4 = 0x04
                           000003   163 	ar3 = 0x03
                           000002   164 	ar2 = 0x02
                           000001   165 	ar1 = 0x01
                           000000   166 	ar0 = 0x00
      000086 AE 82            [24]  167 	mov	r6,dpl
      000088 AF 83            [24]  168 	mov	r7,dph
                                    169 ;	CMakeCCompilerId.c:525: require += info_compiler[argc];
      00008A EE               [12]  170 	mov	a,r6
      00008B 25 08            [12]  171 	add	a,_info_compiler
      00008D FB               [12]  172 	mov	r3,a
      00008E EF               [12]  173 	mov	a,r7
      00008F 35 09            [12]  174 	addc	a,(_info_compiler + 1)
      000091 FC               [12]  175 	mov	r4,a
      000092 AD 0A            [24]  176 	mov	r5,(_info_compiler + 2)
      000094 8B 82            [24]  177 	mov	dpl,r3
      000096 8C 83            [24]  178 	mov	dph,r4
      000098 8D F0            [24]  179 	mov	b,r5
      00009A 12 01 17         [24]  180 	lcall	__gptrget
      00009D FB               [12]  181 	mov	r3,a
      00009E 33               [12]  182 	rlc	a
      00009F 95 E0            [12]  183 	subb	a,acc
      0000A1 FD               [12]  184 	mov	r5,a
                                    185 ;	CMakeCCompilerId.c:526: require += info_platform[argc];
      0000A2 EE               [12]  186 	mov	a,r6
      0000A3 25 0B            [12]  187 	add	a,_info_platform
      0000A5 F9               [12]  188 	mov	r1,a
      0000A6 EF               [12]  189 	mov	a,r7
      0000A7 35 0C            [12]  190 	addc	a,(_info_platform + 1)
      0000A9 FA               [12]  191 	mov	r2,a
      0000AA AC 0D            [24]  192 	mov	r4,(_info_platform + 2)
      0000AC 89 82            [24]  193 	mov	dpl,r1
      0000AE 8A 83            [24]  194 	mov	dph,r2
      0000B0 8C F0            [24]  195 	mov	b,r4
      0000B2 12 01 17         [24]  196 	lcall	__gptrget
      0000B5 F9               [12]  197 	mov	r1,a
      0000B6 33               [12]  198 	rlc	a
      0000B7 95 E0            [12]  199 	subb	a,acc
      0000B9 FC               [12]  200 	mov	r4,a
      0000BA E9               [12]  201 	mov	a,r1
      0000BB 2B               [12]  202 	add	a,r3
      0000BC FB               [12]  203 	mov	r3,a
      0000BD EC               [12]  204 	mov	a,r4
      0000BE 3D               [12]  205 	addc	a,r5
      0000BF FD               [12]  206 	mov	r5,a
                                    207 ;	CMakeCCompilerId.c:527: require += info_arch[argc];
      0000C0 EE               [12]  208 	mov	a,r6
      0000C1 25 0E            [12]  209 	add	a,_info_arch
      0000C3 F9               [12]  210 	mov	r1,a
      0000C4 EF               [12]  211 	mov	a,r7
      0000C5 35 0F            [12]  212 	addc	a,(_info_arch + 1)
      0000C7 FA               [12]  213 	mov	r2,a
      0000C8 AC 10            [24]  214 	mov	r4,(_info_arch + 2)
      0000CA 89 82            [24]  215 	mov	dpl,r1
      0000CC 8A 83            [24]  216 	mov	dph,r2
      0000CE 8C F0            [24]  217 	mov	b,r4
      0000D0 12 01 17         [24]  218 	lcall	__gptrget
      0000D3 F9               [12]  219 	mov	r1,a
      0000D4 33               [12]  220 	rlc	a
      0000D5 95 E0            [12]  221 	subb	a,acc
      0000D7 FC               [12]  222 	mov	r4,a
      0000D8 E9               [12]  223 	mov	a,r1
      0000D9 2B               [12]  224 	add	a,r3
      0000DA FB               [12]  225 	mov	r3,a
      0000DB EC               [12]  226 	mov	a,r4
      0000DC 3D               [12]  227 	addc	a,r5
      0000DD FD               [12]  228 	mov	r5,a
                                    229 ;	CMakeCCompilerId.c:529: require += info_version[argc];
      0000DE EE               [12]  230 	mov	a,r6
      0000DF 24 37            [12]  231 	add	a,#_info_version
      0000E1 F5 82            [12]  232 	mov	dpl,a
      0000E3 EF               [12]  233 	mov	a,r7
      0000E4 34 01            [12]  234 	addc	a,#(_info_version >> 8)
      0000E6 F5 83            [12]  235 	mov	dph,a
      0000E8 E4               [12]  236 	clr	a
      0000E9 93               [24]  237 	movc	a,@a+dptr
      0000EA FC               [12]  238 	mov	r4,a
      0000EB 33               [12]  239 	rlc	a
      0000EC 95 E0            [12]  240 	subb	a,acc
      0000EE FA               [12]  241 	mov	r2,a
      0000EF EC               [12]  242 	mov	a,r4
      0000F0 2B               [12]  243 	add	a,r3
      0000F1 FB               [12]  244 	mov	r3,a
      0000F2 EA               [12]  245 	mov	a,r2
      0000F3 3D               [12]  246 	addc	a,r5
      0000F4 FD               [12]  247 	mov	r5,a
                                    248 ;	CMakeCCompilerId.c:540: require += info_language_dialect_default[argc];
      0000F5 EE               [12]  249 	mov	a,r6
      0000F6 25 11            [12]  250 	add	a,_info_language_dialect_default
      0000F8 FE               [12]  251 	mov	r6,a
      0000F9 EF               [12]  252 	mov	a,r7
      0000FA 35 12            [12]  253 	addc	a,(_info_language_dialect_default + 1)
      0000FC FF               [12]  254 	mov	r7,a
      0000FD AC 13            [24]  255 	mov	r4,(_info_language_dialect_default + 2)
      0000FF 8E 82            [24]  256 	mov	dpl,r6
      000101 8F 83            [24]  257 	mov	dph,r7
      000103 8C F0            [24]  258 	mov	b,r4
      000105 12 01 17         [24]  259 	lcall	__gptrget
      000108 FE               [12]  260 	mov	r6,a
      000109 33               [12]  261 	rlc	a
      00010A 95 E0            [12]  262 	subb	a,acc
      00010C FF               [12]  263 	mov	r7,a
      00010D EE               [12]  264 	mov	a,r6
      00010E 2B               [12]  265 	add	a,r3
      00010F FB               [12]  266 	mov	r3,a
      000110 EF               [12]  267 	mov	a,r7
      000111 3D               [12]  268 	addc	a,r5
                                    269 ;	CMakeCCompilerId.c:542: return require;
      000112 8B 82            [24]  270 	mov	dpl,r3
      000114 F5 83            [12]  271 	mov	dph,a
      000116 22               [24]  272 	ret
                                    273 	.area CSEG    (CODE)
                                    274 	.area CONST   (CODE)
      000137                        275 _info_version:
      000137 49                     276 	.db #0x49	;  73	'I'
      000138 4E                     277 	.db #0x4E	;  78	'N'
      000139 46                     278 	.db #0x46	;  70	'F'
      00013A 4F                     279 	.db #0x4F	;  79	'O'
      00013B 3A                     280 	.db #0x3A	;  58
      00013C 63                     281 	.db #0x63	;  99	'c'
      00013D 6F                     282 	.db #0x6F	;  111	'o'
      00013E 6D                     283 	.db #0x6D	;  109	'm'
      00013F 70                     284 	.db #0x70	;  112	'p'
      000140 69                     285 	.db #0x69	;  105	'i'
      000141 6C                     286 	.db #0x6C	;  108	'l'
      000142 65                     287 	.db #0x65	;  101	'e'
      000143 72                     288 	.db #0x72	;  114	'r'
      000144 5F                     289 	.db #0x5F	;  95
      000145 76                     290 	.db #0x76	;  118	'v'
      000146 65                     291 	.db #0x65	;  101	'e'
      000147 72                     292 	.db #0x72	;  114	'r'
      000148 73                     293 	.db #0x73	;  115	's'
      000149 69                     294 	.db #0x69	;  105	'i'
      00014A 6F                     295 	.db #0x6F	;  111	'o'
      00014B 6E                     296 	.db #0x6E	;  110	'n'
      00014C 5B                     297 	.db #0x5B	;  91
      00014D 30                     298 	.db #0x30	;  48	'0'
      00014E 30                     299 	.db #0x30	;  48	'0'
      00014F 30                     300 	.db #0x30	;  48	'0'
      000150 30                     301 	.db #0x30	;  48	'0'
      000151 30                     302 	.db #0x30	;  48	'0'
      000152 30                     303 	.db #0x30	;  48	'0'
      000153 30                     304 	.db #0x30	;  48	'0'
      000154 33                     305 	.db #0x33	;  51	'3'
      000155 2E                     306 	.db #0x2E	;  46
      000156 30                     307 	.db #0x30	;  48	'0'
      000157 30                     308 	.db #0x30	;  48	'0'
      000158 30                     309 	.db #0x30	;  48	'0'
      000159 30                     310 	.db #0x30	;  48	'0'
      00015A 30                     311 	.db #0x30	;  48	'0'
      00015B 30                     312 	.db #0x30	;  48	'0'
      00015C 30                     313 	.db #0x30	;  48	'0'
      00015D 35                     314 	.db #0x35	;  53	'5'
      00015E 2E                     315 	.db #0x2E	;  46
      00015F 30                     316 	.db #0x30	;  48	'0'
      000160 30                     317 	.db #0x30	;  48	'0'
      000161 30                     318 	.db #0x30	;  48	'0'
      000162 30                     319 	.db #0x30	;  48	'0'
      000163 30                     320 	.db #0x30	;  48	'0'
      000164 30                     321 	.db #0x30	;  48	'0'
      000165 30                     322 	.db #0x30	;  48	'0'
      000166 30                     323 	.db #0x30	;  48	'0'
      000167 5D                     324 	.db #0x5D	;  93
      000168 00                     325 	.db #0x00	;  0
      000169                        326 ___str_0:
      000169 49 4E 46 4F 3A 63 6F   327 	.ascii "INFO:compiler[SDCC]"
             6D 70 69 6C 65 72 5B
             53 44 43 43 5D
      00017C 00                     328 	.db 0x00
      00017D                        329 ___str_1:
      00017D 49 4E 46 4F 3A 70 6C   330 	.ascii "INFO:platform[]"
             61 74 66 6F 72 6D 5B
             5D
      00018C 00                     331 	.db 0x00
      00018D                        332 ___str_2:
      00018D 49 4E 46 4F 3A 61 72   333 	.ascii "INFO:arch[]"
             63 68 5B 5D
      000198 00                     334 	.db 0x00
      000199                        335 ___str_3:
      000199 49 4E 46 4F 3A 64 69   336 	.ascii "INFO:dialect_default[90]"
             61 6C 65 63 74 5F 64
             65 66 61 75 6C 74 5B
             39 30 5D
      0001B1 00                     337 	.db 0x00
                                    338 	.area XINIT   (CODE)
                                    339 	.area CABS    (ABS,CODE)
