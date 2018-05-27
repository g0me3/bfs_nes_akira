
		SECTION_START 0

;-----------------------------------------------
; SCENE 0 (INTRO)
;-----------------------------------------------

; no interactive events

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene0_subs:
		JSR		_s0_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_803C
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s0_sub00_clear_screen
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_s0_sub1B_chr_pal_setup
		SW_PTR	_s0_sub01_intro_type
		SW_PTR	_s0_sub02_fade_out
		SW_PTR	_s0_sub02_tlm00_draw
		SW_PTR	_s0_sub04_snd_msg
		SW_PTR	_s0_sub1C_fade_out
		SW_PTR	_s0_sub05_tlm01_draw
		SW_PTR	_s0_sub06_delay_fade_out
		SW_PTR	_s0_sub08_tlm11_draw
		SW_PTR	_s0_sub09_snd_tlm10_draw
		SW_PTR	_s0_sub0A_scroll
		SW_PTR	_s0_sub1D_msg_fade_out
		SW_PTR	_s0_sub0B_snd_stop_clear_screen
		SW_PTR	_s0_sub0C_icon14
		SW_PTR	_s0_sub0D_msg_fade_out
		SW_PTR	_s0_sub0E_icon15
		SW_PTR	_s0_sub0F_msg_fade_out
		SW_PTR	_s0_sub10_snd_icon16
		SW_PTR	_s0_sub11_msg_fade_out
		SW_PTR	_s0_sub12_icon17
		SW_PTR	_s0_sub13_msg_fade_out
		SW_PTR	_s0_sub14_icon_clear
		SW_PTR	_s0_sub15_icon18
		SW_PTR	_s0_sub16_msg_fade_out
		SW_PTR	_s0_sub17_icon19
		SW_PTR	_s0_sub18_msg_fade_out
;		SW_PTR	_s0_sub19_clear_screen

locret_803C:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub00_clear_screen:
		SW_NXT	_s0_sub1B_chr_pal_setup
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub1B_chr_pal_setup:
		SW_NXT	_s0_sub01_intro_type
		LDA		#0
		STA		_scene_sub_idx_pass				; once we start a new game, we clear pass backup
		STA		_cur_msg_row
		STA		_cur_msg_col
		CHRPAL	$17,0
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub01_intro_type:
		LDA		_frames_counter
		AND		#7
		BNE		locret_80D5
loc_808B:
		LDA		_cur_msg_row
		ASL
		TAX
		LDA		off_80E4,X
		STA		word_0
		LDA		off_80E4+1,X
		STA		word_0+1
		LDY		_cur_msg_col
		LDA		(word_0),Y
		CMP		#_eol
		BEQ		loc_80D6
		CMP		#_ret
		BNE		loc_80AE
		INC		_cur_msg_row
		LDA		#0
		STA		_cur_msg_col
		BEQ		loc_808B
loc_80AE:
#if LANGUAGE == JP_LANG
;-----------------------------------------------
		STA		_char_extra_tile
		LDA		#0
;-----------------------------------------------
#endif
		STA		_char_main_tile
		JSR		_snd_char_type
		LDA		_cur_msg_row
		ASL
		TAX
		LDA		word_80E0,X
		CLC
		ADC		_cur_msg_col
		STA		_cur_msg_char_ppu_ofs
		LDA		word_80E0+1,X
		ADC		#0
		STA		_cur_msg_char_ppu_ofs+1
		LDA		#1
		STA		_cur_msg_pos_increment
		INC		_cur_msg_col
locret_80D5:
		RTS
loc_80D6:
		SW_NXT	_s0_sub02_fade_out
		LDA		#$10
		JMP		_delay

word_80E0:
		.WORD $20C4
		.WORD $2106
off_80E4:
		.WORD byte_80E8
		.WORD byte_8101
#if LANGUAGE == RU_LANG
;-----------------------------------------------
byte_80E8:
		.BYTE _3,_1,__,_G,_O,_D,__,_P,_O,_S,_L,_E,__,_III,_str,_E,_J,__,_M,_I,_R,_O,_V,_O,_J,_ret
byte_8101:
		.BYTE _2,_0,_1,_9,_dot,_8,_dot,_1,_8,_dot,__,_N,_E,_O,_str,_T,_O,_K,_I,_O,_eol
;-----------------------------------------------
#else
;-----------------------------------------------
byte_80E8:
		.BYTE _3,_1,__,_Y,_E,_A,_R,_S,__,_A,_F,_T,_E,_R,__,_W,_O,_R,_L,_D,__,_W,_A,_R,_III,_ret
byte_8101:
		.BYTE _2,_0,_1,_9,_dot,_8,_dot,_1,_8,_dot,__,_N,_E,_O,__,_T,_O,_K,_Y,_O,_eol
#endif

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub02_fade_out:
		SW_FADE	_s0_sub02_tlm00_draw
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub02_tlm00_draw:
		SW_NXT	_s0_sub04_snd_msg
		LDA		#2
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_tlm00_draw:
		TLM5	$68,$69,0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub04_snd_msg:
		JSR		_snd_bike_ride
		SW_NXT	_s0_sub1C_fade_out
		MSG_M
		MSG		_sc0_msgB8
		MSG		_sc0_msg26
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub1C_fade_out:
		SW_FADE	_s0_sub05_tlm01_draw
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub05_tlm01_draw:
		SW_NXT	_s0_sub06_delay_fade_out
		LDA		#0
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_tlm01_draw:
		TLM5	$69,1,1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub06_delay_fade_out:
		SW_FADE	_s0_sub08_tlm11_draw
		LDA		#$10
		JMP		_delay

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub08_tlm11_draw:
		SW_NXT	_s0_sub09_snd_tlm10_draw
		LDA		#0
		STA		byte_345
		LDA		#$11
		JMP		_tlm_nt1_draw_mode4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub09_snd_tlm10_draw:
		JSR		_snd_bike_crash_explode
		SW_NXT	_s0_sub0A_scroll
		LDA		#1
		STA		_scroll_x_shadow+1
		TLM4	$E,$D,$10

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub0A_scroll:
		LDA		#$12
		JSR		_tlm_get_index_by_number
		JSR		_s0_sub0A_scroll_spr_overlay
		LDA		_scroll_x_shadow
		ORA		_scroll_x_shadow+1
		BEQ		loc_86A9
		LDA		_scroll_x_shadow
		SEC
		SBC		#4
		STA		_scroll_x_shadow
		LDA		_scroll_x_shadow+1
		SBC		#0
		STA		_scroll_x_shadow+1
		LDA		_scroll_x_shadow
		AND		#7
		BNE		locret_86A8
		LDA		#7
		STA		_nmi_ppu_tlm_draw_req
		LDA		_scroll_x_shadow
		LSR
		LSR
		LSR
		CLC
		ADC		#$40
		STA		byte_324
		LDA		#$24
		STA		byte_324+1
		RTS
loc_86A9:
		SW_NXT	_s0_sub1D_msg_fade_out
		SW_CUR	_s0_sub1D_msg_fade_out
		LDA		#7
		STA		_nmi_ppu_tlm_draw_req
		LDA		#1
		STA		_scroll_x_shadow+1
locret_86A8:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub0A_scroll_spr_overlay:
		SPR0	_spr_sc0_tetsuo_bike,$30,$90
		LDA		_frames_counter
		AND		#4
		BEQ		loc_846F
		SPR0J	_spr_sc0_tetsuo_bike_tire0,$30,$90
loc_846F:
		SPR0J	_spr_sc0_tetsuo_bike_tire1,$30,$90

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub1D_msg_fade_out:
		SW_FADE	_s0_sub0B_snd_stop_clear_screen
		MSG_M
		MSG		_sc0_msg01
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub0B_snd_stop_clear_screen:
		JSR		_apu_reset
		SW_NXT	_s0_sub0C_icon14
		JSR		_scroll_reset
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub0C_icon14:
		SW_NXT	_s0_sub0D_msg_fade_out
		LDA		#1
		STA		_scene_spr_overlay_idx
		STA		_scene_anim_idx+2				; init tetsuo overlay, boy is already 0
		ICON1	0,0,$14

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub0D_msg_fade_out:
		SW_FADE	_s0_sub0E_icon15
		MSG_M
		MSG		_sc0_msg02
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub0E_icon15:
		SW_NXT	_s0_sub0F_msg_fade_out
		LDA		#2
		STA		_scene_anim_idx+2
		LDA		#1
		STA		_scene_anim_idx+3
		ICON0	0,0,$15

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub0F_msg_fade_out:
		SW_FADE	_s0_sub10_snd_icon16
		MSG_M
		MSG		_sc0_msg03
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub10_snd_icon16:
		JSR		_snd_helicopter
		SW_NXT	_s0_sub11_msg_fade_out
		LDA		#3
		STA		_scene_anim_idx+2
		LDA		#2
		STA		_scene_anim_idx+3
		ICON2	0,0,$16

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub11_msg_fade_out:
		SW_FADE	_s0_sub12_icon17
		MSG_M
		MSG		_sc0_msg04
		MSG		_sc0_msg19
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub12_icon17:
		SW_NXT	_s0_sub13_msg_fade_out
		LDA		#3
		STA		_scene_spr_overlay_idx
		ICON2	1,$2A,$17

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub13_msg_fade_out:
		SW_FADE	_s0_sub14_icon_clear
		MSG_M
		MSG		_sc0_msg05
		MSG		_sc0_msg2E
		MSG_WAIT
		MSG_EOL

-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub14_icon_clear:
		SW_NXT	_s0_sub15_icon18				; FF is special index for clearing the
		LDA		#0								; particular icon picture
		STA		_scene_anim_idx+2				; disable overlay for a frame as well
		ICON1_CLEAR

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub15_icon18:
		SW_NXT	_s0_sub16_msg_fade_out
		LDA		#4
		STA		_scene_spr_overlay_idx
		ICON0	1,$2C,$18

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub16_msg_fade_out:
		SW_FADE	_s0_sub17_icon19
		MSG_M
		MSG		_sc0_msg06
		MSG		_sc0_msg07
		MSG		_sc0_msg06
		MSG		_sc0_msg08
		MSG		_sc0_msg30
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub17_icon19:
		SW_NXT	_s0_sub18_msg_fade_out
		LDA		#5
		STA		_scene_spr_overlay_idx
		ICON0	1,$2D,$19

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_sub18_msg_fade_out:
		SW_FADE	_next_scene						;	_s0_sub19_clear_screen
		MSG_M
		MSG		_sc0_msg2F
		MSG		_sc0_msg09
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
;_s0_sub19_clear_screen:
;		SW_NXT	_next_scene						; this is only place where the message wondow
;		JMP		_msg_wnd_clear_request			; cleared before the next scene, remove it or
												; make all others clear the screen too?

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s0_spr_overlay1
		SW_PTR	_s0_spr_overlay2
		SW_PTR	_s0_spr_overlay3
		SW_PTR	_s0_spr_overlay4
		SW_PTR	_s0_spr_overlay5

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_spr_overlay1:
		LDA		_scene_anim_idx+2				; indexes 0-3 used
		SPR0SW	off_83A4,$40,$60
		LDA		_scene_anim_idx+3
		SPR0JSW	off_83BE,$10,$10
off_83A4:
		.WORD _spr_dummy
		.WORD _spr_sc0_kaneda_head_down
		.WORD _spr_sc0_kaneda_head_left
		.WORD _spr_sc0_kaneda_head_right
off_83BE:
		.WORD _spr_dummy
		.WORD _spr_sc0_kid_eyes_forth
		.WORD _spr_sc0_kid_eyes_right

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_spr_overlay2:
		JSR		_pal_blink_animate
		SPR0	_spr_sc0_tetsuo_face,$40,$68
		SPR0	_spr_sc0_tetsuo_hoody,$30,$90
		LDA		_frames_counter
		LSR
		LSR
		AND		#1
		SPR0JSW	off_8442,$20,$68
off_8442:
		.WORD _spr_sc0_tetsuo_hair0
		.WORD _spr_sc0_tetsuo_hair1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_spr_overlay3:
		JSR		_s0_spr_overlay1
		JMP		_s0_spr_overlay4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_spr_overlay4:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0JSW	off_83DC,$10,$B0
off_83DC:
		.WORD _spr_sc0_colonel_mouth0			; swapped, mouth is closed by default now
		.WORD _spr_sc0_colonel_mouth1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s0_spr_overlay5:
		JSR		_s0_spr_overlay4
		JSR		_do_scene_anim1_pat0101
		LDA		_scene_anim_idx+1
		SPR0JSW	off_83F9,$10,$10
off_83F9:
		.WORD _spr_sc0_kaneda_mouth0			; the same open mouths fix here
		.WORD _spr_sc0_kaneda_mouth1

_spr_sc0_tetsuo_hair0:
		.BYTE   0,$E2,  1,$10
		.BYTE   8,$E3,  1,  0
		.BYTE   8,$E4,  1,  8
		.BYTE $10,$E5,  1,  0
		.BYTE $10,$E6,  1,  8
		.BYTE $10,$E7,  1,$10
		.BYTE $10,$E8,  1,$18
		.BYTE $80
_spr_sc0_tetsuo_hair1:
		.BYTE   0,$E9,  1,$10
		.BYTE   8,$EA,  1,  0
		.BYTE   8,$EB,  1,  8
		.BYTE $10,$EC,  1,  0
		.BYTE $10,$ED,  1,  8
		.BYTE $10,$EE,  1,$10
		.BYTE $10,$EF,  1,$18
		.BYTE $80
_spr_sc0_tetsuo_face:
		.BYTE   0,$D7,  1,  0
		.BYTE   0,$D8,  1,  8
		.BYTE   0,$D9,  1,$10
		.BYTE   0,$DA,  1,$18
		.BYTE   8,$DB,  1,  0
		.BYTE   8,$DC,  1,  8
		.BYTE   8,$DD,  1,$10
		.BYTE   8,$DE,  1,$18
		.BYTE $10,$DF,  1,  8
		.BYTE $10,$E0,  1,$10
		.BYTE $10,$E1,  1,$18
		.BYTE $80
_spr_sc0_tetsuo_hoody:
		.BYTE   0,$F0,  2,  0
		.BYTE   0,$F1,  2,  8
		.BYTE   0,$F2,  2,$10
		.BYTE   8,$F3,  2,  0
		.BYTE   8,$F4,  2,  8
		.BYTE   8,$F5,  2,$10
		.BYTE   8,$F6,  2,$18
		.BYTE   8,$F7,  2,$20
		.BYTE $10,$F8,  2,$10
		.BYTE $10,$F9,  2,$18
		.BYTE $10,$FA,  2,$20
		.BYTE $80
_spr_sc0_kaneda_head_down:
		.BYTE   0,$D3,  2,$28
		.BYTE   8,$E0,  2,$10
		.BYTE   8,$E1,  2,$18
		.BYTE   8,$E2,  2,$20
		.BYTE   8,$E3,  2,$28
		.BYTE $10,$F1,  2,$18
		.BYTE $10,$F2,  2,$20
		.BYTE $10,$F3,  2,$28
		.BYTE $80
_spr_sc0_kaneda_head_left:
		.BYTE   0,$D4,  2,$10
		.BYTE   0,$D5,  2,$18
		.BYTE   0,$D7,  2,$28
		.BYTE   8,$E4,  2,$10
		.BYTE   8,$E5,  2,$18
		.BYTE   8,$E6,  2,$20
		.BYTE   8,$E7,  2,$28
		.BYTE $10,$F5,  2,$18
		.BYTE $10,$F6,  2,$20
		.BYTE $10,$F3,  2,$28
		.BYTE $80
_spr_sc0_kaneda_head_right:
		.BYTE   0,$D8,  2,$10
		.BYTE   0,$DB,  2,$28
		.BYTE   8,$E8,  2,$10
		.BYTE   8,$E9,  2,$18
		.BYTE   8,$EA,  2,$20
		.BYTE   8,$EB,  2,$28
		.BYTE $10,$F9,  2,$18
		.BYTE $10,$FA,  2,$20
		.BYTE $10,$FB,  2,$28
		.BYTE $80
_spr_sc0_kid_eyes_forth:
		.BYTE $28,$DC,  1,$10
		.BYTE $28,$DD,  1,$18
		.BYTE $28,$DE,  1,$20
		.BYTE $28,$DF,  1,$28
		.BYTE $30,$EC,  1,$10
		.BYTE $30,$ED,  1,$18
		.BYTE $30,$EE,  1,$20
		.BYTE $30,$EF,  1,$28
		.BYTE $80
_spr_sc0_kid_eyes_right:
		.BYTE $28,$DC,  1,$10
		.BYTE $28,$FC,  1,$18
		.BYTE $28,$FD,  1,$20
		.BYTE $28,$FE,  1,$28
		.BYTE $30,$EC,  1,$10
		.BYTE $30,$ED,  1,$18
		.BYTE $30,$EE,  1,$20
		.BYTE $30,$EF,  1,$28
		.BYTE $80
_spr_sc0_colonel_mouth1:
		.BYTE $10,$BF,  3,$10
		.BYTE $18,$C0,  3,  8
		.BYTE $18,$C1,  3,$10
		.BYTE $20,$C2,  3,  9
		.BYTE $20,$C6,  3,$10
		.BYTE $20,$C7,  3,$18
		.BYTE $28,$C8,  3,$10
		.BYTE $80
_spr_sc0_colonel_mouth0:
		.BYTE $10,$BF,  3,$10
		.BYTE $18,$C0,  3,  8
		.BYTE $18,$C1,  3,$10
		.BYTE $20,$C2,  3,  9
		.BYTE $20,$C3,  3,$10
		.BYTE $20,$C4,  3,$18
		.BYTE $28,$C5,  3,$10
		.BYTE $80
_spr_sc0_kaneda_mouth1:
		.BYTE $10,$BA,  2,$18
		.BYTE $10,$BB,  2,$20
		.BYTE $80
_spr_sc0_kaneda_mouth0:
		.BYTE $10,$BD,  2,$18
		.BYTE $10,$BE,  2,$20
		.BYTE $80
_spr_sc0_tetsuo_bike:
		.BYTE   0,$CB,  1,$18
		.BYTE   0,$CC,  1,$20
		.BYTE   8,$CD,  1,  8
		.BYTE   8,$CE,  1,$10
		.BYTE   8,$CF,  1,$18
		.BYTE   8,$D0,  1,$20
		.BYTE   8,$D1,  1,$28
		.BYTE $10,$D4,  2,$10
		.BYTE $10,$D5,  1,$18
		.BYTE $10,$D6,  1,$20
		.BYTE $10,$D7,  1,$28
		.BYTE $18,$DA,  1,  0
		.BYTE $18,$DB,  1,  8
		.BYTE $18,$DC,  1,$10
		.BYTE $18,$DD,  1,$18
		.BYTE $18,$DE,  1,$20
		.BYTE $18,$DF,  1,$28
		.BYTE $18,$E0,  1,$30
		.BYTE $18,$E1,  1,$38
		.BYTE $80
_spr_sc0_tetsuo_bike_tire1:
		.BYTE $10,$D2,  1,  0
		.BYTE $10,$D3,  1,  8
		.BYTE $10,$D8,  1,$30
		.BYTE $10,$D9,  1,$38
		.BYTE $80
_spr_sc0_tetsuo_bike_tire0:
		.BYTE $10,$C6,  1,  0
		.BYTE $10,$C7,  1,  8
		.BYTE $10,$C8,  1,$30
		.BYTE $10,$C9,  1,$38
		.BYTE $80

		SECTION_END	0
