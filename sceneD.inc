
		SECTION_START D

;-----------------------------------------------
; SCENE D
;-----------------------------------------------

; original interactive script:
; 1. play shooting game (A,B - fire,dodge)
;	- shoot 7 enemies (jump SCENE E)
;	x get straight shot (game over, restart SCENE D)

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sceneD_subs:
		JSR		_sD_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_B187D
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_sD_sub00_clear
		SW_PTR	_sD_sub01_next_scene
		SW_PTR	_sD_sub07_fade_out_reload_scene	; no menu, no handlers here
		SW_PTR	_sD_sub04_large_hover_nt1_draw
		SW_PTR	_sD_sub05_large_hover_nt0_draw
		SW_PTR	_sD_sub06_large_hover_mus_msg
		SW_PTR	_sD_sub08_tunnels_draw
		SW_PTR	_sD_sub09_sgame_init
		SW_PTR	_sD_sub0C_sgame_loop
		SW_PTR	_sD_sub0E_1_enemy_killed_msg
		SW_PTR	_sD_sub0E_3_enemies_killed_msg
		SW_PTR	_sD_sub10_sgame_complete_msg
		SW_PTR	_sD_sub12_medium_draw
		SW_PTR	_sD_sub13_medium_mus_msg
		SW_PTR	_sD_sub14_large_hover_nt0_redraw
		SW_PTR	_sD_sub15_large_hover_msg2
		SW_PTR	_sD_sub16_room_A_draw0
		SW_PTR	_sD_sub17_room_A_draw1
		SW_PTR	_sD_sub0A_room_A_draw2
		SW_PTR	_sD_sub0A_room_A_msg
		SW_PTR	_sD_sub0D_game_over_msg
		SW_PTR	_sD_sub11_game_over_start

locret_B187D:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub00_clear:
;		LDA		#$D
;		STA		_scene_idx_pass
;		LDA		#_sD_sub00_clear_sidx
;		STA		_scene_sub_save_pass
		LDA		#0
		STA		_scene_states+1
		LDA		#1
		STA		_spr0_overflow_mode_flag
		SW_NXT	_sD_sub04_large_hover_nt1_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub04_large_hover_nt1_draw:
		SW_NXT	_sD_sub05_large_hover_nt0_draw
		LDA		#$39
		JMP		_tlm_nt1_draw_mode4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub05_large_hover_nt0_draw:
		SW_NXT	_sD_sub06_large_hover_mus_msg

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_tlm39_draw:
		TLM4	$25,$20,$39

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub06_large_hover_mus_msg:
		JSR		_snd_fly_on_hover
		SW_NXT	_sD_sub07_fade_out_reload_scene
		SW_RLD	_sD_sub08_tunnels_draw
		LDA		#2
		STA		_scene_spr_overlay_idx			; bg blinking animation
		MSG_M
		MSG		_scD_msg00
		MSG		_scD_msg01
		MSG		_scD_msg0E
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub07_fade_out_reload_scene:
		LDA		#0								; disable overlay before fade out here
		STA		_scene_spr_overlay_idx			; because of blinking animation overlays
		JMP		_fade_out_reload_scene

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub08_tunnels_draw:
		SW_NXT	_sD_sub09_sgame_init
		TLM4	$55,$21,$3A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub0E_1_enemy_killed_msg:
		SW_NXT	_sD_sub0C_sgame_loop
		MSG_1	_scD_msg02

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub0E_3_enemies_killed_msg:
		SW_NXT	_sD_sub0C_sgame_loop
		MSG_M
		MSG		_scD_msg03
		MSG		_scD_msg04
		MSG		_scD_msg05
		MSG		_scD_msg06
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub10_sgame_complete_msg:
		SW_NXT	_sD_sub07_fade_out_reload_scene
		SW_RLD	_sD_sub12_medium_draw
		MSG_1	_scD_msg07

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub12_medium_draw:
		LDA		#4
		STA		_scene_spr_overlay_idx
		SW_NXT	_sD_sub13_medium_mus_msg
		EXJMP	_sF_tlm9C_draw					; defined in system bank

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub13_medium_mus_msg:
		JSR		_snd_akira_flashback_suddenly
		SW_NXT	_sD_sub07_fade_out_reload_scene
		SW_RLD	_sD_sub14_large_hover_nt0_redraw
		MSG_M
		MSG		_scD_msg0C
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub14_large_hover_nt0_redraw:
		SW_NXT	_sD_sub15_large_hover_msg2
		JMP		_sD_tlm39_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub15_large_hover_msg2:
		JSR		_snd_fly_on_hover
		SW_NXT	_sD_sub07_fade_out_reload_scene
		SW_RLD	_sD_sub16_room_A_draw0
		LDA		#2
		STA		_scene_spr_overlay_idx
		MSG_M
		MSG		_scD_msg0D
		MSG		_scD_msg08
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub16_room_A_draw0:
		SW_NXT	_sD_sub17_room_A_draw1
		TLM5	$25,$22,$9A						; shouldn't be delay here?

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub17_room_A_draw1:
		SW_NXT	_sD_sub0A_room_A_draw2
		TLM5	$25,$22,$9B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub0A_room_A_draw2:
		SW_NXT	_sD_sub0A_room_A_msg
		TLM5	$25,$22,$3B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub0A_room_A_msg:
		SW_FADE	_sD_sub01_next_scene			; previously drawn unfaded
		MSG_M
		MSG		_scD_msg09
		MSG		_scD_msg0A
		MSG		_scD_E_13_msg91
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub01_next_scene:
		LDA		#0
		STA		_spr0_overflow_mode_flag		; disable sprite overflow flag
		JMP		_next_scene

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub0D_game_over_msg:
		SW_NXT	_sD_sub11_game_over_start
		MSG_1	_scC_D_13_16_msg90

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub11_game_over_start:
		JSR		_scene_vars_init
		LDX		#$D
		LDY		#0								; always zero
		JMP		_game_over_dead_start

;-----------------------------------------------
; SCENE C SHOOTING MINI-GAME ROUTINES
;-----------------------------------------------

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub09_sgame_init:
		SW_NXT	_sD_sub0C_sgame_loop
		LDA		#$80
		STA		_tmp_x_pos						; init cursor pos
		LDA		#$40
		STA		_tmp_y_pos
		LDA		#0
		STA		_scroll_x_shadow+1
		STA		_sgame_enemy_active_flag
		STA		_sgame_enemy_bullet_active
		STA		_sgame_kaneda_bullet_active
;		STA		_sgame_face_direction			; unused here
;		STA		_sgame_attack_direction			; unused here
;		STA		_sgame_behind_us_counter		; unused here
		LDA		#1
		STA		_sgame_shoot_enable				; force shooting
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sub0C_sgame_loop:
		LDA		#1
		STA		_scene_spr_overlay_idx			; restore possible overlay change here
		JSR		_sD_sgame_enemy_handler
		JSR		_sD_sgame_enemy_bullet_start
		JSR		_sD_sgame_enemy_bullet_handler
		JSR		_sgame_cursor_input
		JSR		_sgame_kaneda_bullet_handler
		LDA		_sgame_kaneda_hidden_flag
		BNE		locret_B1DE7
		LDA		_sgame_enemy_bullet_active		; test enemy bullet hit
		BEQ		locret_B1DE7
		LDA		_sgame_enemy_bullet_y_pos		; some bullets couldn't harm you
		CMP		#$78							; because they path doesn't match
		BCC		locret_B1DE7					; with targer position
		CMP		#$80
		BCS		locret_B1DE7
		LDA		_sgame_enemy_bullet_x_pos
		CMP		#$7C
		BCC		locret_B1DE7
		CMP		#$84
		BCS		locret_B1DE7
		SW_NXT	_sD_sub07_fade_out_reload_scene	; hit detected - game over
		SW_RLD	_sD_sub0D_game_over_msg
locret_B1DE7:
		JSR		_sD_sgame_kaneda_hide_input
		LDA		_sgame_enemy_active_flag		; if enemy active
		BEQ		locret_B1DAA
;		CMP		#2								; no need here, there aren't "explosions" of soldiers
;		BCS		locret_B1DAA
		LDA		_sgame_kaneda_bullet_active		; and kaneda bullet is on
		BEQ		locret_B1DAA
		LDA		_sgame_enemy_x_pos
		SEC
		SBC		_sgame_kaneda_bullet_x_pos		; test collision
		BCS		loc_B1D69
		EOR		#$FF
loc_B1D69:
		CMP		#4
		BCS		locret_B1DAA
		LDA		_sgame_enemy_y_pos
		SEC
		SBC		_sgame_kaneda_bullet_y_pos
		BCS		loc_B1D78
		EOR		#$FF
loc_B1D78:
		CMP		#6
		BCS		locret_B1DAA					; 8x12 hit zone, no matter of spr size
		JSR		_snd_enemy_hit					; hit sound
		LDA		#0
		STA		_sgame_enemy_active_flag
		STA		_sgame_enemy_bullet_active		; disable enemy bullet too...
		STA		_sgame_kaneda_bullet_active
		LDA		#3
		STA		_scene_spr_overlay_idx			; overlay without enemies, but with gun
		INC		_scene_states+1					; increase hit count
		LDA		_scene_states+1
		CMP		#1
		BEQ		loc_B1DAB
		CMP		#3
		BEQ		loc_B1DB1
		CMP		#5
		BEQ		loc_B1DB7
		SW_NXT	_sD_sub0C_sgame_loop
locret_B1DAA:
		RTS
loc_B1DAB:
		SW_NXT	_sD_sub0E_1_enemy_killed_msg
		RTS
loc_B1DB1:
		SW_NXT	_sD_sub0E_3_enemies_killed_msg
		RTS
loc_B1DB7:
		SW_NXT	_sD_sub10_sgame_complete_msg
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sgame_kaneda_hide_input:
		LDA		_sgame_kaneda_hidden_delay		; avoid collision, for a while, disable input if already hidden
		BNE		loc_B1DFC
		LDA		_pads+1
		AND		#2
		BEQ		locret_B1E0E					; start hiding for a few seconds when button pressed
		LDA		#1
		STA		_sgame_kaneda_hidden_flag
		STA		_sgame_kaneda_hidden_delay
		RTS
loc_B1DFC:
		INC		_sgame_kaneda_hidden_delay
		LDA		_sgame_kaneda_hidden_delay
		CMP		#$30
		BCC		locret_B1E0E
		LDA		#0
		STA		_sgame_kaneda_hidden_flag		; restore normal state
		STA		_sgame_kaneda_hidden_delay
locret_B1E0E:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sgame_enemy_handler:
		LDA		_sgame_enemy_active_flag
		BNE		locret_B1CEC
		LDA		_rand
		AND		#$F
		BNE		locret_B1CEC
		INC		_sgame_enemy_active_flag
		LDA		#0
		STA		_scene_anim_idx					; enemy init
		LDA		#$20
		STA		_tmp_direction_y0
		LDA		_rand
		AND		#$7F
		CLC
		ADC		#$40
		STA		_tmp_direction_x0
locret_B1CEC:
		LDA		_tmp_direction_y0				; enemy spr anim
		LDX		#0
loc_B1CB7:
		CMP		byte_B1CC5,X
		BCC		loc_B1CC1
		INX
		CPX		#5
		BCC		loc_B1CB7
loc_B1CC1:
		STX		_scene_anim_idx
		JSR		_sD_sgame_enemy_move
;		LDA		_frames_counter
;		AND		#0								; lolwut?
;		BNE		locret_B1D05
		LDA		_tmp_direction_y0
		CLC
		ADC		#1
		STA		_tmp_direction_y0
		CMP		#$98
		BCC		locret_B1D05
		LDA		#0
		STA		_sgame_enemy_active_flag
locret_B1D05:
		RTS

byte_B1CC5:
		.BYTE $40,$48,$50,$60,$78

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sgame_enemy_bullet_start:
		LDA		_tmp_direction_y0
		CMP		#$30
		BNE		locret_B1E4F
		LDA		_sgame_enemy_bullet_active
		BNE		locret_B1E4F
		INC		_sgame_enemy_bullet_active
		LDA		_tmp_direction_x0
		STA		_tmp_direction_x1+1
		LDA		_tmp_direction_y0
		STA		_tmp_direction_y1+1
		LDA		_tmp_direction_x1+1
		SEC
		SBC		#$80
		BCS		loc_B1E34
		EOR		#$FF
loc_B1E34:
		STA		word_2
		LDA		#0
		STA		word_0+1
		LDA		#$38
		STA		word_2+1
		LDA		#0
		STA		byte_4
		JSR		_div16							; enemy bullet delta x = dir_x/56 (fixed point 8.8)
		LDA		word_0+1
		STA		_tmp_delta_x1
		LDA		word_2
		STA		_tmp_delta_x1+1
locret_B1E4F:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sgame_enemy_move:
		LDA		_tmp_direction_x0
		SEC
		SBC		#$80
		BCS		loc_B1D10
		EOR		#$FF
loc_B1D10:
		STA		word_2
		LDA		#0
		STA		word_0+1
		LDA		#$70
		STA		word_2+1
		LDA		#0
		STA		byte_4
		JSR		_div16
		LDA		word_0+1
		STA		word_0
		LDA		word_2
		STA		word_0+1
		LDA		_tmp_direction_y0
		SEC
		SBC		#$10
		STA		word_2
		JSR		_mul16
		LDA		_tmp_direction_x0
		BMI		loc_B1D41
		LDA		#$80
		SEC
		SBC		byte_5
		JMP		loc_B1D46
loc_B1D41:
		LDA		byte_5
		CLC
		ADC		#$80
loc_B1D46:
		STA		_sgame_enemy_x_pos
		LDA		_tmp_direction_y0
		STA		_sgame_enemy_y_pos
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sgame_enemy_bullet_handler:
		JSR		_sD_sgame_enemy_bullet_x_move
		LDA		_tmp_direction_y1+1				; y move simple
		CLC
		ADC		#2
		STA		_tmp_direction_y1+1
		CMP		#$80
		BCC		locret_B1EA2
		LDA		#0
		STA		_sgame_enemy_bullet_active		; out of screen
locret_B1EA2:
		LDX		#1
		LDA		_tmp_direction_y1+1				; very simple case
		CMP		#$50
		BCS		.34344
		DEX
.34344:
		STX		_scene_anim_idx+2				; animate sprite (previously unused, always 0)
		LDA		_tmp_direction_x1+1
		SEC
		SBC		#$80
		BCS		loc_B1EB3
		EOR		#$FF
loc_B1EB3:
		STA		word_2
		LDA		#0
		STA		word_0+1
		LDA		#$70
		STA		word_2+1
		LDA		#0
		STA		byte_4
		JSR		_div16
		LDA		word_0+1
		STA		word_0
		LDA		word_2
		STA		word_0+1
		LDA		_tmp_direction_y1+1
		SEC
		SBC		#$10
		STA		word_2
		JSR		_mul16
		LDA		_tmp_direction_x1+1
		BMI		loc_B1EE4
		LDA		#$80
		SEC
		SBC		byte_5
		JMP		loc_B1EE9
loc_B1EE4:
		LDA		byte_5
		CLC
		ADC		#$80
loc_B1EE9:
		STA		_sgame_enemy_bullet_x_pos
		LDA		_tmp_direction_y1+1
		STA		_sgame_enemy_bullet_y_pos
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_sgame_enemy_bullet_x_move:
		LDA		_tmp_direction_x1+1
		BMI		loc_B1E7C
		LDA		_tmp_direction_x1
		CLC
		ADC		_tmp_delta_x1
		STA		_tmp_direction_x1
		LDA		_tmp_direction_x1+1
		ADC		_tmp_delta_x1+1
		STA		_tmp_direction_x1+1
		RTS
loc_B1E7C:
		LDA		_tmp_direction_x1
		SEC
		SBC		_tmp_delta_x1
		STA		_tmp_direction_x1
		LDA		_tmp_direction_x1+1
		SBC		_tmp_delta_x1+1
		STA		_tmp_direction_x1+1
		RTS

;-----------------------------------------------
; END OF SGAME ROUTINES
;-----------------------------------------------

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_sD_spr_overlay1
		SW_PTR	_pal_blink_animate
		SW_PTR	_sD_spr_overlay3
		EXOFS	_sF_spr_overlay8				; defined in system bank

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_spr_overlay1:
		JSR		_bg_palette_effect
		LDA		_tmp_y_pos
		STA		word_2
		LDA		_tmp_x_pos
		STA		word_2+1
		SPR0EX	_spr_scD_cursor
		LDA		_sgame_enemy_bullet_active
		BEQ		locret_B1B2E
		LDA		_sgame_enemy_bullet_y_pos
		STA		word_2
		LDA		_sgame_enemy_bullet_x_pos
		STA		word_2+1
		LDA		_scene_anim_idx+2
		SPR0SWEX	off_B1B2F
locret_B1B2E:
		LDA		_sgame_kaneda_bullet_active
		BEQ		locret_B1B54
		LDA		_sgame_kaneda_bullet_y_pos
		STA		word_2
		LDA		_sgame_kaneda_bullet_x_pos
		STA		word_2+1
		LDA		_scene_anim_idx+3
		SPR0SWEX	off_B1B2F
locret_B1B54:
		LDA		_sgame_enemy_active_flag
		BEQ		locret_B1B00
		LDA		_sgame_enemy_y_pos
		STA		word_2
		LDA		_sgame_enemy_x_pos
		STA		word_2+1
		LDA		_scene_anim_idx
		SPR1SW	off_B1B01						; used once here!
locret_B1B00:

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_spr_overlay1_B:
		LDA		_sgame_kaneda_hidden_flag
		BEQ		loc_B1B6E
		SPR0J	_spr_scD_hover_rifle,$68,$68
loc_B1B6E:
		SPR0J	_spr_scD_hover_rifle,$68,$78

off_B1B01:
		.WORD _spr_scD_soldier0
		.WORD _spr_scD_soldier1
		.WORD _spr_scD_soldier2
		.WORD _spr_scD_soldier3
		.WORD _spr_scD_soldier4
		.WORD _spr_scD_soldier5
off_B1B2F:
		.WORD _spr_scD_shot_small
		.WORD _spr_scD_shot_large

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sD_spr_overlay3:
		JSR		_sD_spr_overlay1_B
; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_bg_palette_effect:
		LDA		_frames_counter
		AND		#3
		BNE		loc_B1AA5
		INC		_tmp_cnt0
		LDA		_tmp_cnt0
		CMP		#3
		BCC		loc_B1AA5
		LDA		#0
		STA		_tmp_cnt0
loc_B1AA5:
		LDA		_tmp_cnt0
		ASL
		ASL
		TAX
		LDA		_pal_bg_list,X
		STA		_pal_buf+5
		LDA		_pal_bg_list+1,X
		STA		_pal_buf+6
		LDA		_pal_bg_list+2,X
		STA		_pal_buf+7
		RTS
_pal_bg_list:
		.BYTE   0,  0, $F, $F
		.BYTE   0, $F,  0, $F
		.BYTE  $F,  0,  0						; only first 3 bytes is used

_spr_scD_soldier0:
		.BYTE $F8,$80,  2,$FC
		.BYTE   0,$BF,  2,$FC
		.BYTE   8,$82,  2,$FC
		.BYTE $10,$83,  2,$FC
		.BYTE $80
_spr_scD_soldier1:
		.BYTE $F0,$84,  2,$FC
		.BYTE $F8,$85,  2,$FC
		.BYTE $F8,$86,  2,  4
		.BYTE   0,$87,  2,$FC
		.BYTE   0,$88,  2,  4
		.BYTE   8,$89,  2,$FC
		.BYTE   8,$8A,  2,  4
		.BYTE $10,$8B,  2,$FC
		.BYTE $10,$8C,  2,  4
		.BYTE $18,$8D,  2,$FC
		.BYTE $80
_spr_scD_soldier2:
		.BYTE $F0,$8E,  2,$FC
		.BYTE $F8,$8F,  2,$F8
		.BYTE $F8,$90,  2,  0
		.BYTE   0,$91,  2,$F8
		.BYTE   0,$92,  2,  0
		.BYTE   8,$93,  2,$F8
		.BYTE   8,$94,  2,  0
		.BYTE $10,$95,  2,$F8
		.BYTE $10,$96,  2,  0
		.BYTE $18,$97,  2,  0
		.BYTE $80
_spr_scD_soldier3:
		.BYTE $E8,$98,  2,$FC
		.BYTE $F0,$99,  2,$F8
		.BYTE $F0,$9A,  2,  0
		.BYTE $F8,$9B,  2,$F8
		.BYTE $F8,$9C,  2,  0
		.BYTE   0,$9D,  2,$F8
		.BYTE   0,$9E,  2,  0
		.BYTE   8,$9F,  2,$F8
		.BYTE   8,$A0,  2,  0
		.BYTE $10,$A1,  2,$F8
		.BYTE $10,$A2,  2,  0
		.BYTE $18,$A3,  2,  0
		.BYTE $80
_spr_scD_soldier4:
		.BYTE $E8,$A4,  2,$F8
		.BYTE $E8,$A5,  2,  0
		.BYTE $F0,$A6,  2,$F8
		.BYTE $F0,$A7,  2,  0
		.BYTE $F8,$A8,  2,$F0
		.BYTE $F8,$A9,  2,$F8
		.BYTE $F8,$AA,  2,  0
		.BYTE   0,$AB,  2,$F0
		.BYTE   0,$AC,  2,$F8
		.BYTE   0,$AD,  2,  0
		.BYTE   8,$AE,  2,$F8
		.BYTE   8,$AF,  2,  0
		.BYTE $10,$B0,  2,$F0
		.BYTE $10,$B1,  2,$F8
		.BYTE $10,$B2,  2,  0
		.BYTE $80
_spr_scD_soldier5:
		.BYTE $E0,$B3,  2,$F8
		.BYTE $E0,$B4,  2,  0
		.BYTE $E8,$B5,  2,$F8
		.BYTE $E8,$B6,  2,  0
		.BYTE $F0,$B7,  2,$F0
		.BYTE $F0,$B8,  2,$F8
		.BYTE $F0,$B9,  2,  0
		.BYTE $F0,$BA,  2,  8
		.BYTE $F8,$BB,  2,$F0
		.BYTE $F8,$BC,  2,$F8
		.BYTE $F8,$BD,  2,  0
		.BYTE $F8,$BE,  2,  8
		.BYTE $80
_spr_scD_cursor:
		.BYTE $F8,$F0,  3,$F8
		.BYTE $F8,$F0,$43,  0
		.BYTE   0,$F1,  3,$F8
		.BYTE   0,$F1,$43,  0
		.BYTE $80
_spr_scD_shot_small:
		.BYTE $FC,$EE,  3,$FC
		.BYTE $80
_spr_scD_shot_large:
		.BYTE $FC,$EF,  3,$FC
		.BYTE $80
_spr_scD_hover_rifle:
		.BYTE   0,$F4,  2,  4
		.BYTE   8,$F5,  2,  4
		.BYTE $10,$F5,  2,  4
		.BYTE $80

		SECTION_END D
