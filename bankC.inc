
		ORG $A000

		BANK_START $3C

_apu_music_lib:
		.BYTE $15,   0
		.WORD _mus00
		.BYTE $2A,   1
		.WORD _mus01
		.BYTE $3F,   2
		.WORD _mus02
		.BYTE $54,   3
		.WORD _mus03
		.BYTE $54,   0
		.WORD _mus04
		.BYTE $69,   1
		.WORD _mus05
		.BYTE $7E,   2
		.WORD _mus06
		.BYTE $54,   0
		.WORD _mus07
		.BYTE $69,   1
		.WORD _mus08
		.BYTE $7E,   2
		.WORD _mus09
		.BYTE $93,   3
		.WORD _mus0A
		.BYTE $69,   0
		.WORD _mus0B
		.BYTE $7E,   2
		.WORD _mus0C
		.BYTE $93,   3
		.WORD _mus0D
		.BYTE $54,   0
		.WORD _mus0E
		.BYTE $69,   1
		.WORD _mus0F
		.BYTE $7E,   2
		.WORD _mus10
		.BYTE $93,   3
		.WORD _mus11
		.BYTE $54,   0
		.WORD _mus12
		.BYTE $69,   1
		.WORD _mus13
		.BYTE $7E,   2
		.WORD _mus14
		.BYTE $93,   3
		.WORD _mus15
		.BYTE $54,   0
		.WORD _mus16_un
		.BYTE $69,   1
		.WORD _mus17_un
		.BYTE $54,   0
		.WORD _mus18
		.BYTE $69,   1
		.WORD _mus19
		.BYTE $7E,   2
		.WORD _mus1A
		.BYTE $93,   3
		.WORD _mus1B
		.BYTE $54,   0
		.WORD _mus1C
		.BYTE $69,   1
		.WORD _mus1D
		.BYTE $54,   0
		.WORD _mus1E
		.BYTE $69,   1
		.WORD _mus1F
		.BYTE $7E,   2
		.WORD _mus20
		.BYTE $93,   3
		.WORD _mus21
		.BYTE $54,   0
		.WORD _mus22_un
		.BYTE $69,   1
		.WORD _mus23_un
		.BYTE $7E,   2
		.WORD _mus24_un
		.BYTE $93,   3
		.WORD _mus25_un
		.BYTE $54,   0
		.WORD _mus26
		.BYTE $69,   1
		.WORD _mus27
		.BYTE $7E,   2
		.WORD _mus28
		.BYTE $54,   0
		.WORD _mus29
		.BYTE $69,   1
		.WORD _mus2A
		.BYTE $7E,   2
		.WORD _mus2B
		.BYTE $93,   3
		.WORD _mus2C
		.BYTE $54,   0
		.WORD _mus2D_un
		.BYTE $69,   1
		.WORD _mus2E_un
		.BYTE $7E,   2
		.WORD _mus2F_un
		.BYTE $93,   3
		.WORD _mus30_un
		.BYTE $54,   0
		.WORD _mus31_un
		.BYTE $69,   1
		.WORD _mus32_un
		.BYTE $7E,   2
		.WORD _mus33_un
		.BYTE $54,   0
		.WORD _mus34
		.BYTE $69,   1
		.WORD _mus35
		.BYTE $7E,   2
		.WORD _mus36
		.BYTE $93,   3
		.WORD _mus37
		.BYTE $15,   2
		.WORD _mus38
		.BYTE $2A,   3
		.WORD _mus39
		.BYTE $15,   0
		.WORD _mus3A
		.BYTE $2A,   3
		.WORD _mus3B
		.BYTE $3F,   3
		.WORD _mus3C
		.BYTE $3F,   3
		.WORD _mus3D_un
		.BYTE $3F,   3
		.WORD _mus3E
		.BYTE $3F,   3
		.WORD _mus3F
		.BYTE $3F,   3
		.WORD _mus40
		.BYTE $3F,   3
		.WORD _mus41
		.BYTE $3F,   3
		.WORD _mus42
		.BYTE $3F,   3
		.WORD _mus43
		.BYTE $2A,   0
		.WORD _mus44
		.BYTE $3F,   1
		.WORD _mus45
		.BYTE $54,   2
		.WORD _mus46
		.BYTE $69,   3
		.WORD _mus47
		.BYTE $3F,   3
		.WORD _mus48
		.BYTE $15,   2
		.WORD _mus49
		.BYTE $15,   0
		.WORD _mus4A_un
		.BYTE $2A,   2
		.WORD _mus4B
		.BYTE $3F,   3
		.WORD _mus4C
		.BYTE $3F,   3
		.WORD _mus4D
		.BYTE $3F,   3
		.WORD _mus4E
		.BYTE $2A,   0
		.WORD _mus4F
		.BYTE $3F,   1
		.WORD _mus50
		.BYTE $54,   2
		.WORD _mus51
		.BYTE $69,   3
		.WORD _mus52
		.BYTE 	0,   0
		.WORD _mus53
		.BYTE $15,   1
		.WORD _mus54
		.BYTE $2A,   2
		.WORD _mus55
		.BYTE $3F,   3
		.WORD _mus56
		.BYTE $2A,   0
		.WORD _mus57
		.BYTE $2A,   2
		.WORD _mus58
		.BYTE $3F,   3
		.WORD _mus59
		.BYTE $3F,   0
		.WORD _mus5A
		.BYTE $54,   1
		.WORD _mus5B
		.BYTE $69,   3
		.WORD _mus5C
		.BYTE $54,   0
		.WORD _mus5D
		.BYTE $69,   2
		.WORD _mus5E
		.BYTE $7E,   3
		.WORD _mus5F
		.BYTE $3F,   3
		.WORD _mus60
		.BYTE $2A,   0
		.WORD _mus61_un
		.BYTE $3F,   1
		.WORD _mus62_un
		.BYTE $54,   3
		.WORD _mus63_un
		.BYTE $3F,   3
		.WORD _mus64
		.BYTE $3F,   3
		.WORD _mus65_un
		.BYTE $2A,   0
		.WORD _mus66
		.BYTE $3F,   1
		.WORD _mus67
		.BYTE $54,   2
		.WORD _mus68
		.BYTE $69,   3
		.WORD _mus69
		.BYTE $2A,   2
		.WORD _mus6A
		.BYTE $3F,   3
		.WORD _mus6B
		.BYTE $3F,   0
		.WORD _mus6C
		.BYTE $54,   1
		.WORD _mus6D
		.BYTE $69,   2
		.WORD _mus6E
		.BYTE $7E,   3
		.WORD _mus6F
		.BYTE $54,   0
		.WORD _mus70_un
		.BYTE $69,   1
		.WORD _mus71_un
		.BYTE $7E,   2
		.WORD _mus72_un
		.BYTE $2A,   0
		.WORD _mus73
		.BYTE $3F,   1
		.WORD _mus74
		.BYTE $54,   2
		.WORD _mus75
		.BYTE $69,   3
		.WORD _mus76
		.BYTE $3F,   0
		.WORD _mus77
		.BYTE $54,   1
		.WORD _mus78
		.BYTE $69,   3
		.WORD _mus79
		.BYTE $3F,   3
		.WORD _mus7A
		.BYTE $3F,   3
		.WORD _mus7B
		.BYTE $2A,   0
		.WORD _mus7C
		.BYTE $3F,   1
		.WORD _mus7D
		.BYTE $54,   2
		.WORD _mus7E
		.BYTE $69,   3
		.WORD _mus7F
		.BYTE $54,   0
		.WORD _mus80
		.BYTE $69,   1
		.WORD _mus81
		.BYTE $3F,   0
		.WORD _mus82
		.BYTE $54,   1
		.WORD _mus83
		.BYTE $69,   2
		.WORD _mus84
		.BYTE $7E,   3
		.WORD _mus85
		.BYTE $3F,   0
		.WORD _mus86
		.BYTE $54,   1
		.WORD _mus87
		.BYTE $3F,   3
		.WORD _mus88
		.BYTE $3F,   3
		.WORD _mus89
		.BYTE $3F,   3	; bug? conflicts with hover sound in mini-game of section D
		.WORD _mus8A
		.BYTE $3F,   3
		.WORD _mus8B
		.BYTE $3F,   3
		.WORD _mus8C_un
		.BYTE $3F,   0
		.WORD _mus8D
		.BYTE $54,   1
		.WORD _mus8E
		.BYTE $69,   2
		.WORD _mus8F
		.BYTE $7E,   3
		.WORD _mus90
		.BYTE $3F,   0
		.WORD _mus91
		.BYTE $54,   1
		.WORD _mus92
		.BYTE $3F,   3
		.WORD _mus93
		.BYTE $3F,   3
		.WORD _mus94_un
		.BYTE $3F,   0
		.WORD _mus95_un
		.BYTE $54,   1
		.WORD _mus96_un
		.BYTE $69,   3
		.WORD _mus97_un
		.BYTE $54,   0
		.WORD _mus98
		.BYTE $69,   1
		.WORD _mus99
		.BYTE $7E,   2
		.WORD _mus9A
		.BYTE $93,   3
		.WORD _mus9B_un
		.BYTE $54,   3
		.WORD _mus9C
		.BYTE $54,   0
		.WORD _mus9D
		.BYTE $69,   1
		.WORD _mus9E
		.BYTE $7E,   2
		.WORD _mus9F
		.BYTE $93,   3
		.WORD _musA0
		.BYTE $15,   0
		.WORD _musA1_un
		.BYTE $2A,   1
		.WORD _musA2_un
		.BYTE $3F,   2
		.WORD _musA3
		.BYTE $54,   3
		.WORD _musA4
		.BYTE $15,   0
		.WORD _musA5_un
		.BYTE $2A,   1
		.WORD _musA6_un
		.BYTE $3F,   2
		.WORD _musA7_un
		.BYTE $54,   3
		.WORD _musA8_un
		.BYTE $15,   0
		.WORD _musA9
		.BYTE $2A,   1
		.WORD _musAA
		.BYTE $3F,   2
		.WORD _musAB
		.BYTE $54,   3
		.WORD _musAC
		.BYTE $15,   0
		.WORD _musAD_un
		.BYTE $2A,   1
		.WORD _musAE_un
		.BYTE $3F,   2
		.WORD _musAF_un
		.BYTE $54,   3
		.WORD _musB0_un
		.BYTE $15,   0
		.WORD _musB1
		.BYTE $2A,   1
		.WORD _musB2
		.BYTE $3F,   2
		.WORD _musB3
		.BYTE $54,   3
		.WORD _musB4
		.BYTE $15,   0
		.WORD _musB5_un
		.BYTE $2A,   1
		.WORD _musB6_un
		.BYTE $3F,   2
		.WORD _musB7_un
		.BYTE $54,   3
		.WORD _musB8_un
		.BYTE $2A,   0
		.WORD _musB9_un
		.BYTE $3F,   1
		.WORD _musBA_un
		.BYTE $54,   2
		.WORD _musBB_un
		.BYTE $69,   3
		.WORD _musBC_un
		.BYTE $3F,   3
		.WORD _musBD_un
		.BYTE $54,   0
		.WORD _musBE
		.BYTE $69,   1
		.WORD _musBF
		.BYTE $7E,   2
		.WORD _musC0
		.BYTE $93,   3
		.WORD _musC1
		.BYTE $2A,   0
		.WORD _musC2
		.BYTE $3F,   1
		.WORD _musC3
		.BYTE $54,   2
		.WORD _musC4
		.BYTE $69,   3
		.WORD _musC5
		.BYTE $3F,   3
		.WORD _musC6
		.BYTE $3F,   3
		.WORD _musC7
		.BYTE $3F,   3
		.WORD _musC8
		.BYTE $3F,   3
		.WORD _musC9
		.BYTE $3F,   3
		.WORD _musCA_un
		.BYTE $3F,   3
		.WORD _musCB
		.BYTE $7E,   1
		.WORD _musCC
		.BYTE $3F,   3
		.WORD _musCD
		.BYTE 	0,   4
		.WORD _musCE
		.BYTE $15,   5
		.WORD _musCF
		.BYTE $54,   0
		.WORD _musD0
		.BYTE $69,   1
		.WORD _musD1
		.BYTE $7E,   2
		.WORD _musD2
		.BYTE $93,   3
		.WORD _musD3
_mus00:
		.BYTE   8,  0,$1F,  0,$C1,$80,$A3,$21,$FD,$FE,$20,  8,$22,  4,$22,  2
		.BYTE $20,  1,$1B,  8,$24,  5,$34,  1,$35,  1,$1F,  1,$37, $D,$44,  1
		.BYTE $45,  1,$1F,  1,$47,$11,$B1,  2,$1F,  2,$3A,  1,$1F,  1,$3A,  1
		.BYTE $38,  1,$37,  1,$43,  2,$42,  3,$3A,  1,$40,  1,$1F,  1,$40,  8
		.BYTE $40,  1,$43,  1,$42,  1,$40,  1,$47,  1,$45,  1,$43,  1,$42,  1
		.BYTE $43,  1,$45,  3,$4A,  2,$48,  1,$47,  1,$45,  1,$47,  3,$4A,  2
		.BYTE $47,  1,$4A,  1,$4B,  1,$50,  8,$A1,$94,$A3,$FE,$50,  8,$EF,  8
		.BYTE $A1,  0,$C9,  2,$FD,$FE,$3B,  1,$40,  1,$AE,$80,$44,  1,$AE,$FE
		.BYTE $40,  1,$B0,  0,$FF
_mus01:
		.BYTE   8,  0,$1F,  0,$C1,$80,$A3,$10,$FD,$FE,$15,  8,$17,  4,$17,  2
		.BYTE $15,  1,$14,  8,$19,  5,$29,  1,$2B,  1,$1F,  1,$30, $D,$39,  1
		.BYTE $3B,  1,$1F,  1,$40,$11,$C5,$10,$15,  1,$45,  1,$40,  1,$42,  1
		.BYTE $43,  1,$3A,  1,$35,  1,$17,  2,$47,  1,$42,  1,$44,  1,$45,  1
		.BYTE $40,  1,$37,  1,$14,  2,$44,  1,$3B,  1,$41,  1,$42,  1,$39,  1
		.BYTE $34,  1,$19,  2,$49,  1,$44,  1,$46,  1,$C1,$80,$29,  1,$2B,  1
		.BYTE $1F,  1,$30, $D,$2A,  1,$2B,  1,$1F,  1,$30,$11,$C9,$50,$A0,$1F
		.BYTE $1F,  4,$3A,  1,$1F,  1,$3A,  1,$38,  1,$37,  1,$43,  2,$42,  3
		.BYTE $3A,  1,$40,  1,$1F,  1,$40,  8,$40,  1,$43,  1,$42,  1,$40,  1
		.BYTE $47,  1,$45,  1,$43,  1,$42,  1,$43,  1,$45,  3,$4A,  2,$48,  1
		.BYTE $47,  1,$45,  1,$47,  3,$4A,  2,$47,  1,$4A,  1,$4B,  1,$50,  8
		.BYTE $A1,$94,$50,  8,$A1,  0,$EF,  8,$FD,$FE,$C9,  2,$47,  1,$4B,  1
		.BYTE $50,  1,$4B,  1,$B0,  0,$FF
_mus02:
		.BYTE   8,$10,  0,  0,$A3,$20,$FD,$FE,$25,  1,$B7,  0,$FD,$FE,$27,  1
		.BYTE $B5,  0,$25,  1,$24,  2,$FD,$FE,$24,  1,$B4,  0,$25,  1,$29,  2
		.BYTE $29,  1,$29,  1,$29,  1,$2A,  1,$2B,  1,$1F,  1,$30,  2,$30,  1
		.BYTE $30,  1,$30,  1,$30,  1,$27,  1,$2A,  1,$2B,  1,$33,  1,$2A,  1
		.BYTE $23,  1,$25,  1,$2A,  1,$2B,  1,$1F,  1,$30,  2,$30,  1,$30,  1
		.BYTE $30,  1,$35,  1,$34,  1,$30,  1,$35,  1,$34,  1,$30,  1,$25,  1
		.BYTE $26,  1,$27,  1,$23,  1,$27,  1,$2A,  1,$B1,  2,$FD,$FE,$28,  2
		.BYTE $33,  1,$28,  1,$1F,  1,$28,  1,$33,  1,$28,  1,$2A,  2,$35,  1
		.BYTE $2A,  1,$1F,  1,$2A,  1,$35,  1,$2A,  1,$30,  1,$27,  1,$29,  1
		.BYTE $2A,  1,$1F,  1,$2A,  1,$29,  1,$2A,  1,$30,  1,$27,  1,$29,  1
		.BYTE $2A,  1,$1F,  1,$2A,  1,$29,  1,$2A,  1,$28,  2,$33,  1,$28,  1
		.BYTE $1F,  1,$28,  1,$33,  1,$28,  1,$2A,  2,$35,  1,$2A,  1,$1F,  1
		.BYTE $2A,  1,$35,  1,$2A,  1,$30,  1,$30,  1,$30,  1,$30,  1,$30,  1
		.BYTE $30,  1,$30,  1,$30,  1,$30,  1,$1F,  7,$FD,$FE,$24,  1,$24,  1
		.BYTE $1F,  3,$34,  1,$1F,  1,$34,  1,$1F,  1,$67,  1,$27,  2,$B1,  0
		.BYTE $FF
_mus03:
		.BYTE   8,  0,$1F,  0,$FD,$FE,$C9,  2, $E,  1,  3,  1,$C1,$10,  8,  1
		.BYTE $C9,  2,  3,  1, $E,  1, $E,  1,$C1,$10,  7,  1,  3,  1,$C9,  2
		.BYTE $BE,  0,$C1,$10, $E,  1,  6,  1,  7,  1,  8,  1,  9,  1,  7,  1
		.BYTE  $A,  1, $B,  1,$FD,$FE, $E,  1,$1F,  1,$C1,$15,  8,  1,$C9,  2
		.BYTE  $E,  1,$1F,  1, $E,  1,$C1,$16, $A,  2,$C9,  2,$B5,  0,$C1,$10
		.BYTE  $E,  1, $E,  1, $E,  1, $E,  1, $E,  1, $E,  1, $E,  1, $E,  1
		.BYTE  $E,  1, $F,  1, $E,  1, $D,  1, $C,  1, $B,  1, $A,  1,  9,  1
		.BYTE $EF,  8,$FD,$FE,$C1,$20,  8,  1,  8,  1,  1,  1,  1,  1,  1,  1
		.BYTE   1,  1,  1,  1,  8,  1,$1F,  1,  8,  2, $E,  1, $B,  1, $B,  1
		.BYTE $1F,  2,$B0,  0,$FF
_mus04:
		.BYTE   5,  0,$1A,  0,$C5,  3,$14,  1,$15,  1,$16,  2,$15,  2,$1F,  1
		.BYTE $14,  1,$1F,  2,$14,  1,$15,  1,$16,  1,$17,  1,$18,  2,$B0,  2
		.BYTE $FF
_mus05:
		.BYTE   5,  3,$1A,$84,$C5,  1,$A3,$20,$FD,$FE,$56,  1,$56,  1,$1F,  1
		.BYTE $56,  1,$56,  1,$56,  1,$56,  1,$56,  1,$B0,  2,$FF
_mus06:
		.BYTE   5,  6,  0,  0,$FD,$FE,$20,  1,$22,  1,$23,  2,$22,  3,$20,  1
		.BYTE $1F,  2,$20,  1,$22,  1,$23,  1,$24,  1,$25,  2,$B0,  0,$FF
_mus07:
		.BYTE   7,  0,$1F,  0,$C9,  1,$17,  2,$1F, $C,$17,  2,$17,  1,$17,  1
		.BYTE $1F,  6, $A,  1, $B,  1,$10,  1,$17,  2, $A,  1, $B,  1,$10,  1
		.BYTE $B1,  2,$10,  4,$10,  4,$10,  2,$10,  2,$12,  2,$13, $A,$1F,  8
		.BYTE $B0,  2,$FF
_mus08:
		.BYTE   7,  0,$1F,  0,$C9,  1,$12,  2,$1F, $C,$12,  2,$12,  1,$12,  1
		.BYTE $1F,  6,$1A,  1,$1B,  1,$20,  1,$27,  2,$1A,  1,$1B,  1,$20,  1
		.BYTE $B1,  2,$17,  4,$17,  4,$17,  2,$17,  2,$19,  2,$1A, $A,$1F,  8
		.BYTE $B0,  2,$FF
_mus09:
		.BYTE   7,$10,  0,  0,$FD,$FE,$27,  2,$1F, $C,$27,  2,$27,  1,$27,  1
		.BYTE $1F,  6,$2A,  1,$2B,  1,$30,  1,$37,  2,$2A,  1,$2B,  1,$30,  1
		.BYTE $B1,  0,$20,  4,$20,  4,$20,  2,$20,  2,$22,  2,$23, $A,$1F,  8
		.BYTE $B0,  2,$FF
_mus0A:
		.BYTE   7,  0,$1F,  0,$C9,  3, $E,  2, $E,  2,  7,  2,  1,  1,  3,  1
		.BYTE $B7,  2,$FD,$FE,  8,  1,  3,  1,  2,  1,  3,  1,$B5,  0,$C1,$10
		.BYTE   7,  1,  7,  1,  7,  1,  7,  1,  7,  1,  7,  1,  7,  1,  7,  1
		.BYTE $C9,  3,$B0,  2,$FF
_mus0B:
		.BYTE   5,  0,$1F,  0,$C9,  1,$2A,  1,$29,  1,$1F,  1,$28,  1,$1F,  1
		.BYTE $26,  1,$27,  1,$28,  1,$31,  1,$30,  1,$1F,  6,$B0,  2,$FF
_mus0C:
		.BYTE   5,$10,  0,  0,$FD,$FE,$23,  4,$23,  4,$23,  4,$23,  4,$B0,  0
		.BYTE $FF
_mus0D:
		.BYTE   5,  0,$1F,  0,$C9,  3,  7,  1,  3,  1,  1,  1,  3,  1,$B0,  2 ;	-unused-
		.BYTE $FF
_mus0E:
		.BYTE   4,  0,$1A,$92,$A3,$20,$40,  1,$42,  3,$1F,  9,$50,  3,$B0,  2
		.BYTE $FF
_mus0F:
		.BYTE   4,  0,$1A,$92,$A3,$10,$AE,$80,$39,  1,$3B,  3,$1F,  9,$46,  3
		.BYTE $B0,  2,$FF
_mus10:
		.BYTE   4,$10,  0,  0,$FD,$FE,$1F,  1,$26,  1,$1F,  1,$26,  1,$B6,  0
		.BYTE $27,  2,$27,  2,$B0,  2,$FF
_mus11:
		.BYTE   4,  0,$1F,  0,$C9,  1,  8,  1, $E,  1, $E,  1,  3,  1,  6,  1
		.BYTE   6,  1,$1F,  1, $E,  1,$B0,  2,$FF
_mus12:
		.BYTE   5,  0,$1F,  0,$C5,  3,$A3,$21,$40,  1,$41,  1,$AE,$80,$23,  1
		.BYTE $39,  1,$AE,  0,$BA,  2,$FD,$FE,$40,  1,$41,  1,$48,  1,$AE,$80
		.BYTE $26,  1,$AE,  0,$40,  1,$41,  1,$AE,$80,$39,  1,$AE,  0,$3B,  1
		.BYTE $BF,  0,$B0,  2,$FF
_mus13:
		.BYTE   5,  2,$10,  0,$DF,$10,$C5,  2,$22,  1,$26,  1,$28,  1,$22,  1
		.BYTE $26,  1,$28,  1,$22,  2,$22,  2,$1F,  2,$22,  1,$26,  1,$28,  1
		.BYTE $22,  1,$26,  1,$28,  1,$22,  2,$22,  2,$22,  2,$BF,  2,$A0,$10
		.BYTE $B0,  2,$FF
_mus14:
		.BYTE   5,  6,  0,  0,$FD,$FE,$26,  1,$27,  1,$41,  1,$56,  1,$56,  1
		.BYTE $24,  1,$26,  1,$23,  1,$B0,  0,$FF
_mus15:
		.BYTE   5,  0,$1F,  0,$C1,  8,$FD,$FE,  8,  1,  3,  1,  2,  1,  3,  1
		.BYTE   8,  1,  3,  1,  2,  1,  3,  1,  3,  1,  2,  1,  8,  1,  3,  1
		.BYTE   2,  1,  8,  1,  3,  1, $E,  1,$B5,  0,$FD,$FE,$C1,$16, $E,  1
		.BYTE   7,  3, $E,  1,  7,  3, $E,  1,  7,  3, $E,  1,  7,  3,$B2,  0
		.BYTE $B0,  2,$FF
_mus16_un:
		.BYTE  $B,  2,$1F,  0,$C9,  5,$A3,$21,$FD,$FE,$3A,  4,$3A,  4,$3A,  1
		.BYTE $33,  3,$B0,  2,$FF
_mus17_un:
		.BYTE  $B,  2,$15,  0,$C2,  7,$A3,$21,$FD,$FE,$3A,  4,$3A,  4,$3A,  1
		.BYTE $33,  2,$B0,  2,$FF,$FF
_mus18:
		.BYTE   5,  0,$1F,$92,$A3,$20,$FD,$FE,$40,  1,$46,  1,$1F,  2,$B3,  0
		.BYTE $FD,$FE,$1F,$20,$40,  1,$3B,  1,$3A,  1,$39,  3,$39,  1,$38,  1
		.BYTE $37,  1,$36,  3,$36,  1,$35,  1,$34,  1,$33,  1,$1F,$20,$B0,  0
		.BYTE $FF
_mus19:
		.BYTE   5,  0,$1F,$92,$A3,$10,$FD,$FE,$39,  1,$43,  1,$1F,  2,$B3,  0
		.BYTE $FD,$FE,$1F,$20,$39,  1,$38,  1,$37,  1,$36,  3,$36,  1,$35,  1
		.BYTE $34,  1,$33,  3,$33,  1,$32,  1,$31,  1,$30,  1,$1F,$20,$B0,  0
		.BYTE $FF
_mus1A:
		.BYTE   5,$20,  0,  0,$FD,$FE,$23,  1,$23,  1,$56,  2,$B3,  0,$FD,$FE
		.BYTE $1F,  2,$A2,$10,$23,  2,$1F,  6,$23,  1,$23,  1,$1F,  4,$B0,  0
		.BYTE $FF
_mus1B:
		.BYTE   5,  0,$1F,  0,$C9,  2,$FD,$FE,  9,  1,  3,  1,  1,  1,  3,  1
		.BYTE $B3,  0,$FD,$FE, $E,  1, $E,  1,  3,  1,  1,  1,  8,  2, $E,  1
		.BYTE  $E,  1,$1F,  1,  3,  1,  2,  1,  1,  1,  8,  2,  6,  2,$B0,  0
		.BYTE $FF
_mus1C:
		.BYTE   5,  2,$18,  0,$C9,  6,$AE,$80,$FD,$FE,$37,  4,$AE,$80,$3B,  4
		.BYTE $AE,  0,$37,  4,$37,  1,$AE,$80,$3B,  1,$AE,  0,$40,  4,$37,  2
		.BYTE $37,  2,$1F,  2,$37,  2,$1F,  2,$37,  1,$AE,$80,$3B,  1,$AE,  0
		.BYTE $40,  1,$37,  1,$AE,$80,$3B,  1,$AE,  0,$40,  1,$B0,  2,$FF
_mus1D:
		.BYTE   5,  0,$16,  0,$A3,$21,$1F,  1,$C9,  6,$AE,$80,$FD,$FE,$37,  4
		.BYTE $AE,$80,$3B,  4,$37,  4,$37,  1,$3B,  1,$40,  4,$37,  2,$37,  2
		.BYTE $1F,  2,$37,  2,$1F,  2,$3B,  1,$40,  1,$37,  1,$3B,  1,$40,  1
		.BYTE $B0,  2,$FF
_mus1E:
		.BYTE   9,  3,$18,$94,$C9,  7,$A3,$20,$30,  2,$33,  2,$3A,  2,$B0,  2
		.BYTE $FF
_mus1F:
		.BYTE   9,  3,$15,  0,$C9,  7,$A3,$20,$1F,  1,$30,  2,$33,  2,$3A,  1
		.BYTE $B0,  2,$FF
_mus20:
		.BYTE   9,$30,  0,  0,$A3,$21,$FD,$FE,$20,  2,$1F,  8,$20,  2,$20,  2
		.BYTE $1F,  4,$20,  2,$22,  2,$23,  2,$25,  2,$1F,  8,$23,  2,$23,  2
		.BYTE $1F,  4,$27,  2,$25,  2,$27,  2,$B0,  2,$FF
_mus21:
		.BYTE   9,  0,$1F,  0,$C9,  2,$FD,$FE, $E,  2,  3,  2,  1,  2,  8,  2
		.BYTE   3,  2, $E,  2,$B0,  0,$FF
_mus22_un:
		.BYTE   5,  0,$19,$92,$A3,$20,$36,  2,$1F,  2,$36,  2,$1F,  2,$36,  2
		.BYTE $36,  2,$1F,  6,$46,  2,$B0,  2,$FF
_mus23_un:
		.BYTE   5,  0,$19,$92,$A3,$20,$23,  2,$1F,  2,$23,  2,$1F,  2,$23,  2
		.BYTE $23,  2,$1F,  6,$33,  2,$B0,  2,$FF
_mus24_un:
		.BYTE   5, $A,  0,  0,$FD,$FE,$1F,  1,$27,  1,$25,  1,$26,  1,$1F,  3
		.BYTE $26,  1,$27,  1,$61,  1,$23,  1,$63,  1,$23,  1,$25,  1,$B0,  2
		.BYTE $FF
_mus25_un:
		.BYTE   5,  0,$10,  0,$DF,  7,$FD,$FE,$C1,$10,  8,  1,$C9,  3,  3,  1
		.BYTE   2,  1,  3,  1,$C1,$10,  7,  1,$C9,  3,  1,  1,  3,  1,  2,  1
		.BYTE $C1,$10,  8,  2,  8,  2,  5,  1,  1,  1,  8,  2,  8,  2, $A,  2
		.BYTE $B2,  2,$C1,$12,  5,  1,  5,  1,  5,  1,  5,  1,  6,  1,  6,  1
		.BYTE   6,  1,  6,  1,  8,  1,  8,  1,  8,  1,  8,  1, $A,  1, $A,  1
		.BYTE  $A,  1, $A,  1, $E,  1, $E,  1, $E,  1, $E,  1,$C1,$10,$B0,  2
		.BYTE $FF
_mus26:
		.BYTE  $A,  2,$1F,  0,$C9,  3,$36,  1,$3B,  1,$36,  1,$32,  1,$3B,  2
		.BYTE $36,  1,$30,  1,$39,  2,$B0,  2,$FF
_mus27:
		.BYTE  $A,  3,$17,  0,$1F,  1,$C9,  3,$36,  1,$3B,  1,$36,  1,$32,  1
		.BYTE $3B,  2,$36,  1,$30,  1,$39,  1,$B0,  2,$FF
_mus28:
		.BYTE  $A,$7F,  0,  0,$FD,$FE,$27,  4,$1F,  6,$B1,  0,$FD,$FE,$20,  4
		.BYTE $1F,  6,$B1,  0,$B0,  2,$FF
_mus29:
		.BYTE   4,  0,$1F,$9D,$C5,  3,$FD,$FE,$34,  1,$34,  1,$34,  1,$34,  1
		.BYTE $1F, $A,$34,  1,$34,  1,$1F, $E,$29,  2,$B0,  2,$FF
_mus2A:
		.BYTE   4,  3,$10,$9D,$DF,$10,$C2,  7,$A3,$20,$FD,$FE,$36,  1,$38,  1
		.BYTE $41,  1,$B4,  0,$35,  1,$38,  1,$41,  1,$36,  1,$39,  1,$42,  1
		.BYTE $37,  1,$3B,  1,$43,  1,$38,  1,$40,  1,$44,  1,$39,  1,$3B,  1
		.BYTE $41,  1,$45,  1,$47,  1,$B0,  2,$FF
_mus2B:
		.BYTE   4,  7,  0,  0,$FD,$FE,$23,  1,$23,  1,$23,  1,$23,  1,$1F, $A
		.BYTE $23,  1,$23,  1,$1F, $E,$26,  2,$B0,  0,$FF
_mus2C:
		.BYTE   4,  0,  1,  0,$FD,$FE,  7,  1,  7,  1,  7,  1,  7,  1,$A0,  0
		.BYTE $FD,$FE,  3,  1,  1,  1,  1,  1,  1,  1,$B1,  0,  3,  1,  1,  1
		.BYTE $A0,  1,  7,  1,  7,  1,$A0,  0,$FD,$FE,  3,  1,  1,  1,  1,  1
		.BYTE   1,  1,$B2,  0,  3,  1,  1,  1,$A0,  2,  5,  2,$A0,  1,$B0,  2
		.BYTE $FF
_mus2D_un:
		.BYTE   8,  0,$1F,  0,$A3,$20,$C2,$10,$46,  4,$1F, $C,$43,  4,$1F,  4
		.BYTE $B0,  2,$FF
_mus2E_un:
		.BYTE   8,  0,$1F,  0,$A3,$20,$C2,$10,$3B,  4,$1F, $C,$56,  4,$1F,  4
		.BYTE $B0,  2,$FF
_mus2F_un:
		.BYTE   0,  2,  0,  0,$FD,$FE,$24,  1,$BF,  0,$FD,$FE,$26,  1,$BF,  0
		.BYTE $B0,  2,$FF
_mus30_un:
		.BYTE   8,  0,$1F,  0,$C2,$30,  5,  4,$C9,  2,  3,  1,  1,  1,$C1,$20
		.BYTE   8,  2,$C2,  5,$B0,  2,$FF
_mus31_un:
		.BYTE   7,  3,$1F,  0,$C2,$20,$A3,$21,$FD,$FE,$1F,  2,$3A,$10,$37,$10
		.BYTE $35,$1D,$B0,  2,$FF
_mus32_un:
		.BYTE   7,  3,$1F,  0,$A3,$20,$C2,$10,$FD,$FE,$32,$10,$28,$10,$27,$10
		.BYTE $32,$10,$B0,  0,$FF
_mus33_un:
		.BYTE   7,$7F,  0,  0,$FD,$FE,$23,  1,$B0,  0,$FF
_mus34:
		.BYTE   4,  0,$1F,  0,$C1,  3,$A3,$21,$32,  1,$33,  1,$38,  1,$32,  1
		.BYTE $33,  1,$38,  1,$29,  1,$2A,  1,$33,  1,$29,  1,$2A,  1,$33,  1
		.BYTE $B1,  2,$FF
_mus35:
		.BYTE   4,  0,$1F,  0,$C9,  3,$A3,$21,$32,  1,$33,  1,$38,  1,$32,  1
		.BYTE $33,  1,$38,  1,$29,  1,$2A,  1,$33,  1,$29,  1,$2A,  1,$33,  1
		.BYTE $B1,  2,$FF
_mus36:
		.BYTE   4,  5,  0,  0,$FD,$FE,$20,  1,$20,  1,$20,  1,$B7,  0,$FF
_mus37:
		.BYTE   4,  0,$1F,  0,$C9,  2,$FD,$FE,  6,  1,  6,  1,  6,  1,  6,  3
		.BYTE  $A,  1, $A,  1, $A,  1, $E,  3,  6,  1,  6,  1,  6,  1,  6,  3
		.BYTE  $A,  1, $A,  1, $A,  1,$C1,$50,  7,$10,$FF
_mus38:
		.BYTE   0,$7F,  0,  0,$1F,$30,$FD,$FE,$20,$10,$BF,  0,$FF
_mus39:
		.BYTE   0,  0,$1F,  0, $E,  3, $D,  3, $C,  3, $C,  3, $B,  3, $A,  3
		.BYTE   9,  3,  8,  3,  8,  3,  7,  3,  6,  3,  5,  3,  4,  3,  2,  2
		.BYTE   1,  1, $C,  1, $E,  1,$EF,$40,$FD,$FE, $E,$10,$B0,  0,$FF
_mus3A:
		.BYTE   0,  1,$14,$82,$FD,$FE,$C1,$60,$57, $A,$B0,  0,$FF
_mus3B:
		.BYTE   0,  0,  9,  0,$FD,$FE,  1,  3,  0,  1, $E,  1, $D,  1,$B0,  0
		.BYTE $FF
_mus3C:
		.BYTE   0,  0,  2,  0,  7,  1,  5,  1,$FD,$FE,  2,  1,$B0,  0,$FF
_mus3D_un:
		.BYTE   0,  0,$1F,  0, $A,  1,$EF,  3,$FD,$FE,  1,  1,$B0,  0,$FF
_mus3E:
		.BYTE   0,  0,  2,  0, $F,  3, $E,  2, $B,  1,$FF
_mus3F:
		.BYTE   0,  0,  2,  0, $E,  2, $A,  2,  6,  2, $A,  2, $F,  5,$FF
_mus40:
		.BYTE   0,  0,$1F,  0,$C9,$10, $E,  3, $A,  2,  5,  7,$FF
_mus41:
		.BYTE   0,  0,$1F,  0, $A,  2, $A,  2,  3,  2,$EF,  7,$FD,$FE, $B,  1
		.BYTE $B0,  0,$FF
_mus42:
		.BYTE   0,  0,$1F,  0, $E,  5,$EF,  7,$FD,$FE,  9,  1,$B0,  0,$FF
_mus43:
		.BYTE   1,  0,$1F,  0,  1,  2,  2,  2,  3,  2,  4,  2,  5,  2, $E,  2
		.BYTE  $F,  2, $A,  2,  9,  2,$EF,  7,$FD,$FE, $A,  1,$B0,  0,$FF
_mus44:
		.BYTE   0,  0,$1F,$8D,$A3,$20,  2,  1,$B0,  2,$FF
_mus45:
		.BYTE   0,  0,$1F,$8D,  1,  5,  5,  8,$A1,$95,  6,  5,$A1,  0,$FD,$FE
		.BYTE   3,  1,  3,  1,  2,  1,  3,  1,  3,  1,  2,  1,  3,  1,  2,  1
		.BYTE   1,  1,  3,  1,  2,  1,  3,  1,  2,  1,  3,  1,$BF,  0,$A1,$8D
		.BYTE $B0,  2,$FF
_mus46:
		.BYTE   0,  3,  0,  0,$A3,$20,$24,  1,$BA,  2,$1F,  3,$FD,$FE,$23,  1
		.BYTE $B0,  0,$FF
_mus47:
		.BYTE   0,  0,$16,  0, $A,  1,$B0,  2,$FF
_mus48:
		.BYTE   5,  0,$1F,  0,$C1,  1,  6,  1,  1,  1,$FF
_mus49:
		.BYTE   0,  5,  0,  0,$67,  1,$FF
_mus4A_un:
		.BYTE   0,  2,$1F,  0,$C9,  2,$50,  3,$FF
_mus4B:
		.BYTE   1,  5,  0,  0,$19,  8,$AE,$80,$19, $B,$1F,$30,$B0,  2,$FF
_mus4C:
		.BYTE   2,  0,$10,  0,$DF,  3,  2,  1,$FD,$FE,  3,  1,$B8,  0,$EF,  6
		.BYTE   3,  1,  4,  2,$EF,$FE,$A0,$13,$1F,  2,$FD,$FE,  1,  1,$B5,  0
		.BYTE $A0,$10,$1F,  5,$B0,  2,$FF
_mus4D:
		.BYTE   6,  0,$12,  0,$DA,  3,$FD,$FE,  3,  1,$B0,  0,$FF
_mus4E:
		.BYTE   2,  0,$12,  0,$FD,$FE,  5,  1,$B0,  0,$FF
_mus4F:
		.BYTE   0,  2,$18,  0,$C9,$10,$18,  5,$20,$10,$FF
_mus50:
		.BYTE   0,  0,$1F,$84,$A3,$10,$AE,$80,$C9,$10,$31,  5,$A2,  2,$20,$10
		.BYTE $FF
_mus51:
		.BYTE   0,$7F,  0,  0,$30,  5,$30,  3,$FF
_mus52:
		.BYTE   0,  0,  9,  0, $E,  2, $A,  3,  8,  8,$FF
_mus53:
		.BYTE   0,  0,$1A,$A4,$1F,$10,$4A,  6,$FF
_mus54:
		.BYTE   0,  0,$1A,$A4,$1F, $C,$4B,  6,$FF
_mus55:
		.BYTE   0,$20,  0,  0,$23,  5,$FF
_mus56:
		.BYTE   0,  0,$1F,  0,$1F,  3,  5,  2,$EF,  3,$FD,$FE,  5,  1,$B0,  0
		.BYTE $FF
_mus57:
		.BYTE   0,  2,$1F,  0,$C5,  1,$A3,$21,$69,  1,$1F,$12,$A1,$8A,$40,  3
		.BYTE $1F,$F0,$FF
_mus58:
		.BYTE   0,$7F,  0,  0,$1F,  3,$4A,  3,$FF
_mus59:
		.BYTE   0,  0,$1F,  0,$DF,  3, $A,  1,  9,  1,  8,  1,  6,  1,  5,  1
		.BYTE   4,  1,  3,  1,  1,  1,$1F, $E, $A,  2, $F,  2,  9,  2,$FF
_mus5A:
		.BYTE   0,  0,$12,  0,$DF,  3,$56,$20,$A1,$A5,$56,$30,$FF
_mus5B:
		.BYTE   0,  0,$10,  0,$AE,$80,$DF,  3,$54,$20,$A1,$A5,$54,$30,$FF
_mus5C:
		.BYTE   0,  0,$12,  0,$DF,  7,$FD,$FE,  3,  1,  3,  1,  3,  1,  3,  1
		.BYTE   3,  1,$BF,  0,$FF
_mus5D:
		.BYTE   1,  0,$1F,$82,$50,  2,$B0,  2,$FF
_mus5E:
		.BYTE   1,  3,  0,  0,$23,  2,$B0,  2,$FF
_mus5F:
		.BYTE   1,  0,  0,  0,  9,  2,$B0,  2,$FF
_mus60:
		.BYTE   1,  0,$15,  0,$DF,  3,  3,  2,  4,  2,  5,  2,  6,  2, $A,  2
		.BYTE  $E,  2, $F,  2, $E,  3,$A0,$1F,$EF,  5,$FD,$FE,  9,  1,$B0,  0
		.BYTE $FF
_mus61_un:
		.BYTE   0,  0,$12,  0,$DF,  3,$56,$20,$A1,$A5,$56,$30,$FF
_mus62_un:
		.BYTE   0,  0,$10,  0,$AE,$80,$DF,  3,$54,$20,$A1,$A5,$54,$30,$FF
_mus63_un:
		.BYTE   0,  0,$12,  0,$DF,  7,$FD,$FE,  3,  1,  3,  1,  3,  1,  3,  1
		.BYTE   3,  1,$BF,  0,$A0,  2, $B,  3,  9,  5,  8,  1,  7,$20, $E,  3
		.BYTE $EF,  8,$FD,$FE,  5,  1,  7,  1,  8,  1,  7,  1,$BF,  0, $B,  2
		.BYTE  $E,  5, $B,$10,$FF
_mus64:
		.BYTE   1,  0,  0,  0,  9,  2,  5,  1,$FF
_mus65_un:
		.BYTE   0,  0,  0,  0,$FF
_mus66:
		.BYTE   0,  0,$1F,$84,$A3,$10,$41,$50,$FF
_mus67:
		.BYTE   0,  0,$1B,$DE,$AE,$80,$3B, $D,$40, $D,$41, $D,$42, $D,$43, $D
		.BYTE $44, $D,$FF
_mus68:
		.BYTE   0,  3,  0,  0,$FD,$FE,$23,  2,$23,  2,$23,  2,$23,  2,$BA,  0
		.BYTE $FF
_mus69:
		.BYTE   0,  0,  9,  0,  3,  1,  3,  1,  3,  1,  3,  1,  3,  1,$BB,  2
		.BYTE $1F,  9,  5,  2,  8,  2,$1F,  1,$FD,$FE, $B,  8,$B3,  0, $B,$A1
		.BYTE $2F,$FE,$EF,$48,$FF
_mus6A:
		.BYTE   0,  1,  0,  0,$1F,$A0,$FD,$FE,$20,  1,$B0,  0,$FF
_mus6B:
		.BYTE   0,  0,$10,  0,$DF,$10,$C2,  3,$FD,$FE,  7,  5, $A,  5,$B0,  0
		.BYTE $FF
_mus6C:
		.BYTE   0,  0,$1F,$9B,$10,$30,$A3,$20,$FD,$FE,$30,$50,$B0,  0,$FF
_mus6D:
		.BYTE   0,  0,$1F,$9B,$AE,$80,$10,$30,$A3,$20,$FD,$FE,$41,$50,$B0,  0
		.BYTE $FF
_mus6E:
		.BYTE   0,  2,  0,  0,$FD,$FE,$23,  1,$23,  1,$23,  1,$23,  1,$23,  1
		.BYTE $22,  1,$24,  1,$23,  1,$B0,  0,$FF
_mus6F:
		.BYTE   0,  0,$1F,  0, $E,  2, $F,  2, $A,  2,  5,  2,  6,  2,  8,  2
		.BYTE   9,  2, $A,  2,$B3,  2,$FD,$FE, $A,  1,$B0,  0,$FF
_mus70_un:
		.BYTE   5,  0,$1A,  0,$C5,  3,$14,  1,$15,  1,$16,  2,$15,  2,$1F,  1 ;	-unused-
		.BYTE $14,  1,$1F,  2,$14,  1,$15,  1,$16,  1,$17,  1,$18,  2,$B0,  2
		.BYTE $FF
_mus71_un:
		.BYTE   5,  3,$1A,$84,$C5,  1,$A3,$20,$FD,$FE,$56,  1,$56,  1,$1F,  1 ;	-unused-
		.BYTE $56,  1,$56,  1,$56,  1,$56,  1,$56,  1,$B0,  2,$FF
_mus72_un:
		.BYTE   5,  6,  0,  0,$FD,$FE,$20,  1,$22,  1,$23,  2,$22,  3,$20,  1 ;	-unused-
		.BYTE $1F,  2,$20,  1,$22,  1,$23,  1,$24,  1,$25,  2,$B0,  0,$FF
_mus73:
		.BYTE   1,  0,$1A,$84,$A3,$10,$1F,$80,$31,$10,$FF
_mus74:
		.BYTE   1,  0,$18,$84,$AE,$80,$A3,$10,$1F,$80,$30,  8,$31,  8,$32,  8
		.BYTE $FF
_mus75:
		.BYTE   0,  2,  0,  0,$1F,$50,$FD,$FE,$23,  1,$BF,  0,$B9,  3,$FF
_mus76:
		.BYTE   0,  0,$10,  0,$DF,$10,$FD,$FE, $E,  2, $C,  1,$BF,  0,$B3,  3
		.BYTE  $E,  2, $C,  1, $E,  3, $C,  2, $E,  4, $C,  3, $E,  5, $C,  4
		.BYTE  $E,  6, $C,  5, $E,  7, $C,  6, $E,  8, $C,  7, $E,  9,$FF
_mus77:
		.BYTE   0,  0,$12,  0,$DF,  3,$56,$20,$A1,  5,$56,$30,$A1,  6,$FD,$FE
		.BYTE $4A,$F0,$B0,  0,$FF
_mus78:
		.BYTE   0,  0,$10,  0,$AE,$80,$DF,  3,$54,$20,$A1,$A5,$54,$30,$A1,  0
		.BYTE $FD,$FE,$49,$F0,$B0,  0,$FF
_mus79:
		.BYTE   0,  0,$12,  0,$DF,  7,$FD,$FE,  3,  1,  3,  1,  3,  1,  3,  1
		.BYTE   3,  1,$BF,  0,$FD,$FE,$A0,$15,$DF,  5,  3, $A,$A0,$15,$B0,  0
		.BYTE $FF
_mus7A:
		.BYTE   1,  0,$1F,  0, $E,  2,  9,  1,  6,  1,  8,  3, $E,  1,  8,  1
		.BYTE   3,  1,  9,  1,  3,  1,$FF
_mus7B:
		.BYTE   0,  6,$1F,  0,  9,  1, $A,  1, $E,  1, $F,  2, $A,  3, $C,  2
		.BYTE  $E,  1, $F,  3, $E,  2, $F,  2, $A,  1,$1F,$10, $E,  2, $F,  2
		.BYTE  $A,  2,  9,  2,  7,  1,$EF,  6,$FD,$FE,  9,  1,$B0,  0,$FF
_mus7C:
		.BYTE   0,  0,$1F,$8D,  1,  5,  2, $A,$A1,$A5,$FD,$FE,  6,$17,$B7,  0
		.BYTE $EF,  6,$A1,$8E,  2,$30,  3,$30,$FF
_mus7D:
		.BYTE   0,  0,$1F,$8D,$AE,$80,  1,  5,  2, $A,$A1,$A5,$FD,$FE,  6,$17
		.BYTE $B7,  0,$EF,  6,$A1,$8E,  1,$30,  2,$30,$FF
_mus7E:
		.BYTE   0,$30,$1F,  0,$23,  5,$24, $A,$A1,$95,$FD,$FE,$A2,  1,$23,  1
		.BYTE $23,  1,$23,  1,$23,  1,$23,  1,$23,  1,$23,  1,$23,  1,$23,  1
		.BYTE $23,  1,$23,  1,$23,  1,$23,  1,$BF,  0,$FF
_mus7F:
		.BYTE   0,  0,$1F,  0,$C9,$20, $E,  5,  9, $A,$FD,$FE, $E,$17,$B7,  0
		.BYTE $EF,  6,$FD,$FE,  9,  1,$B0,  0,$FF
_mus80:
		.BYTE   0,  3,$1F,  0,$C1,$30,$42,  2,$EF,  3,$42,$20,$FF
_mus81:
		.BYTE   0,  3,$1A,  0,$AE,$80,$C1,$30,$1F,  2,$36,  2,$EF,  3,$36,$30
		.BYTE $FF
_mus82:
		.BYTE   1,  0,$1F,$94,$A3,$20,$30,  2,$33,  2,$36,  6,$FF
_mus83:
		.BYTE   1,  0,$1F,  0,$A3,$20,$40,  2,$43,  2,$46,  6,$FF
_mus84:
		.BYTE   1,$10,  0,  0,$A3,$20,$23,  2,$26,  2,$29,  6,$FF
_mus85:
		.BYTE   1,  0,$1F,  0,  7,  2,  7,  2,  5,  6,$FF
_mus86:
		.BYTE   0,  0,$1F,  0,$EF,  3,$C1,$40,$46,  2,$53,$30,$FF
_mus87:
		.BYTE   0,  0,$1F,$9D,$AE,$80,$EF,  2,$A3,$20,$53,  2,$53,$30,$FF
_mus88:
		.BYTE   0,  0,$1F,  0,  9,  2, $A,  1, $C,  2, $B,  2,$FD,$FE, $D,  1
		.BYTE $B0,  0,$FF
_mus89:
		.BYTE   0,  0,$1F,  0,$FD,$FE, $E,  1,$B0,  0,$FF
_mus8A:
		.BYTE   0,  0,$1F,  0, $F,  1, $D,  1, $B,  1, $E,  1,  9,  1,  8,  1
		.BYTE   7,  3,$FF
_mus8B:
		.BYTE   0,  0,$1F,  0,  7,  1,  8,  1,  9,  1, $A,  1, $E,  2, $F,  2
		.BYTE  $E,  2, $A,  1,  9,  2,  8,  2,  6,  1,  5,  1,  4,  1,  3,  1
		.BYTE $EF,  5,$FD,$FE, $A,  1,$B0,  0,$FF
_mus8C_un:
		.BYTE   0,  0,$1F,  0,  5,  2,$1F,  2,$EF,  2,$FD,$FE,  6,  1,$B0,  0 ;	-unused-
		.BYTE $FF
_mus8D:
		.BYTE   0,  0,$1F,$8D,  5,  2,  7,  7,$A1,$95,  6,  5,$B1,  2,$1F,$10
		.BYTE $B0,  2,$FF
_mus8E:
		.BYTE   0,  0,$1F,$8D,$AE,$80,  4,  2,  5,  7,$A1,$95,  3,  5,$B1,  2
		.BYTE $1F, $A,$B0,  2,$FF
_mus8F:
		.BYTE   0,  3,  0,  0,$FD,$FE,$23,  1,$B0,  0,$FF
_mus90:
		.BYTE   0,  0,$18,  0,$FD,$FE, $E,  1,$B0,  0,$FF
_mus91:
		.BYTE   4,  0,$1F,  0,$EF,  5,$C9,  2,$FD,$FE,$54,  1,$4B,  1,$50,  1
		.BYTE $49,  1,$52,  1,$45,  1,$47,  1,$44,  1,$B0,  0,$FF
_mus92:
		.BYTE   5,  0,$1F,  0,$1F,  2,$C9,  2,$EF,  5,$FD,$FE,$54,  1,$4B,  1
		.BYTE $50,  1,$49,  1,$52,  1,$45,  1,$47,  1,$44,  1,$B0,  0,$FF
_mus93:
		.BYTE   8,  0,$1F,  0,$EF, $A,$FD,$FE,  4,  2,  4,  2,  4,  2,  4,  2
		.BYTE   4,  2,$BF,  0,$EF,  5,$FD,$FE,  3,  2,  2,  2,  2,  2,  2,  2
		.BYTE   2,  2,$BF,  0,$A0,$10,$B0,  2,$FF
_mus94_un:
		.BYTE   0,  0,$1F,  0, $E,  2,  9,  2, $A,  2, $F,  2,$1F,$10,$EF,  3 ;	-unused-
		.BYTE $FD,$FE,  9,  1,$B0,  0,$FF
_mus95_un:
		.BYTE   0,  0,$1F,  0,$4B,  3,$A3,$10,$FD,$FE,$46,  1,$B0,  0,$FF
_mus96_un:
		.BYTE   0,  0,$1F,  0,$AE,$80,$4B,  3,$A3,$10,$FD,$FE,$51,  1,$B0,  0 ;	-unused-
		.BYTE $FF
_mus97_un:
		.BYTE   0,  0,$17,  0, $E,  1, $F,  1, $C,  1, $A,  1,  9,  1,$FD,$FE ;	-unused-
		.BYTE   7,  1,$B0,  0,$FF
_mus98:
		.BYTE   9,  0,$1E,  0,$C9,$30,$A3,$21,$45,  1,$57,  1,$50,  1,$59,  1
		.BYTE $55,  1,$B0,  2,$FF
_mus99:
		.BYTE   9,  2,$1F,  0,$C2,  2,$A3,$21,$FD,$FE,$37,  1,$40,  1,$A1,$9E
		.BYTE $40,  1,$A1,  0,$42,$10,$1F,  5,$47,  1,$42,$14,$A1,$A5,$42,  1
		.BYTE $A1,  0,$40,  3,$1F,  3,$50,  4,$47,  7,$1F,  1,$45,  1,$47,  3
		.BYTE $45,  1,$47,  3,$45,  1,$47,  3,$45,  1,$47, $A,$1F, $A,$1F,  1
		.BYTE $32,  1,$39,  1,$47,$10,$1F,  5,$50,  1,$4B,  8,$47,$10,$50,  1
		.BYTE $4B,  8,$45,  1,$44, $A,$40,  7,$42,  7,$1F,$10,$B0,  2,$FF
_mus9A:
		.BYTE   9,$7F,  0,  0,$FD,$FE,$27,  1,$27,  1,$B7,  0,$FD,$FE,$30,  1
		.BYTE $30,  1,$B7,  0,$FD,$FE,$22,  1,$22,  1,$22,  1,$B7,  0,$B0,  2
		.BYTE $FF
_mus9B_un:
		.BYTE   6,  0,$1F,  0,$C9,  2, $E,  1,  3,  1,  9,  2, $E,  1,  3,  1 ;	-unused-
		.BYTE  $B,  2,  3,  1, $E,  2, $E,  2, $E,  1,  9,  2,$B0,  2,$FF
_mus9C:
		.BYTE   9,  0,$1F,  0,$FD,$FE,$C2,  9,  5,  4,$C1,$30,  9,  4,$AF,  1
		.BYTE $C5,  3,$EF,  2,$FD,$FE,  6,  1,  5,  1,$BF,  0,$AF,  9,$A0,$1F
		.BYTE $B0,  2,$FF
_mus9D:
		.BYTE   4,  0,$10,  0,$DF,  3,$C9,  5,$45,  2,$47,  2,$AE,$80,$50,  4
		.BYTE $AE,  0,$45,  2,$47,  2,$1F,  2,$45,  2,$45,  2,$47,  2,$AE,$80
		.BYTE $50,  2,$AE,  0,$43,  2,$B0,  2,$FF
_mus9E:
		.BYTE   4,  0,$10,  0,$FD,$FE,$A3,$10,$C5,  8,$AE,$80,$4A,  2,$43,  2
		.BYTE $1F,  2,$43,  4,$43,  2,$1F,  2,$B0,  0,$FF
_mus9F:
		.BYTE   4,$10,  0,  0,$1F,$20,$FD,$FE,$23,  2,$67,  2,$1F,  2,$23,  2
		.BYTE $BB,  0,$FD,$FE,$27,  2,$27,  2,$67,  2,$26,  2,$B7,  0,$FD,$FE
		.BYTE $23,  2,$23,  2,$67,  2,$23,  2,$B7,  0,$B0,  9,$23,  4,$23,  4
		.BYTE $26,  4,$23,  4,$B5,  0,$B0,  3,$FF
_musA0:
		.BYTE   4,  0,$10,  0,$DF,  5,$C9,  2,  9,  2,  3,  2,  9,  2,  3,  2
		.BYTE   9,  2,  3,  2,  9,  2,  3,  2,  9,  2,  3,  2,  9,  2,  3,  2
		.BYTE   9,  2,  9,  2, $A,  2,  9,  2,$B2,  2,$C1,$10,$B0,  4,$FF
_musA1_un:
		.BYTE   4,  2,$1F,$AD,$FD,$FE,$1F,$10,$B1,  0,$C5,  1,$A3,$20,$FD,$FE ;	-unused-
		.BYTE $27,  2,$27,  2,$27,  2,$2A,  2,$27,  2,$27,  2,$30,  2,$24,  2
		.BYTE $B7,  0,$FD,$FE,$2B,  2,$2B,  2,$2B,  2,$33,  2,$2B,  2,$2B,  2
		.BYTE $34,  2,$2A,  2,$B6,  0,$C1,$50,$A1,$AD,$A3,$10,$A0,$1A,$FD,$FE
		.BYTE $25,  2,$27,  2,$30, $C,$34,  8,$30,  8,$2A,  2,$32,  2,$30, $C
		.BYTE $2A,  8,$29,  8,$29,  2,$2A,  2,$30,  4,$25,  8,$24,  2,$25,  2
		.BYTE $27,  4,$30,  8,$B1,  0,$FD,$FE,$33,  4,$1F,  4,$33,  4,$1F,  4
		.BYTE $33,  2,$33,  2,$1F,  4,$38,  4,$1F,  4,$38,  4,$1F,  4,$38,  2
		.BYTE $38,  2,$1F,  4,$41,  4,$1F,  4,$41,  4,$1F,  4,$41,  2,$41,  2
		.BYTE $1F,  4,$45,  4,$1F,  4,$45,  4,$1F,  4,$45,  2,$45,  2,$1F,  4
		.BYTE $45,  4,$1F,  4,$45,  4,$1F,  4,$45,  2,$45,  2,$1F,  4,$C0,$FE
		.BYTE $47,$10,$47,$10,$47,$10,$47,$10,$47,$10,$47,  2,$FF
_musA2_un:
		.BYTE   4,  3,$1F,$91,$A3,$20,$1F,$50,$C9,  8,$FD,$FE,$35,  2,$37,  2 ;	-unused-
		.BYTE $40, $C,$44,  8,$40,  8,$3A,  2,$42,  2,$40, $C,$3A,  8,$39,  8
		.BYTE $39,  2,$3A,  2,$40,  4,$35,  8,$34,  2,$35,  2,$37,  4,$40,  8
		.BYTE $B3,  0,$FD,$FE,$A1,$AD,$2A,  4,$1F,  4,$2A,  4,$1F,  4,$2A,  2
		.BYTE $2A,  2,$1F,  4,$B7,  0,$49,  2,$FF
_musA3:
		.BYTE   4, $A,  0,  0,$FD,$FE,$1F,  6,$23,  2,$26,  2,$27,  2,$67,  2
		.BYTE $22,  2,$B0,  0,$FF
_musA4:
		.BYTE   4,  0,$1F,  0,$C1, $A,$FD,$FE,  9,  2,  3,  2,  3,  2,  8,  2
		.BYTE   3,  2,  3,  2,$C1,$20,  8,  2,$C1, $A,  3,  2,$B0,  0,$FF
_musA5_un:
		.BYTE   3,  2,$10,$AD,$DF,  7,$FD,$FE,$C9,  2,$A3,$20,$37,  2,$3B,  2
		.BYTE $40,  2,$37,  2,$44,  4,$37,  2,$3B,  2,$40,  2,$35,  2,$40,  2
		.BYTE $3B,  2,$BF,  0,$B1,  2,$D0,$FE,$EF,$20,$FD,$FE,$A3,$20,$37,  2
		.BYTE $3B,  2,$40,  2,$37,  2,$44,  4,$37,  2,$3B,  2,$40,  2,$35,  2
		.BYTE $40,  2,$3B,  2,$B0,  0,$FF
_musA6_un:
		.BYTE   3,  0,$17,  0,$A3,$10,$FD,$FE,$A0,$17,$1F, $C,$B6,  0,$C1,$A0
		.BYTE $FD,$FE,$17,$18,$20,$18,$25,$18,$2B,$18,$30,$18,$34,$18,$36,$18
		.BYTE $39,$18,$37,$18,$40,$18,$42,$18,$45,$18,$A0,$1F,$FD,$FE,$34,  2
		.BYTE $35,  6,$34,  2,$35,  6,$34,  2,$35,  6,$44,  2,$1F,  2,$44,  2
		.BYTE $1F,  2,$1F,  2,$44,  2,$1F,  2,$1F,  2,$42,  4,$B3,  0,$B1,  7
		.BYTE $FD,$FE,$EF,  7,$34,  2,$35,  6,$34,  2,$35,  6,$34,  2,$35,  6
		.BYTE $44,  2,$1F,  2,$44,  2,$1F,  2,$1F,  2,$44,  2,$1F,  4,$42,  4
		.BYTE $B0,  0,$FF
_musA7_un:
		.BYTE   3,$20,  0,  0,$FD,$FE,$1F, $C,$B5,  0,$FD,$FE,$24,  2,$25,  6
		.BYTE $24,  2,$25,  6,$24,  2,$25,  2,$20,  4,$24,  2,$25,  6,$24,  2
		.BYTE $25,  2,$20,  4,$20,  4,$23,  4,$B2,  0,$FD,$FE,$27,  2,$67,  2
		.BYTE $27,  2,$67,  2,$27,  2,$27,  2,$1F,  2,$27,  2,$69,  2,$27,  2
		.BYTE $B3,  0,$FD,$FE,$25,  2,$67,  2,$25,  2,$67,  2,$25,  2,$25,  2
		.BYTE $1F,  2,$25,  2,$69,  2,$25,  2,$B3,  0,$B4,$15,$FF
_musA8_un:
		.BYTE   3,  0,$10,  0,$C1,$10,$DF,  7,$B3,  2,$FD,$FE,  9,  2,  3,  2
		.BYTE   1,  2, $E,  2,  3,  2,  3,  2,  7,  2, $E,  2,  9,  2, $F,  2
		.BYTE $BF,  0,$B2,  5,$EF,$10,$FD,$FE,  9,  2,  3,  2,  1,  2, $E,  2
		.BYTE   3,  2,  3,  2,  7,  2, $F,  2,  9,  2, $F,  2,$B0,  0,$FF
_musA9:
		.BYTE   6,  2,$10,  0,$DF,  7,$C9,  2,$A3,$21,$FD,$FE,$36,  1,$36,  1
		.BYTE $BF,  0,$AE,$80,$FD,$FE,$39,  1,$39,  1,$BF,  0,$AE,$FE,$B0,  3
		.BYTE $FF
_musAA:
		.BYTE   6,  0,$10,  0,$DF,  7,$FD,$FE,$C9,  2,$A3,$20,$FD,$FE,$AE,$80
		.BYTE $1F,  1,$46,  1,$1F,  1,$46,  1,$B7,  0,$AE,$FE,$FD,$FE,$1F,  1
		.BYTE $49,  1,$1F,  1,$49,  1,$B7,  0,$B0,  3,$FF
_musAB:
		.BYTE   0,  0,  0,  0,$FF
_musAC:
		.BYTE   6,  0,$1F,  0,$C9,  2,$FD,$FE,  7,  1,  3,  1,  7,  1,  3,  1
		.BYTE  $A,  1, $A,  1, $A,  1,  3,  1,  7,  1,  3,  1,  7,  1,  3,  1
		.BYTE  $A,  2, $A,  1,  3,  1,$B0,  0,$FF
_musAD_un:
		.BYTE   5,  3,$1F,  0,$C2,  2,$A3,$20,$FD,$FE,$36,  8,$36,  8,$1F,  4
		.BYTE $36,  2,$36,  8,$1F,  6,$36,  8,$36,  8,$1F,  4,$36,  8,$1F,  2
		.BYTE $36,  8,$36,  8,$B0,  2,$FF
_musAE_un:
		.BYTE   5,  0,$1F,  0,$AE,$80,$C2,  2,$A3,$20,$FD,$FE,$3A,  8,$3A,  8
		.BYTE $1F,  4,$3A,  2,$3A,  8,$1F,  6,$41,  8,$41,  8,$1F,  4,$3A,  8
		.BYTE $1F,  2,$3A,  8,$41,  8,$B0,  2,$FF
_musAF_un:
		.BYTE   5,$7F,  0,  0,$AE,$80,$A3,$20,$FD,$FE,$4A,  8,$4A,  8,$1F,  4
		.BYTE $4A,  2,$4A,  8,$1F,  6,$51,  8,$51,  8,$1F,  4,$4A,  8,$1F,  2
		.BYTE $48,  8,$51,  8,$B0,  2,$FF
_musB0_un:
		.BYTE   5,  0,$1F,  0,$C1,$30,$A3,$20,$FD,$FE,  8,  8,  8,  8,$1F,  4
		.BYTE   8,  2,  8,  8,$1F,  6,  8,  8,  8,  8,$1F,  4,  8,  8,$1F,  2
		.BYTE   8,  8,  8,  8,$B0,  2,$FF
_musB1:
		.BYTE  $A,  0,$1F,  0,$C2,  2,$A3,$21,$FD,$FE,$40,  1,$41,  1,$47,  1
		.BYTE $42,  1,$40,  1,$42,  1,$40,  1,$44,  1,$40,  1,$42,  1,$B0,  0
		.BYTE $FF
_musB2:
		.BYTE  $A,  0,$1F,  0,$C2,  2,$A3,$20,$FD,$FE,$27,  1,$29,  1,$30,  1
		.BYTE $30,  1,$27,  1,$27,  1,$29,  1,$30,  1,$27,  1,$29,  1,$B0,  0
		.BYTE $FF
_musB3:
		.BYTE   9,$7F,  0,  0,$FD,$FE,$A3,$20,$39,  1,$39,  1,$BA,  0,$FD,$FE
		.BYTE $35,  1,$35,  1,$BA,  0,$FD,$FE,$39,  1,$39,  1,$BA,  0,$FD,$FE
		.BYTE $3A,  1,$3A,  1,$BA,  0,$B0,  2,$FF
_musB4:
		.BYTE   1,  0,$1D,  0,$EF,$30,$FD,$FE,  9,  1,$B0,  0,$FF
_musB5_un:
		.BYTE   4,  0,$10,$AD,$DF,  7,$C9,  7,$FD,$FE,$A3,$10,$35,  2,$40,  2
		.BYTE $37,  4,$35,  2,$40,  2,$37,  2,$35,  2,$33,  2,$35,  2,$BF,  0
		.BYTE $C1,$50,$FD,$FE,$27,  2,$2A,  6,$30,  2,$33,  2,$31,  4,$25,  2
		.BYTE $28,  4,$27,  2,$31,  2,$30,  6,$B0,  0,$FF
_musB6_un:
		.BYTE   4,  0,$10,$92,$A3,$20,$DF,  7,$FD,$FE,$20,  1,$20,  1,$20,  1
		.BYTE $20,  1,$20,  1,$20,  1,$20,  1,$20,  1,$20,  1,$BF,  0,$FD,$FE
		.BYTE $1F,  4,$46,  2,$47,  2,$B8,  0,$FD,$FE,$46,  2,$47,  2,$51,  2
		.BYTE $52,  2,$B6,  0,$1F,$30,$FD,$FE,$46,  2,$47,  2,$51,  2,$52,  2
		.BYTE $56,  4,$B0,  0,$FF
_musB7_un:
		.BYTE   4,$20,  0,  0,$1F,$14,$B1,  2,$FD,$FE,$23,  2,$67,  1,$67,  1
		.BYTE $23,  2,$69,  2,$B8,  0,$FD,$FE,$27,  2,$67,  1,$67,  1,$27,  2
		.BYTE $69,  2,$B8,  0,$B1,  4,$FD,$FE,$23,  4,$26,  4,$23,  4,$23,  4
		.BYTE $26,  4,$23,  4,$B0,  0,$FF
_musB8_un:
		.BYTE   4,  0,$10,  0,$C1,$20,$DF,  7,$FD,$FE, $E,  2, $E,  2,  9,  4
		.BYTE  $E,  2,  7,  4, $E,  4, $E,  2,$B7,  2,$FD,$FE,$C1,$30, $E,  2
		.BYTE   3,  2,  8,  4,$B2,  0,$FD,$FE,$AF,  2,  6,  2,  8,  4, $A,  4
		.BYTE  $F,  3, $E,  7,  5,  7,$B3,  0,$AF,  4,$FD,$FE,  5,  2,  6,  2
		.BYTE   9,  2, $A,  2,  6,  2,$B2,  0,$C9,  5,$FD,$FE,  7,  1,  9,  1
		.BYTE $B6,  0,$FD,$FE,$C1,$20, $E,  1,  8,  1,  8,  1, $F,  1, $E,  1
		.BYTE   8,  1,  8,  1, $F,  1, $E,  1,  8,  1,  8,  1, $F,  1, $E,  1
		.BYTE   8,  1,  8,  1, $E,  1,$B0,  0,$FF
_musB9_un:
		.BYTE   0,  0,$1F,$8D,$A3,$20,$EF,$20,$FD,$FE,  2,  1,$B0,  0,$FF
_musBA_un:
		.BYTE   0,  0,$1F,$8D,$EF,$20,$FD,$FE,  1,  8,  5,  8,$A1,$95,  6,  5
		.BYTE $A1,  0,$FD,$FE,  3,  1,  3,  1,  2,  1,  3,  1,  3,  1,  2,  1
		.BYTE   3,  1,  2,  1,  1,  1,  3,  1,  2,  1,  3,  1,  2,  1,  3,  1
		.BYTE $BF,  0,$A1,$8D,$B0,  3,$FF
_musBB_un:
		.BYTE   0,  3,  0,  0,$A3,$20,$24,  1,$BA,  2,$1F,  3,$FD,$FE,$23,  1
		.BYTE $23,  1,$23,  1,$23,  1,$23,  1,$23,  1,$23,  1,$BF,  0,$B1,  6
		.BYTE $FF
_musBC_un:
		.BYTE   0,  0,$16,  0,$EF,$20,$FD,$FE, $A,  1,$B0,  0,$FF
_musBD_un:
		.BYTE   0,  0,$1F,  0, $E,  3, $D,  3, $C,  3, $C,  3, $B,  3, $A,  3 ;	-unused-
		.BYTE   9,  3,  8,  3,  8,  3,  7,  3,  6,  3,  5,  3,  4,  3,  2,  2
		.BYTE   1,  1, $C,  1, $E,  1,$FD,$FE, $E,$10,$B0,  0,$FF
_musBE:
		.BYTE   5,  0,$1F,  0,$C9,  1,$A3,$21,$40,  2,$42,  2,$37,  2,$32,  2
		.BYTE $B0,  2,$FF
_musBF:
		.BYTE   5,  0,$16,  0,$C2,$10,$1F,  1,$50,  2,$52,  2,$47,  2,$B0,  2
_musC0:
		.BYTE   5,$30,  0,  0,$A3,$21,$FD,$FE,$27, $C,$27,  4,$29,  8,$2B,  8
		.BYTE $22,$10,$1F, $C,$22,  4,$B1,  0,$27, $C,$27,  4,$29,  8,$2B,  8
		.BYTE $2A,$10,$30,$10,$27,$10,$27,$10,$27,$10,$27,$10,$B0,  2,$FF
_musC1:
		.BYTE   5,  0,$1F,  0,$C9,  2,$FD,$FE,$1F,  4,  3,  2,  2,  2,$1F,  4
		.BYTE   3,  2,  2,  2,$1F,  4,  3,  4,  9,  4, $E,  2, $E,  2,$B0,  0
		.BYTE $FF
_musC2:
		.BYTE   0,  0,$1F,$84,$A3,$10,$41,$50,$FF
_musC3:
		.BYTE   0,  0,$1B,$DE,$AE,$80,$3B, $D,$40, $D,$41, $D,$42, $D,$43, $D
		.BYTE $44, $D,$FF
_musC4:
		.BYTE   0,  3,  0,  0,$FD,$FE,$23,  2,$23,  2,$23,  2,$BA,  0,$FF
_musC5:
		.BYTE   0,  0,  9,  0,  3,  1,  3,  1,  3,  1,  3,  1,  3,  1, $B,  2
		.BYTE $FF
_musC6:
		.BYTE   3,  0,  0,  0, $F,  2,$FF
_musC7:
		.BYTE   3,  0,  0,  0, $D,  2,$FF
_musC8:
		.BYTE   3,  0,  0,  0, $E,  2,$FF
_musC9:
		.BYTE   3,  0,  0,  0, $B,  2,$FF
_musCA_un:
		.BYTE   0,  0,  3,  0, $C,  2, $A,  2,  9,  2,  4,  2,  3,  2,  4,  2 ;	-unused-
		.BYTE   3,  2,  1,  2,  3,  2,  4,  2,  1,  2,  3,  2,  1,  2,  3,  2
		.BYTE   2,  2,  3,  2,  1,  2,  1,  2,  1,  2,  1,  2,  3,  2,  1,  2
		.BYTE   2,  2,  1,  2,  3,  2,  2,  2,  1,  2,  2,  2,  3,  2,  2,  1
		.BYTE   2,  2,  3,  2,  3,  1,$FF
_musCB:
		.BYTE   0,  0,  1,  0, $E,  1, $F,  1, $A,  1,  9,  1, $F,  1,$A0,$1F
		.BYTE $EF,  1,$FD,$FE,  7,  1,$B0,  0,$FF
_musCC:
		.BYTE   1,  3,$10,$84,$DF,$20,$C9,  2,$A3,$10,  9,  1,$1F,  7,  9,  3
		.BYTE $1F,$38,$B0,  2,$FF
_musCD:
		.BYTE   0,  0,$1E,  0,$DF,  2,  9,  1,$A0,$17,$DF,  2,  9,  1, $E,  1
		.BYTE $A0,$1F,$FD,$FE,  8,  1,$B2,  0,$A0,$1F,  4,  3,$A0,$1C,$B0,  2
		.BYTE $FF
_musCE:
		.BYTE   1,  1,$10,  0,$AE,$80,$A3,$11,$DF,  5,$FD,$FE,$C2,  8,$37,  8
		.BYTE $3B,  8,$B0,  0,$FF
_musCF:
		.BYTE   1,  3,$10,  0,$DF,  5,$FD,$FE,$C2,  8,$37,  8,$3B,  8,$B0,  0
		.BYTE $FF
_musD0:
		.BYTE   6,  0,$1F,  0,$C2,  3,$A3,$21,$FD,$FE,$1F,  3,$39,  1,$1F,  2
		.BYTE $1F,  2,$39,  1,$1F,  3,$39,  3,$1F,  2,$39,  1,$1F,  6,$B3,  0
		.BYTE $1F,  3,$42,  1,$1F,  2,$1F,  2,$42,  1,$1F,  3,$42,  3,$1F,  2
		.BYTE $42,  1,$1F,  6,$1F,  3,$39,  1,$1F,  2,$1F,  2,$39,  1,$1F,  3
		.BYTE $39,  3,$1F,  2,$39,  1,$1F,  6,$FD,$FE,$47,  2,$46,  1,$44,  2
		.BYTE $41,  3,$39,  1,$41,  2,$44,  1,$47,  2,$46,  1,$44,  2,$41,  3
		.BYTE $39,  1,$41,  2,$44,  1,$47,  2,$46,  1,$44,  2,$41,  1,$44,  3
		.BYTE $41,  2,$44, $D,$B1,  0,$48,  2,$48,  1,$48,  2,$48,  1,$48,  2
		.BYTE $48,  1,$47,  2,$48,  1,$46,  2,$46,  1,$46,  2,$46,  1,$46,  2
		.BYTE $46,  1,$45,  2,$46,  1,$44,  2,$44,  1,$44,  2,$44,  1,$44,  3
		.BYTE $46,  2,$47, $D,$B0,  2,$FF
_musD1:
		.BYTE   6,  0,$1F,  0,$A3,$21,$C2,  3,$FD,$FE,$1F,  3,$34,  1,$1F,  2
		.BYTE $1F,  2,$34,  1,$1F,  3,$34,  3,$1F,  2,$34,  1,$1F,  6,$B3,  0
		.BYTE $1F,  3,$39,  1,$1F,  2,$1F,  2,$39,  1,$1F,  3,$39,  3,$1F,  2
		.BYTE $39,  1,$1F,  6,$1F,  3,$34,  1,$1F,  2,$1F,  2,$34,  1,$1F,  3
		.BYTE $34,  3,$1F,  2,$34,  1,$1F,  6,$B0,  2,$FF
_musD2:
		.BYTE   6,$20,  0,  0,$FD,$FE,$29,  3,$31,  3,$34,  3,$36,  3,$37,  2
		.BYTE $37,  1,$36,  3,$34,  3,$31,  3,$B1,  0,$22,  3,$26,  3,$29,  3
		.BYTE $2B,  3,$30,  2,$30,  1,$2B,  3,$29,  3,$26,  3,$29,  3,$31,  3
		.BYTE $34,  3,$36,  3,$37,  3,$36,  3,$34,  3,$31,  3,$24,  3,$28,  3
		.BYTE $2B,  3,$31,  3,$22,  3,$26,  3,$29,  3,$2B,  3,$29,  3,$29,  3
		.BYTE $29,  3,$29,  3,$29,  3,$26,  3,$27,  3,$28,  3,$B0,  2,$FF
_musD3:
		.BYTE   6,  0,$1F,  0,$C9,  2,$FD,$FE,  3,  3,  3,  1,$1F,  1,  3,  1
		.BYTE $B0,  0,$FF

		BANK_END C,$C000
