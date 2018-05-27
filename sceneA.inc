
		SECTION_START A

;-----------------------------------------------
; SCENE A
;-----------------------------------------------

; original interactive script:
; 1. check (cursor enabled)
;	- beer (beer added)
; 2. open->beer
; 3. open (cursor enabled)
;	- fence net
; 4.1 drink (jump 3.)
; 4.2 run
; 5. go on
; BRANCH A (entry from SCENE 9) {
; 	1. inquire
; 	2. go on (jump SCENE B, BRANCH A)
; }
; BRANCH B (entry from SCENE B) {
; 	1. go on x 2 (jump SCENE B, BRANCH A)
; }

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sceneA_subs:
		JSR		_screen_cursor_handler
		JSR		_sA_water_drops_snd
		LDA		_draw_state_idx
		BNE		locret_39936
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_sA_sub00_clear
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_generic_menu_input
		SW_PTR	_sA_menu_handlers
		SW_PTR	_sA_sub05_closet_init
		SW_PTR	_sA_sub07_closet_draw
		SW_PTR	_sA_sub09_closet_msg
		SW_PTR	_sA_sub02_closet_menu0_loop
		SW_PTR	_sA_sub0B_check0_select
		SW_PTR	_sA_sub14_return_to_closet_menu0
		SW_PTR	_sA_sub11_check1_init
		SW_PTR	_sA_sub0C_check1_select
		SW_PTR	_sA_sub08_open_snd
		SW_PTR	_sA_sub06_closet_menu1_loop
		SW_PTR	_sA_sub15_drunk_delay
		SW_PTR	_sA_sub13_drunk_return_to_closet_menu0
		SW_PTR	_sA_sub0D_run_draw
		SW_PTR	_sA_sub0E_run_menu_loop
		SW_PTR	_sA_sub0F_run_go_on
		SW_PTR	_sA_sub10_run_go_on_menu0_loop
		SW_PTR	_sA_sub12_run_go_on_menu1_loop
locret_39936:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub00_clear:
		SW_NXT	_sA_sub05_closet_init
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub05_closet_init:
		LDA		#$2D
		STA		_menu_restore_tlm_idx_list
		STA		byte_362
		STA		byte_365
		LDA		#$2E
		STA		_menu_restore_tlm_idx_list+1
		STA		byte_363
		STA		byte_366
		LDA		#$2F
		STA		byte_361
		STA		byte_364
		LDA		#0
		STA		byte_35D
		STA		byte_35E
		STA		_tlm_chr_col_draw_req
		STA		byte_350
		SW_NXT	_sA_sub07_closet_draw
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub07_closet_draw:
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
		BCC		locret_39A3C
		CHRPAL	$1F,$1A
		LDA		#0
		STA		_tlm_chr_col_draw_req
		SW_NXT	_sA_sub09_closet_msg
locret_39A3C:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub09_closet_msg:
		SW_NXT	_sA_sub02_closet_menu0_loop
		MSG_1	_scA_msg00

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub02_closet_menu0_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_3998D
		SW_RET	_sA_sub02_closet_menu0_loop
		SW_NXT	_generic_menu_input
		LDA		#0
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default3
		JMP		_menu_draw_request
locret_3998D:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub0B_check0_select:
		LDA		#1
		STA		_tlm_chr_col_draw_req
		JSR		_sA_scroll_draw
		LDA		_pads+1
		AND		#1
		BEQ		locret_39AA3
		JSR		_cursor_active_area_test
		CPX		#$FF
		BNE		loc_39A84
		LDX		#5
loc_39A84:
		LDA		#0
		STA		_active_areas_list_idx
		LDA		#0
		STA		_tlm_chr_col_draw_req
		SW_NXT	_sA_sub02_closet_menu0_loop
		TXA
		SWITCH
		SW_PTR	_sA_sub0B_check0_select_A
		SW_PTR	_sA_sub0B_check0_select_B
		SW_PTR	_sA_sub0B_check0_select_C
		SW_PTR	_sA_sub0B_check0_select_D
		SW_PTR	_sA_sub0B_check0_select_E
		SW_PTR	_sA_sub0B_check0_select_F

locret_39AA3:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub0B_check0_select_A:
		MSG_M
		MSG		_scA_msg06
		MSG		_scA_msg17
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub0B_check0_select_B:
		MSG_1	_scA_10_msg94

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub0B_check0_select_C:
		LDA		_scene_flags
		AND		#1
		BNE		loc_39AE7
		LDA		_scene_flags
		ORA		#1
		STA		_scene_flags
		MSG_1	_scA_msg09
loc_39AE7:
		MSG_1	_scA_msg10

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub0B_check0_select_D:
		MSG_1	_scA_msg01

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub0B_check0_select_E:
		MSG_1	_scA_msg08

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub0B_check0_select_F:
		MSG_1	_scA_msg11

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub0C_check1_select:
		LDA		#1
		STA		_tlm_chr_col_draw_req
		JSR		_sA_scroll_draw
		LDA		_pads+1
		AND		#1
		BEQ		locret_39B51
		JSR		_cursor_active_area_test
		CPX		#$FF
		BNE		loc_39B32
		LDX		#1
loc_39B32:
		LDA		#0
		STA		_active_areas_list_idx
		LDA		#0
		STA		_tlm_chr_col_draw_req
		SW_NXT	_sA_sub02_closet_menu0_loop
		TXA
		SWITCH
		SW_PTR	_sA_sub0C_check1_select_A		; only fence here
		SW_PTR	_sA_sub0C_check1_select_B		; default all wrongs
locret_39B51:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub0C_check1_select_A:
		LDA		_scene_flags
		AND		#$10
		BNE		loc_39B77
		LDA		_scene_flags
		ORA		#$10
		STA		_scene_flags
		SW_NXT	_sA_sub08_open_snd
		MSG_1	_scA_msg0B
loc_39B77:
		SW_NXT	_sA_sub06_closet_menu1_loop
		MSG_1	_scA_msg0C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub0C_check1_select_B:
		MSG_1	_scA_msg0D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub08_open_snd:
		JSR		_snd_vent_fence_broken
		SW_NXT	_sA_sub06_closet_menu1_loop
		MSG_1	_scA_msg0C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub06_closet_menu1_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_39A03
		SW_RET	_sA_sub06_closet_menu1_loop
		SW_NXT	_generic_menu_input
		LDA		#3
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default3
		JMP		_menu_draw_request
locret_39A03:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub15_drunk_delay:
		SW_NXT	_sA_sub13_drunk_return_to_closet_menu0
		LDA		#4
		JMP		_delay

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub13_drunk_return_to_closet_menu0:
		SW_NXT	_sA_sub02_closet_menu0_loop
		CHRPAL	$1F,$1A
		MSG_1	_sc8_A_msg8F

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub0D_run_draw:
		LDA		#0
		STA		_scroll_x_shadow
		STA		_scroll_x_shadow+1
		SW_NXT	_sA_sub0E_run_menu_loop
		TLM5	$20,$1B,$30

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub0E_run_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_39BCB
		SW_RET	_sA_sub0E_run_menu_loop
		SW_NXT	_generic_menu_input
		LDA		#4
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default2
		JMP		_menu_draw_request
locret_39BCB:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub0F_run_go_on:
		SW_NXT	_sA_sub12_run_go_on_menu1_loop
		LDA		_game_global_flags0
		AND		#4
		BNE		loc_39BE7
		SW_NXT	_sA_sub10_run_go_on_menu0_loop
loc_39BE7:
		TLM5	$20,$1B,$31

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub10_run_go_on_menu0_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_39C0C
		SW_RET	_sA_sub10_run_go_on_menu0_loop
		SW_NXT	_generic_menu_input
		LDA		#5
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default3
		JMP		_menu_draw_request
locret_39C0C:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub11_check1_init:
		LDA		#$82
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
		SW_NXT	_sA_sub0C_check1_select
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub12_run_go_on_menu1_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_39C47
		SW_RET	_sA_sub10_run_go_on_menu0_loop
		SW_NXT	_generic_menu_input
		LDA		#6
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default3
		JMP		_menu_draw_request
locret_39C47:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_sub14_return_to_closet_menu0:
		SW_RET	_sA_sub02_closet_menu0_loop
		SW_NXT	_generic_menu_input
		LDA		#0
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default3
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu_init2:
		LDA		_scene_flags
		AND		#1
		BEQ		locret_39CBA
		JMP		_scene_menu_init_default2
locret_39CBA:
		JMP		_scene_menu_init_default1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu_handlers:
		JSR		_menu_switch
		.WORD _sA_menu0
		.WORD _sA_menu1
		.WORD _sA_menu2
		.WORD _sA_menu3
		.WORD _sA_menu4
		.WORD _sA_menu5
		.WORD _sA_menu6
_sA_menu0:
		.WORD _sA_menu0_ponder
		.WORD _sA_menu0_check0_init
		.WORD _sA_menu0_open
_sA_menu1:
		.WORD _sA_menu1_about_terrorist
		.WORD _sA_menu1_about_army
		.WORD _sA_menu1_about_tetsuo
		.WORD _sA_menu1_about_kei
_sA_menu2:
		.WORD _sA_menu2_door
		.WORD _sA_menu2_beer
_sA_menu3:
		.WORD _sA_menu3_run
		.WORD _sA_menu3_drink
		.WORD _sA_menu3_peek
_sA_menu4:
		.WORD _sA_menu4_check
		.WORD _sA_menu4_go_on
_sA_menu5:
		.WORD _sA_menu5_check
		.WORD _sA_menu5_inquire
		.WORD _sA_menu5_go_on
_sA_menu6:
		.WORD _sA_menu6_check
		.WORD _sA_menu6_inquire
		.WORD _sA_menu6_go_on

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu0_ponder:
		SW_NXT	_generic_menu_input
		LDA		#1
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default4
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu0_check0_init:
		LDA		#$81
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
		SW_NXT	_sA_sub0B_check0_select
		SW_CUR	_sA_sub0B_check0_select
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu0_open:
		LDA		_scene_flags
		AND		#8
		BNE		loc_39D79
		SW_NXT	_generic_menu_input
		LDA		#2
		STA		_scene_menu_idx
		JSR		_sA_menu_init2
		JMP		_menu_draw_msg_modeF
loc_39D79:
		SW_NXT	_sA_sub11_check1_init
		SW_CUR	_sA_sub11_check1_init
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu1_about_terrorist:
		SW_NXT	_sA_sub02_closet_menu0_loop
		MSG_1	_scA_msg02

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu1_about_army:
		SW_NXT	_sA_sub02_closet_menu0_loop
		MSG_1	_scA_msg04

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu1_about_tetsuo:
		SW_NXT	_sA_sub02_closet_menu0_loop
		MSG_1	_scA_msg05

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu1_about_kei:
		SW_NXT	_sA_sub02_closet_menu0_loop
		MSG_1	_scA_msg03

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu2_door:
		SW_NXT	_sA_sub02_closet_menu0_loop
		MSG_1	_scA_10_msg94

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu2_beer:
		LDA		#0
		STA		_nmi_ppu_draw0_req
		LDA		_scene_flags
		ORA		#8
		STA		_scene_flags
		SW_NXT	_sA_sub14_return_to_closet_menu0
		MSG_M
		MSG		_scA_msg0A
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu3_run:
		SW_FADE	_sA_sub0D_run_draw
		MSG_1	_scA_msg0E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu3_drink:
		SW_FADE	_sA_sub15_drunk_delay
		LDA		_scene_flags
		AND		#$EF
		STA		_scene_flags
		MSG_M
		MSG		_sc5_A_msg7F
		MSG		_scA_msg0F
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu3_peek:
		SW_NXT	_sA_sub06_closet_menu1_loop
		MSG_1	_scA_msg15

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu4_check:
		SW_NXT	_sA_sub0E_run_menu_loop
		MSG_1	_scA_msg12

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu4_go_on:
		SW_NXT	_sA_sub0F_run_go_on
		JMP		_fade_out_reqest

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu5_check:
		SW_NXT	_sA_sub10_run_go_on_menu0_loop
		MSG_1	_scA_msg13

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu5_inquire:
		SW_NXT	_sA_sub10_run_go_on_menu0_loop
		LDA		_scene_flags
		AND		#2
		BNE		loc_39E53
		LDA		_scene_flags
		ORA		#2
		STA		_scene_flags
		MSG_M
		MSG		_scA_msg14						; "i hear voices"
		MSG		_scA_B_msgA6					; full conversation
		MSG		_scA_B_msgB0
		MSG		_scA_B_msgA7
		MSG		_scA_B_msgB1
		MSG		_scA_B_msgB2
		MSG		_scA_B_msgA8
		MSG		_scA_B_msgAF
		MSG		_scA_B_msgA9
		MSG		_scA_B_msgAA
		MSG		_scA_msg07
		MSG_EOL
loc_39E53:
		MSG_1	_scA_msg1A						; maybe I can hear they talk?

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu5_go_on:
		LDA		_scene_flags
		AND		#2
		BNE		loc_39E69
		SW_NXT	_sA_sub10_run_go_on_menu0_loop
		MSG_1	_scA_msg14
loc_39E69:
		JSR		_snd_sewers_kick_fence
		SW_FADE	_next_scene
		MSG_M
		MSG		_scA_msg18
		MSG		_scA_msg19
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu6_check:
		SW_NXT	_sA_sub12_run_go_on_menu1_loop
		MSG_1	_scA_msg13

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu6_inquire:
		SW_NXT	_sA_sub12_run_go_on_menu1_loop
		MSG_1	_scA_msg14

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_menu6_go_on:
		LDA		_scene_flags
		AND		#4
		BNE		loc_39EB2
		LDA		_scene_flags
		ORA		#4
		STA		_scene_flags
		SW_NXT	_sA_sub12_run_go_on_menu1_loop
		MSG_1	_scA_msg14
loc_39EB2:
		JSR		_snd_sewers_kick_fence
		SW_FADE	_next_scene						; previously unfaded
		MSG_M
		MSG		_scA_msg18
		MSG		_scA_msg19
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_scroll_draw:
		JSR		_sA_scr_cur_scroll_calc
		LDA		_scroll_x_shadow
		AND		#7
		CMP		#4
		BCC		loc_39EFB
		LDA		_scroll_x_shadow
		CLC
		ADC		#8
		STA		byte_35D
		LDA		_scroll_x_shadow+1
		ADC		#1
		STA		byte_35E
		JMP		loc_39F13
loc_39EFB:
		LDA		_scroll_x_shadow
		SEC
		SBC		#8
		STA		byte_35D
		LDA		_scroll_x_shadow+1
		SBC		#0
		STA		byte_35E
		CMP		#$FF
		BNE		loc_39F13
		LDA		#5
		STA		byte_35E
loc_39F13:
		LDX		byte_35E
		LDA		_menu_restore_tlm_idx_list,X
		JMP		_tlm_get_index_by_number

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_scr_cur_scroll_calc:
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
		BCC		loc_39F57
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
		BCS		loc_39F74
		RTS
loc_39F57:
		LDA		_scroll_x_shadow
		SEC
		SBC		#1
		STA		_scroll_x_shadow
		LDA		_scroll_x_shadow+1
		SBC		#0
		STA		_scroll_x_shadow+1
		BCS		locret_39F8E
		LDA		#$FF
		STA		_scroll_x_shadow
		LDA		#5
		STA		_scroll_x_shadow+1
		LDA		#6
		STA		_screen_cursor_x+1
		RTS
loc_39F74:
		LDA		_scroll_x_shadow
		CLC
		ADC		#1
		STA		_scroll_x_shadow
		LDA		_scroll_x_shadow+1
		ADC		#0
		STA		_scroll_x_shadow+1
		CMP		#6
		BCC		locret_39F8E
		LDA		#0
		STA		_scroll_x_shadow
		STA		_scroll_x_shadow+1
		STA		_screen_cursor_x+1
locret_39F8E:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sA_water_drops_snd:
		LDA		_frames_counter
		AND		#$3F
		BNE		locret_39F9E
		LDA		_rand
		AND		#7
		BNE		locret_39F9E
		JSR		_snd_water_drop
locret_39F9E:
		RTS

		SECTION_END A
