
		SECTION_START 12

;-----------------------------------------------
; SCENE 12
;-----------------------------------------------

; original interactive script:
; BRANCH A {
; 	1. move->school
; 	2. move->stadium
; 	OPTION A {
; 		1. go on (jump SCENE 13, BRANCH A)
;	}
; 	OPTION B {
; 		1.1 stop
; 		1.2 [cancel menu with B] (jump OPTION A, probably bug or workaround for exit)
; 		2. check (cursor enabled)
;			- point laser (jump SCENE 13, BRANCH B)
;	}
; }
; BRANCH B {
; 	1. move->town (jump SCENE 12, BRANCH A)
; }

; modified interactive script:
; BRANCH A {
; 	1. move->school
; 	2. move->stadium
; 	OPTION A {
; 		1. go on (jump SCENE 13, BRANCH A)
;	}
; 	OPTION B {
; 		1.1 stop
; 		1.2 go on (jump SCENE 13, BRANCH A)
; 		2. check (cursor enabled)
;			- point laser
; 		3. go on (jump SCENE 13, BRANCH B)
;	}
; }
; BRANCH B {
; 	1. move->town (jump SCENE 12, BRANCH A)
; }

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene12_subs:
		JSR		_screen_cursor_handler
		JSR		_s12_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_6873F
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s12_sub00_clear_branch_select
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_generic_menu_input				; 03
		SW_PTR	_s12_menu_handlers				; 04
		SW_PTR	_s12_sub05_tv_show_draw			; entry for BRANCH A
		SW_PTR	_s12_sub06_tv_show_msg
		SW_PTR	_s12_sub02_tv_show_menu
		SW_PTR	_s12_sub0A_bike_storage_draw	; entry for BRANCH B
		SW_PTR	_s12_sub0B_bike_storage_msg
		SW_PTR	_s12_sub08_bike_storage_menu_loop
		SW_PTR	_s12_sub0C_kaneda_ride_draw0	; branches are concatenated here point of RETRY if laser not taken
		SW_PTR	_s12_sub0D_kaneda_ride_msg0
		SW_PTR	_s12_sub1E_clear
		SW_PTR	_s12_sub0E_tank_ruins_draw
		SW_PTR	_s12_sub0F_tank_ruins_msg
		SW_PTR	_s12_sub09_tank_ruins_menu0_loop
		SW_PTR	_s12_sub16_tank_ruins_menu1_loop; OPTION B branch for good ending!
		SW_PTR	_s12_sub15_tank_ruins_check_select
		SW_PTR	_s12_sub25_laser_taken			; new option
		SW_PTR	_s12_sub25_kaneda_ride_draw1
		SW_PTR	_s12_sub26_kaneda_ride_msg1
		SW_PTR	_s12_sub10_capsule_draw0		; OPTION A entry, common non-interactive scene
		SW_PTR	_s12_sub11_capsule_msg0
		SW_PTR	_s12_sub12_tetsuo_closeup_draw0
		SW_PTR	_s12_sub13_tetsuo_closeup_msg0
		SW_PTR	_s12_sub14_capsule_draw1
		SW_PTR	_s12_sub1F_capsule_msg1
		SW_PTR	_s12_sub20_capsule_msg2
		SW_PTR	_s12_sub21_capsule_msg3
		SW_PTR	_s12_sub17_tetsuo_closeup_draw1
		SW_PTR	_s12_sub18_tetsuo_closeup_msg1
		SW_PTR	_s12_sub19_samples_draw
		SW_PTR	_s12_sub1A_tetsuo_samples_msg0
		SW_PTR	_s12_sub1B_tetsuo_msg1
		SW_PTR	_s12_sub22_clear
		SW_PTR	_s12_sub23_colonel_draw
		SW_PTR	_s12_sub24_colonel_msg
		SW_PTR	_s12_sub1C_tetsuo_closeup_draw2
		SW_PTR	_s12_sub1D_tetsuo_closeup_msg

locret_6873F:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub00_clear_branch_select:
		LDA		_game_global_flags0
		AND		#8
		BNE		loc_6879F
		SW_NXT	_s12_sub05_tv_show_draw
		JMP		_clear_nt0
loc_6879F:
		LDA		_game_global_flags0
		AND		#$F7
		STA		_game_global_flags0
		SW_NXT	_s12_sub0A_bike_storage_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub05_tv_show_draw:
		SW_NXT	_s12_sub06_tv_show_msg
		LDA		#3
		STA		_scene_spr_overlay_idx
		TLM4	$36,$38,$5B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub06_tv_show_msg:
		JSR		_snd_tv_show_helicopter
		LDA		_scene_flags					; set flag for visiting in town, we need it first
		ORA		#1
		STA		_scene_flags
		SW_NXT	_s12_sub02_tv_show_menu
		MSG_M
		MSG		_sc12_msg00
		MSG		_sc12_msg01
		MSG		_sc12_msg02
		MSG		_sc12_msg03
		MSG		_sc12_msg04
		MSG		_sc12_msg05
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub02_tv_show_menu:
		LDA		_pads+1
		AND		#1
		BEQ		locret_687C5
		SW_RET	_s12_sub02_tv_show_menu
		LDA		#0
		JSR		_s12_menus_init
		JMP		_menu_draw_request
locret_687C5:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub08_bike_storage_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_6883F
		SW_RET	_s12_sub08_bike_storage_menu_loop
		LDA		#2
		JSR		_s12_menus_init
		JMP		_menu_draw_request
locret_6883F:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub0A_bike_storage_draw:
		SW_NXT	_s12_sub0B_bike_storage_msg
		LDA		#0
		STA		_scene_spr_overlay_idx
		TLM4	$37,$39,$5C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub0B_bike_storage_msg:
		SW_NXT	_s12_sub08_bike_storage_menu_loop
		LDA		_scene_flags					; going to school without completing the quest
		AND		#1								; just useless
		BEQ		loc_6887D
		MSG_M
		MSG		_sc12_msg06
		MSG		_sc12_msg07
		MSG		_sc12_msg25
		MSG		_sc12_msg24
		MSG		_sc11_12_13_msg97
		MSG_EOL
loc_6887D
		MSG_M
		MSG		_sc12_msg06
		MSG		_sc12_msg08
		MSG		_sc2_F_10_12_13_msg85
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub0C_kaneda_ride_draw0:
		SW_NXT	_s12_sub0D_kaneda_ride_msg0
		LDA		#1
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_tlm5D_draw:
		TLM4	$38,$3A,$5D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub0D_kaneda_ride_msg0:
		JSR		_snd_bike_ride
		SW_NXT	_s12_sub1E_clear
		MSG_M
		MSG		_sc12_msg09
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub1E_clear:
		JSR		_apu_reset						; unless other places, they shut down
		SW_FADE	_s12_sub0E_tank_ruins_draw		; overlay here after the fade out!
		LDA		#0
		STA		_scene_spr_overlay_idx
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub0E_tank_ruins_draw:
		SW_NXT	_s12_sub0F_tank_ruins_msg
		LDA		#2
		STA		_scene_spr_overlay_idx
		LDA		#0
		STA		_scene_anim_idx+2				; init laser draw
		TLM4	$39,$3B,$5E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub0F_tank_ruins_msg:
		JSR		_snd_near_stadium_with_beat
		SW_NXT	_s12_sub09_tank_ruins_menu0_loop
		MSG_1	_sc12_msg0A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub09_tank_ruins_menu0_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_68853
		SW_RET	_s12_sub09_tank_ruins_menu0_loop
		LDA		#5
		JSR		_s12_menus_init
		JMP		_menu_draw_request
locret_68853:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub16_tank_ruins_menu1_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_689D6
		SW_RET	_s12_sub16_tank_ruins_menu1_loop
;		SW_RET	_s12_sub09_tank_ruins_menu0_loop; ok, maybe we have it for on purose!
		LDA		#4								; because this allows us to return back to move
		JSR		_s12_menus_init					; option without need to take a laser, we actually can
		JMP		_menu_draw_request				; escape this route to the bad branch!
locret_689D6:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub10_capsule_draw0:
		SW_NXT	_s12_sub11_capsule_msg0

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_tlm5F_draw:
		LDA		#6
		STA		_scene_spr_overlay_idx
		LDA		#$40
		STA		_tmp_y_pos
		STA		_tmp_direction_y0
		STA		_tmp_cnt0
		STA		_tmp_cnt1
		LDA		#$50
		STA		_tmp_x_pos
		LDA		#$90
		STA		_tmp_direction_x0
		TLM4	$3A,$3C,$5F

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub11_capsule_msg0:
		JSR		_apu_reset
		JSR		_snd_violent_noise
		SW_FADE	_s12_sub12_tetsuo_closeup_draw0
		MSG_M
		MSG		_sc12_msg11
		MSG		_sc12_msg26
		MSG		_sc12_msg12
		MSG_WAIT								; 11 has no tetsuo mouth anim code
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub12_tetsuo_closeup_draw0:
		SW_NXT	_s12_sub13_tetsuo_closeup_msg0
		LDA		#4
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_tlmA0_draw:
		TLM5	$5E,$5E,$A0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub13_tetsuo_closeup_msg0:
		SW_FADE	_s12_sub14_capsule_draw1
		MSG_M
		MSG		_sc12_msg13
		MSG		_sc12_msg14
		MSG		_scF_12_13_15_msg93
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub14_capsule_draw1:
		SW_NXT	_s12_sub1F_capsule_msg1
		JMP		_s12_tlm5F_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub1F_capsule_msg1:
		SW_NXT	_s12_sub20_capsule_msg2
		MSG_M
		MSG		_sc12_msg15
		MSG		_sc12_msg27
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub20_capsule_msg2:
		SW_NXT	_s12_sub21_capsule_msg3			; chaining of messages is redundant here,
		MSG_M
		MSG		_sc12_msg16
		MSG		_sc12_msg28
		MSG_WAIT								; can be stored in one message list
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub21_capsule_msg3:
		SW_FADE	_s12_sub17_tetsuo_closeup_draw1
		MSG_M
		MSG		_sc12_msg17
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub17_tetsuo_closeup_draw1:
		SW_NXT	_s12_sub18_tetsuo_closeup_msg1
		LDA		#4
		STA		_scene_spr_overlay_idx
		JMP		_s12_tlmA0_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub18_tetsuo_closeup_msg1:
		JSR		_apu_reset
		JSR		_snd_hit_splash
		SW_FADE	_s12_sub19_samples_draw
		MSG_M
		MSG		_sc12_msg22
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub19_samples_draw:
		SW_NXT	_s12_sub1A_tetsuo_samples_msg0
		TLM5	$5A,$5A,$9D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub1A_tetsuo_samples_msg0:
		JSR		_snd_search_tetsuo_with_violent_noise
		SW_NXT	_s12_sub1B_tetsuo_msg1
		LDA		#5
		STA		_scene_spr_overlay_idx
		LDA		#0
		STA		_scene_anim_idx					; face back
		MSG_M
		MSG		_sc12_msg18
		MSG		_sc12_msg19
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub1B_tetsuo_msg1:
		SW_FADE	_s12_sub22_clear
		LDA		#1
		STA		_scene_anim_idx					; face forth
		MSG_M
		MSG		_sc12_msg20
		MSG		_sc12_msg1A
		MSG		_sc12_msg29
		MSG		_sc12_msg1B
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub22_clear:
		SW_NXT	_s12_sub23_colonel_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub23_colonel_draw:
		SW_NXT	_s12_sub24_colonel_msg
		LDA		#7
		STA		_scene_spr_overlay_idx
		EXJMP	_sF_icon46_draw					; defined in system bank

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub24_colonel_msg:
		SW_FADE	_s12_sub1C_tetsuo_closeup_draw2
		MSG_M
		MSG		_sc12_msg1C
		MSG		_sc12_msg1E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub1C_tetsuo_closeup_draw2:
		SW_NXT	_s12_sub1D_tetsuo_closeup_msg
		LDA		#4
		STA		_scene_spr_overlay_idx
		JMP		_s12_tlmA0_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub1D_tetsuo_closeup_msg:
		SW_FADE	_next_scene
		MSG_M
		MSG		_sc12_msg1D
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub15_tank_ruins_check_select:
		LDA		_pads+1
		AND		#1
		BEQ		locret_6898E
		JSR		_cursor_active_area_test
		CPX		#$FF
		BNE		loc_68974
		LDX		#3
loc_68974:
		LDA		#0
		STA		_active_areas_list_idx
		SW_NXT	_s12_sub16_tank_ruins_menu1_loop
		TXA
		SWITCH
		SW_PTR	_s12_sub15_tank_ruins_check_select_A
		SW_PTR	_s12_sub15_tank_ruins_check_select_B
		SW_PTR	_s12_sub15_tank_ruins_check_select_B
		SW_PTR	_s12_sub15_tank_ruins_check_select_C

locret_6898E:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub15_tank_ruins_check_select_A:
		LDA		_scene_flags					; reuse it now
		AND		#2
		BNE		_s12_sub15_tank_ruins_check_select_B; default fallback
		ORA		#2
		STA		_scene_flags
		SW_NXT	_s12_sub25_laser_taken			; animated scene
		MSG_M
		MSG		_sc12_msg0D
		MSG		_sc12_msg0E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub15_tank_ruins_check_select_B:
		MSG_1	_sc12_msg0F

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub15_tank_ruins_check_select_C:
		MSG_1	_sc12_msg10

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub25_laser_taken:
		LDA		#1
		STA		_scene_anim_idx+2				; init laser draw
		LDA		#$3F
		STA		_scene_anim_counter+2			; enable delay
		SW_NXT	_s12_sub16_tank_ruins_menu1_loop; return to menu
		MSG_1	_sc12_msg21

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub25_kaneda_ride_draw1:
		SW_NXT	_s12_sub26_kaneda_ride_msg1
		LDA		#1
		STA		_scene_spr_overlay_idx
		JMP		_s12_tlm5D_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_sub26_kaneda_ride_msg1:
		JSR		_snd_bike_ride
		SW_FADE	_s12_sub10_capsule_draw0
		MSG_M
		MSG		_sc12_msg09
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_menus_init:
		STA		_scene_menu_idx
		SW_NXT	_generic_menu_input
		LDA		_scene_menu_idx
		SWITCH
		SW_PTR	_scene_menu_init_default1
		SW_PTR	_scene_menu_init_default1
		SW_PTR	_scene_menu_init_default1
		SW_PTR	_s12_menu_init3
		SW_PTR	_scene_menu_init_default3
		SW_PTR	_scene_menu_init_default3

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_menu_init3:
		LDA		_scene_flags					; sometimes they did strange thig
		AND		#1
		STA		_scene_menu_items
		LDA		#0
		STA		_scene_menu_max_pos
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_menu_handlers:
		JSR		_menu_switch
		.WORD _s12_menu0
		.WORD _s12_menu1
		.WORD _s12_menu2
		.WORD _s12_menu3
		.WORD _s12_menu4
		.WORD _s12_menu5
_s12_menu0:
		.WORD _s12_menu0_move
_s12_menu1:
		.WORD _s12_menu1_school
_s12_menu2:
		.WORD _s12_menu2_move
_s12_menu3:
		.WORD _s12_menu3_town
		.WORD _s12_menu3_stadium
_s12_menu4:
		.WORD _s12_menu4_inquire
		.WORD _s12_menu4_check
		.WORD _s12_menu45_go_on					; new option here
_s12_menu5:
		.WORD _s12_menu5_check
		.WORD _s12_menu45_go_on
		.WORD _s12_menu5_stop

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_menu0_move:
		SW_NXT	_generic_menu_input
		LDA		#1
		STA		_scene_menu_idx
		JSR		_s12_menus_init
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_menu1_school:
		JSR		_apu_reset
		SW_NXT	_s12_sub0A_bike_storage_draw
		JMP		_fade_out_reqest

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_menu2_move:
		SW_NXT	_generic_menu_input
		LDA		#3
		STA		_scene_menu_idx
		JSR		_s12_menus_init
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_menu3_town:
		SW_NXT	_s12_sub05_tv_show_draw
		JMP		_fade_out_reqest

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_menu3_stadium:
		SW_NXT	_s12_sub0C_kaneda_ride_draw0
		JMP		_fade_out_reqest

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_menu4_inquire:
		SW_NXT	_s12_sub16_tank_ruins_menu1_loop
		MSG_1	_sc12_msg0B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_menu4_check:
		LDA		#6
		STA		_active_areas_list_idx
		LDA		#0
		STA		_screen_cursor_x+1
		LDA		#$40
		STA		_screen_cursor_y
		ASL
		STA		_screen_cursor_x
		SW_NXT	_s12_sub15_tank_ruins_check_select
		SW_CUR	_s12_sub15_tank_ruins_check_select
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_menu5_check:
		SW_NXT	_s12_sub09_tank_ruins_menu0_loop
		MSG_1	_sc12_msg0C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_menu45_go_on:
		SW_RLD	_s12_sub25_kaneda_ride_draw1	; any route lead to bike again now
		LDA		_scene_flags					; if we choose go on without getting a laser
		AND		#2								; raise that flag only, in other case it is
		BNE		.got_laser						; already clear
		LDA		_game_global_flags0
		ORA		#$10
		STA		_game_global_flags0
		SW_NXT	_fade_out_reload_scene
		MSG_M
		MSG		_sc12_msg23
		MSG_WAIT								; regular go on message will be here
		MSG_EOL
.got_laser
		SW_CUR	_fade_out_reload_scene			; force to fade out and jump next area
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_menu5_stop:
		LDA		_game_global_flags0				; we could get to this point from scene 13 after
		AND		#$EF							; game over, so we need to clear that flag here anyway.
		STA		_game_global_flags0
		SW_NXT	_s12_sub16_tank_ruins_menu1_loop
		MSG_1	_sc12_msg1F

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s12_spr_overlay1
		SW_PTR	_s12_spr_overlay2
		SW_PTR	_s12_spr_overlay3
		SW_PTR	_s12_spr_overlay4
		SW_PTR	_s12_spr_overlay5
		SW_PTR	_s12_spr_overlay6
		EXOFS	_sF_spr_overlay7				; defined in system bank

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_spr_overlay1:
		JSR		_pal_blink_animate
		SPR0	_spr_sc12_kaneda_bike_parts0,$30,$78
		SPR0	_spr_sc12_kaneda_bike_parts1,$68,$20
		SPR0J	_spr_sc12_kaneda_bike_parts2,$40,$B0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_spr_overlay3:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0SW	off_68D4B,$38,$80
		SPR0	_spr_sc12_tv_speaker_face,$38,$80
		LDA		_frames_counter
		LSR
		LSR
		AND		#1
		SPR0JSW	off_68D6E,$28,$48
off_68D6E:
		.WORD _spr_sc12_heli_blade0
		.WORD _spr_sc12_heli_blade1
off_68D4B:
		.WORD _spr_sc12_tv_speaker_mouth0
		.WORD _spr_sc12_tv_speaker_mouth1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_spr_overlay4:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0JSW	off_819E5,$58,$68
off_819E5:
		.WORD _spr_sc12_tetsuo_mouth0
		.WORD _spr_sc12_tetsuo_mouth1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_spr_overlay6:
 		JSR		_tetsuo_kei_animate
		LDA		_tmp_y_pos						; static sprites of tetsuo and kei
		STA		word_2							; intended to be animated, but isn't
		LDA		_tmp_x_pos						; let's fix it
		STA		word_2+1
		SPR0EX	_spr_sc12_tetsuo_fly_body0
		LDA		_tmp_direction_y0
		STA		word_2
		LDA		_tmp_direction_x0
		STA		word_2+1
		SPR0EX	_spr_sc12_kei_fly_body0
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tetsuo_kei_animate:
		LDA		_frames_counter
		AND		#$03
		BNE		.skip5
		LDA		_scene_anim_counter
		CLC
		ADC		#1
		STA		_scene_anim_counter
		PHA
		AND		#$F
		TAY
		LDA		_tetsuo_kei_hold_list,Y
		CLC
		ADC		_tmp_cnt0
		STA		_tmp_direction_y0
		PLA
		CLC
		ADC		#3
		AND		#$F
		TAY
		LDA		_tetsuo_kei_hold_list,Y
		CLC
		ADC		_tmp_cnt1
		STA		_tmp_y_pos
.skip5:
		RTS

_tetsuo_kei_hold_list:
		.BYTE $00,$02,$03,$04,$04,$04,$03,$02,$00,$FE,$FD,$FC,$FC,$FC,$FD,$FE

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_spr_overlay2:
		SPR0	_spr_sc12_truck_star,$70,$A8
		LDA		_scene_anim_idx+2
		BEQ		.do_laser
		LDA		_scene_anim_counter+2
		BEQ		.no_laser
		DEC		_scene_anim_counter+2
.do_laser:
		SPR0	_spr_sc12_truck_laser,$30,$D0
.no_laser:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s12_spr_overlay5:
		LDA		_scene_anim_idx
		SPR0JSW	off_68D8C,$20,$A0
off_68D8C:
		.WORD _spr_sc12_tetsuo_head_back
		.WORD _spr_sc12_tetsuo_head_face

_spr_sc12_tetsuo_mouth1:
		.BYTE   8,  2,  1,  0
		.BYTE   8,$FA,  1,  8
		.BYTE   8,$FB,  1,$10
		.BYTE $10,$FC,  2,  8
		.BYTE $10,$FD,  2,$10
		.BYTE $80
_spr_sc12_tetsuo_mouth0:
		.BYTE   0,$FE,  1,  8
		.BYTE   8,$F5,  1,  0
		.BYTE   8,$F6,  1,  8
		.BYTE   8,$F7,  1,$10
		.BYTE $10,$F8,  2,  8
		.BYTE $10,$F9,  2,$10
		.BYTE $80
_spr_sc12_kaneda_bike_parts0:
		.BYTE   0,$F0,  2,$10
		.BYTE   8,$F1,  2,  8
		.BYTE   8,$F2,  2,$18
		.BYTE $10,$F3,  2,  8
		.BYTE $10,$F4,  2,$10
		.BYTE $10,$F5,  2,$18
		.BYTE $19,$EE,  2,  2
		.BYTE $18,$F6,  2, $F
		.BYTE $20,$EF,  2,$10
		.BYTE $80
_spr_sc12_kaneda_bike_parts1:
		.BYTE   0,$EB,  1,  8
		.BYTE   0,$EC,  1,$18
		.BYTE   0,$ED,  1,$20
		.BYTE $10,$E9,  1,  0
		.BYTE $10,$EA,  1,  8
		.BYTE $80
_spr_sc12_kaneda_bike_parts2:
		.BYTE   0,$F7,  1,  8
		.BYTE   0,$F8,  1,$10
		.BYTE   8,$F9,  1,$18
		.BYTE $18,$FA,  1,$18
		.BYTE $28,$FB,  1,$18
		.BYTE $30,$FC,  1,  0
		.BYTE $30,$FD,  1,  8
		.BYTE $80
_spr_sc12_truck_laser:
		.BYTE   0,$DB,  1,  0
		.BYTE   0,$DC,  1,  8
		.BYTE   8,$DD,  1,  0
		.BYTE   8,$DE,  1,  8
		.BYTE   8,$DF,  1,$10
		.BYTE $10,$E0,  1,  0
		.BYTE $10,$E1,  1,  8
		.BYTE $10,$E2,  1,$10
		.BYTE $10,$E3,  1,$18
		.BYTE $18,$E4,  1,  8
		.BYTE $18,$E5,  1,$10
		.BYTE $18,$E6,  1,$18
		.BYTE $18,$E7,  1,$20
		.BYTE $20,$E8,  1,  0
		.BYTE $20,$E9,  1,  8
		.BYTE $20,$EA,  1,$10
		.BYTE $20,$EB,  1,$18
		.BYTE $20,$EC,  1,$20
		.BYTE $20,$ED,  1,$28
		.BYTE $28,$EE,  1,  0
		.BYTE $28,$EF,  1,  8
		.BYTE $28,$F0,  1,$10
		.BYTE $28,$F1,  1,$18
		.BYTE $28,$F2,  1,$20
		.BYTE $28,$F3,  1,$28
;		.BYTE $30,$BF,  1,  0		; why? this seems like garbage
		.BYTE $30,$F4,  1,  8
		.BYTE $30,$F5,  1,$10
		.BYTE $30,$F6,  1,$18
		.BYTE $30,$F7,  1,$20
		.BYTE $30,$F8,  1,$28
		.BYTE $80
_spr_sc12_truck_star:
		.BYTE   2,$F9,  2,  0
		.BYTE $80
_spr_sc12_tv_speaker_face:
		.BYTE   0,$DE,  1,  7
		.BYTE   0,$DF,  1, $F
		.BYTE   8,$E0,  1,  0
		.BYTE   8,$E3,  1,$18
		.BYTE $10,$E4,  1,  8
		.BYTE $10,$E5,  1,$10
		.BYTE $10,$E6,  1,$18
		.BYTE $80
_spr_sc12_tv_speaker_mouth1:
		.BYTE   8,$E1,  1,  8
		.BYTE   8,$E2,  1,$10
		.BYTE $80
_spr_sc12_tv_speaker_mouth0:
		.BYTE   8,$AA,  1,  8
		.BYTE   8,$AB,  1,$10
		.BYTE $80
_spr_sc12_heli_blade0:
		.BYTE   0,$E7,  1,  0
		.BYTE   0,$E8,  1,  8
		.BYTE   0,$E7,  1,$10
		.BYTE $80
_spr_sc12_heli_blade1:
		.BYTE   0,$E7,  1,$20
		.BYTE   0,$E8,  1,$28
		.BYTE   0,$E7,  1,$30
		.BYTE $80
_spr_sc12_tetsuo_head_back:
		.BYTE   0,$80,  2,  0
		.BYTE   0,$B9,  2,  8
		.BYTE   0,$82,  2,$10
		.BYTE   0,$83,  2,$18
		.BYTE   8,$88,  2,  0
		.BYTE   8,$BE,  2,  8
		.BYTE   8,$BE,  2,$10
		.BYTE   8,$BE,  2,$18
		.BYTE $10,$89,  2,  0
		.BYTE $10,$8A,  2,  8
		.BYTE $10,$BE,  2,$10
		.BYTE $10,$BE,  2,$18
		.BYTE $18,$8B,  2,  0
		.BYTE $18,$8C,  2,  8
		.BYTE $18,$8D,  2,$10
		.BYTE $18,$8E,  2,$18
		.BYTE $20,$84,  2,  0
		.BYTE $20,$85,  2,  8
		.BYTE $20,$86,  2,$10
		.BYTE $20,$87,  2,$18
		.BYTE $80
_spr_sc12_tetsuo_head_face:
		.BYTE   0,$A8,  2,  0
		.BYTE   0,$A9,  2,  8
		.BYTE   0,$AA,  2,$10
		.BYTE   0,$AB,  2,$18
		.BYTE   8,$AC,  2,  0
		.BYTE   8,$AD,  2,  8
		.BYTE   8,$AE,  2,$10
		.BYTE   8,$BE,  2,$18
		.BYTE $10,$AF,  1,  0
		.BYTE $10,$B0,  1,  8
		.BYTE $10,$BF,  2,$10
		.BYTE $10,$B1,  2,$18
		.BYTE $18,$B2,  1,  0
		.BYTE $18,$B3,  1,  8
		.BYTE $18,$B4,  2,$10
		.BYTE $18,$B5,  2,$18
		.BYTE $20,$B6,  2,  0
		.BYTE $20,$B7,  2,  8
		.BYTE $20,$B8,  2,$10
		.BYTE $20,$87,  2,$18
		.BYTE $80
_spr_sc12_tetsuo_fly_body0:
		.BYTE   0,$92,  1, $C
		.BYTE   0,$A0,  1,$10
		.BYTE   0,$A1,  1,$18
		.BYTE   8,$B6,  2,  3
		.BYTE   8,$96,  1,  8
		.BYTE   8,$A2,  1,$10
		.BYTE $10,$B7,  2,  3
		.BYTE $10,$A3,  1,  8
		.BYTE $10,$A4,  1,$10
		.BYTE $18,$B8,  2,  3
		.BYTE $18,$A5,  1,  8
		.BYTE $18,$A6,  1,$10
		.BYTE $80
_spr_sc12_kei_fly_body0:
		.BYTE   0,$93,  2,  4
		.BYTE   8,$98,  2,  0
		.BYTE   8,$99,  2,  8
		.BYTE $10,$AC,  2,  0
		.BYTE $10,$AD,  2,  8
		.BYTE $18,$AE,  2,  0
		.BYTE $18,$AF,  2,  8
		.BYTE $80

		SECTION_END 12
