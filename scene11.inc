
		SECTION_START 11

;-----------------------------------------------
; SCENE 11
;-----------------------------------------------

; original interactive script:
; 1. look
; 2. check
; 3. run to x 2 (ponder added)
; 4. run to
; 5. ponder x 2 (move added)
; OPTION A {
; 	1. move->town (jump SCENE 12, BRANCH A)
; }
; OPTION B {
; 	2. move->school (jump SCENE 12, BRANCH B)
; }

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene11_subs:
		JSR		_s11_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_68038
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s11_sub00_clear
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_generic_menu_input
		SW_PTR	_s11_menu_handlers
		SW_PTR	_s11_sub05_river_bank_draw0
		SW_PTR	_s11_sub06_river_bank_msg
		SW_PTR	_s11_sub08_kai_msg0
		SW_PTR	_s11_sub09_yamagata_crushed_draw
		SW_PTR	_s11_sub0A_yamagata_crushed_msg
		SW_PTR	_s11_sub0B_river_bank_draw1
		SW_PTR	_s11_sub0C_kai_msg1
		SW_PTR	_s11_sub0D_kaneda_cry_draw
		SW_PTR	_s11_sub0E_kaneda_cry_msg
		SW_PTR	_s11_sub0F_kaneda_crash_draw
		SW_PTR	_s11_sub10_kaneda_crash_msg
		SW_PTR	_s11_sub11_clear
		SW_PTR	_s11_sub12_kaneda_icon1_draw
		SW_PTR	_s11_sub13_kaneda_icon1_msg
		SW_PTR	_s11_sub14_sewers_draw
		SW_PTR	_s11_sub15_sewers_msg
		SW_PTR	_s11_sub02_sewers_menu0_loop
		SW_PTR	_s11_sub17_sewers_menu1_loop
		SW_PTR	_s11_sub19_kiyoko_draw
		SW_PTR	_s11_sub1A_kiyoko_msg
		SW_PTR	_s11_sub1B_tetsuo_draw
		SW_PTR	_s11_sub1C_tetsuo_msg
		SW_PTR	_s11_sub1D_kaneda_draw
		SW_PTR	_s11_sub1E_kaneda_msg
		SW_PTR	_s11_sub18_kaneda_menu_loop

locret_68038:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub00_clear:
		SW_NXT	_s11_sub05_river_bank_draw0
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub05_river_bank_draw0:
		SW_NXT	_s11_sub06_river_bank_msg

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_tlm1B_draw:
		TLM4	$6C,$60,$1B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub06_river_bank_msg:
		SW_NXT	_s11_sub08_kai_msg0
		MSG_M
		MSG		_sc11_msg00
		MSG		_sc11_msg1F
		MSG		_sc11_msg01
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub08_kai_msg0:
		SW_FADE	_s11_sub09_yamagata_crushed_draw
		LDA		#1
		STA		_scene_spr_overlay_idx
		LDA		#0
		STA		_scene_anim_idx+1				; key normal face setup
		MSG_M
		MSG		_sc11_msg95
		MSG		_sc11_msg20
		MSG		_sc11_msg02
		MSG		_sc11_msg03
		MSG		_sc11_msg26
		MSG		_sc11_msg04
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub09_yamagata_crushed_draw:
		JSR		_snd_kaneda_death_ambient
		SW_NXT	_s11_sub0A_yamagata_crushed_msg
		LDA		#0
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_tlm4E_draw:
		TLM5	$2C,$29,$4E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub0A_yamagata_crushed_msg:
		SW_FADE	_s11_sub0B_river_bank_draw1
		MSG_M
		MSG		_sc11_msg05
		MSG		_sc11_msg06
		MSG		_sc11_msg27
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub0B_river_bank_draw1:
		JSR		_apu_reset
		SW_NXT	_s11_sub0C_kai_msg1
		LDA		#1
		STA		_scene_spr_overlay_idx
		STA		_scene_anim_idx+1				; kai crying face
		JMP		_s11_tlm1B_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub0C_kai_msg1:
		SW_FADE	_s11_sub0D_kaneda_cry_draw
		MSG_M
		MSG		_sc11_msg07
		MSG		_sc11_msg08
		MSG		_sc11_msg21
		MSG		_sc11_msg09
		MSG		_sc11_msg22
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub0D_kaneda_cry_draw:
		SW_NXT	_s11_sub0E_kaneda_cry_msg
		LDA		#6
		STA		_scene_spr_overlay_idx
		TLM5	$54,$6C,$4D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub0E_kaneda_cry_msg:
		JSR		_snd_bike_ride
		SW_FADE	_s11_sub0F_kaneda_crash_draw
		MSG_M
		MSG		_sc11_15_msg96
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub0F_kaneda_crash_draw:
		SW_NXT	_s11_sub10_kaneda_crash_msg
		LDA		#0
		STA		_scene_spr_overlay_idx
		TLM5	$2B,$28,$4C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub10_kaneda_crash_msg:
		JSR		_apu_reset
		JSR		_snd_grenade_explosion
		SW_FADE	_s11_sub11_clear
		MSG_M
		MSG		_sc11_12_13_msg97
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub11_clear:
		SW_NXT	_s11_sub12_kaneda_icon1_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub12_kaneda_icon1_draw:
		SW_NXT	_s11_sub13_kaneda_icon1_msg
		LDA		#5
		STA		_scene_spr_overlay_idx
		ICON1	$3B,$3D,$61

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub13_kaneda_icon1_msg:
		SW_FADE	_s11_sub14_sewers_draw
		MSG_M
		MSG		_sc11_msg0C
		MSG		_sc11_msg23
		MSG		_sc11_msg0D
		MSG		_sc11_msg24
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub14_sewers_draw:
		SW_NXT	_s11_sub15_sewers_msg
		TLM4	$6D,$6E,$27

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub15_sewers_msg:
		SW_NXT	_s11_sub02_sewers_menu0_loop
		LDA		#$40
		STA		_tmp_y_pos						; initial position of kai's sprite
		LDA		#$60
		STA		_tmp_x_pos
		LDA		#0
		STA		_scene_anim_idx+1				; init static scene states
		LDA		#2
		STA		_scene_spr_overlay_idx
		MSG_1	_sc11_msg98


;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub02_sewers_menu0_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_6809F
		SW_RET	_s11_sub02_sewers_menu0_loop
		SW_NXT	_generic_menu_input
		LDA		#0
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default4
		JMP		_menu_draw_request
locret_6809F:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub17_sewers_menu1_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_6823D
		SW_RET	_s11_sub17_sewers_menu1_loop
		SW_NXT	_generic_menu_input
		LDA		#1
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default5
		JMP		_menu_draw_request
locret_6823D:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub19_kiyoko_draw:
		SW_NXT	_s11_sub1A_kiyoko_msg
		LDA		#3
		STA		_scene_spr_overlay_idx
		EXJMP	_sF_tlm9C_draw					; defined in system bank

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub1A_kiyoko_msg:
		JSR		_apu_reset
		JSR		_snd_kiyoko_psychodelic
		SW_FADE	_s11_sub1B_tetsuo_draw
		MSG_M
		MSG		_sc11_msg19
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub1B_tetsuo_draw:
		SW_NXT	_s11_sub1C_tetsuo_msg
		LDA		#7
		STA		_scene_spr_overlay_idx
		EXJMP	_s6_tlmA1_draw					; defined in system bank

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub1C_tetsuo_msg:
		SW_FADE	_s11_sub1D_kaneda_draw
		MSG_M
		MSG		_sc11_msg1A
		MSG		_sc11_msg28
		MSG		_sc11_msg1B
		MSG		_sc11_msg0A
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub1D_kaneda_draw:
		SW_NXT	_s11_sub1E_kaneda_msg
		LDA		#4
		STA		_scene_spr_overlay_idx
		FJMP	_s6_tlm88_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub1E_kaneda_msg:
		SW_NXT	_s11_sub18_kaneda_menu_loop
		MSG_M
		MSG		_sc11_msg1C
		MSG		_sc11_msg25
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sub18_kaneda_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_68259
		SW_RET	_s11_sub18_kaneda_menu_loop
		SW_NXT	_generic_menu_input
		LDA		#3
		STA		_scene_menu_idx
		JSR		_s11_menu_init3
		JMP		_menu_draw_request
locret_68259:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu_init3:
		LDA		_scene_flags
		AND		#$10
		BEQ		locret_68321
		JMP		_scene_menu_init_default6
locret_68321:
		JMP		_scene_menu_init_default5

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu_handlers:
		JSR		_menu_switch
		.WORD _s11_menu0
		.WORD _s11_menu1
		.WORD _s11_menu2
		.WORD _s11_menu3
_s11_menu0:
		.WORD _s11_menu0_look
		.WORD _s11_menu0_check
		.WORD _s11_menu0_inquire
		.WORD _s11_menu0_run_to
_s11_menu1:
		.WORD _s11_menu1_look
		.WORD _s11_menu1_check
		.WORD _s11_menu1_inquire
		.WORD _s11_menu1_run_to
		.WORD _s11_menu1_ponder
_s11_menu2:
		.WORD _s11_menu2_town
		.WORD _s11_menu2_school
_s11_menu3:
		.WORD _s11_menu3_run_to
		.WORD _s11_menu3_look
		.WORD _s11_menu3_check
		.WORD _s11_menu3_inquire
		.WORD _s11_menu3_ponder
		.WORD _s11_menu3_move

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu0_look:
		LDA		_scene_flags
		ORA		#1
		STA		_scene_flags
		SW_NXT	_s11_sub02_sewers_menu0_loop
		MSG_1	_sc11_msg0E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu0_check:
		LDA		_scene_flags
		ORA		#2
		STA		_scene_flags
		SW_NXT	_s11_sub02_sewers_menu0_loop
		MSG_1	_sc11_msg0F

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu0_inquire:
		SW_NXT	_s11_sub02_sewers_menu0_loop
		MSG_1	_sc11_msg10

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu0_run_to:
		SW_NXT	_s11_sub02_sewers_menu0_loop
		LDA		_scene_flags
		AND		#7
		CMP		#7
		BEQ		loc_683BC
		LDA		_scene_flags
		ORA		#4
		STA		_scene_flags
		MSG_1	_sc11_msg11
loc_683BC:
		SW_NXT	_s11_sub17_sewers_menu1_loop
		LDA		#0
		STA		_scene_spr_overlay_idx
		MSG_M
		MSG		_sc11_msg12
		MSG		_sc11_msg13
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu1_look:
		SW_NXT	_s11_sub17_sewers_menu1_loop
		MSG_1	_sc11_msg14

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu1_check:
		SW_NXT	_s11_sub17_sewers_menu1_loop
		MSG_1	_sc11_msg15

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu1_inquire:
		SW_NXT	_s11_sub17_sewers_menu1_loop
		MSG_1	_sc11_msg16

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu1_run_to:
		SW_FADE	_s11_sub19_kiyoko_draw
		MSG_M
		MSG		_sc11_msg17						; fixed order of msgs here
		MSG		_sc11_msg18						; it seems both messages are swapped here
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu1_ponder:
		SW_NXT	_s11_sub17_sewers_menu1_loop
		MSG_1	_sc11_msg0B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu2_school:
		LDA		_game_global_flags0				; BRANCH B flag
		ORA		#8
		STA		_game_global_flags0

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu2_town:
		SW_NXT	_next_scene						; no fade out previously, redraw is visible
		JMP		_fade_out_reqest

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu3_run_to:
		SW_NXT	_s11_sub18_kaneda_menu_loop
		MSG_1	_sc11_msg14

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu3_look:
		SW_NXT	_s11_sub18_kaneda_menu_loop
		MSG_1	_sc11_msg14

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu3_check:
		SW_NXT	_s11_sub18_kaneda_menu_loop
		MSG_1	_sc11_msg15

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu3_inquire:
		SW_NXT	_s11_sub18_kaneda_menu_loop
		MSG_1	_sc11_msg16

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu3_ponder:
		SW_NXT	_s11_sub18_kaneda_menu_loop
		LDA		_scene_flags
		AND		#8
		BNE		loc_6846D
		LDA		_scene_flags
		ORA		#8
		STA		_scene_flags
		MSG_1	_sc11_msg1D
loc_6846D:
		LDA		_scene_flags
		ORA		#$10
		STA		_scene_flags
		MSG_1	_sc11_msg1E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_menu3_move:
		SW_NXT	_generic_menu_input
		LDA		#2
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default2
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s11_spr_overlay1
		SW_PTR	_s11_spr_overlay2
		EXOFS	_sF_spr_overlay8				; defined in system bank
		EXOFS	_s17_spr_overlay1_A				; defined in system bank
		EXOFS	_s11_spr_overlay5				; relocated in scene 13 block, shares the same sprites
		SW_PTR	_s11_spr_overlay6
		EXOFS	_s6_spr_overlay4				; defined in system bank

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_spr_overlay1:
		SPR0	_spr_sc11_kai_body,$48,$68
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0SW	off_6851C,$48,$68
		LDA		_scene_anim_idx+1				; here we have two modes
		BNE		loc_6851B						; normal mode, normal face
		SPR0J	_spr_sc11_kai_eyes,$48,$68
loc_6851B:
		JSR		_get_anim_blink_idx				; cry mode with animated eyes
		SPR0JSW	off_68522,$48,$68
off_6851C:
		.WORD _spr_sc11_kai_mouth1
		.WORD _spr_sc11_kai_mouth0
off_68522:
		.WORD _spr_sc11_kai_eyes_cry
		.WORD _spr_sc11_kai_eyes_cry_closed		; reused

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_spr_overlay2:
		JSR		_s11_sewers_anim
;		LDA		_scene_anim_idx					; 0,1 possible, only 0 used
;		SPR0SW	off_68546,$20,$C0				; second sprite seems unfinished,
		SPR0	_spr_sc11_kid0,$20,$C0			; so let's disable it at all
		LDA		_tmp_y_pos
		STA		word_2
		LDA		_tmp_x_pos
		STA		word_2+1
		SPR1	_spr_sc11_kei_torso
		LDA		_scene_anim_idx+1
		SPR1SW	off_68579
		RTS
;off_68546:
;		.WORD _spr_sc11_kid0
;		.WORD _spr_sc11_kid1
off_68579:
		.WORD _spr_sc11_kei_walk0
		.WORD _spr_sc11_kei_walk1
		.WORD _spr_sc11_kei_walk2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_sewers_anim:
		LDA		_tmp_x_pos
		CMP		#$80
		BCS		locret_97AB
		LDA		_frames_counter
		AND		#$F
		BNE		locret_97AB
		LDA		_frames_counter
		LSR
		LSR
		LSR
		LSR
		AND		#3
		TAX
		LDA		byte_97AC,X
		STA		_scene_anim_idx+1
		LDA		_tmp_y_pos
		SEC
		SBC		#1
		STA		_tmp_y_pos
		LDA		_tmp_x_pos
		CLC
		ADC		#1
		STA		_tmp_x_pos
		CMP		#$80
		BCC		locret_97AB
		LDA		#0
		STA		_scene_anim_idx+1				; reset to default state
locret_97AB:
		RTS
byte_97AC:
		.BYTE   0,  1,  0,  2

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s11_spr_overlay5

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s11_spr_overlay6:
		JSR		_pal_blink_animate
		JSR		_get_anim_blink_idx
		SPR0JSW	off_6859D,$4B,$68
off_6859D:
		.WORD _spr_sc11_kaneda_eyes_cry0
		.WORD _spr_sc11_kaneda_eyes_cry1

_spr_sc11_kai_body:
		.BYTE   0,$AC,  1,$10
		.BYTE   0,$AD,  1,$18
		.BYTE   8,$C8,  1,  8
		.BYTE   8,$C9,  1,$10
;		.BYTE   8,$DA,  1,$18					; wrong tile! should be CA!
		.BYTE   8,$CA,  1,$18
		.BYTE   8,$CB,  1,$20
		.BYTE $10,$D8,  1,  8
		.BYTE $10,$DB,  1,$20
		.BYTE $10,$DC,  1,$28
		.BYTE $18,$BC,  1,  8
		.BYTE $18,$BF,  1,$20
		.BYTE $20,$CC,  3,  0
		.BYTE $20,$CD,  3,  8
		.BYTE $20,$CD,$43,$20
		.BYTE $20,$CC,$43,$28
		.BYTE $28,$DD,  3,  0
		.BYTE $28,$DE,  3,  8
		.BYTE $28,$DF,  3,$10
		.BYTE $28,$DF,$43,$18
		.BYTE $28,$DE,$43,$20
		.BYTE $28,$DD,$43,$28
		.BYTE $30,$AE,  3,  0
		.BYTE $30,$AF,  3,  8
		.BYTE $30,$9F,  3,$10
		.BYTE $30,$9F,$43,$18
		.BYTE $30,$AF,$43,$20
		.BYTE $30,$AE,$43,$28
		.BYTE $80
_spr_sc11_kai_mouth0:
		.BYTE $20,$CE,  1,$10
		.BYTE $20,$CE,$41,$18
		.BYTE $80
_spr_sc11_kai_mouth1:
		.BYTE $20,$CF,  1,$10
		.BYTE $20,$CF,$41,$18
		.BYTE $80
_spr_sc11_kai_eyes:
		.BYTE $10,$D9,  1,$10
		.BYTE $10,$DA,  1,$18
		.BYTE $18,$BD,  1,$10
		.BYTE $18,$BE,  1,$18
		.BYTE $80
_spr_sc11_kai_eyes_cry:
		.BYTE $10,$B8,  1,$10
		.BYTE $10,$B9,  1,$18
		.BYTE $18,$BA,  1,$10
		.BYTE $18,$BB,  1,$18
		.BYTE $80
_spr_sc11_kai_eyes_cry_closed:
		.BYTE $10,$B4,  1,$10
		.BYTE $10,$B5,  1,$18
		.BYTE $18,$B6,  1,$10
		.BYTE $18,$B7,  1,$18
		.BYTE $80
_spr_sc11_kid0:
		.BYTE   0,$ED,  1,  8
		.BYTE   8,$EF,  1,  4
		.BYTE   8,$F0,  1, $C
		.BYTE $10,$F1,  1,  8
		.BYTE $18,$F2,  1,  8
		.BYTE $80
;_spr_sc11_kid1:
;		.BYTE   0,$F3,  1,  8					; headless tile, why?
;		.BYTE   8,$F4,  1,  4
;		.BYTE   8,$F5,  1, $C
;		.BYTE $10,$F6,  1,  8
;		.BYTE $18,$F7,  1,  8
;		.BYTE $80
_spr_sc11_kei_torso:
		.BYTE   0,$DA,  2,  6
		.BYTE   8,$DB,  2,  0
		.BYTE   8,$DC,  2,  8
		.BYTE $10,$DD,  2,  0
		.BYTE $10,$DE,  2,  8
		.BYTE $80
_spr_sc11_kei_walk0:
		.BYTE $18,$DF,  2,  0
		.BYTE $18,$E0,  2,  8
		.BYTE $20,$E1,  2,  0
		.BYTE $20,$E2,  2,  8
		.BYTE $28,$E3,  2,  0
		.BYTE $28,$E4,  2,  8
		.BYTE $80
_spr_sc11_kei_walk1:
		.BYTE $18,$E5,  2,  0
		.BYTE $18,$E6,  2,  8
		.BYTE $20,$E7,  2,  8
		.BYTE $28,$E8,  2,  8
		.BYTE $80
_spr_sc11_kei_walk2:
		.BYTE $18,$E9,  2,  0
		.BYTE $18,$EA,  2,  8
		.BYTE $20,$EB,  2,  8
		.BYTE $28,$EC,  2,  8
		.BYTE $80
_spr_sc11_kaneda_eyes_cry0:
		.BYTE   0,$EB,  1,  0
		.BYTE   0,$EC,  1,  8
		.BYTE   0,$ED,  1,$10
		.BYTE   8,$EE,  1,  8
		.BYTE   8,$EF,  1,$10
		.BYTE $80
_spr_sc11_kaneda_eyes_cry1:
		.BYTE   0,$F0,  1,  0
		.BYTE   0,$F1,  1,  8
		.BYTE   0,$F2,  1,$10
		.BYTE   8,$F3,  1,  8
		.BYTE   8,$F4,  1,$10
		.BYTE $80

		SECTION_END 11
