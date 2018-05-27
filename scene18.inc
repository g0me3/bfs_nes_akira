
		SECTION_START 18

;-----------------------------------------------
; SCENE 18 (ENDING)
;-----------------------------------------------

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene18_subs_ending:
		JSR		_ending_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_9AF8
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s18_sub00_ending
		SW_PTR	_s18_sub01_clear
		SW_PTR	_s18_sub03_staff_lines_init
		SW_PTR	_s18_sub04_staff_lines_draw
		SW_PTR	_s18_sub05_staff_tlm_draw
		SW_PTR	_s18_sub06_delay
		SW_PTR	_ending08
		SW_PTR	_ending09
		SW_PTR	_ending0A
		SW_PTR	_fade_out_reload_scene

locret_9AF8:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s18_sub00_ending:
		JSR		_apu_reset
		JSR		_snd_ending
		JSR		_scroll_reset
		SW_NXT	_s18_sub01_clear
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s18_sub01_clear:
		SW_NXT	_s18_sub03_staff_lines_init
		JMP		_msg_wnd_clear_request

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s18_sub03_staff_lines_init:
		INC		_staff_scr_line_idx				; increment lines counter
		SW_NXT	_s18_sub04_staff_lines_draw
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s18_sub04_staff_lines_draw:
;		LDA		_staff_scr_line_idx
;		BEQ		loc_9B52
		LDX		#3								; special case, screens A and C has 3 lines
		LDA		_staff_screen_idx				; the rest has 2 lines
		CMP		#$A
		BEQ		loc_9C79
		CMP		#$C
		BEQ		loc_9C79
		LDX		#2
loc_9C79:
		CPX		_staff_scr_line_idx				; test for end of lines for current screen
		BCS		loc_9C84
		LDA		#0
		STA		_staff_scr_line_idx				; reinit lines counter
		SW_NXT	_s18_sub05_staff_tlm_draw		; let's start in here instead of missing one frame
		RTS
loc_9C84:
		JSR		_staff_line_draw
		INC		_staff_scr_line_idx
		RTS
;loc_9B52:
;		SW_NXT	_s18_sub05_staff_tlm_draw
;		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s18_sub05_staff_tlm_draw:
		LDA		_bad_ending_flag				; a bad ending has no slideshow
		BNE		.no_tlm_draw
		LDA		#1
		STA		_forbid_ending_overlays_flag
		SW_NXT	_s18_sub06_delay				; delay if a picture is drawn
		JMP		_staff_tlm_draw
.no_tlm_draw:
		SW_NXT	_ending08						; only the staff is displayed on
		LDA		#$20							; the last displayed screen
		JMP		_delay

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s18_sub06_delay:
		SW_FADE	_ending08
		LDA		#$20
		JMP		_delay

;-------------S-U-B-R-O-U-T-I-N-E---------------
_ending08:
		LDA		_staff_screen_idx
		CMP		#$C
		BEQ		loc_9B9C
		INC		_staff_screen_idx
		SW_NXT	_s18_sub01_clear
		RTS
loc_9B9C:
		SW_NXT	_ending09
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_ending09:
		SW_NXT	_ending0A
		LDA		#$C0
		JMP		_delay

;-------------S-U-B-R-O-U-T-I-N-E---------------
_ending0A:
		LDA		#0
		STA		_forbid_ending_overlays_flag
		LDA		#1
		STA		_main_sub_idx
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_ending_spr_overlay_set:
		LDA		_forbid_ending_overlays_flag
		BEQ		locret_9C05
		LDA		_bad_ending_flag
		BNE		loc_9BFD
		LDA		#1
		STA		_scene_anim_idx
		STA		_scene_anim_idx+1
		STA		_scene_anim_idx+2
		STA		_scene_anim_idx+3
		LDA		_staff_screen_idx
		SWITCH
		EXOFS	_s0_spr_overlay2
		SW_PTR	_nullsub
		EXOFS	_s5_spr_overlay1
		EXOFS	_s6_spr_overlay4				; defined in system bank
		SW_PTR	_nullsub
		SW_PTR	_s18_sC_spr_overlay2
		EXOFS	_sF_spr_overlay5
		SW_PTR	_nullsub
		EXOFS	_s15_spr_overlay6
		SW_PTR	_nullsub
		SW_PTR	_nullsub
		SW_PTR	_nullsub
		SW_PTR	_nullsub

loc_9BFD:
		LDA		_keep_tetsuo_overlay_for_ending_flag
		BEQ		locret_9C05						; endings D/E has tetsuo sprite, just keep it here
		FJSR	_s16_spr_overlayA				; 1 time, already have RTS here, sweet.
locret_9C05:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s0_spr_overlay2				; 1 time here as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s5_spr_overlay1				; 1 time here as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s15_spr_overlay6				; 1 time here as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s18_sC_spr_overlay2:
		LDA		#1
		STA		_sgame_enemy_active_flag
		LDA		#3
		STA		_scene_anim_idx+1
		LDA		#$30
		STA		_sgame_enemy_y_pos
		LDA		#$90
		STA		_sgame_enemy_x_pos
		FJMP	_sC_spr_overlay2				; 1 time here

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_sF_spr_overlay5				; 1 time here as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_staff_tlm_draw:
		LDA		_staff_screen_idx
		SWITCH
		EXOFS	_s0_tlm00_draw
		EXOFS	_s0_tlm01_draw
		EXOFS	_s5_tlm1E_draw
		EXOFS	_s6_tlmA1_draw					; defined in system bank
		EXOFS	_s7_tlm25_draw
		EXOFS	_sC_tlm35_draw
		EXOFS	_sF_tlm45_draw
		EXOFS	_s11_tlm4E_draw
		EXOFS	_s15_tlm72_draw
		EXOFS	_s15_tlm7A_draw					; defined in system bank
		EXOFS	_s15_tlm9F_draw
		EXOFS	_s16_tlm85_draw
		EXOFS	_s16_tlm93_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s0_tlm00_draw					; 1 time here as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s0_tlm01_draw					; 1 time here as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s5_tlm1E_draw					; 1 time b0 as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_sC_tlm35_draw					; 1 time b0 as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s7_tlm25_draw					; 1 time b0 as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s11_tlm4E_draw					; 1 time b0 as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_sF_tlm45_draw					; 1 time b0 as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s15_tlm72_draw					; 1 time b0 as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s15_tlm9F_draw					; 1 time b0 as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s16_tlm85_draw					; 1 time b0 as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s16_tlm93_draw					; 1 time b0 as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_staff_line_draw:
		LDA		_staff_screen_idx
		ASL
		TAX
		LDA		off_9CD4,X
		STA		word_0
		LDA		off_9CD4+1,X
		STA		word_0+1
		LDX		_staff_scr_line_idx
		DEX
		TXA
		ASL
		TAY
		LDA		(word_0),Y
		STA		word_2
		INY
		LDA		(word_0),Y
		STA		word_2+1
		LDY		#0
		LDA		(word_2),Y
		STA		_tlm_tmp_line_dst
		INY
		LDA		(word_2),Y
		AND		#$FB
		STA		_tlm_tmp_line_dst+1
		INY
		LDA		(word_2),Y
		STA		_nmi_ppu_tlm_draw_len
		INY
		LDX		#0
loc_9CC2:
		LDA		(word_2),Y
		STA		_ppu_tmp_row_buf,X
		INY
		INX
		CPX		_nmi_ppu_tlm_draw_len
		BCC		loc_9CC2
		LDA		#2
		STA		_nmi_ppu_tlm_draw_req
		RTS
off_9CD4:
		.WORD _staff_screen0
		.WORD _staff_screen1
		.WORD _staff_screen2
		.WORD _staff_screen3
		.WORD _staff_screen4
		.WORD _staff_screen5
		.WORD _staff_screen6
		.WORD _staff_screen7
		.WORD _staff_screen8
		.WORD _staff_screen9
		.WORD _staff_screenA
		.WORD _staff_screenB
		.WORD _staff_screenC
_staff_screen0:
		.WORD _staff_scr0_line0
		.WORD _staff_scr0_line1
_staff_screen1:
		.WORD _staff_scr1_line0
		.WORD _staff_scr1_line1
_staff_screen2:
		.WORD _staff_scr2_line0
		.WORD _staff_scr2_line1
_staff_screen3:
		.WORD _staff_scr3_line0
		.WORD _staff_scr3_line1
_staff_screen4:
		.WORD _staff_scr4_line0
		.WORD _staff_scr4_line1
_staff_screen5:
		.WORD _staff_scr5_line0
		.WORD _staff_scr5_line1
_staff_screen6:
		.WORD _staff_scr6_line0
		.WORD _staff_scr6_line1
_staff_screen7:
		.WORD _staff_scr7_line0
		.WORD _staff_scr7_line1
_staff_screen8:
		.WORD _staff_scr8_line0
		.WORD _staff_scr8_line1
_staff_screen9:
		.WORD _staff_scr9_line0
		.WORD _staff_scr9_line1
_staff_screenA:
		.WORD _staff_scrA_line0
		.WORD _staff_scrA_line1
		.WORD _staff_scrA_line2
_staff_screenB:
		.WORD _staff_scrB_line0
		.WORD _staff_scrB_line1
_staff_screenC:
		.WORD _staff_scrC_line0
		.WORD _staff_scrC_line1
		.WORD _staff_scrC_line2

_LINE0		EQU	$2660
_LINE1		EQU	$26A0
_LINE2		EQU	$26E0
_LINE3		EQU	$2720

		MAC	ENDS
{1}	SET	.
		.WORD	[{2}+[[32-{1}_size]/2]]
		.BYTE	{1}_size
{1}_start SET .
		ENDM

		MAC ENDE
{1}_end	SET	.
{1}_size SET [{1}_end-{1}_start]
		ENDM

#if LANGUAGE == RU_LANG
;-----------------------------------------------
		ENDS	_staff_scr0_line0, _LINE0
		.BYTE _R,_E,_ZH,_I,_S,_S,_E,_R,__,_I,__,_S,_C,_E,_N,_A,_R,_I,_S,_T,
		ENDE	_staff_scr0_line0
		ENDS	_staff_scr0_line1, _LINE2
		.BYTE _K,_A,_C,_U,_H,_I,_R,_O,__,_O,_O,_T,_O,_M,_O
		ENDE	_staff_scr0_line1

		ENDS	_staff_scr1_line0, _LINE0
		.BYTE _P,_R,_O,_D,_A,_K,_SH,_N,__,_M,_E,_N,_E,_D,_ZH,_E,_R
		ENDE	_staff_scr1_line0
		ENDS	_staff_scr1_line1, _LINE2
		.BYTE _T,_I,_L,_T,__,_K,_A,_T,_O
		ENDE	_staff_scr1_line1

		ENDS	_staff_scr2_line0, _LINE0
		.BYTE _R,_E,_D,_A,_K,_T,_O,_R,__,_R,_U,_K,_O,_V,_O,_D,_I,_T,_E,_L,_MZ
		ENDE	_staff_scr2_line0
		ENDS	_staff_scr2_line1, _LINE2
		.BYTE _K,_O,_O,_K,_I,__,_3,_7,_5
		ENDE	_staff_scr2_line1

		ENDS	_staff_scr3_line0, _LINE0
		.BYTE _P,_O,_M,_O,_SCH,_N,_I,_K,__,_R,_E,_ZH,_I,_S,_S,_E,_R,_A
		ENDE	_staff_scr3_line0
		ENDS	_staff_scr3_line1, _LINE2
		.BYTE _JU,_K,_I,_str,_T,_JA,_N
		ENDE	_staff_scr3_line1

		ENDS	_staff_scr4_line0, _LINE0
		.BYTE _S,_P,_E,_C,_JE,_F,_F,_E,_K,_T,_JI
		ENDE	_staff_scr4_line0
		ENDS	_staff_scr4_line1, _LINE2
		.BYTE _S,_P,_E,_J,_S,__,_P,_A,_T,_R,_U,_L,_MZ,__,_S,_I,_G,_E,_M,_A
		ENDE	_staff_scr4_line1

		ENDS	_staff_scr5_line0, _LINE0
		.BYTE _A,_R,_T,__,_D,_I,_R,_E,_K,_T,_O,_R
		ENDE	_staff_scr5_line0
		ENDS	_staff_scr5_line1, _LINE2
		.BYTE _SH,_I,_N,__,_B,_U,_N,_I,_N
		ENDE	_staff_scr5_line1

		ENDS	_staff_scr6_line0, _LINE0
		.BYTE _G,_L,_A,_V,_N,_JI,_J,__,_O,_P,_E,_R,_A,_T,_O,_R
		ENDE	_staff_scr6_line0
		ENDS	_staff_scr6_line1, _LINE2
		.BYTE _K,_O,_M,_O,_CH,_I,_str,_O,_O,_K,_A,_M,_I
		ENDE	_staff_scr6_line1

		ENDS	_staff_scr7_line0, _LINE0
		.BYTE _M,_U,_Z,_JI,_K,_A,_L,_MZ,_N,_JI,_J,__,_R,_U,_K,_O,_V,_O,_D,_I,_T,_E,_L,_MZ
		ENDE	_staff_scr7_line0
		ENDS	_staff_scr7_line1, _LINE2
		.BYTE _T,_O,_SH,_I,_K,_O,__,_K,_A,_V,_A,_N,_I,_SH,_I
		ENDE	_staff_scr7_line1

		ENDS	_staff_scr8_line0, _LINE0
		.BYTE _D,_I,_Z,_A,_J,_N,_E,_R,__,_K,_O,_S,_T,_JU,_M,_O,_V
		ENDE	_staff_scr8_line0
		ENDS	_staff_scr8_line1, _LINE2
		.BYTE _K,_O,_M,_P,_MZ,_JU,_T,_E,_R,_str,_A,_T,_O,_M
		ENDE	_staff_scr8_line1

		ENDS	_staff_scr9_line0, _LINE0
		.BYTE _G,_L,_A,_V,_N,_JI,_J,__,_G,_R,_I,_M,_E,_R
		ENDE	_staff_scr9_line0
		ENDS	_staff_scr9_line1, _LINE2
		.BYTE _J,_O,_T,_JA,_N
		ENDE	_staff_scr9_line1

		ENDS	_staff_scrA_line0, _LINE0
		.BYTE _O,_S,_O,_B,_O,_E,__,_S,_P,_A,_S,_I,_B,_O
		ENDE	_staff_scrA_line0
		ENDS	_staff_scrA_line1, _LINE2
		.BYTE _K,_O,_D,_A,_N,_S,_JA
		ENDE	_staff_scrA_line1
		ENDS	_staff_scrA_line2, _LINE3
		.BYTE _ZH,_U,_R,_N,_A,_L,__,_JU,_N,_G
		ENDE	_staff_scrA_line2

		ENDS	_staff_scrB_line0, _LINE0
		.BYTE _M,_R,_dot,__,_JU,_O,_D,_O
		ENDE	_staff_scrB_line0
		ENDS	_staff_scrB_line1, _LINE2
		.BYTE _M,_R,_dot,__,_M,_I,_Z,_U,_O,__,_I,__,_M,_R,_dot,__,_JU,_R,_I
		ENDE	_staff_scrB_line1

		ENDS	_staff_scrC_line0, _LINE0
		.BYTE _A,_K,_I,_R,_A
		ENDE	_staff_scrC_line0
		ENDS	_staff_scrC_line1, _LINE1
		.BYTE _D,_dot,_N,_dot,_K,_dot
		ENDE	_staff_scrC_line1
		ENDS	_staff_scrC_line2, _LINE2
		.BYTE _R,_E,_I,_N,_K,_A,_R,_N,_A,_C,_I,_JA
		ENDE	_staff_scrC_line2
;-----------------------------------------------
#else
;-----------------------------------------------
		ENDS	_staff_scr0_line0, _LINE0
		.BYTE _D,_I,_R,_E,_C,_T,_E,_D,_col,__,_W,_R,_I,_T,_T,_E,_N,__,_B,_Y
		ENDE	_staff_scr0_line0
		ENDS	_staff_scr0_line1, _LINE2
		.BYTE _K,_A,_T,_S,_U,_H,_I,_R,_O,__,_O,_H,_T,_O,_M,_O
		ENDE	_staff_scr0_line1

		ENDS	_staff_scr1_line0, _LINE0
		.BYTE _P,_R,_O,_D,_U,_C,_T,_I,_O,_N,__,_M,_A,_N,_A,_G,_E,_R
		ENDE	_staff_scr1_line0
		ENDS	_staff_scr1_line1, _LINE2
		.BYTE _T,_I,_L,_T,__,_K,_A,_T,_O
		ENDE	_staff_scr1_line1

		ENDS	_staff_scr2_line0, _LINE0
		.BYTE _S,_U,_P,_E,_R,_V,_I,_S,_I,_N,_G,__,_E,_D,_I,_T,_O,_R
		ENDE	_staff_scr2_line0
		ENDS	_staff_scr2_line1, _LINE2
		.BYTE _K,_O,_H,_K,_I,__,_3,_7,_5
		ENDE	_staff_scr2_line1

		ENDS	_staff_scr3_line0, _LINE0
		.BYTE _A,_S,_S,_I,_S,_T,_A,_N,_T,__,_D,_I,_R,_E,_C,_T,_O,_R
		ENDE	_staff_scr3_line0
		ENDS	_staff_scr3_line1, _LINE2
		.BYTE _Y,_U,_K,_I,_E,_str,_C,_H,_A,_N
		ENDE	_staff_scr3_line1

		ENDS	_staff_scr4_line0, _LINE0
		.BYTE _S,_P,_E,_C,_I,_A,_L,__,_E,_F,_F,_E,_C,_T,_S
		ENDE	_staff_scr4_line0
		ENDS	_staff_scr4_line1, _LINE2
		.BYTE _S,_P,_A,_C,_E,__,_P,_A,_T,_R,_O,_L,__,_S,_H,_I,_G,_E,_M,_A
		ENDE	_staff_scr4_line1

		ENDS	_staff_scr5_line0, _LINE0
		.BYTE _A,_R,_T,__,_D,_I,_R,_E,_C,_T,_O,_R
		ENDE	_staff_scr5_line0
		ENDS	_staff_scr5_line1, _LINE2
		.BYTE _S,_H,_I,_N,__,_B,_U,_N,_J,_I,_N
		ENDE	_staff_scr5_line1

		ENDS	_staff_scr6_line0, _LINE0
		.BYTE _D,_I,_R,_E,_C,_T,_O,_R,__,_O,_F,__,_P,_H,_O,_T,_O,_G,_R,_A,_P,_H,_Y
		ENDE	_staff_scr6_line0
		ENDS	_staff_scr6_line1, _LINE2
		.BYTE _K,_O,_M,_O,_C,_H,_I,_str,_O,_H,_K,_A,_M,_I
		ENDE	_staff_scr6_line1

		ENDS	_staff_scr7_line0, _LINE0
		.BYTE _M,_U,_S,_I,_C,__,_S,_U,_P,_E,_R,_V,_I,_S,_O,_R
		ENDE	_staff_scr7_line0
		ENDS	_staff_scr7_line1, _LINE2
		.BYTE _T,_O,_S,_H,_I,_K,_O,__,_K,_A,_W,_A,_N,_I,_S,_H,_I
		ENDE	_staff_scr7_line1

		ENDS	_staff_scr8_line0, _LINE0
		.BYTE _C,_O,_S,_T,_U,_M,_E,__,_D,_E,_S,_I,_G,_N,_E,_R
		ENDE	_staff_scr8_line0
		ENDS	_staff_scr8_line1, _LINE2
		.BYTE _C,_O,_M,_P,_U,_T,_E,_R,_str,_A,_T,_O,_M
		ENDE	_staff_scr8_line1

		ENDS	_staff_scr9_line0, _LINE0
		.BYTE _M,_A,_K,_E,_str,_U,_P,__,_S,_U,_P,_E,_R,_V,_I,_S,_O,_R
		ENDE	_staff_scr9_line0
		ENDS	_staff_scr9_line1, _LINE2
		.BYTE _Y,_O,_C,_C,_H,_A,_N
		ENDE	_staff_scr9_line1

		ENDS	_staff_scrA_line0, _LINE0
		.BYTE _S,_P,_E,_C,_I,_A,_L,__,_T,_H,_A,_N,_K,_S
		ENDE	_staff_scrA_line0
		ENDS	_staff_scrA_line1, _LINE2
		.BYTE _K,_O,_H,_D,_A,_N,_str,_S,_Y,_A
		ENDE	_staff_scrA_line1
		ENDS	_staff_scrA_line2, _LINE3
		.BYTE _Y,_O,_U,_N,_G,__,_M,_A,_G,_A,_Z,_I,_N,_E
		ENDE	_staff_scrA_line2

		ENDS	_staff_scrB_line0, _LINE0
		.BYTE _M,_R,_col,__,_H,_Y,_O,_D,_O
		ENDE	_staff_scrB_line0
		ENDS	_staff_scrB_line1, _LINE2
		.BYTE _M,_R,_col,__,_M,_I,_Z,_U,_O,__,_A,_N,_D,__,_M,_R,_col,__,_Y,_U,_R,_I
		ENDE	_staff_scrB_line1

		ENDS	_staff_scrC_line0, _LINE0
		.BYTE _A,_K,_I,_R,_A
		ENDE	_staff_scrC_line0
		ENDS	_staff_scrC_line1, _LINE1
		.BYTE _D,_dot,_N,_dot,_A
		ENDE	_staff_scrC_line1
		ENDS	_staff_scrC_line2, _LINE2
		.BYTE _R,_E,_I,_N,_C,_A,_R,_N,_A,_T,_I,_O,_N
		ENDE	_staff_scrC_line2
;-----------------------------------------------
#endif

		SECTION_END 18
