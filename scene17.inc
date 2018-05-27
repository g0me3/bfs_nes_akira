
		SECTION_START 17

;-----------------------------------------------
; SCENE 17
;-----------------------------------------------

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene17_subs_game_over:
		JSR		_s17_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_B035F
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s17_sub00_pass_input_clear		; input pass entry branch
		SW_PTR	_s17_sub01_pass_input_chars_draw0
		SW_PTR	_s17_sub02_pass_input_miyako_draw
		SW_PTR	_s17_sub03_pass_input_miyako_msg
		SW_PTR	_s17_sub04_pass_input_kaneda_draw; retry point for wrong pass
		SW_PTR	_s17_sub05_pass_input_kaneda_msg
		SW_PTR	_s17_sub06_pass_input_loop
		SW_PTR	_s17_sub08_pass_input_ok_draw
		SW_PTR	_s17_sub09_pass_input_ok_msg
		SW_PTR	_s17_sub0A_pass_input_ok_decode
		SW_PTR	_s17_sub0B_pass_input_wrong_draw
		SW_PTR	_s17_sub0C_pass_input_wrong_msg

		SW_PTR	_s17_sub0E_game_over_prison
		SW_PTR	_s17_sub17_game_over_prison_draw
		SW_PTR	_s17_sub19_game_over_prison_msg
		SW_PTR	_s17_sub0F_game_over_dead
		SW_PTR	_s17_sub18_game_over_dead_draw
		SW_PTR	_s17_sub1A_game_over_dead_msg
		SW_PTR	_s17_sub1B_game_over_retry_msg
		SW_PTR	_s17_sub1C_game_over_retry_input
		SW_PTR	_s17_sub1F_game_over_retry
		SW_PTR	_s17_sub1D_game_over_pass
		SW_PTR	_s17_sub1E_game_over_pass_msg
		SW_PTR	_s17_sub14_game_over_pass_gen
		SW_PTR	_s17_sub15_game_over_pass_draw

		SW_PTR	_s17_sub10_force_quit
		SW_PTR	_s17_sub11_force_quit_draw
		SW_PTR	_s17_sub12_force_quit_msg
		SW_PTR	_s17_sub13_force_quit_input
		SW_PTR	_s17_sub16_force_quit_wait

		SW_PTR	_fade_out_reload_scene

locret_B035F:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub00_pass_input_clear:
		SW_NXT	_s17_sub01_pass_input_chars_draw0
		LDA		#0
		STA		_tmp_cnt0
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub01_pass_input_chars_draw0:
#if LANGUAGE == JP_LANG
;-----------------------------------------------
		LDA		byte_3BD
		BNE		loc_B0A28
;-----------------------------------------------
#endif
		LDX		_tmp_cnt0
		BNE		loc_B09C5
		LDA		#<[_pass_chars_tbl]
		STA		word_0
		LDA		#>[_pass_chars_tbl]
		STA		word_0+1
		LDA		#$73
		STA		_tlm_tmp_line_dst
		LDA		#$20
		STA		_tlm_tmp_line_dst+1
		BNE		loc_B09E8
loc_B09C5:
		LDA		#0
		CLC
loc_B09C8:
		ADC		#$B
		DEX
		BNE		loc_B09C8
		ADC		#<[_pass_chars_tbl]
		STA		word_0
		LDA		#0
		ADC		#>[_pass_chars_tbl]
		STA		word_0+1
		LDA		_tlm_tmp_line_dst
		CLC
		ADC		#$40
		STA		_tlm_tmp_line_dst
		LDA		_tlm_tmp_line_dst+1
		ADC		#0
		STA		_tlm_tmp_line_dst+1
loc_B09E8:
		LDY		#0
loc_B09EA:
		LDA		(word_0),Y
		STA		_ppu_tmp_row_buf,Y
		INY
		CPY		#$B
		BCC		loc_B09EA
		INC		_tmp_cnt0
		LDA		_tmp_cnt0
		CMP		#7
		BCS		loc_B0A09
		LDA		#$B
		STA		_nmi_ppu_tlm_draw_len
		LDA		#2
		STA		_nmi_ppu_tlm_draw_req
		RTS
loc_B0A09:
#if LANGUAGE == JP_LANG
;-----------------------------------------------
		LDA		#$9B							; here we draw extra nigori at "BACK"
		STA		_tlm_tmp_line_dst				; only used in japanese
		LDA		#$21
		STA		_tlm_tmp_line_dst+1
		LDA		#$39
		STA		_ppu_tmp_row_buf
		LDA		#1
		STA		_nmi_ppu_tlm_draw_len
		LDA		#2
		STA		_nmi_ppu_tlm_draw_req
		LDA		#1
		STA		byte_3BD
		RTS
loc_B0A28:
		LDA		#0
		STA		byte_3BD
;-----------------------------------------------
#endif
		SW_NXT	_s17_sub02_pass_input_miyako_draw
		RTS

_pass_chars_tbl:
#if LANGUAGE == JP_LANG
;-----------------------------------------------
		.BYTE   7,  8,  9, $A, $B,  0,$25,$26,$27,$28,$29
		.BYTE  $C, $D, $E, $F,$10,  0,$2A,  0,$2B,  0,$2C
		.BYTE $11,$12,$13,$14,$15,  0,$2D,$2E,$2F,$30,$31
		.BYTE $16,$17,$18,$19,$1A,  0,$32,  0,$33,  0,$34
		.BYTE $1B,$1C,$1D,$1E,$1F,  0,  0,$13,$13,$27,  0	; difference in forward, back buttons
		.BYTE $20,$21,$22,$23,$24,  0,  0,$29,$1A,$2F,  0
;-----------------------------------------------
#else
;-----------------------------------------------
		.BYTE   7,  8,  9, $A, $B,  0,$25,$26,$27,$28,$29
		.BYTE  $C, $D, $E, $F,$10,  0,$2A,  0,$2B,  0,$2C
		.BYTE $11,$12,$13,$14,$15,  0,$2D,$2E,$2F,$30,$31
		.BYTE $16,$17,$18,$19,$1A,  0,$32,  0,$33,  0,$34
		.BYTE $1B,$1C,$1D,$1E,$1F,  0,  0,$3D,$3D,$40,  0
		.BYTE $20,$21,$22,$23,$24,  0,  0,$41,$3D,$3D,  0
;-----------------------------------------------
#endif

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub02_pass_input_miyako_draw:
		SW_NXT	_s17_sub03_pass_input_miyako_msg

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_tlmA2_draw_A:
		TLM6	$43,$45,$A2						; this mode used only here

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub03_pass_input_miyako_msg:
		JSR		_snd_miyako_theme_with_percussion
		SW_FADE	_s17_sub04_pass_input_kaneda_draw
		MSG_M
		MSG		_sc17_msg7B
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub04_pass_input_kaneda_draw:
		SW_NXT	_s17_sub05_pass_input_kaneda_msg
		LDA		#1
		STA		_scene_spr_overlay_idx
		TLM6	$5D,$5D,$88

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub05_pass_input_kaneda_msg:
		SW_NXT	_s17_sub06_pass_input_loop
		LDA		#0
		STA		_pass_input_pos
		STA		_pass_char_pos_x
		STA		_pass_char_pos_y
		MSG_1	_sc17_msg7A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub06_pass_input_loop:
		JSR		_pass_char_select
		JSR		_pass_char_cursor				; selection cursor
		JSR		_pass_cursor					; pass last char cursor
		JSR		_pass_char_input
		JMP		_pass_test

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub08_pass_input_ok_draw:
		SW_NXT	_s17_sub09_pass_input_ok_msg
		LDA		#0
		STA		_scene_spr_overlay_idx
		JMP		_s17_tlmA2_draw_A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub09_pass_input_ok_msg:
		SW_FADE	_s17_sub0A_pass_input_ok_decode
		MSG_M
		MSG		_sc17_msg78
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub0A_pass_input_ok_decode:
		JSR		_pass_decode
		JSR		_apu_reset
		LDA		#0
		TAX
loc_B0469:
		STA		_scene_anim_idx,X
		STA		_scene_anim_counter,X
		INX
		CPX		#5
		BCC		loc_B0469
		LDA		_scene_idx_pass
		STA		_scene_idx
		LDA		_scene_sub_idx_pass
		STA		_scene_sub_cur
		STA		_scene_sub_next
		LDA		#0
		STA		_scroll_x_shadow
		STA		_scroll_x_shadow+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub0B_pass_input_wrong_draw:
		SW_NXT	_s17_sub0C_pass_input_wrong_msg
		LDA		#0
		STA		_scene_spr_overlay_idx
		JMP		_s17_tlmA2_draw_A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub0C_pass_input_wrong_msg:
		SW_FADE	_s17_sub04_pass_input_kaneda_draw
		MSG_M
		MSG		_sc17_msg79
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub0E_game_over_prison:
		SW_FADE	_s17_sub17_game_over_prison_draw
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub17_game_over_prison_draw:
		SW_NXT	_s17_sub19_game_over_prison_msg
		JSR		_apu_reset
		JSR		_scroll_reset
		LDA		#0
		STA		_scene_spr_overlay_idx
		TLM5	$30,$32,$56

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub19_game_over_prison_msg:
		SW_NXT	_s17_sub1B_game_over_retry_msg
		MSG_M
		MSG		_sc17_msg8C
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub0F_game_over_dead:
		SW_FADE	_s17_sub18_game_over_dead_draw
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub18_game_over_dead_draw:
		SW_NXT	_s17_sub1A_game_over_dead_msg
		JSR		_apu_reset
		JSR		_scroll_reset
		LDA		#0
		STA		_scene_spr_overlay_idx
		TLM5	$31,$33,$57

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub1A_game_over_dead_msg:
		SW_NXT	_s17_sub1B_game_over_retry_msg
		MSG_M
		MSG		_sc17_msg84
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub1B_game_over_retry_msg:
		JSR		_snd_game_over_retry_jingle
		SW_NXT	_s17_sub1C_game_over_retry_input
		MSG_1	_sc17_msg86

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub1C_game_over_retry_input:
		LDA		_pads+1
		AND		#1
		BEQ		loc_B059D
		SW_FADE	_s17_sub1F_game_over_retry
		RTS
loc_B059D:
		LDA		_pads+1
		AND		#2
		BEQ		locret_B05AD
		SW_FADE	_s17_sub1D_game_over_pass
locret_B05AD:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub1F_game_over_retry:
		LDA		_retry_scene_idx
		LDX		_retry_scene_sub_cur
		JMP		_new_scene_ex

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub1D_game_over_pass:
		SW_NXT	_s17_sub1E_game_over_pass_msg
		LDA		_retry_scene_idx				; why they aren't just use retry params
		STA		_scene_idx_pass
		LDA		_retry_scene_sub_cur
		STA		_scene_sub_idx_pass
		JMP		_s17_tlmA2_draw_B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub1E_game_over_pass_msg:
		SW_NXT	_s17_sub14_game_over_pass_gen
		JSR		_apu_reset
		JSR		_snd_miyako_theme_with_percussion
		MSG_M
		MSG		_sc17_msg76
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub14_game_over_pass_gen:
		SW_NXT	_s17_sub15_game_over_pass_draw
		JMP		_pass_generate

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub15_game_over_pass_draw:
		SW_NXT	_s17_sub16_force_quit_wait
		MSG_1	_sc17_msgB6

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub10_force_quit:
		SW_NXT	_s17_sub11_force_quit_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub11_force_quit_draw:
		SW_NXT	_s17_sub12_force_quit_msg
		LDA		#0
		STA		_tmp_cnt0

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_tlmA2_draw_B:
		TLM5	$43,$45,$A2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub12_force_quit_msg:
		SW_NXT	_s17_sub13_force_quit_input
		JSR		_apu_reset
		JSR		_snd_miyako_theme_with_percussion
		MSG_1	_sc17_msg77

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub13_force_quit_input:
		LDA		_pads+1
		AND		#1
		BEQ		loc_B04FA
		SW_NXT	_s17_sub14_game_over_pass_gen
		MSG_M
		MSG		_sc17_msg76
		MSG_WAIT
		MSG_EOL
loc_B04FA:
		LDA		_pads+1
		AND		#2
		BEQ		locret_B0509
		LDA		_scene_idx_pass
		LDX		_scene_sub_idx_pass
		JMP		_new_scene_ex
locret_B0509:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_sub16_force_quit_wait:
		LDA		_pads+1
		AND		#1
		BEQ		locret_B0526
		LDA		#1
		STA		_main_sub_idx
locret_B0526:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_spr_overlay_set:
		LDA		_scene_spr_overlay_idx			; ok, game over can get to there from any place
		AND		#1								; the overlay isn't reinitialized for the first frame here
		SWITCH									; so they may crash if you don't mask it here at least
		SW_PTR	_nullsub
		SW_PTR	_s17_spr_overlay1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_spr_overlay1_A:
		JSR		_do_scene_anim0_pat0121
		LDA		_scene_anim_idx
		SPR0JSW	off_81A08,$46,$78				; caution! both functions uses the same sprites!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s17_spr_overlay1:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0JSW	off_81A08,$46,$48				; caution! both functions uses the same sprites!

off_81A08:										; make sure they both moved at the same time or split
		.WORD _spr_s17_kaneda_mouth2
		.WORD _spr_s17_kaneda_mouth1
		.WORD _spr_s17_kaneda_mouth3

_spr_s17_kaneda_mouth1:
		.BYTE   8,$C2,  1,  8
		.BYTE   0,$BA,  1,  0
		.BYTE   0,$BB,  1,  8
		.BYTE   8,$BC,  1,  0
		.BYTE   8,$BD,  1,  8
		.BYTE $80
_spr_s17_kaneda_mouth2:
		.BYTE   0,$C0,  1,  0
		.BYTE   0,$C1,  1,  8
		.BYTE $80
_spr_s17_kaneda_mouth3:
		.BYTE   3,$C2,  1,  3
		.BYTE   0,$BE,  1,  0
		.BYTE   0,$BF,  1,  8
		.BYTE $80

;-----------------------------------------------
; PASSWORD ROUTINES
;-----------------------------------------------

;-------------S-U-B-R-O-U-T-I-N-E---------------
_pass_char_select:
		LDA		_pads+1
		AND		#$10
		BEQ		loc_B061D
loc_B060A:
		LDA		_pass_char_pos_x
		BEQ		locret_B064B
		DEC		_pass_char_pos_x
		JSR		_pass_get_char
		BEQ		loc_B060A
		BNE		.char_type_snd
loc_B061D:
		LDA		_pads+1
		AND		#$20
		BEQ		loc_B064C
loc_B0623:
		LDA		_pass_char_pos_x
		CMP		#5
		BEQ		locret_B064B
		INC		_pass_char_pos_x
		LDA		_pass_char_pos_x
		CMP		#4
		BEQ		loc_B063F
		JSR		_pass_get_char
		BEQ		loc_B0623
		BNE		.char_type_snd
loc_B063F:
		LDA		_pass_char_pos_y
		CMP		#6
		BCC		locret_B064B
		LDA		#8
		STA		_pass_char_pos_y
locret_B064B:
		RTS
loc_B064C:
		LDA		_pads+1
		AND		#$40
		BEQ		loc_B067B
loc_B0652:
		LDA		_pass_char_pos_y
		BEQ		locret_B064B
		DEC		_pass_char_pos_y
		LDA		_pass_char_pos_y
		CMP		#7
		BNE		loc_B0668
		LDA		_pass_char_pos_x
		CMP		#4
		BCS		loc_B0673
loc_B0668:
		JSR		_pass_get_char
		BEQ		loc_B0652
.char_type_snd:
		JMP		_snd_char_type
loc_B0673:
		LDA		#4
		STA		_pass_char_pos_y
		BNE		locret_B064B
loc_B067B:
		LDA		_pads+1
		AND		#$80
		BEQ		locret_B064B
loc_B0681:
		LDA		_pass_char_pos_y
		CMP		#$A
		BEQ		locret_B064B
		INC		_pass_char_pos_y
		LDA		_pass_char_pos_y
		CMP		#6
		BCC		loc_B0699
		LDA		_pass_char_pos_x
		CMP		#4
		BCS		loc_B06A4
loc_B0699:
		JSR		_pass_get_char
		BEQ		loc_B0681
		BNE		.char_type_snd
loc_B06A4:
		LDA		#8
		STA		_pass_char_pos_y
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_pass_get_char:
		LDA		#0
		LDX		_pass_char_pos_x
		BEQ		loc_B06B7
loc_B06B1:
		CLC
		ADC		#$B
		DEX
		BNE		loc_B06B1
loc_B06B7:
		CLC
		ADC		_pass_char_pos_y
		TAX
		LDA		_pass_chars_tbl,X
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_pass_char_cursor:
		LDA		_frames_counter
		AND		#$C
		BNE		locret_B06FE
		LDA		_pass_char_pos_x
		ASL
		ASL
		ASL
		ASL
		CLC
		ADC		#$18
		STA		word_2
		LDA		_pass_char_pos_y
		ASL
		ASL
		ASL
		CLC
		ADC		#$98
		STA		word_2+1
		LDA		_pass_char_pos_x
		CMP		#4
		BCC		loc_B06FB
		LDA		_pass_char_pos_y
		CMP		#5
		BCC		loc_B06FB
		SPR0EX	_spr_pass_cpecial_cur
		RTS
loc_B06FB:
		SPR0EX	_spr_pass_char_cur
locret_B06FE:
		RTS
_spr_pass_char_cur:
		.BYTE   0,  1,  0,  0
		.BYTE $80
_spr_pass_cpecial_cur:
		.BYTE   0,  1,  0,$F8
		.BYTE   0,  1,  0,  0
		.BYTE   0,  1,  0,  8
		.BYTE $80

;-------------S-U-B-R-O-U-T-I-N-E---------------
_pass_cursor:
		LDA		_frames_counter
		AND		#$C
		BNE		locret_B0731
		LDA		#$A0
		STA		word_2
		LDA		_pass_input_pos
		ASL
		ASL
		ASL
		CLC
		ADC		#$20
		STA		word_2+1
		SPR0EX	_spr_pass_char_cur
locret_B0731:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_pass_char_input:
		LDA		_pads+1
		AND		#2
		BNE		.pass_char_delete
		LDA		_pads+1
		AND		#1
		BEQ		locret_B07B1
		LDA		_pass_char_pos_y
		CMP		#6
		BCC		.pass_char_input
		LDA		_pass_char_pos_x
		CMP		#4
		BEQ		.pass_next_char
		BCC		.pass_char_input
.pass_prev_char:
		DEC		_pass_input_pos
		LDA		_pass_input_pos
		CMP		#8
		BEQ		.pass_prev_char
		CMP		#$11
		BEQ		.pass_prev_char
		CMP		#$FF
		BNE		locret_B07B1
		LDA		#0
		STA		_pass_input_pos
locret_B07B1:
		RTS
.pass_char_input:
		JSR		_pass_set_ppu_ofs
		JSR		_pass_get_char
		JSR		.pass_put_char
.pass_next_char:
		INC		_pass_input_pos
		LDA		_pass_input_pos
		CMP		#8
		BEQ		.pass_next_char					; skip spaces between blocks
		CMP		#$11
		BEQ		.pass_next_char
		CMP		#$1A
		BNE		locret_B07B2
		LDA		#$19
		STA		_pass_input_pos
locret_B07B2:
		RTS
.pass_char_delete:
		JSR		.pass_prev_char
		JSR		_pass_set_ppu_ofs
		LDA		#__
.pass_put_char:
		STA		_ppu_tmp_row_buf
		SEC
		SBC		#7
		LDX		_pass_input_pos
		CPX		#8
		BCC		loc_B0779
		DEX
		CPX		#$10
		BCC		loc_B0779
		DEX
loc_B0779:
		STA		_ppu_tmp_buf1,X
		JSR		_snd_char_type
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_pass_set_ppu_ofs:
		LDA		_pass_input_pos
		CLC
		ADC		#$84
		STA		_tlm_tmp_line_dst
		LDA		#$22
		STA		_tlm_tmp_line_dst+1
		LDA		#1
		STA		_nmi_ppu_tlm_draw_len
		LDA		#2
		STA		_nmi_ppu_tlm_draw_req
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_pass_generate:
		LDA		_scene_idx_pass
		CMP		#$10
		BNE		loc_B07BE
		LDA		#0
		STA		_scene_flags
loc_B07BE:
		JSR		_pass_encode
		JSR		_pass_cypher
		JMP		_pass_format

;-------------S-U-B-R-O-U-T-I-N-E---------------
_pass_encode:
		LDA		_rand
		AND		#$1F
		STA		_pass_tmp
		LDA		_starting_area_num
		STA		_pass_tmp+1
		LDA		_scene_sub_idx_pass
		JSR		_split_nibbles
		STA		_pass_tmp+2
		STX		_pass_tmp+3
		LDA		_scene_idx_pass
		STA		_pass_tmp+4
		LDA		_game_global_flags1
		STX		_pass_tmp+5
		LDA		_game_global_flags0
		JSR		_split_nibbles
		STA		_pass_tmp+6
		STX		_pass_tmp+7
		LDX		#0
loc_B07FA:
		LDA		_scene_states,X
		STA		_pass_tmp+8,X
		INX
		CPX		#4
		BCC		loc_B07FA
		LDX		#0
loc_B0807:
		LDA		_scene_anim_idx,X
		STA		_pass_tmp+$C,X
		INX
		CPX		#4
		BCC		loc_B0807
		LDY		#0
		LDX		#0
loc_B0816:
		TXA
		PHA
		LDA		_scene_flags,X
		JSR		_split_nibbles
		STA		_pass_tmp+$10,Y
		TXA
		STA		_pass_tmp+$11,Y
		PLA
		TAX
		INX
		INY
		INY
		CPX		#3
		BCC		loc_B0816
		LDA		#0
		STA		_pass_tmp+$16
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_split_nibbles:
		PHA
		LSR
		LSR
		LSR
		LSR
		TAX
		PLA
		AND		#$F
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_pass_test:
		LDA		_pads+1
		AND		#8
		BEQ		locret_B0864
		JSR		_snd_char_type
		JSR		_pass_checksum
		CMP		_ppu_tmp_buf1+$17
		BNE		.rong_pass
		SW_FADE	_s17_sub08_pass_input_ok_draw
		RTS
.rong_pass:
		SW_FADE	_s17_sub0B_pass_input_wrong_draw
locret_B0864:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_pass_decode:
		LDX		_ppu_tmp_buf1
		LDY		#1
loc_B086A:
		LDA		_ppu_tmp_buf1,Y
		SEC
		SBC		_pass_delta_tbl,X
		STA		_pass_tmp,Y
		INX
		INY
		CPY		#$16
		BCC		loc_B086A
		LDA		_pass_tmp+1
		STA		_starting_area_num
		LDA		_pass_tmp+2
		STA		word_0
		LDA		_pass_tmp+3
		JSR		_combine_nibbles
		STA		_scene_sub_idx_pass
		LDA		_pass_tmp+4
		STA		_scene_idx_pass
		LDA		_pass_tmp+5
		STA		_game_global_flags1
		LDA		_pass_tmp+6
		STA		word_0
		LDA		_pass_tmp+7
		JSR		_combine_nibbles
		STA		_game_global_flags0
		LDX		#0
loc_B08AA:
		LDA		_pass_tmp+8,X
		STA		_scene_states,X
		INX
		CPX		#4
		BCC		loc_B08AA
		LDX		#0
loc_B08B7:
		LDA		_pass_tmp+$C,X
		STA		_scene_anim_idx,X
		INX
		CPX		#4
		BCC		loc_B08B7
		LDY		#0
		LDX		#0
loc_B08C6:
		LDA		_pass_tmp+$10,Y
		STA		word_0
		LDA		_pass_tmp+$11,Y
		JSR		_combine_nibbles
		STA		_scene_flags,X
		INY
		INY
		INX
		CPX		#3
		BCC		loc_B08C6
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_combine_nibbles:
		ASL
		ASL
		ASL
		ASL
		ORA		word_0
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_pass_cypher:
		LDY		#0
		LDA		_pass_tmp,Y
		STA		_ppu_tmp_buf1,Y
		TAX
		INY
loc_B08ED:
		LDA		_pass_tmp,Y
		CLC
		ADC		_pass_delta_tbl,X
		STA		_ppu_tmp_buf1,Y
		INX
		INY
		CPY		#$17
		BCC		loc_B08ED
		JSR		_pass_checksum
		STA		_ppu_tmp_buf1+$17
		RTS

_pass_delta_tbl:
		.BYTE   3, $A,  1, $B, $A,  1,  5, $B, $C,  8,  2,  0, $D,  4, $E,  8
		.BYTE   5,  1, $B,  1, $D,  2,  8, $E,  3,  2,  7, $E,  3,  0,  8, $C
		.BYTE   5,  4, $A,  4,  1,  6, $D, $D,  4,  7, $A,  6,  0,  0, $C, $A
		.BYTE   5,  0, $B, $C, $B, $E,  9,  6,  0,  2,  0,  7,  9,  3,  8,  9

;-------------S-U-B-R-O-U-T-I-N-E---------------
_pass_checksum:
		LDY		#0
		LDA		_ppu_tmp_buf1,Y
		STA		word_0
loc_B094B:
		LDX		word_0
		LDA		_ppu_tmp_buf1,Y
		CLC
		ADC		_pass_delta_tbl,X
		CLC
		ADC		word_0
		AND		#$1F
		STA		word_0
		INY
		CPY		#$17
		BCC		loc_B094B
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_pass_format:
		LDX		#0
		TXA
loc_B0964:
		STA		_format_buf,X
		INX
		CPX		#$20
		BCC		loc_B0964
		LDX		#0
		LDY		#0
loc_B0970:
		LDA		_ppu_tmp_buf1,X
		CLC
		ADC		#7
		STA		_format_buf,Y
		INX
		INY
		CPX		#8
		BCC		loc_B0970
		INY
loc_B0980:
		LDA		_ppu_tmp_buf1,X
		CLC
		ADC		#7
		STA		_format_buf,Y
		INX
		INY
		CPX		#$10
		BCC		loc_B0980
		INY
loc_B0990:
		LDA		_ppu_tmp_buf1,X
		CLC
		ADC		#7
		STA		_format_buf,Y
		INX
		INY
		CPX		#$18
		BCC		loc_B0990
		INY
		LDA		#$FF
		STA		_format_buf,Y
		RTS

		SECTION_END 17
