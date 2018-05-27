
		SECTION_START 4

;-----------------------------------------------
; SCENE 4
;-----------------------------------------------

; no interactive events

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene4_subs:
		JSR		_s4_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_2004C
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s4_sub00_clear
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_s4_sub04_scene_draw
		SW_PTR	_s4_sub05_msg
		SW_PTR	_s4_sub06_anim_msg
		SW_PTR	_s4_sub07_msg_fade_out
		SW_PTR	_s4_sub09_kaneda_draw_nt1
		SW_PTR	_s4_sub0A_kaneda_draw_nt0
		SW_PTR	_s4_sub0B_msg
		SW_PTR	_s4_sub0C_scene_scroll
		SW_PTR	_s4_sub0D_chase_draw
		SW_PTR	_s4_sub0E_chase_msg

locret_2004C:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_sub00_clear:
		LDA		#0
		STA		_scroll_x_shadow+1
		SW_NXT	_s4_sub04_scene_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_sub04_scene_draw:
		SW_NXT	_s4_sub05_msg
		LDA		#1
		STA		_scene_spr_overlay_idx
		TLM4	7,6,7

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_sub05_msg:
		SW_NXT	_s4_sub06_anim_msg
		MSG_M
		MSG		_sc4_msg00
		MSG		_sc4_msg01
		MSG		_sc4_msg02
		MSG		_sc4_msg03
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_sub06_anim_msg:
		LDA		#5
		STA		_scene_spr_overlay_idx
		SW_NXT	_s4_sub07_msg_fade_out
		MSG_M
		MSG		_sc4_msg04
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_sub07_msg_fade_out:
		LDA		#4
		STA		_scene_spr_overlay_idx
		SW_FADE	_s4_sub09_kaneda_draw_nt1
		MSG_M
		MSG		_sc4_msg05
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_sub09_kaneda_draw_nt1:
		SW_NXT	_s4_sub0A_kaneda_draw_nt0
		LDA		#8
		JMP		_tlm_nt1_draw_mode4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_sub0A_kaneda_draw_nt0:
		SW_NXT	_s4_sub0B_msg
		LDA		#0
		STA		_scroll_x_shadow
		STA		_scroll_y_shadow
		LDA		#1
		STA		_scroll_x_shadow+1
		LDA		#2
		STA		_scroll_y_shadow+1
		STA		_scene_spr_overlay_idx
		TLM4	8,7,$50

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_sub0B_msg:
		JSR		_snd_kanedas_bike_runaway
		LDA		#$10
		STA		_tmp_cnt0
		SW_NXT	_s4_sub0C_scene_scroll
		MSG_1	_sc4_msg06

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_sub0C_scene_scroll:
		LDA		#0
		STA		_scene_spr_overlay_idx			; avoid the sprite tearing
		INC		_tmp_cnt0
		LDA		_tmp_cnt0
		LSR
		LSR										; scroll with acceleration, much better here
		CLC										; since bike just start moving
		ADC		_scroll_x_shadow
		STA		_scroll_x_shadow
		LDA		_scroll_x_shadow+1
		ADC		#0
		STA		_scroll_x_shadow+1
		CMP		#2
		BCC		loc_2014A
		SW_FADE	_s4_sub0D_chase_draw
		RTS
loc_2014A:
		JMP		_s4_spr_overlay2				; call overlay here directly after adjusting Y

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_sub0D_chase_draw:
		SW_NXT	_s4_sub0E_chase_msg
		LDA		#3
		STA		_scene_spr_overlay_idx
		LDA		#0
		STA		_scroll_x_shadow				; reset scrolls needed since we changed
		STA		_scroll_x_shadow+1				; scroll behaviour earlier
		TLM5	$32,$35,$58

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_sub0E_chase_msg:
		JSR		_apu_reset
		JSR		_snd_bikes_ready_to_go			; queue next scene switch
		SW_FADE	_next_scene						; after fade out the screen
		MSG_M
		MSG		_sc4_msg07
		MSG		_sc4_msg08
		MSG_WAIT								; after the messages are displayed
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s4_spr_overlay1
		SW_PTR	_s4_spr_overlay2
		SW_PTR	_s4_spr_overlay3
		SW_PTR	_s4_spr_overlay4
		SW_PTR	_s4_spr_overlay5

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_spr_overlay1:
		JSR		_do_scene_anim2_pat0101			; default anim idx in all functions if anim is disabled
		LDA		_scene_anim_idx+2				; is 1, so we need here an extra dummy word, while there
		SPR0SW	off_2021C,$58,$68				; is no def sprite for mouths with idx 1
		JSR		_do_scene_anim1_pat0101
		LDA		_scene_anim_idx+1
		SPR0SW	off_2023F,$5B,$40
		JSR		_do_scene_anim0_pat0101			; as well as other dummy word is needed, when using patterns 1212
		LDA		_scene_anim_idx					; we can rearrange words and remove extra dummy words at all
		SPR0SW	off_201F9,$50,$C8
		SPR0	_spr_sc4_kai_head_forth,$50,$C8

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_spr_overlay1_A:
		SPR0J	_spr_s4_kai_body0,$50,$C8
off_2021C:
		.WORD _spr_s4_yamagata_mouth_open
		.WORD _spr_dummy
off_2023F:
		.WORD _spr_s4_groupie_mouth_open
		.WORD _spr_dummy
off_201F9:
		.WORD _spr_s4_kai_mouth1
		.WORD _spr_s4_kai_mouth2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_spr_overlay2:
		LDA		_frames_counter
		LSR
		LSR
		LSR
		AND		#1
		SPRRSW	off_20282						; let's combine paired sprites
		SPRR	_spr_s4_tetsuo_with_girl5		; for less sprite calls
		RTS
off_20282:
		.WORD _spr_s4_tetsuo_with_girl1			; these two may be showed all at once
		.WORD _spr_s4_tetsuo_with_girl2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_spr_overlay3:
		SPR0	_spr_s4_yamagata_left_soulder,$40,$48
		SPR0	_spr_s4_yamagata_right_soulder,$30,$58
		SPR0J	_spr_s4_kai_tie,$30,$B8

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_spr_overlay4:
		SPR0	_spr_s4_kai_body1,$50,$C8
		JMP		_s4_spr_overlay4_A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_spr_overlay5:
		JSR		_s4_spr_overlay1_A

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s4_spr_overlay4_A:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0SW	off_2034F,$50,$C8
		SPR0J	_spr_sc4_kai_head_left,$50,$C8
off_2034F:
		.WORD _spr_sc4_kai_mouth_left_open
		.WORD _spr_sc4_kai_mouth_left_shut

_spr_sc4_kai_head_forth:
		.BYTE   0,$99,  1,  8
		.BYTE   0,$9A,  1,$10
		.BYTE   0,$9B,  1,$18
		.BYTE   8,$9C,  3,  8
		.BYTE   8,$9D,  3,$10
		.BYTE   8,$9E,  1,$18
		.BYTE $80
_spr_s4_kai_mouth2:
		.BYTE $10,$C6,  1,  8
		.BYTE $10,$E7,  1,$10
		.BYTE $80
_spr_s4_kai_mouth1:
		.BYTE $10,$A0,  1,  8
		.BYTE $10,$A1,  1,$10
		.BYTE $80
_spr_sc4_kai_head_left:
		.BYTE   0,$AF,  1,  8
		.BYTE   0,$B0,  1,$10
		.BYTE   0,$B1,  1,$18
		.BYTE   8,$B2,  3,  8
		.BYTE   8,$B3,  1,$10
		.BYTE   8,$B4,  1,$18
		.BYTE $10,$B8,  1,$10
		.BYTE $10,$B9,  1,$18
		.BYTE $80
_spr_sc4_kai_mouth_left_shut:
		.BYTE $10,$B7,  1,  8
		.BYTE $80
_spr_sc4_kai_mouth_left_open:
		.BYTE $10,$E8,  1,  8					; unused kai mouth animation tile
		.BYTE $80
_spr_s4_kai_body0:
		.BYTE $10,$9F,  2,  0
		.BYTE $10,$A2,  2,$18
		.BYTE $18,$A3,  2,  0
		.BYTE $18,$A4,  2,  8
		.BYTE $18,$A5,  2,$10
		.BYTE $18,$A6,  2,$18
		.BYTE $20,$A7,  2,  0
		.BYTE $20,$A8,  2,  8
		.BYTE $20,$A9,  2,$10
		.BYTE $20,$AA,  2,$18
		.BYTE $28,$AB,  2,  0
		.BYTE $28,$AC,  2,  8
		.BYTE $28,$AD,  2,$10
		.BYTE $28,$AE,  2,$18
		.BYTE $80
_spr_s4_kai_body1:
		.BYTE $10,$B5,  2,$F8
		.BYTE $10,$B6,  2,  0
		.BYTE $18,$BA,  2,$E0
		.BYTE $18,$BB,  2,$E8
		.BYTE $18,$BC,  2,$F0
		.BYTE $18,$BD,  2,$F8
		.BYTE $18,$BE,  2,  0
		.BYTE $18,$A4,  2,  8
		.BYTE $18,$A5,  2,$10
		.BYTE $18,$A6,  2,$18
		.BYTE $20,$BF,  2,  0
		.BYTE $20,$C0,  2,  8
		.BYTE $20,$C0,$42,$10
		.BYTE $20,$C1,  2,$18
		.BYTE $28,$C2,  2,  0
		.BYTE $28,$C3,  2,  8
		.BYTE $28,$C4,  2,$10
		.BYTE $28,$C5,  2,$18
		.BYTE $80
_spr_s4_yamagata_mouth_open:
		.BYTE $F8,$D9,  2,  0	; fixed position of yamagata's mouth
		.BYTE $80
_spr_s4_groupie_mouth_open:
		.BYTE   0,$D8,  2,  0
		.BYTE $80
_spr_s4_yamagata_left_soulder:
		.BYTE   0,$DA,  1,  0
		.BYTE   8,$DB,  1,  0
		.BYTE $80
_spr_s4_yamagata_right_soulder:
		.BYTE   1,$FF,  1,  7
		.BYTE   8,$DC,  1,  0
		.BYTE   8,$DF,  1,  8
		.BYTE $10,$DD,  1,  0
		.BYTE $10,$DE,  1,  8
		.BYTE $10,$E0,  1,$10
		.BYTE $10,$E1,  1,$18
		.BYTE $18,$E2,  1,$10
		.BYTE $18,$E3,  1,$18
		.BYTE $80
_spr_s4_kai_tie:
		.BYTE   0,$E4,  1,  0
		.BYTE   8,$E5,  1,  0
		.BYTE $10,$E6,  1,  0
		.BYTE $80
_spr_s4_tetsuo_with_girl1:
		.BYTE $30,$80,  1,$80
		.BYTE $38,$D7,  1,$80
		.BYTE $38,$82,  1,$88
		.BYTE $38,$83,  1,$90
		.BYTE $38,$84,  1,$98
		.BYTE $38,$85,  1,$A0
		.BYTE $38,$86,  1,$A8
		.BYTE $40,$87,  1,$80
		.BYTE $40,$88,  1,$88
		.BYTE $40,$89,  1,$90
		.BYTE $40,$8A,  1,$98
		.BYTE $40,$8B,  1,$A0
		.BYTE $40,$8C,  1,$A8
		.BYTE $48,$8D,  1,$A0
		.BYTE $48,$8E,  1,$A8
		.BYTE $68,$CE,  1,$E0
		.BYTE $68,$CF,  1,$F0
		.BYTE $FF
_spr_s4_tetsuo_with_girl2:
		.BYTE $30,$80,  1,$80
		.BYTE $38,$D7,  1,$80
		.BYTE $38,$82,  1,$88
		.BYTE $38,$C7,  1,$90
		.BYTE $38,$C8,  1,$98
		.BYTE $38,$C9,  1,$A0
		.BYTE $38,$CA,  1,$A8
		.BYTE $40,$87,  1,$80
		.BYTE $40,$88,  1,$88
		.BYTE $40,$89,  1,$90
		.BYTE $40,$8A,  1,$98
		.BYTE $40,$8B,  1,$A0
		.BYTE $40,$CB,  1,$A8
		.BYTE $48,$CC,  1,$A0
		.BYTE $48,$CD,  1,$A8
		.BYTE $68,$D2,  1,$E0
		.BYTE $68,$D3,  1,$E8
		.BYTE $68,$D4,  1,$F8
		.BYTE $FF
_spr_s4_tetsuo_with_girl5:
		.BYTE $70,$8F,  1,$1C
		.BYTE $70,$8F,$41,$24
		.BYTE $78,$90,  1,$1C
		.BYTE $78,$90,$41,$24
		.BYTE $70,$91,  1,$54
		.BYTE $70,$92,  1,$5C
		.BYTE $70,$93,  1,$64
		.BYTE $70,$94,  1,$6C
		.BYTE $78,$95,  1,$54
		.BYTE $78,$96,  1,$5C
		.BYTE $78,$97,  1,$64
		.BYTE $78,$98,  1,$6C
		.BYTE $FF

		SECTION_END 4
