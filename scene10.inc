
		SECTION_START 10

;-----------------------------------------------
; SCENE 10
;-----------------------------------------------

; original interactive script:
; 1. call (full menu)
; 2. inquire->army
; 3. inquire->terrorist x 2
; 4. inquire->tetsuo (akira added)
; 5. inquire->akira
; 6. ponder
; 7. run (jump SCENE 11)

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene10_subs:
		JSR		_screen_cursor_handler
		JSR		_s10_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_9811A
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s10_sub00_clear
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_generic_menu_input				; make sure this is 03
		SW_PTR	_s10_menu_handlers				; and this is 04!
		SW_PTR	_s10_sub05_closet_draw
		SW_PTR	_s10_sub06_closet_msg
		SW_PTR	_s10_sub02_closet_menu_loop
		SW_PTR	_s10_sub08_check_select
		SW_PTR	_s10_sub09_kei_story_msgs
		SW_PTR	_s10_sub0B_door_open_draw
		SW_PTR	_s10_sub0A_door_open_menu_loop
		SW_PTR	_s10_sub0C_door_open_msg

locret_9811A:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_sub00_clear:
		SW_NXT	_s10_sub05_closet_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_sub05_closet_draw:
		SW_NXT	_s10_sub06_closet_msg
		TLM4	$2A,$27,$48

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_sub06_closet_msg:
		SW_NXT	_s10_sub02_closet_menu_loop
		MSG_1	_sc10_msg00

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_sub02_closet_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_9815B
		SW_RET	_s10_sub02_closet_menu_loop
		SW_NXT	_generic_menu_input
		LDA		#0
		STA		_scene_menu_idx
		JSR		_s10_menu_init0
		JMP		_menu_draw_request
locret_9815B:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_sub08_check_select:
		LDA		_pads+1
		AND		#1
		BEQ		locret_981C4
		JSR		_cursor_active_area_test
		CPX		#$FF
		BNE		loc_981A8
		LDX		#3
loc_981A8:
		CPX		#2
		BNE		loc_981B4
		LDA		_scene_flags
		AND		#$20
		BNE		loc_981B4
		INX
loc_981B4:
		LDA		#0
		STA		_active_areas_list_idx
		SW_NXT	_s10_sub02_closet_menu_loop
		TXA
		SWITCH
		.WORD	_s10_sub08_check_select_A
		.WORD	_s10_sub08_check_select_B
		.WORD	_s10_sub08_check_select_C
		.WORD	_s10_sub08_check_select_D

locret_981C4:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_sub08_check_select_A:
		MSG_1	_scA_10_msg94

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_sub08_check_select_B:
		MSG_1	_sc10_msg03

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_sub08_check_select_C:
		MSG_1	_sc10_msg02

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_sub08_check_select_D:
		MSG_1	_sc10_msg04

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_sub09_kei_story_msgs:
		JSR		_snd_kiyoko_psychodelic
		SW_NXT	_s10_sub0B_door_open_draw
		MSG_M
		MSG		_sc10_msg11
		MSG		_sc10_msg1A
		MSG		_sc10_msg12
		MSG		_sc10_msg1B
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_sub0B_door_open_draw:
		JSR		_snd_punch2
		LDA		_scene_flags
		ORA		#$40
		STA		_scene_flags
		LDA		#1
		STA		_nmi_ppu_tlm_draw_req
		SW_NXT	_s10_sub0C_door_open_msg
		SW_CUR	_s10_sub0C_door_open_msg
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_sub0C_door_open_msg:
		SW_NXT	_s10_sub0A_door_open_menu_loop
		MSG_1	_sc10_msg13

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_sub0A_door_open_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_981FC
		SW_RET	_s10_sub0A_door_open_menu_loop
		SW_NXT	_generic_menu_input
		LDA		#1
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default2
		JMP		_menu_draw_request
locret_981FC:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_menu_init0:
		LDA		_scene_flags
		AND		#$20
		BNE		loc_9825B
		LDA		#0
		STA		_scene_menu_items
		LDA		#3
		STA		_scene_menu_items+1
		LDA		#1
		STA		_scene_menu_max_pos
		RTS
loc_9825B:
		JMP		_scene_menu_init_default3

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_menu_init2:
		LDA		_scene_flags
		AND		#$F
		CMP		#$F
		BNE		locret_98281
		JMP		_scene_menu_init_default4
locret_98281:
		JMP		_scene_menu_init_default3

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_menu_handlers:
		JSR		_menu_switch
		.WORD _s10_menu0
		.WORD _s10_menu1
		.WORD _s10_menu2
_s10_menu0:
		.WORD _s10_menu0_check
		.WORD _s10_menu0_inquire
		.WORD _s10_menu0_ponder
		.WORD _s10_menu0_call
_s10_menu1:
		.WORD _s10_menu1_run
		.WORD _s10_menu1_shout
_s10_menu2:
		.WORD _s10_menu2_about_army
		.WORD _s10_menu2_about_terrorists
		.WORD _s10_menu2_about_tetsuo
		.WORD _s10_menu2_about_akira

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_menu0_check:
		LDA		#5
		STA		_active_areas_list_idx
		LDA		#0
		STA		_screen_cursor_x
		LDA		#$40
		STA		_screen_cursor_y
		ASL
		STA		_screen_cursor_x
		SW_NXT	_s10_sub08_check_select
		SW_CUR	_s10_sub08_check_select
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_menu0_inquire:
		SW_NXT	_generic_menu_input
		LDA		#2
		STA		_scene_menu_idx
		JSR		_s10_menu_init2
		JMP		_menu_draw_request

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_menu0_ponder:
		LDA		_scene_flags
		AND		#$10
		BNE		loc_982FC
		SW_NXT	_s10_sub02_closet_menu_loop
		MSG_1	_sc10_msg16
loc_982FC:
		SW_NXT	_s10_sub09_kei_story_msgs
		MSG_M
		MSG		_sc10_msg0F
		MSG		_sc10_msg10
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_menu0_call:
		LDA		_scene_flags
		ORA		#$20
		STA		_scene_flags
		LDA		#1
		STA		_scene_spr_overlay_idx
		SW_NXT	_s10_sub02_closet_menu_loop
		MSG_1	_sc10_msg01

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_menu1_run:
		SW_FADE	_next_scene						; previously drawn unfaded
		MSG_M
		MSG		_sc10_msg14
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_menu1_shout:
		SW_NXT	_s10_sub0A_door_open_menu_loop
		MSG_1	_sc10_msg15

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_menu2_about_army:
		LDA		_scene_flags
		ORA		#8
		STA		_scene_flags
		SW_NXT	_s10_sub02_closet_menu_loop
		MSG_1	_sc10_msg05

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_menu2_about_terrorists:
		SW_NXT	_s10_sub02_closet_menu_loop
		LDA		_scene_flags
		AND		#1
		BNE		loc_9837D
		LDA		_scene_flags
		ORA		#1
		STA		_scene_flags
		MSG_M
		MSG		_sc10_msg02
		MSG		_sc2_F_10_12_13_msg85
		MSG_EOL
loc_9837D:
		LDA		_scene_flags
		ORA		#2
		STA		_scene_flags
		MSG_1	_sc10_msg07

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_menu2_about_tetsuo:
		LDA		_scene_flags
		ORA		#4
		STA		_scene_flags
		SW_NXT	_s10_sub02_closet_menu_loop
		MSG_1	_sc10_msg06

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_menu2_about_akira:
		LDA		_scene_flags
		ORA		#$10
		STA		_scene_flags
		SW_NXT	_s10_sub02_closet_menu_loop
		MSG_M
		MSG		_sc10_msg08
		MSG		_sc10_msg09
		MSG		_sc10_msg0A
		MSG		_sc10_msg0B
		MSG		_sc10_msg17
		MSG		_sc10_msg0C
		MSG		_sc10_msg0D
		MSG		_sc10_msg18
		MSG		_sc10_msg0E
		MSG		_sc10_msg19
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s10_spr_overlay1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s10_spr_overlay1:
		SPR0	_spr_sc10_kei_body,$50,$50
		JSR		_get_anim_blink_idx
		SPR0SW	off_98429,$50,$50
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0JSW	off_9842F,$50,$50
off_98429:
		.WORD _spr_sc10_kei_eyes0
		.WORD _spr_sc10_kei_eyes1
off_9842F:
		.WORD _spr_sc10_kei_mouth0
		.WORD _spr_sc10_kei_mouth1

_spr_sc10_kei_body:
		.BYTE   0,$B2,  3,  8
		.BYTE   0,$B3,  3,$10
		.BYTE   0,$B4,  3,$18
		.BYTE   0,$B5,  3,$20
		.BYTE   0,$B6,  3,$28
		.BYTE   8,$B7,  3,  8
		.BYTE   8,$B8,  3,$10
		.BYTE   8,$B9,  3,$18
		.BYTE   8,$B8,  3,$20
		.BYTE   8,$BA,  3,$28
		.BYTE $10,$BB,  2,  8
		.BYTE $10,$BC,  2,$10
		.BYTE $10,$BD,  2,$18
		.BYTE $10,$BE,  2,$20
		.BYTE $10,$BF,  2,$28
		.BYTE $18,$C0,  2,  8
		.BYTE $18,$C4,  2,$28
		.BYTE $20,$C5,  2,  8
		.BYTE $20,$C6,  2,$10
		.BYTE $20,$C8,  2,$20
		.BYTE $20,$C9,  2,$28
		.BYTE $28,$CA,  2,  0
		.BYTE $28,$CB,  2,  8
		.BYTE $28,$CC,  2,$10
		.BYTE $28,$CD,  2,$18
		.BYTE $28,$CE,  2,$20
		.BYTE $28,$CF,  2,$28
		.BYTE $28,$D0,  2,$30
		.BYTE $80
_spr_sc10_kei_eyes0:
		.BYTE $18,$C1,  1,$10
		.BYTE $18,$C2,  1,$18
		.BYTE $18,$C3,  1,$20
		.BYTE $80
_spr_sc10_kei_eyes1:
		.BYTE $18,$D1,  1,$10
		.BYTE $18,$D2,  1,$18
		.BYTE $18,$D3,  1,$20
		.BYTE $80
_spr_sc10_kei_mouth1:
		.BYTE $20,$D4,  1,$18
		.BYTE $80
_spr_sc10_kei_mouth0:
		.BYTE $20,$C7,  1,$18
		.BYTE $80

		SECTION_END 10
