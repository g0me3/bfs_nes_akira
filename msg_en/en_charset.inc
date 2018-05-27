
__		EQU $00
;			$01
;			$02
;			$03
;			$04
;			$05
;			$06
_A		EQU	$07
_B		EQU	$08
_C		EQU	$09
_D		EQU	$0A
_E		EQU	$0B
_F		EQU	$0C
_G		EQU	$0D
_H		EQU	$0E
_I		EQU	$0F
_J		EQU	$10
_K		EQU	$11
_L		EQU	$12
_M		EQU	$13
_N		EQU	$14
_O		EQU	$15
_P		EQU	$16
_Q		EQU	$17
_R		EQU	$18
_S		EQU	$19
_T		EQU	$1A
_U		EQU	$1B
_V		EQU	$1C
_W		EQU	$1D
_X		EQU	$1E
_Y		EQU	$1F
_Z		EQU	$20
_a		EQU	$21
_b		EQU	$22
_c		EQU	$23
_d		EQU	$24
_e		EQU	$25
_f		EQU	$26
_g		EQU	$27
_h		EQU	$28
_i		EQU	$29
_j		EQU	$2A
_k		EQU	$2B
_l		EQU	$2C
_m		EQU	$2D
_n		EQU	$2E
_o		EQU	$2F
_p		EQU	$30
_q		EQU	$31
_r		EQU	$32
_s		EQU	$33
_t		EQU	$34
_u		EQU	$35
_v		EQU	$36
_w		EQU	$37
_x		EQU	$38
_y		EQU	$39
_z		EQU	$3A
;			$3B
;			$3C
_str	EQU $3D
_sla	EQU	$3E
;
;		...										; unused here
;
_0		EQU	$70									; reused numbers
_1		EQU	$71
_2		EQU	$72
_3		EQU	$73
_4		EQU	$74
_5		EQU	$75
_6		EQU	$76
_7		EQU	$77
_8		EQU	$78
_9		EQU	$79
;
;		...
;
_le		EQU $80									; extra custom dict
_me 	EQU	$81
_re 	EQU	$82
_ve 	EQU $83
_it 	EQU $84
_st 	EQU $85
_en 	EQU $86
_er 	EQU $87
_he 	EQU $88
_se 	EQU $89
_be 	EQU $8A
_ll 	EQU $8B
_e_ 	EQU $8C
__t 	EQU $8D
__a 	EQU $8E
_d_ 	EQU $8F
_ou 	EQU $90
__i 	EQU $91
__g 	EQU $92
__s 	EQU $93
_t_ 	EQU $94
_s_ 	EQU $95
__w 	EQU $96
__of 	EQU $97
_an 	EQU $98
_ow 	EQU $99
_ro 	EQU	$9A
_ar 	EQU $9B
_at		EQU $9C
_III	EQU	$9D									; used in intro text
_oo		EQU $9D									; used in messages as macro
_or		EQU $9E									; macroses continues
_ad		EQU $9F
;
;		...
;
_col	EQU $A3									; reused symbols
_dot	EQU $A4
_ddt	EQU $A5
_exc	EQU	$A6
_que	EQU	$A7
_apo	EQU $A8
_bra	EQU $A9
;
;		...
;
_aof	EQU	$B0									; old custom codes
_an0	EQU	$B1
_an1	EQU	$B2
_an2	EQU	$B3
_num	EQU	$B4									; moved here
;
;		...
;
_Yamagata	EQU	$C0								; new dictionary
_Terrorist	EQU	$C1
_Takashi	EQU	$C2
_Akira		EQU	$C3
_Colonel	EQU	$C4
_I_apo		EQU	$C5
_Groupie	EQU	$C6
_Clown		EQU	$C7
_You_apo_re	EQU	$C8
_ed			EQU	$C9
_laser		EQU	$CA
_Neo_Tokyo	EQU	$CB
_before		EQU	$CC
_building	EQU	$CD
_veryone	EQU	$CE
_around		EQU	$CF
_Masaru		EQU	$D0
_Damn		EQU	$D1
_her		EQU	$D2
_Ryu		EQU	$D3
_in 		EQU $D4								; former dupe of _before
_sewer		EQU	$D5
_tollbooth	EQU	$D6
_Nursery	EQU	$D7
_xperimental	EQU	$D8
__the		EQU	$D9
_Tetsuo		EQU	$DA
_Kaneda		EQU	$DB
_ok			EQU	$DC								; former __.... unused
_of			EQU $DD								; former __... unused
_id			EQU $DE								; former __.. unused
_ha			EQU $DF								; former __. unused
_were_		EQU	$E0
_Army		EQU	$E1
_to_		EQU	$E2
_ddt_		EQU	$E3
_dot_dot_dot	EQU	$E4
_apo_s		EQU	$E5
_hat		EQU	$E6
_Kei		EQU	$E7
_Kiyoko		EQU	$E8
_The		EQU	$E9
_Kai		EQU	$EA
_It_apo_s	EQU	$EB
_was		EQU	$EC
_ing		EQU	$ED
_irl		EQU	$EE
_for		EQU	$EF
_with		EQU	$F0
_are		EQU	$F1
_ight		EQU	$F2
_I_			EQU	$F3
_this		EQU	$F4
_But		EQU	$F5
_on			EQU	$F6
_Man		EQU	$F7
_his		EQU	$F8
_and		EQU	$F9
_you		EQU	$FA
_password	EQU	$FB
;			$FC
;			$FD
_ret		EQU $FE
_eol		EQU $FF
