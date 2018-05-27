
		ORG $C000

		BANK_START $EF

		INCBIN "..\copyrights.txt"

;-------------S-U-B-R-O-U-T-I-N-E---------------
; allows to have 256 indexes
;
_switch:
		STA		word_2
		LDA		#0
		STA		word_2+1
		ASL		word_2
		ROL		word_2+1
		CLC
		PLA
		ADC		word_2
		STA		word_2
		PLA
		ADC		word_2+1
		STA		word_2+1
		LDY		#1
		LDA		(word_2),Y
		STA		word_0
		INY
		LDA		(word_2),Y
		STA		word_0+1
		JMP		(word_0)

;-------------S-U-B-R-O-U-T-I-N-E---------------
_RESET:
		SEI
		CLD
		LDX		#0
		STX		_PPU_MASK
		STX		_PPU_CTRL
loc_15C00A:
		LDA		_PPU_STATUS
		BMI		loc_15C00A
		STX		_PPU_CTRL
loc_15C012:
		LDA		_PPU_STATUS
		BPL		loc_15C012
		LDX		#$FF
		TXS
		LDA		#0
		STA		_APU_DMC_FREQ
		LDA		#$40
		STA		_PAD1_REG
;-----------------------------------------------
;debug selftest code, disabled in the release
;-----------------------------------------------
;		LDY		#$D
;		LDX		#$30
;		STX		$8000
;		LDA		$8000
;loc_15C031:
;		INX
;		STX		$8000
;		CMP		$8000
;		BNE		loc_15C03D
;loc_15C03A:
;		JMP		loc_15C03A
;loc_15C03D:
;		LDA		$8000
;		DEY
;		BPL		loc_15C031
;		LDY		#$D
;		LDX		#$30
;		STX		$8001
;		LDA		byte_142AAA
;loc_15C04D:
;		INX
;		STX		$8001
;		CMP		$AAAA
;		BEQ		loc_15C03A
;		LDA		$AAAA
;		DEY
;		BPL		loc_15C04D
;		LDY		#$10
;		STY		$8003
;		LDA		#8
;		STA		_PPU_ADDR
;		LDA		#$99
;		STA		_PPU_ADDR
;		LDX		_PPU_DATA
;		LDX		_PPU_DATA
;		DEY
;loc_15C072:
;		STY		$8003
;		LDA		#8
;		STA		_PPU_ADDR
;		LDA		#$99
;		STA		_PPU_ADDR
;		LDA		_PPU_DATA
;		LDA		_PPU_DATA
;		STX		word_0
;		CMP		word_0
;		BEQ		loc_15C03A
;		TAX
;		DEY
;		BNE		loc_15C072
;-----------------------------------------------
		LDA		#<[_end_of_RAM]
		STA		word_0
		LDA		#>[_end_of_RAM]
		STA		word_0+1
		LDY		#0
loc_15CFD5:
		LDA		#0
		STA		(word_0),Y
		LDA		word_0
		ORA		word_0+1
		BEQ		_MAIN
		LDA		word_0
		SEC
		SBC		#1
		STA		word_0
		LDA		word_0+1
		SBC		#0
		STA		word_0+1
		JMP		loc_15CFD5

;-------------S-U-B-R-O-U-T-I-N-E---------------
_MAIN:
		LDA		#$10
		STA		_ppu_ctrl_shadow
		JSR		_apu_reset
		LDA		#0
		STA		$8000							; set mirror flag to VERTICAL (see notes)
		LDA		#1
		STA		_main_sub_idx

;-------------S-U-B-R-O-U-T-I-N-E---------------
_RING0:
		JSR		_randomize						; idle loop sits here most of the time
		LDA		_main_sub_idx
		BEQ		_RING0
		JSR		_nmi_off						; exit only for prepare the corresponding game mode
		JSR		_render_off
		LDA		_main_sub_idx
		ASL
		TAX
		LDA		off_15C0C3-2,X
		STA		_ring0_tmp_ptr
		LDA		off_15C0C3-1,X
		STA		_ring0_tmp_ptr+1
		JMP		(_ring0_tmp_ptr)
off_15C0C3:
		.WORD _intro_start
		.WORD _ingame_start
		.WORD _title_menu_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_return_to_ring0:								; when done, return to idle state
		LDA		#0
		STA		_main_sub_idx
		JSR		_render_on
		JSR		_nmi_on
		JMP		_RING0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro_start:
		JSR		_apu_reset
		LDA		#0
		STA		_text_typing_snd_disable
		JSR		_intro0_draw					; direct tlm draw (we have nmi and render off here)
		JSR		_scroll_reset
		LDA		#0
		STA		_scene_sub_cur
		STA		_intro0_pal_pos
		STA		_nmi_mode_idx					; nmi intro mode
		JMP		_return_to_ring0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_intro0_draw:
		CHRPAL	$67,$67
		LDA		#$E
		JSR		_tlm_get_index_by_number		; title tilemap idx 0E (chr)
		JSR		_tlm_get_ptr
		LDA		#0
		STA		_tlm_tmp_line_dst
		LDA		#$20
		STA		_tlm_tmp_line_dst+1
		LDX		#0
loc_98954:
		TXA
		PHA
		JSR		_tlm_chr_line_draw
		PLA
		TAX
		INX
		CPX		#$40
		BCC		loc_98954
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_ingame_start:
		JSR		_apu_reset
		JSR		_pal_buf_clear
		JSR		_msg_window_init
		JSR		_spr0_init
		JSR		_scroll_reset
		LDA		#$80
		STA		_msg_wnd_scroll_y_shadow
		LDA		#0
		STA		_msg_wnd_scroll_x_shadow
		STA		_cur_msg_col
		STA		_cur_msg_row
		LDA		#1
		STA		_nmi_mode_idx					; nmi ingame mode
		JMP		_return_to_ring0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_pal_buf_clear:
		LDA		#$F
		LDX		#0
loc_990D0:
		STA		_pal_buf,X
		INX
		CPX		#$20
		BCC		loc_990D0
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_msg_window_init:
		LDA		#$20
		STA		_PPU_ADDR
		LDA		#0
		STA		_PPU_ADDR
		LDA		#0
		TAX
		TAY
loc_9907A:
		STA		_PPU_DATA
		INX
		BNE		loc_9907A
		INY
		CPY		#8
		BCC		loc_9907A
		LDA		#$22
		STA		_PPU_ADDR
		LDA		#0
		STA		_PPU_ADDR
		JSR		_msg_window_draw
		LDA		#$26
		STA		_PPU_ADDR
		LDA		#0
		STA		_PPU_ADDR

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_msg_window_draw:
		LDY		#0
		JSR		_msg_wnd_frame_top
		JMP		loc_990B9
loc_990A4:
		CPY		#$D
		BNE		loc_990AE
		JSR		_msg_wnd_frame_bottom
		JMP		loc_990B9
loc_990AE:
		BCS		loc_990B6
		JSR		_msg_wnd_frame_middle
		JMP		loc_990B9
loc_990B6:
		JSR		_msg_row_buf_clear
loc_990B9:
		LDX		#0
loc_990BB:
		LDA		_ppu_tmp_row_buf,X
		STA		_PPU_DATA
		INX
		CPX		#$20
		BCC		loc_990BB
		INY
		CPY		#$10
		BCC		loc_990A4
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_msg_wnd_frame_top:
		LDA		#$3F
		STA		word_0
		LDA		#4
		STA		word_0+1
		LDA		#5
		STA		word_2
		BNE		_msg_row_buf_fill

;-------------S-U-B-R-O-U-T-I-N-E---------------
_msg_wnd_frame_middle:
		LDA		#0
		STA		word_0
		LDA		#6
		STA		word_0+1
		LDA		#$3B
		STA		word_2
		BNE		_msg_row_buf_fill

;-------------S-U-B-R-O-U-T-I-N-E---------------
_msg_wnd_frame_bottom:
		LDA		#$3C
		STA		word_0
		LDA		#$6C
		STA		word_0+1
		LDA		#$6D
		STA		word_2
		BNE		_msg_row_buf_fill

;-------------S-U-B-R-O-U-T-I-N-E---------------
_msg_row_buf_clear:
		LDA		#0
		STA		word_0
		LDA		#0
		STA		word_0+1
		LDA		#0
		STA		word_2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_msg_row_buf_fill:
		LDA		word_0
		LDX		#0
loc_99116:
		STA		_ppu_tmp_row_buf,X
		INX
		CPX		#$20
		BCC		loc_99116
		LDA		word_0+1
		STA		_ppu_tmp_row_buf
		LDA		word_2
		STA		_ppu_tmp_row_buf+$1F
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr0_init:
		LDX		#0
		STX		_PPU_OAM_ADDR
loc_15C135:
		LDA		_spr0_overflow,X
		STA		_PPU_OAM_DATA
		INX
		CPX		#4
		BCC		loc_15C135
		LDA		#1
		STA		_spr0_trigger_delay
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_title_menu_start:
		JSR		_apu_reset
		JSR		_title_menu_draw
		JSR		_scroll_reset
		LDA		#$40
		STA		_tmp_cnt0						; set timeout counter for intro delay
		LDA		#2
		STA		_nmi_mode_idx					; nmi title menu mode
		LDA		#0
		STA		_apu_test_idx					; sound test init
		LDA		#1								; force enable it here, TODO: hide me
		STA		_apu_test_enable
		JMP		_return_to_ring0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_title_menu_draw:
		CHRPAL	$70,$73
		LDA		#$A6
		JSR		_tlm_get_index_by_number
		JSR		_tlm_get_ptr
		LDA		#0
		STA		_tlm_tmp_line_dst
		LDA		#$24
		STA		_tlm_tmp_line_dst+1
		LDX		#0
loc_9897F:
		TXA
		PHA
		JSR		_tlm_chr_line_draw
		PLA
		TAX
		INX
		CPX		#$20
		BCC		loc_9897F
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_NMI:
		PHA
		TXA
		PHA
		TYA
		PHA
		LDA		_PPU_STATUS
		LDA		_nmi_busy
		BEQ		loc_15C155
		JMP		_nmi_apu_play
loc_15C155:
		LDA		#1
		STA		_nmi_busy
		LDA		#2
		STA		_PPU_OAM_DMA
		JSR		_nmi_ppu_draw
		JSR		_ppu_reload
		JSR		_mmc_reload
		JSR		_spr0_toggle
		JSR		_read_pads
		JSR		_do_frames_counter
		LDA		_nmi_mode_idx
		ASL
		TAX
		LDA		off_15C183,X
		STA		_nmi_tmp_ptr
		LDA		off_15C183+1,X
		STA		_nmi_tmp_ptr+1
		JMP		(_nmi_tmp_ptr)
off_15C183:
		.WORD _nmi_sub0_intro
		.WORD _nmi_sub1_ingame
		.WORD _nmi_sub2_title_menu

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_common:
		JSR		_spr_close
		JSR		_spr_menu_clip
		LDA		#0
		STA		_nmi_busy

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_apu_play:
		LDA		#$3C
		STA		$8001
		JSR		_apu_play
		PLA
		TAY
		PLA
		TAX
		PLA

;-------------S-U-B-R-O-U-T-I-N-E---------------
_IRQ:
		RTI

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr0_toggle:
		LDA		#<[_spr0_off]
		STA		word_0
		LDA		#>[_spr0_off]
		STA		word_0+1
		LDX		#4
		LDA		_nmi_mode_idx
		CMP		#1
		BNE		loc_15C1C5
		LDA		#<[_spr0_overflow]
		STA		word_0
		LDA		#>[_spr0_overflow]
		STA		word_0+1
		LDA		_spr0_overflow_mode_flag
		BEQ		loc_15C1C5
		LDX		#$20
loc_15C1C5:
		STX		word_2+1
		LDY		#0
loc_15C1C9:
		LDA		(word_0),Y
		STA		_spr_buf,Y
		INY
		CPY		word_2+1
		BCC		loc_15C1C9
		STY		_spr_buf_pos
		RTS
_spr0_off:
		.BYTE $FF,$81,$21,$F8
_spr0_overflow:
		.BYTE $7F,$81,$21,$F0
		.BYTE $7F,$81,$21,$F0
		.BYTE $7F,$81,$21,$F0
		.BYTE $7F,$81,$21,$F0
		.BYTE $7F,$81,$21,$F0
		.BYTE $7F,$81,$21,$F0
		.BYTE $7F,$81,$21,$F0
		.BYTE $7F,$81,$21,$F0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_sub0_intro:
		FJSR	_intro_handlers					; 1 time here as JSR
		LDA		_pads+1
		AND		#8
		BEQ		loc_15C20A						; wait for Start
		JSR		_apu_reset
		LDA		#0
		STA		_draw_state_idx
		STA		_nmi_ppu_tlm_draw_req
		LDA		#3
		STA		_main_sub_idx					; jump to title menu
loc_15C20A:
		JMP		_nmi_common

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_sub1_ingame:
		JSR		_debug_scene_skip
		JSR		_scene_handlers					; main event execution sub
		FJSR	_draw_handlers					; 1 time here as JSR
		JSR		_screen_split					; wait for sprite hit0, then setup msg area CHR banks
		JMP		_nmi_common

;-------------S-U-B-R-O-U-T-I-N-E---------------
; scene skip disabled in the final release,
; press B on Pad 2 to skip to the next scene.
;
_debug_scene_skip:
;-----------------------------------------------
;		NOP
;		NOP
;		RTS
;-----------------------------------------------
		LDA		_pads+3
		AND		#2
		BEQ		loc_15CF57
		LDA		_scene_idx
		CMP		#$18
		BEQ		locret_15CF55
		INC		_scene_idx
		BNE		loc_15CF56
loc_15CF57:
		LDA		_pads+3							; added revert scene
		AND		#4								; for convinience
		BEQ		locret_15CF55
		LDA		_scene_idx
		BEQ		locret_15CF55
		DEC		_scene_idx
loc_15CF56:
		LDA		#0
		STA		_menu_is_drawn_flag
		STA		_scene_spr_overlay_idx
		STA		_scene_sub_next
		STA		_draw_state_idx
		STA		_scene_sub_cur
		STA		_cur_msg_col
		STA		_cur_msg_row
		STA		_cur_msg_pos
		STA		_cur_msg_pos+1
		STA		_staff_screen_idx
		STA		_dictionary_str_idx
		STA		_type_fastforward
		JSR		_nmi_vars_init
		JSR		_vars_init
locret_15CF55:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene_handlers:
		LDA		_scene_idx
		SWITCH
		EXOFS	_scene0_subs
		EXOFS	_scene1_subs
		EXOFS	_scene2_subs
		EXOFS	_scene3_subs
		EXOFS	_scene4_subs
		EXOFS	_scene5_subs
		EXOFS	_scene6_subs
		EXOFS	_scene7_subs
		EXOFS	_scene8_subs
		EXOFS	_scene9_subs
		EXOFS	_sceneA_subs
		EXOFS	_sceneB_subs
		EXOFS	_sceneC_subs
		EXOFS	_sceneD_subs
		EXOFS	_sceneE_subs
		EXOFS	_sceneF_subs
		EXOFS	_scene10_subs
		EXOFS	_scene11_subs
		EXOFS	_scene12_subs
		EXOFS	_scene13_subs
		EXOFS	_scene14_subs
		EXOFS	_scene15_subs
		EXOFS	_scene16_subs
		EXOFS	_scene17_subs_game_over
		EXOFS	_scene18_subs_ending

		FJMP	_scene0_subs
		FJMP	_scene1_subs
		FJMP	_scene2_subs
		FJMP	_scene3_subs
		FJMP	_scene4_subs
		FJMP	_scene5_subs
		FJMP	_scene6_subs
		FJMP	_scene7_subs
		FJMP	_scene8_subs
		FJMP	_scene9_subs
		FJMP	_sceneA_subs
		FJMP	_sceneB_subs
		FJMP	_sceneC_subs
		FJMP	_sceneD_subs
		FJMP	_sceneE_subs
		FJMP	_sceneF_subs
		FJMP	_scene10_subs
		FJMP	_scene11_subs
		FJMP	_scene12_subs
		FJMP	_scene13_subs
		FJMP	_scene14_subs
		FJMP	_scene15_subs
		FJMP	_scene16_subs
		FJMP	_scene17_subs_game_over
		FJMP	_scene18_subs_ending

;-------------S-U-B-R-O-U-T-I-N-E---------------
_screen_split:
		LDA		_spr0_trigger_delay
		BNE		loc_15C2B1
loc_15C26C:
		LDA		_PPU_STATUS						; wait for sprite0 hit is over
		AND		#$40
		BNE		loc_15C26C
loc_15C273:
		LDA		_PPU_STATUS						; wait for sprite0 hit start again
		AND		#$40
		BEQ		loc_15C273
		LDX		#2
		STX		$8002
		LDX		#0
		STX		$A000
		INX
		STX		$A001
		INX
		STX		$A002
		INX
		STX		$A003
		LDA		_PPU_STATUS
		LDA		_ppu_ctrl_shadow
		AND		#$FC
		STA		_ppu_ctrl_shadow
		LDA		_msg_wnd_scroll_x_shadow+1
		AND		#1
		ORA		_ppu_ctrl_shadow
		STA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		LDA		_msg_wnd_scroll_x_shadow
		STA		_PPU_SCROLL
		LDA		_msg_wnd_scroll_y_shadow
		STA		_PPU_SCROLL
		RTS
loc_15C2B1:
		INC		_spr0_trigger_delay
		LDA		_spr0_trigger_delay
		CMP		#5
		BCC		locret_15C2C0
		LDA		#0
		STA		_spr0_trigger_delay
locret_15C2C0:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_sub2_title_menu:
		JSR		_title_menu_cursor_set
		JSR		_title_menu_spr_overlay
;-----------------------------------------------
		LDA		_apu_test_enable
		BEQ		.no_apu_test
		JSR		_apu_test_handler
.no_apu_test:
;-----------------------------------------------
		LDA		_pads+1
		AND		#8
		BEQ		loc_15C252
		LDA		_pass_char_pos_x				; test menu item selected
		BNE		loc_15C240
		JSR		_scene_vars_init				; start a new game selected
		LDA		#STARTING_SCENE					; init scene 0, all vars clear
		STA		_scene_idx
		JMP		loc_15C241
loc_15C240:
		LDA		#$17							; password screen scene init
		STA		_scene_idx
loc_15C241:
		LDA		#0								; beginning of script is always 0
		STA		_scene_sub_cur
		STA		_scene_sub_next
		LDA		#2
		STA		_main_sub_idx					; same ingame engine used
		JMP		_nmi_common						; over
loc_15C252:
		LDA		_apu_test_enable
		BNE		loc_15C261
		LDA		_frames_counter					; menu idle disabled if test is on
		AND		#7
		BNE		loc_15C261
		DEC		_tmp_cnt0						; decrease timeout counted before
		BNE		loc_15C261						; demo start again
		LDA		#1
		STA		_main_sub_idx					; restart intro mode
loc_15C261:
		JMP		_nmi_common

;-------------S-U-B-R-O-U-T-I-N-E---------------
_title_menu_cursor_set:
		LDA		_pads+1
		AND		#$34							; up/down/select
		BEQ		loc_15C314
		LDA		_pass_char_pos_x
		EOR		#1
		STA		_pass_char_pos_x
		LDA		#$40
		STA		_tmp_cnt0						; refresh title countdown timer
loc_15C314:
		LDX		_pass_char_pos_x
		LDA		_spt_title_pos,X
		STA		word_2
		LDA		#$58
		STA		word_2+1
		SPR0EX	_spr_title_menu
		RTS

_spt_title_pos:
		.BYTE $70,$80
_spr_title_menu:
		.BYTE   0,$BD,  0,  0,$80

;-------------S-U-B-R-O-U-T-I-N-E---------------
_title_menu_spr_overlay:
		LDA		#1
		STA		_scroll_x_shadow+1
		LDA		#2
		STA		_scroll_y_shadow+1
		SPRR	_spr_title_raw_ovl
		RTS

_spr_title_raw_ovl:
		.BYTE $10,$80,  1,$5B
		.BYTE $18,$82,  1,$50
		.BYTE $18,$83,  1,$58
		.BYTE $20,$84,  1,$40
		.BYTE $20,$85,  1,$48
		.BYTE $20,$86,  1,$50
		.BYTE $20,$87,  1,$58
		.BYTE $20,$88,  1,$60
		.BYTE $20,$89,  1,$68
		.BYTE $28,$8A,  1,$34
		.BYTE $28,$8B,  1,$3C
		.BYTE $28,$8C,  1,$44
		.BYTE $28,$8D,  1,$4C
		.BYTE $28,$8E,  1,$54
		.BYTE $28,$8F,  1,$5C
		.BYTE $28,$90,  1,$64
		.BYTE $28,$91,  1,$6C
		.BYTE $30,$92,  1,$30
		.BYTE $30,$93,  1,$38
		.BYTE $30,$94,  1,$40
		.BYTE $30,$95,  1,$48
		.BYTE $30,$96,  1,$50
		.BYTE $30,$97,  1,$58
		.BYTE $30,$98,  1,$60
		.BYTE $30,$99,  1,$68
		.BYTE $30,$BB,  2,$A8
		.BYTE $38,$9A,  1,$30
		.BYTE $38,$9B,  1,$38
		.BYTE $38,$9C,  1,$40
		.BYTE $38,$9D,  1,$48
		.BYTE $38,$9E,  1,$50
		.BYTE $38,$9F,  1,$58
		.BYTE $38,$A0,  1,$60
		.BYTE $38,$A1,  1,$6C
		.BYTE $40,$A2,  3,$30
		.BYTE $40,$A3,  3,$38
		.BYTE $50,$A4,  2,$20
		.BYTE $4C,$A5,  2,$28
		.BYTE $4C,$A6,  2,$30
		.BYTE $4B,$AD,  3,$52
		.BYTE $4A,$AE,  3,$5A
		.BYTE $47,$AF,  3,$62
		.BYTE $5C,$A7,  3,$20
		.BYTE $5C,$A8,  3,$28
		.BYTE $5C,$A9,  3,$30
		.BYTE $58,$AA,  3,$3E
		.BYTE $55,$AB,  2,$4C
		.BYTE $55,$AC,  2,$54
		.BYTE $80,$BC,  0,$78
		.BYTE $88,$B0,  0,$78
		.BYTE $88,$B1,  0,$80
		.BYTE $98,$B2,  1,$78
		.BYTE $98,$B3,  1,$80
		.BYTE $A0,$B4,  1,$78
		.BYTE $A0,$B5,  1,$80
		.BYTE $B0,$B6,  0,$58
		.BYTE $B0,$B7,  0,$60
		.BYTE $B8,$B8,  0,$58
		.BYTE $B8,$B9,  0,$60
		.BYTE $C0,$BA,  0,$58
		.BYTE $FF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_close:
		LDA		#$FF
		LDX		_spr_buf_pos
		BEQ		locret_15C348					; try to avoid overflow somehow
loc_15C347:
		STA		_spr_buf,X
		INX
		INX
		INX
		INX
		BNE		loc_15C347
locret_15C348:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_menu_clip:
		LDA		_menu_is_drawn_flag				; when menu is displayed, clip all sprites under it.
		BEQ		locret_15C39B
		LDY		#0
loc_15C365:
		LDX		_spr_buf+1,Y
		CPX		#$7E
		BEQ		loc_15C395
		LDX		_spr_buf+3,Y
		CPX		#$99							; X<A0 is changed to 99, since there is one place
		BCC		loc_15C395						; in lab, where kaneda sprites didn't clipped because of that
		CPX		#$F0
		BCS		loc_15C395						; F0 - right corner
		LDX		_spr_buf,Y
		CPX		#$FF
		BEQ		locret_15C39B
		CPX		#$1F
		BCC		loc_15C395						; upper corner Y<1F
		LDA		byte_40							; bottom corner is dinamyc (roll on and out)
		ASL										; so we may clip bottom part according to number of
		ASL										; menu lines currently displayed.
		ASL
		CLC
		ADC		#$1F							; (COL * 8) + 1F of upper corner
		STA		word_0
		CPX		word_0
		BCS		loc_15C395
		LDA		#$FF
		STA		_spr_buf,Y
loc_15C395:
		INY
		INY
		INY
		INY
		BNE		loc_15C365
locret_15C39B:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_sgame_head_draw:
		STA		_sgame_shoot_enable
		LSR
		BCC		loc_15C3AD
		LDA		#<[_tlm_kanedas_bottom_head_on]
		STA		word_0
		LDA		#>[_tlm_kanedas_bottom_head_on]
		STA		word_0+1
		JMP		loc_15C3B5
loc_15C3AD:
		LDA		#<[_tlm_kanedas_bottom_head_off]
		STA		word_0
		LDA		#>[_tlm_kanedas_bottom_head_off]
		STA		word_0+1
loc_15C3B5:
		LDA		#$21
		STA		_PPU_ADDR
		LDA		#$CD
		STA		_PPU_ADDR
		LDY		#0
loc_15C3C1:
		LDA		(word_0),Y
		STA		_PPU_DATA
		INY
		CPY		#7
		BCC		loc_15C3C1
		LDA		#$21
		STA		_PPU_ADDR
		LDA		#$ED
		STA		_PPU_ADDR
loc_15C3D5:
		LDA		(word_0),Y
		STA		_PPU_DATA
		INY
		CPY		#$E
		BCC		loc_15C3D5
		LDA		#0
		STA		_nmi_ppu_sgame_head_draw_req
		RTS
_tlm_kanedas_bottom_head_on:
		.BYTE $E5,$E6,$E7,$E8,$E9,$EA,$EB
		.BYTE $E4,  0,  0,  0,  0,  0,$EC
_tlm_kanedas_bottom_head_off:
		.BYTE   0,  0,  0,  0,  0,  0,  0
		.BYTE   0,  0,  0,  0,  0,  0,  0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_ppu_tmp_buf0_draw:
		LDA		_ppu_tmp_buf0_dst+1
		BEQ		locret_15C421
		STA		_PPU_ADDR
		LDA		_ppu_tmp_buf0_dst
		STA		_PPU_ADDR
		LDX		#0
loc_15C411:
		LDA		_ppu_tmp_buf0,X
		STA		_PPU_DATA
		INX
		CPX		#$20
		BCC		loc_15C411
		LDA		#0
		STA		_ppu_tmp_buf0_dst+1
locret_15C421:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_ppu_tmp_buf1_draw:
		LDA		_ppu_tmp_buf1_dst+1
		BEQ		locret_15C442
		STA		_PPU_ADDR
		LDA		_ppu_tmp_buf1_dst
		STA		_PPU_ADDR
		LDX		#0
loc_15C432:
		LDA		_ppu_tmp_buf1,X
		STA		_PPU_DATA
		INX
		CPX		#$20
		BCC		loc_15C432
		LDA		#0
		STA		_ppu_tmp_buf1_dst+1
locret_15C442:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_ppu_cur_msg_char_draw:
		LDA		_cur_msg_char_ppu_ofs+1
		BEQ		locret_15C46E
		STA		_PPU_ADDR
		LDA		_cur_msg_char_ppu_ofs
		STA		_PPU_ADDR
		LDA		_ppu_ctrl_shadow
		ORA		#4
		STA		_PPU_CTRL
#if LANGUAGE == JP_LANG
;-----------------------------------------------
		LDA		_char_extra_tile				; japan extra nigori type
		STA		_PPU_DATA						; no need for eng version
;-----------------------------------------------
#endif
		LDA		_char_main_tile
		STA		_PPU_DATA
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		LDA		#0
		STA		_cur_msg_char_ppu_ofs+1
locret_15C46E:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_chr_col_draw:
		JSR		_tlm_get_ptr
		LDA		_ppu_ctrl_shadow
		ORA		#4
		STA		_PPU_CTRL
		LDA		byte_35D
		LSR
		LSR
		LSR
		PHA
		CLC
		ADC		_tlm_ptr
		TAX
		LDA		_tlm_ptr+1
		ADC		#0
		STA		_PPU_ADDR
		STX		_PPU_ADDR
		LDX		#0
		LDA		_PPU_DATA
loc_15C495:
		LDA		_PPU_DATA
		STA		_tlm_col_buf,X
		INX
		CPX		#$E
		BCC		loc_15C495
		LDX		#$20
		LDA		byte_35E
		LSR
		BCC		loc_15C4AA
		LDX		#$24
loc_15C4AA:
		STX		_PPU_ADDR
		PLA
		CLC
		ADC		#$40
		STA		_PPU_ADDR
		LDX		#0
loc_15C4B6:
		LDA		_tlm_col_buf,X
		STA		_PPU_DATA
		INX
		CPX		#$E
		BCC		loc_15C4B6
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		LDA		byte_35D
		LSR
		LSR
		LSR
		LSR
		LSR
		PHA
		CLC
		ADC		_tlm_ptr
		STA		word_0
		LDA		#0
		ADC		_tlm_ptr+1
		STA		word_2
		LDA		word_0
		CLC
		ADC		#$C0
		TAX
		LDA		word_2
		ADC		#1
		STA		word_0+1
		STA		_PPU_ADDR
		STX		word_0
		STX		_PPU_ADDR
		LDA		_PPU_DATA
		LDA		_PPU_DATA
		STA		word_2
		LDA		word_0
		CLC
		ADC		#8
		TAX
		LDA		word_0+1
		ADC		#0
		STA		word_0+1
		STA		_PPU_ADDR
		STX		word_0
		STX		_PPU_ADDR
		LDA		_PPU_DATA
		LDA		_PPU_DATA
		STA		word_2+1
		LDA		word_0
		CLC
		ADC		#8
		TAX
		LDA		word_0+1
		ADC		#0
		STA		word_0+1
		STA		_PPU_ADDR
		STX		word_0
		STX		_PPU_ADDR
		LDA		_PPU_DATA
		LDA		_PPU_DATA
		STA		byte_4
		LDA		word_0
		CLC
		ADC		#8
		TAX
		LDA		word_0+1
		ADC		#0
		STA		word_0+1
		STA		_PPU_ADDR
		STX		word_0
		STX		_PPU_ADDR
		LDA		_PPU_DATA
		LDA		_PPU_DATA
		STA		byte_5
		LDX		#$23
		LDA		byte_35E
		LSR
		BCC		loc_15C556
		LDX		#$27
loc_15C556:
		STX		_PPU_ADDR
		PLA
		CLC
		ADC		#$C0
		STA		_PPU_ADDR
		STA		word_0
		LDA		word_2
		STA		_PPU_DATA
		LDA		word_0
		CLC
		ADC		#8
		STX		_PPU_ADDR
		STA		_PPU_ADDR
		STA		word_0
		LDA		word_2+1
		STA		_PPU_DATA
		LDA		word_0
		CLC
		ADC		#8
		STX		_PPU_ADDR
		STA		_PPU_ADDR
		STA		word_0
		LDA		byte_4
		STA		_PPU_DATA
		LDA		word_0
		CLC
		ADC		#8
		STX		_PPU_ADDR
		STA		_PPU_ADDR
		STA		word_0
		LDA		byte_5
		STA		_PPU_DATA
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_prg_line_draw:
		LDA		_tlm_ptr
		STA		word_0
		LDA		_tlm_ptr+1
		STA		word_0+1
		LDY		#0
loc_15C5AA:
		LDA		(word_0),Y
		STA		_ppu_tmp_row_buf,Y
		INY
		CPY		#$20
		BCC		loc_15C5AA
		JMP		_tlm_line_flush

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_chr_line_draw:
		LDX		#0
		LDA		_tlm_ptr+1						; first, get the data from CHR
		STA		_PPU_ADDR
		LDA		_tlm_ptr
		STA		_PPU_ADDR
		LDA		_PPU_DATA
loc_15C5C8:
		LDA		_PPU_DATA
		STA		_ppu_tmp_row_buf,X				; save it in tmp buf
		INX
		CPX		#$20
		BCC		loc_15C5C8

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_line_flush:
		LDA		#$20
		JSR		_tlm_ptr_add
		JMP		_tlm_tmp_line_send				; then send back to CHR lol

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_15C5DB:
		JSR		_ppu_tmp_row_buf_clear
		LDA		_nmi_ppu_draw_counter
		CMP		#$D
		BEQ		locret_15C607
		CMP		#$E
		BEQ		locret_15C607
		LDX		#0
		LDA		_tlm_ptr+1
		STA		_PPU_ADDR
		LDA		_tlm_ptr
		STA		_PPU_ADDR
		LDA		_PPU_DATA
loc_15C5F9:
		LDA		_PPU_DATA
		STA		_ppu_tmp_row_buf+8,X
		INX
		CPX		#$10
		BCC		loc_15C5F9
		BCS		loc_15C62F
locret_15C607:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_15C608:
		JSR		_ppu_tmp_row_buf_clear
		LDA		_nmi_ppu_draw_counter
		CMP		#$D
		BEQ		locret_15C62E
		CMP		#$E
		BEQ		locret_15C62E
		LDA		_tlm_ptr
		STA		word_0
		LDA		_tlm_ptr+1
		STA		word_0+1
		LDY		#0
loc_15C621:
		LDA		(word_0),Y
		STA		_ppu_tmp_row_buf+8,Y
		INY
		CPY		#$10
		BCC		loc_15C621
loc_15C62F:
		LDA		#$10
		JMP		_tlm_ptr_add
locret_15C62E:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_ppu_tmp_row_buf_clear:
		LDA		#0
		TAX
loc_15C638:
		STA		_ppu_tmp_row_buf,X
		STA		_ppu_tmp_row_buf+$10,X
		INX
		CPX		#$10
		BCC		loc_15C638
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_attr_chr_col_read:
		LDX		#0
		LDA		_tlm_ptr+1
		STA		_PPU_ADDR
		LDA		_tlm_ptr
		STA		_PPU_ADDR
		LDA		_PPU_DATA
loc_15C655:
		LDA		_PPU_DATA
		STA		_icon_col_buf,X
		INX
		CPX		#8
		BCC		loc_15C655
		BCS		_tlm_ptr_add_8

;-------------S-U-B-R-O-U-T-I-N-E---------------
_attr_prg_col_read:
		LDA		_tlm_ptr
		STA		word_0
		LDA		_tlm_ptr+1
		STA		word_0+1
		LDY		#0
loc_15C66F:
		LDA		(word_0),Y
		STA		_icon_col_buf,Y
		INY
		CPY		#8
		BCC		loc_15C66F

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_ptr_add_8:
		LDA		#8
		JMP		_tlm_ptr_add

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_15C67F:
		LDX		#0
		LDA		_tlm_ptr+1
		STA		_PPU_ADDR
		LDA		_tlm_ptr
		STA		_PPU_ADDR
		LDA		_PPU_DATA
loc_15C690:
		LDA		_PPU_DATA
		STA		_menu_wnd_row_buf0,X
		INX
		CPX		#4
		BCC		loc_15C690
		BCS		_tmp_ptr_sub_10

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_15C69E:
		LDA		_tlm_bank
;		LSR
		STA		$8001
		LDA		_tlm_ptr
		STA		word_0
		LDA		_tlm_ptr+1
		STA		word_0+1
		LDY		#0
loc_15C6AA:
		LDA		(word_0),Y
		STA		_menu_wnd_row_buf0,Y
		INY
		CPY		#4
		BCC		loc_15C6AA

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tmp_ptr_sub_10:
		LDA		#$10
		JMP		_tmp_ptr_sub

;-------------S-U-B-R-O-U-T-I-N-E---------------
_menu_wnd_row_buf0_chr_read:
		LDA		_tlm_ptr+1
		STA		_PPU_ADDR
		LDA		_tlm_ptr
		STA		_PPU_ADDR
		LDX		#0
		LDA		_PPU_DATA
loc_15C6CB:
		LDA		_PPU_DATA
		STA		_menu_wnd_row_buf0,X
		INX
		CPX		#$A
		BCC		loc_15C6CB
		BCS		_menu_wnd_row_buf0_flush

;-------------S-U-B-R-O-U-T-I-N-E---------------
_menu_wnd_row_buf0_prg_read:
		LDA		_tlm_ptr
		STA		word_0
		LDA		_tlm_ptr+1
		STA		word_0+1
		LDY		#0
loc_15C6E5:
		LDA		(word_0),Y
		STA		_menu_wnd_row_buf0,Y
		INY
		CPY		#$A
		BCC		loc_15C6E5

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_menu_wnd_row_buf0_flush:
		LDA		#$20
		JSR		_tmp_ptr_sub
		JMP		_menu_wnd_row_buf0_send

;-------------S-U-B-R-O-U-T-I-N-E---------------
_menu_wnd_row_buf0_chr_read8:
		LDX		#0
		LDA		_tlm_ptr+1
		STA		_PPU_ADDR
		LDA		_tlm_ptr
		STA		_PPU_ADDR
		LDA		_PPU_DATA
loc_15C708:
		LDA		_PPU_DATA
		STA		_menu_wnd_row_buf0+2,X
		INX
		CPX		#8
		BCC		loc_15C708
		BCS		_tmp_ptr_sub_8

;-------------S-U-B-R-O-U-T-I-N-E---------------
_menu_wnd_row_buf0_prg_read8:
		LDA		_tlm_ptr
		STA		_PPU_ADDR
		LDA		_tlm_ptr+1
		STA		_PPU_ADDR
		LDY		#0
loc_15C724:
		LDA		(word_0),Y
		STA		_menu_wnd_row_buf0+2,Y
		INY
		CPY		#8
		BCC		loc_15C724

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tmp_ptr_sub_8:
		LDA		#8
		JMP		_tmp_ptr_sub

;-------------S-U-B-R-O-U-T-I-N-E---------------
_menu_wnd_row_buf0_send:
		LDA		word_320+1
		STA		_PPU_ADDR
		LDA		word_320
		STA		_PPU_ADDR
		LDX		#0
loc_15C742:
		LDA		_menu_wnd_row_buf0,X
		STA		_PPU_DATA
		INX
		CPX		#$A
		BCC		loc_15C742
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_vars_init:
		LDA		#0
		STA		_nmi_ppu_tlm_draw_req
		STA		_nmi_ppu_icon_draw_req
		STA		_tlm_chr_col_draw_req
		STA		_nmi_ppu_draw0_req
		STA		_nmi_ppu_sgame_head_draw_req
		STA		_cur_msg_char_ppu_ofs+1
		STA		_ppu_tmp_buf0_dst+1
		STA		_ppu_tmp_buf1_dst+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_draw:
		LDA		_nmi_ppu_draw0_req
		BEQ		loc_15C771
		JMP		_nmi_ppu_draw0
loc_15C771:
		LDA		_nmi_ppu_tlm_draw_req
		BEQ		loc_15C779
		JMP		_nmi_ppu_tlm_draw
loc_15C779:
		LDA		byte_34E
		BNE		loc_15C786
		LDA		_nmi_ppu_icon_draw_req
		BEQ		loc_15C786
		JMP		_nmi_ppu_icon_draw
loc_15C786:
		LDA		_tlm_chr_col_draw_req
		BEQ		loc_15C78E
		JMP		_tlm_chr_col_draw
loc_15C78E:
		LDA		_nmi_ppu_sgame_head_draw_req				; no shooting head
		BEQ		loc_15C796
		JMP		_nmi_ppu_sgame_head_draw					; draw head at the bottom
loc_15C796:
		JSR		_ppu_cur_msg_char_draw
		JSR		_ppu_tmp_buf0_draw
		JSR		_ppu_tmp_buf1_draw
		LDA		#0
		STA		byte_34E
		JMP		_pal_send

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_tlm_draw:
		LDA		_nmi_ppu_tlm_draw_req
		SWITCH
		SW_PTR	0
		SW_PTR	_nmi_ppu_tlm_draw_sub1			; draw scene 10 opened door
		SW_PTR	_nmi_ppu_tlm_draw_sub2
		SW_PTR	_nmi_ppu_tlm_draw_sub3
		SW_PTR	_nmi_ppu_tlm_draw_sub4
		SW_PTR	_nmi_ppu_tlm_draw_sub5
		SW_PTR	_nmi_ppu_tlm_draw_sub6
		SW_PTR	_nmi_ppu_tlm_draw_sub7
		SW_PTR	_nmi_ppu_tlm_draw_sub8
		SW_PTR	_nmi_ppu_tlm_draw_sub9

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_tlm_draw_sub1:
		LDA		#<[_tlm_sc10_door_open]
		STA		word_0
		LDA		#>[_tlm_sc10_door_open]
		STA		word_0+1
		LDA		_ppu_ctrl_shadow
		ORA		#4
		STA		_PPU_CTRL
		LDY		#0
		LDA		#$5A
		STA		word_2
loc_15C7E2:
		LDA		#$20
		STA		_PPU_ADDR
		LDA		word_2
		STA		_PPU_ADDR
		LDX		#0
loc_15C7EE:
		LDA		(word_0),Y
		STA		_PPU_DATA
		INY
		INX
		CPX		#8
		BCC		loc_15C7EE
		INC		word_2
		CPY		#$30
		BCC		loc_15C7E2
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		LDA		#0
		STA		_nmi_ppu_tlm_draw_req
		RTS
_tlm_sc10_door_open:
		.BYTE $C7,$C7,$C7,$C7,$D5,$C7,$C7,$DB
		.BYTE $C8,$C8,$C8,$C8,$D6,  1,  1,$DC
		.BYTE $C9,$CD,$CD,$C9,$D7,  1,  1,$DC
		.BYTE $CA,$CE,$D1,  3,$D8,  1,  1,$DC
		.BYTE $CB,$CF,$D2,  3,$D8,  1,  1,$DC
		.BYTE $CC,$D0,$D3,$D4,$D9,$DA,$DA,$DD

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_tlm_draw_sub2:
		LDY		_nmi_ppu_tlm_draw_len
		JSR		_tlm_tmp_line_send_ex
		LDA		#0
		STA		_nmi_ppu_tlm_draw_req
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_tlm_draw_sub3:
		JSR		_tlm_tmp_line_send
		LDA		#0
		STA		_nmi_ppu_tlm_draw_req
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_tlm_draw_sub4:
		LDA		_nmi_ppu_draw_counter
		BNE		loc_15C859
		JSR		_tlm_get_ptr
		INC		_nmi_ppu_draw_counter
		RTS
loc_15C859:
		LDA		_tlm_bank
		AND		#$F0
		BNE		loc_15C869
		JSR		_tlm_chr_setup
		JSR		_tlm_chr_line_draw
		INC		_nmi_ppu_draw_counter
		RTS
loc_15C869:
		LDA		_tlm_bank
;		LSR
		STA		$8001
		JSR		_tlm_prg_line_draw
		INC		_nmi_ppu_draw_counter
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_tlm_draw_sub5:
		LDA		_nmi_ppu_draw_counter
		BNE		loc_15C880
		JSR		_tlm_get_ptr
		INC		_nmi_ppu_draw_counter
		RTS
loc_15C880:
		LDA		_tlm_bank
		AND		#$F0
		BNE		loc_15C89F
		JSR		_tlm_chr_setup
		LDA		_nmi_ppu_draw_counter
		CMP		#$F
		BCS		loc_15C899
		JSR		sub_15C5DB
		JSR		_tlm_tmp_line_send
		JMP		loc_15C8B8
loc_15C899:
		JSR		_tlm_chr_line_draw
		JMP		loc_15C8B8
loc_15C89F:
		LDA		_tlm_bank
;		LSR
		STA		$8001
		LDA		_nmi_ppu_draw_counter
		CMP		#$F
		BCS		loc_15C8B5
		JSR		sub_15C608
		JSR		_tlm_tmp_line_send
		JMP		loc_15C8B8
loc_15C8B5:
		JSR		_tlm_prg_line_draw
loc_15C8B8:
		INC		_nmi_ppu_draw_counter
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_tlm_draw_sub6:
		LDA		_nmi_ppu_draw_counter
		BNE		loc_15C8C5
		JSR		_tlm_get_ptr
		INC		_nmi_ppu_draw_counter
		RTS
loc_15C8C5:
		LDA		_tlm_bank
		STA		$8001
		LDA		_nmi_ppu_draw_counter
		CMP		#$F
		BCS		loc_15C8ED
		JSR		sub_15C608
		LDX		#0
loc_15C8D7:
		LDA		_ppu_tmp_row_buf+8,X
		STA		_ppu_tmp_row_buf,X
		INX
		CPX		#$10
		BCC		loc_15C8D7
		LDY		#$10
		JSR		_tlm_tmp_line_send_ex
		JSR		_tlm_tmp_line_dst_add
		JMP		loc_15C8F3
loc_15C8ED:
		LDA		#$C0
		STA		_tlm_tmp_line_dst
		LDA		#$23
		STA		_tlm_tmp_line_dst+1
		LDA		#<[byte_15CB8C]
		STA		_tlm_ptr
		LDA		#>[byte_15CB8C]
		STA		_tlm_ptr+1
		LDA		_tlm_idx
		CMP		#$30
		BEQ		locret_15CB8B
		LDA		#<[byte_15CBAC]
		STA		_tlm_ptr
		LDA		#>[byte_15CBAC]
		STA		_tlm_ptr+1
locret_15CB8B:
		JSR		_tlm_prg_line_draw
loc_15C8F3:
		INC		_nmi_ppu_draw_counter
		RTS

byte_15CB8C:
		.BYTE $40,$50,$50,$50,$10,  0,  0,  0
		.BYTE $44,$55,$75,$55,$11,  0,  0,  0
		.BYTE $44,$55,$5F,$A5,$11,  0,  0,  0
		.BYTE   4,  5,  9, $A,  1,  0,  0,  0
byte_15CBAC:
		.BYTE $40,$50,$D0,$F0,$10,  0,  0,  0
		.BYTE $44,$DD,$AF,$55,$11,  0,  0,  0
		.BYTE $44,$55,$56,$55,$11,  0,  0,  0
		.BYTE   4,  5,  5,  5,  1,  0,  0,  0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_tlm_draw_sub7:
		LDA		byte_345
		BNE		loc_15C907
		JSR		_tlm_get_ptr
		LDA		#$1F
		JSR		_tlm_ptr_add
		INC		byte_345
		RTS
loc_15C907:
		JSR		_tlm_chr_setup
		JSR		sub_15CA37
		INC		byte_345
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_15CA37:
		LDA		byte_345
		CMP		#$20
		BEQ		loc_15CA8A
		LDA		_ppu_ctrl_shadow
		ORA		#4
		STA		_PPU_CTRL
		LDA		_tlm_ptr+1
		STA		_PPU_ADDR
		LDA		_tlm_ptr
		STA		_PPU_ADDR
		LDX		#0
		LDA		_PPU_DATA
loc_15CA56:
		LDA		_PPU_DATA
		STA		_tlm_col_buf,X
		INX
		CPX		#$10
		BCC		loc_15CA56
		LDA		#1
		JSR		_tmp_ptr_sub
		LDA		byte_324+1
		STA		_PPU_ADDR
		LDA		byte_324
		STA		_PPU_ADDR
		LDX		#0
loc_15CA74:
		LDA		_tlm_col_buf,X
		STA		_PPU_DATA
		INX
		CPX		#$E
		BCC		loc_15CA74
		LDA		_ppu_ctrl_shadow
		STA		_PPU_STATUS
		LDA		#0
		STA		_nmi_ppu_tlm_draw_req
		RTS
loc_15CA8A:
		LDA		#$27
		STA		_PPU_ADDR
		LDA		#$C0
		STA		_PPU_ADDR
		LDX		#0
loc_15CA96:
		LDA		byte_15CAA7,X
		STA		_PPU_DATA
		INX
		CPX		#$20
		BCC		loc_15CA96
		LDA		#0
		STA		_nmi_ppu_tlm_draw_req
		RTS
byte_15CAA7:
		.BYTE $A0,$A0,$A0,$A0,$A0,$A0,$F0,$70
		.BYTE $AA,$AA,$AA,$AA,$AA,$AA,$AE,$FF
		.BYTE $AA,$AA,$AA,$AA,$AA,$AA,$AA,$AE
		.BYTE $AA,$AA,$AA,$AA,$AA,$AA,$AA,$FE

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_tlm_draw_sub8:
		LDA		#0
		STA		_nmi_ppu_tlm_draw_req
		LDA		word_320+1
		STA		_PPU_ADDR
		LDA		word_320
		STA		_PPU_ADDR
		LDY		#0
loc_15C924:
		LDA		_menu_wnd_row_buf0,Y
		STA		_PPU_DATA
		INY
		CPY		#$A
		BCC		loc_15C924
		LDA		word_320
		CLC
		ADC		#$20
		TAX
		LDA		word_320+1
		ADC		#0
		STA		_PPU_ADDR
		STX		_PPU_ADDR
		LDY		#0
loc_15C943:
		LDA		_menu_wnd_row_buf1,Y
		STA		_PPU_DATA
		INY
		CPY		#$A
		BCC		loc_15C943
		LDA		_scene_idx
		CMP		#$A
		BEQ		loc_15C958
		CMP		#$F
		BNE		loc_15C9A4
loc_15C958:
		LDA		word_320
		SEC
		SBC		#$20
		STA		word_0
		LDA		word_320+1
		AND		#$FB
		STA		word_0+1
		LDA		word_320+1
		EOR		#4
		ORA		word_0+1
		SBC		#0
		STA		word_0+1
		STA		_PPU_ADDR
		LDA		word_0
		STA		_PPU_ADDR
		LDY		#0
loc_15C97C:
		LDA		_menu_wnd_row_buf0,Y
		STA		_PPU_DATA
		INY
		CPY		#$A
		BCC		loc_15C97C
		LDA		word_0
		CLC
		ADC		#$20
		TAX
		LDA		word_0+1
		ADC		#0
		STA		_PPU_ADDR
		STX		_PPU_ADDR
		LDY		#0
loc_15C999:
		LDA		_menu_wnd_row_buf1,Y
		STA		_PPU_DATA
		INY
		CPY		#$A
		BCC		loc_15C999
loc_15C9A4:
		JSR		sub_15CBE7
		LDA		byte_40
		AND		#$E
		TAX
		LDA		_scroll_x_shadow
		AND		#$10
		BNE		loc_15C9B0
		LDA		off_99C06,X
		STA		word_0
		LDA		off_99C06+1,X
		STA		word_0+1
		JMP		(word_0)
off_99C06:
		.WORD _nmi_ppu_tlm_draw_sub8_A_1
		.WORD _nmi_ppu_tlm_draw_sub8_A_1
		.WORD _nmi_ppu_tlm_draw_sub8_A_2
		.WORD _nmi_ppu_tlm_draw_sub8_A_2
		.WORD _nmi_ppu_tlm_draw_sub8_A_4
		.WORD _nullsub
		.WORD _nullsub
		.WORD _nullsub
		.WORD _nullsub
loc_15C9B0:
		LDA		off_99CFB,X
		STA		word_0
		LDA		off_99CFB+1,X
		STA		word_0+1
		JMP		(word_0)
off_99CFB:
		.WORD _nmi_ppu_tlm_draw_sub8_B_1
		.WORD _nmi_ppu_tlm_draw_sub8_B_1
		.WORD _nmi_ppu_tlm_draw_sub8_B_2
		.WORD _nmi_ppu_tlm_draw_sub8_B_2
		.WORD _nmi_ppu_tlm_draw_sub8_B_4
		.WORD _nullsub
		.WORD _nullsub
		.WORD _nullsub
		.WORD _nullsub

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_tlm_draw_sub8_A_1:
		LDA		_menu_attr_backup_line0_hi_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_lo_ofs
		STA		_PPU_ADDR
		LDA		#0
		STA		_PPU_DATA
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line0_02
		AND		#$CC
		STA		_PPU_DATA
		LDA		_scene_idx
		CMP		#2
		BEQ		locret_99C18
		LDA		_menu_attr_backup_line0_A_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_lo_ofs
		SEC
		SBC		#8
		STA		_PPU_ADDR
		LDA		#0
		STA		_PPU_DATA
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line0_A2
		AND		#$CC
		STA		_PPU_DATA
locret_99C18:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_tlm_draw_sub8_A_2:
		LDA		_menu_attr_backup_line1_hi_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line1_lo_ofs
		STA		_PPU_ADDR
		LDA		#0
		STA		_PPU_DATA
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line1_02
		AND		#$CC
		STA		_PPU_DATA
		LDA		_scene_idx
		CMP		#2
		BEQ		locret_99C5A
		LDA		_menu_attr_backup_line1_A_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_lo_ofs
		STA		_PPU_ADDR
		LDA		#0
		STA		_PPU_DATA
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line1_A2
		AND		#$CC
		STA		_PPU_DATA
locret_99C5A:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_tlm_draw_sub8_A_4:
		LDA		_menu_attr_backup_line2_hi_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line2_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line2_00
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line2_01
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line2_02
		AND		#$FC
		STA		_PPU_DATA
		LDA		_scene_idx
		CMP		#2
		BEQ		locret_99C99
		LDA		_menu_attr_backup_line2_A_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line1_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line2_A0
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line2_A1
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line2_A2
		AND		#$FC
		STA		_PPU_DATA
locret_99C99:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_tlm_draw_sub8_B_1:
		LDA		_menu_attr_backup_line0_hi_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_00
		AND		#$33
		STA		_PPU_DATA
		LDA		#0
		STA		_PPU_DATA
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line0_A_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_lo_ofs
		SEC
		SBC		#8
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_A0
		AND		#$33
		STA		_PPU_DATA
		LDA		#0
		STA		_PPU_DATA
		STA		_PPU_DATA
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_tlm_draw_sub8_B_2:
		LDA		_menu_attr_backup_line1_hi_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line1_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line1_00
		AND		#$33
		STA		_PPU_DATA
		LDA		#0
		STA		_PPU_DATA
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line1_A_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line1_A0
		AND		#$33
		STA		_PPU_DATA
		LDA		#0
		STA		_PPU_DATA
		STA		_PPU_DATA
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_tlm_draw_sub8_B_4:
		LDA		_menu_attr_backup_line2_hi_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line2_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line2_00
		AND		#$F3
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line2_01
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line2_02
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line2_A_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line1_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line2_A0
		AND		#$F3
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line2_A1
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line2_A2
		AND		#$F0
		STA		_PPU_DATA
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_tlm_draw_sub9:
		LDY		_nmi_ppu_tlm_draw_len
		JSR		_tlm_tmp_line_send_ex
		LDA		_scene_idx
		CMP		#2
		BEQ		loc_15C9E8
		LDA		_tlm_tmp_line_dst+1
		AND		#$FB
		STA		word_0
		LDA		_tlm_tmp_line_dst+1
		EOR		#4
		ORA		word_0
		STA		_tlm_tmp_line_dst+1
		LDA		_tlm_tmp_line_dst
		SEC
		SBC		#$20
		STA		_tlm_tmp_line_dst
		LDA		_tlm_tmp_line_dst+1
		SBC		#0
		STA		_tlm_tmp_line_dst+1
		LDY		_nmi_ppu_tlm_draw_len
		JSR		_tlm_tmp_line_send_ex
loc_15C9E8:
		LDA		#0
		STA		_nmi_ppu_tlm_draw_req
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_draw0:
		LDA		byte_40
		BNE		loc_15CA0C
		LDA		_scene_idx
		CMP		#$10
		BNE		loc_15CA04
		LDA		_scene_flags
		AND		#$40
		BEQ		loc_15CA04
		LDA		#1
		STA		_nmi_ppu_tlm_draw_req
loc_15CA04:
		LDA		#0
		STA		_menu_is_drawn_flag
		STA		_nmi_ppu_draw0_req
loc_15CA0C:
		JSR		_nmi_ppu_draw0_A
		LDA		_scene_idx
		CMP		#$F
		BEQ		loc_15CA34
		CMP		#$A
		BNE		loc_15CA27
		LDA		_tlm_draw_cur_lib_idx
		CMP		#$30
		BEQ		loc_15CA27
		CMP		#$31
		BNE		loc_15CA34
loc_15CA27:
		LDA		_tlm_bank
		AND		#$F0
		BEQ		loc_15CA31
		JMP		_tlm_prg_bank_nmi_draw0
loc_15CA31:
		JMP		_tlm_chr_bank_nmi_draw0
loc_15CA34:
		JMP		_sceneF_nmi_draw0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_draw0_A:
		LDX		byte_40
		INX
		TXA
		AND		#$E
		TAX
		LDA		_scroll_x_shadow
		AND		#$10
		BEQ		loc_B00C9
		LDA		off_B01AF,X
		STA		word_0
		LDA		off_B01AF+1,X
		STA		word_0+1
		JMP		(word_0)
off_B01AF:
		.WORD _nmi_ppu_draw0_A_A
		.WORD _nmi_ppu_draw0_A_B
		.WORD _nmi_ppu_draw0_A_C
		.WORD _nmi_ppu_draw0_A_D
		.WORD _nmi_ppu_draw0_A_E
		.WORD _nullsub
		.WORD _nullsub
		.WORD _nullsub
loc_B00C9:
		LDA		off_B00DF,X
		STA		word_0
		LDA		off_B00DF+1,X
		STA		word_0+1
		JMP		(word_0)
off_B00DF:
		.WORD _nmi_ppu_draw0_A_A
		.WORD _nmi_ppu_draw0_A_F
		.WORD _nmi_ppu_draw0_A_C
		.WORD _nmi_ppu_draw0_A_G
		.WORD _nmi_ppu_draw0_A_E
		.WORD _nullsub
		.WORD _nullsub
		.WORD _nullsub

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_draw0_A_F:
		LDA		_menu_attr_backup_line0_hi_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_00
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line0_01
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line0_02
		AND		#$FC
		STA		_PPU_DATA
		LDA		_scene_idx
		CMP		#2
		BEQ		loc_B011F
		JSR		sub_B0335
		LDA		_menu_attr_backup_line0_lo_ofs
		SEC
		SBC		#8
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_A0
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line0_A1
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line0_A2
		AND		#$FC
		STA		_PPU_DATA
loc_B011F:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_draw0_A_G:
		LDA		_menu_attr_backup_line1_hi_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line1_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line1_00
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line1_01
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line1_02
		AND		#$FC
		STA		_PPU_DATA
		LDA		_scene_idx
		CMP		#2
		BEQ		loc_B0174
		JSR		sub_B0335
		LDA		_menu_attr_backup_line0_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line1_A0
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line1_A1
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line1_A2
		AND		#$FC
		STA		_PPU_DATA
loc_B0174:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_draw0_A_B:
		LDA		_menu_attr_backup_line0_hi_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_00
		AND		#$F3
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line0_01
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line0_02
		AND		#$F0
		STA		_PPU_DATA
		LDA		_scene_idx
		CMP		#2
		BEQ		loc_B01EF
		JSR		sub_B0335
		LDA		_menu_attr_backup_line0_lo_ofs
		SEC
		SBC		#8
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_A0
		AND		#$F3
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line0_A1
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line0_A2
		AND		#$F0
		STA		_PPU_DATA
loc_B01EF:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_draw0_A_D:
		LDA		_menu_attr_backup_line1_hi_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line1_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line1_00
		AND		#$F3
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line1_01
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line1_02
		AND		#$F0
		STA		_PPU_DATA
		LDA		_scene_idx
		CMP		#2
		BEQ		loc_B0244
		JSR		sub_B0335
		LDA		_menu_attr_backup_line0_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line1_A0
		AND		#$F3
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line1_A1
		AND		#$F0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line1_A2
		AND		#$F0
		STA		_PPU_DATA
loc_B0244:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_draw0_A_A:
		LDA		_menu_attr_backup_line0_hi_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_00
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line0_01
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line0_02
		STA		_PPU_DATA
		LDA		_scene_idx
		CMP		#2
		BEQ		loc_B0290
		JSR		sub_B0335
		LDA		_menu_attr_backup_line0_lo_ofs
		SEC
		SBC		#8
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_A0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line0_A1
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line0_A2
		STA		_PPU_DATA
loc_B0290:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_draw0_A_C:
		LDA		_menu_attr_backup_line1_hi_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line1_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line1_00
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line1_01
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line1_02
		STA		_PPU_DATA
		LDA		_scene_idx
		CMP		#2
		BEQ		loc_B02D6
		JSR		sub_B0335
		LDA		_menu_attr_backup_line0_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line1_A0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line1_A1
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line1_A2
		STA		_PPU_DATA
loc_B02D6:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_draw0_A_E:
		LDA		_menu_attr_backup_line2_hi_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line2_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line2_00
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line2_01
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line2_02
		STA		_PPU_DATA
		LDA		_scene_idx
		CMP		#2
		BEQ		loc_B0319
		JSR		sub_B0335
		LDA		_menu_attr_backup_line1_lo_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line2_A0
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line2_A1
		STA		_PPU_DATA
		LDA		_menu_attr_backup_line2_A2
		STA		_PPU_DATA
loc_B0319:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_B0335:
		LDA		_menu_attr_backup_line0_hi_ofs
		AND		#$FB
		STA		word_0
		LDA		_menu_attr_backup_line0_hi_ofs
		EOR		#4
		ORA		word_0
		STA		_PPU_ADDR
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_ppu_icon_draw:
		LDA		_icon_cur_col_pos
		BNE		loc_15CAD1
		JSR		_tlm_get_ptr
		INC		_icon_cur_col_pos
		RTS
loc_15CAD1:
		LDA		_icon_tlm_idx					; if index is FF, it just clears the icon
		CMP		#$FF
		BNE		loc_15CAE5
		LDA		#0
		TAX
loc_15CADA:
		STA		_icon_col_buf,X
		INX
		CPX		#8
		BCC		loc_15CADA
		BCS		loc_15CAFF
loc_15CAE5:
		LDA		_tlm_bank
		AND		#$F0
		BNE		loc_15CAF5
		JSR		_tlm_chr_setup
		JSR		_attr_chr_col_read
		JMP		loc_15CAFF
loc_15CAF5:
		LDA		_tlm_bank
;		LSR
		STA		$8001
		JSR		_attr_prg_col_read
loc_15CAFF:
		INC		_icon_cur_col_pos
		LDA		_icon_cur_col_pos
		CMP		#$A
		BCC		loc_15CB08
		RTS
loc_15CB08:
		LDA		_icon_col_dst+1
		STA		_PPU_ADDR
		LDA		_icon_col_dst
		STA		_PPU_ADDR
		LDX		#0
loc_15CB16:
		LDA		_icon_col_buf,X
		STA		_PPU_DATA
		INX
		CPX		#8
		BCC		loc_15CB16
		LDA		_icon_col_dst
		CLC
		ADC		#$20
		STA		_icon_col_dst
		LDA		_icon_col_dst+1
		ADC		#0
		STA		_icon_col_dst+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_tmp_line_send:
		LDY		#$20
		JSR		_tlm_tmp_line_send_ex
		JMP		_tlm_tmp_line_dst_add

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_tmp_line_send_ex:
		LDA		_tlm_tmp_line_dst+1
		STA		_PPU_ADDR
		LDA		_tlm_tmp_line_dst
		STA		_PPU_ADDR
		LDX		#0
loc_15CB49:
		LDA		_ppu_tmp_row_buf,X
		STA		_PPU_DATA
		INX
		DEY
		BNE		loc_15CB49
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_tmp_line_dst_add:
		LDA		_tlm_tmp_line_dst
		CLC
		ADC		#$20
		STA		_tlm_tmp_line_dst
		LDA		_tlm_tmp_line_dst+1
		ADC		#0
		STA		_tlm_tmp_line_dst+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_prg_bank_nmi_clear:
		LDA		#0
		TAX
loc_15CBCF:
		STA		_menu_wnd_row_buf0,X
		INX
		CPX		#$A
		BCC		loc_15CBCF
		JSR		_menu_wnd_row_buf0_send
		LDA		byte_40
		BEQ		loc_15CBE1
		DEC		byte_40
		RTS
loc_15CBE1:
		LDA		#0
		STA		_nmi_ppu_tlm_draw_req
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_15CBE7:
		LDA		byte_40
		CMP		#2
		BEQ		loc_15CBEE
		RTS
loc_15CBEE:
		LDA		_menu_attr_backup_line0_hi_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_lo_ofs
		STA		_PPU_ADDR
		LDA		_PPU_DATA
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line0_00
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line0_01
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line0_02

		LDA		_menu_attr_backup_line0_A_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line0_lo_ofs
		STA		_PPU_ADDR
		LDA		_PPU_DATA
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line0_A0
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line0_A1
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line0_A2

		LDA		_menu_attr_backup_line1_hi_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line1_lo_ofs
		STA		_PPU_ADDR
		LDA		_PPU_DATA
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line1_00
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line1_01
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line1_02

;		LDA		_menu_attr_backup_line0_A_ofs
		LDA		_menu_attr_backup_line1_A_ofs
		STA		_PPU_ADDR
;		LDA		_menu_attr_backup_line0_lo_ofs
		LDA		_menu_attr_backup_line1_lo_ofs
		STA		_PPU_ADDR
		LDA		_PPU_DATA
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line1_A0
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line1_A1
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line1_A2

		LDA		_menu_attr_backup_line2_hi_ofs
		STA		_PPU_ADDR
		LDA		_menu_attr_backup_line2_lo_ofs
		STA		_PPU_ADDR
		LDA		_PPU_DATA
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line2_00
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line2_01
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line2_02

;		LDA		_menu_attr_backup_line0_A_ofs
		LDA		_menu_attr_backup_line2_A_ofs
		STA		_PPU_ADDR
;		LDA		_menu_attr_backup_line0_lo_ofs
		LDA		_menu_attr_backup_line2_lo_ofs
		STA		_PPU_ADDR
		LDA		_PPU_DATA
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line2_A0
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line2_A1
		LDA		_PPU_DATA
		STA		_menu_attr_backup_line2_A2
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_prg_bank_nmi_draw0:
		LDA		byte_350
		BEQ		loc_15CCCB
		CMP		#$FF
		BNE		loc_15CCC1
		JMP		_tlm_prg_bank_nmi_clear
loc_15CCC1:
		CMP		#1
		BEQ		loc_15CCC8
		JMP		_tlm_prg_bank_nmi_draw0_2
loc_15CCC8:
		JMP		_tlm_prg_bank_nmi_draw0_1
loc_15CCCB:
		JMP		_tlm_prg_bank_nmi_draw0_0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_chr_bank_nmi_draw0:
		LDA		byte_350
		BEQ		loc_15CCE4
		CMP		#$FF
		BNE		loc_15CCDA
		JMP		_tlm_prg_bank_nmi_clear
loc_15CCDA:
		CMP		#1
		BEQ		loc_15CCE1
		JMP		_tlm_chr_bank_nmi_draw2
loc_15CCE1:
		JMP		_tlm_chr_bank_nmi_draw1
loc_15CCE4:
		JMP		_tlm_chr_bank_nmi_draw0_0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_prg_bank_nmi_draw0_0:
		LDA		byte_40
		CMP		#$A
		BNE		loc_15CCF3
		JSR		_tlm_draw_something
		DEC		byte_40
		RTS
loc_15CCF3:
		JSR		sub_15CD03
		DEC		byte_40
		BEQ		locret_15CD02
		JSR		_word_320_add32
		JSR		sub_15CD03
		DEC		byte_40
locret_15CD02:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_15CD03:
		LDX		byte_367
		LDA		_menu_restore_tlm_idx_list,X
		JSR		_tlm_get_index_by_number
		LDA		_tlm_bank
;		LSR
		STA		$8001
		JMP		_menu_wnd_row_buf0_prg_read

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_chr_bank_nmi_draw0_0:
		LDA		byte_40
		CMP		#$A
		BNE		loc_15CD22
		JSR		_tlm_draw_something
		DEC		byte_40
		RTS
loc_15CD22:
		JSR		sub_15CD32
		DEC		byte_40
		BEQ		locret_15CD31
		JSR		_word_320_add32
		JSR		sub_15CD32
		DEC		byte_40
locret_15CD31:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_15CD32:
		LDX		byte_367
		LDA		_menu_restore_tlm_idx_list,X
		JSR		_tlm_get_index_by_number
		JSR		_tlm_chr_setup
		JMP		_menu_wnd_row_buf0_chr_read

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_prg_bank_nmi_draw0_2:
		LDA		#0
		TAX
loc_15CD44:
		STA		_menu_wnd_row_buf0,X
		INX
		CPX		#$A
		BCC		loc_15CD44
		LDA		byte_40
		CMP		#$A
		BNE		loc_15CD63
		LDA		_tlm_draw_cur_lib_idx
		JSR		_tlm_get_index_by_number
		JSR		_tlm_get_ptr
		LDA		#$BC
		JSR		_tlm_ptr_add
		DEC		byte_40
		RTS
loc_15CD63:
		JSR		sub_15C69E
		JSR		_menu_wnd_row_buf0_send
		DEC		byte_40
		BEQ		locret_15CD86
		JSR		_word_320_add32
		JSR		sub_15C69E
		JSR		_menu_wnd_row_buf0_send
		DEC		byte_40
locret_15CD86:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_chr_bank_nmi_draw2:
		LDA		#0
		TAX
loc_15CD8A:
		STA		_menu_wnd_row_buf0,X
		INX
		CPX		#$A
		BCC		loc_15CD8A
		LDA		byte_40
		CMP		#$A
		BNE		loc_15CDA9
		LDA		_tlm_draw_cur_lib_idx
		JSR		_tlm_get_index_by_number
		JSR		_tlm_get_ptr
		LDA		#$BC
		JSR		_tlm_ptr_add
		DEC		byte_40
		RTS
loc_15CDA9:
		JSR		_tlm_chr_setup
		JSR		sub_15C67F
		JSR		_menu_wnd_row_buf0_send
		DEC		byte_40
		BEQ		locret_15CDC4
		JSR		_word_320_add32
		JSR		_tlm_chr_setup
		JSR		sub_15C67F
		JSR		_menu_wnd_row_buf0_send
		DEC		byte_40
locret_15CDC4:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_prg_bank_nmi_draw0_1:
		LDA		#0
		TAX
loc_15CDC8:
		STA		_menu_wnd_row_buf0,X
		INX
		CPX		#$A
		BCC		loc_15CDC8
		LDA		byte_40
		CMP		#$A
		BNE		loc_15CDE8
		LDA		_tlm_draw_cur_lib_idx
		JSR		_tlm_get_index_by_number
		JSR		_tlm_get_ptr
		LDA		#$38
		JSR		_tlm_ptr_add
		DEC		byte_40
		RTS
loc_15CDE8:
		JSR		sub_15CDFE
		JSR		_menu_wnd_row_buf0_send
		DEC		byte_40
		BEQ		locret_15CDFD
		JSR		_word_320_add32
		JSR		sub_15CDFE
		JSR		_menu_wnd_row_buf0_send
		DEC		byte_40
locret_15CDFD:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_15CDFE:
		LDA		byte_40
		CMP		#6
		BCS		locret_15CE0E
		LDA		_tlm_bank
;		LSR
		STA		$8001
		JSR		_menu_wnd_row_buf0_prg_read8
locret_15CE0E:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_chr_bank_nmi_draw1:
		LDA		#0
		TAX
loc_15CE12:
		STA		_menu_wnd_row_buf0,X
		INX
		CPX		#$A
		BCC		loc_15CE12
		LDA		byte_40
		CMP		#$A
		BNE		loc_15CE32
		LDA		_tlm_draw_cur_lib_idx
		JSR		_tlm_get_index_by_number
		JSR		_tlm_get_ptr
		LDA		#$38
		JSR		_tlm_ptr_add
		DEC		byte_40
		RTS
loc_15CE32:
		JSR		sub_15CE4C
		JSR		_menu_wnd_row_buf0_send
		LDA		byte_40
		BEQ		locret_15CE4B
		DEC		byte_40
		BEQ		locret_15CE4B
		JSR		_word_320_add32
		JSR		sub_15CE4C
		JSR		_menu_wnd_row_buf0_send
		DEC		byte_40
locret_15CE4B:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_15CE4C:
		LDA		byte_40
		CMP		#6
		BCS		locret_15CE58
		JSR		_tlm_chr_setup
		JSR		_menu_wnd_row_buf0_chr_read8
locret_15CE58:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_word_320_add32:
		LDA		#$20
		STA		word_0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_word_320_add_ex:
		LDA		word_320
		SEC
		SBC		word_0
		STA		word_320
		LDA		word_320+1
		SBC		#0
		STA		word_320+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_ptr_add:
		STA		word_0
		LDA		_tlm_ptr
		CLC
		ADC		word_0
		STA		_tlm_ptr
		LDA		_tlm_ptr+1
		ADC		#0
		STA		_tlm_ptr+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tmp_ptr_sub:
		STA		word_0
		LDA		_tlm_ptr
		SEC
		SBC		word_0
		STA		_tlm_ptr
		LDA		_tlm_ptr+1
		SBC		#0
		STA		_tlm_ptr+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sceneF_nmi_draw0:
		LDA		byte_40
		CMP		#$A
		BNE		loc_15CEAE
		JSR		_tlm_draw_something
		DEC		byte_40
		RTS
loc_15CEAE:
		JSR		sub_15CEB4
		DEC		byte_40
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_draw_something:
		LDA		_scroll_x_shadow
		CLC
		ADC		#$A0
		PHA
		LDA		_scroll_x_shadow+1
		ADC		#0
		TAX
		STX		byte_367
		INX
		LDA		_menu_restore_tlm_idx_list,X
		JSR		_tlm_get_index_by_number
		JSR		_tlm_get_ptr
		LDA		_tlm_ptr
		CLC
		ADC		#$40
		STA		word_368
		LDA		_tlm_ptr+1
		ADC		#1
		STA		word_368+1
		PLA
		LSR
		LSR
		LSR
		AND		#$1E
		PHA
		CLC
		ADC		word_368
		STA		word_368
		LDA		#0
		ADC		word_368+1
		STA		word_368+1
		LDX		byte_367
		LDA		_menu_restore_tlm_idx_list,X
		JSR		_tlm_get_index_by_number
		JSR		_tlm_get_ptr
		LDA		_tlm_ptr
		CLC
		ADC		#$60
		STA		_tlm_ptr
		LDA		_tlm_ptr+1
		ADC		#1
		STA		_tlm_ptr+1
		PLA
		CLC
loc_99AE0:
		ADC		_tlm_ptr
		STA		_tlm_ptr
		LDA		#0
		ADC		_tlm_ptr+1
		STA		_tlm_ptr+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_15CEB4:
		LDX		byte_367
		LDA		_menu_restore_tlm_idx_list,X
		JSR		_tlm_get_index_by_number
		JSR		_tlm_chr_setup
		JSR		_menu_wnd_row_buf0_chr_read
		LDX		byte_367
		INX
		LDA		_menu_restore_tlm_idx_list,X
		JSR		_tlm_get_index_by_number
		JSR		_tlm_chr_setup
		LDA		word_368+1
		STA		_PPU_ADDR
		LDA		word_368
		STA		_PPU_ADDR
		LDX		#0
		LDA		_PPU_DATA
loc_15CEE5:
		LDA		_PPU_DATA
		STA		_menu_wnd_row_buf0,X
		INX
		CPX		#$A
		BCC		loc_15CEE5
		LDA		word_368
		SEC
		SBC		#$20
		STA		word_368
		LDA		word_368+1
		SBC		#0
		STA		word_368+1
		LDA		word_320
		SEC
		SBC		#$20
		TAX
		LDA		word_320+1
		AND		#$FB
		STA		word_0
		LDA		word_320+1
		EOR		#4
		ORA		word_0
		SBC		#0
		STA		_PPU_ADDR
		STX		_PPU_ADDR
		LDX		#0
loc_15CF20:
		LDA		_menu_wnd_row_buf0,X
		STA		_PPU_DATA
		INX
		CPX		#$A
		BCC		loc_15CF20
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_far_call:
		LDA		$8000
		PHA
		STX		$8000
		TYA
		ASL
		TAX
		LDA		FAR_SUB_START,X
		STA		word_0
		LDA		FAR_SUB_START+1,X
		STA		word_0+1
		JSR		_word_0_jmp
		PLA
		STA		$8000
		RTS

_word_0_jmp:
		JMP		(word_0)

;-------------S-U-B-R-O-U-T-I-N-E---------------
_read_pads:
		LDA		_pads
		STA		word_0+1
		LDA		_pads+2
		STA		word_2
		LDA		#1
		STA		_PAD0_REG
		LDA		#0
		STA		_PAD0_REG
		LDX		#8
loc_15CFA5:
		LDA		_PAD0_REG
		AND		#3
		CMP		#1
		ROR		_pads
		LDA		_PAD1_REG
		AND		#3
		CMP		#1
		ROR		_pads+2
		DEX
		BNE		loc_15CFA5
		LDA		_pads
		EOR		word_0+1
		AND		_pads
		STA		_pads+1
		LDA		_pads+2
		EOR		word_2
		AND		_pads+2
		STA		_pads+3
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_pal_send:
		LDA		_PPU_STATUS
		LDY		#0
		LDA		#$3F
		STA		_PPU_ADDR
		STY		_PPU_ADDR
loc_15CFFF:
		LDA		_pal_buf,Y
		STA		_PPU_DATA
		LDA		_pal_buf+1,Y
		STA		_PPU_DATA
		INY
		INY
		CPY		#$20
		BCC		loc_15CFFF
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_ppu_reload:
		LDA		_PPU_STATUS
		LDA		_ppu_ctrl_shadow
		AND		#$FC
		STA		_ppu_ctrl_shadow
		LDA		_scroll_x_shadow+1
		AND		#1
		ORA		_ppu_ctrl_shadow
		STA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		LDA		_scroll_x_shadow
		STA		_PPU_SCROLL
		LDA		_scroll_y_shadow
		STA		_PPU_SCROLL
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_render_on:
		LDA		#$1E
		BNE		_set_ppu_mask

;-------------S-U-B-R-O-U-T-I-N-E---------------
_render_off:
		LDA		#0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_set_ppu_mask:
		STA		_ppu_mask_shadow
		STA		_PPU_MASK
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_on:
		LDA		_PPU_STATUS
		LDA		_ppu_ctrl_shadow
		ORA		#$80
		STA		_ppu_ctrl_shadow
		BNE		_set_ppu_ctrl

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nmi_off:
		LDA		_ppu_ctrl_shadow
		AND		#$7F
		STA		_ppu_ctrl_shadow

;-------------S-U-B-R-O-U-T-I-N-E---------------
_set_ppu_ctrl:
		STA		_PPU_CTRL
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_randomize:
		LDA		_rand
		ASL
		ASL
		CLC
		ADC		_rand
		CLC
		ADC		#$B
		STA		_rand
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_mmc_reload:
		LDA		_prg_bank_8000
		STA		$8000
		LDA		_prg_bank_A000
		STA		$8001
		LDA		_chr_bank01
		STA		$8002
		LDA		_chr_bank23
		STA		$8003
		LDA		_chr_bank4
		STA		$A000
		LDA		_chr_bank5
		STA		$A001
		LDA		_chr_bank6
		STA		$A002
		LDA		_chr_bank7
		STA		$A003
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_get_params4:
		LDY		#1
		LDA		(byte_4),Y						; read params
		STA		word_0
		INY
		LDA		(byte_4),Y
		STA		word_0+1
		INY
		LDA		(byte_4),Y
		STA		word_2
		INY
		LDA		(byte_4),Y
		STA		word_2+1
		TYA										; push address back
		CLC
		ADC		byte_4
		TAY
		LDA		byte_5
		ADC		#0
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_get_params2:
		LDY		#1
		LDA		(byte_4),Y						; read params
		STA		word_0
		INY
		LDA		(byte_4),Y
		STA		word_0+1
		TYA										; push address back
		CLC
		ADC		byte_4
		TAY
		LDA		byte_5
		ADC		#0
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_load0_param_sw:
		ASL
		STA		byte_6
		PLA										; get data ptr (ret addr-1)
		STA		byte_4
		PLA
		STA		byte_5
		JSR		_spr_get_params4
		JMP		_spr_load0_param_sw_ex0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_load0_param_sw_ex:
		ASL
		STA		byte_6
		PLA										; get data ptr (ret addr-1)
		STA		byte_4
		PLA
		STA		byte_5
		JSR		_spr_get_params2

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_load0_param_sw_ex0:
		PHA
		TYA
		PHA
		LDY		byte_6
		LDA		(word_0),Y
		PHA
		INY
		LDA		(word_0),Y
		STA		word_0+1
		PLA
		STA		word_0
		JMP		_spr_load0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_load0_param_ex
		PLA										; get data ptr (ret addr-1)
		STA		byte_4
		PLA
		STA		byte_5
		JSR		_spr_get_params2
		JMP		_spr_load0_0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_load0_param:
		PLA										; get data ptr (ret addr-1)
		STA		byte_4
		PLA
		STA		byte_5
		JSR		_spr_get_params4

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_load0_0:
		PHA
		TYA
		PHA

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
; sprite load at desired position on the screen
; with no Y clipping
;
_spr_load0:
		LDA		#0
		STA		_spr_y_clip_flag
		BEQ		_spr_load						; no fallthrough

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_load1_param_sw_ex:
		ASL
		STA		byte_6
		PLA										; get data ptr (ret addr-1)
		STA		byte_4
		PLA
		STA		byte_5
		JSR		_spr_get_params2
		PHA
		TYA
		PHA
		LDY		byte_6
		LDA		(word_0),Y
		PHA
		INY
		LDA		(word_0),Y
		STA		word_0+1
		PLA
		STA		word_0
		JMP		_spr_load1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_load1_param:
		PLA										; get data ptr (ret addr-1)
		STA		byte_4
		PLA
		STA		byte_5
		JSR		_spr_get_params2
		PHA
		TYA
		PHA

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
; the same as previous, but with Y clipping
;
_spr_load1:
		LDA		#$40
		STA		_spr_y_clip_flag

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_load:
		LDA		#0
		STA		byte_4
		TXA
		PHA
		LDY		#0
		LDX		_spr_buf_pos
loc_15D17F:
		TXA
		BNE		loc_15D187
loc_15D182:
		STX		_spr_buf_pos
		PLA
		TAX
		RTS
loc_15D187:
		LDA		(word_0),Y
		CMP		#$80
		BEQ		loc_15D182
		BCC		loc_15D1A5
		EOR		#$FF
		ADC		#0
		STA		byte_A
		LDA		word_2
		SEC
		SBC		byte_A
		BCS		loc_15D1AB
loc_15D19F:
		INY
		INY
		INY
		INY
		BNE		loc_15D187
loc_15D1A5:
		CLC
		ADC		word_2
		BCS		loc_15D19F
loc_15D1AB:
		SEC
		SBC		#1
; here is the only difference between spr0 and spr1
;-----------------------------------------------
		BIT		_spr_y_clip_flag
		BVC		._spr_no_clip
		CMP		#8
		BCC		loc_15D19F
		CMP		#$80
		BCS		loc_15D19F
._spr_no_clip:
;-----------------------------------------------
		STA		_spr_buf,X
		INY
		LDA		(word_0),Y
		STA		_spr_buf+1,X
		INY
		LDA		(word_0),Y
		EOR		byte_4
		STA		_spr_buf+2,X
		LDA		byte_4
		AND		#3
		BEQ		loc_15D1DD
		STA		byte_9
		LDA		_spr_buf+2,X
		AND		#$F0
		ORA		byte_9
		STA		_spr_buf+2,X
loc_15D1DD:
		INY
		BIT		byte_4
		LDA		(word_0),Y
		BVC		loc_15D1EA
		LDA		#$F8
		SEC
		SBC		(word_0),Y
loc_15D1EA:
		CLC
		BPL		loc_15D209
		EOR		#$FF
		STA		byte_A
		LDA		word_2+1
		SBC		byte_A
		BCC		loc_15D205
		CMP		#$F9
		BCS		loc_15D205
loc_15D1FE:
		STA		_spr_buf+3,X
		INX
		INX
		INX
		INX
loc_15D205:
		INY
		JMP		loc_15D17F
loc_15D209:
		ADC		word_2+1
		BCC		loc_15D1FE
		INY
		JMP		loc_15D187

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_area_row_clear:
		LDA		#0
		TAX
loc_15D215:
		STA		_ppu_tmp_buf0,X
		INX
		CPX		#$20
		BCC		loc_15D215
		JSR		_draw_area_clear_pos_calc
		INC		_nmi_ppu_draw_counter
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_menu_switch:
		JSR		_scene_bg_redraw_request
		LDA		_scene_menu_idx
		ASL
		TAY
		PLA
		STA		word_0
		PLA
		STA		word_0+1
		INY
		LDA		(word_0),Y
		PHA
		INY
		LDA		(word_0),Y
		STA		word_0+1
		PLA
		STA		word_0
		LDX		_cur_scene_menu_pos
		LDA		_scene_menu_items,X
		ASL
		TAY
		LDA		(word_0),Y
		STA		word_2
		INY
		LDA		(word_0),Y
		STA		word_2+1
		JMP		(word_2)

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_area_clear_pos_calc:
		LDA		_nmi_ppu_draw_counter
		CMP		#$10
		BEQ		loc_15D258
		JSR		_draw_cnt_asl5
		STA		_ppu_tmp_buf0_dst
		LDA		word_2
		CLC
		ADC		_tmp_idxF
		STA		_ppu_tmp_buf0_dst+1
		RTS
loc_15D258:
		LDA		#$C0
		STA		_ppu_tmp_buf0_dst
		LDA		_tmp_idxF
		CLC
		ADC		#3
		STA		_ppu_tmp_buf0_dst+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_cnt_asl5:
		LDA		_nmi_ppu_draw_counter
		LDX		#0
		STX		word_2
		ASL
		ROL		word_2
		ASL
		ROL		word_2
		ASL
		ROL		word_2
		ASL
		ROL		word_2
		ASL
		ROL		word_2
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
; input, none, calc bank and ptr idx from
; _scene_idx and _cur_msg_idx
; set prg bank and return block idx in A
;
_get_msg_block_prg_and_idx:
		LDA		_scene_idx
		LDX		_cur_msg_idx
		CPX		#$70
		BCC		.12
		LDA		#$17
.12
		ASL
		TAX
		LDA		_msg_blocks_list,X
		STA		$8001
		LDA		_msg_blocks_list+1,X
		RTS

	; library entry
	MAC		MSG_B
	.BYTE	{1}_bank,{1}_pidx
	ENDM

_msg_blocks_list:
		MSG_B	_scene0_msg_lib
		MSG_B	_scene1_msg_lib
		MSG_B	_scene2_msg_lib
		MSG_B	_scene3_msg_lib
		MSG_B	_scene4_msg_lib
		MSG_B	_scene5_msg_lib
		MSG_B	_scene6_msg_lib
		MSG_B	_scene7_msg_lib
		MSG_B	_scene8_msg_lib
		MSG_B	_scene9_msg_lib
		MSG_B	_sceneA_msg_lib
		MSG_B	_sceneB_msg_lib
		MSG_B	_sceneC_msg_lib
		MSG_B	_sceneD_msg_lib
		MSG_B	_sceneE_msg_lib
		MSG_B	_sceneF_msg_lib
		MSG_B	_scene10_msg_lib
		MSG_B	_scene11_msg_lib
		MSG_B	_scene12_msg_lib
		MSG_B	_scene13_msg_lib
		MSG_B	_scene14_msg_lib
		MSG_B	_scene15_msg_lib
		MSG_B	_scene16_msg_lib
		MSG_B	_scene17_msg_lib

;-------------S-U-B-R-O-U-T-I-N-E---------------
_div16:
		LDA		#0
		STA		byte_5
		STA		byte_6
		LDY		#$F
loc_15D039:
		ASL		word_0+1
		ROL		word_2
		ROL		byte_5
		ROL		byte_6
		LDA		byte_5
		SEC
		SBC		word_2+1
		STA		byte_7
		LDA		byte_6
		SBC		byte_4
		BCC		loc_15D056
		STA		byte_6
		LDA		byte_7
		STA		byte_5
		INC		word_0+1
loc_15D056:
		DEY
		BPL		loc_15D039
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_mul16:
		LDY		#7
		LDA		#0
		STA		word_2+1
		STA		byte_4
		STA		byte_5
		STA		byte_6
loc_15D2B5:
		LSR		word_2
		BCC		loc_15D2CC
		LDA		word_0
		CLC
		ADC		byte_4
		STA		byte_4
		LDA		word_0+1
		ADC		byte_5
		STA		byte_5
		LDA		word_2+1
		ADC		byte_6
		STA		byte_6
loc_15D2CC:
		ASL		word_0
		ROL		word_0+1
		ROL		word_2+1
		DEY
		BPL		loc_15D2B5
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_get_ptr:
		LDA		_tlm_bank
		AND		#$F0
		BNE		loc_15D32D
		JSR		_tlm_chr_setup
		LDA		_PPU_STATUS
		LDA		#0
		STA		_PPU_ADDR
		LDA		_tlm_idx
		STA		_PPU_ADDR
		LDA		_PPU_DATA
		LDA		_PPU_DATA
		STA		_tlm_ptr
		LDA		_PPU_DATA
		STA		_tlm_ptr+1
		RTS
loc_15D32D:
		LDA		_tlm_bank
;		LSR
		STA		$8001
		LDX		_tlm_idx
		LDA		$A000,X
		STA		_tlm_ptr
		LDA		$A001,X
		STA		_tlm_ptr+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_chr_setup:
		LDA		_tlm_bank
		ASL
		TAY
		LDX		_tlm_chr_bank_list,Y
		STX		$8002
		INX
		STX		$8003
		LDX		_tlm_chr_bank_list+1,Y
		STX		$A000
		INX
		STX		$A001
		INX
		STX		$A002
		INX
		STX		$A003
		RTS

_tlm_chr_bank_list:
		.BYTE $60,$C4							; C0 C2 C4 C5 C6 C7
		.BYTE $64,$CC							; C8 CA CC CD CE CF
		.BYTE $68,$D4							; ...
		.BYTE $6C,$DC							; ...
		.BYTE $70,$E4							; E0 E2 E4 E5 E6 E7

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_get_index_by_number:
		STA		word_0
		LDA		#0
		STA		word_0+1
		ASL		word_0
		ROL		word_0+1
		LDA		word_0
		CLC
		ADC		#<[_tlm_indexes_lib]
		STA		word_0
		LDA		word_0+1
		ADC		#>[_tlm_indexes_lib]
		STA		word_0+1
		LDY		#0
		LDA		(word_0),Y
		STA		_tlm_bank
		INY
		LDA		(word_0),Y
		ASL
		STA		_tlm_idx
		RTS

		MAC	TLM_B
{1}_sidx	SET	[[.-_tlm_indexes_lib]>>1]
		.BYTE	{1}_bank,{1}_pidx
		ENDM

_tlm_indexes_lib:
		TLM_B	_tlm00
		TLM_B	_tlm01
		TLM_B	_tlm02
		TLM_B	_tlm03
		TLM_B	_tlm04
		TLM_B	_tlm05
		TLM_B	_tlm06
		TLM_B	_tlm07
		TLM_B	_tlm08
		TLM_B	_tlm09
		TLM_B	_tlm0A
		TLM_B	_tlm0B
		TLM_B	_tlm0C
		TLM_B	_tlm0D
		TLM_B	_tlm0E
		TLM_B	_tlm0F
		TLM_B	_tlm10
		TLM_B	_tlm11
		TLM_B	_tlm12
		TLM_B	_tlm13
		TLM_B	_tlm14
		TLM_B	_tlm15
		TLM_B	_tlm16
		TLM_B	_tlm17
		TLM_B	_tlm18
		TLM_B	_tlm19
		TLM_B	_tlm1A
		TLM_B	_tlm1B
		TLM_B	_tlm1C
		TLM_B	_tlm1D
		TLM_B	_tlm1E
		TLM_B	_tlm1F
		TLM_B	_tlm20
		.BYTE   2,  7		; 21 == 20
		TLM_B	_tlm22
		TLM_B	_tlm23
		.BYTE   2, $A		; 24 == 5D
		TLM_B	_tlm25
		.BYTE   2, $C		; 26 == 5E
		TLM_B	_tlm27
		TLM_B	_tlm28
		TLM_B	_tlm29
		TLM_B	_tlm2A
		TLM_B	_tlm2B
		TLM_B	_tlm2C
		TLM_B	_tlm2D
		TLM_B	_tlm2E
		TLM_B	_tlm2F
		TLM_B	_tlm30
		TLM_B	_tlm31
		TLM_B	_tlm32
		TLM_B	_tlm33
		TLM_B	_tlm34
		TLM_B	_tlm35
		TLM_B	_tlm36
		TLM_B	_tlm37
		TLM_B	_tlm38
		TLM_B	_tlm39
		TLM_B	_tlm3A
		TLM_B	_tlm3B
		TLM_B	_tlm3C
		TLM_B	_tlm3D
		TLM_B	_tlm3E
		TLM_B	_tlm3F
		TLM_B	_tlm40
		TLM_B	_tlm41
		TLM_B	_tlm42
		TLM_B	_tlm43
		TLM_B	_tlm44
		TLM_B	_tlm45
		TLM_B	_tlm46
		.BYTE   4,  8		; 47	; unref
		TLM_B	_tlm48
		.BYTE   4, $A		; 49	; unref
		.BYTE   4, $B		; 4A	; unref
		.BYTE   4, $C		; 4B	; unref
		TLM_B	_tlm4C
		TLM_B	_tlm4D
		TLM_B	_tlm4E
		TLM_B	_tlm4F
		TLM_B	_tlm50
		TLM_B	_tlm51
		.BYTE   1, $A		; 52	; unused
		TLM_B	_tlm53
		TLM_B	_tlm54
		TLM_B	_tlm55
		TLM_B	_tlm56
		TLM_B	_tlm57
		TLM_B	_tlm58
		TLM_B	_tlm59
		TLM_B	_tlm5A
		TLM_B	_tlm5B
		TLM_B	_tlm5C
		TLM_B	_tlm5D
		TLM_B	_tlm5E
		TLM_B	_tlm5F
		TLM_B	_tlm60
		TLM_B	_tlm61
		TLM_B	_tlm62
		TLM_B	_tlm63
		TLM_B	_tlm64
		TLM_B	_tlm65
		TLM_B	_tlm66
		TLM_B	_tlm67
		TLM_B	_tlm68
		TLM_B	_tlm69
		TLM_B	_tlm6A
		TLM_B	_tlm6B
		TLM_B	_tlm6C
		TLM_B	_tlm6D
		TLM_B	_tlm6E
		TLM_B	_tlm6F
		.BYTE   4,  0		; 70	; unref
		.BYTE   4,  0		; 71	; unref
		TLM_B	_tlm72
		.BYTE   4,  0		; 73	; unref
		.BYTE   4,  0		; 74	; unref
		TLM_B	_tlm75
		TLM_B	_tlm76
		TLM_B	_tlm77
		TLM_B	_tlm78
		TLM_B	_tlm79
		TLM_B	_tlm7A
		TLM_B	_tlm7B
		TLM_B	_tlm7C
		TLM_B	_tlm7D
		TLM_B	_tlm7E
		TLM_B	_tlm7F
		TLM_B	_tlm80
		TLM_B	_tlm81
		TLM_B	_tlm82
		TLM_B	_tlm83
		TLM_B	_tlm84
		TLM_B	_tlm85
		TLM_B	_tlm86
		TLM_B	_tlm87
		TLM_B	_tlm88
		TLM_B	_tlm89
		TLM_B	_tlm8A
		TLM_B	_tlm8B
		TLM_B	_tlm8C
		TLM_B	_tlm8D
		TLM_B	_tlm8E
		.BYTE $3D,$10		; 8F	; unref
		.BYTE $3D,$11		; 90	; unref
		TLM_B	_tlm91
		TLM_B	_tlm92
		TLM_B	_tlm93
		.BYTE $3D,$14		; 94	; unref
		TLM_B	_tlm95
		TLM_B	_tlm96
		TLM_B	_tlm97
		TLM_B	_tlm98
		TLM_B	_tlm99
		TLM_B	_tlm9A
		TLM_B	_tlm9B
		TLM_B	_tlm9C
		TLM_B	_tlm9D
		TLM_B	_tlm9E
		TLM_B	_tlm9F
		TLM_B	_tlmA0
		TLM_B	_tlmA1
		TLM_B	_tlmA2
		TLM_B	_tlmA3
		TLM_B	_tlmA4
		TLM_B	_tlmA5
		TLM_B	_tlmA6

;		.BYTE   0,  0		; 00
;		.BYTE   0,  1		; 01
;		.BYTE $3D,$19		; 02
;		.BYTE $3D,$1A		; 03
;		.BYTE $3D,$1B		; 04
;		.BYTE   0,  5		; 05
;		.BYTE   0,  6		; 06
;		.BYTE   0,  7		; 07
;		.BYTE   0,  8		; 08
;		.BYTE   1,  0		; 09
;		.BYTE   1,  1		; 0A
;		.BYTE   1,  2		; 0B
;		.BYTE   1,  3		; 0C
;		.BYTE   1,  4		; 0D
;		.BYTE   1,  5		; 0E
;		.BYTE   1, $D		; 0F
;		.BYTE   0,$10		; 10
;		.BYTE   0,$11		; 11
;		.BYTE   0,$12		; 12
;		.BYTE   3,$18		; 13
;		.BYTE   0, $A		; 14
;		.BYTE   0, $B		; 15
;		.BYTE   0, $C		; 16
;		.BYTE   0, $D		; 17
;		.BYTE   0, $E		; 18
;		.BYTE   0, $F		; 19
;		.BYTE   2,  1		; 1A
;		.BYTE   2,  2		; 1B
;		.BYTE   2,  3		; 1C
;		.BYTE   2,  4		; 1D
;		.BYTE   2,  5		; 1E
;		.BYTE   1,  8		; 1F
;		.BYTE   2,  7		; 20
;		.BYTE   2,  7		; 21	; unref
;		.BYTE   2,  8		; 22
;		.BYTE   2,  9		; 23
;		.BYTE   2, $A		; 24	; unref
;		.BYTE   2, $B		; 25
;		.BYTE   2, $C		; 26	; unref
;		.BYTE   2, $D		; 27
;		.BYTE   2, $E		; 28
;		.BYTE   2, $F		; 29
;		.BYTE   2,$10		; 2A
;		.BYTE   2,$11		; 2B
;		.BYTE   2,$12		; 2C
;		.BYTE   3,  0		; 2D
;		.BYTE   3,  1		; 2E
;		.BYTE   3,  2		; 2F
;		.BYTE   3,  3		; 30
;		.BYTE   3,  4		; 31
;		.BYTE   3,  5		; 32
;		.BYTE   3,  6		; 33
;		.BYTE   3,  7		; 34
;		.BYTE   3,  8		; 35
;		.BYTE   3,  9		; 36
;		.BYTE   3, $A		; 37
;		.BYTE   3, $B		; 38
;		.BYTE   3, $C		; 39
;		.BYTE   3, $D		; 3A
;		.BYTE   3, $E		; 3B
;		.BYTE   3, $F		; 3C
;		.BYTE   3,$10		; 3D
;		.BYTE   3,$11		; 3E
;		.BYTE   4,  0		; 3F
;		.BYTE   4,  1		; 40
;		.BYTE   4,  2		; 41
;		.BYTE   4,  3		; 42
;		.BYTE   4,  4		; 43
;		.BYTE   4,  5		; 44
;		.BYTE   4,  6		; 45
;		.BYTE   4,  7		; 46
;		.BYTE   4,  8		; 47	; unref
;		.BYTE   4,  9		; 48
;		.BYTE   4, $A		; 49	; unref
;		.BYTE   4, $B		; 4A	; unref
;		.BYTE   4, $C		; 4B	; unref
;		.BYTE   4, $D		; 4C
;		.BYTE   4,$22		; 4D
;		.BYTE   4, $F		; 4E
;		.BYTE   0,$13		; 4F
;		.BYTE   0,  9		; 50
;		.BYTE   1, $E		; 51
;		.BYTE   1, $A		; 52	; unused
;		.BYTE   4,$10		; 53
;		.BYTE   4,$11		; 54
;		.BYTE   4,$12		; 55
;		.BYTE   3,$19		; 56
;		.BYTE   3,$1A		; 57
;		.BYTE   0,$14		; 58
;		.BYTE   3,$12		; 59
;		.BYTE   3,$13		; 5A
;		.BYTE   2,  0		; 5B
;		.BYTE   2,  6		; 5C
;		.BYTE   2, $A		; 5D
;		.BYTE   2, $C		; 5E
;		.BYTE   2,$13		; 5F
;		.BYTE   0,$15		; 60
;		.BYTE   0,$16		; 61
;		.BYTE   0,$17		; 62
;		.BYTE   0,$19		; 63
;		.BYTE   0,$1A		; 64
;		.BYTE   0,$1B		; 65
;		.BYTE   0,$1C		; 66
;		.BYTE   0,$1D		; 67
;		.BYTE   0,$1E		; 68
;		.BYTE   0,$1F		; 69
;		.BYTE   0,$20		; 6A
;		.BYTE   4,$16		; 6B
;		.BYTE   4,$17		; 6C
;		.BYTE   4,$18		; 6D
;		.BYTE   4,$19		; 6E
;		.BYTE   4,$1A		; 6F
;		.BYTE   4,  0		; 70	; unref
;		.BYTE   4,  0		; 71	; unref
;		.BYTE   4,$1B		; 72
;		.BYTE   4,  0		; 73	; unref
;		.BYTE   4,  0		; 74	; unref
;		.BYTE   4,$13		; 75
;		.BYTE   4,$1C		; 76
;		.BYTE   4,$1D		; 77
;		.BYTE   4,$1E		; 78
;		.BYTE   4,$1F		; 79
;		.BYTE   4,$20		; 7A
;		.BYTE   4,$21		; 7B
;		.BYTE   4, $A		; 7C
;		.BYTE   4, $B		; 7D
;		.BYTE   4, $C		; 7E
;		.BYTE $3D,  0		; 7F
;		.BYTE $3D,  1		; 80
;		.BYTE $3D,  2		; 81
;		.BYTE $3D,  3		; 82
;		.BYTE $3D,  4		; 83
;		.BYTE $3D,  5		; 84
;		.BYTE $3D,  6		; 85
;		.BYTE $3D,  7		; 86
;		.BYTE $3D,  8		; 87
;		.BYTE $3D,  9		; 88
;		.BYTE $3D, $A		; 89
;		.BYTE $3D, $B		; 8A
;		.BYTE $3D, $C		; 8B
;		.BYTE $3D, $D		; 8C
;		.BYTE $3D, $E		; 8D
;		.BYTE $3D, $F		; 8E
;		.BYTE $3D,$10		; 8F	; unref
;		.BYTE $3D,$11		; 90	; unref
;		.BYTE $3D,$12		; 91
;		.BYTE $3D,$13		; 92
;		.BYTE $3D,$14		; 93
;		.BYTE $3D,$14		; 94	; unref
;		.BYTE   0,$18		; 95
;		.BYTE   1,  6		; 96
;		.BYTE   1,  7		; 97
;		.BYTE   1, $B		; 98
;		.BYTE   1, $C		; 99
;		.BYTE   3,$16		; 9A
;		.BYTE   3,$17		; 9B
;		.BYTE   4,$15		; 9C
;		.BYTE   2,$14		; 9D
;		.BYTE   4,  8		; 9E
;		.BYTE   4, $E		; 9F
;		.BYTE $3D,$15		; A0
;		.BYTE   1,  9		; A1
;		.BYTE $3D,$16		; A2
;		.BYTE   4,$23		; A3
;		.BYTE $3D,$17		; A4
;		.BYTE $3D,$18		; A5
;		.BYTE   0,  2		; A6

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_load_raw_param_sw:
		ASL
		STA		byte_6
		PLA										; get data ptr (ret addr-1)
		STA		byte_4
		PLA
		STA		byte_5
		JSR		_spr_get_params2
		PHA
		TYA
		PHA
		LDY		byte_6
		LDA		(word_0),Y
		PHA
		INY
		LDA		(word_0),Y
		STA		word_0+1
		PLA
		STA		word_0
		JMP		_spr_load_raw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_load_raw_param:
		PLA										; get data ptr (ret addr-1)
		STA		byte_4
		PLA
		STA		byte_5
		JSR		_spr_get_params2
		PHA
		TYA
		PHA

;-------------S-U-B-R-O-U-T-I-N-E---------------
_spr_load_raw:
		LDX		_spr_buf_pos
		LDY		#0
loc_15D4F3:
		LDA		(word_0),Y
		CMP		#$FF
		BEQ		loc_15D545
		SEC
		SBC		_scroll_y_shadow
		STA		word_2
		LDA		#2
		SBC		_scroll_y_shadow+1
		BCC		loc_15D537
		BNE		loc_15D537
		LDA		word_2
		SEC
		SBC		#1
		STA		_spr_buf,X
		INY
		INX
		LDA		(word_0),Y
		STA		_spr_buf,X
		INY
		INX
		LDA		(word_0),Y
		STA		_spr_buf,X
		INY
		INX
		LDA		(word_0),Y
		SEC
		SBC		_scroll_x_shadow
		STA		word_2
		LDA		#1
		SBC		_scroll_x_shadow+1
		BCC		loc_15D53E
		BNE		loc_15D53E
		LDA		word_2
		STA		_spr_buf,X
		INY
		INX
		JMP		loc_15D4F3
loc_15D537:
		INY
		INY
		INY
		INY
		JMP		loc_15D4F3
loc_15D53E:
		DEX
		DEX
		DEX
		INY
		JMP		loc_15D4F3
loc_15D545:
		STX		_spr_buf_pos
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
; what we have here, is a backup cur idx for password
; it's a leftover from dev stage, sometimes it checks
; manually wether to store the sub idx or not (scene C)
; or hardcoded here as for scene 2, messy, maybe we need
; to fix it somehow.
;
_scene_idx_for_pass_save:
		LDA		_scene_idx						; passwords scene is an exception
		CMP		#$17							; we can't have password to it
		BEQ		locret_15D56A
;		LDA		_scene_idx						; also there is a special case for scene 2
;		CMP		#2								; no need anymore
;		BNE		loc_15D55A
;		LDA		_scene_sub_cur					; when terrorist with grenade about to appear
;		CMP		#_s2_sub17_gym_redraw_nt0_sidx	; we couldn't save pass for this place too
;		BEQ		locret_15D56A
;loc_15D55A:
		LDA		_forbid_sub_cur_backup_trigger	; as well, we can force to forbid save it here
		BNE		loc_15D565						; what a mess goddammit!
		LDA		_scene_sub_cur					; finally, store cur sub idx for pass, b
		STA		_scene_sub_save_pass			; but this is not actual store place for it! it's just backup
		RTS
loc_15D565:
		LDA		#0								; once set, cleared, so set it every time you need
		STA		_forbid_sub_cur_backup_trigger
locret_15D56A:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scroll_reset:
		LDA		#0
		STA		_scroll_x_shadow
		STA		_scroll_x_shadow+1
		STA		_scroll_y_shadow
		STA		_scroll_y_shadow+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
; pal blink modify the palette buf
; as well as fade out sub does this
; if they met, you'll hang forever
;
_pal_blink_animate:
		LDA		_draw_state_idx					; this function used in many places
		CMP		#_draw_sub05_fade_out_sidx		; the fade idx there is different now
		BEQ		loc_8442						; so we must make it universal
		LDA		_frames_counter
		ASL
		AND		#$C
		TAX
		LDA		_pal_blink_list,X
		STA		_pal_buf+$D
		LDA		_pal_blink_list+1,X
		STA		_pal_buf+$E
		LDA		_pal_blink_list+2,X
		STA		_pal_buf+$F
loc_8442:
		RTS

_pal_blink_list:
		.BYTE $20, $F, $F, $F
		.BYTE  $F,$20, $F, $F
		.BYTE  $F, $F,$20, $F
		.BYTE  $F, $F, $F						; only 3 bytes are used for every 4 bytes

;-------------S-U-B-R-O-U-T-I-N-E---------------
; do delay before continue to the next sub
;
_delay:
		STA		_msg_exit_delay_timer
		LDA		#_draw_sub0E_exit_delay_sidx
		STA		_draw_state_idx
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_get_anim_blink_idx:
		LDX		#0
		LDA		_frames_counter
		AND		#$C0
		BNE		loc_15D5B8
		LDA		_frames_counter
		AND		#$3F
		CMP		#7
		BCS		loc_15D5B8
		INX										; used by most of the functions to animate, may be optimized
loc_15D5B8:
		TXA										; used on scene 16 directly, without saving in var
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_do_scene_anim0_pat0101:
		LDX		#0
		.BYTE $2C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_do_scene_anim1_pat0101:
		LDX		#1
		.BYTE $2C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_do_scene_anim2_pat0101:
		LDX		#2
		.BYTE $2C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_do_scene_anim3_pat0101:
		LDX		#3

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_do_scene_anim_pat0101:
		LDA		#<[_anim_pat0101]
		STA		word_0
		LDA		#>[_anim_pat0101]
		STA		word_0+1
		JMP		_do_scene_anim

;-------------S-U-B-R-O-U-T-I-N-E---------------
_do_scene_anim0_pat0121:
		LDX		#0
		.BYTE $2C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_do_scene_anim1_pat0121:
		LDX		#1
		.BYTE $2C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_do_scene_anim2_pat0121:
		LDX		#2
		.BYTE $2C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_do_scene_anim3_pat0121:
		LDX		#3

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_do_scene_anim_pat0121:
		LDA		#<[_anim_pat0121]
		STA		word_0
		LDA		#>[_anim_pat0121]
		STA		word_0+1

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_do_scene_anim:
		LDA		_scene_anim_active,X
		BNE		loc_15D5FC
		LDA		#1
		BNE		loc_15D60D
loc_15D5FC:
		LDA		_frames_counter
		AND		#7
		BNE		locret_15D610
		DEC		_scene_anim_counter,X
		LDA		_scene_anim_counter,X
		AND		#3
		TAY
		LDA		(word_0),Y
loc_15D60D:
		STA		_scene_anim_idx,X
locret_15D610:
		RTS
_anim_pat0121:
		.BYTE   0,  1,  2,  1
_anim_pat0101:
		.BYTE   0,  1,  0,  1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_next_scene:
		INC		_scene_idx
		LDA		#0
		STA		_scene_sub_cur
		STA		_scene_sub_next
		STA		_scene_sub_save_pass
		JMP		_vars_init

;-------------S-U-B-R-O-U-T-I-N-E---------------
_generic_menu_input:
		LDA		_scene_sub_return
		CMP		#$FF
		BEQ		loc_8F5A
		LDA		_pads+1
		AND		#2
		BEQ		loc_8F5A
		LDA		_scene_sub_return
		STA		_scene_sub_next
		JMP		_scene_bg_redraw_request
loc_8F5A:
		JSR		_generic_menu_handler
		LDA		_pads+1
		AND		#1
		BEQ		locret_8F68
		LDA		#4								; make sure, menu handlers has sub idx = 4!
		STA		_scene_sub_next
locret_8F68:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_new_scene:
		LDX		#0								; scene entry always 0!

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_new_scene_ex:
		STA		_scene_idx
		STX		_scene_sub_cur
		STX		_scene_sub_next

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_vars_init:
		JSR		_apu_reset

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene_vars_init:
		LDA		#0
		STA		_spr0_overflow_mode_flag
		STA		_active_areas_list_idx
		STA		_scene_spr_overlay_idx
		STA		_tlm_chr_col_draw_req
		STA		_scroll_x_shadow
		STA		_scroll_x_shadow+1
		TAX
loc_15D679:
		STA		_scene_states,X
		STA		_scene_flags,X
		STA		_scene_anim_idx,X
		STA		_scene_anim_counter,X
		INX
		CPX		#5
		BCC		loc_15D679
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene_menu_init_default1:
		LDA		#1
		.BYTE $2C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene_menu_init_default2:
		LDA		#2
		.BYTE $2C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene_menu_init_default3:
		LDA		#3
		.BYTE $2C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene_menu_init_default4:
		LDA		#4
		.BYTE $2C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene_menu_init_default5:
		LDA		#5
		.BYTE $2C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene_menu_init_default6:
		LDA		#6

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene_menu_init_default:
		STA		word_0

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene_menu_init_default_ex:
		LDX		#0
loc_15D68D:
		TXA
		STA		_scene_menu_items,X
		INX
		CPX		word_0
		BCC		loc_15D68D
		DEX
		STX		_scene_menu_max_pos
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_generic_menu_handler:
		LDA		_scene_idx
		STA		_scene_idx_pass
		LDA		_scene_sub_save_pass			; store current saved pass state
		STA		_scene_sub_idx_pass
		JSR		_debug_force_menu_quit_test
		JSR		_menu_selection_input
		JSR		_menu_cursor_draw
		LDA		_scene_menu_pos
		STA		_cur_scene_menu_pos
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_debug_force_menu_quit_test:
		LDA		_pads+3
		AND		#1
		BEQ		locret_15D6DC
		JSR		_apu_reset
		JSR		_nmi_vars_init
		LDA		#$17
		STA		_scene_idx
		LDA		#_s17_sub10_force_quit_sidx
		STA		_scene_sub_cur
		STA		_scene_sub_next
		LDA		#0
		STA		_scene_spr_overlay_idx
		STA		_draw_state_idx
		STA		_menu_is_drawn_flag
		STA		_scroll_x_shadow
		STA		_scroll_x_shadow+1
locret_15D6DC:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_menu_selection_input:
		LDA		_pads+1
		AND		#$10
		BEQ		loc_15D70E
		LDA		_scene_menu_pos
		BEQ		locret_15D744
		SEC
		SBC		byte_3AB
		CMP		#2
		BCS		loc_15D70A
		LDA		byte_3AB
		BEQ		loc_15D70A
		DEC		byte_3AB
		LDA		#0
		STA		byte_60
		EXJSR	_menu_draw
		LDA		#0
		STA		byte_60
		STA		byte_3B8
		LDA		#_draw_sub10_menu_scroll_up_sidx
		STA		_draw_state_idx
loc_15D70A:
		DEC		_scene_menu_pos
		RTS
loc_15D70E:
		LDA		_pads+1
		AND		#$20
		BEQ		locret_15D744
		LDA		_scene_menu_max_pos
		SEC
		SBC		_scene_menu_pos
		BEQ		locret_15D744
		CMP		#2
		BCC		loc_15D741
		LDA		_scene_menu_pos
		SEC
		SBC		byte_3AB
		CMP		#2
		BCC		loc_15D741
		LDA		#0
		STA		byte_60
		EXJSR	_menu_draw
		LDA		#0
		STA		byte_60
		STA		byte_3B8
		LDA		#_draw_sub11_menu_scroll_down_sidx
		STA		_draw_state_idx
		INC		byte_3AB
loc_15D741:
		INC		_scene_menu_pos
locret_15D744:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_menu_cursor_draw:
		LDA		_scene_menu_pos
		SEC
		SBC		byte_3AB
		TAX
		LDA		byte_15D76F,X
		STA		word_2
		LDA		_scroll_x_shadow
		AND		#$F
		STA		word_2+1
		LDA		#$A8
		SEC
		SBC		word_2+1
		STA		word_2+1
		SPR0EX	_spr_cur_right
		RTS
_spr_cur_right:
		.BYTE   0,$7E,  0,  0
		.BYTE $80
byte_15D76F:
#if LANGUAGE == JP_LANG
;-----------------------------------------------
		.BYTE $30,$40,$50,$60
;-----------------------------------------------
#else
;-----------------------------------------------
		.BYTE $28,$38,$48,$58
;-----------------------------------------------
#endif

;-------------S-U-B-R-O-U-T-I-N-E---------------
_screen_cursor_handler:
		LDA		_active_areas_list_idx
		BEQ		locret_15D79C
		JSR		_screen_cursor_controls
		JSR		_screen_cursor_limits
;		LDA		_frames_counter					; i personally don't like it blinking
;		AND		#$1C
;		BEQ		locret_15D79C
		LDA		_screen_cursor_y
		STA		word_2
		LDA		_screen_cursor_x
		SEC
		SBC		_scroll_x_shadow
		STA		word_2+1
		SPR0EX	_spr_cur_arrow
locret_15D79C:
		RTS
_spr_cur_arrow:
		.BYTE   0,$7D,  0,$FC
		.BYTE $80

;-------------S-U-B-R-O-U-T-I-N-E---------------
_screen_cursor_controls:
		LDA		_pads
		AND		#$10
		BEQ		loc_15D7B2
		LDA		_screen_cursor_y
		SEC
		SBC		#1
		STA		_screen_cursor_y
		RTS
loc_15D7B2:
		LDA		_pads
		AND		#$20
		BEQ		loc_15D7C2
		LDA		_screen_cursor_y
		CLC
		ADC		#1
		STA		_screen_cursor_y
		RTS
loc_15D7C2:
		LDA		_pads
		AND		#$40
		BEQ		loc_15D7DA
		LDA		_screen_cursor_x
		SEC
		SBC		#1
		STA		_screen_cursor_x
		LDA		_screen_cursor_x+1
		SBC		#0
		STA		_screen_cursor_x+1
		RTS
loc_15D7DA:
		LDA		_pads
		AND		#$80
		BEQ		locret_15D7F1
		LDA		_screen_cursor_x
		CLC
		ADC		#1
		STA		_screen_cursor_x
		LDA		_screen_cursor_x+1
		ADC		#0
		STA		_screen_cursor_x+1
locret_15D7F1:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_screen_cursor_limits:
		LDX		#$10
		LDA		_scene_idx
		CMP		#$F
		BEQ		loc_15D803
		LDX		#0
		LDA		byte_350
		BEQ		loc_15D803
		LDX		#8
loc_15D803:
		LDA		_pads
		AND		#$10
		BEQ		loc_15D819
		LDA		_screen_cursor_y
		SEC
		SBC		_scr_cur_limits_list,X
		BCS		locret_15D878
		LDA		_scr_cur_limits_list,X
		STA		_screen_cursor_y
		RTS
loc_15D819:
		LDA		_pads
		AND		#$20
		BEQ		loc_15D82F
		LDA		_screen_cursor_y
		SEC
		SBC		_scr_cur_limits_list+2,X
		BCC		locret_15D878
		LDA		_scr_cur_limits_list+2,X
		STA		_screen_cursor_y
		RTS
loc_15D82F:
		LDA		_scene_idx
		CMP		#$A
		BEQ		locret_15D878
		LDA		_pads
		AND		#$40
		BEQ		loc_15D857
		LDA		_screen_cursor_x
		SEC
		SBC		_scr_cur_limits_list+4,X
		LDA		_screen_cursor_x+1
		SBC		_scr_cur_limits_list+5,X
		BCS		locret_15D878
		LDA		_scr_cur_limits_list+4,X
		STA		_screen_cursor_x
		LDA		_scr_cur_limits_list+5,X
		STA		_screen_cursor_x+1
		RTS
loc_15D857:
		LDA		_pads
		AND		#$80
		BEQ		locret_15D878
		LDA		_screen_cursor_x
		SEC
		SBC		_scr_cur_limits_list+6,X
		LDA		_screen_cursor_x+1
		SBC		_scr_cur_limits_list+7,X
		BCC		locret_15D878
		LDA		_scr_cur_limits_list+6,X
		STA		_screen_cursor_x
		LDA		_scr_cur_limits_list+7,X
		STA		_screen_cursor_x+1
locret_15D878:
		RTS
_scr_cur_limits_list:
		.WORD $10,$78,  8,$F8
		.WORD $10,$68,$40,$C0
		.WORD $10,$78,  8,$1F8

;-------------S-U-B-R-O-U-T-I-N-E---------------
_menu_draw_msg_modeF:
		LDA		#0
		STA		byte_60
		STA		_scene_menu_pos
		STA		byte_3AB
		EXJSR	_menu_draw
		LDA		#_draw_sub0F_menu_items_fill_sidx
		STA		_draw_state_idx
		LDA		#0
		STA		byte_60
		STA		byte_3B8
		STA		_nmi_ppu_draw0_req
		STA		_scene_menu_pos
		STA		byte_3AB
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene_bg_redraw_request:
		LDA		#1
		STA		_nmi_ppu_draw0_req
;		LDA		#0
;		STA		_unused_var0
		LDA		#2
		STA		_menu_is_drawn_flag
		LDA		#$A
		STA		byte_40
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
;_unused9:
;		LDA		#1
;		STA		byte_34B
;		JMP		_unused0

;-------------S-U-B-R-O-U-T-I-N-E---------------
;_unused8:
;		LDA		#2
;		STA		byte_34B

;-------------S-U-B-R-O-U-T-I-N-E---------------
;_unused0:
;		LDA		#_draw_sub0D_menu_draw_sidx
;		STA		_draw_state_idx
;		LDA		#0
;		STA		byte_47
;		LDA		#1
;		STA		_unused_var0
;		JMP		sub_15D912

;-------------S-U-B-R-O-U-T-I-N-E---------------
_menu_draw_request:
		LDA		#_draw_sub0D_menu_draw_sidx
		STA		_draw_state_idx
		LDA		#0
		STA		byte_47
;		STA		_unused_var0
		STA		_scene_menu_pos
		STA		byte_34B
		STA		byte_3AB
sub_15D912:
		LDA		_scroll_x_shadow
		CLC
		ADC		#$A0
		STA		word_0
		LDA		_scroll_x_shadow+1
		ADC		#0
		LSR
		LDX		#$23
		BCC		loc_15D924
		LDX		#$27
loc_15D924:
		LDA		word_0
		LSR
		LSR
		LSR
		LSR
		LSR
		CLC
		ADC		#$C8
		STA		_menu_attr_backup_line0_lo_ofs
		STX		_menu_attr_backup_line0_hi_ofs
		LDA		_menu_attr_backup_line0_lo_ofs
		CLC
		ADC		#8
		STA		_menu_attr_backup_line1_lo_ofs
		LDA		_menu_attr_backup_line0_hi_ofs
		ADC		#0
		STA		_menu_attr_backup_line1_hi_ofs
		LDA		_menu_attr_backup_line0_lo_ofs
		CLC
		ADC		#$10
		STA		_menu_attr_backup_line2_lo_ofs
		LDA		_menu_attr_backup_line0_hi_ofs
		ADC		#0
		STA		_menu_attr_backup_line2_hi_ofs
		LDA		_menu_attr_backup_line0_hi_ofs
		AND		#$FB
		STA		word_0
		LDA		_menu_attr_backup_line0_hi_ofs
		EOR		#4
		ORA		word_0
		STA		_menu_attr_backup_line0_A_ofs
		LDA		_menu_attr_backup_line1_hi_ofs
		AND		#$FB
		STA		word_0
		LDA		_menu_attr_backup_line1_hi_ofs
		EOR		#4
		ORA		word_0
		STA		_menu_attr_backup_line1_A_ofs
		LDA		_menu_attr_backup_line2_hi_ofs
		AND		#$FB
		STA		word_0
		LDA		_menu_attr_backup_line2_hi_ofs
		EOR		#4
		ORA		word_0
		STA		_menu_attr_backup_line2_A_ofs
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
;_unused1:
;		LDA		#7
;		STA		_message_state_id
;		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
; setup CHR/PAL parameters, X is CHR idx
; Y is PAL idx
;
_chr_pal_setup:
		PHA
		TYA
		PHA
		TXA
		JSR		_chr_lib_banks_load
		PLA
		JSR		_pal_lib_load
		PLA
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_nt0_draw_mode4_chrpal_load:
		JSR		_chr_pal_setup
		LDX		#$20
		BNE		_tlm_draw_mode4_ex

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_nt1_draw_mode4:
		LDX		#$24

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_draw_mode4_ex:
		STA		_menu_restore_tlm_idx_list
		STA		_menu_restore_tlm_idx_list+1
;		STA		byte_5C							; unused var
		STX		_tlm_tmp_line_dst+1
		JSR		_tlm_get_index_by_number
		JSR		_scene_idx_for_pass_save
		LDA		#$40
		STA		_tlm_tmp_line_dst
		LDA		#0
		STA		_nmi_ppu_draw_counter
		STA		byte_350
		LDA		#4
		STA		_nmi_ppu_tlm_draw_req
		LDA		#_draw_sub08_tlm4_draw_sidx
		STA		_draw_state_idx
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_draw_mode5_chrpal_load:
		STA		_tlm_draw_cur_lib_idx
		JSR		_chr_pal_setup
		JSR		_tlm_get_index_by_number
		JSR		_scene_idx_for_pass_save
		LDA		#$40
		STA		_tlm_tmp_line_dst
		LDA		#$20
		STA		_tlm_tmp_line_dst+1
		LDA		#0
		STA		_nmi_ppu_draw_counter
		LDA		#5
		STA		_nmi_ppu_tlm_draw_req
		LDA		#2
		STA		byte_350
		LDA		#_draw_sub08_tlm4_draw_sidx
		STA		_draw_state_idx
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_tlm_draw_mode6_chrpal_load:
		STA		_tlm_draw_cur_lib_idx
		JSR		_chr_pal_setup
		JSR		_tlm_get_index_by_number
		LDA		#$42
		STA		_tlm_tmp_line_dst
		LDA		#$20
		STA		_tlm_tmp_line_dst+1
		LDA		#0
		STA		_nmi_ppu_draw_counter
		LDA		#6
		STA		_nmi_ppu_tlm_draw_req
		LDA		#2
		STA		byte_350
		LDA		#_draw_sub08_tlm4_draw_sidx
		STA		_draw_state_idx
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_clear_nt0:
		JSR		_scene_idx_for_pass_save
		LDA		#$FF
		STA		byte_350
		LDA		#0
		STA		_nmi_ppu_draw_counter
		LDA		#_draw_sub06_nt0_draw_area_clear_sidx
		STA		_draw_state_idx
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_clear_nt1:
		JSR		_scene_idx_for_pass_save
		LDA		#$FF
		STA		byte_350
		LDA		#0
		STA		_nmi_ppu_draw_counter
		LDA		#_draw_sub0C_nt1_draw_area_clear_sidx
		STA		_draw_state_idx
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_icon0_draw:
		JSR		_chr_pal_setup
		TAX
		LDA		#0
		BEQ		_icon_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_icon1_draw:
		JSR		_chr_pal_setup
		TAX
		LDA		#1
		BNE		_icon_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_icon2_draw:
		JSR		_chr_pal_setup
		TAX
		LDA		#2

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_icon_draw:
		STA		_icon_position_idx
		STX		_icon_tlm_idx
		CMP		#2
		BNE		loc_15DA53
		STX		_tlm_draw_cur_lib_idx
		LDA		#1
		STA		byte_350
loc_15DA53:
		LDA		_icon_position_idx
		ASL
		TAX
		LDA		_icon_dst_list,X
		STA		_icon_col_dst
		LDA		_icon_dst_list+1,X
		STA		_icon_col_dst+1
		LDA		_icon_tlm_idx
		JSR		_tlm_get_index_by_number
		LDA		#1
		STA		_nmi_ppu_icon_draw_req
		LDA		#0
		STA		_icon_cur_col_pos
		LDA		#_draw_sub09_icon_sidx
		STA		_draw_state_idx				; set up drawing poll routine

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
; this is an actual icon drawing poll
;
_draw_sub09_icon:
		LDA		_icon_cur_col_pos
		CMP		#$A
		BCC		locret_15DA8C
		JSR		_icon_attr_queue
		LDA		#0
		STA		_nmi_ppu_icon_draw_req
		STA		_icon_cur_col_pos
		STA		_draw_state_idx
		LDA		_scene_sub_next
		STA		_scene_sub_cur
locret_15DA8C:
		RTS
_icon_dst_list:
		.WORD $2042
		.WORD $210C
		.WORD $2056

;-------------S-U-B-R-O-U-T-I-N-E---------------
_icon_attr_queue:
		LDA		#<[_icon_col_buf]
		STA		word_0
		LDA		#>[_icon_col_buf]
		STA		word_0+1
		LDA		#$C0
		STA		_ppu_tmp_buf1_dst
		LDA		#$23
		STA		_ppu_tmp_buf1_dst+1
		LDA		_icon_position_idx
		ASL
		TAX
		LDA		_icon_attr_ofs_list,X
		STA		word_2
		LDA		_icon_attr_ofs_list+1,X
		STA		word_2+1
		JMP		(word_2)
_icon_attr_ofs_list:
		.WORD _icon_attr_queue_sub0
		.WORD _icon_attr_queue_sub1
		.WORD _icon_attr_queue_sub2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_icon_attr_queue_sub0:
		LDX		#0
		JSR		_attr_and
		LDY		#0
		LDX		#0
		JSR		_attr_or
		INY
		LDX		#1
		JSR		_attr_or
		INY
		LDX		#8
		JSR		_attr_or
		INY
		LDX		#9
		JMP		_attr_or

;-------------S-U-B-R-O-U-T-I-N-E---------------
_icon_attr_queue_sub1:
		LDY		#0
		LDA		(word_0),Y
		STA		_ppu_tmp_buf1+$13
		INY
		LDA		(word_0),Y
		STA		_ppu_tmp_buf1+$14
		INY
		LDA		(word_0),Y
		STA		_ppu_tmp_buf1+$1B
		INY
		LDA		(word_0),Y
		STA		_ppu_tmp_buf1+$1C
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_icon_attr_queue_sub2:
		LDX		#5
		JSR		_attr_and
		LDY		#0
		LDX		#5
		JSR		_attr_or
		INY
		LDX		#6
		JSR		_attr_or
		INY
		LDX		#$D
		JSR		_attr_or
		INY
		LDX		#$E
		JMP		_attr_or

;-------------S-U-B-R-O-U-T-I-N-E---------------
_attr_and:
		LDA		_ppu_tmp_buf1,X
		AND		#$3F
		STA		_ppu_tmp_buf1,X
		LDA		_ppu_tmp_buf1+1,X
		AND		#$F
		STA		_ppu_tmp_buf1+1,X
		LDA		_ppu_tmp_buf1+2,X
		AND		#$CF
		STA		_ppu_tmp_buf1+2,X
		LDA		_ppu_tmp_buf1+8,X
		AND		#$33
		STA		_ppu_tmp_buf1+8,X
		LDA		_ppu_tmp_buf1+9,X
		AND		#0
		STA		_ppu_tmp_buf1+9,X
		LDA		_ppu_tmp_buf1+$A,X
		AND		#$CC
		STA		_ppu_tmp_buf1+$A,X
		LDA		_ppu_tmp_buf1+$10,X
		AND		#$F3
		STA		_ppu_tmp_buf1+$10,X
		LDA		_ppu_tmp_buf1+$11,X
		AND		#$F0
		STA		_ppu_tmp_buf1+$11,X
		LDA		_ppu_tmp_buf1+$12,X
		AND		#$FC
		STA		_ppu_tmp_buf1+$12,X
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_attr_or:
		LDA		(word_0),Y
		ROR
		ROR
		ROR
		AND		#$C0
		ORA		_ppu_tmp_buf1,X
		STA		_ppu_tmp_buf1,X
		LDA		(word_0),Y
		ASL
		ASL
		AND		#$30
		ORA		_ppu_tmp_buf1+1,X
		STA		_ppu_tmp_buf1+1,X
		LDA		(word_0),Y
		LSR
		LSR
		AND		#$C
		ORA		_ppu_tmp_buf1+8,X
		STA		_ppu_tmp_buf1+8,X
		LDA		(word_0),Y
		ROL
		ROL
		ROL
		AND		#3
		ORA		_ppu_tmp_buf1+9,X
		STA		_ppu_tmp_buf1+9,X
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
;_unref_52:
;		LDX		#0
;		LDA		_tlm_ptr+1
;		STA		_PPU_ADDR
;		LDA		_tlm_ptr
;		STA		_PPU_ADDR
;		LDA		_PPU_DATA
;loc_15DBC6:
;		LDA		_PPU_DATA
;		STA		_menu_wnd_row_buf0,X
;		INX
;		CPX		#$A
;		BCC		loc_15DBC6
;		LDA		_tlm_ptr
;		SEC
;		SBC		#$20
;		STA		_tlm_ptr
;		LDA		_tlm_ptr+1
;		SBC		#0
;		STA		_tlm_ptr+1
;		LDA		word_320+1
;		STA		_PPU_ADDR
;		LDA		word_320
;		STA		_PPU_ADDR
;		LDX		#0
;loc_15DBF0:
;		LDA		_menu_wnd_row_buf0,X
;		STA		_PPU_DATA
;		INX
;		CPX		#$A
;		BCC		loc_15DBF0
;		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
;_unsed2:
;		LDA		#_draw_sub04_break_sidx
;		STA		_draw_state_idx
;		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_fade_out_reload_scene:
		LDA		_scene_sub_reload
		STA		_scene_sub_next

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_fade_out_reqest:
		LDA		#_draw_sub05_fade_out_sidx
		STA		_draw_state_idx
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_msg_single_load_param:
		PLA
		STA		word_0
		PLA
		STA		word_0+1
		LDY		#1
		LDA		(word_0),Y
		STA		_cur_msg_list_buf
		LDA		#_eol
		STA		_cur_msg_list_buf+1
		BNE		_msg_list_load_ex

;-------------S-U-B-R-O-U-T-I-N-E---------------
_msg_list_load_param:
		PLA
		STA		word_0
		PLA
		STA		word_0+1
		INC		word_0
		BNE		loc_15DC1B
		INC		word_0+1
loc_15DC1B:
		LDY		#0
loc_15DC1C:
		LDA		(word_0),Y
		STA		_cur_msg_list_buf,Y
		INY
		CMP		#$FF
		BNE		loc_15DC1C

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_msg_list_load_ex:
		LDX		#0
		LDA		_cur_msg_list_buf,X
		INX
		STX		_cur_msg_list_buf_pos

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
; caution! it's polling from display routines
;
_cur_msg_load:
		STA		_cur_msg_idx
		JSR		_get_msg_block_prg_and_idx
		ASL
		TAX
		LDA		$A000,X
		STA		word_0
		LDA		$A001,X
		STA		word_0+1
		LDA		#0
		STA		word_2
		LDA		_cur_msg_idx
		CMP		#$70
		BCC		loc_15DC78
		SEC
		SBC		#$70
loc_15DC78:
		ASL
		ROL		word_2
		CLC
		ADC		word_0
		STA		word_0
		LDA		word_2
		ADC		word_0+1
		STA		word_0+1
		LDY		#0
		LDA		(word_0),Y
		STA		_cur_msg_ptr
		INY
		LDA		(word_0),Y
		STA		_cur_msg_ptr+1
		LDA		#0
		STA		_cur_msg_col
		STA		_cur_msg_row
		STA		_cur_msg_pos
		STA		_cur_msg_pos+1
		STA		_dictionary_str_idx
		STA		_type_fastforward
		STA		byte_47
		LDA		#_draw_sub03_type_init_sidx
		STA		_draw_state_idx
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_msg_wnd_clear_request:
		LDA		#0
		STA		_cur_msg_col
		STA		_cur_msg_row
		STA		byte_47
		LDA		#_draw_sub0A_msg_area_clear_sidx
		STA		_draw_state_idx
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_do_frames_counter:
		INC		_frames_counter
		BNE		locret_15DCBE
		INC		_frames_counter+1
locret_15DCBE:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_game_over_prison_start:
		LDA		#_s17_sub0E_game_over_prison_sidx
		BNE		_game_over_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_game_over_dead_start:
		LDA		#_s17_sub0F_game_over_dead_sidx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_game_over_start:
		STX		_retry_scene_idx				; if you choose to retry the game, you'll be
		STY		_retry_scene_sub_cur			; returning to selected scene/sub
		STA		_scene_sub_cur
		STA		_scene_sub_next
		LDA		#$17							; scene for passwords (17)
		STA		_scene_idx
		JMP		_apu_reset

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sgame_cursor_input:
		LDA		_pads
		AND		#$10
		BEQ		loc_15DCFF
		LDA		_tmp_y_pos
		SEC
		SBC		#4
		CMP		#$18
		BCS		loc_15DCF9
		LDA		#$18
loc_15DCF9:
		STA		_tmp_y_pos
		JMP		loc_15DD14
loc_15DCFF:
		LDA		_pads
		AND		#$20
		BEQ		loc_15DD14
		LDA		_tmp_y_pos
		CLC
		ADC		#4
		CMP		#$78
		BCC		loc_15DD11
		LDA		#$78
loc_15DD11:
		STA		_tmp_y_pos
loc_15DD14:
		LDA		_pads
		AND		#$40
		BEQ		loc_15DD2C
		LDA		_tmp_x_pos
		SEC
		SBC		#4
		CMP		#8
		BCS		loc_15DD26
		LDA		#8
loc_15DD26:
		STA		_tmp_x_pos
		RTS
loc_15DD2C:
		LDA		_pads
		AND		#$80
		BEQ		locret_15DD41
		LDA		_tmp_x_pos
		CLC
		ADC		#4
		CMP		#$F8
		BCC		loc_15DD3E
		LDA		#$F8
loc_15DD3E:
		STA		_tmp_x_pos
locret_15DD41:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sgame_kaneda_bullet_handler:
		LDA		_sgame_kaneda_bullet_active		; one bullet at time
		BNE		loc_15DD59
		LDA		_sgame_shoot_enable				; forbid shooting
		LSR
		BCC		loc_15DD59
		LDA		_pads+1							; if head is on the screen, shooting enabled
		AND		#1
		BEQ		locret_15DD62
		INC		_scene_states					; bullets counter
		JMP		_sgame_kaneda_bullet_start
loc_15DD59:
		JSR		_sgame_kaneda_bullet_move_x
		LDA		_sgame_kaneda_bullet_dir_y
		SEC
		SBC		_sgame_kaneda_bullet_delta_y
		STA		_sgame_kaneda_bullet_dir_y
		LDA		_sgame_kaneda_bullet_dir_y+1
		SBC		_sgame_kaneda_bullet_delta_y+1
		STA		_sgame_kaneda_bullet_dir_y+1
		CMP		_sgame_kaneda_bullet_y_dst
		BCS		locret_15DDD6
		LDA		#0
		STA		_sgame_kaneda_bullet_active
locret_15DDD6:
;		LDA		#0
;		STA		_scene_anim_idx+3
		JSR		_sgame_kaneda_bullet_spr_animate
		LDA		_sgame_kaneda_bullet_dir_x+1
		STA		_sgame_kaneda_bullet_x_pos
		LDA		_sgame_kaneda_bullet_dir_y+1
		STA		_sgame_kaneda_bullet_y_pos
		RTS
locret_15DD62:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sgame_kaneda_bullet_spr_animate:				; unref function with kaneda bullet timer
		LDA		_frames_counter					; never used in final game
		AND		#1
;		BNE		locret_15DD85
		CLC
		ADC		_sgame_kaneda_bullet_timer		; simplify
;		CLC
;		ADC		#1
		STA		_sgame_kaneda_bullet_timer
;		CMP		#$20
;		BCC		locret_15DD85
;		LDA		#0
;		STA		_sgame_kaneda_bullet_active		; no need here, value is too much
locret_15DD85:
		LDX		#1								; also there weren't bullet scaling at all
		LDA		_sgame_kaneda_bullet_timer		; scale enemy bullet now
		CMP		#4								; total clocks for bullet is 13
		BCC		.34343
		DEX
.34343:
		STX		_scene_anim_idx+3
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sgame_kaneda_bullet_move_x:
		LDA		_sgame_kaneda_bullet_delta_x+1
		BPL		loc_15DDA2
		AND		#$7F
		STA		word_0
		LDA		_sgame_kaneda_bullet_dir_x
		CLC
		ADC		_sgame_kaneda_bullet_delta_x
		STA		_sgame_kaneda_bullet_dir_x
		LDA		_sgame_kaneda_bullet_dir_x+1
		ADC		word_0
		STA		_sgame_kaneda_bullet_dir_x+1
		RTS
loc_15DDA2:
		AND		#$7F
		STA		word_0
		LDA		_sgame_kaneda_bullet_dir_x
		SEC
		SBC		_sgame_kaneda_bullet_delta_x
		STA		_sgame_kaneda_bullet_dir_x
		LDA		_sgame_kaneda_bullet_dir_x+1
		SBC		word_0
		STA		_sgame_kaneda_bullet_dir_x+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sgame_kaneda_bullet_start:
		INC		_sgame_kaneda_bullet_active
		LDA		#$80
		STA		_sgame_kaneda_bullet_dir_x+1
		STA		_sgame_kaneda_bullet_dir_y+1
		LDA		#0
;		STA		byte_535						; unused
;		STA		byte_53B
;		STA		byte_538
		STA		_sgame_kaneda_bullet_timer		; reused
		LDA		_tmp_y_pos
		STA		_sgame_kaneda_bullet_y_dst		; dst_y = cursor x pos
		LDA		_tmp_x_pos
		BMI		loc_15DE19
		LDA		#$80
		SEC
		SBC		_tmp_x_pos
		JMP		loc_15DE1C
loc_15DE19:
		SEC
		SBC		#$80
loc_15DE1C:
		STA		word_2
		LDA		#0
		STA		word_0+1
		LDA		#$18
		STA		word_2+1
		LDA		#0
		STA		byte_4
		JSR		_div16
		LDA		word_0+1
		STA		_sgame_kaneda_bullet_delta_x	; delta_x = (128-cursor_x)/24 (fixed point 8.8!)
		LDA		_tmp_x_pos
		AND		#$80
		ORA		word_2
		STA		_sgame_kaneda_bullet_delta_x+1
		LDA		#$80
		SEC
		SBC		_tmp_y_pos
		STA		word_2
		LDA		#0
		STA		word_0+1
		LDA		#$18
		STA		word_2+1
		LDA		#0
		STA		byte_4
		JSR		_div16
		LDA		word_0+1
		STA		_sgame_kaneda_bullet_delta_y	; delta_y = (128-cursor_y)/24 (fixed point 8.8!)
		LDA		word_2
		STA		_sgame_kaneda_bullet_delta_y+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_chr_lib_banks_load:
;		STA		_tmp_idxF						; redundant
		STA		word_0
		LDX		#0
		STX		word_0+1
		ASL
		ASL		word_0
		ROL		word_0+1
		ASL		word_0
		ROL		word_0+1
		CLC
		ADC		word_0
		STA		word_0
		LDA		word_0+1
		ADC		#0
		STA		word_0+1
		LDA		#<[_chr_banks_lib]
		CLC
		ADC		word_0
		STA		word_0
		LDA		#>[_chr_banks_lib]
		ADC		word_0+1
		STA		word_0+1
		LDY		#0
loc_15DE8A:
		LDA		(word_0),Y
		STA		_chr_bank4,Y
		INY
		CPY		#4
		BCC		loc_15DE8A
		LDA		(word_0),Y
		STA		_chr_bank01
		INY
		LDA		(word_0),Y
		STA		_chr_bank23
		RTS
_chr_banks_lib:
		.BYTE $10,$11, $E, $F,  2,  9	; 00
		.BYTE $10,$11, $E, $F,  2,  9
		.BYTE   0,  1,$16,$17,  2,$17
		.BYTE   0,  1,$14,$15,  2,  9
		.BYTE   0,  1,  0,$17,  2,  0
		.BYTE   0,  1,$1A,$1B,  2, $E
		.BYTE   0,  1,$18,  0,  2, $C
		.BYTE   0,  1,$20,$21,  2,$12
		.BYTE   0,  1,$22,$23,  2,$12
		.BYTE   0,  1,$B2,$B3,  2,$5A
		.BYTE   0,  1,$30,$31,  2,  0
		.BYTE   0,  1,$30,$31,  2,  0
		.BYTE   0,  1,$32,$33,  2,$5A
		.BYTE   0,  1,$34,$35,  2,$1B
		.BYTE   0,  1,$A8,$A9,  2,  4
		.BYTE   0,  1,$1A,$1B,  2, $C
		.BYTE   0,  1,$1E,$1F,  2, $E	; 10
		.BYTE   0,  1,$26,$27,  2,$17
		.BYTE   0,  1,$28,$29,  2,$17
		.BYTE   0,  1,$2A,$2B,  2,$17
		.BYTE   0,  1,$2C,$2D,  2,$17
		.BYTE   0,  1,$B0,$B1,  2,$5D
		.BYTE   0,  1,$34,$35,  2,$5F
		.BYTE   0,  1,  2,  3,  2,  0
		.BYTE   0,  1,$3A,$3B,  2,$1F
		.BYTE   0,  1,$3A,$3B,  2,$45
		.BYTE   0,  1,$3C,$3D,  2,  0
		.BYTE   0,  1,$46,$47,  2,$24
		.BYTE   0,  1,$40,$41,  2,$24
		.BYTE   0,  1,$42,$43,  2,$5A
		.BYTE   0,  1,$44,$45,  2,  4
		.BYTE   0,  1,$4E,$4F,  2,  0
		.BYTE   0,  1,$50,$51,  2,  0	; 20
		.BYTE   0,  1,$56,$57,  2,  0
		.BYTE   0,  1,$58,$59,  2,  0
		.BYTE   0,  1,$B6,$B7,  2,$2B
		.BYTE   0,  1,$5A,$5B,  2,  0
		.BYTE   0,  1,$5C,$5D,  2,  0
		.BYTE   0,  1,$62,$63,  2,  0
		.BYTE   0,  1,$64,$65,  2,$5C
		.BYTE   0,  1,$66,$67,  2,$5C
		.BYTE   0,  1,$B8,$B9,  2,$5C
		.BYTE   0,  1,$68,$69,  2,$1B
		.BYTE   0,  1,$6E,$6F,  2,$37
		.BYTE   0,  1,$6C,$6D,  2,  0
		.BYTE   0,  1,$44,$45,  2,$24
		.BYTE   0,  1,$4A,$4B,  2,$26
		.BYTE   0,  1,$4C,$4D,  2,$26
		.BYTE   0,  1,$AA,$AB,  2,  0	; 30
		.BYTE   0,  1,$AC,$AD,  2,  0
		.BYTE   0,  1,$AE,$AF,  2,$12
		.BYTE   0,  1,$40,$41,  2,$5A
		.BYTE   0,  1,$52,$53,  2,$2A
		.BYTE   0,  1,$54,$55,  2,$2A
		.BYTE   0,  1,$70,$71,  2,$38
		.BYTE   0,  1,$72,$73,  2,  0
		.BYTE   0,  1,$74,$75,  2,$12
		.BYTE   0,  1,$76,$77,  2,$56
		.BYTE   0,  1,$78,$79,  2,$5D
		.BYTE   0,  1,$7A,$7B,  2,$40
		.BYTE   0,  1,$7C,$7D,  2,$40
		.BYTE   0,  1,$7A,$7B,  2,$40
		.BYTE   0,  1,$7E,$7F,  2,$40
		.BYTE   0,  1,$82,$83,  2,$30
		.BYTE   0,  1,$88,$89,  2,$44	; 40
		.BYTE   0,  1,$38,$39,  2,$45
		.BYTE   0,  1,$8C,$8D,  2,$5F
		.BYTE   0,  1,  2,  3,  2,  0
		.BYTE   0,  1,$90,$91,  2,$42
		.BYTE   0,  1,$92,$93,  2,$49
		.BYTE   0,  1,$6A,$6B,  2,$44
		.BYTE   0,  1,  0,  0,  2,$44	; -unused-
		.BYTE   0,  1,$84,$85,  2,$44
		.BYTE   0,  1,$94,$95,  2,$4B
		.BYTE   0,  1,$96,$97,  2,  0
		.BYTE   0,  1,$98,$99,  2,$1F
		.BYTE   0,  1,$9A,$9B,  2,  0
		.BYTE   0,  1,$9C,$9D,  2,  0
		.BYTE   0,  1,$9C,$9D,  2,  0
		.BYTE   0,  1,$A0,$A1,  2,$5D
		.BYTE   0,  1,$A2,$A3,  2,$79	; 50
		.BYTE   0,  1,$86,$87,  2,  0	; -unused-
		.BYTE   0,  1,$A6,$A7,  2,  0	; -unused-
		.BYTE   0,  1,$A4,$A5,  2,  0
		.BYTE   0,  1,$86,$87,  2,$29
		.BYTE   0,  1,$5E,$5F,  2,$30
		.BYTE   0,  1,  0,  0,  2,  0	; -unused-
		.BYTE   0,  1,$8A,$8B,  2,$35
		.BYTE   0,  1,$FE,$FF,  2,$7F
		.BYTE   0,  1,$FE,$FF,  2,$7F
		.BYTE   0,  1,$F8,$F9,  2,$7C
		.BYTE   0,  1,$F8,$F9,  2,$7C
		.BYTE   0,  1,$FA,$FB,  2,$7D
		.BYTE   0,  1,$FC,$FD,  2,$7E
		.BYTE   0,  1,$FC,$FD,  2,$7E
		.BYTE   0,  1,$7E,$7F,  2,$40
		.BYTE $F4,$F5,$F6,$F7,  2,  0	; 60
		.BYTE $E8,$E9,$EA,$EB,  2,$55
		.BYTE $EC,$ED,$EE,$EF,$76,$77
		.BYTE $F0,$F1,$F2,$F3,$78,$79
		.BYTE   0,  1,$9E,$9F,  2,$4F
		.BYTE   0,  1,$A6,$A7,  2,$2F
		.BYTE   0,  1,  0,  0,  2,  0	; -unused-
		.BYTE   4,  5,  6,  7,  2,  0
		.BYTE   0,  1,$8A,$8B,  2,$1B
		.BYTE   0,  1,$8E,$8F,  2,  0
		.BYTE   0,  1,$87,$87,  2,$45
		.BYTE   0,  1,$3A,$3B,  2,$34
		.BYTE   0,  1,$28,$29,  2,$37
		.BYTE   0,  1,$40,$41,  2,$36
		.BYTE   0,  1,$38,$39,  2,$1C
		.BYTE   0,  1,$BC,$BD,  2,$2F
		.BYTE  $A, $B, $C, $D,  0,  4	; 70
		.BYTE   0,  1,$8E,$8F,  2,$35

;-------------S-U-B-R-O-U-T-I-N-E---------------
_pal_lib_load:
		LDX		#0
		STX		word_0+1
		ASL
		ROL		word_0+1
		ASL
		ROL		word_0+1
		ASL
		ROL		word_0+1
		STA		word_2
		LDA		word_0+1
		STA		word_2+1						; word_1 = A * 8
		LDA		word_2
		ASL
		ROL		word_0+1						; A/word_0+1 = A * 16
		CLC
		ADC		word_2
		STA		word_0
		LDA		word_0+1
		ADC		word_2+1
		STA		word_0+1						; word_0 = A * 24
		LDA		word_0
		CLC
		ADC		#<[_pal_lib]
		STA		word_0
		LDA		word_0+1
		ADC		#>[_pal_lib]
		STA		word_0+1
		LDY		#0
		LDX		#0
loc_17A16C:
		LDA		#$F
		STA		_pal_buf,X
		INX
		LDA		(word_0),Y
		STA		_pal_buf,X
		INY
		INX
		LDA		(word_0),Y
		STA		_pal_buf,X
		INY
		INX
		LDA		(word_0),Y
		STA		_pal_buf,X
		INY
		INX
		CPX		#$20
		BCC		loc_17A16C
		RTS

_pal_lib:
		.BYTE $20,$2C, $F,$20,$36,$16,$20,$31,$16,$13,$1C, $C,$20,$16,$11,$20,$31, $C,$20,$36,$16,  0,  0,  0
		.BYTE $20,$2C, $F,$32,$22,$20,$32,$38,$27,$38,$26,$27,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$36, $C,$20,$36,$16,$20,$2C,$1C,$20,$16,$11, $C,$36, $F,$20,$36, $F,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$36,$26,$1C,$36,  6,$20,$1C,  6,$20,$16, $F,$20,$26, $F,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$36,$26,$20,  6,  0,$20,$36,  0,$20,$16,$11,$20,$36, $F, $C,$36, $F,$36, $C, $F
		.BYTE $20,$2C, $F,$20,$36,$26,$17,$36,$26,  0,  0,  0,$20,$16,$11,$20,$36, $F,$20,$10, $F,$20,$26, $F
		.BYTE $20,$2C, $F,$36,$20,$1C,$36,  6,$1C,$20,$10,  0,$20,$16,$11,$36,$1C, $F,  6,$1C, $F,$20,$36, $F
		.BYTE $20,$2C, $F,$11,$20,$16,$11,$20,$36,  0,  0,  0,$20,$16,$11,$20,$36, $F,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$16,$1C,$20,$36,$16,$20,$36,$1C,$20,$16,$11,$20,$36, $F,$16,$36, $F,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$31,$1C,$20,$16,$1C,  0,  0,  0,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$31,$1C,$20,$36,$1C,$20,$36,$16,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$37,  6,$1C,$37,$20,$1C,$36,  6,$1C,$20,$16,$11,$20,$36, $F,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$31,$20,$36,$31,$20,$10,$31,$37,$10,$20,$16,$11,$20,$27, $F,$20,$36, $F,  0,  0,  0
		.BYTE $20,$2C, $F,$31,$1C, $C,$37,$26,$2C,$2C,$1C, $C,$20,$16,$11,$31,$17, $F,$20,$28, $F,  0,  0,  0
		.BYTE $20,$2C, $F,$37,$27, $C,$37,$27,$16,$37,$23,$31,$20,$16,$11, $F,$26,$36,$38,$16,  0, $F,$20,$36
		.BYTE $20,$2C, $F,$20,$10,  0,  0,  0,  0,  0,  0,  0,$20,$16,$11,$1C,$36, $F,$20,$36, $F,$17,$36, $F
		.BYTE $20,$2C, $F,$10,  0, $C,$10,  9, $C,$10,$1C, $C,$20,$16,$11,$20,$36, $F,  6,$1C, $F,$36,$1C, $F
		.BYTE $20,$2C, $F,$10,$1C,$20,$10,$36,$15,$21,$36,$16,$20,$16,$11,$38,$16,  0, $F,$16,  0,$20,$36,$21
		.BYTE $20,$2C, $F,$30,$21, $C,$30,$21,$1C,  0,  0,  0,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$36,$26,$20,  6,  0,$20,$36,  0,$20,$16,$11,$20,$36, $F,$20,$10, $F,$20,$26, $F
		.BYTE $20,$2C, $F,$10,$20,  0,$20,$10,  0,  0,  0,  0,$20,$16,$11,$20,$36, $F, $C,$2C, $F, $C,$36, $F
		.BYTE $20,$2C, $F,$20,$36, $C,$21,$36, $C,$17,$36, $C,$20,$16,$11,$20,$26, $F,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$10,$20,  0,$20,$10,  0,  0,  0,  0,$20,$16,$11,$36,$16, $F,$36, $C, $F,$2C,$1C, $F
		.BYTE $20,$2C, $F,$20,$36,$17,  0,  0,  0,  0,  0,  0,$20,$16,$11,$20,$27,$37,$20,$17, $F,$20,$27, $F
		.BYTE $20,$2C, $F,$20,$36, $C,$20,$2C, $C,$2C,$36, $C,$20,$16,$11,  0,$16,  6,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$36,$16,  0,$20,$10,  0,$20,$36,$16,$20,$16,$11,$20,$36, $F,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,  8,$10,  0,$20,$10,  0,$20,$10,$31,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$10,  0,  0,  0,  0,  0,  0,  0,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,  6,$10,  0,$1C,$10,  0,  0,  0,  0,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$37,$20,$27,$37,$36,$26,$37,  0,$2C,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,  6,$10,  0,$2C,$10,  0,$20,$10,  0,$20,$16,$11,$27,$17, $F, $C,$36, $F,$20,$16,$26
		.BYTE $20,$2C, $F,$36,  0,$26,$36,$26,$18,$36,$2C,$26,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$36,$26,$10,$26,  7,$20, $F, $F,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,  0,  0,  0,  0,  0,  0,  0,  0,  0,$20,$16,$11,$16,$26,$38,$36,$1C, $F,$20,$16,$26
		.BYTE $20,$2C, $F,$20,$2C, $C,  0,  0,  0,  0,  0,  0,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$10,$19,  8,$10,$27,$17,$10,$36,$26,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$10,$31,$20,$10,$36,$20,$10,  0,$20,$20,$16,$11,$20,$36, $F,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$10,$36,$20,$10,$36,$26,$10,$31,$20,$20,$16,$11,$10,$36,$20,$2C,$31,$20,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$10,  0,$10,$2C, $C,$10,$36, $C,$20,$16,$11,$20,$36, $F,$20,$10, $F, $F, $F, $F
		.BYTE $20,$2C, $F,$20,$27,$18,$27,$16,  6,  0,  0,  0,$20,$16,$11,$20,$36, $F,$26,$36, $F, $C,$36, $F
		.BYTE $20,$2C, $F,$20,$10,  7,$20,$10,$1C,$20,$28,$26,$20,$16,$11,$20,$36, $F,$1C,$36, $F,$1C,$16, $F
		.BYTE $20,$2C, $F,$20,$10,  0,  0,  0,  0,  0,  0,  0,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$36,$16,$20,$31,$16,$20,$36,$26,$20,$16,$11,$20,$31, $C,$20,$36,$16,$20,$36,$26
		.BYTE $20,$2C, $F,$20,$36,$16,$20,$36,$1C,$20,$36,$26,$20,$16,$11,$20,$31, $C,$20,$36,$16,$20,$36,$26 ;	-unused-
		.BYTE $20,$2C, $F,$20,$36,$16,$20,$36,$1C,$20,$36,$26,$20,$16,$11,$20,$31, $C,$20,$36,$16,$20,$36,$26
		.BYTE $20,$2C, $F,$20,$36,$16,$20,$36,$1C,$20,$36,$26,$20,$16,$11,$20,$31, $C,$20,$36,$16,$20,$36,$26
		.BYTE $20,$2C, $F,$31,$37,  6,$31,$20,$10,$31,$37, $C,$20,$16,$11,$20,$36, $F,$20,$10, $F,  0,  0,  0
		.BYTE $20,$2C, $F,$1C,$27,$1A,$1C, $C,$1A, $C, $A,$1A,$20,$16,$11,$36,$26, $F,$38,$26, $F,$36,$20, $F
		.BYTE $20,$2C, $F,$1C,$36,$1A,  8,$1C,$1A,$36,$1C,  8,$20,$16,$11,$36,$20, $F,$36,$35, $F,  0,  0,  0
		.BYTE $20,$2C, $F,  0,$36,$1A,$20,$36,$1A,$26,$36,$1A,$20,$16,$11,$36,$20, $F,$36,$35, $F,  0,  0,  0
		.BYTE $20,$2C, $F,$36,$26, $C,$36,$26,$20,$36,$16, $C,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$36,$26, $C,$10,$16, $C,$36,$16, $C,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$10,  0,$20,$10,$36,  0,  0,  0,$20,$16,$11,$20, $F,$36,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$36,$20,$1C,$36,$31,$1C,$36,$31,$20,$20,$16,$11,$36,  6,$20,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$36,$16,$20,$36,  8,$20,$16,  8,$20,$20,$16,$11,$36, $F,$1C,$36,$35, $F,  0,  0,  0
		.BYTE $20,$2C, $F,$36,  8,$1C,$38,$1A,$1C,$17,$36,$1C,$20,$16,$11,$36,$26, $F,$36,$38, $F,$36, $F,$1C
		.BYTE $20,$2C, $F,$20,$21,$1C,$36,$21,$1C,$11,$21,$1C,$20,$16,$11,$20,$36, $F,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$36,$1C,$16,$20,$1C, $C,$20,$1C,$16,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$10,$16,  6,$26,$16,  6,$20, $F, $F,$20,$16,$11,$1C, $C,$3C,$18,$16,$36,  0,  0,  0
		.BYTE $20,$2C, $F,$20, $C,$10,$20,$31,$10,$20,$37,$10,$20,$16,$11,$10,  0, $F,$16,$28, $F,  0,  0,  0
		.BYTE $20,$2C, $F,$31,$2C,$18,$1C,$2C,$18,$31,$2C,$23,$20,$16,$11, $F,$36,$20, $F,$36,$17,$37,  8,$23
		.BYTE $20,$2C, $F,$31,$16,$36,$31,$20,$36,$31,$20,$16,$20,$16,$11,$31,$20,$36,$20,$16,$36,  0,  0,  0
		.BYTE $20,$2C, $F,$33,$35,$20,$33,$35,$17,$33,$22,$13,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$31,$36,$16,$31,$10,$16,$31,$36,$20,$20,$16,$11,$31,$36,$16,$20,$36,$16,$20,$36, $F
		.BYTE $20,$2C, $F,$23,$35,$17,$23,$16,$26,$23,$35,$16,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$10,  0, $C,$10,$16, $C,$36,$16, $C,$20,$16,$11,$20,$26,$16,$10,$16, $F,$10,$36, $F
		.BYTE $20,$2C, $F,  0,$38,$16,$20,$38,$16,$38,$36,$16,$20,$16,$11,$20,$38, $F,$20,$36, $F,$36,$16, $F
		.BYTE $20,$2C, $F,$20,$10,$17, $F, $F, $F, $F, $F, $F,$20,$16,$11,$11,$16, $F,$20,$37, $F,$37,$16, $F
		.BYTE $20,$2C, $F,$10,$36,$16,$11,$36,$16,$36,$10,$16,$20,$16,$11,$16,  6, $F,$20,$10, $F,$26,$36, $F
		.BYTE $20,$2C, $F,$20,$36,$16,$20,$36,$32,$20,$36,$17,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$37,$20,$21,$37,$20,$28,$10,$20,$21,$20,$16,$11,$20,$20,$21,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$36,$26,$20,$21,$1C, $F, $F, $F,$20,$16,$11,$2B,$31,$2C,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$39,$1C,$2C,$1C, $C,  0,  0,  0,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$36,$16,$1C,$36,$16, $C,$20, $C,$1C,$20,$16,$11,$20,$36, $F,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$39,  0,  0,  0,  0,  0,  0,  0,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$37,$17,$20,$37,$26,  0,  0,  0,$20,$16,$11,$20,$37, $F,$10,  0, $F,  0,  0,  0
		.BYTE $20,$2C, $F,$3C,$2C, $C,$30,$39,  9,$2C,$1C, $C,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$1C,$2C,  0,  0,  0,  0,  0,  0,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$11,  1,  0,$20,$10,$21,$11,$10,  0,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$38,$28,$27,$17,$28,$20,$10,$38,$20,$16,$11,$30,$39,$19,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$31,$20,$36,$31,$16,$38,$10,$16,  6,$20,$16,$11,$31,$36,$38,$30,$39,$19,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$16,$36, $C,$16,$36,$20,$37,$27,$20,$16,$11,$36,$20, $F,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$36,$16,$1C, $C,$16,$1C, $C,$11,$20,$20,$16,$11,$20,$1C, $F,  0,  0,  0,  0,  0,  0 ;	-unused-
		.BYTE $20,$2C, $F,$21,$20,$10,$20,$10,  0,$2C,$20,$10,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0 ;	-unused-
		.BYTE $20,$2C, $F,$20,$38,$27,$17,  8,$27,$17,$20,$27,$20,$16,$11,$20,$38,$27,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$38,$27,$17,  8,$27,$17,$20,$27,$20,$16,$11,$20,$38,$27,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$30,$3C, $C,$30,$38,$35,$2C,$1C, $C,$20,$16,$11,$30,$38,$27,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$31,$2C,$18,$1C,$2C,$18,$31,$2C,$23,$20,$16,$11, $F,$36,$20,$20,$16,$26,  0,  0,  0 ;	-unused-
		.BYTE $20,$2C, $F,$20,$27,$36,$1C,$27,$36,  0,  0,  0,$20,$16,$11,$16,  6,$31,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$10,$31,$20,$1C,$31,$20,  0,  0,  0,$20,$16,$11,$15, $F,$20,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$10,  7,$20,$11,  7,$36,$11,$16,$20,$16,$11,$20,$36, $F,$16,$36, $F,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$36,$28,$25,$36,$11,$20,$36,$16,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$36,$39,$11,$36,$16,$11,$36,$26,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$31,$36,$26,$31,$36,$20,$31,$36, $C,$20,$16,$11,$20, $F,$20,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$20,$36,$31,$31,$36,$16,$20,$36,$26,$20,$16,$11,$20,$36, $F,$16,$36, $F,  0,  0,  0
		.BYTE $20,$2C, $F,$10,  0,  0,  0,  0,  0,  0,  0,  0,$20,$16,$11,$20,$36, $F,  1,$16, $F,  8,$16,$27
		.BYTE $20,$2C, $F,$20,$10,  0,  0,  0,  0,  0,  0,  0,$20,$16,$11,$20,$36, $F,$1C,$36, $F,$1C,$16, $F
		.BYTE $20,$2C, $F,$20,$20,$20,$10,$21,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $31,$16,  6,$36,$16,  6, $C,$16,  6,  0,  0,  0,$20,$16,  6,$31,  1, $F,$28,  1, $F,$20,$27,$26
		.BYTE  $C,$16,  6, $C,$10,  0,$31,$16,  6,$36,$16,  6,$38,$27, $F, $C,$10,  0,  0,  0,  0,  0,  0,  0
		.BYTE $16,  6,$31,$16,  6, $C,$36,  6, $C,$16,  6,$26,$16,$26,$20,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$36,$26,$38,$2C, $C,$38,$2C, $C,$16,$20,$16,$11,$36,$16, $F,$36,$20, $F,  6,$16, $F
		.BYTE $20,$2C, $F,  0,  0,  0,  0,  0,  0,  0,  0,  0,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0 ;	-unused-
		.BYTE   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,$30,$39,  9,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE  $F, $F, $F,$20,$A6, $F, $F, $F, $F, $F, $F, $F,$20,$20,$20,  0,  0,  0,  0,  0,  0,  0,  0,  0 ;	-unused-
		.BYTE $20,$2C, $F,$20,$36,$2C, $C,$36,$2C,$20, $F, $F,$20,$16,$11,$20,$36,$2C,$20,$2C, $C,  0,  0,  0
		.BYTE $20,$2C, $F,$36,  7,$27,$36,  7,$20,  0,  0,  0,$20,$16,$11,$20,  7, $F,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$10,$36,$20,$10,$36,$26,$26,$36,$20,$20,$16,$11,$10,$36,$20,$26,$36,$20,  0,  0,  0
		.BYTE $20,$2C, $F,$36,$26,$31,$36,$26,$1C,$21,$11,  1,$20,$16,$11,$36,$20, $F,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$10,  0, $C,$10,  9, $C,$10,$1C, $C,$20,$16,$11,$10,$36,$17,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$10,$20,  0,$20,$10,  0,  0,  0,  0,$20,$16,$11,$20,$36, $F,$26,$36, $F,$1C,$16, $F
		.BYTE $20,$2C, $F,$36,$20,$16,$20,$20,$16,  0,  0,  0,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$36,$16,$27,$20,$16,$27,  0,  0,  0,$20,$16,$11,$1C, $C, $F,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$21,$20,$10,$20,$10,  0,$2C,$20,$10,$20,$16,$11,  0,  0,  0,  0,  0,  0,  0,  0,  0
		.BYTE $20,$2C, $F,$1C,$16,$38,$1C,$16,  6,$31,$2C,$20,$20,$16,$11, $F,$17,$27, $F,$29,$36, $F,$29,$26
		.BYTE $16,  6,$2B,$1C,$2C,$2B,$20,$2C,  6,  6,  7,$2B,$16,  7,$36,$1C,$2C,$20,$28, $A,$20,$20, $F,  1
		.BYTE $20,$2C, $F,$20,$36,$27,$26,$36,$27,  6,$36,$27,$20,$16,$11,$20,$36,$27,$26,$36,$27,  0,  0,  0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cursor_active_area_test:
		LDA		_active_areas_list_idx
		BPL		_cursor_active_area_test0
		JMP		_cursor_active_area_test1
_cursor_active_area_test0:
		ASL
		TAX
		LDA		_active_areas_lib0,X
		STA		word_0
		LDA		_active_areas_lib0+1,X
		STA		word_0+1
		LDX		#0
		LDY		#0
loc_99805:
		LDA		_screen_cursor_y
		CMP		(word_0),Y
		BCC		loc_99827
		INY
		CMP		(word_0),Y
		BCS		loc_99828
		LDA		_screen_cursor_x
		INY
		CMP		(word_0),Y
		BCC		loc_99829
		INY
		CMP		(word_0),Y
		BCC		locret_9983C
		CMP		(word_0),Y
		CMP		#$FF
		BEQ		locret_9983C
		JMP		loc_9982A
loc_99827:
		INY
loc_99828:
		INY
loc_99829:
		INY
loc_9982A:
		INY
		LDA		(word_0),Y
		CMP		#$FF
		BEQ		loc_9983A
		CMP		#$FE
		BNE		loc_99805
		INX
		INY
		JMP		loc_99805
loc_9983A:
		LDX		#$FF
locret_9983C:
		RTS

_active_areas_lib0:
		.WORD 0
		.WORD _active_areas_list1
		.WORD _active_areas_list2
		.WORD _active_areas_list3
		.WORD _active_areas_list4
		.WORD _active_areas_list5
		.WORD _active_areas_list6
_active_areas_list1:
		.BYTE $48,$4F,$70,$97
		.BYTE $50,$7F,$68,$9F
		.BYTE $FE
		.BYTE $38,$5F,$18,$2F
		.BYTE $60,$7F,  0,$37
		.BYTE $FE
		.BYTE $68,$7F,$38,$47
		.BYTE $50,$7F,$48,$67
		.BYTE $FE
		.BYTE $28,$4F,$98,$AF
		.BYTE $50,$5F,$A0,$A7
		.BYTE $60,$7F,$A0,$B7
		.BYTE $FE
		.BYTE $40,$67,$C8,$DF
		.BYTE $68,$7F,$B8,$DF
		.BYTE $FE
		.BYTE $58,$7F,$E0,$FF
		.BYTE $FF
_active_areas_list2:
		.BYTE $50,$67,$58,$97
		.BYTE $48,$77,$E8,$FF
		.BYTE $FE
		.BYTE $58,$7F,$A8,$C7
		.BYTE $FE
		.BYTE $68,$6F,$40,$4F
		.BYTE $FE
		.BYTE $68,$6F,$30,$3F
		.BYTE $68,$6F,$68,$87
		.BYTE $FE
		.BYTE $38,$4F,$70,$7F
		.BYTE $FE
		.BYTE $74,$7F,$60,$97
		.BYTE $FF
_active_areas_list3:
		.BYTE $40,$6F,$39,$3F
		.BYTE $60,$6F,$40,$47
		.BYTE $FE
		.BYTE $58,$6F,$48,$4F
		.BYTE $FE
		.BYTE $50,$6F,$50,$57
		.BYTE $FE
		.BYTE $48,$67,$B0,$B7
		.BYTE $FE
		.BYTE $50,$67,$C0,$C7
		.BYTE $40,$4F,$C0,$CF
		.BYTE $FE
		.BYTE $50,$77,$C8,$D7
		.BYTE $FE
		.BYTE $30,$3F,$30,$37
		.BYTE $FE
		.BYTE $30,$3F,$B0,$B7
		.BYTE $FE
		.BYTE $38,$5F,$60,$6F
		.BYTE $FE
		.BYTE $48,$5F,$B8,$BF
		.BYTE $FF
_active_areas_list4:
		.BYTE $20,$37,$48,$5F
		.BYTE $48,$6F,$48,$4F
		.BYTE $38,$6F,$50,$5F
		.BYTE $28,$3F,$A0,$B7
		.BYTE $50,$6F,$98,$A7
		.BYTE $40,$6F,$A8,$B7
		.BYTE $FE
		.BYTE $28,$6F,$78,$87
		.BYTE $FE
		.BYTE $38,$47,$48,$4F
		.BYTE $40,$4F,$A0,$A7
		.BYTE $FF
_active_areas_list5:
		.BYTE $10,$4F,$D0,$FF
		.BYTE $FE
		.BYTE $50,$5F,$38,$4F
		.BYTE $FE
		.BYTE $50,$7F,$60,$87
		.BYTE $FF
_active_areas_list6:
		.BYTE $40,$67,$D8,$FF
		.BYTE $FE
		.BYTE $48,$67,$A8,$D7
		.BYTE $68,$7F,$90,$FF
		.BYTE $FE
		.BYTE $60,$6F,$38,$47
		.BYTE $FF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cursor_active_area_test1:
		ASL
		TAX
		LDA		_active_areas_lib1,X
		STA		word_0
		LDA		_active_areas_lib1+1,X
		STA		word_0+1
		LDX		#0
		LDY		#0
loc_9993A:
		LDA		(word_0),Y
		SEC
		SBC		_screen_cursor_y
		INY
		LDA		(word_0),Y
		SBC		_screen_cursor_y+1				; Y is a 16-bit var actually, but
		INY										; high part never used during the
		BCS		loc_99979						; game, except this place
		LDA		(word_0),Y
		SEC
		SBC		_screen_cursor_y
		INY
		LDA		(word_0),Y
		SBC		_screen_cursor_y+1
		INY
		BCC		loc_9997B
		LDA		(word_0),Y
		SEC
		SBC		_screen_cursor_x
		INY
		LDA		(word_0),Y
		INY
		SBC		_screen_cursor_x+1
		BCS		loc_9997D
		LDA		(word_0),Y
		SEC
		SBC		_screen_cursor_x
		INY
		LDA		(word_0),Y
		SBC		_screen_cursor_x+1
		INY
		BCS		locret_99993
		JMP		loc_9997F
loc_99979:
		INY
		INY
loc_9997B:
		INY
		INY
loc_9997D:
		INY
		INY
loc_9997F:
		INY
		LDA		(word_0),Y
		CMP		#$FF
		BEQ		loc_99991
		DEY
		CMP		#$FE
		BNE		loc_9993A
		INX
		INY
		INY
		JMP		loc_9993A
loc_99991:
		LDX		#$FF
locret_99993:
		RTS

_active_areas_lib1:
		.WORD 0
		.WORD _active_areas_list81
		.WORD _active_areas_list82
		.WORD _active_areas_list83
_active_areas_list81:
		.WORD $68,  $7F, $210, $270, $68,  $7F, $510, $570
		.WORD $FEFE
		.WORD $28,  $7F,  $18,  $5F, $28,  $7F, $318, $35F
		.WORD $28,  $7F, $618, $65F
		.WORD $FEFE
		.WORD $60,  $7F,  $D0,  $EF, $60,  $7F, $3D0, $3EF
		.WORD $60,  $7F, $6D0, $6EF, $68,  $7F,  $F8, $117
		.WORD $68,  $7F, $3F8, $417, $68,  $7F, $6F8, $717
		.WORD $FEFE
		.WORD $20,  $6F, $2B0, $2C8, $20,  $6F, $5B0, $5C8
		.WORD $FEFE
		.WORD $70,  $7F, $178, $19F, $70,  $7F, $478, $49F
		.WORD $FFFF
_active_areas_list82:
		.WORD $70,  $7F, $178, $19F, $70,  $7F, $478, $49F
		.WORD $FFFF
_active_areas_list83:
		.WORD $58,  $7F,    0,  $1F
		.WORD $FEFE
		.WORD $60,  $7F,  $48,  $5F, $68,  $6F,  $60,  $67
		.WORD $FEFE
		.WORD $50,  $5F,  $28,  $3F, $60,  $7F,  $28,  $47
		.WORD $FEFE
		.WORD $20,  $2F,  $D8,  $E7, $30,  $6F,  $D0,  $EF
		.WORD $FEFE
		.WORD $3F,  $4F, $1A0, $1AF, $50,  $7F, $198, $1BF
		.WORD $FFFF

;-----------------------------------------------
; SOUND DRIVER
;-----------------------------------------------

_far_apu_load_param:
		LDA		#$3C							; apu prg bank
		STA		$8001
		PLA
		STA		word_0
		PLA
		STA		word_0+1
.5:
		INC		word_0
		BNE		.4
		INC		word_0+1
.4:
		LDY		#0
		LDA		(word_0),Y
		CMP		#$FF
		BEQ		.3
		JSR		_apu_load
		BEQ		.5								; last opcode of _apu_load clear zero!
.3:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_apu_load:
		LDY		#0
		STY		_apu_tmp_ptr+1
		ASL
		ROL		_apu_tmp_ptr+1
		ASL
		ROL		_apu_tmp_ptr+1
		CLC
		ADC		#<[_apu_music_lib]
		STA		_apu_tmp_ptr
		LDA		#>[_apu_music_lib]
		ADC		_apu_tmp_ptr+1
		STA		_apu_tmp_ptr+1					; _ptr = idx * 4 + _apu_music_lib
		LDA		(_apu_tmp_ptr),Y
		TAX
		LDA		_apu_bufs,X
		CMP		#$FF
		BEQ		loc_17B05F
		LDA		_apu_bufs+1,X
		AND		#3
		TAY
		LDA		byte_17B4B1,Y
		AND		_apu_status_mask
		STA		_apu_status_mask
loc_17B05F:
		LDY		#1
		LDA		(_apu_tmp_ptr),Y
		STA		_apu_bufs+1,X
		INY
		LDA		(_apu_tmp_ptr),Y
		STA		_apu_bufs+2,X
		INY
		LDA		(_apu_tmp_ptr),Y
		STA		_apu_bufs+3,X
		LDA		#0								; make sure the last opcode is zero!
		STA		_apu_bufs,X						; i'm relying on it!
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_apu_reset:
		LDY		#0
		STY		byte_6DA
		STY		_APU_STATUS
		STY		_apu_status_mask
loc_17B085:
		LDA		#$FF
		STA		_apu_bufs,Y
		TYA
		CLC
		ADC		#$15
		TAY
		CMP		#$D2
		BNE		loc_17B085
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_apu_play:
		LDA		#0
		STA		byte_6D2
		INC		byte_6D9
loc_17B09C:
		TAX
		LDA		_apu_bufs+1,X
		AND		#3
		STA		byte_6D3
		TAY
		ASL
		ASL
		STA		byte_6D5
		LDA		byte_17B4B5,Y
		STA		byte_6D4
		LDA		_apu_bufs,X
		BEQ		loc_17B112
		CMP		#$FF
		BEQ		loc_17B109
		JSR		sub_17B44F
		JSR		sub_17B3C6
		INC		_apu_bufs+$D,X
		LDA		_apu_bufs+$D,X
		CMP		_apu_bufs+$C,X
		BCC		loc_17B0D1
		LDA		_apu_bufs+$C,X
		STA		_apu_bufs+$D,X
loc_17B0D1:
		DEC		_apu_bufs+5,X
		BPL		loc_17B0EE
		LDA		_apu_bufs+4,X
		AND		#$F
		STA		_apu_bufs+5,X
		JSR		sub_17B40D
		LDA		_apu_bufs+$14,X
		BEQ		loc_17B0E9
		DEC		_apu_bufs+$14,X
loc_17B0E9:
		DEC		_apu_bufs+7,X
		BEQ		loc_17B0F4
loc_17B0EE:
		JSR		sub_17B3A0
		JMP		loc_17B0FD
loc_17B0F4:
		LDA		_apu_bufs+$13,X
		STA		_apu_bufs+$14,X
		JSR		_apu_cmd_fetch
loc_17B0FD:
		LDY		byte_6D3
		LDA		byte_17B4AD,Y
		ORA		byte_6D2
		STA		byte_6D2
loc_17B109:
		TXA
		CLC
		ADC		#$15
		CMP		#$D2
		BNE		loc_17B09C
		RTS
loc_17B112:
		LDA		_apu_bufs+2,X
		STA		_apu_tmp_ptr
		LDA		_apu_bufs+3,X
		STA		_apu_tmp_ptr+1
		LDY		#0
		LDA		(_apu_tmp_ptr),Y
		AND		#$F
		STA		_apu_bufs+4,X
		STA		_apu_bufs+5,X
		INY
		JSR		sub_17B386
		INY
		LDA		(_apu_tmp_ptr),Y
		ORA		byte_6D7
		STA		_apu_bufs+6,X
		INY
		LDA		(_apu_tmp_ptr),Y
		STA		_apu_bufs+8,X
		LDA		#0
		STA		_apu_bufs+9,X
		STA		_apu_bufs+$A,X
		STA		_apu_bufs+$B,X
		STA		_apu_bufs+$E,X
		LDA		#2
		STA		_apu_bufs,X
		BNE		loc_17B0F4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_apu_cmd_fetch:
		LDY		#0
		STY		_apu_tmp_ptr+1
		LDA		_apu_bufs,X
		ASL
		ROL		_apu_tmp_ptr+1
		ADC		_apu_bufs+2,X
		STA		_apu_tmp_ptr
		LDA		_apu_bufs+3,X
		ADC		_apu_tmp_ptr+1
		STA		_apu_tmp_ptr+1
loc_17B16D:
		LDA		(_apu_tmp_ptr),Y
		INC		_apu_bufs,X
		INY
		CMP		#$F0
		BCS		loc_17B191
		CMP		#$E0
		BCS		loc_17B1A9
		CMP		#$D0
		BCS		loc_17B1B3
		CMP		#$C0
		BCS		loc_17B1C9
		CMP		#$B0
		BCS		loc_17B1E9
		CMP		#$A0
		BCC		loc_17B18E
		JMP		loc_17B217
loc_17B18E:
		JMP		loc_17B2D6
loc_17B191:
		CMP		#$FD
		BNE		loc_17B19F
		LDA		_apu_bufs,X
		STA		_apu_bufs+$12,X
loc_17B19B:
		INY
		JMP		loc_17B16D
loc_17B19F:
		CMP		#$FF
		BNE		loc_17B19B
		STA		_apu_bufs,X
		JMP		loc_17B368
loc_17B1A9:
		AND		#$F
		EOR		#$FF
		CLC
		ADC		#1
		JMP		loc_17B1B5
loc_17B1B3:
		AND		#$F
loc_17B1B5:
		BIT		byte_6D4
		BMI		loc_17B1C5
		STA		_apu_bufs+$E,X
		LDA		(_apu_tmp_ptr),Y
		STA		_apu_bufs+$F,X
		STA		_apu_bufs+$10,X
loc_17B1C5:
		INY
		JMP		loc_17B16D
loc_17B1C9:
		AND		#$F
		STA		byte_6D7
		BIT		byte_6D4
		BMI		loc_17B1E5
		LDA		_apu_bufs+6,X
		AND		#$10
		BEQ		loc_17B1E5
		LDA		(_apu_tmp_ptr),Y
		STA		_apu_bufs+$C,X
		LDA		byte_6D7
		STA		_apu_bufs+$B,X
loc_17B1E5:
		INY
		JMP		loc_17B16D
loc_17B1E9:
		AND		#$F
		BEQ		loc_17B20A
		PHA
		LDA		(_apu_tmp_ptr),Y
		BNE		loc_17B1FF
		PLA
		DEC		_apu_bufs+9,X
		BEQ		loc_17B214
		BPL		loc_17B20A
		STA		_apu_bufs+9,X
		BMI		loc_17B20A
loc_17B1FF:
		PLA
		DEC		_apu_bufs+$A,X
		BEQ		loc_17B214
		BPL		loc_17B20A
		STA		_apu_bufs+$A,X
loc_17B20A:
		LDA		(_apu_tmp_ptr),Y
		BNE		loc_17B211
		LDA		_apu_bufs+$12,X
loc_17B211:
		STA		_apu_bufs,X
loc_17B214:
		JMP		_apu_cmd_fetch
loc_17B217:
		BNE		loc_17B228
		BIT		byte_6D4
		BMI		loc_17B231
		LDA		_apu_bufs+6,X
		AND		#$C0
		ORA		(_apu_tmp_ptr),Y
		JMP		loc_17B246
loc_17B228:
		CMP		#$A1
		BNE		loc_17B235
		LDA		(_apu_tmp_ptr),Y
		STA		_apu_bufs+8,X
loc_17B231:
		INY
		JMP		loc_17B16D
loc_17B235:
		CMP		#$A2
		BNE		loc_17B24D
		JSR		sub_17B386
		BCS		loc_17B246
		LDA		_apu_bufs+6,X
		AND		#$1F
		ORA		byte_6D7
loc_17B246:
		STA		_apu_bufs+6,X
		INY
		JMP		loc_17B16D
loc_17B24D:
		CMP		#$A3
		BNE		loc_17B26E
		LDA		(_apu_tmp_ptr),Y
		BMI		loc_17B272
		PHA
		AND		#$F
		ASL
		STA		_apu_bufs+$13,X
		STA		_apu_bufs+$14,X
		PLA
		AND		#$70
		ORA		byte_6D3
		ORA		#$80
		STA		_apu_bufs+1,X
		INY
		JMP		loc_17B16D
loc_17B26E:
		CMP		#$A4
		BNE		loc_17B27E
loc_17B272:
		LDA		_apu_bufs+1,X
		AND		#3
		STA		_apu_bufs+1,X
		INY
		JMP		loc_17B16D
loc_17B27E:
		CMP		#$AD
		BNE		loc_17B2AB
		LDA		(_apu_tmp_ptr),Y
		PHA
		LDA		#0
		STA		_apu_tmp_ptr+1
		LDA		_apu_bufs,X
		ASL
		ROL		_apu_tmp_ptr+1
		ADC		_apu_bufs+2,X
		STA		_apu_bufs+2,X
		LDA		_apu_bufs+3,X
		ADC		_apu_tmp_ptr+1
		STA		_apu_bufs+3,X
		LDA		#0
		STA		_apu_bufs,X
		PLA
		BNE		loc_17B2B8
		JMP		loc_17B112
loc_17B2AB:
		CMP		#$AE
		BNE		loc_17B2BC
		ASL		_apu_bufs+4,X
		LDA		(_apu_tmp_ptr),Y
		ASL
		ROR		_apu_bufs+4,X
loc_17B2B8:
		INY
		JMP		loc_17B16D
loc_17B2BC:
		CMP		#$AF
		BNE		loc_17B2D2
		LDA		(_apu_tmp_ptr),Y
		AND		#$F
		STA		_apu_bufs+5,X
		LDA		_apu_bufs+4,X
		AND		#$F0
		ORA		_apu_bufs+5,X
		STA		_apu_bufs+4,X
loc_17B2D2:
		INY
		JMP		loc_17B16D
loc_17B2D6:
		STA		byte_6D7
		LDA		(_apu_tmp_ptr),Y
		STA		_apu_bufs+7,X
		LDA		byte_6D7
		BIT		byte_6D4
		BVS		loc_17B359
		PHA
		AND		#$F
		CMP		#$C
		BCS		loc_17B367
		ASL
		TAY
		LDA		_apu_bufs+4,X
		BPL		loc_17B2F9
		TYA
		CLC
		ADC		#$18
		TAY
loc_17B2F9:
		LDA		byte_17B47D,Y
		STA		byte_6D7
		LDA		byte_17B47D+1,Y
		STA		byte_6D8
		PLA
		LSR
		LSR
		LSR
		LSR
		BEQ		loc_17B316
		TAY
loc_17B30D:
		LSR		byte_6D8
		ROR		byte_6D7
		DEY
		BNE		loc_17B30D
loc_17B316:
		LDA		#0
		STA		_apu_bufs+$D,X
		JSR		sub_17B378
		LDA		byte_17B4AD,Y
		ORA		_apu_status_mask
		STA		_apu_status_mask
		STA		_APU_STATUS
		LDA		byte_6D8
		PHA
		LDA		byte_6D7
		PHA
		JSR		sub_17B3A3
		LDA		_apu_bufs+8,X
		STA		_APU_PULSE1_SWEEP,Y
		PLA
		STA		_APU_PULSE1_TIME,Y
		CMP		#2
		BCC		loc_17B34B
		CMP		#$FE
		BCC		loc_17B34D
		LDA		#$FD
		BNE		loc_17B34D
loc_17B34B:
		LDA		#2
loc_17B34D:
		STA		_apu_bufs+$11,X
		PLA
		AND		#7
		ORA		#8
		STA		_APU_PULSE1_LEN,Y
		RTS
loc_17B359:
		CMP		#$10
		BCS		loc_17B368
		STA		byte_6D7
		LDA		#0
		STA		byte_6D8
		BEQ		loc_17B316
loc_17B367:
		PLA
loc_17B368:
		JSR		sub_17B378
		LDA		byte_17B4B1,Y
		AND		_apu_status_mask
		STA		_APU_STATUS
		STA		_apu_status_mask
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_17B378:
		LDY		byte_6D3
		LDA		byte_17B4AD,Y
		BIT		byte_6D2
		BEQ		locret_17B385
		PLA
		PLA
locret_17B385:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_17B386:
		BIT		byte_6D4
		BMI		loc_17B397
		LDA		(_apu_tmp_ptr),Y
		ROR
		ROR
		ROR
		AND		#$C0
		STA		byte_6D7
		CLC
		RTS
loc_17B397:
		LDA		(_apu_tmp_ptr),Y
		AND		#$7F
		STA		byte_6D7
		SEC
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_17B3A0:
		JSR		sub_17B378

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_17B3A3:
		CPY		#2
		BEQ		loc_17B3BC
		LDA		_apu_bufs+$B,X
		BNE		sub_17B3D2
		LDA		_apu_bufs+6,X
		AND		#$10
		ASL
		ORA		_apu_bufs+6,X
		LDY		byte_6D5
		STA		_APU_PULSE1_ENV,Y
		RTS
loc_17B3BC:
		LDA		_apu_bufs+6,X
		LDY		byte_6D5
		STA		_APU_TRI_COUNT
locret_17B3BC:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_17B3C6:
		JSR		sub_17B378
		CPY		#2
		BEQ		locret_17B3BC
		LDA		_apu_bufs+$B,X
		BEQ		locret_17B3BC

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_17B3D2:
		ASL
		ASL
		ASL
		ASL
		PHA
		LDA		#0
		STA		byte_6D7
		LDA		_apu_bufs+$D,X
		LDY		#3
loc_17B3E1:
		ASL
		CMP		_apu_bufs+$C,X
		BCC		loc_17B3EA
		SBC		_apu_bufs+$C,X
loc_17B3EA:
		ROL		byte_6D7
		DEY
		BPL		loc_17B3E1
		PLA
		ORA		byte_6D7
		TAY
		LDA		_apu_bufs+6,X
		AND		#$F
		ORA		byte_17B529,Y
		TAY
		LDA		_apu_bufs+6,X
		AND		#$C0
		ORA		byte_17B5C9,Y
		LDY		byte_6D5
		STA		_APU_PULSE1_ENV,Y
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_17B40D:
		BIT		byte_6D4
		BMI		locret_17B440
		LDA		_apu_bufs+$E,X
		BEQ		locret_17B440
		DEC		_apu_bufs+$10,X
		BNE		locret_17B440
		LDA		_apu_bufs+$F,X
		STA		_apu_bufs+$10,X
		LDA		_apu_bufs+6,X
		AND		#$1F
		STA		byte_6D7
		AND		#$10
		BEQ		locret_17B440
		LDA		_apu_bufs+$E,X
		BMI		loc_17B441
		DEC		_apu_bufs+$E,X
		LDA		byte_6D7
		CMP		#$1F
		BEQ		locret_17B440
		INC		_apu_bufs+6,X
locret_17B440:
		RTS
loc_17B441:
		INC		_apu_bufs+$E,X
		LDA		byte_6D7
		CMP		#$10
		BEQ		locret_17B440
		DEC		_apu_bufs+6,X
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_17B44F:
		JSR		sub_17B378
		BIT		byte_6D4
		BVS		locret_17B47C
		LDA		_apu_bufs+$14,X
		BNE		locret_17B47C
		LDA		_apu_bufs+1,X
		BPL		locret_17B47C
		AND		#$70
		STA		byte_6D7
		LDA		byte_6D9
		AND		#$F
		ORA		byte_6D7
		TAY
		LDA		byte_17B4B9,Y
		CLC
		ADC		_apu_bufs+$11,X
		LDY		byte_6D5
		STA		_APU_PULSE1_TIME,Y
locret_17B47C:
		RTS

byte_17B47D:
		.BYTE $AE,  6,$4E,  6,$F4,  5,$9E,  5,$4D,  5,  1,  5,$B9,  4,$75,  4
		.BYTE $35,  4,$F9,  3,$C0,  3,$8A,  3,$7E,  6,$21,  6,$C9,  5,$76,  5
		.BYTE $27,  5,$DD,  4,$96,  4,$55,  4,$17,  4,$DD,  3,$A5,  3,$71,  3
byte_17B4AD:
		.BYTE   1,  2,  4,  8
byte_17B4B1:
		.BYTE  $E, $D, $B,  7
byte_17B4B5:
		.BYTE   0,  1,$82,$43
byte_17B4B9:
		.BYTE   0,  0,  1,  1,  0,  0,$FF,$FF,  0,  0,  1,  1,  0,  0,$FF,$FF
		.BYTE   0,  0,  0,  0,  1,  1,  1,  1,  0,  0,  0,  0,$FF,$FF,$FF,$FF
		.BYTE   0,  1,  2,  1,  0,$FF,$FE,$FF,  0,  1,  2,  1,  0,$FF,$FE,$FF
		.BYTE   0,  0,  1,  1,  2,  2,  1,  1,  0,  0,$FF,$FF,$FE,$FE,$FF,$FF
		.BYTE $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE $FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE   1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1
byte_17B529:
		.BYTE   2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2
		.BYTE $F0,$E0,$D0,$C0,$B0,$A0,$90,$80,$70,$60,$50,$40,$30,$20,$10,  0
		.BYTE   0,$10,$20,$30,$40,$50,$60,$70,$80,$90,$A0,$B0,$C0,$D0,$E0,$F0
		.BYTE $F0,$E0,$D0,$C0,$B0,$A0,$90,$80,$80,$90,$A0,$B0,$C0,$D0,$E0,$F0
		.BYTE $80,$90,$A0,$B0,$C0,$D0,$E0,$F0,$F0,$E0,$D0,$C0,$B0,$A0,$90,$80
		.BYTE $F0,$D0,$B0,$90,$70,$50,$30,$10,$E0,$C0,$A0,$80,$60,$40,$20,  0
		.BYTE $F0,$E0,$D0,$C0,$C0,$D0,$E0,$D0,$C0,$A0,$80,$60,$40,$20,$10,  0
		.BYTE $F0,$D0,$B0,$90,$A0,$B0,$90,$70,$60,$50,$40,$30,$20,$10,$10,  0
		.BYTE $40,$40,$40,$40,$40,$40,$40,$60,$60,$70,$80,$A0,$C0,$F0,$B0,$80
		.BYTE $F0,$F0,$A0,$80,$F0,$F0,$A0,$80,$70,$70,$60,$60,$50,$50,$40,$20
byte_17B5C9:
		.BYTE $30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30,$30
		.BYTE $30,$30,$30,$30,$30,$30,$30,$30,$31,$31,$31,$31,$31,$31,$31,$31
		.BYTE $30,$30,$30,$30,$31,$31,$31,$31,$31,$31,$31,$31,$32,$32,$32,$32
		.BYTE $30,$30,$30,$31,$31,$31,$31,$31,$32,$32,$32,$32,$32,$33,$33,$33
		.BYTE $30,$30,$31,$31,$31,$31,$32,$32,$32,$32,$33,$33,$33,$33,$34,$34
		.BYTE $30,$30,$31,$31,$31,$32,$32,$32,$33,$33,$33,$34,$34,$34,$35,$35
		.BYTE $30,$30,$31,$31,$32,$32,$32,$33,$33,$34,$34,$34,$35,$35,$36,$36
		.BYTE $30,$30,$31,$31,$32,$32,$33,$33,$34,$34,$35,$35,$36,$36,$37,$37
		.BYTE $30,$31,$31,$32,$32,$33,$33,$34,$34,$35,$35,$36,$36,$37,$37,$38
		.BYTE $30,$31,$31,$32,$32,$33,$34,$34,$35,$35,$36,$37,$37,$38,$38,$39
		.BYTE $30,$31,$31,$32,$33,$33,$34,$35,$35,$36,$37,$37,$38,$39,$39,$3A
		.BYTE $30,$31,$31,$32,$33,$34,$34,$35,$36,$37,$37,$38,$39,$3A,$3A,$3B
		.BYTE $30,$31,$32,$32,$33,$34,$35,$36,$36,$37,$38,$39,$3A,$3A,$3B,$3C
		.BYTE $30,$31,$32,$33,$33,$34,$35,$36,$37,$38,$39,$3A,$3A,$3B,$3C,$3D
		.BYTE $30,$31,$32,$33,$34,$35,$36,$37,$37,$38,$39,$3A,$3B,$3C,$3D,$3E
		.BYTE $30,$31,$32,$33,$34,$35,$36,$37,$38,$39,$3A,$3B,$3C,$3D,$3E,$3F

; callers lib with *custom* comments are not match the APU data layouts,
; they were adjusted later during developement

		APU_L	_snd_akira_title_explosion
		.BYTE $00,$01,$02,$03,$FF
		APU_L	_snd_terrorist_with_grenade	; used with 3C
		.BYTE $04,$05,$06,$FF
		APU_L	_snd_hideout_ambient
		.BYTE $07,$08,$09,$0A,$FF
		APU_L	_snd_flood_channel_beat
		.BYTE $0B,$0C,$0D,$FF
		APU_L	_snd_search_tetsuo_ambient
		.BYTE $0B,$0C,$FF					;*custom*
		APU_L	_snd_search_tetsuo_with_violent_noise
		.BYTE $0B,$9C,$FF					;*custom*
		APU_L	_snd_clown_fight
		.BYTE $0E,$0F,$10,$11,$FF
		APU_L	_snd_energic_something_happening_pulse
		.BYTE $12,$13,$14,$15,$FF
		APU_L	_apu_load_16_17
		.BYTE $16,$17,$FF
		APU_L	_snd_sewers_danger_beat
		.BYTE $18,$19,$1A,$1B,$FF
		APU_L	_snd_kiyoko_psychodelic
		.BYTE $1C,$1D,$FF
		APU_L	_snd_kaneda_death_ambient
		.BYTE $1E,$1F,$20,$21,$FF
		APU_L	_apu_load_22_23_24_25
		.BYTE $22,$23,$24,$25,$FF
		APU_L	_snd_kids_praying
		.BYTE $26,$27,$28,$FF
		APU_L	_snd_battle_action_beat
		.BYTE $29,$2A,$2B,$2C,$FF
		APU_L	_snd_battle_begin_beat
		.BYTE $29,$2B,$2C,$FF				;*custom*
		APU_L	_apu_load_2D_2E_2F_30
		.BYTE $2D,$2E,$2F,$30,$FF
		APU_L	_apu_load_31_32_33
		.BYTE $31,$32,$33,$FF
		APU_L	_snd_game_over_retry_jingle
		.BYTE $34,$35,$36,$37,$FF
		APU_L	_snd_explosion
		.BYTE $38,$39,$FF
		APU_L	_snd_helicopter
		.BYTE $3A,$3B,$FF
		APU_L	_snd_grenade_hissss			; used with 4,5,6
		.BYTE $3C,$FF
		APU_L	_apu_load_3D
		.BYTE $3D,$FF
		APU_L	_snd_punch0					; used with 40
		.BYTE $3E,$FF
		APU_L	_snd_punch1
		.BYTE $3F,$FF
		APU_L	_snd_punch2					; used with 3E
		.BYTE $40,$FF
		APU_L	_snd_grenade_explosion
		.BYTE $41,$FF
		APU_L	_snd_sgame_enemy_explode
		.BYTE $42,$FF
		APU_L	_snd_walkway_explosion
		.BYTE $43,$FF
		APU_L	_snd_bike_ride
		.BYTE $44,$45,$46,$47,$FF
		APU_L	_snd_char_type
		.BYTE $48,$FF
		APU_L	_apu_load_49
		.BYTE $49,$FF
		APU_L	_apu_load_4A_4B_4C
		.BYTE $4A,$4B,$4C,$FF
		APU_L	_apu_load_4A
		.BYTE $4A,$FF						;*custom*
		APU_L	_snd_noisy_silent_ambient
		.BYTE $4B,$4C,$CC,$FF				;*custom*
		APU_L	_snd_walkway_noise
		.BYTE $4D,$FF
		APU_L	_snd_drainage_water_noise0
		.BYTE $4E,$FF
		APU_L	_snd_sewers_kick_fence
		.BYTE $4F,$50,$51,$52,$FF
		APU_L	_snd_army_gun_fire
		.BYTE $53,$54,$55,$56,$FF
		APU_L	_snd_water_drop
		.BYTE $57,$FF
		APU_L	_snd_vent_fence_broken
		.BYTE $58,$59,$FF
		APU_L	_snd_drainage_hover_flyby
		.BYTE $5A,$5B,$5C,$FF
		APU_L	_snd_drainage_hover_motor
		.BYTE $5D,$5E,$5F,$FF
		APU_L	_snd_hit_splash
		.BYTE $60,$FF
		APU_L	_apu_load_61_62_63
		.BYTE $61,$62,$63,$FF
		APU_L	_snd_paper_drop_on_table
		.BYTE $64,$FF
		APU_L	_apu_load_65
		.BYTE $65,$FF
		APU_L	_snd_bike_crash_explode
		.BYTE $66,$67,$68,$69,$FF
		APU_L	_snd_tv_show_helicopter
		.BYTE $6A,$6B,$FF
		APU_L	_snd_orbital_laser_shot
		.BYTE $6C,$6D,$6E,$6F,$FF
		APU_L	_apu_load_70_71_72
		.BYTE $70,$71,$72,$FF
		APU_L	_snd_crc_and_car_arrival
		.BYTE $73,$74,$75,$76,$FF
		APU_L	_snd_fly_on_hover
		.BYTE $77,$78,$79,$FF
		APU_L	_snd_hover_crushA
		.BYTE $7A,$FF
		APU_L	_snd_hover_crushB
		.BYTE $7B,$FF
		APU_L	_snd_kanedas_bike_runaway
		.BYTE $7C,$7D,$7E,$7F,$FF
		APU_L	_snd_akira_flashback_suddenly
		.BYTE $80,$81,$FF
		APU_L	_snd_girl_detected
		.BYTE $82,$83,$84,$85,$FF
		APU_L	_snd_mirror_hit
		.BYTE $86,$87,$FF
		APU_L	_snd_raged_tetsuo_noise
		.BYTE $88,$FF
		APU_L	_snd_hard_noise				; used with 9D,9E,9F and alone
		.BYTE $89,$FF
		APU_L	_snd_enemy_hit
		.BYTE $8A,$FF
		APU_L	_snd_kai_bike_explode
		.BYTE $8B,$FF
		APU_L	_apu_load_8C
		.BYTE $8C,$FF
		APU_L	_snd_bikes_ready_to_go
		.BYTE $8D,$8E,$8F,$90,$FF
		APU_L	_snd_marble_descent
		.BYTE $91,$92,$FF
		APU_L	_snd_water_flood_recide
		.BYTE $93,$FF
		APU_L	_apu_load_94
		.BYTE $94,$FF
		APU_L	_apu_load_95_96_97
		.BYTE $95,$96,$97,$FF
		APU_L	_snd_miyako_theme_with_percussion
		.BYTE $98,$99,$9A,$9B,$FF
		APU_L	_apu_load_98_99_9A
		.BYTE $98,$99,$9A,$FF				;*custom*
		APU_L	_snd_violent_noise
		.BYTE $9C,$FF
		APU_L	_snd_near_stadium_with_beat
		.BYTE $9D,$9E,$9F,$A0,$FF
		APU_L	_snd_near_stadium_without_beat	; used with 89
		.BYTE $9D,$9E,$9F,$FF				;*custom*
		APU_L	_apu_load_A1_A2_A3_A4
		.BYTE $A1,$A2,$A3,$A4,$FF
		APU_L	_snd_mutation_beat
		.BYTE $A3,$A4,$FF					;*custom*
		APU_L	_apu_load_A5_A6_A7_A8
		.BYTE $A5,$A6,$A7,$A8,$FF
		APU_L	_snd_bad_ending_theme
		.BYTE $A9,$AA,$AB,$AC,$FF
		APU_L	_apu_load_AD_AE_AF_B0
		.BYTE $AD,$AE,$AF,$B0,$FF
		APU_L	_snd_black_hole_theme
		.BYTE $B1,$B2,$B3,$B4,$FF
		APU_L	_apu_load_B5_B6_B7_B8
		.BYTE $B5,$B6,$B7,$B8,$FF
		APU_L	_apu_load_B9_BA_BB_BC
		.BYTE $B9,$BA,$BB,$BC,$FF
		APU_L	_apu_load_BD
		.BYTE $BD,$FF
		APU_L	_snd_rest_place_ambient
		.BYTE $BE,$BF,$C0,$C1,$FF
		APU_L	_snd_kaneda_bike_dash
		.BYTE $C2,$C3,$C4,$C5,$FF
		APU_L	_snd_people_coming0
		.BYTE $C6,$FF
		APU_L	_snd_people_coming1
		.BYTE $C7,$FF
		APU_L	_snd_people_coming2
		.BYTE $C8,$FF
		APU_L	_snd_people_coming3
		.BYTE $C9,$FF
		APU_L	_apu_load_CA
		.BYTE $CA,$FF
		APU_L	_snd_clown_punch
		.BYTE $CB,$FF
		APU_L	_apu_load_CC				; used with 4B,4C
		.BYTE $CC,$FF
		APU_L	_snd_kaneda_hover_jump_up
		.BYTE $CD,$FF
		APU_L	_snd_police_sirens
		.BYTE $CE,$CF,$FF
		APU_L	_snd_ending
		.BYTE $D0,$D1,$D2,$D3,$FF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_apu_test_handler:
		JSR		_apu_test_draw
		JSR		_apu_test_set
		LDA		_pads+3							; simple sound test
		LSR
		LSR
		LSR
		LSR
		AND		#3
		SWITCH
		.WORD	_nullsub
		.WORD	_apu_test_inc
		.WORD	_apu_test_dec
		.WORD	_nullsub

;-------------S-U-B-R-O-U-T-I-N-E---------------
_apu_test_set:
		LDA		_pads+3							; simple sound test
		AND		#3
		SWITCH
		.WORD	_nullsub
		.WORD	_apu_test_play
		.WORD	_apu_reset
		.WORD	_nullsub

;-------------S-U-B-R-O-U-T-I-N-E---------------
_apu_test_inc:
		LDX		_apu_test_idx
		CPX		#94
		BCS		.set
		INX
		BNE		.set

;-------------S-U-B-R-O-U-T-I-N-E---------------
_apu_test_dec:
		LDX		_apu_test_idx
		BEQ		.set
		DEX
.set:
		STX		_apu_test_idx
		RTS

_apu_test_pos_x	EQU	$10
_apu_test_pos_y	EQU $10

;-------------S-U-B-R-O-U-T-I-N-E---------------
_apu_test_draw:
		LDA		_apu_test_idx
		LSR
		LSR
		LSR
		LSR
		SPR0SW	_spr_hex_list,_apu_test_pos_y,_apu_test_pos_x
		LDA		_apu_test_idx
		AND		#$F
		SPR0SW	_spr_hex_list,_apu_test_pos_y,_apu_test_pos_x+8
		RTS

_spr_hex_list:
		.WORD	_spr_hex0
		.WORD	_spr_hex1
		.WORD	_spr_hex2
		.WORD	_spr_hex3
		.WORD	_spr_hex4
		.WORD	_spr_hex5
		.WORD	_spr_hex6
		.WORD	_spr_hex7
		.WORD	_spr_hex8
		.WORD	_spr_hex9
		.WORD	_spr_hexA
		.WORD	_spr_hexB
		.WORD	_spr_hexC
		.WORD	_spr_hexD
		.WORD	_spr_hexE
		.WORD	_spr_hexF

_spr_hex0:
		.BYTE   0,_0,  0,  0,$80
_spr_hex1:
		.BYTE   0,_1,  0,  0,$80
_spr_hex2:
		.BYTE   0,_2,  0,  0,$80
_spr_hex3:
		.BYTE   0,_3,  0,  0,$80
_spr_hex4:
		.BYTE   0,_4,  0,  0,$80
_spr_hex5:
		.BYTE   0,_5,  0,  0,$80
_spr_hex6:
		.BYTE   0,_6,  0,  0,$80
_spr_hex7:
		.BYTE   0,_7,  0,  0,$80
_spr_hex8:
		.BYTE   0,_8,  0,  0,$80
_spr_hex9:
		.BYTE   0,_9,  0,  0,$80
_spr_hexA:
		.BYTE   0,_A,  0,  0,$80
_spr_hexB:
		.BYTE   0,_B,  0,  0,$80
_spr_hexC:
		.BYTE   0,_C,  0,  0,$80
_spr_hexD:
		.BYTE   0,_D,  0,  0,$80
_spr_hexE:
		.BYTE   0,_E,  0,  0,$80
_spr_hexF:
		.BYTE   0,_F,  0,  0,$80

;-------------S-U-B-R-O-U-T-I-N-E---------------
_apu_test_play:
		LDA		_apu_test_idx
		SWITCH
		.WORD _snd_akira_title_explosion		; 00
		.WORD _snd_terrorist_with_grenade		; 01 used with _snd_grenade_hissss
		.WORD _snd_hideout_ambient				; 02
		.WORD _snd_flood_channel_beat			; 03
		.WORD _snd_search_tetsuo_ambient		; 04
		.WORD _snd_search_tetsuo_with_violent_noise	; 05
		.WORD _snd_clown_fight					; 06
		.WORD _snd_energic_something_happening_pulse; 07
		.WORD _apu_load_16_17					; 08
		.WORD _snd_sewers_danger_beat			; 09
		.WORD _snd_kiyoko_psychodelic			; 0A
		.WORD _snd_kaneda_death_ambient			; 0B
		.WORD _apu_load_22_23_24_25				; 0C
		.WORD _snd_kids_praying					; 0D
		.WORD _snd_battle_action_beat			; 0E
		.WORD _snd_battle_begin_beat			; 0F
		.WORD _apu_load_2D_2E_2F_30				; 10
		.WORD _apu_load_31_32_33				; 11
		.WORD _snd_game_over_retry_jingle		; 12
		.WORD _snd_explosion					; 13
		.WORD _snd_helicopter					; 14
		.WORD _snd_grenade_hissss				; 15 used with _snd_terrorist_with_grenade
		.WORD _apu_load_3D						; 16
		.WORD _snd_punch0						; 17
		.WORD _snd_punch1						; 18
		.WORD _snd_punch2						; 19
		.WORD _snd_grenade_explosion			; 1A
		.WORD _snd_sgame_enemy_explode			; 1B
		.WORD _snd_walkway_explosion			; 1C
		.WORD _snd_bike_ride					; 1D
		.WORD _snd_char_type					; 1E
		.WORD _apu_load_49						; 1F
		.WORD _apu_load_4A_4B_4C				; 20
		.WORD _apu_load_4A						; 21
		.WORD _snd_noisy_silent_ambient			; 22
		.WORD _snd_walkway_noise				; 23
		.WORD _snd_drainage_water_noise0		; 24
		.WORD _snd_sewers_kick_fence			; 25
		.WORD _snd_army_gun_fire				; 26
		.WORD _snd_water_drop					; 27
		.WORD _snd_vent_fence_broken			; 28
		.WORD _snd_drainage_hover_flyby			; 29
		.WORD _snd_drainage_hover_motor			; 2A
		.WORD _snd_hit_splash					; 2B
		.WORD _apu_load_61_62_63				; 2C
		.WORD _snd_paper_drop_on_table			; 2D
		.WORD _apu_load_65						; 2E
		.WORD _snd_bike_crash_explode			; 2F
		.WORD _snd_tv_show_helicopter			; 30
		.WORD _snd_orbital_laser_shot			; 31
		.WORD _apu_load_70_71_72				; 32
		.WORD _snd_crc_and_car_arrival			; 33
		.WORD _snd_fly_on_hover					; 34
		.WORD _snd_hover_crushA					; 35
		.WORD _snd_hover_crushB					; 36
		.WORD _snd_kanedas_bike_runaway			; 37
		.WORD _snd_akira_flashback_suddenly		; 38
		.WORD _snd_girl_detected				; 39
		.WORD _snd_mirror_hit					; 3A
		.WORD _snd_raged_tetsuo_noise			; 3B
		.WORD _snd_hard_noise					; 3C used with _snd_near_stadium_without_beat and alone
		.WORD _snd_enemy_hit					; 3D
		.WORD _snd_kai_bike_explode				; 3E
		.WORD _apu_load_8C						; 3F
		.WORD _snd_bikes_ready_to_go			; 40
		.WORD _snd_marble_descent				; 41
		.WORD _snd_water_flood_recide			; 42
		.WORD _apu_load_94						; 43
		.WORD _apu_load_95_96_97				; 44
		.WORD _snd_miyako_theme_with_percussion	; 45
		.WORD _apu_load_98_99_9A				; 46
		.WORD _snd_violent_noise				; 47
		.WORD _snd_near_stadium_with_beat		; 48
		.WORD _snd_near_stadium_without_beat	; 49 used with _snd_hard_noise
		.WORD _apu_load_A1_A2_A3_A4				; 4A
		.WORD _snd_mutation_beat				; 4B
		.WORD _apu_load_A5_A6_A7_A8				; 4C
		.WORD _snd_bad_ending_theme				; 4D
		.WORD _apu_load_AD_AE_AF_B0				; 4E
		.WORD _snd_black_hole_theme				; 4F
		.WORD _apu_load_B5_B6_B7_B8				; 50
		.WORD _apu_load_B9_BA_BB_BC				; 51
		.WORD _apu_load_BD						; 52
		.WORD _snd_rest_place_ambient			; 52
		.WORD _snd_kaneda_bike_dash				; 54 similar to _snd_bike_crash_explode but with no explowion
		.WORD _snd_people_coming0				; 55
		.WORD _snd_people_coming1				; 56
		.WORD _snd_people_coming2				; 57
		.WORD _snd_people_coming3				; 58
		.WORD _apu_load_CA						; 59
		.WORD _snd_clown_punch					; 5A
		.WORD _apu_load_CC						; 5B
		.WORD _snd_kaneda_hover_jump_up			; 5C
		.WORD _snd_police_sirens				; 5D
		.WORD _snd_ending						; 5E

;-----------------------------------------------
; FAR CALLS SYS LIBRARY
;-----------------------------------------------

		FJMP	_menu_draw						; 3 times
		FJMP	_s6_spr_overlay4				; 3 times
		FJMP	_s6_tlmA1_draw					; 2 times
		FJMP	_sF_icon46_draw					; 2 times
		FJMP	_sF_spr_overlay7				; 2 times
		FJMP	_sF_spr_overlay8				; 4 times
		FJMP	_sF_tlm9C_draw					; 4 times
		FJMP	_s15_tlm7A_draw					; 3 times
		FJMP	_s17_spr_overlay1_A				; 2 times

;-------------S-U-B-R-O-U-T-I-N-E---------------
_nullsub:
		RTS

_spr_dummy:
		.BYTE $80

		LAST_BANK_END EF,$10000

total_banks	= 16
total_size	= 16*8192

; initial free space		: $0F69
; jump/farcall redunction	: $125A (minus bank0 size lol)
; parametric switches		: $168C (minus bank0 size lol)
; parametric message lists	: $211C (minus bank0 size lol)
; parametric sprites		: $2db2
; more refactoring			: $348a
; more parametrification	: $4056 (two empty banks!)
; palette lib opt, zero ram	: $5205
; some sprites removal		: $5433
; finished code refactor	: $583A (for en ver, much more for jp!)