
		SECTION_START 13

;-----------------------------------------------
; SCENE 13
;-----------------------------------------------

; original interactive script:
; BRANCH A {
; 	1. dodge/jump on (game over, restart SCENE 12, BRANCH A, OPTION A)
; }
; BRANCH B {
; 	1. use
; 	1.x dodge/jump on (game over, restart SCENE 13, BRANCH B)
; 	2. play shooting game (A - fire)
;		- shot tetsuo's body or empty space x 5 (jump 3.)
;		- shot tetsuo's chest (jump SCENE 16-66, ENDING A)
;		- shot samples (jump SCENE 16-90, ENDING B)
;		- shot tetsuo's right arm (jump SCENE 15, BRANCH B)
; 	3. look
; 	3.x hide/turn/yell (game over, restart SCENE 13, BRANCH B)
; 	4. yell (jump SCENE 14, BRANCH A)
; 	4.x jump/ask out/look (game over, restart SCENE 13, BRANCH B)
; }

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene13_subs:
		JSR		_s13_spr_overlay_set
		LDA		_draw_state_idx
		BEQ		locret_69030
		RTS
locret_69030:
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s13_sub00_clear
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_generic_menu_input
		SW_PTR	_s13_menu_handlers
		SW_PTR	_s13_sub05_tetsuo_icon1_draw
		SW_PTR	_s13_sub06_tetsuo_icon1_msg0
		SW_PTR	_s13_sub3C_tetsuo_icon1_clear
		SW_PTR	_s13_sub08_tetsuo_icon0_draw
		SW_PTR	_s13_sub09_kaneda_icon2_draw
		SW_PTR	_s13_sub3D_kaneda_tetsuo_msg0
		SW_PTR	_s13_sub0A_kaneda_icon1_draw0
		SW_PTR	_s13_sub0B_kaneda_icon1_msg0
		SW_PTR	_s13_sub0C_tetsuo_sgame_draw
		SW_PTR	_s13_sub0D_branch_select
		SW_PTR	_s13_sub2F_branchA_menu_loop
		SW_PTR	_s13_sub31_branchA_game_over
		SW_PTR	_s13_sub02_branchB_menu_loop
		SW_PTR	_s13_sub2B_branchB_game_over
		SW_PTR	_s13_sgame_loop
		SW_PTR	_s13_sub2A_optionA_hit_missed_msg	; OPTION A
		SW_PTR	_s13_sub28_optionA_hit_body_msg
		SW_PTR	_s13_sub0F_optionA_clear
		SW_PTR	_s13_sub2C_optionA_tetsuo_icon0_draw
		SW_PTR	_s13_sub10_optionA_kaneda_icon1_draw
		SW_PTR	_s13_sub11_optionA_msg0
		SW_PTR	_s13_sub12_optionA_orbital_laser_shot_draw
		SW_PTR	_s13_sub13_optionA_orbital_laser_shot_msg
		SW_PTR	_s13_sub25_optionA_clear
		SW_PTR	_s13_sub14_optionA_kaneda_ranaway_icon1_draw0
		SW_PTR	_s13_sub15_optionA_kaneda_ranaway_msg0
		SW_PTR	_s13_sub16_optionA_kaneda_ranaway_icon_clear
		SW_PTR	_s13_sub17_optionA_tetsuo_without_arm_icon0_draw
		SW_PTR	_s13_sub18_optionA_tetsuo_without_arm_msg
		SW_PTR	_s13_sub19_optionA_kaneda_with_rock_icon2_draw
		SW_PTR	_s13_sub1A_optionA_kaneda_with_rock_msg0
		SW_PTR	_s13_sub1A_optionA_kaneda_with_rock_msg1	; message split
		SW_PTR	_s13_sub3A_optionA_tetsuo_closeup_draw
		SW_PTR	_s13_sub3B_optionA_tetsuo_closeup_msg
		SW_PTR	_s13_sub1B_optionA_clear
		SW_PTR	_s13_sub1C_optionA_rubble_fallen_icon1_draw
		SW_PTR	_s13_sub1D_optionA_rubble_fallen_msg
		SW_PTR	_s13_sub1E_optionA_kaneda_runaway_icon1_draw1
		SW_PTR	_s13_sub1F_optionA_kaneda_runaway_msg1
		SW_PTR	_s13_sub20_optionA_kaneda_runaway_menu0_loop
		SW_PTR	_s13_sub34_optionA_kaneda_runaway_menu1_loop
		SW_PTR	_s13_sub21_optionA_kai_kei_icon0_draw
		SW_PTR	_s13_sub22_optionA_kai_kei_msg0
		SW_PTR	_s13_sub23_optionA_kai_kei_icon2_draw
		SW_PTR	_s13_sub24_optionA_kai_kei_msg1
		SW_PTR	_s13_sub3E_optionA_clear
		SW_PTR	_s13_sub3F_optionA_colonel_icon1_draw
		SW_PTR	_s13_sub40_optionA_sol_destroyed_msg
		SW_PTR	_s13_sub41_optionA_kiyoko_draw
		SW_PTR	_s13_sub42_optionA_kiyoko_msg
		SW_PTR	_s13_sub45_optionA_game_over_msg
		SW_PTR	_s13_sub38_optionA_game_over
		SW_PTR	_s13_sub29_optionB_hit_chest_msg	; OPTION B
		SW_PTR	_s13_sub43_optionB_hit_tetsuo_chest_msg
		SW_PTR	_s13_sub2D_optionB_s16_sub66_warp
		SW_PTR	_s13_sub35_optionC_hit_right_arm	; OPTION C
		SW_PTR	_s13_sub36_optionC_s15_sub10_warp
		SW_PTR	_s13_sub44_optionD_hit_samples		; OPTION D
		SW_PTR	_s13_sub44_optionD_hit_samples_msg
		SW_PTR	_s13_sub37_optionD_s16_sub90_warp

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub00_clear:
		SW_NXT	_s13_sub05_tetsuo_icon1_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub05_tetsuo_icon1_draw:
		SW_NXT	_s13_sub06_tetsuo_icon1_msg0
		ICON1	$3B,$3D,$60

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub06_tetsuo_icon1_msg0:
		SW_FADE	_s13_sub3C_tetsuo_icon1_clear
		LDA		#1
		STA		_scene_spr_overlay_idx
		MSG_M
		MSG		_sc13_msg00
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub3C_tetsuo_icon1_clear:
		SW_NXT	_s13_sub08_tetsuo_icon0_draw
		ICON1_CLEAR

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub08_tetsuo_icon0_draw:
		SW_NXT	_s13_sub09_kaneda_icon2_draw
		JMP		_s13_icon60_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub09_kaneda_icon2_draw:
		SW_NXT	_s13_sub3D_kaneda_tetsuo_msg0
		LDA		#2
		STA		_scene_spr_overlay_idx
		ICON2	$3B,$3D,$61

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub3D_kaneda_tetsuo_msg0:
		SW_FADE	_s13_sub0A_kaneda_icon1_draw0
		MSG_M
		MSG		_sc13_msg01
		MSG		_sc13_msg02
		MSG		_sc13_msg03
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub0A_kaneda_icon1_draw0:
		SW_NXT	_s13_sub0B_kaneda_icon1_msg0
		LDA		#3
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_icon62_draw:
		ICON1	$3B,$3D,$62

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub0B_kaneda_icon1_msg0:
		SW_FADE	_s13_sub0C_tetsuo_sgame_draw
		MSG_M
		MSG		_sc13_msg04
		MSG		_sc13_msg1F
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub0C_tetsuo_sgame_draw:
		SW_NXT	_s13_sub0D_branch_select
		LDA		#8
		STA		_scene_spr_overlay_idx
		LDA		#1
		STA		_sgame_shoot_enable
		LDA		#$70
		STA		_tmp_direction_x0
		STA		_tmp_x_pos
		STA		_tmp_cnt0
		LDA		#$30
		STA		_tmp_direction_y0
		STA		_tmp_cnt1
		LDA		#$40
		STA		_tmp_y_pos
		LDA		#0
		STA		_scene_anim_idx
		STA		_scene_anim_counter
		STA		_scene_anim_counter+1
		STA		_scene_anim_counter+2
		STA		_sgame_kaneda_bullet_active
		TLM4	$5F,$5F,$95

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub0D_branch_select:
		JSR		_snd_battle_begin_beat
		SW_NXT	_s13_sub02_branchB_menu_loop	; got laser
		LDA		_game_global_flags0
		AND		#$10
		BEQ		loc_691B7
		SW_NXT	_s13_sub2F_branchA_menu_loop	; no laser
loc_691B7:
		MSG_1	_sc13_15_msg9E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub2F_branchA_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_69442
		SW_RET	_s13_sub2F_branchA_menu_loop
		LDA		#1
		JSR		_s13_menus_init
		JMP		_menu_draw_request
locret_69442:
		RTS

; TODO: use one of these functions as common game over for both branches with
; working condition testing, remove different game over functions from menu1/2
; could make one menu as well with enabled or disabled laser option.

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub31_branchA_game_over:
;		LDA		_game_global_flags0				; here we have var3 always set lol, so
;		AND		#$10							; we couldn't retry here at all
;		BEQ		loc_6946D
;		LDA		#$12							; pass from scene 12, sub 0E
;		STA		_scene_idx_pass					; can we do this far without laser?
;		LDA		#_s12_sub0E_tank_ruins_draw_sidx; no
;		STA		_scene_sub_save_pass
;loc_6946D:
;		LDX		#$13							; in any case, we jump to a custom scene select switch
;		LDY		#_s13_sub32_branchA_fade_out_sidx; which do actual scene 12 retry
		LDX		#$12							; fixed all this here
		LDY		#_s12_sub0E_tank_ruins_draw_sidx
		JMP		_game_over_dead_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub02_branchB_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_690DF
		SW_RET	_s13_sub02_branchB_menu_loop
		LDA		#0
		JSR		_s13_menus_init
		JMP		_menu_draw_request
locret_690DF:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub2B_branchB_game_over:
;		LDA		_game_global_flags0				; in this branch var3 always zero,
;		AND		#$10							; we just couldn't retry from 12
;		BEQ		loc_693FA
;		LDA		#$12
;		STA		_scene_idx_pass
;		LDA		#_s12_sub0E_tank_ruins_draw_sidx; this is for sure 0E sub for scene 12, but it doesn't work like that!
;		STA		_scene_sub_save_pass			; the last sub idx for pass here is C, wo it will restore on kaneda's bike!
;loc_693FA:
		LDX		#$13							; let's make it proper way
		LDY		#0
		JMP		_game_over_dead_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub0F_optionA_clear:
		SW_NXT	_s13_sub2C_optionA_tetsuo_icon0_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub2C_optionA_tetsuo_icon0_draw:
		SW_NXT	_s13_sub10_optionA_kaneda_icon1_draw
;		CHRPAL	$3B,$3D							; if we set pal here, we will see how icon1 drawn

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_icon60_draw:
		ICON0EX	$60

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub10_optionA_kaneda_icon1_draw:
		SW_NXT	_s13_sub11_optionA_msg0
		LDA		#4
		STA		_scene_spr_overlay_idx
		LDA		#1
		STA		_scene_anim_idx
		JMP		_s13_icon62_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub11_optionA_msg0:
		SW_FADE	_s13_sub12_optionA_orbital_laser_shot_draw
		MSG_M
		MSG		_sc13_msg0F
		MSG		_sc13_msg08
		MSG		_sc13_msg28
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub12_optionA_orbital_laser_shot_draw:
		SW_NXT	_s13_sub13_optionA_orbital_laser_shot_msg
		LDA		#0
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_tlm63_draw:
		TLM4	$3C,$3E,$63

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub13_optionA_orbital_laser_shot_msg:
		JSR		_snd_orbital_laser_shot
		SW_FADE	_s13_sub25_optionA_clear
		MSG_M
		MSG		_sc13_msg10
		MSG		_scF_12_13_15_msg93
		MSG		_sc13_msg11
		MSG		_sc2_13_15_16_msg82
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub25_optionA_clear:
		SW_NXT	_s13_sub14_optionA_kaneda_ranaway_icon1_draw0
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub14_optionA_kaneda_ranaway_icon1_draw0:
		SW_NXT	_s13_sub15_optionA_kaneda_ranaway_msg0

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_icon67_draw:
		ICON1	$3E,$40,$67

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub15_optionA_kaneda_ranaway_msg0:
		JSR		_snd_walkway_explosion
		SW_FADE	_s13_sub16_optionA_kaneda_ranaway_icon_clear
		MSG_M
		MSG		_sc13_msg12
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub16_optionA_kaneda_ranaway_icon_clear:
		SW_NXT	_s13_sub17_optionA_tetsuo_without_arm_icon0_draw
		ICON1_CLEAR

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub17_optionA_tetsuo_without_arm_icon0_draw:
		SW_NXT	_s13_sub18_optionA_tetsuo_without_arm_msg
		LDA		#5
		STA		_scene_spr_overlay_idx
		ICON0	$3D,$3F,$64

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub18_optionA_tetsuo_without_arm_msg:
		JSR		_apu_reset
		JSR		_snd_battle_action_beat
		SW_FADE	_s13_sub19_optionA_kaneda_with_rock_icon2_draw
		MSG_M
		MSG		_sc13_msg13
		MSG		_sc13_msg09
		MSG		_scF_12_13_15_msg93
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub19_optionA_kaneda_with_rock_icon2_draw:
		SW_NXT	_s13_sub1A_optionA_kaneda_with_rock_msg0
		LDA		#6
		STA		_scene_spr_overlay_idx
		ICON2	$3D,$3F,$65

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub1A_optionA_kaneda_with_rock_msg0:
		SW_NXT	_s13_sub1A_optionA_kaneda_with_rock_msg1
		LDA		#0								; init lifting face
		STA		_scene_anim_idx
;		MSG_M
;		MSG		_sc13_msg14
;		MSG		_sc13_msg15
;		MSG		_sc13_msg16
;		MSG_WAIT								;lets split it here
		MSG_M
		MSG		_sc13_msg14
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub1A_optionA_kaneda_with_rock_msg1:
		SW_FADE	_s13_sub3A_optionA_tetsuo_closeup_draw
		LDA		#1								; make use of the other kaneda's face
		STA		_scene_anim_idx
		MSG_M
		MSG		_sc13_msg15
		MSG		_sc13_msg16
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub3A_optionA_tetsuo_closeup_draw:
		SW_NXT	_s13_sub3B_optionA_tetsuo_closeup_msg
		LDA		#9
		STA		_scene_spr_overlay_idx
		FJMP	_s12_tlmA0_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub3B_optionA_tetsuo_closeup_msg:
		SW_FADE	_s13_sub1B_optionA_clear
		MSG_M
		MSG		_sc13_msg17
		MSG		_sc13_msg0B
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub1B_optionA_clear:
		SW_NXT	_s13_sub1C_optionA_rubble_fallen_icon1_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub1C_optionA_rubble_fallen_icon1_draw:
		SW_NXT	_s13_sub1D_optionA_rubble_fallen_msg
		LDA		#7
		STA		_scene_spr_overlay_idx
		ICON1	$3D,$3F,$66

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub1D_optionA_rubble_fallen_msg:
		SW_FADE	_s13_sub1E_optionA_kaneda_runaway_icon1_draw1
		MSG_M
		MSG		_sc13_msg18
		MSG		_sc13_msg27
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub1E_optionA_kaneda_runaway_icon1_draw1:
		SW_NXT	_s13_sub1F_optionA_kaneda_runaway_msg1
		LDA		#0
		STA		_scene_spr_overlay_idx
		JMP		_s13_icon67_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub1F_optionA_kaneda_runaway_msg1:
		JSR		_snd_walkway_explosion
		SW_NXT	_s13_sub20_optionA_kaneda_runaway_menu0_loop
		MSG_M
		MSG		_sc13_msg19
		MSG		_sc13_msg29
		MSG		_sc13_msg1A
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub20_optionA_kaneda_runaway_menu0_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_6931C
		SW_RET	_s13_sub20_optionA_kaneda_runaway_menu0_loop
		LDA		#2
		JSR		_s13_menus_init
		JMP		_menu_draw_request
locret_6931C:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub34_optionA_kaneda_runaway_menu1_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_6949C
		SW_RET	_s13_sub34_optionA_kaneda_runaway_menu1_loop
		LDA		#3
		JSR		_s13_menus_init
		JMP		_menu_draw_request
locret_6949C:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub21_optionA_kai_kei_icon0_draw:
		SW_NXT	_s13_sub22_optionA_kai_kei_msg0
		ICON0	$3E,$40,$68

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub22_optionA_kai_kei_msg0:
		SW_FADE	_s13_sub23_optionA_kai_kei_icon2_draw
		MSG_M
		MSG		_sc13_msg26
		MSG		_sc13_msg1E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub23_optionA_kai_kei_icon2_draw:
		SW_NXT	_s13_sub24_optionA_kai_kei_msg1
		ICON2	$3E,$40,$69

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub24_optionA_kai_kei_msg1:
		SW_FADE	_s13_sub3E_optionA_clear
		MSG_M
		MSG		_scD_E_13_msg91
		MSG		_sc13_msg2C
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sgame_loop:
		LDA		_sgame_kaneda_bullet_active
		BNE		locret_6979A
		JSR		_sgame_cursor_input
locret_6979A:
		JSR		_sgame_kaneda_bullet_handler
		LDA		_sgame_kaneda_bullet_active
		BEQ		locret_697F1
		LDA		_tmp_y_pos
		CMP		_sgame_kaneda_bullet_dir_y+1	; test shooting to nowhere
		BCC		locret_697F1
		LDA		#0
		STA		_sgame_kaneda_bullet_active
		LDA		_scene_states					; shoot counter
		CMP		#5
		BCC		loc_697CC
		SW_FADE	_s13_sub0F_optionA_clear		; shooting to nowhere 5 times
		MSG_M
		MSG		_sc13_msg0D
		MSG		_sc13_msg0E
		MSG_EOL
loc_697CC:
		LDA		_tmp_direction_y0
		CLC
		ADC		#$18
		SEC
		SBC		_sgame_kaneda_bullet_dir_y+1
		BCC		loc_697F2
		CMP		#8
		BCS		loc_697F2
		LDA		_tmp_direction_x0
		CLC
		ADC		#$14
		SEC
		SBC		_sgame_kaneda_bullet_dir_x+1
		BCC		loc_697F2
		CMP		#8
		BCS		loc_697F2
		SW_NXT	_s13_sub29_optionB_hit_chest_msg; shoot point A
locret_697F1:
		RTS
loc_697F2:
		LDA		_tmp_direction_y0
		CLC
		ADC		#$10
		SEC
		SBC		_sgame_kaneda_bullet_dir_y+1
		BCC		loc_69818
		CMP		#$10
		BCS		loc_69818
		LDA		_tmp_direction_x0
		CLC
		ADC		#8
		SEC
		SBC		_sgame_kaneda_bullet_dir_x+1
		BCC		loc_69818
		CMP		#8
		BCS		loc_69818
		SW_NXT	_s13_sub35_optionC_hit_right_arm; shoot point B
		RTS
loc_69818:
		LDA		_tmp_direction_y0
		CLC
		ADC		#$28
		SEC
		SBC		_sgame_kaneda_bullet_dir_y+1
		BCC		loc_6983E
		CMP		#$28
		BCS		loc_6983E
		LDA		_tmp_direction_x0
		CLC
		ADC		#$18
		SEC
		SBC		_sgame_kaneda_bullet_dir_x+1
		BCC		loc_6983E
		CMP		#$10
		BCS		loc_6983E
		SW_NXT	_s13_sub28_optionA_hit_body_msg	; shoot point C
		RTS
loc_6983E:
		LDA		_sgame_kaneda_bullet_dir_y+1
		SEC
		SBC		#$58
		BCC		loc_6985C
		CMP		#$10
		BCS		loc_6985C
		LDA		_sgame_kaneda_bullet_dir_x+1
		SEC
		SBC		#$C0
		BCC		loc_6985C
		CMP		#$30
		BCS		loc_6985C
		SW_NXT	_s13_sub44_optionD_hit_samples	; shoot point D, even samples position
		RTS										; are calculated from tetsuo position
loc_6985C:
		SW_NXT	_s13_sub2A_optionA_hit_missed_msg	; shoot point E
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub2A_optionA_hit_missed_msg:
		SW_NXT	_s13_sgame_loop
		MSG_1	_sc13_15_msg9F

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub28_optionA_hit_body_msg:
		JSR		_apu_reset
		JSR		_snd_punch0
		LDA		_scene_states
		CMP		#5
		BCC		loc_693AD
		SW_FADE	_s13_sub0F_optionA_clear
		MSG_M
		MSG		_sc13_msg0C
		MSG		_sc13_msg0E
		MSG_EOL
loc_693AD:
		SW_NXT	_s13_sgame_loop
		MSG_1	_sc13_msg0A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub29_optionB_hit_chest_msg:
		JSR		_apu_reset
		JSR		_snd_hit_splash
		SW_NXT	_s13_sub43_optionB_hit_tetsuo_chest_msg
		MSG_1	_sc13_15_msg9A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub43_optionB_hit_tetsuo_chest_msg:
		SW_FADE	_s13_sub2D_optionB_s16_sub66_warp
		MSG_1	_sc13_15_msg9B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub44_optionD_hit_samples:
		JSR		_apu_reset
		JSR		_snd_hit_splash
		LDA		#1
		STA		_scene_anim_idx					; tetsuo try to fly away
		LDA		#0
		STA		_scene_anim_counter
		SW_NXT	_s13_sub44_optionD_hit_samples_msg
		MSG_M
		MSG		_sc13_msg05
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub44_optionD_hit_samples_msg:
		SW_FADE	_s13_sub37_optionD_s16_sub90_warp
		MSG_M
		MSG		_sc13_msg24
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub37_optionD_s16_sub90_warp:
		JSR		_snd_hit_splash
		JSR		_scene_vars_init
		WARP	$16,_s16_sub90_orbital_laser_shot_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub35_optionC_hit_right_arm:
		SW_FADE	_s13_sub36_optionC_s15_sub10_warp
		JSR		_apu_reset
		JMP		_snd_hit_splash

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub36_optionC_s15_sub10_warp:
		JSR		_scene_vars_init
		WARP	$15,_s15_sub10_clear

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub2D_optionB_s16_sub66_warp:
		JSR		_snd_hit_splash
		JSR		_scene_vars_init
		WARP	$16,_s16_sub66_safe_town_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub3E_optionA_clear:
		SW_NXT	_s13_sub3F_optionA_colonel_icon1_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub3F_optionA_colonel_icon1_draw:
		SW_NXT	_s13_sub40_optionA_sol_destroyed_msg
		EXJMP	_sF_icon46_draw					; defined in system bank

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub40_optionA_sol_destroyed_msg:
		SW_FADE	_s13_sub41_optionA_kiyoko_draw
		LDA		#$B
		STA		_scene_spr_overlay_idx
		MSG_M
		MSG		_sc13_msg2A
		MSG		_sc13_msg2B
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub41_optionA_kiyoko_draw:
		SW_NXT	_s13_sub42_optionA_kiyoko_msg
		LDA		#$A
		STA		_scene_spr_overlay_idx
		EXJMP	_sF_tlm9C_draw					; defined in system bank

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub42_optionA_kiyoko_msg:
		SW_FADE	_next_scene
		MSG_M
		MSG		_sc13_msg2D
		MSG		_sc13_msg2E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub45_optionA_game_over_msg:
		JSR		_snd_walkway_explosion
		SW_FADE	_s13_sub38_optionA_game_over
		MSG_M
		MSG		_sc13_msg21
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_sub38_optionA_game_over:
		JSR		_snd_walkway_explosion
;		LDA		_game_global_flags0				; we could get this far with laser only
;		AND		#$10							; no need to check it here
;		BEQ		loc_694D6
;		LDA		#$12
;		STA		_scene_idx_pass
;		LDA		#_s12_sub0E_tank_ruins_draw_sidx; why they did even use this var??
;		STA		_scene_sub_save_pass			; it's just a latch, and copied in pass at menus only
;loc_694D6:
		LDX		#$13
		LDY		#_s13_sub12_optionA_orbital_laser_shot_draw_sidx
		JMP		_game_over_dead_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_menus_init:
		STA		_scene_menu_idx
		SW_NXT	_generic_menu_input
		LDA		_scene_menu_idx
		SWITCH
		SW_PTR	_scene_menu_init_default3
		SW_PTR	_scene_menu_init_default2
		SW_PTR	_scene_menu_init_default5
		SW_PTR	_scene_menu_init_default4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_menu_handlers:
		JSR		_menu_switch
		.WORD _s13_menu0
		.WORD _s13_menu1
		.WORD _s13_menu2
		.WORD _s13_menu3
_s13_menu0:
		.WORD _s13_menu0_dodge
		.WORD _s13_menu0_jump_on
		.WORD _s13_menu0_use
_s13_menu1:
		.WORD _s13_menu1_dodge
		.WORD _s13_menu1_jump_on
_s13_menu2:
		.WORD _s13_menu2_hide
		.WORD _s13_menu2_turn
		.WORD _s13_menu2_yell
		.WORD _s13_menu2_inquire
		.WORD _s13_menu2_look
_s13_menu3:
		.WORD _s13_menu3_yell
		.WORD _s13_menu3_jump
		.WORD _s13_menu3_ask_out
		.WORD _s13_menu3_look

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_menu0_dodge:
		SW_FADE	_s13_sub2B_branchB_game_over
		MSG_M
		MSG		_sc13_msg06
		MSG		_scC_D_13_16_msg90
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_menu0_jump_on:
		SW_FADE	_s13_sub2B_branchB_game_over
		MSG_M
		MSG		_sc13_msg07
		MSG		_scC_D_13_16_msg90
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_menu0_use:
		SW_NXT	_s13_sgame_loop
		MSG_1	_sc13_15_msg99

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_menu1_dodge:
		SW_FADE	_s13_sub31_branchA_game_over
		MSG_M
		MSG		_sc13_msg06
		MSG		_scC_D_13_16_msg90
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_menu1_jump_on:
		SW_FADE	_s13_sub31_branchA_game_over
		MSG_M
		MSG		_sc13_msg07
		MSG		_scC_D_13_16_msg90
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_menu2_hide:
		SW_NXT	_s13_sub45_optionA_game_over_msg
		MSG_M
		MSG		_sc13_msg20
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_menu2_turn:
		SW_NXT	_s13_sub45_optionA_game_over_msg
		MSG_M
		MSG		_sc13_msg22
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_menu2_yell:
		SW_NXT	_s13_sub45_optionA_game_over_msg
		MSG_M
		MSG		_sc13_msg23
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_menu2_inquire:
		SW_NXT	_s13_sub20_optionA_kaneda_runaway_menu0_loop
		MSG_M
		MSG		_sc11_12_13_msg97
		MSG		_sc13_msg1B
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_menu2_look:
		SW_NXT	_s13_sub34_optionA_kaneda_runaway_menu1_loop
		MSG_M
		MSG		_sc13_msg1C
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_menu3_yell:
		JSR		_apu_reset
		SW_FADE	_s13_sub21_optionA_kai_kei_icon0_draw
		MSG_M
		MSG		_sc13_msg1D
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_menu3_jump:
		SW_NXT	_s13_sub45_optionA_game_over_msg
		MSG_M
		MSG		_sc2_13_msgA0
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_menu3_ask_out:
		SW_NXT	_s13_sub45_optionA_game_over_msg
		MSG_M
		MSG		_sc13_msg25
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_menu3_look:
		SW_NXT	_s13_sub45_optionA_game_over_msg
		MSG_M
		MSG		_sc2_F_10_12_13_msg85
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s13_spr_overlay1
		SW_PTR	_s13_spr_overlay2
		SW_PTR	_s13_spr_overlay3
		SW_PTR	_s13_spr_overlay4
		SW_PTR	_s13_spr_overlay5
		SW_PTR	_s13_spr_overlay6
		SW_PTR	_s13_spr_overlay7
		SW_PTR	_s13_spr_overlay8
		EXOFS	_s12_spr_overlay4
		EXOFS	_sF_spr_overlay8				; defined in system bank
		EXOFS	_sF_spr_overlay7				; defined in system bank

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_spr_overlay1:
		SPR0	_spr_sc13_tetsuo_forehead0,$58,$78
		SPR0	_spr_sc13_tetsuo_mouth0,$58,$78
		SPR0J	_spr_sc13_tetsuo_eyes0,$58,$78

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_spr_overlay2:
		JSR		_s13_spr_overlay2_A
		JMP		_s13_spr_overlay2_B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_spr_overlay3:
		JSR		_s13_spr_overlay2_A
		JSR		_s13_spr_overlay2_B
		JMP		_s13_spr_overlay2_C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_spr_overlay4:
		JSR		_s13_spr_overlay2_A
		JMP		_s13_spr_overlay2_C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_spr_overlay2_A:
		SPR0	_spr_sc13_tetsuo_forehead0,$28,$28
		JSR		_do_scene_anim1_pat0101
		LDA		_scene_anim_idx+1
		SPR0SW	off_6991F,$28,$28
		JSR		_get_anim_blink_idx
		SPR0JSW	off_69925,$28,$28
off_6991F:
		.WORD _spr_sc13_tetsuo_mouth0
		.WORD _spr_sc13_tetsuo_mouth1
off_69925:
		.WORD _spr_sc13_tetsuo_eyes1
		.WORD _spr_sc13_tetsuo_eyes2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_spr_overlay2_B:
		SPR0	_spr_sc1113_kaneda_body_forth,$28,$C8
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0SW	off_699B4,$28,$C8
		JSR		_get_anim_blink_idx
		SPR0JSW	off_699BA,$28,$C8

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_spr_overlay5:								; moved from scene 11! shares the same sprites
		SPR0	_spr_sc1113_kaneda_body_forth,$58,$78	; as _s13_spr_overlay2_B, but different positions
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0SW	off_699B4,$58,$78
		JSR		_get_anim_blink_idx
		SPR0JSW	off_699BA,$58,$78
off_699B4:
		.WORD _spr_sc1113_kaneda_mouth0
		.WORD _spr_sc1113_kaneda_mouth1
off_699BA:
		.WORD _spr_sc1113_kaneda_eyes0
		.WORD _spr_sc1113_kaneda_eyes1


;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_spr_overlay2_C:
		SPR0	_spr_sc13_kaneda_left_head,$48,$70
		LDA		_scene_spr_overlay_idx			; this overlay shares mouth blink from overlay 2
		CMP		#4								; but can't be animated if overlay is set 4
		BNE		.skip0							; we fix it here
		JSR		_do_scene_anim0_pat0101
.skip0:
		LDA		_scene_anim_idx
		SPR0SW	off_69A65,$48,$70
		JSR		_get_anim_blink_idx
		SPR0JSW	off_69A69,$48,$70
off_69A65:
		.WORD _spr_sc13_kaneda_left_mouth1
		.WORD _spr_sc13_kaneda_left_mouth0
off_69A69:
		.WORD _spr_sc13_kaneda_left_eyes0		; reused, resored blinking animation
		.WORD _spr_sc13_kaneda_left_eyes1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_spr_overlay5:
		SPR0J	_spr_sc13_kaneda_without_arm,$18,$10

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_spr_overlay6:
		JSR		_s13_spr_overlay5
		LDA		_scene_anim_idx
		SPR0JSW	off_69A9C,$19,$D9
off_69A9C:
		.WORD _spr_sc13_kaneda_with_rock0
		.WORD _spr_sc13_kaneda_with_rock1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_spr_overlay7:
		SPR0J	_spr_sc13_rubbles,$40,$60

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s13_spr_overlay8:
		JSR		_tetsuo_animate
		LDA		_scene_sub_cur
		CMP		#_s13_sgame_loop_sidx			; show cursor only if in mini-game mode
		BNE		locret_69ACE
		LDA		_tmp_y_pos
		STA		word_2
		LDA		_tmp_x_pos
		STA		word_2+1
		SPR0EX	_spr_sc13_cursor
locret_69ACE:
		LDA		_sgame_kaneda_bullet_active
		BEQ		locret_69AF0
		LDA		_sgame_kaneda_bullet_y_pos
		STA		word_2
		LDA		_sgame_kaneda_bullet_x_pos
		STA		word_2+1
		LDA		_scene_anim_idx+3
		SPR0SWEX	off_69AF1
locret_69AF0:
		LDA		_tmp_direction_y0				; animate me!
		STA		word_2
		LDA		_tmp_direction_x0
		STA		word_2+1
		LDA		_scene_anim_idx					; only 0 used
		SPR0SWEX	off_69B11
		SPR0J	_spr_sc13_samples,$58,$C0
off_69AF1:
		.WORD _spr_sc13_kaneda_bullet0
		.WORD _spr_sc13_kaneda_bullet1
off_69B11:
		.WORD _spr_sc13_tetsuo_body0
		.WORD _spr_sc13_tetsuo_body1
		.WORD _spr_dummy

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tetsuo_animate:
		LDA		_scene_anim_idx
		BNE		.anim2
		LDA		_frames_counter
		AND		#$03
		BNE		.skip1
		LDA		_scene_anim_counter
		CLC
		ADC		#1
		STA		_scene_anim_counter
		AND		#$F
		TAY
		LDA		_tetsuo_hold_list,Y
		CLC
		ADC		_tmp_cnt1
		STA		_tmp_direction_y0
		RTS
.anim2:
		LDA		_tmp_direction_x0
		BMI		.skip1
		LDA		_scene_anim_counter
		CLC
		ADC		#1
		STA		_scene_anim_counter
		LSR
		LSR
		STA		_scene_anim_counter+1
		LSR
		STA		_scene_anim_counter+2
		LDA		_tmp_direction_x0
		SEC
		SBC		_scene_anim_counter+1
		STA		_tmp_direction_x0
		BPL		.skip3
		LDA		#2
		STA		_scene_anim_idx
.skip3:
		LDA		_tmp_direction_y0
		SEC
		SBC		_scene_anim_counter+2
		STA		_tmp_direction_y0
.skip1:
		RTS

_tetsuo_hold_list:
		.BYTE $00,$FC,$FA,$F9,$F8,$F9,$FA,$FC,$00,$04,$06,$07,$08,$07,$06,$04

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s12_spr_overlay4				; 1 time here as OFS

_spr_sc13_tetsuo_forehead0:
		.BYTE   0,$87,  1,  0
		.BYTE   0,$88,  1,  8
		.BYTE $80
_spr_sc13_tetsuo_mouth1:
		.BYTE $10,$80,  1,  0
		.BYTE $10,$82,  1,  8
		.BYTE $80
_spr_sc13_tetsuo_mouth0:
		.BYTE $10,$8B,  1,  0
		.BYTE $10,$8C,  1,  8
		.BYTE $80
_spr_sc13_tetsuo_eyes1:
		.BYTE   8,$85,  1,  0
		.BYTE   8,$86,  1,  8
		.BYTE $80
_spr_sc13_tetsuo_eyes2:
		.BYTE   8,$83,  1,  0
		.BYTE   8,$84,  1,  8
		.BYTE $80
_spr_sc13_tetsuo_eyes0:
		.BYTE   8,$89,  1,  0
		.BYTE   8,$8A,  1,  8
		.BYTE $80
_spr_sc1113_kaneda_body_forth:
		.BYTE   0,$91,  1,  0
		.BYTE   0,$92,  1,  8
		.BYTE $80
_spr_sc1113_kaneda_mouth1:
		.BYTE $10,$8D,  2,  0
		.BYTE $10,$8E,  2,  8
		.BYTE $80
_spr_sc1113_kaneda_mouth0:
		.BYTE $10,$95,  2,  0
		.BYTE $10,$96,  2,  8
		.BYTE $80
_spr_sc1113_kaneda_eyes0:
		.BYTE   8,$93,  1,  0
		.BYTE   8,$94,  1,  8
		.BYTE $80
_spr_sc1113_kaneda_eyes1:
		.BYTE   8,$8F,  1,  0
		.BYTE   8,$90,  1,  8
		.BYTE $80
_spr_sc13_kaneda_left_head:
		.BYTE   0,$97,  1,  0
		.BYTE   0,$98,  1,  8
		.BYTE   0,$99,  1,$10
		.BYTE   0,$9A,  1,$18
		.BYTE   0,$9B,  1,$20
		.BYTE   8,$9C,  1,  0
		.BYTE   8,$9D,  1,  8
		.BYTE   8,$9E,  1,$10
		.BYTE   8,$9F,  1,$18
		.BYTE   8,$A0,  1,$20
		.BYTE   8,$A1,  1,$28
		.BYTE $80
_spr_sc13_kaneda_left_mouth0:
		.BYTE $18,$A3,  1,  0
		.BYTE $20,$A5,  1,  0
		.BYTE $28,$A6,  1,  0
		.BYTE $80
_spr_sc13_kaneda_left_mouth1:
		.BYTE $18,$A8,  1,  0
		.BYTE $20,$AA,  1,  0
		.BYTE $28,$AB,  1,  0
		.BYTE $80
_spr_sc13_kaneda_left_eyes0:
		.BYTE $10,$A2,  1,  8
		.BYTE $18,$A4,  1,  8
		.BYTE $80
_spr_sc13_kaneda_left_eyes1:
		.BYTE $10,$A7,  1,  8
		.BYTE $18,$A9,  1,  8
		.BYTE $80
_spr_sc13_kaneda_without_arm:
		.BYTE   0,$D8,  1,$18
		.BYTE   0,$D9,  1,$20
		.BYTE   0,$DA,  1,$28
		.BYTE   0,$DB,  1,$30
		.BYTE   8,$DC,  1,  8
		.BYTE   8,$DD,  1,$10
		.BYTE   8,$DE,  1,$18
		.BYTE   8,$BA,  2,$20
		.BYTE   8,$BB,  2,$28
		.BYTE   8,$DF,  1,$30
		.BYTE $10,$BC,  1,  8
		.BYTE $10,$BD,  2,$10
		.BYTE $10,$BE,  2,$18
		.BYTE $10,$BF,  2,$20
		.BYTE $10,$C0,  2,$28
		.BYTE $10,$C1,  2,$30
		.BYTE $18,$C2,  2,  8
		.BYTE $18,$C3,  2,$10
		.BYTE $18,$C4,  2,$18
		.BYTE $18,$C5,  2,$20
		.BYTE $18,$C6,  2,$28
		.BYTE $18,$C7,  2,$30
		.BYTE $20,$C8,  2,  0
		.BYTE $20,$C9,  2,  8
		.BYTE $20,$CA,  2,$10
		.BYTE $20,$CB,  2,$18
		.BYTE $20,$CC,  2,$20
		.BYTE $28,$CD,  2,  0
		.BYTE $28,$CE,  2,  8
		.BYTE $28,$CF,  2,$10
		.BYTE $28,$D0,  2,$18
		.BYTE $28,$D1,  2,$20
		.BYTE $28,$D2,  1,$28
		.BYTE $30,$D3,  2,  0
		.BYTE $30,$D4,  2,  8
		.BYTE $30,$D5,  2,$10
		.BYTE $30,$D6,  2,$18
		.BYTE $30,$D7,  1,$28
		.BYTE $80
_spr_sc13_kaneda_with_rock0:
		.BYTE   0,$AC,  3,  0
		.BYTE   0,$AD,  3,  8
		.BYTE   8,$AE,  3,  0
		.BYTE   8,$AF,  3,  8
		.BYTE $10,$B0,  3,  0
		.BYTE $10,$B1,  3,  8
		.BYTE $80
_spr_sc13_kaneda_with_rock1:
		.BYTE   0,$B2,  3,  0
		.BYTE   0,$B3,  3,  8
		.BYTE   8,$B4,  3,  0
		.BYTE   8,$B5,  3,  8
		.BYTE $10,$B6,  3,  0
		.BYTE $10,$B7,  3,  8
		.BYTE $80
_spr_sc13_rubbles:
		.BYTE   0,$B8,  3,$20
		.BYTE   0,$B8,  3,$30
		.BYTE   8,$B8,  3,  0
		.BYTE $10,$B9,  3,  0
		.BYTE $20,$B8,  3,$28
		.BYTE $28,$B8,  3,$20
		.BYTE $28,$B9,  3,$28
		.BYTE $30,$B9,  3,$20
		.BYTE $80
_spr_sc13_cursor:
		.BYTE $F8,$FE,  3,$F8
		.BYTE $F8,$FE,$43,  0
		.BYTE   0,$FF,  3,$F8
		.BYTE   0,$FF,$43,  0
		.BYTE $80
_spr_sc13_kaneda_bullet0:
		.BYTE $FC,$FC,  3,$FC
		.BYTE $80
_spr_sc13_kaneda_bullet1:
		.BYTE $FC,$FD,  3,$FC
		.BYTE $80
_spr_sc13_tetsuo_body0:
		.BYTE   0,$E0,  1,  9
		.BYTE   8,$E1,  1,  8
		.BYTE   8,$E2,  1,$10
		.BYTE  $A,$EC,  2, $A
		.BYTE $10,$E3,  1,  0
		.BYTE $10,$E4,  1,  8
		.BYTE $10,$E5,  1,$10
		.BYTE $10,$ED,  2,$10
		.BYTE $18,$E6,  2,  8
		.BYTE $18,$E7,  2,$10
		.BYTE $20,$E8,  2,  8
		.BYTE $20,$E9,  2,$10
		.BYTE $28,$EA,  2,  8
		.BYTE $28,$EB,  2,$10
		.BYTE $80
_spr_sc13_tetsuo_body1:
		.BYTE   0,$EE,  1,  0
		.BYTE   0,$EF,  1,  8
		.BYTE   2,$F9,  2, $A
		.BYTE   8,$F0,  1,  0
		.BYTE   8,$F1,  1,  8
		.BYTE   8,$F8,  2, $D
		.BYTE $10,$F2,  2,  0
		.BYTE $10,$F3,  2,  8
		.BYTE $10,$F4,  2,$10
		.BYTE $18,$F5,  2,  0
		.BYTE $18,$F6,  2,  8
		.BYTE $18,$F7,  2,$10
		.BYTE $80
_spr_sc13_samples:
		.BYTE   0,$FA,  1,  0
		.BYTE   0,$FA,  1,  8
		.BYTE   0,$FA,  1,$18
		.BYTE   0,$FA,  1,$28
		.BYTE   8,$FB,  1,  0
		.BYTE   8,$FB,  1,  8
		.BYTE   8,$FB,  1,$18
		.BYTE   8,$FB,  1,$28
		.BYTE $80

;_spr_unref:
;		.BYTE $F8,$D7,  1,$FC		; it seems there are no such sprites
;		.BYTE   0,$D8,  1,$FC		; in CHR dat, no bank matching this
;		.BYTE   8,$D9,  1,$FC
;		.BYTE $80
;_spr_unref_0:
;		.BYTE $FC,$DA,  1,$F0
;		.BYTE $F4,$DB,  1,$F8
;		.BYTE $FC,$DC,  1,$F8
;		.BYTE   4,$DD,  1,$F8
;		.BYTE $FC,$DE,  1,  0
;		.BYTE $FC,$DF,  1,  8
;		.BYTE $80
;_spr_unref_1:
;		.BYTE $F0,$E0,  1,$F4
;		.BYTE $F0,$E1,  1,$FC
;		.BYTE $F8,$E2,  1,$F4
;		.BYTE $F8,$E3,  1,$FC
;		.BYTE $F8,$E4,  1,  4
;		.BYTE   0,$E5,  1,$F4
;		.BYTE   0,$E6,  1,$FC
;		.BYTE   0,$E7,  1,  4
;		.BYTE   8,$E8,  1,$F4
;		.BYTE   8,$E9,  1,$FC
;		.BYTE $80
;_spr_unref_2:
;		.BYTE $F0,$EA,  1,$F8
;		.BYTE $F0,$EB,  1,  0
;		.BYTE $F8,$EC,  1,$F8
;		.BYTE $F8,$ED,  1,  0
;		.BYTE   0,$EE,  1,$F8
;		.BYTE   0,$EF,  1,  0
;		.BYTE   8,$F0,  1,$F8
;		.BYTE   8,$F1,  1,  0
;		.BYTE $10,$F2,  1,$F8
;		.BYTE $10,$F3,  1,  0
;		.BYTE $80
;_spr_unref_3:
;		.BYTE $F0,$F4,  1,$F8
;		.BYTE $F0,$F5,  1,  0
;		.BYTE $F8,$F6,  1,$F0
;		.BYTE $F8,$F7,  1,$F8
;		.BYTE $F8,$F8,  1,  0
;		.BYTE   0,$F9,  1,$F0
;		.BYTE   0,$FA,  1,$F8
;		.BYTE   0,$FB,  1,  0
;		.BYTE   0,$FC,  1,  8
;		.BYTE   8,$FD,  1,$F0
;		.BYTE   8,$FE,  1,$F8
;		.BYTE   8,$FF,  1,  0
;		.BYTE $80

		SECTION_END 13
