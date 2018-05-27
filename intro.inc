
		SECTION_START 19

;-----------------------------------------------
; DEMO LOOP
;-----------------------------------------------

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro_handlers:
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_intro00_palette_effect
		SW_PTR	_intro01_nt0_clear
		SW_PTR	_intro02_nt1_clear
		SW_PTR	_intro03_copyright0_draw
		SW_PTR	_intro04_scroll_left_delay_40
		SW_PTR	_common_delay
		SW_PTR	_intro06_scroll_left_delay_18
		SW_PTR	_intro07_nt1_clear
		SW_PTR	_intro08_bike0_draw
		SW_PTR	_intro09_scroll_right
		SW_PTR	_intro0A_delay
		SW_PTR	_intro0B_scroll_right
		SW_PTR	_intro0C_nt1_clear
		SW_PTR	_intro0D_copyright1_draw
		SW_PTR	_scroll_right_delay40
		SW_PTR	_common_delay
		SW_PTR	_intro10_scroll_up
		SW_PTR	_common_delay
		SW_PTR	_intro1E_bike1_attr_draw
		SW_PTR	_intro12_bike1_draw_scroll_up
		SW_PTR	_intro13_delay
		SW_PTR	_intro14_bike1_scroll_down
		SW_PTR	_intro15_delay
		SW_PTR	_intro16_copyright2_draw_scroll_up
		SW_PTR	_common_delay
		SW_PTR	_scroll_right_delay18
		SW_PTR	_common_delay
		SW_PTR	_intro1A_bike2_draw
		SW_PTR	_intro1B_scroll_right_delay_80
		SW_PTR	_intro1C_delay
		SW_PTR	_intro1D_stop

;-------------S-U-B-R-O-U-T-I-N-E---------------
; palette effect on the intro0 screen
;
_intro00_palette_effect:
		LDX		_intro0_pal_pos
		LDA		_intro0_pal_delay_list,X
		INC		_intro0_pal_cnt
		CMP		_intro0_pal_cnt
		BNE		locret_98ED5
		LDX		#0
		STX		_intro0_pal_cnt
		INC		_intro0_pal_pos
		LDX		_intro0_pal_pos
		CPX		#2
		BNE		loc_98EB5
		JSR		_apu_reset						; explode sound after delay
		JSR		_snd_explosion
loc_98EB5:
		LDA		_intro0_pal_pos
		CMP		#4
		BCC		loc_98EBF
		LDX		#1								; scroll to akira screen
		STX		_scroll_x_shadow+1
loc_98EBF:
		CMP		#$14
		BCC		locret_98ED5
		JSR		_apu_reset
		JSR		_snd_akira_title_explosion
		JMP		_clear_cnt1_next_sub
locret_98ED5:
		LDA		#0
		TAY
		STA		word_0+1
		LDA		_intro0_pal_pos
		ASL
		ROL		word_0+1
		ASL
		ROL		word_0+1
		ASL
		ROL		word_0+1
		ASL
		ROL		word_0+1
		CLC
		ADC		#<[_intro0_pal_lib]
		STA		word_0
		LDA		word_0+1
		ADC		#>[_intro0_pal_lib]
		STA		word_0+1
		LDA		(word_0),Y
		STA		_pal_buf+$10
loc_98F0E:
		LDA		(word_0),Y
		STA		_pal_buf,Y
		INY
		CPY		#$10
		BCC		loc_98F0E
		RTS
_intro0_pal_delay_list:
		.BYTE $60,  8,  4,$20,  2,  4,  4,  8,  8,  8,$10,$10,$50,  8,  8,$40,$10,$10,$10,$FF
_intro0_pal_lib:
		.BYTE  $F,  0,$10, $C, $F,  0,  0,  0, $F, $F, $F, $F, $F, $F, $F, $F
		.BYTE $20, $F,$20, $F,$20,  0,  0,  0, $F, $F, $F, $F, $F, $F, $F, $F
		.BYTE $20,$10,$20,$10,$20,  0,  0,  0, $F, $F, $F, $F, $F, $F, $F, $F
		.BYTE $20,$20,$20,$20,$20,$20,$20,$20,$20,$20,$20,$20,$20,$20,$20,$20
		.BYTE  $F, $F, $F, $F, $F, $F, $F, $F, $F, $F, $F, $F, $F, $F, $F, $F
		.BYTE  $F,  0, $F, $F, $F, $F, $F, $F, $F, $F, $F, $F, $F,  0, $F, $F
		.BYTE  $F,$10, $F, $F, $F, $F, $F, $F, $F,  0, $F,  0, $F,$10, $F, $F
		.BYTE  $F,$30, $F, $F, $F, $F, $F, $F, $F,$10, $F,$10, $F,$30, $F, $F
		.BYTE  $F,$30,  9, $F, $F, $F, $F, $F, $F,$30, $F,$30, $F,$30,  9, $F
		.BYTE  $F,$30,$19, $F, $F, $F, $F, $F, $F,$30,  9,$30, $F,$30,$19, $F
		.BYTE  $F,$30,$29,  9, $F, $F, $F, $F, $F,$30,$19,$30, $F,$30,$29,  9
		.BYTE  $F,$30,$39,  9, $F, $F, $F, $F, $F,$30,$29,$30, $F,$30,$39,  9
		.BYTE  $F,$30,$39,  9, $F, $F, $F, $F, $F,$30,$39,$30, $F,$30,$39,  9
		.BYTE  $F,$30,$39,  9, $F,  0,  8, $F, $F,$30,$39,$30, $F,$30,$39,  9
		.BYTE  $F,$30,$39,  9, $F,$10,  6, $F, $F,$30,$39,$30, $F,$30,$39,  9
		.BYTE  $F,$30,$39,  9, $F,$20,$16, $F, $F,$30,$39,$30, $F,$30,$39,  9
		.BYTE  $F,$30,$29,  9, $F,$20,$16, $F, $F,$30,$29,$30, $F,$30,$29,  9
		.BYTE  $F,$10,$19,  9, $F,$20,$16, $F, $F,$10,$19,$10, $F,$10,$19,  9
		.BYTE  $F,  0,  9, $F, $F,$20,$16, $F, $F,  0,  9,  0, $F,  0,  9, $F
		.BYTE  $F, $F, $F, $F, $F,$20,$16, $F, $F, $F, $F, $F, $F, $F, $F, $F
		.BYTE  $F, $F, $F, $F, $F,$20,$16, $F, $F, $F, $F, $F, $F, $F, $F, $F

;-------------S-U-B-R-O-U-T-I-N-E---------------
; clears the screen slowly with effect of a black
; curtain falling from the top of the screen
;
_intro01_nt0_clear:
		JSR		_ppu_nt0_clear_queue			; queue clear line, once per frame
		LDA		_tmp_cnt1						; count frames
		BNE		locret_98A08					; if all 32 lines are clear
		INC		_scene_sub_cur
locret_98A08:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
; the same, but for nt1. since most of the time
; we use nt1 for draw image in bg, we couldn't
; actually see the curtain clear as well
;
_intro02_nt1_clear:
		JSR		_ppu_nt1_clear_queue			; the same as pervious
		LDA		_tmp_cnt1
		BNE		locret_98A19
		JSR		_scroll_reset					; this time reset scrolls to nt0
		INC		_scene_sub_cur
locret_98A19:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro03_copyright0_draw:
		LDA		_tmp_cnt1
		BNE		loc_98A33
		CHRPAL	$60,$61							; setup first copyright screen chr and pal
		LDA		#0
		STA		_tlm_tmp_line_dst
		LDA		#$24
		STA		_tlm_tmp_line_dst+1
loc_98A33:
		LDA		_tmp_cnt1						; copy tlm data line by line
		ASL										; this takes 32 frames to be done
		TAX
		LDA		_tlm_copyright0_map,X
		STA		word_2
		LDA		_tlm_copyright0_map+1,X
		STA		word_2+1
		JSR		_ppu_tmp_row_fill
		INC		_tmp_cnt1						; increment row counter
		LDA		#3								; set dequeue request
		STA		_nmi_ppu_tlm_draw_req
		LDA		_tmp_cnt1
		CMP		#$20
		BCC		locret_98A51
		INC		_scene_sub_cur
locret_98A51:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro04_scroll_left_delay_40:
		JSR		_scroll_x_add8					; stop, when hi scroll bit is 1,
		BEQ		locret_98A61					; so we have nt1 on the screen

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_set_delay_40_next_sub:
		LDA		#$40							; delay in 1/4 seconds unit
		STA		_tmp_cnt0
		INC		_scene_sub_cur
locret_98A61:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro06_scroll_left_delay_18:
		JSR		_scroll_x_add8					; scrolls nt1 to the left again
		CMP		#2								; until we have it scrolled completely
		BNE		locret_98A7E

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_set_delay_18_next_sub:
		LDA		#$18							; delay again
		STA		_tmp_cnt0
		INC		_scene_sub_cur
locret_98A7E:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro07_nt1_clear:
		JSR		_ppu_nt1_clear_queue			; again we have nt0 on the screen
		LDA		_tmp_cnt1						; won't see anything untill next scroll
		BNE		locret_98A98
		JSR		_scroll_set_nt1					; setup scrolls again to scroll in the opposite direction
		INC		_scene_sub_cur					; set corresponding scroll values to match overlay
locret_98A98:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro08_bike0_draw:
		LDA		_tmp_cnt1						; draw the picture of the bike #1
		BNE		loc_98AB2
		CHRPAL	$61,$62
		LDA		#$96
		JSR		_tlm_nt1_draw_mode4				; here we have queue method of drawing
		LDA		#0
		STA		_tlm_tmp_line_dst
loc_98AB2:
		INC		_tmp_cnt1
		LDA		_nmi_ppu_draw_counter			; should watch the nmi counters instead
		CMP		#$21
		BCC		locret_98ACA
		LDA		#0
		STA		_nmi_ppu_tlm_draw_req			; clear nmi request

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_clear_cnt1_next_sub:
		LDA		#0
		STA		_tmp_cnt1
		INC		_scene_sub_cur
locret_98ACA:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro09_scroll_right:
		JSR		_scroll_right_delay40
		JMP		_spr_bike0_anim_overlay_set		; once again, scroll the picture

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro0A_delay:
		JSR		_common_delay
		JMP		_spr_bike0_anim_overlay_set		; wait

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro0B_scroll_right:
		JSR		_scroll_right_delay18
		JMP		_spr_bike0_anim_overlay_set		; roll out of the screen

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_bike0_anim_overlay_set:
		SPRR	_spr_bike0_overlay4
		LDA		_frames_counter
		LSR
		AND		#3
		SPRRSW	off_9952C
		RTS
off_9952C:
		.WORD _spr_bike0_overlay0
		.WORD _spr_bike0_overlay1
		.WORD _spr_bike0_overlay2
		.WORD _spr_bike0_overlay3

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro0C_nt1_clear:
		JSR		_ppu_nt1_clear_queue
		LDA		_tmp_cnt1
		BNE		locret_98B18
		JSR		_scroll_set_nt1					; reset the scroll again
		INC		_scene_sub_cur
locret_98B18:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro0D_copyright1_draw:
		LDA		_tmp_cnt1						; prepare screen
		BNE		loc_98B32
		CHRPAL	$60,$61
		LDA		#0
		STA		_tlm_tmp_line_dst
		LDA		#$24
		STA		_tlm_tmp_line_dst+1
loc_98B32:
		LDA		_tmp_cnt1
		ASL
		TAX
		LDA		_tlm_copyright1_map,X
		STA		word_2
		LDA		_tlm_copyright1_map+1,X
		STA		word_2+1
		JSR		_ppu_tmp_row_fill
		INC		_tmp_cnt1						; increment row counter
		LDA		#3								; set dequeue request
		STA		_nmi_ppu_tlm_draw_req
		LDA		_tmp_cnt1
		CMP		#$20
		BCC		locret_98B55
		JMP		_clear_cnt1_next_sub
locret_98B55:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scroll_right_delay40:
		JSR		_scroll_x_sub8
		LDA		_scroll_x_shadow
		BNE		locret_98B67
		JMP		_set_delay_40_next_sub
locret_98B67:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro10_scroll_up:
		JSR		_scroll_y_add8
		JSR		_ppu_nt1_clear_queue			; the same time time clear it above the
		LDA		_tmp_cnt1						; visible area, nicely done!
		BNE		locret_98B9C
		LDA		#$E0
		STA		_scroll_y_shadow				; this time we prepare the scrolls
		LDA		#0								; from bottom to top
		STA		_scroll_y_shadow+1
		STA		_scroll_x_shadow
		LDA		#1
		STA		_scroll_x_shadow+1
		JMP		_set_delay_18_next_sub
locret_98B9C:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro1E_bike1_attr_draw:
		LDA		#$20
		STA		_nmi_ppu_tlm_draw_len
		LDA		#$C0
		STA		_tlm_tmp_line_dst				; custom attrs load
		LDA		#$27
		STA		_tlm_tmp_line_dst+1
		LDA		#<[byte_98D32]
		STA		word_2
		LDA		#>[byte_98D32]
		STA		word_2+1
		LDA		_tmp_cnt1
		BEQ		loc_98D08						; one chunk, then another
		CMP		#1
		BNE		loc_98D1D
		LDA		#$E0
		STA		_tlm_tmp_line_dst
		LDA		#<[byte_98D52]
		STA		word_2
		LDA		#>[byte_98D52]
		STA		word_2+1
loc_98D08:
		JSR		_ppu_tmp_row_fill
		INC		_tmp_cnt1
		LDA		#2
		STA		_nmi_ppu_tlm_draw_req			; attr dequeue
		RTS
loc_98D1D:
		CHRPAL	$62,$63							; prepare chr data
		JMP		_clear_cnt1_next_sub
byte_98D32:
		.BYTE   0,  0,  0,  0,  0,  0,  0,  0
		.BYTE   0,  0,  0,  0,$A0,$A0,  0,  0
		.BYTE   0,  0,  0,  0,$FF,$BA,  0,  0
		.BYTE   0,  0,  0,  0,  0, $A,  0,  0
byte_98D52:
		.BYTE   0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $50,  0,  0,  0,  0,  0,  0,  0
		.BYTE $55,$11,  0,  0,  0,  0,  0,  0
		.BYTE   5,  5,  0,  0,  0,  0,  0,  0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro12_bike1_draw_scroll_up:
		LDA		_tmp_cnt1						; picture while scrolling up line by line
		BNE		loc_98BBA
		LDA		#$97
		JSR		_tlm_nt1_draw_mode4				; prepare tlm queue
		LDA		#0
		STA		_tlm_tmp_line_dst
loc_98BBA:
		JSR		_scroll_y_add8
		INC		_tmp_cnt1
		LDA		_nmi_ppu_draw_counter			; check nmi counter
		CMP		#$20
		BCC		locret_98BE4
		LDA		#0
		STA		_nmi_ppu_tlm_draw_req			; stop drawing
		LDA		#0
		STA		_tmp_cnt1
		JMP		_set_delay_40_next_sub
locret_98BE4:
		JSR		_spr_bike1_anim_overlay_set		; this time we could draw this
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro13_delay:
		JSR		_common_delay
		JMP		_spr_bike1_anim_overlay_set

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro14_bike1_scroll_down:
		JSR		_scroll_y_sub8
		LDA		#0
		STA		word_0+1
		LDA		_tmp_cnt1
		ASL
		ROL		word_0+1
		ASL
		ROL		word_0+1
		ASL
		ROL		word_0+1
		ASL
		ROL		word_0+1
		ASL
		ROL		word_0+1
		STA		word_0
		LDA		#$A0
		SEC
		SBC		word_0
		STA		_tlm_tmp_line_dst
		LDA		#$27
		SBC		word_0+1
		STA		_tlm_tmp_line_dst+1
		JSR		_ppu_tmp_row_clear
		LDA		_tmp_cnt1
		CMP		#$20
		BCC		locret_98E0D
		LDA		#0
		STA		_tmp_cnt1
locret_98E0D:
		LDA		_tmp_cnt1
		BNE		locret_98C19
		LDA		#0
		STA		_scroll_y_shadow
		JMP		_set_delay_18_next_sub
locret_98C19:
		JSR		_spr_bike1_anim_overlay_set
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_bike1_anim_overlay_set:
		SPRR	_spr_bike1_anim_overlay6
		LDA		_frames_counter
		LSR
		AND		#3
		PHA
		SPRRSW	off_99564
		PLA
		SPRRSW	off_9956C
		RTS

off_99564:
		.WORD _spr_bike1_anim_overlay0
		.WORD _spr_bike1_anim_overlay1
		.WORD _spr_bike1_anim_overlay2
		.WORD _spr_bike1_anim_overlay3
off_9956C:
		.WORD _spr_bike1_anim_overlay4
		.WORD _spr_bike1_anim_overlay4
		.WORD _spr_bike1_anim_overlay5
		.WORD _spr_bike1_anim_overlay5

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro15_delay:
		JSR		_common_delay
		LDA		_tmp_cnt0
		BNE		locret_98C2E
		CHRPAL	$60,$61
locret_98C2E:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro16_copyright2_draw_scroll_up:
		JSR		_scroll_y_sub8
		LDA		#3
		STA		_nmi_ppu_tlm_draw_req
		LDA		#$1F							; the last ptrs of this table is for
		SEC										; attr, since we draw it in reverse
		SBC		_tmp_cnt1						; we should first write attrs
		ASL
		TAX
		LDA		_tlm_copyright2_map,X
		STA		word_2
		LDA		_tlm_copyright2_map+1,X
		STA		word_2+1
		JSR		_ppu_tmp_row_fill
		LDA		#0
		STA		word_0+1
		LDA		_tmp_cnt1
		ASL
		ROL		word_0+1
		ASL
		ROL		word_0+1
		ASL
		ROL		word_0+1
		ASL
		ROL		word_0+1
		ASL
		ROL		word_0+1
		STA		word_0
		LDA		#$E0
		SEC
		SBC		word_0
		STA		_tlm_tmp_line_dst
		LDA		#$27
		SBC		word_0+1
		STA		_tlm_tmp_line_dst+1
		INC		_tmp_cnt1
		LDA		_tmp_cnt1
		CMP		#$20
		BCC		locret_98E67
		LDA		#0
		STA		_tmp_cnt1
locret_98E67:
		LDA		_tmp_cnt1
		BNE		locret_98C48
		JMP		_set_delay_40_next_sub
locret_98C48:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scroll_right_delay18:
		JSR		_scroll_x_sub8
		LDA		_scroll_x_shadow
		BNE		locret_98C65
		JMP		_set_delay_18_next_sub
locret_98C65:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro1A_bike2_draw:
		LDA		_tmp_cnt1
		BNE		loc_98C8A
		CHRPAL	$63,$64
		LDA		#$98
		JSR		_tlm_nt1_draw_mode4
		LDA		#0
		STA		_tlm_tmp_line_dst
loc_98C8A:
		INC		_tmp_cnt1
		LDA		_nmi_ppu_draw_counter
		CMP		#$21
		BCC		locret_98CAE
		JSR		_scroll_set_nt1
		LDA		#0
		STA		_nmi_ppu_tlm_draw_req
		JMP		_clear_cnt1_next_sub
locret_98CAE:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro1B_scroll_right_delay_80:
		JSR		_scroll_x_sub8
		LDA		_scroll_x_shadow
		BNE		locret_98CC3
		LDA		#$80
		STA		_tmp_cnt0
		INC		_scene_sub_cur
locret_98CC3:
		JSR		_spr_bike2_anim_overlay_set
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro1C_delay:
		JSR		_common_delay
		JMP		_spr_bike2_anim_overlay_set

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_bike2_anim_overlay_set:
		SPRR	_spr_bike2_anim_overlay7
		LDA		_frames_counter
		LSR
		AND		#3
		PHA
		SPRRSW	off_995A4
		PLA
		SPRRSW	off_995AC
		RTS

off_995A4:
		.WORD _spr_bike2_anim_overlay0
		.WORD _spr_bike2_anim_overlay1
		.WORD _spr_bike2_anim_overlay2
		.WORD _spr_bike2_anim_overlay3
off_995AC:
		.WORD _spr_bike2_anim_overlay0
		.WORD _spr_bike2_anim_overlay4
		.WORD _spr_bike2_anim_overlay5
		.WORD _spr_bike2_anim_overlay6

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro1D_stop:
		LDA		#1
		STA		_main_sub_idx
		JMP		_apu_reset

;-------------S-U-B-R-O-U-T-I-N-E---------------
; delay in _tmp_cnt0 in 1/4 seconds uint
;
_common_delay:
		LDA		_frames_counter
		AND		#3
		BNE		locret_98D7C
		DEC		_tmp_cnt0
locret_98D7C:
		BNE		locret_98A6C
		INC		_scene_sub_cur
locret_98A6C:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scroll_set_nt1:
		LDA		#0
		STA		_scroll_x_shadow
		LDA		#8
		STA		_scroll_y_shadow				; adjust a little to fit into ntcs screen
		LDA		#2
		STA		_scroll_x_shadow+1
		STA		_scroll_y_shadow+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scroll_x_add8:
		LDA		_scroll_x_shadow
		CLC
		ADC		#8
		STA		_scroll_x_shadow
		LDA		_scroll_x_shadow+1
		ADC		#0
		STA		_scroll_x_shadow+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scroll_x_sub8:
		LDA		_scroll_x_shadow
		SEC
		SBC		#8
		STA		_scroll_x_shadow
		LDA		_scroll_x_shadow+1
		SBC		#0
		STA		_scroll_x_shadow+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scroll_y_add8:
		LDA		_scroll_y_shadow
		CLC
		ADC		#8
		STA		_scroll_y_shadow
		BCC		.yadd8
		INC		_scroll_y_shadow+1
.yadd8:
		LDA		_scroll_y_shadow
		CMP		#$F0
		BCC		.1
		LDA		#0
		STA		_scroll_y_shadow
		INC		_scroll_y_shadow+1
.1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scroll_y_sub8:
		LDA		_scroll_y_shadow
		SEC
		SBC		#8
		STA		_scroll_y_shadow
		LDA		_scroll_y_shadow+1
		SBC		#0
		STA		_scroll_y_shadow+1
		LDA		_scroll_y_shadow
		CMP		#$F0
		BCC		.2
		LDA		#$E8
		STA		_scroll_y_shadow
.2
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_ppu_nt0_clear_queue:
		LDA		_tmp_cnt1
		BNE		loc_98DC7
		LDA		#$20
		STA		_tlm_tmp_line_dst+1
		BNE		loc_98DC6						; no fallthrough here, sorry!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_ppu_nt1_clear_queue:
		LDA		_tmp_cnt1
		BNE		loc_98DC7
		LDA		#$24
		STA		_tlm_tmp_line_dst+1
loc_98DC6:
		LDA		#0
		STA		_tlm_tmp_line_dst
loc_98DC7:
		JSR		_ppu_tmp_row_clear
		LDA		_tmp_cnt1
		CMP		#$20
		BCC		locret_98DD6
		LDA		#0
		STA		_tmp_cnt1
locret_98DD6:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_ppu_tmp_row_fill:
		LDY		#0
loc_98E6A:
		LDA		(word_2),Y						; copy tlm data
		STA		_ppu_tmp_row_buf,Y
		INY
		CPY		#$20
		BCC		loc_98E6A
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_ppu_tmp_row_clear:
		LDA		#0
		LDY		#0								; fill with zeroes
loc_98E86:
		STA		_ppu_tmp_row_buf,Y
		INY
		CPY		#$20
		BCC		loc_98E86
		INC		_tmp_cnt1						; increment counter
		LDA		#3								; set dequeue request for tmp line
		STA		_nmi_ppu_tlm_draw_req
		RTS

#if LANGUAGE == JP_LANG
;-----------------------------------------------
_tlm_copyright0_map:
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright0_row1
		.WORD _tlm_copyright0_row2
		.WORD _tlm_copyright0_row3
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright0_row4
		.WORD _tlm_copyright0_row5
		.WORD _tlm_copyright0_row6
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright0_attr
		.WORD _tlm_copyright0_attr
_tlm_copyright1_map:
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_row0
		.WORD _tlm_copyright1_row1
		.WORD _tlm_copyright1_row2
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_row3
		.WORD _tlm_copyright1_row4
		.WORD _tlm_copyright1_row5
		.WORD _tlm_copyright1_row6
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_row7
		.WORD _tlm_copyright1_row8
		.WORD _tlm_copyright1_row8B
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_row9
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_attr0
		.WORD _tlm_copyright1_attr1
_tlm_copyright2_map:
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright2_row0
		.WORD _tlm_copyright2_row1
		.WORD _tlm_copyright2_row2
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright2_row3
		.WORD _tlm_copyright2_row4
		.WORD _tlm_copyright2_row5
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright0_attr
		.WORD _tlm_copyright0_attr
;-----------------------------------------------
#endif
#if LANGUAGE == EN_LANG
;-----------------------------------------------
_tlm_copyright0_map:
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright0_row1
		.WORD _tlm_copyright0_row2
		.WORD _tlm_copyright0_row3
		.WORD _tlm_empty_row
		.WORD _tlm_copyright0_row3A
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright0_row4
		.WORD _tlm_copyright0_row5
		.WORD _tlm_copyright0_row6
		.WORD _tlm_empty_row
		.WORD _tlm_copyright0_row6A
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright0_attr
		.WORD _tlm_copyright0_attr
_tlm_copyright1_map:
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_row0
		.WORD _tlm_copyright1_row1
		.WORD _tlm_copyright1_row2
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_row2A
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_row3
		.WORD _tlm_copyright1_row4
		.WORD _tlm_copyright1_row5
		.WORD _tlm_copyright1_row6
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_row7
		.WORD _tlm_copyright1_row8
		.WORD _tlm_copyright1_row8A
		.WORD _tlm_copyright1_row8B
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_row9
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_attr0
		.WORD _tlm_copyright1_attr1
_tlm_copyright2_map:
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright2_row0
		.WORD _tlm_copyright2_row1
		.WORD _tlm_copyright2_row2
		.WORD _tlm_empty_row
		.WORD _tlm_copyright2_row2A
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright2_row3
		.WORD _tlm_copyright2_row4
		.WORD _tlm_copyright2_row5
		.WORD _tlm_empty_row
		.WORD _tlm_copyright2_row5A
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright0_attr
		.WORD _tlm_copyright0_attr
;-----------------------------------------------
#endif
#if LANGUAGE == RU_LANG
;-----------------------------------------------
_tlm_copyright0_map:
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright0_row1
		.WORD _tlm_copyright0_row2
		.WORD _tlm_copyright0_row3
		.WORD _tlm_empty_row
		.WORD _tlm_copyright0_row3A
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright0_row4
		.WORD _tlm_copyright0_row5
		.WORD _tlm_copyright0_row6
		.WORD _tlm_empty_row
		.WORD _tlm_copyright0_row6A
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright0_attr
		.WORD _tlm_copyright0_attr
_tlm_copyright1_map:
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_row0
		.WORD _tlm_copyright1_row1
		.WORD _tlm_copyright1_row2
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_row2A
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_row3
		.WORD _tlm_copyright1_row4
		.WORD _tlm_copyright1_row5
		.WORD _tlm_copyright1_row6
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_row7
		.WORD _tlm_copyright1_row8
		.WORD _tlm_copyright1_row8A
		.WORD _tlm_copyright1_row8B
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_row9
		.WORD _tlm_empty_row
		.WORD _tlm_copyright1_attr0
		.WORD _tlm_copyright1_attr1
_tlm_copyright2_map:
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright2_row0
		.WORD _tlm_copyright2_row1
		.WORD _tlm_copyright2_row2
		.WORD _tlm_empty_row
		.WORD _tlm_copyright2_row2A
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright2_row3
		.WORD _tlm_copyright2_row4
		.WORD _tlm_copyright2_row5
		.WORD _tlm_empty_row
		.WORD _tlm_copyright2_row5A
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_empty_row
		.WORD _tlm_copyright0_attr
		.WORD _tlm_copyright0_attr
;-----------------------------------------------
#endif

_sp	EQU $00
A__	EQU $9A
B__	EQU $D5
C__	EQU $9D
D__	EQU $A7
E__	EQU $A5
F__	EQU $D6
G__	EQU $A2
H__	EQU $A3
I__	EQU $9B
J__	EQU $D9
K__	EQU $AD
L__	EQU $A1
M__	EQU $AC
N__	EQU $A0
O__	EQU $9C
P__	EQU $9F
R__	EQU $9E
S__	EQU $A4
T__	EQU $99
U__	EQU $D8
V__	EQU $A6
W__	EQU $D2
_Y_	EQU $D1
_0_	EQU $D0
_1_	EQU $A8
_2_	EQU $CF
_3_	EQU $D3
_4_	EQU $D4
_6_	EQU $D7
_7_	EQU $AB
_8_	EQU $AA
_9_	EQU $A9
_C_	EQU $98
_sl	EQU $CE
; only for russian
Ir_	EQU $DA
Pr_ EQU $DB
Cr_ EQU $DC
Jr_ EQU $DD
Sj_ EQU $DE
IJ_ EQU $DF
Dr_ EQU $E0
Ur_ EQU $E1
Zr_ EQU $E2
Gr_ EQU $E3
Lr_ EQU $E4
Mz_ EQU $E5
Br_ EQU $E6
_X_ EQU $E7
Sh_ EQU $E8

#if LANGUAGE == EN_LANG
;-----------------------------------------------
_tlm_copyright1_row8A:
		.BYTE _sp,_C_,_sp,_2_,_0_,_1_,_1_,_sp,D__,A__,N__,K__,E__,_sl,N__,_1_,A__,H__,A__,K__,_sl,P__,E__,N__,N__,_Y_,W__,I__,S__,E__,_sp;  0
_tlm_copyright2_row5A:
        .BYTE _sp,_sp,_sp,A__,K__,I__,R__,A__,_sp,P__,R__,O__,D__,U__,C__,T__,I__,O__,N__,_sp,C__,O__,M__,M__,I__,T__,T__,E__,E__;  0,  0,  0
_tlm_copyright2_row2A:
        .BYTE _sp,_sp,_sp,_sp,_sp,_sp,I__,N__,_sp,C__,O__,O__,P__,E__,R__,A__,T__,I__,O__,N__,_sp,_sp,W__,I__,T__,H__;  0,  0,  0,  0,  0,  0
_tlm_copyright0_row3A:
		.BYTE _sp,_sp,_sp,_sp,_sp,_sp,_sp,_sp,O__,R__,I__,G__,I__,N__,A__,L__,_sp,W__,O__,R__,K__,_sp,B__,_Y_;  0,  0,  0,  0,  0,  0,  0,  0
_tlm_copyright0_row6A:
		.BYTE _sp,_sp,_sp,_sp,_sp,_sp,_sp,_sp,K__,A__,T__,S__,U__,H__,I__,R__,O__,_sp,O__,O__,T__,O__,M__,O__,_sp,_sp,_sp;  0,  0,  0,  0,  0
_tlm_copyright1_row2A:
		.BYTE _sp,_sp,_sp,_sp,_sp,P__,R__,O__,J__,E__,C__,T__,_sp,P__,R__,O__,D__,U__,C__,T__,I__,O__,N__,_sp,_sp,B__,_Y_;  0,  0,  0,  0,  0
;-----------------------------------------------
#endif
#if LANGUAGE == RU_LANG
;-----------------------------------------------
_tlm_copyright1_row8A:
		.BYTE _sp,_C_,_sp,_2_,_0_,_1_,_6_,_sp,S__,C__,A__,R__,A__,B__,A__,_Y_,_sl,C__,A__,H__,_4_,E__,_3_,_sp,_sp,_sp,_sp,_sp,_sp,_sp,_sp,_sp
_tlm_copyright2_row5A:
        .BYTE _sp,_sp,_sp,_sp,A__,K__,Ir_,P__,A__,_sp,Pr_,P__,O__,Dr_,A__,K__,Sh_,H__,_sp,K__,O__,M__,Ir_,T__,E__,T__,O__,M__,_sp,_sp,_sp,_sp
_tlm_copyright2_row2A:
        .BYTE _sp,_sp,_sp,_sp,_sp,_sp,_sp,_sp,B__,_sp,C__,O__,Dr_,P__,Ur_,Zr_,E__,C__,T__,B__,E__,_sp,_sp,C__,_sp,_sp,_sp,_sp,_sp,_sp,_sp,_sp
_tlm_copyright0_row3A:
		.BYTE _sp,_sp,_sp,_sp,_sp,_sp,O__,P__,Ir_,Gr_,Ir_,H__,A__,Lr_,Mz_,H__,A__,Jr_,_sp,_sp,P__,A__,Br_,O__,T__,A__,_sp,_sp,_sp,_sp,_sp,_sp
_tlm_copyright0_row6A:
		.BYTE _sp,_sp,_sp,_sp,_sp,_sp,_sp,_sp,K__,A__,Cr_,Ur_,_X_,Ir_,P__,O__,_sp,_sp,O__,O__,T__,O__,M__,O__,_sp,_sp,_sp,_sp,_sp,_sp,_sp,_sp
_tlm_copyright1_row2A:
		.BYTE _sp,_sp,_sp,_sp,_sp,_sp,Pr_,P__,O__,Ir_,_3_,B__,O__,Dr_,C__,T__,B__,O__,_sp,Pr_,P__,O__,E__,K__,T__,A__,_sp,_sp,_sp,_sp,_sp,_sp
;-----------------------------------------------
#endif
_tlm_copyright0_row1:
		.BYTE   0,  0,  0,  0,  0,  0,  0,  0,  4,  5,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, $D, $E, $F;  0,  0,  0,  0,  0,  0,  0,  0
_tlm_copyright0_row2:
		.BYTE   0,  0,  0,  0,  0,  0,  0,  0,  7,  8,  9,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,$10,$11,$12;  0,  0,  0,  0,  0,  0,  0,  0
_tlm_copyright0_row3:
		.BYTE   0,  0,  0,  0,  0,  0,  0,  0, $A, $B, $C,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,$13,$14,$15;  0,  0,  0,  0,  0,  0,  0,  0
_tlm_copyright2_row0:
		.BYTE   0,  0,  0,  0,  0,  0,  0,  0,$38,$39,$3A,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,$41,$42,$43;  0,  0,  0,  0,  0,  0,  0,  0
_tlm_copyright2_row1:
		.BYTE   0,  0,  0,  0,  0,  0,  0,  0,$3B,$3C,$3D,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,$44,$45,$46;  0,  0,  0,  0,  0,  0,  0,  0
_tlm_copyright2_row2:
		.BYTE   0,  0,  0,  0,  0,  0,  0,  0,$3E,$3F,$40,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,$47,$48,$49,  0,  0;  0,  0,  0,  0,  0,  0
_tlm_copyright0_row4:
		.BYTE   0,  0,  0,  0,  0,  0,$16,  0,  0,  0,  0,$1D,$1E,$1F,  0,  0,  0,  0,$26,$27,$28,  0,  0,  0,$2F,$30,$31;  0,  0,  0,  0,  0
_tlm_copyright0_row5:
		.BYTE   0,  0,  0,  0,  0,$17,$18,$19,  0,  0,  0,$20,$21,$22,  0,  0,  0,  0,$29,$2A,$2B,  0,  0,  0,$32,$33,$34;  0,  0,  0,  0,  0
_tlm_copyright0_row6:
		.BYTE   0,  0,  0,  0,  0,$1A,$1B,$1C,  0,  0,  0,$23,$24,$25,  0,  0,  0,  0,$2C,$2D,$2E,  0,  0,  0,$35,$36,$37;  0,  0,  0,  0,  0
_tlm_copyright1_row0:
		.BYTE   0,  0,  0,  0,  0,$7D,$7E,$7F,  0,  0,  0,$86,$87,$88,  0,  0,  0,  0,$8F,$90,$91,  0,  0,  0, $D, $E, $F;  0,  0,  0,  0,  0
_tlm_copyright1_row1:
		.BYTE   0,  0,  0,  0,  0,$80,$81,$82,  0,  0,  0,$89,$8A,$8B,  0,  0,  0,  0,$92,$93,$94,  0,  0,  0,$10,$11,$12;  0,  0,  0,  0,  0
_tlm_copyright1_row2:
		.BYTE   0,  0,  0,  0,  0,$83,$84,$85,  0,  0,  0,$8C,$8D,$8E,  0,  0,  0,  0,$95,$96,$97,  0,  0,  0,$13,$14,$15;  0,  0,  0,  0,  0
_tlm_copyright1_row4:
		.BYTE   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,$B0,$B1,$B2,$B3,$B4,$B5,$B6,$B7,$B8,$B9;  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
_tlm_copyright1_row5:
		.BYTE   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,$BA,$BB,$BC,$BD,$BE,$BF,$C0,$C1,$C2,$C3;  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
_tlm_copyright1_row6:
		.BYTE   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,$C4,$C5,$C6,$C7,$C8,$C9,$CA,$CB,$CC,$CD;  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
_tlm_empty_row:
		.BYTE   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0;  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
_tlm_copyright1_row3:
		.BYTE   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,$AE,$AF,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0;  0
#if LANGUAGE == RU_LANG
;-----------------------------------------------
_tlm_copyright1_row7:
		.BYTE _sp,_C_,_sp,_1_,_9_,_8_,_7_,_sp,K__,O__,M__,Ir_,T__,E__,T__,_sp,M__,A__,S__,H__,R__,O__,O__,M__,_sl,A__,K__,Ir_,P__,A__,_sp;  0
_tlm_copyright1_row8:
		.BYTE _sp,_C_,_sp,_1_,_9_,_8_,_8_,_sp,K__,O__,P__,Pr_,O__,P__,A__,Cr_,Ir_,Jr_,_sp,T__,A__,Ir_,T__,O__,_sp,_sp,_sp,_sp,_sp,_sp,_sp;  0
_tlm_copyright1_row8B:
		.BYTE _sp,_C_,_sp,_2_,_0_,_1_,_6_,_sp,C__,A__,H__,_4_,E__,_3_,_sp,B__,F__,S__,_sp,G__,M__,B__,H__,_sp;  0,  0,  0,  0,  0,  0,  0,  0
_tlm_copyright1_row9:
		.BYTE _sp,_sp,_sp,_sp,_sp,_sp,_sp,_sp,B__,C__,E__,_sp,Pr_,P__,A__,B__,A__,_sp,_3_,A__,Sj_,Ir_,Sj_,E__,H__,IJ_,_sp,_sp;  0,  0,  0,  0
;-----------------------------------------------
#else
;-----------------------------------------------
_tlm_copyright1_row7:
		.BYTE _sp,_C_,_sp,_1_,_9_,_8_,_7_,_sp,M__,A__,S__,H__,R__,O__,O__,M__,_sl,A__,K__,I__,R__,A__,_sp,C__,O__,M__,M__,I__,T__,E__,E__;  0
_tlm_copyright1_row8:
		.BYTE _sp,_C_,_sp,_1_,_9_,_8_,_8_,_sp,T__,A__,I__,T__,O__,_sp,C__,O__,R__,P__,O__,R__,A__,T__,I__,O__,N__,_sp,_sp,_sp,_sp,_sp,_sp;  0
_tlm_copyright1_row8B:
		.BYTE _sp,_C_,_sp,_2_,_0_,_1_,_6_,_sp,C__,A__,H__,_4_,E__,_3_,_sp,B__,F__,S__,_sp,G__,M__,B__,H__,_sp;  0,  0,  0,  0,  0,  0,  0,  0
_tlm_copyright1_row9:
		.BYTE _sp,_sp,_sp,_sp,_sp,_sp,_sp,_sp,A__,L__,L__,_sp,R__,I__,G__,H__,T__,S__,_sp,R__,E__,S__,E__,R__,V__,E__,D__,_sp;  0,  0,  0,  0
;-----------------------------------------------
#endif
_tlm_copyright2_row3:
		.BYTE   0,  0,  0,  0,$4A,$4B,$4C,$51,$52,$53,$5A,$5B,$5C,$8F,$90,$91, $D, $E, $F,$62,$63,$64,$6B,$6C,$6D,$74,$75,$76;  0,  0,  0,  0
_tlm_copyright2_row4:
		.BYTE   0,  0,  0,  0,  0,$4D,$4E,$54,$55,$56,$5D,$5E,$5F,$92,$93,$94,$10,$11,$12,$65,$66,$67,$6E,$6F,$70,$77,$78,$79;  0,  0,  0,  0
_tlm_copyright2_row5:
		.BYTE   0,  0,  0,  0,$4F,$50,  0,$57,$58,$59,  0,$60,$61,$95,$96,$97,$13,$14,$15,$68,$69,$6A,$71,$72,$73,$7A,$7B,$7C;  0,  0,  0,  0
_tlm_copyright1_attr0:
		.BYTE   0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $55,$55,$55,$55,$55,$55,$55,$55
		.BYTE $55,$55,$55,$55,$55,$55,$55,$55
		.BYTE $55,$55,$95,$A5,$A5,$65,$55,$55
_tlm_copyright1_attr1:
		.BYTE $55,$55,$59,$5A,$5A,$56,$55,$55
		.BYTE $55,$55,$55,$55,$55,$55,$55,$55
		.BYTE $55,$55,$55,$55,$55,$55,$55,$55
		.BYTE   5,  5,  5,  5,  5,  5,  5,  5
_tlm_copyright0_attr:
		.BYTE $55,$55,$55,$55,$55,$55,$55,$55
		.BYTE $55,$55,$55,$55,$55,$55,$55,$55
		.BYTE $55,$55,$55,$55,$55,$55,$55,$55
		.BYTE $55,$55,$55,$55,$55,$55,$55,$55

_spr_bike0_overlay4:
		.BYTE $80,$D9,  3,$48
		.BYTE $80,$DA,  3,$50
		.BYTE $83,$DB,  3,$58
		.BYTE $88,$DC,  3,$48
		.BYTE $88,$DD,  3,$50
		.BYTE $8B,$DE,  3,$58
		.BYTE $90,$F5,  3,$A8
		.BYTE $90,$F6,  3,$B0
		.BYTE $99,$DF,  1,$60
		.BYTE $98,$E0,  1,$68
		.BYTE $99,$E1,  1,$70
		.BYTE $A0,$E2,  1,$68
		.BYTE $A8,$F7,  1,$80
		.BYTE $A8,$F8,  1,$88
		.BYTE $A8,$F9,  1,$90
		.BYTE $A8,$FA,  1,$98
		.BYTE $B0,$FB,  1,$80
		.BYTE $B0,$FC,  1,$88
		.BYTE $B0,$FD,  1,$90
		.BYTE $B0,$FE,  1,$98
		.BYTE $B0,$E3,  1,$50
		.BYTE $B0,$E4,  1,$58
		.BYTE $B8,$E5,  1,$50
		.BYTE $B8,$E6,  1,$58
		.BYTE $B8,$E9,  1,$70
		.BYTE $B8,$EA,  1,$78
		.BYTE $C0,$EB,  1,$70
		.BYTE $C0,$EC,  1,$78
		.BYTE $C1,$E7,  1,$45
		.BYTE $C9,$E8,  1,$45
		.BYTE $D6,$F0,  1,$60
		.BYTE $D8,$ED,  1,$48
		.BYTE $D8,$EE,  1,$50
		.BYTE $D8,$EF,  1,$58
		.BYTE $DE,$F4,  1,$60
		.BYTE $E0,$F1,  1,$48
		.BYTE $E0,$F2,  1,$50
		.BYTE $E0,$F3,  1,$58
_spr_bike0_overlay0:
		.BYTE $FF
_spr_bike0_overlay1:
		.BYTE $B8,$D0,  3,$20
		.BYTE $B8,$D1,  3,$28
		.BYTE $B8,$D2,  3,$30
		.BYTE $FF
_spr_bike0_overlay2:
		.BYTE $B8,$D3,  3,$20
		.BYTE $B8,$D4,  3,$28
		.BYTE $B8,$D5,  3,$30
		.BYTE $FF
_spr_bike0_overlay3:
		.BYTE $B8,$D6,  3,$20
		.BYTE $B8,$D7,  3,$28
		.BYTE $B8,$D8,  3,$30
		.BYTE $FF
_spr_bike1_anim_overlay6:
		.BYTE $58,$FD,  0,$50
		.BYTE $60,$FE,  0,$6A
		.BYTE $65,$FF,  0,$C0
		.BYTE $78,$F9,  0,$B8
		.BYTE $78,$FA,  0,$C0
		.BYTE $80,$FB,  0,$B8
		.BYTE $80,$FC,  0,$C0
		.BYTE $8C, $E,  0,$B8
		.BYTE $8C, $F,  0,$C0
_spr_bike1_anim_overlay0:
		.BYTE $FF
_spr_bike1_anim_overlay1:
		.BYTE $88,$EA,  1,$30
		.BYTE $88,$EB,  1,$38
		.BYTE $88,$EA,  1,$40
		.BYTE $C0,$F0,  1,$20
		.BYTE $C0,$F1,  1,$28
		.BYTE $C0,$F2,  1,$30
		.BYTE $D8,$F6,  1,$20
		.BYTE $D8,$F7,  1,$28
		.BYTE $D8,$F8,  1,$30
		.BYTE $FF
_spr_bike1_anim_overlay2:
		.BYTE $80,$EA,  1,$38
		.BYTE $80,$EB,  1,$40
		.BYTE $80,$EC,  1,$48
		.BYTE $A8,$ED,  1,$20
		.BYTE $A8,$EE,  1,$28
		.BYTE $A8,$EF,  1,$30
		.BYTE $D0,$F3,  1,$20
		.BYTE $D0,$F4,  1,$28
		.BYTE $D0,$F5,  1,$30
		.BYTE $FF
_spr_bike1_anim_overlay3:
		.BYTE $78,$EA,  1,$40
		.BYTE $78,$EB,  1,$48
		.BYTE $78,$EC,  1,$50
		.BYTE $98,$EA,  1,$28
		.BYTE $98,$EB,  1,$30
		.BYTE $98,$EC,  1,$38
		.BYTE $C8,$F0,  1,$20
		.BYTE $C8,$F1,  1,$28
		.BYTE $C8,$F2,  1,$30
		.BYTE $FF
_spr_bike1_anim_overlay4:
		.BYTE $B0,$57,  1,  8
		.BYTE $B8,$59,  1,  8
		.BYTE $C0,$57,  1,$18
		.BYTE $C8,$59,  1,$18
		.BYTE $E0,$5A,  1,$30
		.BYTE $A8,$57,  1,  0
		.BYTE $B0,$56,  1,  0
		.BYTE $B8,$58,  1,  0
		.BYTE $B8,$57,  1,$10
		.BYTE $C0,$56,  1,$10
		.BYTE $C8,$58,  1,$10
		.BYTE $E8,$5B,  1,$28
		.BYTE $FF
_spr_bike1_anim_overlay5:
		.BYTE $B0,$57,  1,  0
		.BYTE $B8,$59,  1,  0
		.BYTE $C0,$57,  1,$10
		.BYTE $C8,$59,  1,$10
		.BYTE $E8,$5A,  1,$28
		.BYTE $A8,$57,  1,  8
		.BYTE $B0,$56,  1,  8
		.BYTE $B8,$58,  1,  8
		.BYTE $B8,$57,  1,$18
		.BYTE $C0,$56,  1,$18
		.BYTE $C8,$58,  1,$18
		.BYTE $E0,$5B,  1,$30
		.BYTE $FF
_spr_bike2_anim_overlay7:
		.BYTE $80,$C7,  0,$3F
		.BYTE $88,$C9,  0,$48
		.BYTE $98,$CA,  0,$38
		.BYTE $AB,$C8,  0,$6A
		.BYTE $B0,$CB,  0,$28
		.BYTE $B8,$CC,  0,$28
		.BYTE $C0,$CD,  0,$40
_spr_bike2_anim_overlay0:
		.BYTE $FF
_spr_bike2_anim_overlay1:
		.BYTE $CE, $C,  0,$12
		.BYTE $CE,$B8,  0,$1A
		.BYTE $D6,$BE,  0,$12
		.BYTE $D6,$DB,  0,$1A
		.BYTE $FF
_spr_bike2_anim_overlay2:
		.BYTE $D0, $C,  0,$10
		.BYTE $D0,$B8,  0,$18
		.BYTE $D8,$BE,  0,$10
		.BYTE $D8,$DB,  0,$18
		.BYTE $FF
_spr_bike2_anim_overlay3:
		.BYTE $D2, $C,  0, $E
		.BYTE $D2,$B8,  0,$16
		.BYTE $DA,$BE,  0, $E
		.BYTE $DA,$DB,  0,$16
		.BYTE $FF
_spr_bike2_anim_overlay4:
		.BYTE $36, $C,  0,$AA
		.BYTE $36,$B8,  0,$B2
		.BYTE $3E,$BE,  0,$AA
		.BYTE $3E,$DB,  0,$B2
		.BYTE $FF
_spr_bike2_anim_overlay5:
		.BYTE $38, $C,  0,$A8
		.BYTE $38,$B8,  0,$B0
		.BYTE $40,$BE,  0,$A8
		.BYTE $40,$DB,  0,$B0
		.BYTE $FF
_spr_bike2_anim_overlay6:
		.BYTE $3A, $C,  0,$A6
		.BYTE $3A,$B8,  0,$AE
		.BYTE $42,$BE,  0,$A6
		.BYTE $42,$DB,  0,$AE
		.BYTE $FF

		SECTION_END 19
