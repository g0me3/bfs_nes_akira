
		SECTION_START 2

;-----------------------------------------------
; SCENE 2 (WAITING ROOM)
;-----------------------------------------------

; original interactive script:
; 1. check->peek (cursor enabled)
; 	- point girl in orange x 2 (ask out added)
; 2. ask out
; BRANCH A {
; 	1. any option
; 	2.x any option (game over, restart SCENE 1)
; }
; BRANCH B {
; 	1. yell
; 	2. take cover
; 	3. army (talk appears)
; 	4. talk (jump SCENE 3)
; }

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene2_subs:
		JSR		_screen_cursor_handler
		JSR		_s2_spr_overlay_set
		LDA		_nmi_ppu_draw0_req
		BNE		locret_8EE9
		LDA		_draw_state_idx
		BNE		locret_8EE9
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s2_sub00_clear					; most of scenes uses 00 as jumper to 05
		SW_PTR	_next_scene						; let assume it's 01 always
		SW_PTR	_fade_out_reload_scene			; 02 accordingly
		SW_PTR	_generic_menu_input				; 03, then
		SW_PTR	_s2_menu_handlers				; should be 04 as well
		SW_PTR	_s2_sub05_gym_draw_nt1			; assume that this is actual entry for scene (05)
		SW_PTR	_s2_sub0E_gym_draw_nt0
		SW_PTR	_s2_sub06_gym_init_msg
		SW_PTR	_s2_sub02_scene_main_loop
		SW_PTR	_s2_sub07_gym_pick
		SW_PTR	_s2_sub08_gym_menu2
		SW_PTR	_s2_sub0A_gym_menu3
		SW_PTR	_s2_sub0Fa_terrorist_speech
		SW_PTR	_s2_sub0F_terrorist_stop
		SW_PTR	_s2_sub0Ba_terrorist_punch
		SW_PTR	_s2_sub0B_terrorist_punch
		SW_PTR	_s2_sub0C_terrorist_over
		SW_PTR	_s2_sub0D_gym_menu5
		SW_PTR	_s2_sub10_game_over_prison
		SW_PTR	_s2_sub12_dead_msg
		SW_PTR	_s2_sub12_game_over_dead
		SW_PTR	_s2_sub14_clear
		SW_PTR	_s2_sub15_girl_draw
		SW_PTR	_s2_sub16_girl_msg
		SW_PTR	_s2_sub13_gym_redraw_nt1
		SW_PTR	_s2_sub17_gym_redraw_nt0

locret_8EE9:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub00_clear:
		JSR		_scroll_reset
		SW_NXT	_s2_sub05_gym_draw_nt1
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub05_gym_draw_nt1:
		SW_NXT	_s2_sub0E_gym_draw_nt0

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_tlm4F_draw:
		LDA		#$4F
		JMP		_tlm_nt1_draw_mode4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub0E_gym_draw_nt0:
		SW_NXT	_s2_sub06_gym_init_msg
		LDA		#1
		STA		_forbid_sub_cur_backup_trigger

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_tlm05_draw:
		TLM4	5,$13,5

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub02_scene_main_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_8F43
		SW_RET	_s2_sub02_scene_main_loop
		LDA		#0
		JSR		_s2_menu_inits
		JMP		_menu_draw_request
locret_8F43:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub06_gym_init_msg:
		SW_NXT	_s2_sub02_scene_main_loop
		MSG_M
		MSG		_sc2_msg00
		MSG		_sc2_msg0E
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub07_gym_pick:
		LDA		_pads+1
		AND		#1
		BEQ		locret_8FA3
		JSR		_cursor_active_area_test
		CPX		#$FF
		BNE		loc_8F96
		LDX		#$A
loc_8F96:
		LDA		#0
		STA		_active_areas_list_idx
		SW_NXT	_s2_sub02_scene_main_loop
		TXA
		SWITCH
		SW_PTR	_s2_sub07_gym_pick_0
		SW_PTR	_s2_sub07_gym_pick_1
		SW_PTR	_s2_sub07_gym_pick_2
		SW_PTR	_s2_sub07_gym_pick_3
		SW_PTR	_s2_sub07_gym_pick_4
		SW_PTR	_s2_sub07_gym_pick_5
		SW_PTR	_s2_sub07_gym_pick_6
		SW_PTR	_s2_sub07_gym_pick_7
		SW_PTR	_s2_sub07_gym_pick_8
		SW_PTR	_s2_sub07_gym_pick_9
		SW_PTR	_s2_sub07_gym_pick_A

locret_8FA3:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub07_gym_pick_0:
		MSG_1	_sc2_msg03

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub07_gym_pick_1:
		MSG_1	_sc2_msg08

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub07_gym_pick_2:
		MSG_1	_sc2_msg07

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub07_gym_pick_3:
		MSG_1	_sc2_msg09

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub07_gym_pick_4:
		MSG_1	_sc2_msg04

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub07_gym_pick_5:
		MSG_1	_sc2_msg06

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub07_gym_pick_6:
		MSG_1	_sc2_msg0F

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub07_gym_pick_7:
		MSG_1	_sc2_msg16

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub07_gym_pick_8:
		MSG_1	_sc2_msg05

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub07_gym_pick_9:
		LDA		_game_global_flags0
		AND		#1
		BEQ		loc_9455
		LDA		_scene_flags					; ask aut flag raise
		ORA		#1
		STA		_scene_flags
		MSG_1	_sc2_msg14						; "oh! cute girl!"
loc_9455:
		LDA		_scene_flags
		AND		#1
		BNE		loc_9484
		LDA		_scene_states
		BNE		loc_9471
		INC		_scene_states
		MSG_1	_sc2_msg0A						; "i've seen this person before"
loc_9471:
		LDA		_scene_flags
		ORA		#1
		STA		_scene_flags
		SW_FADE	_s2_sub14_clear					; gotcha!
		RTS
loc_9484:
		MSG_1	_sc2_msg28						; "planning on stay here?"

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub07_gym_pick_A:
		MSG_1	_sc2_msg02

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub08_gym_menu2:
		LDA		#1
		STA		_scene_anim_idx+3
		STA		_scroll_x_shadow+1
		LDA		#$4F
		STA		_menu_restore_tlm_idx_list+1	; for two-screen scenes, manually set the second one
		LDA		_pads+1							; index for menu restoration
		AND		#1
		BEQ		locret_8FD2
		LDA		#0
		STA		_scene_states+1
		SW_RET	_s2_sub08_gym_menu2
		LDA		#2
		JSR		_s2_menu_inits
		JMP		_menu_draw_request
locret_8FD2:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub0A_gym_menu3:
		LDA		_pads+1
		AND		#1
		BEQ		locret_8FF7
		SW_RET	_s2_sub0A_gym_menu3
		LDA		#3
		JSR		_s2_menu_inits
		JMP		_menu_draw_request
locret_8FF7:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
; the moment scene changes terrorist to army it
; changes the chr bank immediately, for at least one
; frame the terrorist drawn with a wrong bank,
; let's just disable it for this frame to look better
;
_s2_sub0Ba_terrorist_punch:
		LDA		#0
		STA		_scene_spr_overlay_idx
		SW_NXT	_s2_sub0B_terrorist_punch
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub0B_terrorist_punch:
		LDA		#3
		STA		_scene_spr_overlay_idx
		SW_NXT	_s2_sub0C_terrorist_over
		CHRPAL	$F,4
		MSG_M
		MSG		_sc2_msg1C
		MSG		_sc2_msg1D
		MSG		_sc2_msg1E
		MSG		_sc2_F_10_12_13_msg85
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub0C_terrorist_over:
		LDA		#4
		STA		_scene_spr_overlay_idx
		SW_NXT	_s2_sub0D_gym_menu5
		MSG_1	_sc2_msg1F

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub0D_gym_menu5:
		LDA		_pads+1
		AND		#1
		BEQ		locret_904C
		SW_RET	_s2_sub0D_gym_menu5
		LDA		#5
		JSR		_s2_menu_inits
		JMP		_menu_draw_request
locret_904C:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
; previously unused terrorist's line restored here
; so we can see its facial animation as well lol
;
_s2_sub0Fa_terrorist_speech:
		SW_NXT	_s2_sub0F_terrorist_stop
		MSG_M
		MSG		_sc2_msg18
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub0F_terrorist_stop:
		JSR		_apu_reset
		LDA		#2
		STA		_scene_anim_idx+3
		SW_NXT	_s2_sub0Ba_terrorist_punch
		MSG_M
		MSG		_sc2_msgBA
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub10_game_over_prison:
		JSR		_s2_game_over_select			; scene selection is the same, but game overs
		JMP		_game_over_prison_start			; are different

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub12_dead_msg:
		JSR		_snd_grenade_explosion
		SW_FADE	_s2_sub12_game_over_dead
		MSG_M
		MSG		_sc2_msg13
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub12_game_over_dead:
		JSR		_s2_game_over_select
		JMP		_game_over_dead_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
; select to return to scene 1 back or stay in scene 2
;
_s2_game_over_select:
		LDA		_game_global_flags0
		AND		#1
		BNE		loc_9090
		JSR		_scene_vars_init				; x is not saved here
		LDX		#2								; index
		BNE		loc_9091
loc_9090:
		LDX		#1
loc_9091:
		LDY		#0								; start either scene 2 or 1 from beginning, so just 0
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub13_gym_redraw_nt1:
		SW_NXT	_s2_sub17_gym_redraw_nt0
		JMP		_s2_tlm4F_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub14_clear:
		SW_NXT	_s2_sub15_girl_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub15_girl_draw:
		SW_NXT	_s2_sub16_girl_msg
		LDA		#0
		STA		_scene_anim_counter
		LDA		#5
		STA		_scene_spr_overlay_idx
		ICON1	6,5,6

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub16_girl_msg:
		JSR		_snd_girl_detected
		SW_FADE	_s2_sub13_gym_redraw_nt1
		MSG_M
		MSG		_sc2_msg0B
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_sub17_gym_redraw_nt0:
		LDA		#0
		STA		_scene_spr_overlay_idx
		SW_NXT	_s2_sub02_scene_main_loop
		JMP		_s2_tlm05_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu_inits:
		STA		_scene_menu_idx
		SW_NXT	_generic_menu_input
		LDA		_scene_menu_idx
		SWITCH
		.WORD	_s2_menu_init0
		.WORD	_scene_menu_init_default2
		.WORD	_scene_menu_init_default3
		.WORD	_scene_menu_init_default5
		.WORD	_scene_menu_init_default3
		.WORD	_s2_menu_init5

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu_init0:
		LDA		_scene_flags
		AND		#1
		BEQ		loc_9383
		JMP		_scene_menu_init_default3
loc_9383:
		JMP		_scene_menu_init_default2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu_init5:
		LDA		_scene_flags
		AND		#$10
		BEQ		loc_93EA
		JMP		_scene_menu_init_default3
loc_93EA:
		JMP		_scene_menu_init_default2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu_handlers:
		JSR		_menu_switch
		.WORD _s2_menu0
		.WORD _s2_menu1
		.WORD _s2_menu2
		.WORD _s2_menu3
		.WORD _s2_menu4
		.WORD _s2_menu5
_s2_menu0:
		.WORD _s2_menu0_inquire
		.WORD _s2_menu0_check
		.WORD _s2_menu0_ask_out
_s2_menu1:
		.WORD _s2_menu1_nearby
		.WORD _s2_menu1_pick
_s2_menu2:
		.WORD _s2_menu2_yell
		.WORD _s2_menu2_panic
		.WORD _s2_menu2_jump
_s2_menu3:
		.WORD _s2_menu2_run
		.WORD _s2_menu2_tackle
		.WORD _s2_menu2_take_cover
		.WORD _s2_menu2_stare
		.WORD _s2_menu2_pray
_s2_menu4:
		.WORD _s2_menu4_nearby
		.WORD _s2_menu4_girl
		.WORD _s2_menu4_army
_s2_menu5:
		.WORD _s2_menu5_go_back
		.WORD _s2_menu5_look
		.WORD _s2_menu5_talk

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu0_inquire:
		SW_NXT	_s2_sub02_scene_main_loop
		MSG_1	_sc2_msg01

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu0_check:
		LDA		#1
		JSR		_s2_menu_inits
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu0_ask_out:
		JSR		_snd_terrorist_with_grenade
		JSR		_snd_grenade_hissss
		LDA		#1
		STA		_scene_spr_overlay_idx
		SW_NXT	_s2_sub08_gym_menu2
		MSG_1	_sc2_msg0C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu1_nearby:
		SW_NXT	_s2_sub02_scene_main_loop
		MSG_1	_sc2_msg02

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu1_pick:
		SW_NXT	_s2_sub07_gym_pick
		SW_CUR	_s2_sub07_gym_pick
		LDA		#3
		STA		_active_areas_list_idx
		LDA		#0
		STA		_screen_cursor_x+1
		LDA		#$40
		STA		_screen_cursor_y
		ASL
		STA		_screen_cursor_x
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu2_yell:
		LDA		#0
		STA		_scene_states+1
		SW_NXT	_s2_sub0A_gym_menu3
		MSG_1	_sc2_13_15_16_msg82

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu2_panic:
		LDA		#1
		STA		_scene_states+1
		SW_NXT	_s2_sub0A_gym_menu3
		MSG_1	_sc2_6_msg83

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu2_jump:
		LDA		#2
		STA		_scene_states+1
		SW_NXT	_s2_sub0A_gym_menu3
		MSG_1	_sc2_13_msgA0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu2_run:
		SW_FADE	_s2_sub10_game_over_prison
		MSG_M
		MSG		_sc2_msg10
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu2_tackle:
		SW_NXT	_s2_sub12_dead_msg
		MSG_M
		MSG		_sc2_msg12
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu2_take_cover:
		LDA		_game_global_flags0				; take cover only works if you doesn't laugh, goddamit!
		AND		#1
		BNE		loc_9281
		LDA		_scene_states+1					; index what you selected before
		SWITCH
		SW_PTR	_s2_menu2_take_cover_A			; yell
		SW_PTR	_s2_menu2_take_cover_B			; panic
		SW_PTR	_s2_menu2_take_cover_C			; jump
loc_9281:
		SW_NXT	_s2_sub12_dead_msg
		MSG_M
		MSG		_sc2_msgA2
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu2_take_cover_A:
		SW_NXT	_s2_sub0Fa_terrorist_speech
		LDA		_scene_flags
		ORA		#2
		STA		_scene_flags
		MSG_M
		MSG		_sc2_msg15
		MSG		_sc2_F_10_12_13_msg85
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu2_take_cover_B:
		SW_NXT	_s2_sub08_gym_menu2
		MSG_1	_sc2_msgA2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu2_take_cover_C:
		SW_FADE	_s2_sub10_game_over_prison
		MSG_M
		MSG		_sc2_msg19						; here we have msg1A for take cove and pray commands!
		MSG		_sc2_msg1A
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu2_stare:
		SW_NXT	_s2_sub12_dead_msg
		MSG_M
		MSG		_sc2_F_10_12_13_msg85
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu2_pray:
		SW_FADE	_s2_sub10_game_over_prison
		MSG_M
		MSG		_sc2_15_msgA1
		MSG		_sc2_msg17
		MSG		_sc2_msg1A
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu4_nearby:
		SW_NXT	_s2_sub0D_gym_menu5
		LDA		_scene_flags
		AND		#4
		BNE		loc_92D2
		MSG_1	_sc2_msg23
loc_92D2:
		LDA		_scene_flags
		ORA		#8
		STA		_scene_flags
		MSG_1	_sc2_msg21

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu4_girl:
		SW_NXT	_s2_sub0D_gym_menu5
		LDA		_scene_flags
		ORA		#4
		STA		_scene_flags
		MSG_1	_sc2_msg22

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu4_army:
		SW_NXT	_s2_sub0D_gym_menu5
		LDA		_scene_flags
		ORA		#$10
		STA		_scene_flags
		MSG_1	_sc2_msg0D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu5_go_back:
		SW_FADE	_s2_sub12_game_over_dead
		MSG_M
		MSG		_sc2_msg20
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu5_look:
		LDA		#4
		JSR		_s2_menu_inits
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_menu5_talk:
		SW_FADE	_next_scene
		MSG_M
		MSG		_sc2_msg24
		MSG		_sc2_msg25
		MSG		_sc2_msg26
		MSG		_sc2_msg27
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s2_spr_overlay1
		SW_PTR	_nullsub
		SW_PTR	_s2_spr_overlay3
		SW_PTR	_s2_spr_overlay4
		SW_PTR	_s2_spr_overlay5

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_spr_overlay1:
		LDA		_scene_anim_idx+3
		CMP		#2
		BEQ		loc_953F
		JSR		_do_scene_anim0_pat0101			; here is anim for terrorists mouth. there is no
		LDA		_scene_anim_idx					; speech lines used in final version, and one
		SPR0SW	off_956C,$38,$68				; unused line uses idx=0 instead, fixed in this version
loc_953F:
		SPR0	_spr_sc2_terrorist_body,$38,$68
		LDA		_scene_anim_idx+3
		SPR0SW	off_9572,$38,$68
		LDA		_scene_anim_idx+3
		CMP		#1
		BNE		locret_94BB
		LDA		_frames_counter
		LSR
		LSR
		AND		#3
		SPR0SW	off_9595,$30,$68
locret_94BB:
		RTS
off_9595:
		.WORD _spr_sc2_grenade0
		.WORD _spr_sc2_grenade0
		.WORD _spr_sc2_grenade2
		.WORD _spr_sc2_grenade3
off_956C:
		.WORD _spr_sc2_terror_mouth_open
		.WORD _spr_sc2_terror_mouth_closed
off_9572:
		.WORD _spr_sc2_terrorist_hands0
		.WORD _spr_sc2_terrorist_hands1
		.WORD _spr_sc2_terrorist_hands2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_spr_overlay3:
		SPR0	_spr_sc2_police_and_terrors,$48,$68
		LDA		_tmp_cnt0
		BEQ		loc_94CB
		DEC		_tmp_cnt0
locret_94BE:
		RTS
loc_94CB:
		SPR0	_spr_sc2_police_punch_hand,$48,$68
		LDA		_frames_counter
		AND		#$1F
		BNE		locret_94BE
		LDA		_rand
		AND		#$F
		ORA		#$10
		STA		_tmp_cnt0
		LDA		_rand
		AND		#3
		SWITCH
		SW_PTR	_snd_punch0
		SW_PTR	_snd_punch1
		SW_PTR	_snd_punch2
		SW_PTR	_nullsub

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_spr_overlay4:
		SPR0	_spr_sc2_army_in_gym_body,$30,$10
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0JSW	off_502A1,$30,$10
off_502A1:
		.WORD _spr_sc2_army_in_gym_mouth0
		.WORD _spr_sc2_army_in_gym_mouth1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s2_spr_overlay5:
		LDA		_scene_anim_counter
		CMP		#$60
		BCS		loc_9513
		LSR
		LSR
		LSR
		LSR
		LSR
		AND		#3
		TAX
		LDA		byte_9516,X
		STA		_scene_anim_idx
		INC		_scene_anim_counter
loc_9513:
		LDA		_scene_anim_idx
		SPR0JSW	off_95B7,$58,$70
off_95B7:
		.WORD _spr_sc2_girl_in_gym_eyes_left
		.WORD _spr_sc2_girl_in_gym_eyes_right
byte_9516:
		.BYTE   0,  1,  0,  0

_spr_sc2_police_punch_hand:
		.BYTE   8,$D8,  3,  0
		.BYTE   8,$DC,  3,  8
		.BYTE $10,$E3,  3,  0
		.BYTE $80
_spr_sc2_terrorist_body:
		.BYTE $18,$F7,  1,$10
		.BYTE $18,$F7,$41,$18
		.BYTE $20,$F9,  1,$10
		.BYTE $20,$F9,$41,$18
		.BYTE $28,$FA,  1,$10
		.BYTE $28,$FA,$41,$18
		.BYTE $30,$FB,  1,$10
		.BYTE $30,$FB,$41,$18
		.BYTE $38,$FC,  1, $D
		.BYTE $38,$FC,$41,$1A
		.BYTE $80
_spr_sc2_terrorist_hands0:
		.BYTE   0,$E2,  1,$10
		.BYTE   0,$E3,  1,$18
		.BYTE   8,$F1,  1,  8
		.BYTE   8,$F1,$41,$20
		.BYTE $10,$F4,  1,  8
		.BYTE $10,$F5,  1,$10
		.BYTE $10,$F6,  1,$18
		.BYTE $10,$F4,$41,$20
		.BYTE $80
_spr_sc2_terrorist_hands1:
		.BYTE   0,$E2,  1,$10
		.BYTE   0,$E3,  1,$18
		.BYTE   8,$E5,  1,  8
		.BYTE   8,$E6,  1,$10
		.BYTE   8,$E7,  1,$18
		.BYTE   8,$E8,  1,$20
		.BYTE $10,$EB,  1,  0
		.BYTE $10,$EC,  1,  8
		.BYTE $10,$ED,  1,$10
		.BYTE $10,$EE,  1,$18
		.BYTE $10,$EF,  1,$20
		.BYTE $10,$F0,  1,$28
		.BYTE $80
_spr_sc2_terrorist_hands2:
		.BYTE   0,$E0,  1,$10
		.BYTE   0,$E1,  1,$18
		.BYTE   8,$E5,  1,  8
		.BYTE   8,$E9,  1,$10
		.BYTE   8,$EA,  1,$18
		.BYTE   8,$E8,  1,$20
		.BYTE $10,$EB,  1,  0
		.BYTE $10,$EC,  1,  8
		.BYTE $10,$ED,  1,$10
		.BYTE $10,$EE,  1,$18
		.BYTE $10,$EF,  1,$20
		.BYTE $10,$F0,  1,$28
		.BYTE $80
_spr_sc2_terror_mouth_closed:
		.BYTE   8,$F2,  1,$10
		.BYTE   8,$F3,  1,$18
		.BYTE $80
_spr_sc2_terror_mouth_open:
		.BYTE   8,$E6,  1,$10
		.BYTE   8,$E7,  1,$18
		.BYTE $80
_spr_sc2_grenade0:
		.BYTE $10,$F8,  2,  0
		.BYTE $80
_spr_sc2_grenade2:
		.BYTE   8,$DE,  2,  0
		.BYTE $10,$DF,  2,  0
		.BYTE $80
_spr_sc2_grenade3:
		.BYTE   0,$DD,  2,  0
		.BYTE   8,$DE,  2,  0
		.BYTE $10,$DF,  2,  0
		.BYTE $80
_spr_sc2_girl_in_gym_eyes_left:
		.BYTE   0,$FA,  3,  8
		.BYTE   0,$FB,  3,$10
		.BYTE   8,$FC,  3,  0
		.BYTE   8,$FD,  3,  8
		.BYTE   8,$AE,  3,$10
		.BYTE $10,$AF,  3,  0
		.BYTE $10,$B0,  3,  8
		.BYTE $80
_spr_sc2_girl_in_gym_eyes_right:
		.BYTE   0,$AA,  3,  8
		.BYTE   0,$AB,  3,$10
		.BYTE   8,$AC,  3,  0
		.BYTE   8,$AD,  3,  8
		.BYTE   8,$AE,  3,$10
		.BYTE $10,$AF,  3,  0
		.BYTE $10,$B0,  3,  8
		.BYTE $80
_spr_sc2_army_in_gym_mouth1:
		.BYTE $10,$B8,  2,$18
		.BYTE $80
_spr_sc2_army_in_gym_mouth0:
		.BYTE $10,$F9,  2,$18
		.BYTE $80
_spr_sc2_army_in_gym_body:
		.BYTE   0,$B1,  2,$10
		.BYTE   0,$B2,  2,$18
		.BYTE   0,$B3,  2,$20
		.BYTE   8,$B4,  2,$10
		.BYTE   8,$B5,  1,$18
		.BYTE   8,$B4,$41,$20
		.BYTE $10,$B6,  2,  8
		.BYTE $10,$B7,  2,$10
		.BYTE $10,$B7,$41,$20
		.BYTE $10,$B6,$41,$28
		.BYTE $18,$B9,  2,  0
		.BYTE $18,$BA,  2,  8
		.BYTE $18,$BB,  2,$10
		.BYTE $18,$BC,  2,$18
		.BYTE $18,$BD,  2,$20
		.BYTE $18,$BE,  2,$28
		.BYTE $18,$B9,$42,$30
		.BYTE $20,$BF,  2,  0
		.BYTE $20,$C0,  2,  8
		.BYTE $20,$C1,  2,$10
		.BYTE $20,$C2,  2,$18
		.BYTE $20,$C4,  2,$20
		.BYTE $20,$C5,  2,$28
		.BYTE $20,$C6,  2,$30
		.BYTE $28,$C7,  2,  0
		.BYTE $28,$C8,  2,  8
		.BYTE $28,$C9,  2,$10
		.BYTE $28,$CA,  2,$18
		.BYTE $28,$CB,  2,$20
		.BYTE $28,$CC,  2,$28
		.BYTE $28,$C7,$42,$30
		.BYTE $30,$CD,  2,  8
		.BYTE $30,$D7,  2,$10
		.BYTE $30,$D1,  2,$18
		.BYTE $30,$D7,  2,$20
		.BYTE $30,$CD,$42,$28
		.BYTE $38,$CE,  2,  8
		.BYTE $38,$D2,  2,$10
		.BYTE $38,$D3,  2,$18
		.BYTE $38,$D2,$42,$20
		.BYTE $38,$CE,$42,$28
		.BYTE $40,$CF,  2,  8
		.BYTE $40,$D4,  2,$10
		.BYTE $40,$D5,  2,$18
		.BYTE $40,$D4,$42,$20
		.BYTE $40,$CF,$42,$28
		.BYTE $48,$D0,  2,  8
		.BYTE $48,$D7,  2,$10
		.BYTE $48,$D6,  2,$18
		.BYTE $48,$D7,$42,$20
		.BYTE $48,$D0,$42,$28
		.BYTE $80
_spr_sc2_police_and_terrors:
		.BYTE   0,$D9,  3, $D
		.BYTE   0,$DA,  3,$15
		.BYTE   0,$DB,  3,$1D
		.BYTE   8,$DD,  3,  8
		.BYTE   8,$DE,  3,$10
		.BYTE   8,$DF,  3,$18
		.BYTE   8,$E0,  3,$20
		.BYTE   8,$E1,  3,$28
		.BYTE $10,$E2,  3,  0
		.BYTE $10,$FE,  3,  8
		.BYTE $10,$FE,  3,$10
		.BYTE $10,$E4,  3,$18
		.BYTE $10,$E5,  3,$20
		.BYTE $10,$E6,  3,$28
		.BYTE $18,$E7,  3,  0
		.BYTE $18,$E8,  3,  8
		.BYTE $18,$E9,  3,$10
		.BYTE $18,$EA,  3,$18
		.BYTE $18,$EB,  3,$20
		.BYTE $18,$EC,  3,$28
		.BYTE $20,$ED,  3,  0
		.BYTE $20,$EE,  3,  8
		.BYTE $20,$EF,  3,$10
		.BYTE $20,$F0,  3,$18
		.BYTE $20,$F1,  3,$20
		.BYTE $20,$F2,  3,$28
		.BYTE $28,$F3,  3,  0
		.BYTE $28,$F4,  3,  8
		.BYTE $28,$F5,  3,$10
		.BYTE $28,$F6,  3,$18
		.BYTE $28,$F7,  3,$20
		.BYTE $28,$F8,  3,$28
		.BYTE $80

		SECTION_END 2
