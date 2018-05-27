
___		EQU $00
__		EQU	$00	; eng compat
;			$01
;			$02
;			$03
;			$04
;			$05
;			$06
_a_		EQU $07
_i_		EQU $08
_u_		EQU $09
_e_		EQU $0A
_o_		EQU $0B
_ka		EQU $0C
_ki		EQU $0D
_ku		EQU $0E
_ke		EQU $0F
_ko		EQU $10
_sa		EQU $11
_si		EQU $12
_su		EQU $13
_se		EQU $14
_so		EQU $15
_ta		EQU $16
_ti		EQU $17
_tu		EQU $18
_te		EQU $19
_to		EQU $1A
_na		EQU $1B
_ni		EQU $1C
_nu		EQU $1D
_ne		EQU $1E
_no		EQU $1F
_ha		EQU $20
_hi		EQU $21
_hu		EQU $22
_he		EQU $23
_ho		EQU $24
_ma		EQU $25
_mi		EQU $26
_mu		EQU $27
_me		EQU $28
_mo		EQU $29
_ya		EQU $2A
_yu		EQU $2B
_yo		EQU $2C
_ra		EQU $2D
_ri		EQU $2E
_ru		EQU $2F
_re		EQU $30
_ro		EQU $31
_wa		EQU $32
_wo		EQU $33
_n_		EQU $34
_yy		EQU $35
_uu		EQU $36
_oo		EQU $37
_tt		EQU $38
_gg		EQU $39
_pp		EQU $3A
;			$3B
;			$3C
_str	EQU $3D
_dot	EQU $3E
;			$3F
_A_		EQU $40
_I_		EQU $41
_U_		EQU $42
_E_		EQU $43
_O_		EQU $44
_KA		EQU $45
_KI		EQU $46
_KU		EQU $47
_KE		EQU $48
_KO		EQU $49
_SA		EQU $4A
_SI		EQU $4B
_SU		EQU $4C
_SE		EQU $4D
_SO		EQU $4E
_TA		EQU $4F
_TI		EQU $50
_TU		EQU $51
_TE		EQU $52
_TO		EQU $53
_HA		EQU $54
_HI		EQU $55
_HU		EQU $56
_HE		EQU $57
_HO		EQU $58
_MA		EQU $59
_MI		EQU $5A
_MU		EQU $5B
_ME		EQU $5C
_MO		EQU $5D
_YA		EQU $5E
_YO		EQU $5F
_RA		EQU $60
_RI		EQU $61
_RU		EQU $62
_RE		EQU $63
_RO		EQU $64
_WA		EQU $65
_N_		EQU $66
_II		EQU $67
_YY		EQU $68
_UU		EQU $69
_6A		EQU $6A									; don't know how to name it lol
_TT		EQU $6B
;			$6C
;			$6D
_R		EQU $6E
_NA		EQU $6F
_0		EQU $70
_1		EQU $71
_2		EQU $72
_3		EQU $73
_4		EQU $74
_5		EQU $75
_6		EQU $76
_7		EQU $77
_8		EQU $78
_9		EQU $79
_C		EQU $7A
_F		EQU $7B
_H		EQU $7C
_L		EQU $7D
_O		EQU $7E
_P		EQU $7F
_NE		EQU $80
_S		EQU $81
_NI		EQU $82
_NU		EQU $83
_NO		EQU $84
_YU		EQU $85
_86		EQU $86									; don't know how to name it lol
_AA		EQU $87
_88		EQU $88									; don't know how to name it lol
_89		EQU $89									; don't know how to name it lol
_OO		EQU $8A
_A		EQU $8B
_B		EQU $8C
_D		EQU $8D
_E		EQU $8E
_G		EQU $8F
_I		EQU $90
_J		EQU $91
_K		EQU $92
_M		EQU $93
_N		EQU $94									; used in staff roll
_Q		EQU $95
_T		EQU $96
_U		EQU $97
_V		EQU $98
_W		EQU $99
_X		EQU $9A
_Y		EQU $9B
_Z		EQU $9C
_III	EQU $9D
;			$9E
;			$9F
;			$A0
;			$A1
;			$A2
_col	EQU $A3
_cr		EQU	$A4
_lt		EQU	$A5
_ex		EQU	$A6
_qe		EQU	$A7
;
;		...
;
_aof		EQU	$B0									; exceptions from regular charset
_an0		EQU $B1
_an1		EQU	$B2
_an2		EQU	$B3
_num	EQU $B4									; number special case
;
;		...
;												; end of regular charset
_ga		EQU	$C0									; special decoding for hiragana and dictionary
_gi		EQU	$C1
_gu		EQU	$C2
_ge		EQU	$C3
_go		EQU	$C4
_za		EQU	$C5
_zi		EQU	$C6
_zu		EQU	$C7
_ze		EQU	$C8
_zo		EQU	$C9
_da		EQU	$CA
_di		EQU	$CB
_du		EQU	$CC
_de		EQU	$CD
_do		EQU	$CE
_ba		EQU	$CF
_bi		EQU	$D0
_bu		EQU	$D1
_be		EQU	$D2
_bo		EQU	$D3
_pa		EQU	$D4
_pi		EQU	$D5
_pu		EQU	$D6
_pe		EQU	$D7
_po		EQU	$D8
_______________________________		EQU	$D9
___________________________		EQU	$DA
_______________________		EQU	$DB
___________________		EQU	$DC
_______________		EQU	$DD
___________		EQU	$DE
_______		EQU	$DF
_GA		EQU	$E0
_GI		EQU	$E1
_GU		EQU	$E2
_GE		EQU	$E3
_GO		EQU	$E4
_ZA		EQU	$E5
_ZI		EQU	$E6
_ZU		EQU	$E7
_ZE		EQU	$E8
_ZO		EQU	$E9
_DA		EQU	$EA
_DI		EQU	$EB
_DU		EQU	$EC
_DE		EQU	$ED
_DO		EQU	$EE
_BA		EQU	$EF
_BI		EQU	$F0
_BU		EQU	$F1
_BE		EQU	$F2
_BO		EQU	$F3
_PA		EQU	$F4
_PI		EQU	$F5
_PU		EQU	$F6
_PE		EQU	$F7
_PO		EQU	$F8
_ka__ne__da	EQU	$F9
_te_tsu__o_	EQU	$FA
_password	EQU	$FB
;			$FC
;			$FD
_ret	EQU $FE
_eol	EQU $FF
