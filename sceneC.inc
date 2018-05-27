
		SECTION_START C

;-----------------------------------------------
; SCENE C
;-----------------------------------------------

; original interactive script:
; 1. go on
; 2. play shooting game (A,B,SEL - fire,hide,turn)
;	- shoot 7 enemies (jump 3.)
;	x get shot (game over, restart SCENE C)
;	x wait to long (game over, restart SCENE C)
; 3. dodge
; 3.x run or hide (game over, restart SCENE C-3.)
; 4. jump on (jump SCENE D)
; 4.x run or hide (game over, restart SCENE C-3.)

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sceneC_subs:
		JSR		_sC_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_50A88
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_sC_sub00_clear
		SW_PTR	_sC_sub01_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_generic_menu_input
		SW_PTR	_sC_menu_handlers
		SW_PTR	_sC_sub05_drainage0_draw
		SW_PTR	_sC_sub06_drainage0_mus_msg
		SW_PTR	_sC_sub02_drainage0_menu_loop
		SW_PTR	_sC_sub08_drainage1_draw
		SW_PTR	_sC_sub09_drainage1_msg
		SW_PTR	_sC_sub0A_ambush_draw
		SW_PTR	_sC_sub0B_ambush_mus_msg
		SW_PTR	_sC_sub0C_ambush_menu_loop
		SW_PTR	_sC_sub0D_nt1_clear
		SW_PTR	_sC_sub20_sgame_start_draw
		SW_PTR	_sC_sub18_sgame_init
		SW_PTR	_sC_sub19_sgame_loop
		SW_PTR	_sC_sub21_sgame_is_over_draw	; redraw for game over only
		SW_PTR	_sC_sub1A_sgame_is_over_msgs
		SW_PTR	_sC_sub1E_hover_approach_anim0
		SW_PTR	_sC_sub1E_hover_approach_anim1
		SW_PTR	_sC_sub1E_hover_approach_anim2
		SW_PTR	_sC_sub0F_hover_approach_menu_loop
		SW_PTR	_sC_sub10_sewer_wall_menu_loop
		SW_PTR	_sC_sub17_clear
		SW_PTR	_sC_sub11_kaneda_jump_draw
		SW_PTR	_sC_sub12_kaneda_jump_snd_msg
		SW_PTR	_sC_sub13_kaneda_hover_draw
		SW_PTR	_sC_sub14_kaneda_hover_msg
		SW_PTR	_sC_sub15_get_on_hover_draw
		SW_PTR	_sC_sub16_get_on_hover_msg
		SW_PTR	_sC_sub22_hover_approach_game_over_msg
		SW_PTR	_sC_sub23_hover_approach_game_over
		SW_PTR	_sC_sub1D_behind_us_game_over
		SW_PTR	_sC_sub1B_game_over_msg
		SW_PTR	_sC_sub1C_game_over
locret_50A88:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub00_clear:
		LDA		#1
		STA		_spr0_overflow_mode_flag
		SW_NXT	_sC_sub05_drainage0_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub05_drainage0_draw:
		SW_NXT	_sC_sub06_drainage0_mus_msg
		TLM5	$21,$1C,$32

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub06_drainage0_mus_msg:
		JSR		_snd_drainage_water_noise0
		SW_NXT	_sC_sub02_drainage0_menu_loop
		MSG_M
		MSG		_scC_msg00
		MSG		_scC_msg01
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub02_drainage0_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_50B01
		SW_RET	_sC_sub02_drainage0_menu_loop
		SW_NXT	_generic_menu_input
		LDA		#0
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default2
		JMP		_menu_draw_request
locret_50B01:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub08_drainage1_draw:
		SW_NXT	_sC_sub09_drainage1_msg
		TLM5	$21,$1C,$33

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub09_drainage1_msg:
		JSR		_snd_drainage_hover_flyby
		SW_FADE	_sC_sub0A_ambush_draw
		MSG_M
		MSG		_scC_msg04
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub0A_ambush_draw:
		SW_NXT	_sC_sub0B_ambush_mus_msg
		TLM4	$22,$1D,$34

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub0B_ambush_mus_msg:
		JSR		_snd_drainage_hover_motor
		SW_NXT	_sC_sub0C_ambush_menu_loop
		MSG_1	_scC_msg05

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub0C_ambush_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_50BB6
		SW_RET	_sC_sub0C_ambush_menu_loop
		SW_NXT	_generic_menu_input
		LDA		#1
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default2
		JMP		_menu_draw_request
locret_50BB6:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub0D_nt1_clear:
		SW_NXT	_sC_sub20_sgame_start_draw
		LDA		#1
		STA		_forbid_sub_cur_backup_trigger
		JMP		_clear_nt1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub10_sewer_wall_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_50C15
		SW_RET	_sC_sub10_sewer_wall_menu_loop
		SW_NXT	_generic_menu_input
		LDA		#3
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default3
		JMP		_menu_draw_request
locret_50C15:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub11_kaneda_jump_draw:
		SW_NXT	_sC_sub12_kaneda_jump_snd_msg
		LDA		#0
		STA		_scene_spr_overlay_idx
		ICON2	$24,$1F,$36

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub12_kaneda_jump_snd_msg:
		JSR		_snd_kaneda_hover_jump_up
		SW_FADE	_sC_sub13_kaneda_hover_draw
		LDA		#$13
		JMP		_delay							; rld is different now

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub13_kaneda_hover_draw:
		SW_NXT	_sC_sub14_kaneda_hover_msg
		ICON0	$24,$1F,$37

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub14_kaneda_hover_msg:
		SW_FADE	_sC_sub15_get_on_hover_draw
		MSG_M
		MSG		_scC_msg0F
		MSG		_scC_msg08
		MSG		_scC_msg10
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub15_get_on_hover_draw:
		SW_NXT	_sC_sub16_get_on_hover_msg
		ICON1	$24,$1F,$38

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub16_get_on_hover_msg:
		SW_FADE	_sC_sub01_next_scene
		MSG_M
		MSG		_scC_msg11
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub17_clear:
		SW_NXT	_sC_sub11_kaneda_jump_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub1A_sgame_is_over_msgs:
		LDA		#0
		STA		_scene_spr_overlay_idx
		SW_NXT	_sC_sub1E_hover_approach_anim0
		MSG_M
		MSG		_scC_msg09
		MSG		_scC_msg0D
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub1E_hover_approach_anim0:
		SW_NXT	_sC_sub1E_hover_approach_anim1
		LDA		#2
		STA		_scene_spr_overlay_idx
		LDA		#1
		STA		_sgame_enemy_active_flag
		LDA		#$80
		STA		_sgame_enemy_x_pos
		LDA		#$50
		STA		_sgame_enemy_y_pos
		LDA		#0
		STA		_scene_anim_idx+1
		LDA		#4
		JMP		_delay

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub1E_hover_approach_anim1:
		SW_NXT	_sC_sub1E_hover_approach_anim2
		LDA		#$80
		STA		_sgame_enemy_x_pos
		LDA		#$50
		STA		_sgame_enemy_y_pos
		LDA		#2
		STA		_scene_anim_idx+1
		LDA		#4
		JMP		_delay

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub1E_hover_approach_anim2:
		SW_NXT	_sC_sub0F_hover_approach_menu_loop
;		LDA		#_sC_sub21_sgame_is_over_draw_sidx
;		STA		_scene_sub_idx_pass				; hacky way to correct password generation
		LDA		#$80
		STA		_sgame_enemy_x_pos
		LDA		#$50
		STA		_sgame_enemy_y_pos
		LDA		#4
		STA		_scene_anim_idx+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub0F_hover_approach_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_50BF9
;		SW_RET	_sC_sub1E_hover_approach_anim2	; since we should not return here actually
		SW_NXT	_generic_menu_input				; after pass is entered, we need to hack like that
		SW_RET	_sC_sub0F_hover_approach_menu_loop
		LDA		#2
		STA		_scene_menu_idx
		JSR		_sC_menu_init2
		JMP		_menu_draw_request
locret_50BF9:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub21_sgame_is_over_draw:
		SW_NXT	_sC_sub1A_sgame_is_over_msgs
		BNE		_sC_tlm35_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub20_sgame_start_draw:
		SW_NXT	_sC_sub18_sgame_init
		LDA		#1
		STA		_forbid_sub_cur_backup_trigger

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_tlm35_draw:
		TLM4	$23,$1E,$35

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub22_hover_approach_game_over_msg:
		SW_NXT	_sC_sub23_hover_approach_game_over
		MSG_M
		MSG		_scC_D_13_16_msg90
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub1D_behind_us_game_over:
		SW_NXT	_sC_sub1B_game_over_msg
		MSG_M
		MSG		_scC_msg12
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub1B_game_over_msg:
		SW_NXT	_sC_sub1C_game_over
		MSG_M
		MSG		_scC_D_13_16_msg90
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub23_hover_approach_game_over:
		LDY		#_sC_sub21_sgame_is_over_draw_sidx
		BNE		_sC_game_over

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub1C_game_over:
		LDY		#0								; always zero

; !FALLTHROUGH!

_sC_game_over:
		LDX		#$C
		JMP		_game_over_dead_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub01_next_scene:
		LDA		#0
		STA		_spr0_overflow_mode_flag
		JMP		_next_scene

;-----------------------------------------------
; SCENE C SHOOTING MINI-GAME ROUTINES
;-----------------------------------------------

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub18_sgame_init:
		LDA		#1
		STA		_scene_spr_overlay_idx
		SW_NXT	_sC_sub19_sgame_loop
		LDA		#1
		STA		_nmi_ppu_sgame_head_draw_req	; disable kaneda's head
		LDA		#$80
		STA		_tmp_x_pos
		LDA		#$40
		STA		_tmp_y_pos
		LDA		#0
		STA		_sgame_enemy_active_flag
		STA		_sgame_enemy_bullet_active
		STA		_sgame_kaneda_bullet_active
		STA		_sgame_face_direction
;		STA		_sgame_attack_direction			; never changes here
		STA		_sgame_behind_us_counter
		LDA		#1
		STA		_sgame_shoot_enable
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sub19_sgame_loop:
		LDA		_sgame_turn_around_flag
		BNE		loc_50CFB
		JSR		_sC_sgame_behind_us_countdown
		JSR		_sC_sgame_enemy_handler
		JSR		_sC_sgame_enemy_bullet_handler
		JSR		_sgame_kaneda_bullet_handler	; common routine
		JSR		_sgame_cursor_input				; common as well
		JSR		_sC_sgame_turn_around_input
		JSR		_sC_sgame_kaneda_hit_detect
		JSR		_sC_sgame_enemy_hit_detect
		JMP		_sC_sgame_kaneda_hide_input
loc_50CFB:
		LDA		_scroll_x_shadow
		CLC
		ADC		#$10
		STA		_scroll_x_shadow
		LDA		_scroll_x_shadow+1
		ADC		#0
		STA		_scroll_x_shadow+1
		CMP		#2
		BCC		locret_50D1D
		LDA		#0
		STA		_scroll_x_shadow
		STA		_scroll_x_shadow+1
		STA		_sgame_turn_around_flag
		LDA		#1
		STA		_scene_spr_overlay_idx
		INC		_sgame_face_direction
locret_50D1D:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sgame_behind_us_countdown:
		LDA		_sgame_face_direction			; test if we faced the enemy
		AND		#1
;		STA		word_0							; var is always 0, no need to test it
;		LDA		_sgame_attack_direction
;		AND		#1
;		CMP		word_0
		BEQ		loc_5150A
		INC		_sgame_behind_us_counter		; if we turn back to the enemy
		LDA		_sgame_behind_us_counter
		CMP		#$FF
		BCC		locret_5150F
		SW_NXT	_sC_sub1D_behind_us_game_over	; do game over
		RTS
loc_5150A:
		LDA		#0
		STA		_sgame_behind_us_counter
locret_5150F:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sgame_enemy_handler:
		LDA		_sgame_enemy_active_flag
		CMP		#2
		BCS		loc_511E5						; test if explosion state
		JSR		_sC_sgame_enemy_start
		JSR		_sC_sgame_enemy_main_timer
		JSR		_sC_sgame_enemy_spr_animate
		JSR		_sC_sgame_enemy_pos_calc
		JMP		_sC_sgame_enemy_bullet_start
loc_511E5:
		INC		_sgame_enemy_active_flag
		CMP		#$10
		BCC		locret_51200					; explosion delay
		LDA		#0
		STA		_sgame_enemy_active_flag
		INC		_scene_states+1
		LDA		_scene_states+1
		CMP		#7
		BCC		locret_51200					; total 7 to shoot
		SW_NXT	_sC_sub1A_sgame_is_over_msgs	; game complete
locret_51200:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sgame_enemy_start:
		LDA		_sgame_face_direction			; test if we faced the enemy
		AND		#1
;		STA		word_0							; no need to test with always zero
;		LDA		_sgame_attack_direction
;		AND		#1
;		CMP		word_0
		BNE		locret_5123E
		LDA		_sgame_enemy_active_flag
		BNE		locret_5123E					; one enemy at a time
		LDA		_rand
		AND		#$1F
		BNE		locret_5123E					; random delay
		INC		_sgame_enemy_active_flag		; enable enemy
		LDA		#$20
		STA		_sgame_enemy_main_timer			; enemy t = [20..00]
		LDA		_rand
		AND		#$F0							; _rand here has 1F bits cleared (see above)
		STA		_tmp_direction_x0				; enemy dir_x = rand & E0 [00,20..E0]
		AND		#$70							; enemy dir_y = dir_x & 70 [00, 20..60]
		STA		_tmp_direction_y0
;		LDA		#0								; unused hi bits of vars
;		STA		_tmp_direction_x0+1
;		STA		byte_529
;		STA		_tmp_direction_y0+1
		JSR		_snd_drainage_hover_flyby		; overwrites some channels of hover motor noise
locret_5123E:									; game continues with the rest of it with no restore
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sgame_enemy_main_timer:
		LDA		_sgame_enemy_active_flag
		BEQ		locret_51267					; if enemy is active
		LDA		_frames_counter					; every 4 frames
		AND		#3
		BNE		locret_51267
		LDA		_sgame_enemy_main_timer			; do main enemy state counter
		SEC										; t = t - 1
		SBC		#1
		STA		_sgame_enemy_main_timer
		BCS		locret_51267
		LDA		#0
		STA		_sgame_enemy_active_flag		; if zero, then it fly out of range
		INC		_sgame_face_direction			; as well switch the attack direction
locret_51267:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sgame_enemy_spr_animate:
		LDX		#0
loc_5126C:
		LDA		byte_5127D,X
		CMP		_sgame_enemy_main_timer			; scale enemy sprite
		BCC		loc_51279
		INX
		CPX		#4
		BCC		loc_5126C
loc_51279:
		STX		_scene_anim_idx+1
		RTS
byte_5127D:
		.BYTE $1A,$12, $C,  6

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sgame_enemy_pos_calc:
		LDA		_sgame_enemy_active_flag
		BNE		loc_51287
		RTS
loc_51287:
		LDA		_tmp_direction_x0
		SEC
		SBC		#$80
		BCC		loc_51291
		EOR		#$FF
loc_51291:
		STA		word_0+1
		LDA		#0
		STA		word_2
		LDA		_sgame_enemy_main_timer
		LSR
		BNE		loc_5129F
		LDA		#1
loc_5129F:
		STA		word_2+1
		LDA		#0
		STA		byte_4
		JSR		_div16
		LDA		_tmp_direction_x0
		BMI		loc_512B7
		LDA		#$80
		SEC
		SBC		word_0+1
		BCS		loc_512C1
		BCC		.enemy_pass_away
loc_512B7:
		LDA		word_0+1
		CLC
		ADC		#$80
		BCS		.enemy_pass_away
loc_512C1:
		STA		_sgame_enemy_x_pos				; x = 128+(2*sign(dir_x)*abs(dir_x-128))/t
		LDA		_tmp_direction_y0
		STA		word_0+1
		LDA		#0
		STA		word_2
		LDA		_sgame_enemy_main_timer
		LSR
		BNE		loc_512D5
		LDA		#1
loc_512D5:
		STA		word_2+1
		LDA		#0
		STA		byte_4
		JSR		_div16
		LDA		#$70
		SEC
		SBC		_sgame_enemy_main_timer
		BCC		.enemy_pass_away
		SEC
		SBC		word_0+1
		BCC		.enemy_pass_away
		STA		_sgame_enemy_y_pos				; y = 112-(2*dir_y)/t-t
		RTS
.enemy_pass_away:
		INC		_sgame_face_direction
		LDA		#0
		STA		_sgame_enemy_active_flag
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sgame_enemy_bullet_start:
		LDA		_sgame_enemy_main_timer
		CMP		#$18							; shot when at some point in ait
		BNE		locret_51373
		LDA		_sgame_enemy_bullet_active		; do this only once
		BNE		locret_51373
		INC		_sgame_enemy_bullet_active		; active enemy bullet
		LDA		_tmp_direction_x0				; bullet dir_x = enemy dir_x
		STA		_tmp_direction_x1+1
		LDA		_sgame_enemy_main_timer			; bullet t = current enemy t (init t = 18)
		STA		_sgame_enemy_bullet_main_timer
		LDA		_tmp_direction_y0
		STA		_tmp_direction_y1+1				; hi-nibble fixed point 8.8
;		LDA		#0								; unused here as well
;		STA		byte_52C
;		STA		byte_532
;		STA		byte_52F
		LDA		_tmp_direction_x1+1				; calc movement delta for bullet
		BMI		loc_51332
		LDA		#$80
		SEC
		SBC		_tmp_direction_x1+1
		JMP		loc_51335
loc_51332:
		SEC
		SBC		#$80
loc_51335:
		STA		word_2
		LDA		#0
		STA		word_0+1
		LDA		#$28
		STA		word_2+1
		LDA		#0
		STA		byte_4
		JSR		_div16
		LDA		word_0+1
		STA		_tmp_delta_x1					; enemy bullet delta_x = (128 - dir_x)/40 (fixed point 8.8!)
		LDA		_tmp_direction_x1+1
		AND		#$80
		ORA		word_2
		STA		_tmp_delta_x1+1
		LDA		_tmp_direction_y1+1				; enemy bullet delta_y = (dir_y/40) (fixed point 8.8!)
		STA		word_2
		LDA		#0
		STA		word_0+1
		LDA		#$28
		STA		word_2+1
		LDA		#0
		STA		byte_4
		JSR		_div16
		LDA		word_0+1
		STA		_tmp_delta_y1
		LDA		word_2
		STA		_tmp_delta_y1+1
locret_51373:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sgame_enemy_bullet_handler:
		LDA		_sgame_enemy_bullet_active		; added test if active,
		BNE		.dfsdf							; previously were counting indefinitely
		RTS
.dfsdf:
		JSR		_sC_sgame_enemy_bullet_move
		LDA		_tmp_direction_y1				; fixed point subtract dir_y = dir_y - delta_y
		SEC
		SBC		_tmp_delta_y1
		STA		_tmp_direction_y1
		LDA		_tmp_direction_y1+1
		SBC		_tmp_delta_y1+1
		STA		_tmp_direction_y1+1
		LDA		_frames_counter
		AND		#1
		BNE		loc_5139C
		LDA		_sgame_enemy_bullet_main_timer	; bullet timer decrease
		SEC
		SBC		#1
		STA		_sgame_enemy_bullet_main_timer
		BCS		loc_5139C
		LDA		#0
		STA		_sgame_enemy_bullet_active
loc_5139C:
		LDX		#0
		LDA		_sgame_enemy_bullet_main_timer	; scale enemy bullet
		CMP		#$C
		BCS		.34342
		INX
.34342:
		STX		_scene_anim_idx+2
		LDA		_tmp_direction_x1+1
		BMI		loc_513F8
		LDA		#$80
		SEC
		SBC		_tmp_direction_x1+1
		JMP		loc_513FB
loc_513F8:
		SEC
		SBC		#$80
loc_513FB:
		STA		word_0+1
		LDA		#0
		STA		word_2
		LDA		_sgame_enemy_bullet_main_timer
		LSR
		BNE		loc_51409
		LDA		#1
loc_51409:
		STA		word_2+1
		LDA		#0
		STA		byte_4
		JSR		_div16
		LDA		_tmp_direction_x1+1
		BMI		loc_5141F
		LDA		#$80
		SEC
		SBC		word_0+1
		JMP		loc_51424
loc_5141F:
		LDA		word_0+1
		CLC
		ADC		#$80
loc_51424:
		STA		_sgame_enemy_bullet_x_pos		; bullet x pos = 128-2*(128-dir_x)/t)
		LDA		_tmp_direction_y1+1
		STA		word_0+1
		LDA		#0
		STA		word_2
		LDA		_sgame_enemy_bullet_main_timer
		LSR
		BNE		loc_51438
		LDA		#1
loc_51438:
		STA		word_2+1
		LDA		#0
		STA		byte_4
		JSR		_div16
		LDA		#$70
		SEC
		SBC		_sgame_enemy_bullet_main_timer
		SEC
		SBC		word_0+1
		STA		_sgame_enemy_bullet_y_pos		; bullet y pos = 112-2*(dir_y)/t
locret_5139D:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sgame_enemy_bullet_move:
		LDA		_tmp_delta_x1+1					; fixed point subtract dir_x = dir_x - delta_x
		BMI		loc_513B6
		LDA		_tmp_direction_x1
		CLC
		ADC		_tmp_delta_x1
		STA		_tmp_direction_x1
		LDA		_tmp_direction_x1+1
		ADC		_tmp_delta_x1+1
		STA		_tmp_direction_x1+1
		RTS
loc_513B6:
		LDA		_tmp_direction_x1
		SEC
		SBC		_tmp_delta_x1
		STA		_tmp_direction_x1
		LDA		_tmp_delta_x1+1
		AND		#$7F
		STA		word_0
		LDA		_tmp_direction_x1+1
		SBC		word_0
		STA		_tmp_direction_x1+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sgame_turn_around_input:
		LDA		_pads+1
		AND		#4
		BEQ		locret_51467
		LDA		#1
		STA		_sgame_turn_around_flag
		LDA		#0
		STA		_scene_spr_overlay_idx
		STA		_sgame_enemy_active_flag
		STA		_sgame_enemy_bullet_active
		STA		_sgame_kaneda_bullet_active
locret_51467:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sgame_kaneda_hit_detect:
		LDA		_sgame_kaneda_hidden_flag		; check if kaneda is hiding
		BNE		locret_514E9
		LDA		_sgame_enemy_bullet_active		; and bullet is in air
		BEQ		locret_514E9
		LDA		_sgame_enemy_bullet_main_timer	; then check the last trajectory portion
		CMP		#4
		BCS		locret_514E9
		LDA		_tmp_direction_x1+1
		CMP		#$78
		BCC		locret_514E9					; and wait for particular position of bullet
		CMP		#$88
		BCS		locret_514E9
		SW_FADE	_sC_sub1B_game_over_msg			; then kaneda is dead
locret_514E9:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sgame_enemy_hit_detect:
		LDA		_sgame_enemy_active_flag
		BEQ		locret_514C2
		CMP		#2
		BCS		locret_514C2
		LDA		_sgame_kaneda_bullet_active
		BEQ		locret_514C2
		LDA		_sgame_enemy_x_pos
		SEC
		SBC		_sgame_kaneda_bullet_x_pos
		BCS		loc_514A2
		EOR		#$FF
loc_514A2:
		CMP		#4
		BCS		locret_514C2
		LDA		_sgame_enemy_y_pos
		SEC
		SBC		_sgame_kaneda_bullet_y_pos
		BCS		loc_514B1
		EOR		#$FF
loc_514B1:
		CMP		#6
		BCS		locret_514C2
		JSR		_snd_sgame_enemy_explode
		LDA		#2
		STA		_sgame_enemy_active_flag
		LDA		#0
		STA		_sgame_kaneda_bullet_active
locret_514C2:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_sgame_kaneda_hide_input:
		LDA		_pads							; always hid, while button is held
		AND		#2
		BEQ		loc_51479
		LDA		#2
		STA		_nmi_ppu_sgame_head_draw_req	; draw empty
		LDA		#1
		STA		_sgame_kaneda_hidden_flag		; hidden flag is on
		RTS
loc_51479:
;		LDA		#0
;		STA		_sgame_kaneda_hidden_delay		; not using here
		LDA		#1
		STA		_nmi_ppu_sgame_head_draw_req	; draw head
		LDA		#0
		STA		_sgame_kaneda_hidden_flag
		RTS

;-----------------------------------------------
; END OF SGAME ROUTINES
;-----------------------------------------------

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_menu_init2:
		LDA		_scene_flags					; throw weapon to hide throw option
		AND		#1
		BNE		loc_50E04
		JMP		_scene_menu_init_default4
loc_50E04:
		JMP		_scene_menu_init_default3

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_menu_handlers:
		JSR		_menu_switch
		.WORD _sC_menu0
		.WORD _sC_menu1
		.WORD _sC_menu2
		.WORD _sC_menu3
_sC_menu0:
		.WORD _sC_menu0_talk
		.WORD _sC_menu0_go_on
_sC_menu1:
		.WORD _sC_menu1_run
		.WORD _sC_menu1_take
_sC_menu2:
		.WORD _sC_menu2_run
		.WORD _sC_menu2_hide
		.WORD _sC_menu2_dodge
		.WORD _sC_menu2_throw
_sC_menu3:
		.WORD _sC_menu3_run
		.WORD _sC_menu3_hide
		.WORD _sC_menu3_jump_on

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_menu0_talk:
		SW_NXT	_sC_sub02_drainage0_menu_loop
		LDA		_scene_flags
		AND		#2
		BNE		loc_50E79
		LDA		_scene_flags
		ORA		#2
		STA		_scene_flags
		MSG_M
		MSG		_scC_msg02
		MSG		_scC_msg06
		MSG_EOL
loc_50E79:
		MSG_1	_scC_msg01

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_menu0_go_on:
		SW_FADE	_sC_sub08_drainage1_draw
		MSG_1	_scC_msg03

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_menu1_run:
		SW_NXT	_sC_sub0C_ambush_menu_loop
		MSG_1	_scC_15_msgA5

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_menu1_take:
		SW_FADE	_sC_sub0D_nt1_clear
		LDA		#0
		STA		_scene_states+1					; a number of hovers shot here
		MSG_M
		MSG		_scC_msg07
		MSG		_scC_msg13
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_menu2_run:
		SW_NXT	_sC_sub22_hover_approach_game_over_msg
		MSG_M
		MSG		_scC_15_msgA5
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_menu2_hide:
		SW_NXT	_sC_sub22_hover_approach_game_over_msg
		MSG_M
		MSG		_scC_msg0B
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_menu2_dodge:
		SW_NXT	_sC_sub10_sewer_wall_menu_loop
		MSG_1	_scC_msg0C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_menu2_throw:
		LDA		_scene_flags
		ORA		#1
		STA		_scene_flags
		SW_NXT	_sC_sub0F_hover_approach_menu_loop
		MSG_1	_scC_msg0A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_menu3_run:
		SW_NXT	_sC_sub22_hover_approach_game_over_msg
		MSG_M
		MSG		_scC_15_msgA5
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_menu3_hide:
		SW_NXT	_sC_sub22_hover_approach_game_over_msg
		MSG_M
		MSG		_scC_msg0B
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_menu3_jump_on:
		SW_FADE	_sC_sub17_clear
		MSG_M
		MSG		_scC_msg0E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_sC_spr_overlay1
		SW_PTR	_sC_spr_overlay2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_spr_overlay1:
		LDA		_tmp_y_pos
		STA		word_2
		LDA		_tmp_x_pos
		STA		word_2+1
		SPR0EX	_scr_scC_aim_cursor
		LDA		_sgame_kaneda_bullet_active		; do kaneda's bullet
		BEQ		locret_5100B
		LDA		_sgame_kaneda_bullet_y_pos
		STA		word_2
		LDA		_sgame_kaneda_bullet_x_pos
		STA		word_2+1
		LDA		_scene_anim_idx+3				; kaneda's projectile idx
		SPR0SWEX	off_5100C
locret_5100B:
		LDA		_sgame_enemy_bullet_active		; do enemy's bullet
		BEQ		locret_50FBD
		LDA		_sgame_enemy_bullet_y_pos
		STA		word_2
		LDA		_sgame_enemy_bullet_x_pos
		STA		word_2+1
		LDA		_scene_anim_idx+2				; enemy's projectile idx
		SPR0SWEX	off_5100C
locret_50FBD:
		JMP		_sC_spr_overlay2
off_5100C:
		.WORD _spr_scC_small_projectile
		.WORD _spr_scC_large_projectile

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sC_spr_overlay2:
		LDX		_sgame_enemy_active_flag
		BEQ		locret_50FA8
		LDA		_sgame_enemy_y_pos
		STA		word_2
		LDA		_sgame_enemy_x_pos
		STA		word_2+1
		CPX		#1
		BNE		loc_50F8C
		LDA		_scene_anim_idx+1
		SPR0SWEX	off_50FA9
		RTS
loc_50F8C:
		LDA		_scene_anim_idx+1
		SPR0SWEX	off_50FB3
locret_50FA8:
		RTS
off_50FA9:
		.WORD _spr_scC_hover_aproach0
		.WORD _spr_scC_hover_aproach1
		.WORD _spr_scC_hover_aproach2
		.WORD _spr_scC_hover_aproach3
		.WORD _spr_scC_hover_aproach4
off_50FB3:
		.WORD _spr_scC_explosion0
		.WORD _spr_scC_explosion1
		.WORD _spr_scC_explosion1
		.WORD _spr_scC_explosion2
		.WORD _spr_scC_explosion2

_spr_scC_hover_aproach0:
		.BYTE   0,$C0,  1,$FC
		.BYTE   8,$C1,  1,$FC
		.BYTE $80
_spr_scC_hover_aproach1:
		.BYTE $F4,$C2,  2,$F8
		.BYTE $F4,$C2,$42,  0
		.BYTE $FC,$C3,  1,$F8
		.BYTE $FC,$C3,$41,  0
		.BYTE   4,$C4,  1,$F8
		.BYTE   4,$C4,$41,  0
		.BYTE $80
_spr_scC_hover_aproach2:
		.BYTE $E8,$C5,  1,$FC
		.BYTE $F0,$C6
		.BYTE   1,$F4,$F0,$C7
		.BYTE   2,$FC,$F0,$C6
		.BYTE $41,  4,$F8,$C8
		.BYTE   1,$F4,$F8,$C9
		.BYTE   1,$FC,$F8,$C8
		.BYTE $41,  4,  0,$CA
		.BYTE   1,$F4,  0,$CB
		.BYTE   1,$FC,  0,$CA
		.BYTE $41,  4,  8,$CC
		.BYTE   1,$F4,  8,$CD
		.BYTE   1,$FC,  8,$CC
		.BYTE $41,  4,$80
_spr_scC_hover_aproach3:
		.BYTE $E4,$CE,  2,$F8
		.BYTE $E4,$CE,$42,  0
		.BYTE $EC,$CF,  2,$F8
		.BYTE $EC,$CF,$42,  0
		.BYTE $F4,$D0,  1,$F0
		.BYTE $F4,$D1,  1,$F8
		.BYTE $F4,$D1,$41,  0
		.BYTE $F4,$D0,$41,  8
		.BYTE $FC,$D2,  1,$F0
		.BYTE $FC,$D3,  1,$F8
		.BYTE $FC,$D4,  1,  0
		.BYTE $FC,$D2,$41,  8
		.BYTE   4,$D5,  1,$F0
		.BYTE   4,$D6,  1,$F8
		.BYTE   4,$D6,$41,  0
		.BYTE   4,$D5,$41,  8
		.BYTE  $C,$D7,  1,$F0
		.BYTE  $C,$D8,  1,$F8
		.BYTE  $C,$D8,$41,  0
		.BYTE  $C,$D7,$41,  8
		.BYTE $80
_spr_scC_hover_aproach4:
		.BYTE $E0,$D9,  2,$F4
		.BYTE $E0,$DA,  2,$FC
		.BYTE $E0,$D9,$42,  4
		.BYTE $E8,$DB,  2,$F4
		.BYTE $E8,$DC,  2,$FC
		.BYTE $E8,$DB,$42,  4
		.BYTE $F0,$DD,  1,$EC
		.BYTE $F0,$DE,  1,$F4
		.BYTE $F0,$DF,  1,$FC
		.BYTE $F0,$DE,$41,  4
		.BYTE $F0,$DD,$41, $C
		.BYTE $F8,$E0,  1,$EC
		.BYTE $F8,$E1,  1,$F4
		.BYTE $F8,$E2,  1,$FC
		.BYTE $F8,$E3,  1,  4
		.BYTE $F8,$E0,$41, $C
		.BYTE   0,$E4,  1,$EC
		.BYTE   0,$E5,  1,$F4
		.BYTE   0,$E6,  1,$FC
		.BYTE   0,$E7,  1,  4
		.BYTE   0,$E4,$41, $C
		.BYTE   8,$E8,  1,$EC
		.BYTE   8,$E9,  1,$F4
		.BYTE   8,$EA,  1,$FC
		.BYTE   8,$E9,$41,  4
		.BYTE   8,$E8,$41, $C
		.BYTE $10,$EB,  1,$EC
		.BYTE $10,$EC,  1,$F4
		.BYTE $10,$ED,  1,$F8
		.BYTE $10,$EC,$41,  4
		.BYTE $10,$EB,$41, $C
		.BYTE $80
_scr_scC_aim_cursor:
		.BYTE $F8,$EE,  3,$F8
		.BYTE $F8,$EE,$43,  0
		.BYTE   0,$EF,  3,$F8
		.BYTE   0,$EF,$43,  0
		.BYTE $80
_spr_scC_small_projectile:
		.BYTE $FC,$FE,  3,$FC
		.BYTE $80
_spr_scC_large_projectile:
		.BYTE $FC,$FF,  3,$FC
		.BYTE $80
_spr_scC_explosion0:
		.BYTE $FC,$F0,  3,$FC
		.BYTE $80
_spr_scC_explosion1:
		.BYTE $F4,$F1,  3,$F0
		.BYTE $F4,$F2,  3,$F8
		.BYTE $F4,$F2,$43,  0
		.BYTE $F4,$FD,$83,  8
		.BYTE $FC,$F5,  3,$F0
		.BYTE $FC,$F6,  3,$F8
		.BYTE $FC,$F7,  3,  0
		.BYTE $FC,$F5,$C3,  8
		.BYTE   4,$FA,  3,$F0
		.BYTE   4,$F2,$83,$F8
		.BYTE   4,$F2,$C3,  0
		.BYTE   4,$F9,$83,  8
		.BYTE $80
_spr_scC_explosion2:
		.BYTE $F0,$F1,  3,$EC
		.BYTE $F0,$F2,  3,$F4
		.BYTE $F0,$F3,  3,$FC
		.BYTE $F0,$F4,  3,  4
		.BYTE $F8,$F5,  3,$EC
		.BYTE $F8,$F6,  3,$F4
		.BYTE $F8,$F7,  3,$FC
		.BYTE $F8,$F8,  3,  4
		.BYTE $F8,$F9,  3, $C
		.BYTE   0,$FA,  3,$EC
		.BYTE   0,$FB,  3,$F4
		.BYTE   0,$F7,  3,$FC
		.BYTE   0,$F7,$43,  4
		.BYTE   0,$F5,$C3, $C
		.BYTE   8,$FC,  3,$F4
		.BYTE   8,$F3,$C3,$FC
		.BYTE   8,$F2,$C3,  4
		.BYTE   8,$FD,  3, $C
		.BYTE $80

		SECTION_END C
