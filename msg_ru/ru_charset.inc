
__		EQU $00
;			$01
;			$02
;			$03
;			$04
;			$05
;			$06
_A		EQU	$07		; À
_B		EQU	$08		; Á
_V		EQU	$09		; Â
_G		EQU	$0A		; Ã
_D		EQU	$0B		; Ä
_E		EQU	$0C		; Å
_ZH		EQU	$0D		; Æ
_Z		EQU	$0E		; Ç
_I		EQU	$0F		; È
_J		EQU	$10		; É
_K		EQU	$11		; Ê
_L		EQU	$12		; Ë
_M		EQU	$13		; Ì
_N		EQU	$14		; Í
_O		EQU	$15		; Î
_P		EQU	$16		; Ï
_R		EQU	$17		; Ð
_S		EQU	$18		; Ñ
_T		EQU	$19		; Ò
_U		EQU	$1A		; Ó
_F		EQU	$1B		; Ô
_H		EQU	$1C		; Õ
_C		EQU	$1D		; Ö
_CH		EQU	$1E		; ×
_SH		EQU	$1F		; Ø
_SCH	EQU	$20		; Ù
;_Ú		EQU	$21
_JI		EQU	$22		; Û
_MZ		EQU	$23		; Ü
_JE		EQU	$24		; Ý
_JU		EQU	$25		; Þ
_JA		EQU	$26		; ß

_a		EQU	$27		; à
_b		EQU	$28		; á
_v		EQU	$29		; â
_g		EQU	$2A		; ã
_d		EQU	$2B		; ä
_e		EQU	$2C		; å
_zh		EQU	$2D		; æ
_z		EQU	$2E		; ç
_i		EQU	$2F		; è
_j		EQU	$30		; é
_k		EQU	$31		; ê
_l		EQU	$32		; ë
_m		EQU	$33		; ì
_n		EQU	$34		; í
_o		EQU	$35		; î
_p		EQU	$36		; ï
_r		EQU	$37		; ð
_s		EQU	$38		; ñ
_t		EQU	$39		; ò
_u		EQU	$3A		; ó
;			$3B
;			$3C
_str	EQU $3D
_sla	EQU	$3E
;
;		...										; unused here
;
_f		EQU	$50		; ô
_h		EQU	$51		; õ
_c		EQU	$52		; ö
_ch		EQU	$53		; ÷
_sh		EQU	$54		; ø
_sch	EQU	$55		; ù
_tz		EQU	$56		; ú
_ji		EQU	$57		; û
_mz		EQU	$58		; ü
_je		EQU	$59		; ý
_ju		EQU	$5A		; þ
_ja		EQU	$5B		; ÿ
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
_jo		EQU	$6F		; ¸
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
; î 3510
; a	3288
; å 2489
; í 2130
; ò 2080
; è 1964
; ð 1530
;/n 1528
; ñ 1516
; ë 1449
; . 1416
; â 1141
; " 1112
; ä 1099
; ó 1093
; ë 1019
; ì 0914
; ï 0785
;/e 0712
; û 0698
; ÿ 0652
; ü 0645
; é 0566
; : 0549
; ç 0543
; ý 0533
; á 0528
; ã 0499
; , 0494
; ÷ 0413
; ! 0410
; ø 0328
; æ 0299
; ö 0273
; õ 0256
; ¸ 0206
; ? 0200
; þ 0176
; ù 0098
; ô 0038
; ú 0011
