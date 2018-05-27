
		SECTION_START 14

;-----------------------------------------------
; SCENE 14
;-----------------------------------------------

; original interactive script:
; BRANCH A (entry from SCENE 13 only) {
; 	1. inquire->kai->bike
; 	2. peek->laser
; 	3. inquire->kai->bike
; 	4. ponder
; 	5. peek->kei (jump SCENE 15, BRANCH A)
; }

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene14_subs:
		JSR		_s14_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_984EB
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s14_sub00_clear
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_generic_menu_input
		SW_PTR	_s14_menu_handlers
		SW_PTR	_s14_sub05_rest_place_draw
		SW_PTR	_s14_sub06_rest_place_msg
		SW_PTR	_s14_sub02_rest_place_menu_loop
		SW_PTR	_s14_sub0A_inquire_kai_about_bike_msg
		SW_PTR	_s14_sub08_kaneda_bike_draw
		SW_PTR	_s14_sub09_kaneda_bike_msg

locret_984EB:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_sub00_clear:
		SW_NXT	_s14_sub05_rest_place_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_sub05_rest_place_draw:
		SW_NXT	_s14_sub06_rest_place_msg
		LDA		#1
		STA		_scene_spr_overlay_idx
		TLM4	$3F,$41,$6A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_sub06_rest_place_msg:
		JSR		_snd_rest_place_ambient
		SW_NXT	_s14_sub02_rest_place_menu_loop
		MSG_1	_sc14_msg00

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_sub02_rest_place_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_9852A
		SW_RET	_s14_sub02_rest_place_menu_loop
		LDA		#0
		JSR		_s14_menus_init
		JMP		_menu_draw_request
locret_9852A:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_sub08_kaneda_bike_draw:
		SW_NXT	_s14_sub09_kaneda_bike_msg
		LDA		#2
		STA		_scene_spr_overlay_idx
		TLM4	$38,$3A,$5D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_sub09_kaneda_bike_msg:
		JSR		_snd_bike_ride
		SW_FADE	_next_scene
		MSG_M
		MSG		_sc14_msg10
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_sub0A_inquire_kai_about_bike_msg:
		JSR		_snd_kai_bike_explode
		SW_NXT	_s14_sub02_rest_place_menu_loop
		MSG_M
		MSG		_sc14_msg0B
		MSG		_sc14_msg12
		MSG		_sc14_msg0C
		MSG		_sc14_msg13
		MSG		_sc14_msg0D
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menus_init:
		STA		_scene_menu_idx
		SW_NXT	_generic_menu_input
		LDA		_scene_menu_idx
		SWITCH
		SW_PTR	_scene_menu_init_default4
		SW_PTR	_scene_menu_init_default2
		SW_PTR	_scene_menu_init_default3
		SW_PTR	_scene_menu_init_default3
		SW_PTR	_scene_menu_init_default3

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menu_handlers:
		JSR		_menu_switch
		.WORD _s14_menu0
		.WORD _s14_menu1
		.WORD _s14_menu2
		.WORD _s14_menu3
		.WORD _s14_menu4
_s14_menu0:
		.WORD _s14_menu0_stare
		.WORD _s14_menu0_ponder
		.WORD _s14_menu0_inquire
		.WORD _s14_menu0_peek
_s14_menu1:
		.WORD _s14_menu1_kei
		.WORD _s14_menu1_kai
_s14_menu2:
		.WORD _s14_menu2_about_tetsuo
		.WORD _s14_menu2_stadium
		.WORD _s14_menu2_about_bike
_s14_menu3:
		.WORD _s14_menu3_about_tetsuo
		.WORD _s14_menu3_stadium
		.WORD _s14_menu3_about_bike
_s14_menu4:
		.WORD _s14_menu4_kei
		.WORD _s14_menu4_kai
		.WORD _s14_menu4_laser

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menu0_stare:
		SW_NXT	_s14_sub02_rest_place_menu_loop
		MSG_1	_sc14_msg01

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menu0_ponder:
		SW_NXT	_s14_sub02_rest_place_menu_loop
		LDA		_scene_flags
		ORA		#8
		STA		_scene_flags
		MSG_1	_sc14_msg0E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menu0_inquire:
		SW_RET	_s14_sub02_rest_place_menu_loop
		LDA		#1
		JSR		_s14_menus_init
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menu0_peek:
		SW_RET	_s14_sub02_rest_place_menu_loop
		LDA		#4
		JSR		_s14_menus_init
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menu1_kei:
		SW_RET	_s14_sub02_rest_place_menu_loop
		LDA		#2
		JSR		_s14_menus_init
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menu1_kai:
		SW_RET	_s14_sub02_rest_place_menu_loop
		LDA		#3
		JSR		_s14_menus_init
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menu2_about_tetsuo:
		SW_NXT	_s14_sub02_rest_place_menu_loop
		MSG_1	_sc14_msg05

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menu2_stadium:
		SW_NXT	_s14_sub02_rest_place_menu_loop
		MSG_M
		MSG		_sc14_msg03
		MSG		_sc14_msg04
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menu2_about_bike:
		SW_NXT	_s14_sub02_rest_place_menu_loop
		MSG_1	_sc14_msg06

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menu3_about_tetsuo:
		SW_NXT	_s14_sub02_rest_place_menu_loop
		MSG_1	_sc14_msg07

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menu3_stadium:
		SW_NXT	_s14_sub02_rest_place_menu_loop
		MSG_1	_sc14_msg08

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menu3_about_bike:
		SW_NXT	_s14_sub02_rest_place_menu_loop
		LDA		_scene_flags
		AND		#3
		CMP		#3
		BEQ		loc_986F1
		LDA		_scene_flags
		ORA		#1
		STA		_scene_flags
		MSG_1	_sc14_msg09
loc_986F1:
		LDA		_scene_flags
		AND		#4
		BNE		loc_98715
		SW_NXT	_s14_sub0A_inquire_kai_about_bike_msg
		LDA		#1
		STA		_scene_anim_idx+1				; don't know where it should be
		STA		_scene_anim_idx+2				; put on laser
		LDA		_scene_flags
		ORA		#4
		STA		_scene_flags
		MSG_M
		MSG		_sc14_msg0A
		MSG_WAIT
		MSG_EOL
loc_98715:
		MSG_1	_sc14_msg12

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menu4_kei:
		LDA		_scene_flags
		AND		#$F
		CMP		#$F
		BEQ		loc_98730
		SW_NXT	_s14_sub02_rest_place_menu_loop
		MSG_1	_sc14_msg11
loc_98730:
		SW_FADE	_s14_sub08_kaneda_bike_draw
		MSG_M
		MSG		_sc14_msg0F
		MSG		_sc14_msg14
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menu4_kai:
		SW_NXT	_s14_sub02_rest_place_menu_loop
		LDA		_scene_flags
		AND		#4
		BNE		loc_98762
;		LDA		_scene_flags					; for what?!
;		ORA		#$11
;		STA		_scene_flags
		MSG_1	_sc14_msg09
loc_98762:
		MSG_1	_sc14_msg12

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_menu4_laser:
		SW_NXT	_s14_sub02_rest_place_menu_loop
		LDA		_scene_flags
		ORA		#2
		STA		_scene_flags
		MSG_1	_sc14_msg02

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s14_spr_overlay1
		EXOFS	_s12_spr_overlay1

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s12_spr_overlay1				; 1 time here as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s14_spr_overlay1:
		SPR0	_spr_sc14_kaneda_body,$40,$B8
		LDA		_frames_counter
		LSR
		LSR
		LSR
		AND		#1
		SPR0SW	off_987CA,$70,$70
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0SW	off_987EB,$50,8
		LDA		_scene_anim_idx+1				; only 0 used
		SPR0SW	off_9880D,$40,$B8
		LDA		_scene_anim_idx+2				; used both
		SPR0JSW	off_9882B,$70,$B0
off_987CA:
		.WORD _spr_sc14_flame0
		.WORD _spr_sc14_flame1
off_987EB:
		.WORD _spr_sc14_kei_mouth0
		.WORD _spr_sc14_kei_mouth1
;		.WORD _spr_sc14_kei_eyes0				; unused at all
off_9880D:
		.WORD _spr_sc14_kaneda_head1
		.WORD _spr_sc14_kaneda_head0
off_9882B:
		.WORD _spr_dummy
		.WORD _spr_sc14_laser

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s12_spr_overlay1				; 1 time b6 as OFS

_spr_sc14_flame0:
		.BYTE   0,$C2,  1,  0
		.BYTE   0,$C3,  1,  8
		.BYTE   8,$C4,  1,  0
		.BYTE   8,$C5,  1,  8
		.BYTE $80
_spr_sc14_flame1:
		.BYTE   0,$C3,$41,  0
		.BYTE   0,$C2,$41,  8
		.BYTE   8,$C5,$41,  0
		.BYTE   8,$C4,$41,  8
		.BYTE $80
_spr_sc14_kei_mouth1:
		.BYTE   8,$E9,  2,  0
		.BYTE   8,$EA,  2,  8
		.BYTE $80
_spr_sc14_kei_mouth0:
		.BYTE   8,$EB,  2,  0
		.BYTE   8,$EC,  2,  8
		.BYTE $80
;_spr_sc14_kei_eyes0:
;		.BYTE   7,$ED,  2,  4
;		.BYTE $80
_spr_sc14_kaneda_body:
		.BYTE $10,$D6,  2, $B					; copy of whole body here
		.BYTE $10,$D7,  2,$13
		.BYTE $10,$D8,  2,$1B
		.BYTE $10,$D9,  2,$23
		.BYTE $18,$DA,  2,  6
		.BYTE $18,$DB,  2, $E
		.BYTE $18,$DC,  2,$16
		.BYTE $18,$DD,  2,$1E
		.BYTE $20,$DE,  2,$12
		.BYTE $20,$DF,  2,$1A
		.BYTE $28,$E0,  2,$10
		.BYTE $28,$E1,  2,$18
		.BYTE $30,$E2,  2,$10
		.BYTE $30,$E3,  2,$18
		.BYTE $38,$E4,  2,$10
		.BYTE $80
_spr_sc14_kaneda_head0:
		.BYTE   0,$E5,  3,$18
		.BYTE   0,$E6,  3,$20
		.BYTE   8,$E7,  3,$18
		.BYTE   8,$E8,  3,$20
		.BYTE $80
_spr_sc14_kaneda_head1:
		.BYTE   0,$D1,  2,$18
		.BYTE   0,$D2,  2,$20
		.BYTE   8,$D3,  2,$11
		.BYTE   8,$D4,  2,$19
		.BYTE   8,$D5,  2,$21
		.BYTE $80
_spr_sc14_laser:
		.BYTE   0,$C6,  2,  0
		.BYTE   0,$C7,  2,  8
		.BYTE   0,$C8,  2,$10
		.BYTE   8,$C9,  2,  0
		.BYTE   8,$CA,  2,  8
		.BYTE   8,$CB,  2,$10
		.BYTE $80

		SECTION_END 14
