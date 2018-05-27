
		SECTION_START 3

;-----------------------------------------------
; SCENE 3 (OUTSIDE OF DOME)
;-----------------------------------------------

; no interactive events

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene3_subs:
		JSR		_s3_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_972B
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s3_sub00_clear
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_s3_sub04_dome_draw
		SW_PTR	_s3_sub05_dome_msgs
		SW_PTR	_s3_sub06_dome_girl_walk
		SW_PTR	_s3_sub07_dome_girl_gone
		SW_PTR	_s3_sub08_dome_explode
		SW_PTR	_s3_sub09_dome_final_msg

locret_972B:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s3_sub00_clear:
		LDA		#0
		STA		_scroll_x_shadow+1
		SW_NXT	_s3_sub04_dome_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s3_sub04_dome_draw:
		LDA		#$40
		STA		_tmp_y_pos
		LDA		#$80
		STA		_tmp_x_pos
		LDA		#1
		STA		_scene_spr_overlay_idx
		SW_NXT	_s3_sub05_dome_msgs
		TLM4	$10,$E,$13

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s3_sub05_dome_msgs:
		SW_NXT	_s3_sub06_dome_girl_walk
		MSG_M
		MSG		_sc3_msg00
		MSG		_sc3_msg01
		MSG		_sc3_msg02
		MSG		_sc3_msg03
		MSG		_sc3_msg04
		MSG		_sc3_msg05
		MSG		_sc3_msg06
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s3_sub06_dome_girl_walk:
		LDA		#2
		STA		_scene_spr_overlay_idx
		LDA		_frames_counter
		LSR
		LSR
		LSR
		AND		#3
		TAX
		LDA		byte_97AB,X
		STA		_scene_anim_idx+1
		LDA		_tmp_x_pos
		CLC
		ADC		#1
		STA		_tmp_x_pos
		CMP		#$F0
		BCC		locret_97AA
		SW_NXT	_s3_sub07_dome_girl_gone
locret_97AA:
		RTS
byte_97AB:
		.BYTE   0,  1,  0,  2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s3_sub07_dome_girl_gone:
		LDA		#3
		STA		_scene_spr_overlay_idx
		SW_NXT	_s3_sub08_dome_explode
		MSG_M
		MSG		_sc3_msg07
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s3_sub08_dome_explode:
		JSR		_snd_grenade_explosion
		LDA		#4
		STA		_scene_spr_overlay_idx
		LDA		#2
		STA		_scene_anim_idx+3				; originally this spr visible only for 1 frame
		SW_NXT	_s3_sub09_dome_final_msg
		LDA		#5								; added some delay to make it more cinematic
		JMP		_delay

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s3_sub09_dome_final_msg:
		LDA		#1
		STA		_scene_anim_idx+2
		STA		_scene_anim_idx+3
		SW_FADE	_next_scene
		MSG_M
		MSG		_sc3_msg09
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s3_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s3_spr_overlay1
		SW_PTR	_s3_spr_overlay2
		SW_PTR	_s3_spr_overlay3
		SW_PTR	_s3_spr_overlay4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s3_spr_overlay1:
		JSR		_s3_spr_overlay3
		SPR0J	_spr_s3_girl_stand,$40,$80		; here is no animation, converted to static sprite

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s3_spr_overlay2:
		JSR		_s3_spr_overlay3
		LDA		_tmp_y_pos
		STA		word_2
		LDA		_tmp_x_pos
		STA		word_2+1
		SPR0EX	_spr_s3_girl_walk_head
		LDA		_scene_anim_idx+1
		SPR0SWEX	off_98B0
		RTS
off_98B0:
		.WORD _spr_s3_girl_walk_body0
		.WORD _spr_s3_girl_walk_body1
		.WORD _spr_s3_girl_walk_body2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s3_spr_overlay4:
		JSR		_s3_spr_overlay3_A
		LDA		_scene_anim_idx+3
		SPR0JSW	off_98D0,$30,$88
off_98D0:
		.WORD _spr_dummy						; no explosion (default)
		.WORD _spr_s3_explosion1				; this spr visible all the time
		.WORD _spr_s3_explosion2				; this visible only for 1 frame, so you may say invisible lol

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s3_spr_overlay3:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0SW	off_9874,$40,$48

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s3_spr_overlay3_A:
		LDA		_scene_anim_idx+2
		SPR0JSW	off_987A,$40,$48
off_9874:
		.WORD _spr_s3_kaneda_mouth0
		.WORD _spr_s3_kaneda_mouth1
off_987A:
		.WORD _spr_s3_kaneda_head_forth
		.WORD _spr_s3_kaneda_head_back

_spr_s3_kaneda_head_forth:
		.BYTE   0,$80,  1, $D
		.BYTE   0,$80,$41,$15
		.BYTE   8,$83,  1, $D
		.BYTE   8,$84,  1,$15
		.BYTE $10,$85,  1, $D
		.BYTE $18,$FF,  2,  0
		.BYTE $18,$87,  1,$11
		.BYTE $36,$8D,  1,  8
		.BYTE $37,$8E,  1,$20
		.BYTE $80
_spr_s3_kaneda_head_back:
		.BYTE   0,$80,  1, $D
		.BYTE   0,$80,$41,$15
		.BYTE   8,$88,  1, $D
		.BYTE   8,$89,  1,$15
		.BYTE $10,$8A,  1, $D
		.BYTE $10,$8B,  1,$15
		.BYTE $18,$FF,  2,  0
		.BYTE $18,$8C,  1,$11
		.BYTE $36,$8D,  1,  8
		.BYTE $37,$8E,  1,$20
		.BYTE $80
_spr_s3_kaneda_mouth1:
		.BYTE $10,$86,  1,$15
		.BYTE $80
_spr_s3_kaneda_mouth0:
		.BYTE $10,$FE,  1,$15
		.BYTE $80
_spr_s3_girl_stand:
		.BYTE   0,$8F,  1,  8
		.BYTE   0,$90,  1,$10
		.BYTE   8,$91,  1,  8
		.BYTE   8,$92,  1,$10
		.BYTE $10,$93,  1,  8
		.BYTE $10,$94,  1,$10
		.BYTE $18,$95,  1,  0
		.BYTE $18,$96,  1,  8
		.BYTE $18,$96,$41,$10
		.BYTE $18,$95,$41,$18
		.BYTE $20,$97,  1,  0
		.BYTE $20,$98,  1,  8
		.BYTE $20,$98,$41,$10
		.BYTE $20,$97,$41,$18
		.BYTE $28,$99,  1,  0
		.BYTE $28,$9A,  1,  8
		.BYTE $28,$9A,$41,$10
		.BYTE $28,$99,$41,$18
		.BYTE $30,$9B,  1,  0
		.BYTE $30,$9C,  1,  8
		.BYTE $30,$9C,$41,$10
		.BYTE $30,$9B,$41,$18
		.BYTE $38,$9D,  1,  0
		.BYTE $38,$9E,  1,  8
		.BYTE $38,$9E,$41,$10
		.BYTE $38,$9D,$41,$18
		.BYTE $80
_spr_s3_girl_walk_head:
		.BYTE   0,$9F,  1,  3
		.BYTE   0,$A0,  1, $B
		.BYTE   8,$A1,  1,  3
		.BYTE   8,$A2,  1, $B
		.BYTE   8,$A3,  1,$13
		.BYTE $10,$A4,  1,  3
		.BYTE $10,$A5,  1, $B
		.BYTE $80
_spr_s3_girl_walk_body2:
		.BYTE $20,$C4,  1,  4					; this patch wrongly placed 4 pixels left
		.BYTE $20,$C5,  1, $C					; so the sprite looks "teared" during
		.BYTE $28,$C6,  1,  4					; animation
		.BYTE $28,$C7,  1, $C					; also it should be used above body0 sprite
		.BYTE $30,$C8,  1,  4					; and originally has its full copy at
		.BYTE $30,$C9,  1, $C					; the end
		.BYTE $38,$CA,  1,  0					;
		.BYTE $38,$CB,  1,  8					; we fix this patch and reuse the single copy
		.BYTE $38,$CC,  1,$10					; of body0 for optimization, so fallthrough is here

; !FALLTHROUGH!

_spr_s3_girl_walk_body0:
		.BYTE $18,$A6,  1,  0
		.BYTE $18,$A7,  1,  8
		.BYTE $18,$A8,  1,$10
		.BYTE $20,$A9,  1,  0
		.BYTE $20,$AA,  1,  8
		.BYTE $20,$AB,  1,$10
		.BYTE $28,$AC,  1,  0
		.BYTE $28,$AD,  1,  8
		.BYTE $28,$AE,  1,$10
		.BYTE $30,$AF,  1,  0
		.BYTE $30,$B0,  1,  8
		.BYTE $30,$B1,  1,$10
		.BYTE $38,$B2,  1,  0
		.BYTE $38,$B3,  1,  8
		.BYTE $38,$B4,  1,$10
		.BYTE $80
_spr_s3_girl_walk_body1:
		.BYTE $18,$A6,  1,  0
		.BYTE $18,$A7,  1,  8
		.BYTE $18,$A8,  1,$10
		.BYTE $20,$B5,  1,  0
		.BYTE $20,$B6,  1,  8
		.BYTE $20,$B7,  1,$10
		.BYTE $28,$B8,  1,$F8
		.BYTE $28,$B9,  1,  0
		.BYTE $28,$BA,  1,  8
		.BYTE $28,$BB,  1,$10
		.BYTE $30,$BC,  1,$F8
		.BYTE $30,$BD,  1,  0
		.BYTE $30,$BE,  1,  8
		.BYTE $30,$BF,  1,$10
		.BYTE $38,$C0,  1,$F8
		.BYTE $38,$C1,  1,  0
		.BYTE $38,$C2,  1,  8
		.BYTE $38,$C3,  1,$10
		.BYTE $80
_spr_s3_explosion1:
		.BYTE   0,$D2,  1,$10
		.BYTE   8,$D3,  1,  0
		.BYTE   8,$D4,  1,  8
		.BYTE   8,$D5,  1,$10
		.BYTE   8,$D6,  1,$18
		.BYTE   8,$D7,  1,$20
		.BYTE $10,$D8,  1,  8
		.BYTE $10,$D9,  1,$10
		.BYTE $10,$DA,  1,$18
		.BYTE $10,$DB,  1,$20
		.BYTE $18,$DC,  1,$20
		.BYTE $80
_spr_s3_explosion2:
		.BYTE   8,$CD,  1,  8
		.BYTE   8,$CE,  1,$10
		.BYTE $10,$CF,  1,  8
		.BYTE $10,$D0,  1,$10
		.BYTE $10,$D1,  1,$18
		.BYTE $80

		SECTION_END 3
