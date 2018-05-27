
		SECTION_START 1

;-----------------------------------------------
; SCENE 1 (INTERROGATION)
;-----------------------------------------------

; original interactive script:
; 1. talk x 2 (laugh menu added)
; OPTION A {
; 	1. laugh (jump SCENE 2, BRANCH A)
; }
; OPTION B {
; 	1. look->gang (cursor enabled)
; 		- point yamagata x 2
; 		- point kai x 2
; 		- point kaneda x 2
; 	2. press B or wait 16 seconds (laugh replace with peek)
; 	3. peek->list x 2 (inquire added)
; 	4. inquire x 3 (jump SCENE 2, BRANCH B)
; }

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene1_subs:
		JSR		_screen_cursor_handler
		JSR		_s1_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_86E7
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s1_sub00_init_clear
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_generic_menu_input				; former _s1_sub05_menu_input, 03 now
		SW_PTR	_s1_menu_handlers				; 04 now
		SW_PTR	_s1_sub01_interrogate_draw
		SW_PTR	_s1_sub02_msg
		SW_PTR	_s1_sub03_interrogate_update
		SW_PTR	_s1_sub04_scene_main_loop
		SW_PTR	_s1_sub08_gang_view_start
		SW_PTR	_s1_sub13_gang_view_init
		SW_PTR	_s1_sub0A_gang_view_pick
		SW_PTR	_s1_sub0B_clear_before_girl
		SW_PTR	_s1_sub09_girl_icon1_draw
		SW_PTR	_s1_sub0C_girl_msg
		SW_PTR	_s1_sub0F_gang_draw
		SW_PTR	_s1_sub11_interrogate_redraw
		SW_PTR	_s1_sub10_interrogate_loop
		SW_PTR	_s1_sub12_interrogate_pick

locret_86E7:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub00_init_clear:
		LDA		_game_global_flags0				; clear laugh flag only if return here
		AND		#$FE
		STA		_game_global_flags0
		SW_NXT	_s1_sub01_interrogate_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub01_interrogate_draw:
		SW_NXT	_s1_sub02_msg
		LDA		#1
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_tlm02_draw:
		TLM4	2,2,2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub02_msg:
		SW_NXT	_s1_sub03_interrogate_update
		MSG_M
		MSG		_sc1_msgB9
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub03_interrogate_update:
		JSR		_snd_paper_drop_on_table
		LDA		#1
		STA		_scene_anim_idx+2
		STA		_scene_anim_idx+3
		STA		_scene_anim_idx+4
		SW_NXT	_s1_sub04_scene_main_loop
		MSG_1	_sc1_msg0B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub04_scene_main_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_878D
		SW_RET	_s1_sub04_scene_main_loop
		SW_NXT	_generic_menu_input
		LDA		#0
		STA		_scene_menu_idx
		JSR		_s1_menu_items_init
		JMP		_menu_draw_request
locret_878D:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu_items_init:
		LDX		#0
		STX		_scene_menu_items
		INX
		STX		_scene_menu_items+1
		LDA		_scene_flags
		AND		#$F
		CMP		#$F
		BEQ		loc_8A1D
		LDA		_scene_flags
		AND		#1
		BEQ		loc_8A32
		INX
		LDA		#4
		STA		_scene_menu_items,X
		BNE		loc_8A32
loc_8A1D:
		INX
		LDA		#2
		STA		_scene_menu_items,X
		LDA		_scene_flags
		AND		#$1F
		CMP		#$1F
		BNE		loc_8A32
		INX
		LDA		#3
		STA		_scene_menu_items,X
loc_8A32:
		STX		_scene_menu_max_pos
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub08_gang_view_start:
		SW_NXT	_s1_sub13_gang_view_init
		MSG_1	_sc1_msg16

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub09_girl_icon1_draw:
		SW_NXT	_s1_sub0C_girl_msg
		ICON1	4,3,4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub0A_gang_view_pick:
		LDA		_pads+1
		AND		#2
		BNE		loc_88FA
		LDA		_frames_counter
		AND		#$3F
		BNE		locret_890C
		INC		_s1_gang_view_delay_counter
		LDA		_s1_gang_view_delay_counter
		CMP		#$10
		BCC		locret_890C
		LDA		#0
		STA		_active_areas_list_idx
		SW_FADE	_s1_sub11_interrogate_redraw
		MSG_1	_sc1_msg21
loc_88FA:
		LDA		#0
		STA		_active_areas_list_idx
		SW_FADE	_s1_sub11_interrogate_redraw
		JMP		_msg_wnd_clear_request
locret_890C:
		LDA		_pads+1
		AND		#1
		BEQ		locret_87EF
		JSR		_cursor_active_area_test
		CPX		#$FF
		BEQ		locret_87EF
		LDA		#0
		STA		_active_areas_list_idx
		SW_NXT	_s1_sub13_gang_view_init
		TXA
		SWITCH
		SW_PTR	_s1_sub0A_gang_view_pick_0
		SW_PTR	_s1_sub0A_gang_view_pick_1
		SW_PTR	_s1_sub0A_gang_view_pick_2
		SW_PTR	_s1_sub0A_gang_view_pick_3
		SW_PTR	_s1_sub0A_gang_view_pick_4
		SW_PTR	_s1_sub0A_gang_view_pick_5

locret_87EF:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub0A_gang_view_pick_0:
		LDA		_scene_states+1
		BNE		loc_893C
		INC		_scene_states+1
		MSG_1	_sc1_msg17
loc_893C:
		LDA		_scene_flags
		ORA		#2
		STA		_scene_flags
		MSG_M
		MSG		_sc1_msg18
		MSG		_sc1_msg31
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub0A_gang_view_pick_1:
		LDA		_scene_states+2
		BEQ		loc_8973
		CMP		#2
		BCS		loc_8976
		LDA		_scene_flags
		ORA		#4
		STA		_scene_flags
		INC		_scene_states+2
		MSG_M
		MSG		_sc1_msg1F
		MSG		_sc1_msg80
		MSG_EOL
loc_8973:
		INC		_scene_states+2
loc_8976:
		MSG_1	_sc1_msg1A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub0A_gang_view_pick_2:
		LDA		_scene_states+3
		BEQ		loc_89A5
		CMP		#2
		BCS		loc_89A8
		LDA		_scene_flags
		ORA		#8
		STA		_scene_flags
		INC		_scene_states+3
		MSG_M
		MSG		_sc1_msg20
		MSG		_sc1_msg80
		MSG_EOL
loc_89A5:
		INC		_scene_states+3
loc_89A8:
		MSG_1	_sc1_msg1B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub0A_gang_view_pick_3:
		MSG_1	_sc1_msg1C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub0A_gang_view_pick_4:
		MSG_1	_sc1_msg1D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub0A_gang_view_pick_5:
		MSG_1	_sc1_msg1E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub0B_clear_before_girl:
		LDA		#0
		STA		_scene_spr_overlay_idx
		SW_NXT	_s1_sub09_girl_icon1_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub0C_girl_msg:
		SW_FADE	_s1_sub11_interrogate_redraw
		MSG_M
		MSG		_sc1_msg81
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub0F_gang_draw:
		SW_NXT	_s1_sub08_gang_view_start
		LDA		#2
		STA		_scene_spr_overlay_idx
		TLM4	3,3,3

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub10_interrogate_loop:
		SW_NXT	_s1_sub04_scene_main_loop		; ok, here we check for gang-look done
		LDA		_scene_flags					; and the first talk sequence as well
		AND		#$F								; now, any time we return to interrogation
		CMP		#$F								; room, the army will ask "so you not a terrorists?"
		BNE		locret_8852						; which is reset the kaneda's ansers all the way
		LDA		_scene_flags					; you may done it as many times as you wish
		ORA		#$20							; just exit to gang view and return back,
		STA		_scene_flags					; now the main menu is inquire
		LDA		#0
		STA		_scene_states
		MSG_1	_sc1_msg22
locret_8852:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub11_interrogate_redraw:
		SW_NXT	_s1_sub10_interrogate_loop
		LDA		#1
		STA		_scene_spr_overlay_idx
		STA		_scene_anim_idx+2
		STA		_scene_anim_idx+3
		STA		_scene_anim_idx+4
		JMP		_s1_tlm02_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub12_interrogate_pick:
		LDA		_pads+1
		AND		#1
		BEQ		locret_889D
		JSR		_cursor_active_area_test
		CPX		#$FF
		BNE		loc_8883
		LDX		#6								; default option, any other part of the screen
loc_8883:
		LDA		#0
		STA		_active_areas_list_idx
		SW_NXT	_s1_sub04_scene_main_loop
		TXA
		SWITCH
		SW_PTR	_s1_sub12_interrogate_pick_0
		SW_PTR	_s1_sub12_interrogate_pick_1
		SW_PTR	_s1_sub12_interrogate_pick_2
		SW_PTR	_s1_sub12_interrogate_pick_3
		SW_PTR	_s1_sub12_interrogate_pick_4
		SW_PTR	_s1_sub12_interrogate_pick_5
		SW_PTR	_s1_sub12_interrogate_pick_6

locret_889D:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub12_interrogate_pick_0:
		MSG_1	_sc1_msg11

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub12_interrogate_pick_1:
		MSG_1	_sc1_msg12

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub12_interrogate_pick_2:
		MSG_1	_sc1_msg13

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub12_interrogate_pick_3:
		MSG_1	_sc1_msg14

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub12_interrogate_pick_4:
		MSG_M
		MSG		_sc1_msg24
		MSG		_sc1_msg80
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub12_interrogate_pick_5:
		MSG_M
		MSG		_sc1_msg25
		MSG		_sc1_msg80
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub12_interrogate_pick_6:
		MSG_1	_sc1_msg32


;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_sub13_gang_view_init:
		SW_NXT	_s1_sub0A_gang_view_pick
		LDA		#1
		STA		_active_areas_list_idx
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu_handlers:
		JSR		_menu_switch
		.WORD _s1_menu0
		.WORD _s1_menu1
		.WORD _s1_menu2
_s1_menu0:
		.WORD _s1_menu0_talk
		.WORD _s1_menu0_look
		.WORD _s1_menu0_peek
		.WORD _s1_menu0_inquire
		.WORD _s1_menu0_laugh
_s1_menu1:
		.WORD _s1_menu1_gang
		.WORD _s1_menu1_pick
		; army
		; kaneda
		; license
		; list
_s1_menu2:
		.WORD _s1_menu2_army
		.WORD _s1_menu2_desk
		.WORD _s1_menu2_list

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu0_talk:
		SW_NXT	_s1_sub04_scene_main_loop
		LDA		_scene_flags
		AND		#$20
		BNE		loc_8AC5
		LDA		_scene_states
		SWITCH
		SW_PTR	_s1_menu0_talk_A
		SW_PTR	_s1_menu0_talk_B
		SW_PTR	_s1_menu0_talk_C
loc_8AC5:
		LDA		_scene_states
		SWITCH
		SW_PTR	_s1_menu0_talk_D
		SW_PTR	_s1_menu0_talk_E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu0_talk_A:
		JSR		_s1_menu0_item_inc0
		MSG_M
		MSG		_sc1_msg0C
		MSG		_sc1_msg0D
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu0_talk_B:
		JSR		_s1_menu0_item_inc0
		MSG_M
		MSG		_sc1_msg0E
		MSG		_sc1_msg0F
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu0_talk_C:
		JSR		_s1_menu0_item_inc0
		MSG_1	_sc1_msg10

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu0_talk_E:
		JSR		_s1_menu0_item_inc1
		MSG_1	_sc1_msg10

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu0_talk_D:
		JSR		_s1_menu0_item_inc1
		MSG_1	_sc1_msg23

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu0_item_inc0:
		LDX		_scene_states
		LDA		_s1_menu0_item_inc0_states,X
		STA		_scene_states
		CMP		#2
		BNE		loc_8AC2
		LDA		_scene_flags					; enable laugh menu
		ORA		#1
		STA		_scene_flags
loc_8AC2:
		RTS
_s1_menu0_item_inc0_states:
		.BYTE	1,2,2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu0_item_inc1:
		LDX		_scene_states
		LDA		_s1_menu0_item_inc1_states,X
		STA		_scene_states
		RTS
_s1_menu0_item_inc1_states:
		.BYTE	1,1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu0_look:
		SW_NXT	_generic_menu_input
		LDA		#1
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default2
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu0_peek:
		SW_NXT	_generic_menu_input
		LDA		#2
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default3
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu0_inquire:
		LDA		_scene_flags+1
		INC		_scene_flags+1
		SWITCH
		.WORD	_s1_menu0_inquire_A
		.WORD	_s1_menu0_inquire_B
		.WORD	_s1_menu0_inquire_C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu0_inquire_A:
		SW_NXT	_s1_sub04_scene_main_loop
		MSG_M
		MSG		_sc1_msg28
		MSG		_sc1_msg80
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu0_inquire_B:
		SW_NXT	_s1_sub04_scene_main_loop
		MSG_M
		MSG		_sc1_msg29
		MSG		_sc1_msg31
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu0_inquire_C:
		SW_FADE	_next_scene						; var3 here is clear, so return to next scene if die
		MSG_M
		MSG		_sc1_msg2A
		MSG		_sc1_msg2B
		MSG		_sc1_msg2C
		MSG		_sc1_msg15
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu0_laugh:
		SW_FADE	_next_scene
		LDA		_game_global_flags0				; if set, return here if die
		ORA		#1
		STA		_game_global_flags0
		MSG_M
		MSG		_sc1_msg2D
		MSG		_sc1_msg2C
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu1_gang:
		SW_NXT	_s1_sub0F_gang_draw
		LDA		#0
		STA		_s1_gang_view_delay_counter
		STA		_screen_cursor_x+1
		LDA		#$40
		STA		_screen_cursor_y
		ASL
		STA		_screen_cursor_x
		JMP		_fade_out_reqest

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu1_pick:
		SW_NXT	_s1_sub12_interrogate_pick
		SW_CUR	_s1_sub12_interrogate_pick
		LDA		#2
		STA		_active_areas_list_idx
		LDA		#0
		STA		_screen_cursor_x+1
		LDA		#$40
		STA		_screen_cursor_y
		ASL
		STA		_screen_cursor_x
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu2_army:
		SW_NXT	_s1_sub04_scene_main_loop
		MSG_M
		MSG		_sc1_msg24
		MSG		_sc1_msg31
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu2_desk:
		SW_NXT	_s1_sub04_scene_main_loop
		MSG_M
		MSG		_sc1_msg25
		MSG		_sc1_msg31
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_menu2_list:
		LDA		_scene_flags+2
		BNE		loc_8BF4
		INC		_scene_flags+2
		SW_NXT	_s1_sub04_scene_main_loop
		MSG_1	_sc1_msg81
loc_8BF4:
		LDA		_scene_flags
		ORA		#$10
		STA		_scene_flags
		SW_FADE	_s1_sub0B_clear_before_girl
		MSG_1	_sc1_msg27

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s1_spr_overlay1
		SW_PTR	_s1_spr_overlay2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_spr_overlay1:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0SW	off_8C5F,$48,$70
		LDA		_scene_anim_idx+2
		SPR0SW	off_8C7D,$50,$48
		LDA		_scene_anim_idx+3
		SPR0SW	off_8CC2,$40,$E8
		LDA		_scene_anim_idx+3
		BEQ		loc_8CCC
		JSR		_do_scene_anim1_pat0101			; second's army interrogator to the right mouth anim
		LDA		_scene_anim_idx+1				; used at the end of scene
		SPR0SW	off_8CC8,$40,$E8
loc_8CCC:
		LDA		_scene_anim_idx+4
		SPR0JSW	off_8CE6,$68,$40
off_8C5F:
		.WORD _spr_sc1_army_mouth0
		.WORD _spr_sc1_army_mouth1
off_8C7D:
		.WORD _spr_sc1_interrog_army_hand_up
		.WORD _spr_sc1_interrog_army_hand_empty
off_8CC2:
		.WORD _spr_sc1_interrog_army_to_the_right0
		.WORD _spr_sc1_interrog_army_to_the_right1
off_8CC8:
		.WORD _spr_sc1_interrog_army_to_the_right_mouth1
		.WORD _spr_sc1_interrog_army_to_the_right_mouth0
off_8CE6:
		.WORD _spr_dummy
		.WORD _spr_sc1_interrog_license

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s1_spr_overlay2:
		SPR0	_spr_sc1_ganga_kuwata_head,$30,$90
		SPR0	_spr_sc1_ganga_kaneda_head,$50,$78
		SPR0J	_spr_sc1_ganga_takeyama_head,$58,$E0

_spr_sc1_army_mouth1:
		.BYTE   0,$92,  1,  0
		.BYTE   0,$93,  1,  8
		.BYTE $80
_spr_sc1_army_mouth0:
		.BYTE   0,$94,  1,  0
		.BYTE   0,$95,  1,  8
		.BYTE $80
_spr_sc1_interrog_army_to_the_right_mouth0:
		.BYTE $18,$84,  1,  0
		.BYTE $80
_spr_sc1_interrog_army_to_the_right_mouth1:
		.BYTE $18,$88,  1,  0
		.BYTE $80
_spr_sc1_interrog_army_hand_up:
		.BYTE   0,$98,  2,  8
		.BYTE   8,$96,  2,  8
		.BYTE   8,$97,  1,$10
		.BYTE $10,$99,  1,  8
		.BYTE $10,$9A,  1,$10
		.BYTE $80
_spr_sc1_interrog_army_hand_empty:
		.BYTE   8,$9B,  1,  0
		.BYTE   8,$9C,  1,  8
		.BYTE   8,$9D,  1,$10
		.BYTE $10,$9E,  1,  0
		.BYTE $10,$9F,  1,  8
		.BYTE $10,$A0,  1,$10
		.BYTE $80
_spr_sc1_interrog_army_to_the_right0:
		.BYTE   0,$80,  1,  0
		.BYTE   0,$A8,  1,  8
		.BYTE   8,$8A,  1,  0
		.BYTE   8,$AF,  1,  8
		.BYTE   8,$8B,  1,$10
		.BYTE $10,$8C,  1,  0
		.BYTE $10,$8D,  1,  8
		.BYTE $10,$8E,  1,$10
		.BYTE $18,$8F,  1,  0
		.BYTE $18,$90,  1,  8
		.BYTE $18,$91,  1,$10
		.BYTE $80
_spr_sc1_interrog_army_to_the_right1:
		.BYTE   0,$80,  1,  0
		.BYTE   0,$A8,  1,  8
		.BYTE   8,$82,  1,  0
		.BYTE   8,$AF,  1,  8
		.BYTE   8,$83,  1,$10
		.BYTE $10,$85,  1,  0
		.BYTE $10,$86,  1,  8
		.BYTE $10,$87,  1,$10
		.BYTE $18,$89,  1,  8
		.BYTE $18,$91,  1,$10
		.BYTE $80
_spr_sc1_interrog_license:
		.BYTE   0,$A1,  2,  0
		.BYTE   0,$A2,  2,  8
		.BYTE $80
_spr_sc1_ganga_kuwata_head:
		.BYTE   0,$80,  1,  0
		.BYTE   0,$82,  1,  8
		.BYTE   0,$AB,  1,$10
		.BYTE   0,$83,  1,$18
		.BYTE   0,$84,  1,$20
		.BYTE   8,$85,  1,  0
		.BYTE   8,$86,  1,  8
		.BYTE   8,$87,  1,$10
		.BYTE   8,$88,  1,$18
		.BYTE   8,$89,  1,$20
		.BYTE $10,$8A,  1,  0
		.BYTE $10,$8B,  1,  8
		.BYTE $10,$8C,  1,$10
		.BYTE $10,$8D,  1,$18
		.BYTE $10,$8E,  1,$20
		.BYTE $18,$8F,  1,  0
		.BYTE $18,$90,  1,  8
		.BYTE $18,$91,  1,$10
		.BYTE $18,$92,  1,$18
		.BYTE $20,$96,  1,  8
		.BYTE $20,$97,  1,$10
		.BYTE $20,$98,  1,$18
		.BYTE $80
_spr_sc1_ganga_kaneda_head:
		.BYTE   0,$93,  1,  8
		.BYTE   0,$94,  1,$10
		.BYTE   0,$95,  1,$18
		.BYTE   8,$99,  1,  8
		.BYTE   8,$9A,  1,$10
		.BYTE   8,$9B,  1,$18
		.BYTE $10,$9C,  1,  0
		.BYTE $10,$9D,  1,  8
		.BYTE $10,$9E,  1,$18
		.BYTE $18,$9F,  1,  0
		.BYTE $18,$A0,  1,  8
		.BYTE $18,$A1,  1,$10
		.BYTE $18,$A2,  1,$18
		.BYTE $20,$A3,  1,$10
		.BYTE $20,$A4,  1,$18
		.BYTE $20,$A5,  1,$20
		.BYTE $28,$A6,  1,  8
		.BYTE $28,$A7,  1,$10
		.BYTE $28,$A8,  1,$18
		.BYTE $28,$A9,  1,$20
		.BYTE $80
_spr_sc1_ganga_takeyama_head:
		.BYTE   0,$AA,  1,  0
		.BYTE   0,$AB,  1,  8
		.BYTE   0,$AC,  1,$10
		.BYTE   0,$AD,  1,$18
		.BYTE   8,$AE,  1,  0
		.BYTE   8,$AF,  1,$10
		.BYTE $10,$B0,  1,  8
		.BYTE $10,$B1,  1,$10
		.BYTE $10,$B2,  1,$18
		.BYTE $18,$B3,  1,  0
		.BYTE $18,$B4,  1,  8
		.BYTE $18,$B5,  1,$10
		.BYTE $18,$B6,  1,$18
		.BYTE $20,$B7,  1,  8
		.BYTE $20,$B8,  1,$10
		.BYTE $20,$B9,  1,$18
		.BYTE $80

		SECTION_END 1
