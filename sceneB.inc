
		SECTION_START B

;-----------------------------------------------
; SCENE B
;-----------------------------------------------

; original interactive script:
; BRANCH A {
; 	1. talk
; 	2. inquire->army
; 	3. inquire->terrorists
; 	4. ponder
; 	5. beg x 2 (jump SCENE C)
; }
; BRANCH B {
; 	1. beg x 2
; 	1.x take->lab ID (jump SCENE A, BRANCH B)
; 	2. inquire->army
; 	2.x take->lab ID (jump SCENE A, BRANCH B)
; 	3. inquire->terrorists
; 	3.x take->lab ID (jump SCENE A, BRANCH B)
; 	4. ponder
; 	4.x take->lab ID (jump SCENE A, BRANCH B)
; 	5. take->lab ID (jump SCENE C)
; }

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sceneB_subs:
		JSR		_sB_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_504EF
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_sB_sub00_scene_branch
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_generic_menu_input
		SW_PTR	_sB_menu_handlers
		SW_PTR	_sB_sub05_fence_grab_draw_A		; BRANCH A
		SW_PTR	_sB_sub06_fence_grab_msg_A
		SW_PTR	_sB_sub0A_terrorist_close_up_draw_A
		SW_PTR	_sB_sub02_terrorist_close_up_menu_loop_A
		SW_PTR	_sB_sub0A_terrorist_close_up_msg_A
		SW_PTR	_sB_sub08_terrorists_room_draw_A
		SW_PTR	_sB_sub09_terrorists_room_msg_A
		SW_PTR	_sB_sub0C_terrorists_room_menu_loop_A
		SW_PTR	_sB_sub10_terrorists_room_draw_B; BRANCH B
		SW_PTR	_sB_sub11_terrorists_room_msg_B
		SW_PTR	_sB_sub12_terrorists_room_menu_loop_B
		SW_PTR	_sB_sub13_return_to_closet_B
locret_504EF:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_sub00_scene_branch:
		LDA		_game_global_flags0				; if already visited this room
		AND		#4								; or lied to the terrorists
		BNE		loc_50532						; start from beginning, BRANCH A
		LDA		_game_global_flags0
		AND		#2
		BEQ		loc_50532
		SW_NXT	_sB_sub10_terrorists_room_draw_B; if tell truth, continue from the middle part
		JMP		_clear_nt0						; BRANCH B
loc_50532:
		SW_NXT	_sB_sub05_fence_grab_draw_A
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_sub05_fence_grab_draw_A:
		JSR		_snd_punch0						; let's try to keep both sounds somehow
		SW_NXT	_sB_sub06_fence_grab_msg_A
		LDA		#0
		STA		_scene_spr_overlay_idx
		STA		_scroll_x_shadow
		STA		_scroll_x_shadow+1
		TLM5	$34,$36,$59

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_sub06_fence_grab_msg_A:
;		JSR		_snd_punch0						; 3E will be overwritten with 40
		JSR		_snd_punch2						; so we couldn't hear 3E at all here
		SW_FADE	_sB_sub0A_terrorist_close_up_draw_A
		MSG_M
		MSG		_scB_msg00
		MSG		_scB_msg01
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_sub0A_terrorist_close_up_draw_A:
		SW_NXT	_sB_sub0A_terrorist_close_up_msg_A
		LDA		#2
		STA		_scene_spr_overlay_idx			; overlay is the same too, will use EXOFS
		TLM5	$2E,$31,$55						; the same as in scene 9

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_sub0A_terrorist_close_up_msg_A:
		SW_NXT	_sB_sub02_terrorist_close_up_menu_loop_A
		MSG_1	_scB_msg02

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_sub02_terrorist_close_up_menu_loop_A:
		LDA		_pads+1
		AND		#1
		BEQ		locret_50556
		SW_RET	_sB_sub02_terrorist_close_up_menu_loop_A
		LDA		#0
		JSR		_sB_menu_inits
		JMP		_menu_draw_request
locret_50556:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_sub08_terrorists_room_draw_A:
		SW_NXT	_sB_sub09_terrorists_room_msg_A

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_tlm5A_draw:
		LDA		#1
		STA		_scene_spr_overlay_idx
		TLM4	$35,$37,$5A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_sub09_terrorists_room_msg_A:
		SW_NXT	_sB_sub0C_terrorists_room_menu_loop_A
		MSG_1	_scB_msg05

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_sub0C_terrorists_room_menu_loop_A:
		LDA		_pads+1
		AND		#1
		BEQ		locret_5061F
		SW_RET	_sB_sub0C_terrorists_room_menu_loop_A
		LDA		#1
		JSR		_sB_menu_inits
		JMP		_menu_draw_request
locret_5061F:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_sub10_terrorists_room_draw_B:
		SW_NXT	_sB_sub11_terrorists_room_msg_B
		JMP		_sB_tlm5A_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_sub11_terrorists_room_msg_B:
		SW_NXT	_sB_sub12_terrorists_room_menu_loop_B
		MSG_M
		MSG		_scB_msg09						; A6-AA, AF, B0-B1 used in A and B
		MSG		_scA_B_msgA6
		MSG		_scA_B_msgB0
		MSG		_scA_B_msgA7
		MSG		_scA_B_msgB1
		MSG		_scA_B_msgB2
		MSG		_scA_B_msgA8
		MSG		_scA_B_msgAF
		MSG		_scA_B_msgA9
		MSG		_scA_B_msgAA
		MSG		_scB_msg0C
		MSG		_scB_msg08
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_sub12_terrorists_room_menu_loop_B:
		LDA		_pads+1
		AND		#1
		BEQ		locret_50674
		SW_RET	_sB_sub12_terrorists_room_menu_loop_B
		LDA		#2
		JSR		_sB_menu_inits
		JMP		_menu_draw_request
locret_50674:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_sub13_return_to_closet_B:
		LDA		_game_global_flags0
		ORA		#4
		STA		_game_global_flags0
		LDA		#$A
		JMP		_new_scene

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu_inits:
		STA		_scene_menu_idx
		SW_NXT	_generic_menu_input
		LDA		_scene_menu_idx
		SWITCH
		.WORD	_scene_menu_init_default1
		.WORD	_scene_menu_init_default3
		.WORD	_scene_menu_init_default4
		.WORD	_scene_menu_init_default2
		.WORD	_scene_menu_init_default3
		.WORD	_scene_menu_init_default3

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu_handlers:
		JSR		_menu_switch
		.WORD _sB_menu0
		.WORD _sB_menu1
		.WORD _sB_menu2
		.WORD _sB_menu3
		.WORD _sB_menu4
		.WORD _sB_menu5
_sB_menu0:
		.WORD _sB_menu0_talk
_sB_menu1:
		.WORD _sB_menu1_beg
		.WORD _sB_menu1_ponder
		.WORD _sB_menu1_inquire
_sB_menu2:
		.WORD _sB_menu2_take
		.WORD _sB_menu2_beg
		.WORD _sB_menu2_ponder
		.WORD _sB_menu2_inquire
_sB_menu3:
		.WORD _sB_menu3_lab_id
		.WORD _sB_menu3_photo
_sB_menu4:
		.WORD _sB_menu4_about_army
		.WORD _sB_menu4_about_lab
		.WORD _sB_menu4_about_terrorist
_sB_menu5:
		.WORD _sB_menu5_about_army
		.WORD _sB_menu5_about_lab
		.WORD _sB_menu5_about_terrorist

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu0_talk:
		SW_FADE	_sB_sub08_terrorists_room_draw_A
		MSG_M
		MSG		_scB_msg03
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu1_beg:
		LDA		_scene_flags
		AND		#$F
		CMP		#$F
		BEQ		loc_50743
		LDA		_scene_flags
		ORA		#1
		STA		_scene_flags
		SW_NXT	_sB_sub0C_terrorists_room_menu_loop_A
		MSG_1	_scB_msg06
loc_50743:
		SW_FADE	_next_scene
		MSG_M
		MSG		_scB_msg07
		MSG		_scB_msg0A
		MSG		_scB_msg0E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu1_ponder:
		SW_NXT	_sB_sub0C_terrorists_room_menu_loop_A
		LDA		_scene_flags
		AND		#2
		BNE		loc_5076E
		MSG_1	_scB_msg0B
loc_5076E:
		LDA		_scene_flags
		ORA		#4
		STA		_scene_flags
		MSG_1	_scB_msg0D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu1_inquire:
		SW_RET	_sB_sub0C_terrorists_room_menu_loop_A
		LDA		#4
		JSR		_sB_menu_inits
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu2_take:
		SW_RET	_sB_sub12_terrorists_room_menu_loop_B
		LDA		#3
		JSR		_sB_menu_inits
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu2_beg:
		SW_NXT	_sB_sub12_terrorists_room_menu_loop_B
		LDA		_scene_flags+1
		AND		#1
		BNE		loc_507BE
		LDA		_scene_flags+1
		ORA		#1
		STA		_scene_flags+1
		MSG_1	_scB_msg06
loc_507BE:
		LDA		_scene_flags+1
		ORA		#4
		STA		_scene_flags+1
		MSG_1	_scB_msg07

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu2_ponder:
		SW_NXT	_sB_sub12_terrorists_room_menu_loop_B
		LDA		_scene_flags+1
		AND		#2
		BNE		loc_507DC
		MSG_1	_scB_msg0B
loc_507DC:
		LDA		_scene_flags+1
		ORA		#$10
		STA		_scene_flags+1
		MSG_1	_scB_msg0D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu2_inquire:
		SW_RET	_sB_sub12_terrorists_room_menu_loop_B
		LDA		#5
		JSR		_sB_menu_inits
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu3_lab_id:
		SW_NXT	_fade_out_reload_scene
		LDA		_scene_flags+1
		AND		#$1F
		CMP		#$1F
		BEQ		loc_50816
		SW_RLD	_sB_sub13_return_to_closet_B
		MSG_1	_scB_msg12
loc_50816:
		SW_RLD	_next_scene						; previously drawn unfaded
		MSG_M
		MSG		_scB_msg0A
		MSG		_scB_msg0E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu3_photo:
		SW_NXT	_sB_sub12_terrorists_room_menu_loop_B
		MSG_1	_scB_msg13

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu4_about_army:
		LDA		_scene_flags
		ORA		#2
		STA		_scene_flags
		SW_NXT	_sB_sub0C_terrorists_room_menu_loop_A
		MSG_1	_scB_msg0F

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu4_about_lab:
		SW_NXT	_sB_sub0C_terrorists_room_menu_loop_A
		MSG_1	_scB_msg10

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu4_about_terrorist:
		LDA		_scene_flags
		ORA		#8
		STA		_scene_flags
		SW_NXT	_sB_sub0C_terrorists_room_menu_loop_A
		MSG_1	_scB_msg11

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu5_about_army:
		LDA		_scene_flags+1
		ORA		#2
		STA		_scene_flags+1
		SW_NXT	_sB_sub12_terrorists_room_menu_loop_B
		MSG_1	_scB_msg0F

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu5_about_lab:
		SW_NXT	_sB_sub12_terrorists_room_menu_loop_B
		MSG_1	_scB_msg10

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_menu5_about_terrorist:
		LDA		_scene_flags+1
		ORA		#8
		STA		_scene_flags+1
		SW_NXT	_sB_sub12_terrorists_room_menu_loop_B
		MSG_1	_scB_msg11

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_sB_spr_overlay1
		EXOFS	_s9_spr_overlay3				; use me instead!

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s9_spr_overlay3				; 1 time here as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sB_spr_overlay1:
		JSR		_do_scene_anim2_pat0101
		LDA		_scene_anim_idx+2
		SPR0SW	off_508E5,$30,$80
		SPR0	_spr_scB_kei_body,$30,$80
		JSR		_do_scene_anim1_pat0101
		LDA		_scene_anim_idx+1
		SPR0SW	off_50908,$48,$D8
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0JSW	off_5092B,$28,$20
off_50908:
		.WORD _spr_scB_terrorist0_mouth0
		.WORD _spr_scB_terrorist0_mouth1
off_508E5:
		.WORD _spr_scB_kei_mouth0
		.WORD _spr_scB_kei_mouth1
off_5092B:
		.WORD _spr_scB_terrorist2_mouth0
		.WORD _spr_scB_terrorist2_mouth1

_spr_scB_terrorist0_mouth1:
		.BYTE   0,$E5,  3,  0
		.BYTE $80
_spr_scB_terrorist0_mouth0:
		.BYTE   0,$E6,  3,  0
		.BYTE $80
_spr_scB_terrorist2_mouth1:
		.BYTE   0,$E9,  3,  0
		.BYTE   0,$EA,  3,  8
		.BYTE $80
_spr_scB_terrorist2_mouth0:
		.BYTE   0,$E7,  3,  0
		.BYTE   0,$E8,  3,  8
		.BYTE $80
_spr_scB_kei_body:
		.BYTE   0,$EC,$41,  8
		.BYTE   0,$EB,$41,$10
		.BYTE   0,$EB,  1,$18
		.BYTE   0,$EC,  1,$20
		.BYTE   8,$ED,$41,  8
		.BYTE   8,  3,$41,$10
		.BYTE   8,  3,  1,$18
		.BYTE   8,$ED,  1,$20
		.BYTE $10,$F0,$41,  8
		.BYTE $10,$EF,$41,$10
		.BYTE $10,$EF,  1,$18
		.BYTE $10,$F0,  1,$20
		.BYTE $18,$F2,$41,  8
		.BYTE $18,$F2,  1,$20
		.BYTE $20,$F4,$42,  8
		.BYTE $20,$F3,$41,$10
		.BYTE $20,$F3,  1,$18
		.BYTE $20,$F4,  2,$20
		.BYTE $28,$F6,$42,  0
		.BYTE $28,$F5,$42,  8
		.BYTE $28,  2,$42,$10
		.BYTE $28,  2,  2,$18
		.BYTE $28,$F5,  2,$20
		.BYTE $28,$F6,  2,$28
		.BYTE $30,$F8,$42,  0
		.BYTE $30,$F7,$42,  8
		.BYTE $30,  2,$42,$10
		.BYTE $30,  2,  2,$18
		.BYTE $30,$F7,  2,$20
		.BYTE $30,$F8,  2,$28
		.BYTE $38,$FC,$42,  0
		.BYTE $38,$F9,  2,  8
		.BYTE $38,$FA,$42,$10
		.BYTE $38,$FA,  2,$18
		.BYTE $38,$FB,  2,$20
		.BYTE $38,$FC,  2,$28
		.BYTE $40,$FF,$42,  0
		.BYTE $40,$FE,$42,  8
		.BYTE $40,$FD,$42,$10
		.BYTE $40,$FD,  2,$18
		.BYTE $40,$FE,  2,$20
		.BYTE $40,$FF,  2,$28
		.BYTE $48,$F8,$42,  8
		.BYTE $48,  2,$42,$10
		.BYTE $48,  2,  2,$18
		.BYTE $48,$F8,  2,$20
		.BYTE $80
_spr_scB_kei_mouth1:
		.BYTE $18,$F1,$41,$10
		.BYTE $18,$F1,  1,$18
		.BYTE $80
_spr_scB_kei_mouth0:
		.BYTE $18,$EE,$41,$10
		.BYTE $18,$EE,  1,$18
		.BYTE $80

		SECTION_END B
