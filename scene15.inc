		SECTION_START 15

;-----------------------------------------------
; SCENE 15
;-----------------------------------------------

; BRANCH A {
; 	OPTION A {
; 		1. hit
; 		1.x dash/pray/throw (game over, restart SCENE 15, BRANCH A)
;		2. play shooting game (A - fire)
; 			- hit tetsuo's chest (jump SCENE 16-66, ENDING A)
; 			x hit any other point (game over, restart SCENE 15, BRANCH A)
;	}
; 	OPTION B {
; 		1. look
; 		2. ponder
; 		3. look
;		OPTION B-1 {
; 			1. throw->right
; 			1.x dash/take/crouch/yell (game over, restart SCENE 15, BRANCH A, OPTION B)
; 			2. hit
;			3. play shooting game (A - fire)
; 				- hit tetsuo's chest (jump SCENE 16-66, ENDING A)
; 				x hit tetsuo's body or miss (game over, restart SCENE 15, OPTION A-B)
; 				x hit mirror (game over, restart SCENE 15, OPTION A-B)
;		}
;		OPTION B-2 {
; 			1. throw->left
; 			1.x dash/take/crouch/yell (game over, restart SCENE 15, OPTION A-B)
; 			2. hit
;			3. play shooting game (A - fire)
; 				- hit tetsuo's chest (jump SCENE 16-66, ENDING A)
; 				x hit tetsuo's body or miss (game over, restart SCENE 15, OPTION A-B)
; 				- hit mirror to the left (jump SCENE 15, BRANCH B)
;		}
;	}
; }
; BRANCH B {
; 	OPTION A {
; 		1. look
;		OPTION A-1 {
; 			1. jump (jump SCENE 16-00, ENDING F)
;		}
;		OPTION A-2 {
; 			1. run (jump SCENE 16-50, ENDING D)
;		}
;		OPTION A-3 {
; 			1. hit (jump SCENE 16-70, ENDING E)
;		}
;	}
; 	OPTION B {
; 		1. attack (jump SCENE 16-40, ENDING C)
;	}
; }

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene15_subs:
		JSR		_s15_spr_overlay_set
		LDA		_draw_state_idx
		BEQ		locret_80045
		JMP		locret_80046
locret_80045:
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s15_sub00_clear
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_generic_menu_input
		SW_PTR	_s15_menu_handlers
		SW_PTR	_s15_sub05_laser_icon1_draw0
		SW_PTR	_s15_sub06_laser_msg0
		SW_PTR	_s15_sub08_laser_icon1_clear0
		SW_PTR	_s15_sub09_laser_icon2_draw
		SW_PTR	_s15_sub0A_laser_msg1
		SW_PTR	_s15_sub0B_tetsuo_icon0_draw
		SW_PTR	_s15_sub0C_tetsuo_msg
		SW_PTR	_s15_sub0D_kaneda_fight_draw
		SW_PTR	_s15_sub0E_kaneda_fight_msg
		SW_PTR	_s15_sub02_kaneda_fight_menu_loop0
		SW_PTR	_s15_optionA_sgame_loop
		SW_PTR	_s15_optionA_sgame_game_over_msg
		SW_PTR	_s15_optionA_sgame_game_over
		SW_PTR	_s15_sub0F_kaneda_fight_menu_loop1
		SW_PTR	_s15_optionB_sgame_loop
		SW_PTR	_s15_optionB_sgame_game_over_msg
		SW_PTR	_s15_optionB_sgame_game_over
		SW_PTR	_s15_sub49_miss_hit
		SW_PTR	_s15_sub37_tetsuo_body_hit
		SW_PTR	_s15_sub36_tetsuo_chest_hit
		SW_PTR	_s15_sub48_s16_sub66_warp
		SW_PTR	_s15_sub35_mirror_hit
		SW_PTR	_s15_sub10_clear						; BRANCH B
		SW_PTR	_s15_sub11_tetsuo_right_arm_icon1_draw
		SW_PTR	_s15_sub12_tetsuo_right_arm_msg
		SW_PTR	_s15_sub13_kaneda_bike_draw
		SW_PTR	_s15_sub14_kaneda_bike_msg
		SW_PTR	_s15_sub15_clear
		SW_PTR	_s15_sub16_laser_icon1_draw1
		SW_PTR	_s15_sub17_laser_msg1
		SW_PTR	_s15_sub18_tetsuo_grow_arm_draw
		SW_PTR	_s15_sub19_tetsuo_grow_arm_msg
		SW_PTR	_s15_sub1A_tetsuo_mutate_draw
		SW_PTR	_s15_sub1B_tetsuo_mutate_msg
		SW_PTR	_s15_sub39_tetsuo_mutate_menu_loop
		SW_PTR	_s15_sub20_tetsuo_mutate_look_msg0		; OPTION A
		SW_PTR	_s15_sub1E_tetsuo_mutate_look_msg1
		SW_PTR	_s15_sub21_kids_pray_draw
		SW_PTR	_s15_sub22_kids_pray_msg
		SW_PTR	_s15_sub23_clear
		SW_PTR	_s15_sub24_kids_icon0_draw
		SW_PTR	_s15_sub25_kids_icon1_draw
		SW_PTR	_s15_sub26_kids_icon2_draw
		SW_PTR	_s15_sub27_kids_icons_msg
		SW_PTR	_s15_sub28_akira_draw
		SW_PTR	_s15_sub28_akira_delay
		SW_PTR	_s15_sub2A_akira_with_kids_draw
		SW_PTR	_s15_sub2B_akira_with_kids_msg
		SW_PTR	_s15_sub2C_clear
		SW_PTR	_s15_sub2D_explosion_icon1_draw
		SW_PTR	_s15_sub2E_explosion_icon1_delay
		SW_PTR	_s15_sub2F_tetsuo_fears_draw
		SW_PTR	_s15_sub30_tetsuo_fears_msg
		SW_PTR	_s15_sub3A_tetsuo_fear_menu_loop
		SW_PTR	_s15_sub31_kaneda_jump_into_light_draw	; OPTION A-1
		SW_PTR	_s15_sub32_kaneda_jump_into_light_msg
		SW_PTR	_s15_sub3C_clear
		SW_PTR	_s15_sub3E_big_light_icon1_draw0
		SW_PTR	_s15_sub3F_big_light_msg
		SW_PTR	_s15_sub40_big_light_icon1_draw1
		SW_PTR	_s15_sub41_big_light_icon1_msg
		SW_PTR	_s15_sub42_s16_sub50_clear_warp			; OPTION A-2
		SW_PTR	_s15_sub43_s16_sub70_warp				; OPTION A-3
		SW_PTR	_s15_sub3B_s16_sub41_tetsuo_attaked_msg_warp	; OPTION B

locret_80046:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub00_clear:
		SW_NXT	_s15_sub05_laser_icon1_draw0
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub05_laser_icon1_draw0:
		SW_NXT	_s15_sub06_laser_msg0
		LDA		#1
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_icon6D_draw:
		ICON1	$40,$42,$6D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub06_laser_msg0:
		SW_FADE	_s15_sub08_laser_icon1_clear0
		MSG_M
		MSG		_sc15_msg00
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub08_laser_icon1_clear0:
		SW_NXT	_s15_sub09_laser_icon2_draw
		ICON1_CLEAR

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub09_laser_icon2_draw:
		SW_NXT	_s15_sub0A_laser_msg1
		LDA		#2
		STA		_scene_spr_overlay_idx
		ICON2	$40,$42,$6C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub0A_laser_msg1:
		SW_FADE	_s15_sub0B_tetsuo_icon0_draw
		MSG_M
		MSG		_sc15_msg01
		MSG		_sc15_msg02
		MSG		_sc15_msg1F
		MSG		_sc5_6_15_msgAB
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub0B_tetsuo_icon0_draw:
		SW_NXT	_s15_sub0C_tetsuo_msg
		LDA		#3
		STA		_scene_spr_overlay_idx
		ICON0	$40,$42,$6B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub0C_tetsuo_msg:
		SW_FADE	_s15_sub0D_kaneda_fight_draw
		MSG_M
		MSG		_sc15_msg9D
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub0D_kaneda_fight_draw:
		SW_NXT	_s15_sub0E_kaneda_fight_msg
		LDA		#$40
		STA		_tmp_direction_y0
		LDA		#$80
		STA		_tmp_direction_x0
		LDA		#4
		STA		_scene_spr_overlay_idx
		LDA		#0
		STA		_scene_anim_idx					; set kaneda sprite standing
		TLM4	$57,$43,$6E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub0E_kaneda_fight_msg:
		JSR		_snd_energic_something_happening_pulse
		SW_NXT	_s15_sub02_kaneda_fight_menu_loop0
		MSG_1	_sc15_msg04

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub02_kaneda_fight_menu_loop0:
		LDA		_pads+1
		AND		#1
		BEQ		locret_80105
		SW_RET	_s15_sub02_kaneda_fight_menu_loop0
		LDA		#0
		JSR		_s15_menus_init
		JMP		_menu_draw_request
locret_80105:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub10_clear:
		SW_NXT	_s15_sub11_tetsuo_right_arm_icon1_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub11_tetsuo_right_arm_icon1_draw:
		SW_NXT	_s15_sub12_tetsuo_right_arm_msg
		LDA		#0
		STA		_scene_spr_overlay_idx
		ICON1	$41,$6F,$6F

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub12_tetsuo_right_arm_msg:
		JSR		_snd_hit_splash
		SW_FADE	_s15_sub13_kaneda_bike_draw
		MSG_M
		MSG		_sc15_msgAC
		MSG		_scF_12_13_15_msg93
		MSG		_sc15_msg16
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub13_kaneda_bike_draw:
		SW_NXT	_s15_sub14_kaneda_bike_msg
		LDA		#$A
		STA		_scene_spr_overlay_idx
		TLM5	$6E,$70,$A3

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub14_kaneda_bike_msg:
		JSR		_snd_kaneda_bike_dash
		SW_FADE	_s15_sub15_clear
		MSG_M
		MSG		_sc15_msg17
		MSG		_sc15_msg18
		MSG		_sc15_msg19
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub15_clear:
		SW_NXT	_s15_sub16_laser_icon1_draw1
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub16_laser_icon1_draw1:
		SW_NXT	_s15_sub17_laser_msg1
		LDA		#1
		STA		_scene_spr_overlay_idx
		JMP		_s15_icon6D_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub17_laser_msg1:
		SW_FADE	_s15_sub18_tetsuo_grow_arm_draw
		MSG_M
		MSG		_sc15_msg2B
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub18_tetsuo_grow_arm_draw:
		SW_NXT	_s15_sub19_tetsuo_grow_arm_msg
		LDA		#6
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_tlm72_draw:
		TLM4	$42,$44,$72

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub19_tetsuo_grow_arm_msg:
		JSR		_apu_reset
		JSR		_snd_mutation_beat
		SW_FADE	_s15_sub1A_tetsuo_mutate_draw
		MSG_M
		MSG		_sc6_15_msg89
		MSG		_sc15_msg1A
		MSG		_sc15_msg20
		MSG		_scF_12_13_15_msg93
		MSG		_sc15_msg1B
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub1A_tetsuo_mutate_draw:
		SW_NXT	_s15_sub1B_tetsuo_mutate_msg
		LDA		#5
		STA		_scene_spr_overlay_idx
		LDA		#0
		STA		_tmp_cnt0
		STA		_tmp_cnt2
		TLM5	$71,$74,$75

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub1B_tetsuo_mutate_msg:
		SW_NXT	_s15_sub39_tetsuo_mutate_menu_loop
		MSG_M
		MSG		_sc15_msg1C
		MSG		_sc15_msg15
		MSG		_sc15_msg1D
		MSG		_sc6_15_msg88
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub39_tetsuo_mutate_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_80504
		SW_RET	_s15_sub02_kaneda_fight_menu_loop0
		LDA		#3
		JSR		_s15_menus_init
		JMP		_menu_draw_request
locret_80504:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub20_tetsuo_mutate_look_msg0:
		SW_NXT	_s15_sub1E_tetsuo_mutate_look_msg1
		MSG_M
		MSG		_sc15_16_msgC5
		MSG		_sc15_16_msgC6
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub1E_tetsuo_mutate_look_msg1:				; here is overlay animation started
		SW_FADE	_s15_sub21_kids_pray_draw
		MSG_M
		MSG		_sc15_msg21
		MSG		_sc15_msg22
		MSG		_sc15_msg23
		MSG		_sc5_6_15_msgAB
		MSG		_sc15_16_msgC7
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub21_kids_pray_draw:
		SW_NXT	_s15_sub22_kids_pray_msg

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_tlm76_draw:
		LDA		#0
		STA		_scene_spr_overlay_idx
		TLM4	$44,$46,$76

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub22_kids_pray_msg:
		JSR		_apu_reset
		JSR		_snd_kids_praying
		SW_FADE	_s15_sub23_clear
		MSG_M
		MSG		_sc15_16_msgC8
		MSG		_sc15_msg25
		MSG		_sc15_msg24
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub23_clear:
		SW_NXT	_s15_sub24_kids_icon0_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub24_kids_icon0_draw:
		SW_NXT	_s15_sub25_kids_icon1_draw		; draw icon silently. while pal is blank
		ICON0EX	$77

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub25_kids_icon1_draw:
		SW_NXT	_s15_sub26_kids_icon2_draw
		ICON1EX	$78

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub26_kids_icon2_draw:
		SW_NXT	_s15_sub27_kids_icons_msg
		LDA		#7
		STA		_scene_spr_overlay_idx
		ICON2	$45,$46,$79						; last icon drawn with pal load

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub27_kids_icons_msg:
		SW_FADE	_s15_sub28_akira_draw
		MSG_M
		MSG		_sc15_msg27
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub28_akira_draw:
		SW_NXT	_s15_sub28_akira_delay
		LDA		#0
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_tlm7A_draw:
		TLM5	$46,$47,$7A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub28_akira_delay:
		SW_FADE	_s15_sub2A_akira_with_kids_draw
		LDA		#$10
		JMP		_delay

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub2A_akira_with_kids_draw:
		SW_NXT	_s15_sub2B_akira_with_kids_msg
		TLM4	$48,$47,$7B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub2B_akira_with_kids_msg:
		SW_FADE	_s15_sub2C_clear
		MSG_M
		MSG		_sc15_msg29
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub2C_clear:
		SW_NXT	_s15_sub2D_explosion_icon1_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub2D_explosion_icon1_draw:
		SW_NXT	_s15_sub2E_explosion_icon1_delay

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_icon7D_draw:
		ICON1	$48,$48,$7D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub2E_explosion_icon1_delay:
		JSR		_apu_reset
		JSR		_snd_explosion
		SW_FADE	_s15_sub2F_tetsuo_fears_draw
		LDA		#$20							; too short delay for me
		JMP		_delay

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub2F_tetsuo_fears_draw:
		SW_NXT	_s15_sub30_tetsuo_fears_msg

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_tlm9F_draw:
		TLM4	$5C,$5C,$9F

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub30_tetsuo_fears_msg:
		JSR		_snd_hard_noise
		JSR		_snd_near_stadium_without_beat
		SW_NXT	_s15_sub3A_tetsuo_fear_menu_loop
		MSG_M
		MSG		_sc15_msg9D
		MSG		_sc5_6_15_msgAB
		MSG		_sc15_msg1E
		MSG		_sc15_msg2D
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub3A_tetsuo_fear_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_80518
		SW_RET	_s15_sub02_kaneda_fight_menu_loop0
		LDA		#4
		JSR		_s15_menus_init
		JMP		_menu_draw_request
locret_80518:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub31_kaneda_jump_into_light_draw:
		SW_NXT	_s15_sub32_kaneda_jump_into_light_msg

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_tlm9E_draw:
		TLM5	$5B,$5B,$9E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub32_kaneda_jump_into_light_msg:
		SW_FADE	_s15_sub3C_clear
		MSG_M
		MSG		_sc2_13_15_16_msg82
		MSG		_sc15_msg36
		MSG		_sc15_msg37
		MSG		_sc15_msg38
		MSG		_sc15_msg2A
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub3C_clear:
		SW_NXT	_s15_sub3E_big_light_icon1_draw0
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
;_s15_sub3D_big_light_icon1_draw:				; never seen, because the next picture
;		SW_NXT	_s15_sub3E_big_light_icon1_draw0; replacing it
;		ICON1EX	$7C								; it seems we have another bug here

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub3E_big_light_icon1_draw0:				; so, logically, we have three stage of light
		SW_NXT	_s15_sub3F_big_light_msg		; first one shown at the beginning of scene
		ICON1	$48,$48,$7C						; here is the second one

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub3F_big_light_msg:
		SW_FADE	_s15_sub40_big_light_icon1_draw1
		MSG_M
		MSG		_sc15_16_msgC9
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub40_big_light_icon1_draw1:
		SW_NXT	_s15_sub41_big_light_icon1_msg	; for some reason icon indexes are mangled
		ICON1	$48,$48,$7E						; 7D, 7C then 7E the right order
;		ICON1	$48,$48,$7D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub41_big_light_icon1_msg:
		SW_FADE	_next_scene
		MSG_M
		MSG		_sc15_16_msgCA
		MSG		_sc15_16_msgCB
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sgame_init:
		LDA		#8
		STA		_scene_spr_overlay_idx
		LDA		#$80
		STA		_tmp_x_pos
		LDA		#$40
		STA		_tmp_y_pos
		LDA		#1
		STA		_sgame_shoot_enable
		LDA		#0
		STA		_sgame_kaneda_bullet_active
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_optionA_sgame_loop:
		JSR		_sgame_loop_common
		BCS		locret_8067F
		SW_NXT	_s15_sub49_miss_hit
locret_8067F:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_optionB_sgame_loop:
		JSR		_sgame_loop_common
		BCS		locret_806F7					; if carry set, exit
		LDA		_tmp_direction_y1+1
		STA		word_0
		LDA		_tmp_direction_x1+1
		STA		word_0+1
		LDA		_tmp_y_pos
		STA		word_2
		LDA		_tmp_x_pos
		STA		word_2+1
		JSR		_sub16
		LDA		word_0
		CMP		#8
		BCS		loc_806F2
		LDA		word_0+1
		CMP		#8
		BCS		loc_806F2
		SW_NXT	_s15_sub35_mirror_hit
		RTS
loc_806F2:
		SW_NXT	_s15_sub49_miss_hit
locret_806F7:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sgame_loop_common:								; used twice
		LDA		_sgame_kaneda_bullet_active
		BNE		loc_80630
		JSR		_sgame_cursor_input
loc_80630:
		JSR		_sgame_kaneda_bullet_handler
		LDA		_sgame_kaneda_bullet_active
		BEQ		.break							; is bullet fired?
		LDA		_tmp_y_pos
		SEC
		SBC		_sgame_kaneda_bullet_dir_y+1
		BCC		.break							; is it hit the cross hatch?
		LDA		_tmp_direction_y0
		STA		word_0
		LDA		_tmp_direction_x0
		STA		word_0+1
		LDA		_tmp_y_pos
		STA		word_2
		LDA		_tmp_x_pos
		STA		word_2+1
		JSR		_sub16
		LDA		word_0
		CMP		#8
		BCS		loc_806B7
		LDA		word_0+1
		CMP		#8
		BCS		loc_806B7
		SW_NXT	_s15_sub36_tetsuo_chest_hit
		SEC
		RTS
loc_806B7:
		LDA		word_0
		CMP		#$20
		BCS		.continue
		LDA		word_0+1
		CMP		#8
		BCS		.continue
		SW_NXT	_s15_sub37_tetsuo_body_hit
.break:
		SEC
		RTS
.continue:
		CLC
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sub16:
		LDA		word_0
		SEC
		SBC		word_2
		BCS		loc_80703
		EOR		#$FF
loc_80703:
		STA		word_0
		LDA		word_0+1
		SEC
		SBC		word_2+1
		BCS		loc_80710
		EOR		#$FF
loc_80710:
		STA		word_0+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_optionA_sgame_game_over_msg:
		JSR		_snd_hit_splash
		SW_FADE	_s15_optionA_sgame_game_over
		MSG_M
		MSG		_sc15_msg03
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_optionA_sgame_game_over:
		JSR		_scene_vars_init
		LDX		#$15
		LDY		#0								; always 0
		JMP		_game_over_dead_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_optionB_sgame_game_over_msg:
		JSR		_snd_hit_splash
		SW_FADE	_s15_optionB_sgame_game_over
		MSG_M
		MSG		_sc15_msg03
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_optionB_sgame_game_over:
		JSR		_scene_vars_init
		LDX		#$15
		LDY		#_s15_sub0D_kaneda_fight_draw_sidx
		JMP		_game_over_dead_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub35_mirror_hit:
		JSR		_apu_reset
		JSR		_snd_mirror_hit
		LDA		_scene_flags					; wrong hand
		AND		#$10
		BNE		loc_8049A
		LDA		#2
		STA		_scene_anim_idx					; right hand wound anim
		SW_FADE	_s15_sub10_clear
		MSG_1	_sc15_msg12
loc_8049A:
		SW_FADE	_s15_optionB_sgame_game_over_msg
		MSG_M
		MSG		_sc15_msg10
		MSG		_sc15_msg08
		MSG		_sc13_15_msg9E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub0F_kaneda_fight_menu_loop1:
		LDA		_pads+1
		AND		#1
		BEQ		locret_80200
		SW_RET	_s15_sub0F_kaneda_fight_menu_loop1
		LDA		#1
		JSR		_s15_menus_init
		JMP		_menu_draw_request
locret_80200:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub36_tetsuo_chest_hit:
		JSR		_apu_reset
		JSR		_snd_hit_splash
		LDA		#1
		STA		_scene_anim_idx					; get on the knee
		SW_FADE	_s15_sub48_s16_sub66_warp
		MSG_M
		MSG		_sc13_15_msg9A
		MSG		_sc13_15_msg9B
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub37_tetsuo_body_hit:
		LDX		#_s15_optionA_sgame_game_over_msg_sidx
		LDA		_scene_flags
		AND		#8
		BEQ		loc_804D9
		LDX		#_s15_optionB_sgame_game_over_msg_sidx
loc_804D9:
		STX		_scene_sub_reload
		SW_NXT	_fade_out_reload_scene
		MSG_M
		MSG		_sc15_msg13
		MSG		_sc15_msg08
		MSG		_sc13_15_msg9E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub3B_s16_sub41_tetsuo_attaked_msg_warp:
		WARP	$16,_s16_sub41_tetsuo_attaked_msg

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub42_s16_sub50_clear_warp:
		WARP	$16,_s16_sub50_clear

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub43_s16_sub70_warp:
		WARP	$16,_s16_sub70_kaneda_jump_into_light_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub48_s16_sub66_warp:
		WARP	$16,_s16_sub66_safe_town_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_sub49_miss_hit:
		LDX		#_s15_optionA_sgame_game_over_msg_sidx
		LDA		_scene_flags
		AND		#8
		BEQ		loc_805B4
		LDX		#_s15_optionB_sgame_game_over_msg_sidx
loc_805B4:
		STX		_scene_sub_reload
		SW_NXT	_fade_out_reload_scene
		MSG_M
		MSG		_sc13_15_msg9F
		MSG		_sc15_msg08
		MSG		_sc13_15_msg9E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menus_init:
		STA		_scene_menu_idx
		SW_NXT	_generic_menu_input
		LDA		_scene_menu_idx
		SWITCH
		SW_PTR	_scene_menu_init_default6
		SW_PTR	_scene_menu_init_default5
		SW_PTR	_scene_menu_init_default2
		SW_PTR	_scene_menu_init_default2
		SW_PTR	_scene_menu_init_default3

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu_handlers:
		JSR		_menu_switch
		.WORD _s15_menu0
		.WORD _s15_menu1
		.WORD _s15_menu2
		.WORD _s15_menu3
		.WORD _s15_menu4
_s15_menu0:
		.WORD _s15_menu0_hit
		.WORD _s15_menu0_dash
		.WORD _s15_menu0_pray
		.WORD _s15_menu0_throw
		.WORD _s15_menu0_look
		.WORD _s15_menu0_ponder
_s15_menu1:
		.WORD _s15_menu1_dash
		.WORD _s15_menu1_take
		.WORD _s15_menu1_crouch
		.WORD _s15_menu1_yell
		.WORD _s15_menu1_hit
_s15_menu2:
		.WORD _s15_menu2_right
		.WORD _s15_menu2_left
_s15_menu3:
		.WORD _s15_menu3_look
		.WORD _s15_menu3_attack
_s15_menu4:
		.WORD _s15_menu4_jump
		.WORD _s15_menu4_run
		.WORD _s15_menu4_hit

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu0_hit:
		JSR		_s15_sgame_init
		SW_NXT	_s15_optionA_sgame_loop
		MSG_1	_sc13_15_msg99

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu0_dash:
		SW_FADE	_s15_optionA_sgame_game_over_msg
		MSG_M
		MSG		_sc15_msg05
		MSG		_sc15_msg06
		MSG		_sc15_msg08
		MSG		_sc13_15_msg9E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu0_pray:
		SW_FADE	_s15_optionA_sgame_game_over_msg
		MSG_M
		MSG		_sc2_15_msgA1
		MSG		_sc15_msg08
		MSG		_sc13_15_msg9E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu0_throw:
		LDA		_scene_flags
		AND		#4
		BNE		loc_8081A
		SW_FADE	_s15_optionA_sgame_game_over_msg
		MSG_M
		MSG		_sc15_msg09
		MSG		_sc15_msg08
		MSG		_sc13_15_msg9E
		MSG_WAIT
		MSG_EOL
loc_8081A:
		SW_RET	_s15_sub02_kaneda_fight_menu_loop0
		LDA		#2
		JSR		_s15_menus_init
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu0_look:
		SW_NXT	_s15_sub02_kaneda_fight_menu_loop0
		LDA		_scene_flags
		AND		#1
		BNE		loc_80840
		LDA		_scene_flags
		ORA		#1
		STA		_scene_flags
loc_8083B:
		MSG_1	_sc15_msg07
loc_80840:
		LDA		_scene_flags
		AND		#3
		CMP		#3
		BNE		loc_8083B
		LDA		_scene_flags
		ORA		#4
		STA		_scene_flags
		MSG_M
		MSG		_sc15_msg0B
		MSG		_sc15_msg0C
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu0_ponder:
		SW_NXT	_s15_sub02_kaneda_fight_menu_loop0
		LDA		_scene_flags
		ORA		#2
		STA		_scene_flags
		MSG_1	_sc15_msg0D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu1_dash:
		SW_NXT	_s15_optionB_sgame_game_over_msg
		MSG_M
		MSG		_sc15_msg05
		MSG		_sc15_msg06
		MSG		_sc15_msg08
		MSG		_sc13_15_msg9E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu1_take:
		SW_NXT	_s15_optionB_sgame_game_over_msg
		MSG_M
		MSG		_sc15_msg0F
		MSG		_sc15_msg08
		MSG		_sc13_15_msg9E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu1_crouch:
		SW_NXT	_s15_optionB_sgame_game_over_msg
		MSG_M
		MSG		_scC_15_msgA5
		MSG		_sc15_msg08
		MSG		_sc13_15_msg9E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu1_yell:
		SW_NXT	_s15_optionB_sgame_game_over
		MSG_M
		MSG		_sc11_15_msg96
		MSG		_sc15_msg08
		MSG		_sc13_15_msg9E
		MSG		_sc15_msg03
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu1_hit:
		JSR		_s15_sgame_init
		SW_NXT	_s15_optionB_sgame_loop
		MSG_1	_sc13_15_msg99

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu2_right:								; right from the viewer side!
		SW_NXT	_s15_sub0F_kaneda_fight_menu_loop1
		LDA		_scene_flags
		ORA		#$18
		STA		_scene_flags
		LDA		#$40
		STA		_tmp_direction_y1+1
		LDA		#$C0
		STA		_tmp_direction_x1+1
		MSG_1	_sc15_msg0E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu2_left:
		SW_NXT	_s15_sub0F_kaneda_fight_menu_loop1	; this is actually throw under right hand!
		LDA		_scene_flags
		ORA		#8
		STA		_scene_flags
		LDA		#$40
		STA		_tmp_direction_y1+1
		LDA		#$40
		STA		_tmp_direction_x1+1
		MSG_1	_sc15_msg0E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu3_look:
		SW_NXT	_s15_sub20_tetsuo_mutate_look_msg0
		MSG_1	_sc15_msg11

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu3_attack:
		SW_NXT	_s15_sub3B_s16_sub41_tetsuo_attaked_msg_warp
		MSG_1	_sc15_msg14

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu4_jump:
		SW_FADE	_s15_sub31_kaneda_jump_into_light_draw
		MSG_M
		MSG		_sc15_msg33
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu4_run:
		SW_FADE	_s15_sub42_s16_sub50_clear_warp
		MSG_M
		MSG		_sc15_msg34
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_menu4_hit:
		SW_FADE	_s15_sub43_s16_sub70_warp
		MSG_M
		MSG		_sc15_msg35
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s15_spr_overlay1
		SW_PTR	_s15_spr_overlay2
		SW_PTR	_s15_spr_overlay3
		SW_PTR	_s15_spr_overlay4
		SW_PTR	_s15_spr_overlay5
		SW_PTR	_s15_spr_overlay6
		SW_PTR	_s15_spr_overlay7
		SW_PTR	_s15_spr_overlay8
		EXOFS	_s6_spr_overlay4				; defined in system bank
		SW_PTR	_s15_spr_overlayA

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_spr_overlay1:
		JSR		_do_scene_anim0_pat0101			; there is no speech in this scene
		LDA		_scene_anim_idx
		SPR0JSW	off_80ADD,$60,$88
off_80ADD:
		.WORD _spr_sc15_kaneda_icon1_mouth0		; unused
		.WORD _spr_sc15_kaneda_icon1_mouth1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_spr_overlay2:
		JSR		_do_scene_anim0_pat0101			; enabled kaneda's mouth here as well
		LDA		_scene_anim_idx
		SPR0JSW	off_80B00,$28,$D0
off_80B00:
		.WORD _spr_sc15_kaneda_icon2_mouth0
		.WORD _spr_sc15_kaneda_icon2_mouth1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_spr_overlay3:
		JSR		_s15_spr_overlay2
		JSR		_do_scene_anim1_pat0101
		LDA		_scene_anim_idx+1
		SPR0JSW	off_80B23,$28,$28
off_80B23:
		.WORD _spr_sc15_tetsuo_mouth0
		.WORD _spr_sc15_tetsuo_mouth1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_spr_overlay4:
		JSR		_s15_spr_overlay4_A

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_spr_overlay4_B:
		LDA		_scene_flags
		AND		#8
		BEQ		locret_80BC6
		LDA		_tmp_direction_y1+1				; mirror position
		STA		word_2
		LDA		_tmp_direction_x1+1
		STA		word_2+1
		SPR0EX	_s15_sgame_mirror
locret_80BC6:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_spr_overlay5:
		LDA		#0
		LDX		_scene_anim_active
		BEQ		loc_809E2
		INC		_tmp_cnt0
		LDA		_tmp_cnt0
		LSR
		LSR
		LSR
		AND		#3
loc_809E2:
		SPR0SW	off_809F9,$38,$70
		LDA		#0
		LDX		_scene_sub_cur
		CPX		#_s15_sub1E_tetsuo_mutate_look_msg1_sidx
		BEQ		loc_80A11
		LDA		_tmp_cnt2
		AND		#$F
		JMP		loc_80A25
loc_80A11:
		LDA		_tmp_cnt2
		AND		#$F
		PHA
		CMP		#$F
		BEQ		loc_80A24
		LDA		_frames_counter
		AND		#$F
		BNE		loc_80A24
		INC		_tmp_cnt2
loc_80A24:
		PLA
loc_80A25:
		PHA
		PHA
		AND		#7
		SPR0SW	off_80A70,$28,$40
		PLA
		SPR0SW	off_80A80,$48,$90
		PLA
		SPR0JSW	off_80AA0,$58,$88
off_80A70:
		.WORD _spr_sc15_tetsuo_mutate0
		.WORD _spr_sc15_tetsuo_mutate1
		.WORD _spr_sc15_tetsuo_mutate2
		.WORD _spr_sc15_tetsuo_mutate3
		.WORD _spr_sc15_tetsuo_mutate3
		.WORD _spr_sc15_tetsuo_mutate3
		.WORD _spr_sc15_tetsuo_mutate3
		.WORD _spr_sc15_tetsuo_mutate3
off_80A80:
		.WORD _spr_sc15_tetsuo_mutate0
		.WORD _spr_sc15_tetsuo_mutate1
		.WORD _spr_sc15_tetsuo_mutate2
		.WORD _spr_sc15_tetsuo_mutate3
		.WORD _spr_sc15_tetsuo_mutate4
		.WORD _spr_sc15_tetsuo_mutate5
		.WORD _spr_sc15_tetsuo_mutate6
		.WORD _spr_sc15_tetsuo_mutate7
		.WORD _spr_sc15_tetsuo_mutate8
		.WORD _spr_sc15_tetsuo_mutate9
		.WORD _spr_sc15_tetsuo_mutateA
		.WORD _spr_sc15_tetsuo_mutateB
		.WORD _spr_sc15_tetsuo_mutateB
		.WORD _spr_sc15_tetsuo_mutateB
		.WORD _spr_sc15_tetsuo_mutateB
		.WORD _spr_sc15_tetsuo_mutateB
off_80AA0:
		.WORD _spr_sc15_tetsuo_mutate0
		.WORD _spr_sc15_tetsuo_mutate1
		.WORD _spr_sc15_tetsuo_mutate2
		.WORD _spr_sc15_tetsuo_mutate3
		.WORD _spr_sc15_tetsuo_mutate4
		.WORD _spr_sc15_tetsuo_mutate5
		.WORD _spr_sc15_tetsuo_mutate6
		.WORD _spr_sc15_tetsuo_mutate7
		.WORD _spr_sc15_tetsuo_mutate8
		.WORD _spr_sc15_tetsuo_mutate9
		.WORD _spr_sc15_tetsuo_mutateA
		.WORD _spr_sc15_tetsuo_mutateB
		.WORD _spr_sc15_tetsuo_mutateC
		.WORD _spr_sc15_tetsuo_mutateD
		.WORD _spr_sc15_tetsuo_mutateD
		.WORD _spr_sc15_tetsuo_mutateD
off_809F9:
		.WORD _spr_sc15_tetsuo_mutateE
		.WORD _spr_sc15_tetsuo_mutateE
		.WORD _spr_sc15_tetsuo_mutateF
		.WORD _spr_sc15_tetsuo_mutateG

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_spr_overlay8:
		LDA		_tmp_y_pos
		STA		word_2
		LDA		_tmp_x_pos
		STA		word_2+1
		SPR0EX	_spr_s15_cursor
		JSR		_s15_spr_overlay4_B
		LDA		_sgame_kaneda_bullet_active
		BEQ		locret_80BA5
		LDA		_sgame_kaneda_bullet_y_pos
		STA		word_2
		LDA		_sgame_kaneda_bullet_x_pos
		STA		word_2+1
		LDA		_scene_anim_idx+3
		SPR0SWEX	off_80BA6
locret_80BA5:

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_spr_overlay4_A:
		LDA		_tmp_direction_y0
		STA		word_2
		LDA		_tmp_direction_x0
		STA		word_2+1
		LDA		_scene_anim_idx
		SPR0SWEX	off_80B45
		RTS

off_80B45:
		.WORD _s15_sgame_tetsuo_stand
		.WORD _s15_sgame_tetsuo_knee
		.WORD _s15_sgame_tetsuo_wounded
off_80BA6:
		.WORD _spr_s15_bullet0
		.WORD _spr_s15_bullet1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_spr_overlay7:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0JSW	off_80B69,$30,$C0
off_80B69:
		.WORD _spr_sc15_kids_mouth0
		.WORD _spr_sc15_kids_mouth1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_spr_overlayA:
		SPR0J	_spr_sc15_kaneda_laser,$20,$68

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s15_spr_overlay6:
		LDA		_frames_counter
		AND		#$C0
		BEQ		loc_50044
		LDA		_frames_counter
		LSR
		LSR
		LSR
		LSR
		LSR
		AND		#1
		STA		_scene_anim_idx
loc_50044:
		LDA		_scene_anim_idx
		SPR0SW	off_50064,$10,$90
		LDA		_frames_counter
		LSR
		LSR
		LSR
		LSR
		AND		#7
		PHA
		SPR0SW	off_50087,$20,$30
		PLA
		SPR0JSW	off_500B6,$10,$10
off_50064:
		.WORD _spr_sc15_tetsuo_grow_arm0
		.WORD _spr_sc15_tetsuo_grow_arm1
off_50087:
		.WORD _spr_sc15_tetsuo_grow_arm2
		.WORD _spr_sc15_tetsuo_grow_arm3
		.WORD _spr_sc15_tetsuo_grow_arm4
		.WORD _spr_sc15_tetsuo_grow_arm5
		.WORD _spr_sc15_tetsuo_grow_arm6
		.WORD _spr_sc15_tetsuo_grow_arm5
		.WORD _spr_sc15_tetsuo_grow_arm4
		.WORD _spr_sc15_tetsuo_grow_arm3
off_500B6:
		.WORD _spr_sc15_tetsuo_grow_arm7
		.WORD _spr_sc15_tetsuo_grow_arm8
		.WORD _spr_sc15_tetsuo_grow_arm9
		.WORD _spr_sc15_tetsuo_grow_armA
		.WORD _spr_sc15_tetsuo_grow_armB
		.WORD _spr_sc15_tetsuo_grow_armA
		.WORD _spr_sc15_tetsuo_grow_arm9
		.WORD _spr_sc15_tetsuo_grow_arm8

_spr_sc15_tetsuo_grow_arm0:
		.BYTE   0,$E3,  2,$18
		.BYTE   0,$E4,  2,$20
		.BYTE   8,$E5,  1,  0
		.BYTE   8,$E6,  1,  8
		.BYTE   8,$E7,  2,$10
		.BYTE   8,$E8,  2,$18
		.BYTE   8,$E9,  2,$20
		.BYTE $10,$EA,  1,  0
		.BYTE $10,$EB,  1,  8
		.BYTE $10,$EC,  2,$10
		.BYTE $10,$ED,  2,$18
		.BYTE $10,$EE,  2,$20
		.BYTE $18,$EF,  2,  0
		.BYTE $18,$F0,  2,  8
		.BYTE $18,$F1,  2,$10
		.BYTE $18,$F2,  2,$18
		.BYTE $18,$F3,  2,$20
		.BYTE $80
_spr_sc15_tetsuo_grow_arm1:
		.BYTE   0,$E3,  2,$18
		.BYTE   0,$E4,  2,$20
		.BYTE   8,$F4,  1,  0
		.BYTE   8,$F5,  1,  8
		.BYTE   8,$F6,  2,$10
		.BYTE   8,$F7,  2,$18
		.BYTE   8,$F8,  2,$20
		.BYTE $10,$F9,  1,  0
		.BYTE $10,$FA,  1,  8
		.BYTE $10,$EC,  2,$10
		.BYTE $10,$ED,  2,$18
		.BYTE $10,$FB,  2,$20
		.BYTE $18,$EF,  2,  0
		.BYTE $18,$FC,  2,  8
		.BYTE $18,$F1,  2,$10
		.BYTE $18,$F2,  2,$18
		.BYTE $18,$F3,  2,$20
		.BYTE $80
_spr_sc15_tetsuo_grow_arm2:
		.BYTE   0,$DC,  1,  8
		.BYTE $10,$DC,  1,$10
		.BYTE $18,$DC,$C1,  8
		.BYTE $80
_spr_sc15_tetsuo_grow_arm3:
		.BYTE   0,$DC,  1,  8
		.BYTE   8,$DC,$C1,$10
		.BYTE $10,$DC,  1,  0
		.BYTE $18,$DC,$C1,  8
		.BYTE $20,$DC,  1,$10
		.BYTE $80
_spr_sc15_tetsuo_grow_arm4:
		.BYTE   0,$DC,  1,  8
		.BYTE   8,$DC,$C1,$10
		.BYTE $10,$DC,  1,  0
		.BYTE $10,$DC,  1,$18
		.BYTE $18,$DC,$C1,  8
		.BYTE $20,$DC,  1,$10
		.BYTE $28,$DC,$C1,$18
		.BYTE $38,$DC,$41,$40
		.BYTE $80
_spr_sc15_tetsuo_grow_arm5:
		.BYTE   0,$DC,  1,  8
		.BYTE   8,$DC,$C1,$10
		.BYTE $10,$DC,  1,  0
		.BYTE $10,$DC,  1,$18
		.BYTE $18,$DC,$C1,  8
		.BYTE $18,$DC,$C1,$20
		.BYTE $20,$DC,  1,$10
		.BYTE $28,$DC,$C1,$18
		.BYTE $30,$DC,  1,$20
		.BYTE $30,$DC,$41,$48
		.BYTE $38,$DC,$41,$40
		.BYTE $80
_spr_sc15_tetsuo_grow_arm6:
		.BYTE   0,$DC,  1,  8
		.BYTE   8,$DC,$C1,$10
		.BYTE $10,$DC,  1,  0
		.BYTE $10,$DC,  1,$18
		.BYTE $18,$DC,$C1,  8
		.BYTE $18,$DC,$C1,$20
		.BYTE $20,$DC,  1,$10
		.BYTE $20,$DC,  1,$28
		.BYTE $28,$DC,$C1,$18
		.BYTE $28,$DC,$41,$50
		.BYTE $30,$DC,  1,$20
		.BYTE $30,$DC,$41,$48
		.BYTE $38,$DC,$C1,$28
		.BYTE $38,$DC,$41,$40
		.BYTE $80
_spr_sc15_tetsuo_grow_arm7:
		.BYTE $30,$DD,$43,$50
		.BYTE $38,$DE,$43,$50
		.BYTE $80
_spr_sc15_tetsuo_grow_arm8:
		.BYTE $10,$D6,  3,$38
		.BYTE $10,$D7,  3,$40
		.BYTE $80
_spr_sc15_tetsuo_grow_arm9:
		.BYTE   8,$D8,  3,$38
		.BYTE   8,$D9,  3,$40
		.BYTE $10,$DA,  3,$38
		.BYTE $10,$DB,  3,$40
		.BYTE $20,$DD,  3,$18
		.BYTE $28,$DE,  3,$18
		.BYTE $80
_spr_sc15_tetsuo_grow_armA:
		.BYTE $10,$D6,  3,$38
		.BYTE $10,$D7,  3,$40
		.BYTE $20,$DF,  3,$10
		.BYTE $20,$E0,  3,$18
		.BYTE $28,$E1,  3,$10
		.BYTE $28,$E2,  3,$18
		.BYTE $30,$DD,$43,$50
		.BYTE $38,$DC,$43,$50
		.BYTE $80
_spr_sc15_tetsuo_grow_armB:
		.BYTE $20,$DD,  3,$18
		.BYTE $28,$DE,  3,$18
		.BYTE $30,$E0,$43,$50
		.BYTE $30,$DF,$43,$58
		.BYTE $38,$E2,$43,$50
		.BYTE $38,$E1,$43,$58
		.BYTE $80
_spr_sc15_kaneda_icon1_mouth1:
		.BYTE   0,$F4,  1,  0
		.BYTE   0,$F5,  1,  8
		.BYTE   8,$FC,  1,  8
		.BYTE $80
_spr_sc15_kaneda_icon1_mouth0:
		.BYTE   0,$F6,  1,  0
		.BYTE   0,$F7,  1,  8
		.BYTE   8,$FD,  1,  8
		.BYTE $80
_spr_sc15_kaneda_icon2_mouth1:
		.BYTE   0,$EE,  1,  0
		.BYTE   0,$EF,  1,  8
		.BYTE $80
_spr_sc15_kaneda_icon2_mouth0:
		.BYTE   0,$EC,  1,  0
		.BYTE   0,$ED,  1,  8
		.BYTE $80
_spr_sc15_tetsuo_mouth1:
		.BYTE   0,$E8,  1,  0
		.BYTE   0,$E9,  1,  8
		.BYTE   8,$F2,  1,  0
		.BYTE   8,$F3,  1,  8
		.BYTE $10,$FA,  1,  0
		.BYTE $10,$FB,  1,  8
		.BYTE $80
_spr_sc15_tetsuo_mouth0:
		.BYTE   0,$E8,  1,  0
		.BYTE   0,$E9,  1,  8
		.BYTE   8,$F0,  1,  0
		.BYTE   8,$F1,  1,  8
		.BYTE $10,$F8,  1,  0
		.BYTE $10,$F9,  1,  8
		.BYTE $80
_s15_sgame_tetsuo_wounded:
		.BYTE $F0,$C1,  3,$F8
		.BYTE $F0,$C2,  3,  0
		.BYTE $F8,$C3,  3,$F8
		.BYTE $F8,$C6,  3,  0
		.BYTE   0,$CC,  3,$F0
		.BYTE   0,$CA,  3,$F8
		.BYTE   0,$CB,  3,  0
		.BYTE   8,$CD,  1,$F8
		.BYTE   8,$CE,  1,  0
		.BYTE $10,$CF,  1,$F8
		.BYTE $10,$D0,  1,  0
		.BYTE $18,$D1,  1,$F0
		.BYTE $18,$D3,  1,$F8
		.BYTE $18,$D4,  1,  0
		.BYTE $18,$D5,  1,  8
		.BYTE $20,$D7,  1,$F0
		.BYTE $20,$D8,  1,$F8
		.BYTE $20,$D9,  1,  0
		.BYTE $80
_s15_sgame_tetsuo_stand:
		.BYTE $F0,$C1,  3,$F8
		.BYTE $F0,$C2,  3,  0
		.BYTE $F8,$C3,  3,$F8
		.BYTE $F8,$C4,  3,  0
		.BYTE $F8,$C5,  3,  8
		.BYTE   0,$CC,  3,$F0
		.BYTE   0,$C7,  3,$F8
		.BYTE   0,$C8,  3,  0
		.BYTE   0,$C9,  3,  8
		.BYTE   8,$CD,  1,$F8
		.BYTE   8,$CE,  1,  0
		.BYTE $10,$CF,  1,$F8
		.BYTE $10,$D0,  1,  0
		.BYTE $18,$D2,  1,$F0
		.BYTE $18,$D3,  1,$F8
		.BYTE $18,$D4,  1,  0
		.BYTE $18,$D5,  1,  8
		.BYTE $20,$D7,  1,$F0
		.BYTE $20,$D8,  1,$F8
		.BYTE $20,$D9,  1,  0
		.BYTE $80
_s15_sgame_tetsuo_knee:
		.BYTE   8,$DA,  3,$F8
		.BYTE   8,$DB,  3,  0
		.BYTE $10,$DC,  3,$F8
		.BYTE $10,$DD,  3,  0
		.BYTE $18,$DE,  1,$F8
		.BYTE $18,$DF,  3,  0
		.BYTE $20,$E0,  1,$F0
		.BYTE $20,$E1,  1,$F8
		.BYTE $20,$E2,  1,  0
		.BYTE $20,$E3,  1,  8
		.BYTE $80
_spr_sc15_kids_mouth1:
		.BYTE   0,$F4,  1,  0
		.BYTE   0,$F5,  1,  8
		.BYTE $80
_spr_sc15_kids_mouth0:
		.BYTE   0,$F2,  1,  0
		.BYTE   0,$F3,  1,  8
		.BYTE $80
_s15_sgame_mirror:
		.BYTE   0,$AD,  1,  0
		.BYTE $80
_spr_s15_cursor:
		.BYTE $F8,$E7,  1,$F8
		.BYTE $F8,$E7,$41,  0
		.BYTE   0,$E8,  1,$F8
		.BYTE   0,$E8,$41,  0
		.BYTE $80
_spr_s15_bullet0:
		.BYTE $FC,$E5,  3,$FC
		.BYTE $80
_spr_s15_bullet1:
		.BYTE $FC,$E6,  3,$FC
		.BYTE $80
_spr_sc15_tetsuo_mutateE:
		.BYTE   0,$B0,  1,  0
		.BYTE   0,$B1,  1,  8
		.BYTE   0,$B2,  1,$10
		.BYTE   8,$B3,  1,  0
		.BYTE   8,$B4,  1,  8
		.BYTE   8,$B5,  1,$10
		.BYTE $10,$B6,  1,  0
		.BYTE $10,$B7,  1,  8
		.BYTE $10,$B8,  1,$10
		.BYTE $80
_spr_sc15_tetsuo_mutateF:
		.BYTE   0,$B9,  1,  0
		.BYTE   0,$BA,  1,  8
		.BYTE   0,$BB,  1,$10
		.BYTE   8,$BC,  1,  0
		.BYTE   8,$BD,  1,  8
		.BYTE   8,$BE,  1,$10
		.BYTE $10,$BF,  1,  0
		.BYTE $10,$F0,  1,  8
		.BYTE $10,$F1,  1,$10
		.BYTE $80
_spr_sc15_tetsuo_mutateG:
		.BYTE   0,$F2,  1,  0
		.BYTE   0,$F3,  1,  8
		.BYTE   0,$F4,  1,$10
		.BYTE   8,$F5,  1,  0
		.BYTE   8,$F6,  1,  8
		.BYTE   8,$F7,  1,$10
		.BYTE $10,$F8,  1,  0
		.BYTE $10,$F9,  1,  8
		.BYTE $10,$FA,  1,$10
		.BYTE $80
_spr_sc15_tetsuo_mutate0:
		.BYTE   0,$FB,  2,  0
		.BYTE $80
_spr_sc15_tetsuo_mutate1:
		.BYTE   0,$FD,  2,  0
		.BYTE   0,$FC,  2,  0
		.BYTE $80
_spr_sc15_tetsuo_mutate2:
		.BYTE   0,$FD,  2,  0
		.BYTE   0,$FF,  2,  0
		.BYTE   0,$FC,  2,  0
		.BYTE $80
_spr_sc15_tetsuo_mutateD:
		.BYTE $B8,$FF,  2,  0
_spr_sc15_tetsuo_mutateC:
		.BYTE $B8,$FF,  2,  0
_spr_sc15_tetsuo_mutateB:
		.BYTE $B8,$FF,  2,  0
_spr_sc15_tetsuo_mutateA:
		.BYTE $B8,$FF,  2,  0
_spr_sc15_tetsuo_mutate9:
		.BYTE $B8,$FF,  2,  0
_spr_sc15_tetsuo_mutate8:
		.BYTE $B8,$FF,  2,  0
_spr_sc15_tetsuo_mutate7:
		.BYTE $C0,$FF,  2,  0
_spr_sc15_tetsuo_mutate6:
		.BYTE $C8,$FF,  2,  0
_spr_sc15_tetsuo_mutate5:
		.BYTE $D0,$FF,  2,  0
_spr_sc15_tetsuo_mutate4:
		.BYTE $D8,$FF,  2,  0
_spr_sc15_tetsuo_mutate3:
		.BYTE $E0,$FF,  2,  0
		.BYTE $E8,$FF,  2,  0
		.BYTE $F0,$FF,  2,  0
		.BYTE $F8,$FF,  2,  0
		.BYTE   0,$FD,  2,  0
		.BYTE $80
_spr_sc15_kaneda_laser:
		.BYTE   3,$F7,  1,  0
		.BYTE   3,$F8,  1,  8
		.BYTE   3,$F9,  1,$10
		.BYTE   2,$FA,  1,$1A
		.BYTE   2,$FB,  1,$22
		.BYTE $10,$FC,  1,$18
		.BYTE $18,$FD,  1,$18
		.BYTE $80

		SECTION_END 15
