
		SECTION_START F

;-----------------------------------------------
; SCENE F
;-----------------------------------------------

; original interactive script:
; OPTION A {
; 	1. look->tetsuo (talk added)
; 	2. talk->tetsuo (jump SCENE 10)
; }
; OPTION B {
; 	1. show->lab ID
; 	2. look->colonel (talk added)
; 	3.x talk->colonel (game over, restart SCENE F)
; }

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sceneF_subs:
		JSR		_screen_cursor_handler
		JSR		_sF_spr_overlay_set
		LDA		_nmi_ppu_draw0_req
		BNE		locret_51530
		LDA		_draw_state_idx
		BNE		locret_51530
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_sF_sub00_clear
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_generic_menu_input
		SW_PTR	_sF_menu_handlers
		SW_PTR	_sF_sub05_nursery_draw_init
		SW_PTR	_sF_sub06_nursery_draw
		SW_PTR	_sF_sub08_nursery_initial_msg
		SW_PTR	_sF_sub02_nursery_menu_loop
		SW_PTR	_sF_sub09_check_select
		SW_PTR	_sF_sub1D_kyoko_draw
		SW_PTR	_sF_sub1E_kyoko_msg
		SW_PTR	_sF_sub20_colonel_autoscroll
		SW_PTR	_sF_sub21_colonel_menu_loop
		SW_PTR	_sF_sub18_clear
		SW_PTR	_sF_sub0A_kaneda_icon0_draw0
		SW_PTR	_sF_sub0B_kaneda_icon0_msg0
		SW_PTR	_sF_sub19_tetsuo_icon2_draw0
		SW_PTR	_sF_sub1A_tetsuo_icon2_msg0
		SW_PTR	_sF_sub0C_tetsuo_icon2_draw1
		SW_PTR	_sF_sub0D_tetsuo_icon2_msg1
		SW_PTR	_sF_sub0E_kaneda_icon0_draw1
		SW_PTR	_sF_sub0F_kaneda_icon0_msg1
		SW_PTR	_sF_sub10_kyoko_draw
		SW_PTR	_sF_sub11_kyoko_msg
		SW_PTR	_sF_sub12_raged_tetsuo_draw
		SW_PTR	_sF_sub13_raged_tetsuo_msg0
		SW_PTR	_sF_sub1F_raged_tetsuo_msg1
		SW_PTR	_sF_sub14_kyoko_draw
		SW_PTR	_sF_sub15_kyoko_msg
		SW_PTR	_sF_sub22_clear
		SW_PTR	_sF_sub16_colonel_icon1_draw
		SW_PTR	_sF_sub17_colonel_icon1_msg
		SW_PTR	_sF_sub1B_game_over

locret_51530:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub00_clear:
		JSR		_apu_reset
		SW_NXT	_sF_sub05_nursery_draw_init
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub05_nursery_draw_init:
		LDA		#$3F
		STA		_menu_restore_tlm_idx_list
		STA		byte_361
		STA		byte_363
		STA		byte_365
		LDA		#$40
		STA		_menu_restore_tlm_idx_list+1
		STA		byte_362
		STA		byte_364
		STA		byte_366
		LDA		#0
		STA		byte_35D
		STA		byte_35E
		STA		_tlm_chr_col_draw_req
		STA		byte_350
		SW_NXT	_sF_sub06_nursery_draw
		SW_CUR	_sF_sub06_nursery_draw
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub06_nursery_draw:
		LDA		byte_35D
		CLC
		ADC		#7
		STA		byte_35D
		LDA		byte_35E
		ADC		#0
		STA		byte_35E
		LDX		byte_35E
		LDA		_menu_restore_tlm_idx_list,X
		JSR		_tlm_get_index_by_number
		INC		_tlm_chr_col_draw_req
		LDA		_tlm_chr_col_draw_req
		CMP		#$38
		BCC		locret_51654
		CHRPAL	$27,$24
		LDA		#0
		STA		_tlm_chr_col_draw_req
		STA		_scroll_x_shadow
		STA		_scroll_x_shadow+1
		LDA		#$90
		STA		_tmp_x_pos
		LDA		#1
		STA		_tmp_x_pos+1
		LDA		#6
		STA		_scene_spr_overlay_idx
		LDA		#1
		STA		_scene_anim_idx+2				; init tetsuo's head to the left
		SW_NXT	_sF_sub08_nursery_initial_msg
		SW_CUR	_sF_sub08_nursery_initial_msg
locret_51654:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub08_nursery_initial_msg:
		SW_NXT	_sF_sub02_nursery_menu_loop
		LDA		_scene_flags
		AND		#$40
		BNE		locret_5166F
		MSG_1	_scF_msg00
locret_5166F:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub02_nursery_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_515AA
		SW_RET	_sF_sub02_nursery_menu_loop
		SW_NXT	_generic_menu_input
		LDA		#0
		STA		_scene_menu_idx
		JSR		_sF_menu_init0
		JMP		_menu_draw_request
locret_515AA:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub09_check_select:
		LDA		#1
		STA		_tlm_chr_col_draw_req
		JSR		_sF_scroll_draw
		LDA		_pads+1
		AND		#1
		BEQ		locret_516A6
		JSR		_cursor_active_area_test
		CPX		#$FF
		BNE		loc_51687
		LDX		#5
loc_51687:
		LDA		#0
		STA		_active_areas_list_idx
		LDA		#0
		STA		_tlm_chr_col_draw_req
		SW_NXT	_sF_sub02_nursery_menu_loop
		TXA
		SWITCH
		SW_PTR	_sF_sub09_check_select_A
		SW_PTR	_sF_sub09_check_select_B
		SW_PTR	_sF_sub09_check_select_C
		SW_PTR	_sF_sub09_check_select_D
		SW_PTR	_sF_sub09_check_select_E
		SW_PTR	_sF_sub09_check_select_F

locret_516A6:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub09_check_select_A:
		LDA		_scene_flags
		ORA		#1
		STA		_scene_flags
		MSG_1	_scF_msg03

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub09_check_select_B:
		LDA		_scene_flags
		ORA		#2
		STA		_scene_flags
		MSG_1	_scF_msg02

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub09_check_select_C:
		LDA		_scene_flags
		ORA		#4
		STA		_scene_flags
		MSG_1	_scF_msg03

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub09_check_select_D:
		LDA		_scene_flags
		ORA		#8
		STA		_scene_flags
		MSG_1	_scF_msg04

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub09_check_select_E:
		LDA		_scene_flags
		ORA		#$10
		STA		_scene_flags
		MSG_1	_scF_msg05

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub09_check_select_F:
		MSG_1	_scF_msg01

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub0C_tetsuo_icon2_draw1:
		SW_NXT	_sF_sub0D_tetsuo_icon2_msg1
		LDA		#2
		STA		_scene_spr_overlay_idx
		ICON2	$28,$25,$43

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub0D_tetsuo_icon2_msg1:
		SW_FADE	_sF_sub0E_kaneda_icon0_draw1
		MSG_M
		MSG		_scF_msg09
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub0E_kaneda_icon0_draw1:
		SW_NXT	_sF_sub0F_kaneda_icon0_msg1
		LDA		#4
		STA		_scene_spr_overlay_idx
		ICON0	$28,$25,$41

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub0F_kaneda_icon0_msg1:
		JSR		_snd_hit_splash
		SW_FADE	_sF_sub10_kyoko_draw
		MSG_M
		MSG		_sc2_F_10_12_13_msg85
		MSG		_scF_msg0A
		MSG		_scF_msg92
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub10_kyoko_draw:
		SW_NXT	_sF_sub11_kyoko_msg
		LDA		#8
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_tlm9C_draw:
		TLM5	$59,$59,$9C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub11_kyoko_msg:
		JSR		_snd_akira_flashback_suddenly
		SW_FADE	_sF_sub12_raged_tetsuo_draw
		MSG_M
		MSG		_scF_msg10
		MSG		_scF_msg0C
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub12_raged_tetsuo_draw:
		JSR		_apu_reset
		JSR		_snd_raged_tetsuo_noise
		SW_NXT	_sF_sub13_raged_tetsuo_msg0
		LDA		#5
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_tlm45_draw:
		LDA		#1
		STA		_spr0_overflow_mode_flag
		LDA		#0
		STA		_scene_anim_idx+2				; init tetsuo's head forth
		LDA		#$70
		STA		_tmp_x_pos
		LDA		#0
		STA		_tmp_x_pos+1
		LDA		#$38
		STA		_tmp_direction_x0
		STA		_tmp_direction_y0+1
		LDA		#$30
		STA		_tmp_direction_y0
		LDA		#$A0
		STA		_tmp_direction_x0+1
		LDA		#$28
		STA		_tmp_direction_x1+1
		LDA		#$78
		STA		_tmp_direction_y1+1
		STA		byte_52F
		LDA		#$C8
		STA		byte_52C
		TLM4	$29,$26,$45

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub13_raged_tetsuo_msg0:
		SW_NXT	_sF_sub1F_raged_tetsuo_msg1
		MSG_M
		MSG		_scF_12_13_15_msg93
		MSG		_scF_msg92
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub1F_raged_tetsuo_msg1:
		SW_FADE	_sF_sub14_kyoko_draw
		LDA		#9
		STA		_scene_spr_overlay_idx
		MSG_M
		MSG		_scF_msg0D
		MSG		_scF_msg1D
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub14_kyoko_draw:
		SW_NXT	_sF_sub15_kyoko_msg
		LDA		#0
		STA		_spr0_overflow_mode_flag
		LDA		#8
		STA		_scene_spr_overlay_idx
		JSR		_scroll_reset
		JMP		_sF_tlm9C_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub15_kyoko_msg:
		SW_FADE	_sF_sub22_clear
		MSG_M
		MSG		_scF_msg0E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub22_clear:
		SW_NXT	_sF_sub16_colonel_icon1_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub16_colonel_icon1_draw:
		SW_NXT	_sF_sub17_colonel_icon1_msg
		LDA		#7
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_icon46_draw:
		ICON1	$28,$6B,$46

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub17_colonel_icon1_msg:
		SW_FADE	_next_scene
		MSG_M
		MSG		_scF_msg0F
		MSG		_scF_msg1F
		MSG		_scF_msg1E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub18_clear:
		LDA		#0
		STA		_scroll_x_shadow
		STA		_scroll_x_shadow+1
		SW_NXT	_sF_sub0A_kaneda_icon0_draw0
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub0A_kaneda_icon0_draw0:
		SW_NXT	_sF_sub0B_kaneda_icon0_msg0
		LDA		#1
		STA		_scene_spr_overlay_idx
		ICON0	$28,$25,$42

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub0B_kaneda_icon0_msg0:
		SW_FADE	_sF_sub19_tetsuo_icon2_draw0
		MSG_M
		MSG		_scF_msg06
		MSG		_scF_msg1A
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub19_tetsuo_icon2_draw0:
		SW_NXT	_sF_sub1A_tetsuo_icon2_msg0
		LDA		#3
		STA		_scene_spr_overlay_idx
		ICON2	$28,$25,$44

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub1A_tetsuo_icon2_msg0:
		SW_FADE	_sF_sub0C_tetsuo_icon2_draw1
		MSG_M
		MSG		_scF_msg07
		MSG		_scF_msg1B
		MSG		_scF_msg1C
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub1B_game_over:
		LDA		#0
		STA		_scroll_x_shadow
		STA		_scroll_x_shadow+1
		JSR		_scene_vars_init				; missing var resets here, so pass have them in release ver here
		LDX		#$F
		LDY		#0								; always zero
		JMP		_game_over_prison_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub1D_kyoko_draw:
		SW_NXT	_sF_sub1E_kyoko_msg
		LDA		#8
		STA		_scene_spr_overlay_idx
		JSR		_scroll_reset
		JMP		_sF_tlm9C_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub1E_kyoko_msg:
		JSR		_snd_kiyoko_psychodelic
		SW_FADE	_sF_sub00_clear
		MSG_M
		MSG		_scF_msg19
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub20_colonel_autoscroll:
		LDA		_scroll_x_shadow
		CMP		#$70
		BCS		loc_518DF
		CLC
		ADC		#4
		STA		_scroll_x_shadow
		CMP		#$80
		BCC		loc_518F7
		BCS		loc_518EC
loc_518DF:
		CMP		#$90
		BCC		loc_518EC
		SEC
		SBC		#4
		STA		_scroll_x_shadow
		CMP		#$80
		BCS		loc_518F7
loc_518EC:
		LDA		#0
		STA		_tlm_chr_col_draw_req
		SW_NXT	_sF_sub21_colonel_menu_loop
		RTS
loc_518F7:
		LDA		#1
		STA		_tlm_chr_col_draw_req

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_scroll_draw:
		JSR		_sF_scr_cur_scroll_calc
		LDA		_scroll_x_shadow
		AND		#7
		CMP		#4
		BCC		loc_51E3F
		LDA		_scroll_x_shadow
		CLC
		ADC		#$80
		STA		byte_35D
		LDA		_scroll_x_shadow+1
		ADC		#1
		STA		byte_35E
		JMP		loc_51E57
loc_51E3F:
		LDA		_scroll_x_shadow
		SEC
		SBC		#$80
		STA		byte_35D
		LDA		_scroll_x_shadow+1
		SBC		#0
		STA		byte_35E
		CMP		#$FF
		BNE		loc_51E57
		LDA		#5
		STA		byte_35E
loc_51E57:
		LDX		byte_35E
		LDA		_menu_restore_tlm_idx_list,X
		JMP		_tlm_get_index_by_number

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_scr_cur_scroll_calc:
		LDA		_scroll_x_shadow
		CLC
		ADC		#$40
		STA		word_0
		LDA		_scroll_x_shadow+1
		ADC		#0
		STA		word_0+1
		LDA		_screen_cursor_x
		SEC
		SBC		word_0
		LDA		_screen_cursor_x+1
		SBC		word_0+1
		BCC		loc_51E9B
		LDA		_scroll_x_shadow
		CLC
		ADC		#$C0
		STA		word_0
		LDA		_scroll_x_shadow+1
		ADC		#0
		STA		word_0+1
		LDA		_screen_cursor_x
		SEC
		SBC		word_0
		LDA		_screen_cursor_x+1
		SBC		word_0+1
		BCS		loc_51EB5
		RTS
loc_51E9B:
		LDA		_scroll_x_shadow
		SEC
		SBC		#1
		STA		_scroll_x_shadow
		LDA		_scroll_x_shadow+1
		SBC		#0
		STA		_scroll_x_shadow+1
		CMP		#$FF
		BNE		locret_51ECE
		LDA		#0
		STA		_scroll_x_shadow
		STA		_scroll_x_shadow+1
		RTS
loc_51EB5:
		LDA		_scroll_x_shadow
		CLC
		ADC		#1
		STA		_scroll_x_shadow
		LDA		_scroll_x_shadow+1
		ADC		#0
		STA		_scroll_x_shadow+1
		CMP		#1
		BNE		locret_51ECE
		LDA		#$FF
		STA		_scroll_x_shadow
		LDA		#0
		STA		_scroll_x_shadow+1
locret_51ECE:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_sub21_colonel_menu_loop:
		SW_RET	_sF_sub02_nursery_menu_loop
		SW_NXT	_generic_menu_input
		LDA		#1
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default2
		JMP		_menu_draw_request

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_menu_init0:
		LDA		_scene_flags
		AND		#$1F
		BEQ		locret_5194A
		JMP		_scene_menu_init_default5
locret_5194A:
		JMP		_scene_menu_init_default4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_menu_init2:
		LDX		#0
		LDY		#0
		LDA		_scene_flags
loc_51959:
		LSR
		BCC		loc_51965
		PHA
		LDA		_sF_menu_list,X
		STA		_scene_menu_items,Y
		PLA
		INY
loc_51965:
		INX
		CPX		#5
		BCC		loc_51959
		DEY
		STY		_scene_menu_max_pos
		RTS
_sF_menu_list:
		.BYTE   0,  1,  2,  3,  4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_menu_handlers:
		JSR		_menu_switch
		.WORD _sF_menu0
		.WORD _sF_menu1
		.WORD _sF_menu2
_sF_menu0:
		.WORD _sF_menu0_run
		.WORD _sF_menu0_rely_on_key
		.WORD _sF_menu0_show
		.WORD _sF_menu0_look
		.WORD _sF_menu0_talk
_sF_menu1:
		.WORD _sF_menu1_pocket
		.WORD _sF_menu1_lab_id
_sF_menu2:
		.WORD _sF_menu2_masaru
		.WORD _sF_menu2_takahasi
		.WORD _sF_menu2_kyoko
		.WORD _sF_menu2_colonel
		.WORD _sF_menu2_tetsuo

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_menu0_run:
		SW_NXT	_sF_sub02_nursery_menu_loop
		MSG_1	_scF_msg08

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_menu0_rely_on_key:
		SW_NXT	_sF_sub02_nursery_menu_loop
		MSG_1	_scF_msg11

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_menu0_show:
		SW_NXT	_sF_sub20_colonel_autoscroll
		SW_CUR	_sF_sub20_colonel_autoscroll
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_menu0_look:
		LDA		#$83
		STA		_active_areas_list_idx
		LDA		#$40
		STA		_screen_cursor_y
		LDA		_scroll_x_shadow
		CLC
		ADC		#$80
		STA		_screen_cursor_x
		LDA		_scroll_x_shadow+1
		ADC		#0
		STA		_screen_cursor_x+1
		SW_NXT	_sF_sub09_check_select
		SW_CUR	_sF_sub09_check_select
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_menu0_talk:
		SW_RET	_sF_sub02_nursery_menu_loop
		SW_NXT	_generic_menu_input
		LDA		#2
		STA		_scene_menu_idx
		JSR		_sF_menu_init2
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_menu1_pocket:
		SW_NXT	_sF_sub02_nursery_menu_loop
		MSG_1	_scF_msg12

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_menu1_lab_id:
		SW_NXT	_sF_sub02_nursery_menu_loop
		LDA		_scene_flags
		ORA		#$20
		STA		_scene_flags
		MSG_1	_scF_msg13

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_menu2_masaru:
		SW_NXT	_sF_sub02_nursery_menu_loop
		MSG_M
		MSG		_scF_msg16
		MSG		_scF_msg17
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_menu2_takahasi:
		SW_NXT	_sF_sub02_nursery_menu_loop
		MSG_M
		MSG		_scF_msg16
		MSG		_scF_msg17
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_menu2_kyoko:
		LDA		_scene_flags
		ORA		#$40
		STA		_scene_flags
		SW_FADE	_sF_sub1D_kyoko_draw
		MSG_M
		MSG		_scF_msg16
		MSG		_scF_msg18
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_menu2_colonel:
		LDA		_scene_flags
		AND		#$20
		BNE		loc_51A7F
		SW_NXT	_sF_sub02_nursery_menu_loop
		MSG_1	_scF_msg15
loc_51A7F:
		SW_FADE	_sF_sub1B_game_over
		MSG_1	_scF_msg14

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_menu2_tetsuo:
		SW_NXT	_sF_sub18_clear
		JMP		_fade_out_reqest

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_sF_spr_overlay1
		SW_PTR	_sF_spr_overlay2
		SW_PTR	_sF_spr_overlay3
		SW_PTR	_sF_spr_overlay4
		SW_PTR	_sF_spr_overlay5
		SW_PTR	_sF_spr_overlay6
		SW_PTR	_sF_spr_overlay7
		SW_PTR	_sF_spr_overlay8
		SW_PTR	_sF_spr_overlay9

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_spr_overlay2:
		JSR		_sF_spr_overlay4

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_spr_overlay1:
		JSR		_do_scene_anim0_pat0101			; restored mouth anim
		LDA		_scene_anim_idx
		SPR0JSW	off_51B9E,$28,$28
off_51B9E:
		.WORD _spr_scF_kaneda_mouth1
		.WORD _spr_scF_kaneda_mouth0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_spr_overlay3:
		JSR		_do_scene_anim1_pat0101			; restored mouth anim
		LDA		_scene_anim_idx+1
		SPR0SW	off_51BBC,$30,$C0
		JMP		_sF_spr_overlay1
off_51BBC:
		.WORD _spr_scF_tetsuo_mouth1
		.WORD _spr_scF_tetsuo_mouth0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_spr_overlay4:
		JSR		_do_scene_anim1_pat0101			; restored mouth anim
		LDA		_scene_anim_idx+1
		SPR0JSW	off_51B80,$28,$B8
off_51B80:
		.WORD _spr_scF_tetsuo_mouth3
		.WORD _spr_scF_tetsuo_mouth2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_spr_overlay5:
		JSR		_sF_spr_overlay9

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_spr_overlay6:
		LDA		#$40
		STA		word_2
		LDA		_tmp_x_pos
		SEC
		SBC		_scroll_x_shadow
		STA		word_2+1
		LDA		_tmp_x_pos+1
		SBC		_scroll_x_shadow+1
		BNE		locret_51B61
		LDA		word_2+1
		PHA
		SPR0EX	_spr_scF_tetsuo_body
		LDA		#$40
		STA		word_2
		PLA
		STA		word_2+1
		LDA		_scene_anim_idx+2
		SPR0SWEX	off_51B62
locret_51B61:
		RTS
off_51B62:
		.WORD _spr_scF_head0
		.WORD _spr_scF_head1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_spr_overlay7:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0JSW	off_51B21,$68,$78
off_51B21:
		.WORD _spr_scF_colonel_mouth0
		.WORD _spr_scF_colonel_mouth1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_spr_overlay8:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0JSW	off_51AFE,$58,$76
off_51AFE:
		.WORD _spr_scF_kiyoko_mouth0
		.WORD _spr_scF_kiyoko_mouth1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sF_spr_overlay9:
		LDA		_frames_counter
		AND		#3
		BNE		loc_51C45
		DEC		_tmp_direction_y0
		DEC		_tmp_direction_y0+1
		DEC		_tmp_direction_y1+1
		DEC		byte_52F
		LDX		#$A0
		LDA		_tmp_direction_y0
		CMP		#8
		BCS		loc_51C27
		STX		_tmp_direction_y0
loc_51C27:
		LDA		_tmp_direction_y0+1
		CMP		#8
		BCS		loc_51C31
		STX		_tmp_direction_y0+1
loc_51C31:
		LDA		_tmp_direction_y1+1
		CMP		#8
		BCS		loc_51C3B
		STX		_tmp_direction_y1+1
loc_51C3B:
		LDA		byte_52F
		CMP		#8
		BCS		loc_51C45
		STX		byte_52F
loc_51C45:
		LDA		_tmp_direction_y0
		STA		word_2
		LDA		_tmp_direction_x0
		STA		word_2+1
		SPR1	_spr_scF_flying_boulder0
		LDA		_tmp_direction_y0+1
		STA		word_2
		LDA		_tmp_direction_x0+1
		STA		word_2+1
		SPR1	_spr_scF_flying_boulder1
		LDA		_tmp_direction_y1+1
		STA		word_2
		LDA		_tmp_direction_x1+1
		STA		word_2+1
		SPR1	_spr_scF_flying_boulder2
		LDA		byte_52F
		STA		word_2
		LDA		byte_52C
		STA		word_2+1
		SPR1	_spr_scF_flying_boulder3
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
;_unref:										; so sad, the tiles used here are removed
;		JSR		_do_scene_anim0_pat0101			; from CHR data, so we never know what
;		LDA		_scene_anim_idx					; is this
;		SPR0SW	_spr_unused_lib,$38,$28
;		SPR0J	_spr_unused_0,$38,$28
;_spr_unused_lib:
;		.WORD _spr_dummy
;		.WORD _spr_unused2
;		.WORD _spr_unused1
;_spr_unused_0:
;		.BYTE   0,$CA,  2,  0
;		.BYTE   0,$CB,  2,  8
;		.BYTE   8,$CC,  2,  0
;		.BYTE   8,$CD,  2,  8
;		.BYTE $10,$CE,  2,  0
;		.BYTE $10,$CF,  2,  8
;		.BYTE $80
;_spr_unused1:
;		.BYTE $10,$CE,  2,  0
;		.BYTE $10,$CF,  2,  8
;		.BYTE $80
;_spr_unused2:
;		.BYTE $10,$D0,  2,  0
;		.BYTE $10,$D1,  2,  8
;		.BYTE $80

_spr_scF_kiyoko_mouth1:
		.BYTE   0,$FE,  1,  0
		.BYTE $80
_spr_scF_kiyoko_mouth0:
		.BYTE   1,$FF,  1,  0
		.BYTE $80
_spr_scF_colonel_mouth1:
		.BYTE   0,$BC,  1,  0
		.BYTE   0,$BD,  1,  8
		.BYTE $80
_spr_scF_colonel_mouth0:
		.BYTE   0,$BE,  1,  0
		.BYTE   0,$BF,  1,  8
		.BYTE $80
_spr_scF_tetsuo_body:
		.BYTE $10,$DE,  1,  8
		.BYTE $10,$DF,  1,$10
		.BYTE $10,$E0,  1,$18
		.BYTE $10,$E1,  1,$20
		.BYTE $18,$E2,  1,  8
		.BYTE $18,$E3,  1,$10
		.BYTE $18,$E4,  1,$18
		.BYTE $18,$E5,  1,$20
		.BYTE $18,$E6,  1,$28
		.BYTE $20,$E7,  1,  8
		.BYTE $20,$E8,  1,$10
		.BYTE $20,$E9,  1,$18
		.BYTE $20,$EA,  1,$20
		.BYTE $20,$EB,  1,$28
		.BYTE $28,$EC,  1,  8
		.BYTE $28,$ED,  1,$10
		.BYTE $28,$EE,  1,$18
		.BYTE $28,$EF,  1,$20
		.BYTE $28,$F0,  1,$28
		.BYTE $30,$F1,  1,  8
		.BYTE $30,$F2,  1,$10
		.BYTE $30,$F3,  1,$18
		.BYTE $30,$F4,  1,$20
		.BYTE $38,$F5,  1,  0
		.BYTE $38,$F6,  1,  8
		.BYTE $38,$F7,  1,$20
		.BYTE $38,$F8,  1,$28
		.BYTE $80
_spr_scF_head0:
		.BYTE   0,$D6,  1,$10
		.BYTE   0,$D7,  1,$18
		.BYTE   8,$D8,  1,$10
		.BYTE   8,$D9,  1,$18
		.BYTE $80
_spr_scF_head1:
		.BYTE   0,$DA,  1,$10
		.BYTE   0,$DB,  1,$18
		.BYTE   8,$DC,  1,$10
		.BYTE   8,$DD,  1,$18
		.BYTE $80
_spr_scF_tetsuo_mouth2:
		.BYTE   0,$C5,  1,  0
		.BYTE   0,$C6,  1,  8
		.BYTE   8,$C7,  1,  0
		.BYTE   8,$C8,  1,  8
		.BYTE $80
_spr_scF_tetsuo_mouth3:
		.BYTE   0,$C5,  1,  0
		.BYTE   0,$C6,  1,  8
		.BYTE   8,$C7,  1,  0
		.BYTE   8,$C9,  1,  8
		.BYTE $80
_spr_scF_kaneda_mouth0:
		.BYTE   0,$D2,  1,  0
		.BYTE   0,$D3,  1,  8
		.BYTE   8,$D5,  1,  8
		.BYTE $80
_spr_scF_kaneda_mouth1:
		.BYTE   0,$D2,  1,  0
		.BYTE   0,$D3,  1,  8
		.BYTE   8,$D4,  1,  8
		.BYTE $80
_spr_scF_tetsuo_mouth0:
		.BYTE   0,$C0,  1,  0
		.BYTE   0,$C2,  1,  8
		.BYTE   8,$C4,  1,  8
		.BYTE $80
_spr_scF_tetsuo_mouth1:
		.BYTE   0,$C0,  1,  0
		.BYTE   0,$C1,  1,  8
		.BYTE   8,$C3,  1,  8
		.BYTE $80
_spr_scF_flying_boulder0:
		.BYTE $E0,$FC,  2,$20
		.BYTE $E8,$FB,  2,$10
		.BYTE $E8,$F9,  2,$30
		.BYTE $F0,$FF,  2,  0
		.BYTE $F0,$FA,  2,$30
		.BYTE $80
_spr_scF_flying_boulder1:
		.BYTE $E8,$FD,  2,  0
		.BYTE $F0,$F9,  2,$10
		.BYTE $F8,$FA,  2,$10
		.BYTE $80
_spr_scF_flying_boulder2:
		.BYTE $E0,$FE,  2,$18
		.BYTE $80
_spr_scF_flying_boulder3:
		.BYTE $E0,$FF,  2,$18
		.BYTE $80

		SECTION_END F
