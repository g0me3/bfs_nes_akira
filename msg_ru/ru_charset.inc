
__		EQU $00
;			$01
;			$02
;			$03
;			$04
;			$05
;			$06
_A		EQU	$07		; �
_B		EQU	$08		; �
_V		EQU	$09		; �
_G		EQU	$0A		; �
_D		EQU	$0B		; �
_E		EQU	$0C		; �
_ZH		EQU	$0D		; �
_Z		EQU	$0E		; �
_I		EQU	$0F		; �
_J		EQU	$10		; �
_K		EQU	$11		; �
_L		EQU	$12		; �
_M		EQU	$13		; �
_N		EQU	$14		; �
_O		EQU	$15		; �
_P		EQU	$16		; �
_R		EQU	$17		; �
_S		EQU	$18		; �
_T		EQU	$19		; �
_U		EQU	$1A		; �
_F		EQU	$1B		; �
_H		EQU	$1C		; �
_C		EQU	$1D		; �
_CH		EQU	$1E		; �
_SH		EQU	$1F		; �
_SCH	EQU	$20		; �
;_�		EQU	$21
_JI		EQU	$22		; �
_MZ		EQU	$23		; �
_JE		EQU	$24		; �
_JU		EQU	$25		; �
_JA		EQU	$26		; �

_a		EQU	$27		; �
_b		EQU	$28		; �
_v		EQU	$29		; �
_g		EQU	$2A		; �
_d		EQU	$2B		; �
_e		EQU	$2C		; �
_zh		EQU	$2D		; �
_z		EQU	$2E		; �
_i		EQU	$2F		; �
_j		EQU	$30		; �
_k		EQU	$31		; �
_l		EQU	$32		; �
_m		EQU	$33		; �
_n		EQU	$34		; �
_o		EQU	$35		; �
_p		EQU	$36		; �
_r		EQU	$37		; �
_s		EQU	$38		; �
_t		EQU	$39		; �
_u		EQU	$3A		; �
;			$3B
;			$3C
_str	EQU $3D
_sla	EQU	$3E
;
;		...										; unused here
;
_f		EQU	$50		; �
_h		EQU	$51		; �
_c		EQU	$52		; �
_ch		EQU	$53		; �
_sh		EQU	$54		; �
_sch	EQU	$55		; �
_tz		EQU	$56		; �
_ji		EQU	$57		; �
_mz		EQU	$58		; �
_je		EQU	$59		; �
_ju		EQU	$5A		; �
_ja		EQU	$5B		; �
_col	EQU $5C									; reused symbols
_dot	EQU $5D
_ddt	EQU $5E
_exc	EQU	$5F
_que	EQU	$60
_quo	EQU $61
_III	EQU	$62
_0		EQU	$63									; reused numbers
_1		EQU	$64
_2		EQU	$65
_3		EQU	$66
_4		EQU	$67
_5		EQU	$68
_6		EQU	$69
_7		EQU	$6A
_8		EQU	$6B
;			$6C
;			$6D
_9		EQU	$6E
_jo		EQU	$6F		; �
;
;		...
;
_aof	EQU	$B0									; old custom codes
_an0	EQU	$B1
_an1	EQU	$B2
_an2	EQU	$B3
_num	EQU	$B4									; moved here
_password	EQU	$FB
;			$FC
;			$FD
_ret	EQU $FE
_eol	EQU $FF


;---------------
; DICTIONARY MACROSES

_ddt__quo		EQU	$70
_Kanjeda		EQU	$71
_Tjecuo			EQU	$72
_dot_dot_dot	EQU	$73
_Kaj			EQU	$74
_Kej			EQU	$75
_exc_aof_quo	EQU	$76
_dot_aof_quo	EQU	$77
_t_mz			EQU	$78
_s_ja			EQU	$79
_to				EQU	$7A
_na				EQU	$7B
_ra				EQU	$7C
_no				EQU	$7D
_po				EQU	$7E
_ro				EQU	$7F
_ko				EQU	$80
_st				EQU	$81
_oennji			EQU	$82
_li				EQU	$83
_ne				EQU	$84
_ta				EQU	$85
_te				EQU	$86
_ka				EQU	$87
_ni				EQU	$88
_la				EQU	$89
_go				EQU	$8A
_vo				EQU	$8B
_re				EQU	$8C
_da				EQU	$8D
__i_			EQU	$8E
_mz_			EQU	$8F
_de				EQU	$90
_za				EQU	$91
_ri				EQU	$92
_lo				EQU	$93
_va				EQU	$94
_en				EQU	$95
_mo				EQU	$96
_que_quo		EQU	$97
_me				EQU	$98
_exc_quo		EQU	$99
_col_			EQU	$9A
_ja_			EQU	$9B
__v				EQU	$9C
__s				EQU	$9D
__p				EQU	$9E
__b				EQU	$9F
_ve				EQU	$A0
_ti				EQU	$A1
_ki				EQU	$A2
_ru				EQU	$A3
_l_				EQU	$A4
_e_				EQU	$A5
_di				EQU	$A6
;		EQU	$A7
;		EQU	$A8
;		EQU	$A9
;		EQU	$AA
;		EQU	$AB
;		EQU	$AC
;		EQU	$AD
;		EQU	$AE
;		EQU	$AF

;---------------
; COMPAT FOR NOW

_apo	EQU $61
_Q		EQU	$17
_W		EQU	$1D
_X		EQU	$1E
_Y		EQU	$1F
_q		EQU	$31
_w		EQU	$37
_x		EQU	$38
_y		EQU	$3A

; ENDOF COMPAT
;-------------

; unoptimized full script C4BF (50367)
; _ 5050
; � 3510
; a	3288
; � 2489
; � 2130
; � 2080
; � 1964
; � 1530
;/n 1528
; � 1516
; � 1449
; . 1416
; � 1141
; " 1112
; � 1099
; � 1093
; � 1019
; � 0914
; � 0785
;/e 0712
; � 0698
; � 0652
; � 0645
; � 0566
; : 0549
; � 0543
; � 0533
; � 0528
; � 0499
; , 0494
; � 0413
; ! 0410
; � 0328
; � 0299
; � 0273
; � 0256
; � 0206
; ? 0200
; � 0176
; � 0098
; � 0038
; � 0011
