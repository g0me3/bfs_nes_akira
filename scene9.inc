
		SECTION_START 9

;-----------------------------------------------
; SCENE 9
;-----------------------------------------------

; original interactive script:
; 1. talk x 4
; 2. check (cursor enabled)
; 	- point ryu x 2
; 	- point right terrorist (explain added)
;	x point gun (game over, restart SCENE 9)
; OPTION A [
; 	1. explain->lie/tease
; 	2. rely on key (jump SCENE A, BRANCH A)
; }
; OPTION B {
; 	1. explain->truth
; 	2. rely on key (jump SCENE B, BRANCH B)
; }

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene9_subs:
		JSR		_screen_cursor_handler
		JSR		_s9_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_393AB
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s9_sub00_clear
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_generic_menu_input
		SW_PTR	_s9_menu_handlers
		SW_PTR	_s9_sub05_kei_draw
		SW_PTR	_s9_sub06_kei_msg
		SW_PTR	_s9_sub02_kei_menu_loop
		SW_PTR	_s9_sub08_ryu_draw
		SW_PTR	_s9_sub10_ryu_msg
		SW_PTR	_s9_sub0B_ryu_check_select
		SW_PTR	_s9_sub09_terrorist_close_up_draw
		SW_PTR	_s9_sub0C_terrorist_closeup_msg
		SW_PTR	_s9_sub07_terrorist_close_up_menu_loop
		SW_PTR	_s9_sub11_scene_B_warp
		SW_PTR	_s9_sub0D_game_over_draw
		SW_PTR	_s9_sub0E_game_over_mus_msg
		SW_PTR	_s9_sub0F_game_over_dead

locret_393AB:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub00_clear:
		SW_NXT	_s9_sub05_kei_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub05_kei_draw:
		SW_NXT	_s9_sub06_kei_msg
		LDA		#1
		STA		_scene_spr_overlay_idx
		TLM5	$2E,$2F,$53

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub06_kei_msg:
		SW_NXT	_s9_sub02_kei_menu_loop
		MSG_M
		MSG		_sc9_msgB7
		MSG		_sc9_msg13
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub02_kei_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_393F6
		SW_RET	_s9_sub02_kei_menu_loop
		SW_NXT	_generic_menu_input
		LDA		#0
		STA		_scene_menu_idx
		JSR		_s9_menu_init0
		JMP		_menu_draw_request
locret_393F6:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub08_ryu_draw:
		SW_NXT	_s9_sub10_ryu_msg
		LDA		#2
		STA		_scene_spr_overlay_idx
		TLM5	$2F,$30,$54

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub10_ryu_msg:
		SW_NXT	_s9_sub02_kei_menu_loop
		MSG_1	_sc9_msg06

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub07_terrorist_close_up_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_3945F
		SW_RET	_s9_sub07_terrorist_close_up_menu_loop
		SW_NXT	_generic_menu_input
		LDA		#1
		STA		_scene_menu_idx
		JSR		_s9_menu_init1
		JMP		_menu_draw_request
locret_3945F:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub09_terrorist_close_up_draw:
		SW_NXT	_s9_sub0C_terrorist_closeup_msg
		LDA		#3
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_tlm55_draw:
		TLM5	$2E,$31,$55

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub0C_terrorist_closeup_msg:
		SW_NXT	_s9_sub07_terrorist_close_up_menu_loop
		MSG_1	_sc9_msg0B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub0B_ryu_check_select:
		LDA		_pads+1
		AND		#1
		BEQ		locret_394B1
		JSR		_cursor_active_area_test
		CPX		#$FF
		BNE		loc_39497
		LDX		#3
loc_39497:
		LDA		#0
		STA		_active_areas_list_idx
		SW_NXT	_s9_sub02_kei_menu_loop
		TXA
		SWITCH
		SW_PTR	_s9_sub0B_ryu_check_select_A
		SW_PTR	_s9_sub0B_ryu_check_select_B
		SW_PTR	_s9_sub0B_ryu_check_select_C
		SW_PTR	_s9_sub0B_ryu_check_select_D

locret_394B1:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub0B_ryu_check_select_A:
		LDA		_scene_flags+1
		AND		#7
		CMP		#7
		BEQ		loc_394D0
		MSG_1	_sc9_msg08
loc_394D0:
		SW_FADE	_s9_sub09_terrorist_close_up_draw
		MSG_M
		MSG		_sc9_msg09
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub0B_ryu_check_select_B:
		LDA		_scene_flags+1
		AND		#2
		BNE		loc_39504
		LDA		_scene_flags+1
		ORA		#2
		STA		_scene_flags+1
		MSG_1	_sc9_msg11
loc_39504:
		LDA		_scene_flags+1
		ORA		#4
		STA		_scene_flags+1
		MSG_1	_sc9_msg07

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub0B_ryu_check_select_C:
		SW_FADE	_s9_sub0D_game_over_draw
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub0B_ryu_check_select_D:
		MSG_1	_sc9_msg13

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub0D_game_over_draw:
		SW_NXT	_s9_sub0E_game_over_mus_msg
		LDA		#3
		STA		_scene_spr_overlay_idx
		JMP		_s9_tlm55_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub0E_game_over_mus_msg:
		JSR		_snd_army_gun_fire
		SW_FADE	_s9_sub0F_game_over_dead
		MSG_M
		MSG		_sc9_msgAE
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub0F_game_over_dead:
		LDX		#9
		LDY		#0								; start brom the beginning, no need to index
		JMP		_game_over_dead_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_sub11_scene_B_warp:
		LDA		#$B
		JMP		_new_scene

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_menu_init0:
		LDA		_scene_flags
		AND		#8
		BNE		loc_395AE
		JMP		_scene_menu_init_default1
loc_395AE:
		JMP		_scene_menu_init_default3

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_menu_init1:
		LDA		#0
		STA		_scene_menu_max_pos
		LDA		_scene_flags
		AND		#$C0
		BNE		loc_395C7
		LDA		#0
		STA		_scene_menu_items
		RTS
loc_395C7:
		LDA		#1
		STA		_scene_menu_items
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_menu_handlers:
		JSR		_menu_switch
		.WORD _s9_menu0
		.WORD _s9_menu1
		.WORD _s9_menu2
_s9_menu0:
		.WORD _s9_menu0_talk
		.WORD _s9_menu0_ponder
		.WORD _s9_menu0_check
_s9_menu1:
		.WORD _s9_menu1_explain
		.WORD _s9_menu1_rely_on_kei
_s9_menu2:
		.WORD _s9_menu2_truth
		.WORD _s9_menu2_lie
		.WORD _s9_menu2_tease

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_menu0_talk:
		SW_NXT	_s9_sub02_kei_menu_loop
		LDA		_scene_flags
		AND		#1
		BNE		loc_39633
		LDA		_scene_flags
		ORA		#1
		STA		_scene_flags
		MSG_M
		MSG		_sc9_msg01
		MSG		_sc9_msg02
		MSG_EOL
loc_39633:
		LDA		_scene_flags
		AND		#2
		BNE		loc_39650
		LDA		_scene_flags
		ORA		#2
		STA		_scene_flags
		MSG_M
		MSG		_sc9_msg03
		MSG		_sc9_msg14
		MSG_EOL
loc_39650:
		LDA		_scene_flags
		AND		#4
		BNE		loc_3966D
		LDA		_scene_flags
		ORA		#4
		STA		_scene_flags
		MSG_M
		MSG		_sc9_msg04
		MSG		_sc9_msg02
		MSG_EOL
loc_3966D:
		LDA		_scene_flags
		AND		#8
		BNE		loc_39698
		LDA		_scene_flags
		ORA		#8
		STA		_scene_flags
		SW_FADE	_s9_sub08_ryu_draw
		LDA		#4
		STA		_scene_spr_overlay_idx
		MSG_1	_sc9_msg05
loc_39698:
		MSG_1	_sc9_msg0E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_menu0_ponder:
		SW_NXT	_s9_sub02_kei_menu_loop
		LDA		_scene_flags+1
		ORA		#1
		STA		_scene_flags+1
		MSG_1	_sc9_msg0A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_menu0_check:
		LDA		#4
		STA		_active_areas_list_idx
		LDA		#0
		STA		_screen_cursor_x
		LDA		#$40
		STA		_screen_cursor_y
		ASL
		STA		_screen_cursor_x
		SW_NXT	_s9_sub0B_ryu_check_select
		SW_CUR	_s9_sub0B_ryu_check_select
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_menu1_explain:
		LDA		_scene_flags
		AND		#$3F
		STA		_scene_flags
		SW_NXT	_generic_menu_input
		LDA		#2
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default3
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_menu1_rely_on_kei:
		LDA		_scene_flags
		AND		#$40
		BNE		loc_39719
		SW_FADE	_s9_sub11_scene_B_warp
		LDA		_game_global_flags0				; BRANCH B
		ORA		#2
		STA		_game_global_flags0
		MSG_M
		MSG		_sc9_msg0F
		MSG_WAIT
		MSG_EOL
loc_39719:
		SW_FADE	_next_scene						; BRANCH A
		MSG_M
		MSG		_sc9_msg10
		MSG		_sc9_msg8D
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_menu2_truth:
		SW_NXT	_s9_sub07_terrorist_close_up_menu_loop
		LDA		_scene_flags
		ORA		#$80
		STA		_scene_flags
		MSG_M
		MSG		_sc9_msg0C
		MSG		_sc9_msg8E
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_menu2_lie:
		SW_NXT	_s9_sub07_terrorist_close_up_menu_loop
		LDA		_scene_flags
		ORA		#$40
		STA		_scene_flags
		MSG_M
		MSG		_sc9_msg12
		MSG		_sc9_msg8E
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_menu2_tease:
		SW_NXT	_s9_sub07_terrorist_close_up_menu_loop
		LDA		_scene_flags
		ORA		#$40
		STA		_scene_flags
		MSG_M
		MSG		_sc9_msg0D
		MSG		_sc9_msg15
		MSG		_sc9_msg8E
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s9_spr_overlay1
		SW_PTR	_s9_spr_overlay2
		SW_PTR	_s9_spr_overlay3
		SW_PTR	_s9_spr_overlay4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_spr_overlay1:
		SPR0	_spr_sc9_kei_body,$40,$60
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0JSW	off_39802,$40,$60
off_39802:
		.WORD _spr_sc9_kei_mouth_shut
		.WORD _spr_sc9_kei_mouth_open

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_spr_overlay2:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0JSW	off_39825,$38,$A8
off_39825:
		.WORD _spr_sc9_terrorist_small_mouth0
		.WORD _spr_sc9_terrorist_small_mouth1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_spr_overlay3:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0JSW	off_39848,$38,$90
off_39848:
		.WORD _spr_sc9_terrorist_big_mouth0
		.WORD _spr_sc9_terrorist_big_mouth1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s9_spr_overlay4:
		JSR		_s9_spr_overlay1
		LDA		_frames_counter					; knock-knock overlay, entering terrorists
		AND		#3
		BNE		locret_397C9
		LDA		_rand
		LSR
		BCC		locret_397C9
		AND		#3
		SWITCH
		SW_PTR	_snd_people_coming0
		SW_PTR	_snd_people_coming1
		SW_PTR	_snd_people_coming2
		SW_PTR	_snd_people_coming3
locret_397C9:
		RTS

_spr_sc9_kei_body:
		.BYTE   0,$E4,  3,$10
		.BYTE   0,$E5,  3,$18
		.BYTE   0,  3,  3,$20
		.BYTE   0,$E5,$43,$28
		.BYTE   0,$E4,$43,$30
		.BYTE   8,$E6,  3,$10
		.BYTE   8,  3,  3,$18
		.BYTE   8,  3,  3,$20
		.BYTE   8,  3,  3,$28
		.BYTE   8,$E6,$43,$30
		.BYTE $10,$E7,  3,$10
		.BYTE $10,$E8,  3,$18
		.BYTE $10,$E9,  3,$20
		.BYTE $10,$EA,  3,$28
		.BYTE $10,$E7,$43,$30
		.BYTE $18,$EB,  3,$10
		.BYTE $18,$EC,  3,$18
		.BYTE $18,$ED,  1,$20
		.BYTE $18,$EE,  3,$28
		.BYTE $18,$EB,$43,$30
		.BYTE $20,$EF,  1,$18
		.BYTE $20,$EF,$41,$28
		.BYTE $28,$FE,$42,  4
		.BYTE $28,$FD,$42, $C
		.BYTE $28,$F2,$42,$14
		.BYTE $28,$F1,$42,$1C
		.BYTE $28,$F1,  2,$24
		.BYTE $28,$F2,  2,$2C
		.BYTE $28,$FD,  2,$34
		.BYTE $28,$FE,  2,$3C
		.BYTE $80
_spr_sc9_kei_mouth_shut:
		.BYTE $20,$FF,  1,$20
		.BYTE $80
_spr_sc9_kei_mouth_open:
		.BYTE $20,$F0,  1,$20
		.BYTE $80
_spr_sc9_terrorist_big_mouth1:
		.BYTE   0,$F3,  1,  0
		.BYTE   0,$F4,$41,  8
		.BYTE   0,$F5,  1,$10
		.BYTE $80
_spr_sc9_terrorist_big_mouth0:
		.BYTE   0,$F6,  1,  0
		.BYTE   0,$F7,$41,  8
		.BYTE   0,$F8,  1,$10
		.BYTE $80
_spr_sc9_terrorist_small_mouth1:
		.BYTE   0,$FB,  1,  0
		.BYTE   8,$FC,  1,  0
		.BYTE $80
_spr_sc9_terrorist_small_mouth0:
		.BYTE   0,$F9,  1,  0
		.BYTE   8,$FA,  1,  0
		.BYTE $80

		SECTION_END 9
