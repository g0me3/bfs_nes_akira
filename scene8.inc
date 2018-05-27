
		SECTION_START 8

;-----------------------------------------------
; SCENE 8
;-----------------------------------------------

; original interactive script:
; 1. inquire (peek added)
; 2. peek
; 3. sneak
; 3.x make noise/hide (game over, restart SCENE 8)
; 4. dash
; 4.x any other (game over, restart SCENE 8)
; 5. dive (jump SCENE 9)
; 5.x any other (game over, restart SCENE 8)

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene8_subs:
		JSR		_s8_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_38901
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s8_sub00_clear
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_generic_menu_input
		SW_PTR	_s8_menu_handlers
		SW_PTR	_s8_sub05_area2_draw
		SW_PTR	_s8_sub06_area2_mus_msg
		SW_PTR	_s8_sub02_area2_menu_loop
		SW_PTR	_s8_sub08_sewers_draw_mus
		SW_PTR	_s8_sub09_sewers_msg
		SW_PTR	_s8_sub0A_sewers_menu0_loop
		SW_PTR	_s8_sub11_army_fire_draw_bad
		SW_PTR	_s8_sub12_army_fire_msg
		SW_PTR	_s8_sub20_army_fire_shoot_snd
		SW_PTR	_s8_sub0E_kick_metal_fence_snd
		SW_PTR	_s8_sub0B_sewers_menu1_loop
		SW_PTR	_s8_sub14_army_shoot_snd
		SW_PTR	_s8_sub0F_army_fire_draw_good
		SW_PTR	_s8_sub0C_army_menu_loop
		SW_PTR	_s8_sub16_dive_draw
		SW_PTR	_s8_sub17_dive_msg
		SW_PTR	_s8_sub18_girl_shot_draw
		SW_PTR	_s8_sub19_girl_shot_animate
		SW_PTR	_s8_sub1A_fade_out
		SW_PTR	_s8_sub1B_army_shot_draw
		SW_PTR	_s8_sub1C_army_shot_flash_delay
		SW_PTR	_s8_sub1D_kaneda_girl_draw
		SW_PTR	_s8_sub1E_kaneda_girl_msg
		SW_PTR	_s8_sub0D_game_over_prison
		SW_PTR	_s8_sub10_game_over_dead

locret_38901:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub00_clear:
		SW_NXT	_s8_sub05_area2_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub05_area2_draw:
		SW_NXT	_s8_sub06_area2_mus_msg
		TLM4	$12,$F,$1B						; the same as in scenes 5 and 7

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub06_area2_mus_msg:
		JSR		_snd_flood_channel_beat
		SW_NXT	_s8_sub02_area2_menu_loop
		MSG_1	_sc8_msg00

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub02_area2_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_3896A
		SW_RET	_s8_sub02_area2_menu_loop
		SW_NXT	_generic_menu_input
		LDA		#0
		STA		_scene_menu_idx
		JSR		_s8_menu_init0
		JMP		_menu_draw_request
locret_3896A:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub08_sewers_draw_mus:
		JSR		_snd_sewers_danger_beat
		SW_NXT	_s8_sub09_sewers_msg
		LDA		#1
		STA		_scene_spr_overlay_idx
		TLM4	$1C,$14,$27

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub09_sewers_msg:
		SW_NXT	_s8_sub0A_sewers_menu0_loop
		MSG_1	_sc8_msg05

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub0A_sewers_menu0_loop:
		LDA		#0								; since we may return here,
		STA		_scene_anim_idx					; we should reset it here
		LDA		_pads+1
		AND		#1
		BEQ		locret_389EB
		SW_RET	_s8_sub0A_sewers_menu0_loop
		SW_NXT	_generic_menu_input
		LDA		#1
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default5
		JMP		_menu_draw_request
locret_389EB:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub0D_game_over_prison:
		JSR		_scene_vars_init
		LDX		#8
		LDY		#0								; from beginning let it be 0
		JMP		_game_over_prison_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub0E_kick_metal_fence_snd:
		JSR		_snd_sewers_kick_fence			; disables two of three bg music channels, stops high-pitch voice
		LDA		#1
		STA		_scene_anim_idx
		SW_NXT	_s8_sub0B_sewers_menu1_loop
		MSG_M
		MSG		_sc8_msg0F
		MSG		_sc8_msg10
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub0B_sewers_menu1_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_38A07
		SW_RET	_s8_sub0B_sewers_menu1_loop
		SW_NXT	_generic_menu_input
		LDA		#2
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default5
		JMP		_menu_draw_request
locret_38A07:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub11_army_fire_draw_bad:
		LDA		#_s8_sub12_army_fire_msg_sidx
		BNE		_s8_apu_tlm28_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub0F_army_fire_draw_good:
		LDA		#_s8_sub0C_army_menu_loop_sidx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_apu_tlm28_draw:
		STA		_scene_sub_next
		LDA		#0
		STA		_scene_spr_overlay_idx
		JSR		_snd_sewers_danger_beat
		TLM5	$33,$15,$28

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub0C_army_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_38A23
		SW_RET	_s8_sub0C_army_menu_loop
		SW_NXT	_generic_menu_input
		LDA		#3
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default4
		JMP		_menu_draw_request
locret_38A23:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub10_game_over_dead:
		JSR		_scene_vars_init
		LDX		#8
		LDY		#0								; from beginning, let it be 0
		JMP		_game_over_dead_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub12_army_fire_msg:
		SW_NXT	_s8_sub20_army_fire_shoot_snd
		MSG_M
		MSG		_sc8_msg8A
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub20_army_fire_shoot_snd:
		JSR		_snd_army_gun_fire
		SW_NXT	_s8_sub10_game_over_dead
		MSG_M
		MSG		_sc8_msg8B
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub14_army_shoot_snd:
		JSR		_snd_army_gun_fire
		SW_FADE	_s8_sub10_game_over_dead
		MSG_M
		MSG		_sc8_msg8B
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub16_dive_draw:
		SW_NXT	_s8_sub17_dive_msg
		LDA		#2
		STA		_scene_spr_overlay_idx
		LDA		#0
		STA		_tmp_y_pos
		LDA		#$58
		STA		_tmp_x_pos
		LDA		#$38
		STA		_tmp_direction_y0
		LDA		#$68
		STA		_tmp_direction_x0
		TLM4	$1D,$16,$29

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub17_dive_msg:
		SW_FADE	_s8_sub18_girl_shot_draw
		MSG_M
		MSG		_sc8_msg19
		MSG		_sc8_msg1A
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub18_girl_shot_draw:
		SW_NXT	_s8_sub19_girl_shot_animate
		LDA		#6
		STA		_scene_spr_overlay_idx
		LDA		#0
		STA		_spr0_overflow_mode_flag		; forgot to disable, thus this isn't break anything
		STA		_scene_anim_idx
		STA		_tmp_cnt0
		TLM5	$1E,$17,$2A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub19_girl_shot_animate:
		LDA		_frames_counter
		AND		#3
		BNE		locret_38B4E
		INC		_tmp_cnt0
		LDA		_tmp_cnt0
		LDX		#0
		CMP		#$10
		BCC		loc_38B41
		INX
		CMP		#$14
		BCC		loc_38B41
		INX
		CMP		#$20
		BCC		loc_38B41
		SW_NXT	_s8_sub1A_fade_out
		RTS
loc_38B41:
		STX		_scene_anim_idx
		LDA		_tmp_cnt0
		CMP		#$10
		BNE		locret_38B4E
		JMP		_snd_army_gun_fire
locret_38B4E:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub1A_fade_out:
		SW_FADE	_s8_sub1B_army_shot_draw
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub1B_army_shot_draw:
		SW_NXT	_s8_sub1C_army_shot_flash_delay
		LDA		#7
		STA		_scene_spr_overlay_idx
		TLM5	$2D,$18,$2B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub1C_army_shot_flash_delay:
		SW_FADE	_s8_sub1D_kaneda_girl_draw
		LDA		#4
		JMP		_delay

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub1D_kaneda_girl_draw:
		SW_NXT	_s8_sub1E_kaneda_girl_msg
		LDA		#4
		STA		_scene_spr_overlay_idx
		TLM4	$1B,$19,$2C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_sub1E_kaneda_girl_msg:
		SW_FADE	_next_scene
		MSG_M
		MSG		_sc8_msg1B
		MSG		_sc8_msg0A
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu_init0:
		LDA		_scene_flags
		AND		#2
		BEQ		locret_38BE9
		JMP		_scene_menu_init_default3
locret_38BE9:
		JMP		_scene_menu_init_default2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu_handlers:
		JSR		_menu_switch
		.WORD _s8_menu0
		.WORD _s8_menu1
		.WORD _s8_menu2
		.WORD _s8_menu3
_s8_menu0:
		.WORD _s8_menu0_check
		.WORD _s8_menu0_inquire
		.WORD _s8_menu0_peek
_s8_menu1:
		.WORD _s8_menu1_talk
		.WORD _s8_menu1_ask_out
		.WORD _s8_menu1_make_noise
		.WORD _s8_menu1_hide
		.WORD _s8_menu1_sneak
_s8_menu2:
		.WORD _s8_menu2_talk
		.WORD _s8_menu2_raise_hands
		.WORD _s8_menu2_pray
		.WORD _s8_menu2_jump_on
		.WORD _s8_menu2_dash
_s8_menu3:
		.WORD _s8_menu3_play_dumb
		.WORD _s8_menu3_slide
		.WORD _s8_menu3_flip
		.WORD _s8_menu3_dive

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu0_check:
		SW_NXT	_s8_sub02_area2_menu_loop
		MSG_1	_sc8_msg01

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu0_inquire:
		SW_NXT	_s8_sub02_area2_menu_loop
		LDA		_scene_flags
		ORA		#2
		STA		_scene_flags
		MSG_1	_sc8_msg03

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu0_peek:
		SW_FADE	_s8_sub08_sewers_draw_mus
		MSG_M
		MSG		_sc8_msg04
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu1_talk:
		LDA		#1
		STA		_scene_anim_idx
		SW_NXT	_s8_sub0A_sewers_menu0_loop
		MSG_M
		MSG		_sc8_msg06
		MSG		_sc8_msg07
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu1_ask_out:
		SW_NXT	_s8_sub0A_sewers_menu0_loop
		MSG_M
		MSG		_sc8_msg1C
		MSG		_sc8_msg07
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu1_make_noise:
		LDA		#1
		STA		_scene_anim_idx
		SW_FADE	_s8_sub11_army_fire_draw_bad
		MSG_M
		MSG		_sc8_msg08
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu1_hide:
		SW_FADE	_s8_sub0D_game_over_prison
		MSG_M
		MSG		_sc8_msg0B
		MSG		_sc8_msg8A
		MSG		_sc8_msg0C
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu1_sneak:
		SW_NXT	_s8_sub0E_kick_metal_fence_snd
		MSG_M
		MSG		_sc8_msg0E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu2_talk:
		SW_NXT	_s8_sub14_army_shoot_snd
		MSG_M
		MSG		_sc8_msg11
		MSG		_sc8_msg8A
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu2_raise_hands:
		SW_NXT	_s8_sub0D_game_over_prison
		MSG_M
		MSG		_sc8_msg12
		MSG		_sc8_msg8A
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu2_pray:
		SW_NXT	_s8_sub0D_game_over_prison
		MSG_M
		MSG		_sc8_msg13
		MSG		_sc8_msg8A
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu2_jump_on:
		SW_NXT	_s8_sub0D_game_over_prison
		MSG_M
		MSG		_sc8_msg14
		MSG		_sc8_msg8A
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu2_dash:
		SW_FADE	_s8_sub0F_army_fire_draw_good
		MSG_1	_sc8_msg15

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu3_play_dumb:
		SW_NXT	_s8_sub14_army_shoot_snd
		MSG_M
		MSG		_sc8_A_msg8F
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu3_slide:
		SW_FADE	_s8_sub10_game_over_dead
		MSG_M
		MSG		_sc8_msg16
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu3_flip:
		SW_FADE	_s8_sub10_game_over_dead
		MSG_M
		MSG		_sc8_msg17
		MSG		_sc8_msg8A
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_menu3_dive:
		SW_FADE	_s8_sub16_dive_draw
		MSG_1	_sc8_msg18

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s8_spr_overlay1
		SW_PTR	_s8_spr_overlay2
		SW_PTR	0	;	_s8_spr_overlay3		; -unused-
		SW_PTR	_s8_spr_overlay4
		SW_PTR	0
		SW_PTR	_s8_spr_overlay6
		SW_PTR	_s8_spr_overlay7

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_spr_overlay1:
		SPR0	_spr_sc8_sewers_army_body,$18,$50
		LDA		_scene_anim_idx
		SPR0SW	off_38E22,$18,$50
		SPR0J	_spr_sc8_sewers_girl,$18,$D0
off_38E22:
		.WORD _spr_sc8_sewers_army_head_forth
		.WORD _spr_sc8_sewers_army_head_back

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_spr_overlay2:
		LDA		_tmp_y_pos
		CMP		#$90
		BCS		locret_38DE8
		LDA		#1
		STA		_spr0_overflow_mode_flag		; trick to cut out bottom sprite edges
		JSR		_s8_spr_overlay2_A
		JSR		_s8_spr_overlay2_B
		JMP		_s8_spr_overlay2_C
locret_38DE8:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_spr_overlay2_A:
		LDX		#0
		LDA		_tmp_y_pos
		CMP		#$70
		BCC		loc_38F59
		INX
		CMP		#$78
		BCC		loc_38F59
		INX
		CMP		#$80
		BCC		loc_38F59
		INX
		CMP		#$88
		BCC		loc_38F59
		LDX		#0
loc_38F59:
		TXA
		SPR0JSW	off_38F71,$60,$90
off_38F71:
		.WORD _spr_dummy
		.WORD _spr_sc8_water_splash0
		.WORD _spr_sc8_water_splash1
		.WORD _spr_sc8_water_splash2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_spr_overlay2_B:
		LDA		_tmp_y_pos
		CMP		_tmp_direction_y0
		BCC		loc_38E70
		INC		_tmp_direction_y0
		INC		_tmp_direction_y0
		INC		_tmp_direction_x0
loc_38E70:
		LDA		_tmp_direction_y0
		CMP		#$80
		BCS		locret_38E8C
		LDA		_tmp_direction_y0
		STA		word_2
		LDA		_tmp_direction_x0
		STA		word_2+1
		SPR1	_spr_sc8_soldier_dive
locret_38E8C:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_spr_overlay2_C:
		INC		_tmp_y_pos
		INC		_tmp_y_pos
		INC		_tmp_x_pos
		LDA		_tmp_y_pos
		CMP		#$80
		BCS		locret_38E5E
		LDA		_tmp_y_pos
		STA		word_2
		LDA		_tmp_x_pos
		STA		word_2+1
		SPR1	_spr_sc8_kaneda_dive
locret_38E5E:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
;_s8_spr_overlay3:								; unknown unused overlay, no CHR matches
;		LDA		_scene_anim_idx+1
;		LDA		#0
;		SPR0JSW	off_38F3B,$40,$70
;off_38F3B:
;		.WORD byte_392CC
;		.WORD byte_392E1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_spr_overlay4:
		SPR0	_spr_sc8_kaneda_girls_heads,$20,$80
		JSR		_get_anim_blink_idx
		PHA
		SPR0SW	off_38EBB,$20,$80				; eyes animations separated
		PLA
		SPR0SW	off_38EBC,$20,$80				; the same
		JSR		_do_scene_anim0_pat0101			; here is anim driver missed
		LDA		_scene_anim_idx					; so we couldn't see the animations
		SPR0JSW	off_38EBA,$20,$80				; mouth animated separately now
off_38EBA:
		.WORD _spr_sc8_kaneda_mouth_open		; it seems, they didn't finished it here
		.WORD _spr_sc8_kaneda_mouth_shut		; mouth and eyes were concatenated,
off_38EBB:										; and can't be animated separately.
		.WORD _spr_sc8_kaneda_eyes_open
		.WORD _spr_sc8_kaneda_eyes_shut
off_38EBC:
		.WORD _spr_sc8_girls_eyes_open
		.WORD _spr_sc8_girls_eyes_shut

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_spr_overlay6:
		SPR0	_spr_sc8_girl_shot_hair,$20,$88
		LDA		_scene_anim_idx					; animated by handler
		SPR0SW	off_38F08,$38,$90
		LDA		_scene_anim_idx					; the same
		CMP		#1
		BNE		locret_38F07
		SPR0	_spr_sc8_girl_shot_fire,$34,$4C
locret_38F07:
		RTS
off_38F08:
		.WORD _spr_sc8_girl_shot_eyes0
		.WORD _spr_sc8_girl_shot_eyes1
		.WORD _spr_sc8_girl_shot_eyes2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s8_spr_overlay7:
		SPR0J	_spr_sc8_army_shoot_blood,$28,$40

_spr_sc8_sewers_army_body:
		.BYTE   8,$AE,  3,$30
		.BYTE   8,$AF,  3,$38
		.BYTE $10,$B0,  3,  8
		.BYTE $10,$DF,  3,$10
		.BYTE $10,$E0,  3,$18
		.BYTE $10,$B3,  3,$20
		.BYTE $10,$B4,  3,$28
		.BYTE $10,$B5,  3,$30
		.BYTE $18,$B6,  3,  6
		.BYTE $18,$B7,  3, $E
		.BYTE $18,$B8,  3,$16
		.BYTE $18,$B9,  3,$1E
		.BYTE $18,$BA,  3,$26
		.BYTE $18,$BB,  3,$2E
		.BYTE $20,$BC,  3,  0
		.BYTE $20,$BD,  3,  8
		.BYTE $20,$C2,  3,$10
		.BYTE $20,$BE,  3,$18
		.BYTE $20,$BF,  3,$20
		.BYTE $28,$C0,  3,  0
		.BYTE $28,$C1,  3,  8
		.BYTE $28,$C2,  3,$10
		.BYTE $28,$C3,  3,$18
		.BYTE $30,$C4,  3,  0
		.BYTE $30,$C5,  3,  8
		.BYTE $30,$C6,  3,$10
		.BYTE $30,$C7,  3,$18
		.BYTE $30,$C8,  3,$20
		.BYTE $38,$C9,  3,  8
		.BYTE $38,$CA,  3,$10
		.BYTE $38,$CB,  3,$18
		.BYTE $38,$CC,  3,$20
		.BYTE $38,$CD,  3,$28
		.BYTE $40,$CE,  3,  8
		.BYTE $40,$CF,  3,$10
		.BYTE $40,$D0,  3,$18
		.BYTE $40,$D1,  3,$20
		.BYTE $40,$D2,  3,$28
		.BYTE $40,$D3,  3,$30
		.BYTE $48,$D4,  3,  8
		.BYTE $48,$D5,  3,$10
		.BYTE $48,$D6,  3,$27
		.BYTE $48,$D7,  3,$2F
		.BYTE $50,$D8,  3,$28
		.BYTE $50,$D9,  3,$30
		.BYTE $80
_spr_sc8_sewers_army_head_forth:
		.BYTE   0,$DB,  3,$10
		.BYTE   0,$DC,  3,$18
		.BYTE   4,$DA,  3,$20
		.BYTE   8,$DD,  3,$10
		.BYTE   8,$DE,  3,$18
		.BYTE $80
_spr_sc8_sewers_army_head_back:
		.BYTE   0,$AA,  3,$10
		.BYTE   0,$AB,  3,$18
		.BYTE   8,$AC,  3,$10
		.BYTE   8,$AD,  1,$18
		.BYTE $80
_spr_sc8_sewers_girl:
		.BYTE   0,$E1,  1,  8
		.BYTE   8,$E2,  1,  3
		.BYTE   8,$E3,  1, $B
		.BYTE $10,$E4,  1,  8
		.BYTE $18,$E5,  2,  1
		.BYTE $18,$E6,  1,  9
		.BYTE $20,$E7,  2,  2
		.BYTE $20,$E8,  2, $A
		.BYTE $80
_spr_sc8_kaneda_dive:
		.BYTE   0,$C8,  1,  0
		.BYTE   0,$C9,  1,  8
		.BYTE   0,$CA,  1,$10
		.BYTE   0,$CB,  1,$18
		.BYTE   8,$CC,  1,  0
		.BYTE   8,$CD,  1,  8
		.BYTE   8,$CE,  1,$10
		.BYTE   8,$CF,  1,$18
		.BYTE   8,$D0,  1,$20
		.BYTE $10,$D1,  1,  0
		.BYTE $10,$D2,  1,  8
		.BYTE $10,$D3,  1,$10
		.BYTE $18,$D4,  1,  0
		.BYTE $18,$D5,  1,  8
		.BYTE $18,$D6,  1,$10
		.BYTE $18,$FB,  1,$18
		.BYTE $20,$FC,  1,$10
		.BYTE $20,$FD,  1,$18
		.BYTE $80
_spr_sc8_soldier_dive:
		.BYTE   0,$D7,  2,  8
		.BYTE   0,$D8,  2,$10
		.BYTE   0,$D9,  2,$18
		.BYTE   8,$DA,  2,  8
		.BYTE   8,$DB,  2,$10
		.BYTE   8,$DC,  2,$18
		.BYTE $10,$DD,  2,  8
		.BYTE $10,$DE,  2,$10
		.BYTE $10,$DF,  2,$18
		.BYTE $18,$E0,  2,  0
		.BYTE $18,$E1,  2,  8
		.BYTE $18,$E2,  2,$10
		.BYTE $18,$E3,  2,$18
		.BYTE $20,$E4,  2,  8
		.BYTE $20,$E5,  2,$10
		.BYTE $20,$E6,  2,$18
		.BYTE $28,$E7,  2,  8
		.BYTE $28,$E8,  2,$10
		.BYTE $28,$E9,  2,$18
		.BYTE $28,$EA,  2,$20
		.BYTE $30,$EB,  2,  8
		.BYTE $30,$EC,  2,$10
		.BYTE $30,$ED,  2,$18
		.BYTE $30,$EE,  2,$20
		.BYTE $80
_spr_sc8_kaneda_girls_heads:
		.BYTE   0,$8B,  1,  0
		.BYTE   0,$8C,  1,  8
		.BYTE   0,$8D,  1,$10
		.BYTE   8,$94,  1,  0
		.BYTE   8,$94,  1,  8
		.BYTE   8,$8E,  1,$10
		.BYTE   8,$8F,  1,$18
		.BYTE   8,$90,  1,$20
		.BYTE   8,$91,  1,$28
		.BYTE $10,$94,  1,  0
		.BYTE $10,$92,  1,  8
		.BYTE $10,$93,  1,$10
		.BYTE $10,$94,  1,$18
		.BYTE $10,$94,  1,$20
		.BYTE $10,$94,  1,$28
		.BYTE $10,$95,  1,$30
		.BYTE $18,$96,  1,  0
		.BYTE $18,$9C,  1,$30
		.BYTE $20,$9D,  1,  0
		.BYTE $20,$9F,  1,$18					; girls mouth always static, move here
		.BYTE $20,$A0,  1,$20					;
		.BYTE $20,$A1,  1,$28					;
		.BYTE $28,$A2,  1,  8
		.BYTE $28,$A3,  1,$10
		.BYTE $28,$A4,  1,$18
		.BYTE $28,$A5,  1,$20
		.BYTE $28,$A6,  1,$28
		.BYTE $30,$A7,  1,$10
		.BYTE $30,$A8,  1,$18
		.BYTE $30,$A9,  1,$20
		.BYTE $80								; missing or with reason?
_spr_sc8_kaneda_eyes_open:
		.BYTE $18,$80,  1,  8
		.BYTE $18,$82,  1,$10
		.BYTE $80
_spr_sc8_kaneda_eyes_shut:
		.BYTE $18,$97,  1,  8
		.BYTE $18,$98,  1,$10
		.BYTE $80
_spr_sc8_girls_eyes_open:
		.BYTE $18,$83,  1,$18
		.BYTE $18,$84,  1,$20
		.BYTE $18,$85,  1,$28
		.BYTE $80
_spr_sc8_girls_eyes_shut:
		.BYTE $18,$99,  1,$18
		.BYTE $18,$9A,  1,$20
		.BYTE $18,$9B,  1,$28
		.BYTE $80
_spr_sc8_kaneda_mouth_shut:
		.BYTE $20,$9F,  1,  8
		.BYTE $20,$9E,  1,$10
		.BYTE $80
_spr_sc8_kaneda_mouth_open:
		.BYTE $20,$86,  1,  8
		.BYTE $20,$87,  1,$10
		.BYTE $80
_spr_sc8_girl_shot_hair:
		.BYTE   0,$F3,  3,  8
		.BYTE   0,$F4,  3,$10
		.BYTE   0,$F5,  3,$18
		.BYTE   0,$F6,  3,$20
		.BYTE   0,$F7,  3,$28
		.BYTE   8,$F8,  3,  0
		.BYTE   8,$F9,  3,  8
		.BYTE   8,$F9,  3,$10
		.BYTE   8,$F9,  3,$18
		.BYTE   8,$F9,  3,$20
		.BYTE   8,$F9,  3,$28
		.BYTE   8,$FA,  3,$30
		.BYTE $80
_spr_sc8_girl_shot_eyes0:
		.BYTE   0,$E2,  3,  0
		.BYTE   0,$E3,  3,  8
		.BYTE   0,$E4,  3,$10
		.BYTE   8,$E5,  3,  4
		.BYTE $10,$E6,  3,  6
		.BYTE $80
_spr_sc8_girl_shot_eyes1:
		.BYTE   0,$E7,  3,  0
		.BYTE   0,$E8,  3,  8
		.BYTE   0,$E9,  3,$10
		.BYTE   8,$E5,  3,  4
		.BYTE $10,$EA,  3,  6
		.BYTE $80
_spr_sc8_girl_shot_eyes2:
		.BYTE   0,$EB,  3,  0
		.BYTE   0,$EC,  3,  8
		.BYTE   0,$ED,  3,$10
		.BYTE   8,$E5,  3,  4
		.BYTE $10,$EE,  3,  6
		.BYTE $80
_spr_sc8_girl_shot_fire:
		.BYTE   0,$EF,  1,  0
		.BYTE   0,$F0,  1,  8
		.BYTE   8,$F1,  1,  0
		.BYTE   8,$F2,  1,  8
		.BYTE $80
_spr_sc8_army_shoot_blood:
		.BYTE   0,$E9,  1,  0
		.BYTE   0,$EA,  1,  8
		.BYTE   0,$EB,  1,$10
		.BYTE   0,$EC,  1,$18
		.BYTE   8,$ED,  1,  0
		.BYTE   8,$EE,  1,  8
		.BYTE   8,$EF,  1,$10
		.BYTE   8,$F0,  1,$18
		.BYTE   8,$F1,  1,$20
		.BYTE $10,$F2,  1,  0
		.BYTE $10,$F3,  1,  8
		.BYTE $10,$F4,  1,$10
		.BYTE $10,$F5,  1,$18
		.BYTE $10,$F6,  1,$20
		.BYTE $18,$F7,  1,  8
		.BYTE $18,$F8,  1,$10
		.BYTE $18,$F9,  1,$18
		.BYTE $80
;byte_392CC:									; unused unknown sprites, not CHR match here
;		.BYTE   0,$C3,  1,  1
;		.BYTE   0,$C4,  1,  9
;		.BYTE   0,$C4,$41,$11
;		.BYTE   0,$C3,$41,$19
;		.BYTE   9,$C7,  1, $D
;		.BYTE $80
;byte_392E1:
;		.BYTE   0,$C3,  1,  1
;		.BYTE   0,$C4,  1,  9
;		.BYTE   0,$C4,$41,$11
;		.BYTE   0,$C3,$41,$19
;		.BYTE   9,$C5,  1, $D
;		.BYTE $11,$C6,  1, $D
;		.BYTE $80
_spr_sc8_water_splash0:
		.BYTE $18,$F0,  3,  0					; for some reason here was a garbage tile FE
		.BYTE $18,$F1,  3,  8
		.BYTE $18,$F2,  3,$10
		.BYTE $80
_spr_sc8_water_splash1:
		.BYTE   8,$F2,  3,$18
		.BYTE $10,$F3,  3,  0
		.BYTE $10,$F4,  3,  8
		.BYTE $10,$F5,  3,$10
		.BYTE $10,$F6,  3,$18
		.BYTE $18,$F7,  3,  0
		.BYTE $18,$F8,  3,  8
		.BYTE $18,$F9,  3,$10
		.BYTE $18,$FA,  3,$18
		.BYTE $80
_spr_sc8_water_splash2:
		.BYTE   0,$F3,  3,  0
		.BYTE   0,$F2,  3,$18
		.BYTE   8,$F6,  3,  8
		.BYTE   8,$F4,  3,$10
		.BYTE $18,$F2,$43,  8
		.BYTE $18,$F2,$83,$18
		.BYTE $80

		SECTION_END 8
