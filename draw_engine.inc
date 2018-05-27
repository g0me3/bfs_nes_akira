
		SECTION_START 1A

;-----------------------------------------------
; MESSAGE DISPLAY AND DRAWING HANDLERS
;-----------------------------------------------

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_handlers:
		LDA		_nmi_ppu_draw0_req
		BEQ		loc_B0AA4
		JMP		sub_B0FB4
loc_B0AA4:
		LDA		_draw_state_idx
		SWITCH
		SW_PTR	_draw_sub00_exit
		SW_PTR	_draw_sub01_type
		SW_PTR	_draw_sub02_wait
		SW_PTR	_draw_sub03_type_init
;		SW_PTR	_draw_sub04_break				; -unused-
		SW_PTR	_draw_sub05_fade_out
		SW_PTR	_draw_sub06_nt0_draw_area_clear
;		SW_PTR	_draw_sub07_wait_A_press		; -unused-
		SW_PTR	_draw_sub08_tlm4_draw
		SW_PTR	_draw_sub09_icon
		SW_PTR	_draw_sub0A_msg_area_clear
		SW_PTR	_draw_sub0B_menu_wnd
		SW_PTR	_draw_sub0C_nt1_draw_area_clear
		SW_PTR	_draw_sub0D_menu_draw
		SW_PTR	_draw_sub0E_exit_delay
		SW_PTR	_draw_sub0F_menu_items_fill
		SW_PTR	_draw_sub10_menu_scroll_up
		SW_PTR	_draw_sub11_menu_scroll_down

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_sub00_exit:
		LDA		_scene_sub_next
		STA		_scene_sub_cur
		LDA		#_draw_sub00_exit_sidx
		STA		_draw_state_idx
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_sub01_type:
		LDA		_pads+1
		AND		#1
		BEQ		loc_B0AF7
;		NOP										; message skip disabled
;		NOP										; in final release
;		NOP
;		JMP		loc_B0AF7
;		LDA		#1
		STA		_type_fastforward
loc_B0AF7:
		LDA		_type_fastforward
		BNE		loc_B0B02
		LDA		_frames_counter
		AND		#3
		BNE		locret_B0B15
loc_B0B02:
		JSR		_type_get_row
		JSR		_type_char
		LDA		_char_main_tile
		BEQ		locret_B0B15
		LDA		_text_typing_snd_disable
		BNE		locret_B0B15
		JMP		_apu_load_49
locret_B0B15:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_sub02_wait:
		LDX		_cur_msg_list_buf_pos			; check next msg idx (already incremented below)
		LDA		_cur_msg_list_buf,X
		CMP		#$FF
		BNE		loc_B0B23						; if FF, exit immediately, no delay
		JMP		_draw_sub00_exit
loc_B0B23:
		JSR		_cursor_draw_wait_key			; if any messages in the list, then
		BEQ		locret_B0B39					; wait for key before display it
		LDX		_cur_msg_list_buf_pos			; fetch actual msg idx
		LDA		_cur_msg_list_buf,X
		INX
		STX		_cur_msg_list_buf_pos			; set next pos
		CMP		#$FE							; dummy msg idx, force wait delay to single messages
		BEQ		locret_B0B39
		JMP		_cur_msg_load					; load msg params
locret_B0B39:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cursor_draw_wait_key:
		LDA		_frames_counter
		AND		#$18
		BEQ		locret_15DBAF
		SPR0	_cursor_down,$D8,$80
locret_15DBAF:
		LDA		_pads+1
		AND		#1
		RTS
_cursor_down:
		.BYTE   0,$7F,  0,  0,$80

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_sub03_type_init:
		JSR		_msg_row_clear
		BCC		locret_B0B43
		LDX		#_draw_sub01_type_sidx
		STX		_draw_state_idx
locret_B0B43:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
;_draw_sub04_break:
;		LDA		#_draw_sub00_exit_sidx			; -unused-
;		STA		_draw_state_idx					; -unused-
;		RTS										; -unused-

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_sub05_fade_out:
		LDA		byte_3B6
		BNE		loc_B0B8A
		LDA		_frames_counter
		AND		#3
		BNE		locret_B0B95
		LDA		#1
		STA		byte_34E
;		LDA		#$F								; redundant
		LDX		#4
		LDY		#0
loc_B0B5F:
		LDA		_pal_buf,X
		SEC
		SBC		#$10
		BCS		loc_B0B6A
		LDA		#$F
		INY
loc_B0B6A:
		STA		_pal_buf,X
		LDA		_pal_buf+$10,X
		SEC
		SBC		#$10
		BCS		loc_B0B78
		LDA		#$F
		INY
loc_B0B78:
		STA		_pal_buf+$10,X
		INX
		CPX		#$10
		BCC		loc_B0B5F
		CPY		#$18
		BCC		locret_B0B95
		LDA		#1
		STA		byte_3B6
		RTS
loc_B0B8A:
		LDA		#0
		STA		byte_3B6
		JSR		_attrs_default_draw
		JMP		_draw_sub00_exit
locret_B0B95:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_attrs_default_draw:
		LDA		#$55
		LDX		#0
loc_B0B9A:
		STA		_ppu_tmp_row_buf,X
		INX
		CPX		#$20
		BCC		loc_B0B9A
		LDA		#$C0
		STA		_tlm_tmp_line_dst
		LDA		#$23
		STA		_tlm_tmp_line_dst+1
		LDA		#9
		STA		_nmi_ppu_tlm_draw_req
		LDA		#$20
		STA		_nmi_ppu_tlm_draw_len
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
; the same as 0C TODO: optimize me!
_draw_sub06_nt0_draw_area_clear:
		LDA		_nmi_ppu_draw_counter
		BNE		loc_B0BE0
		LDA		#$F
		LDX		#4
loc_B0BBF:
		STA		_pal_buf+4,X
		STA		_pal_buf+$14,X
		INX
		CPX		#$C
		BCC		loc_B0BBF
		LDA		#$55
		LDX		#0
loc_B0BCE:
		STA		_ppu_tmp_buf1,X
		INX
		CPX		#$20
		BCC		loc_B0BCE
		LDA		#$C0
		STA		_ppu_tmp_buf1_dst
		LDA		#$23
		STA		_ppu_tmp_buf1_dst+1
loc_B0BE0:
		LDA		_nmi_ppu_draw_counter
		CMP		#$10
		BCS		loc_B0BED
		LDA		#$20
		STA		_tmp_idxF
		JMP		_draw_area_row_clear
loc_B0BED:
		JMP		_draw_sub00_exit

;-------------S-U-B-R-O-U-T-I-N-E---------------
;_draw_sub07_wait_A_press:
;		LDA		_pads+1
;		AND		#1
;		BEQ		locret_B0BF9
;		JMP		_draw_sub00_exit
;locret_B0BF9:
;		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_sub08_tlm4_draw:
		LDA		_nmi_ppu_draw_counter
		CMP		#$F
		BCC		locret_B0C1B
		BEQ		loc_B0C0A
		LDA		#0
		STA		_nmi_ppu_tlm_draw_req
		JMP		_draw_sub00_exit
loc_B0C0A:
		LDA		_tlm_tmp_line_dst
		CLC
		ADC		#$C0
		STA		_tlm_tmp_line_dst
		LDA		_tlm_tmp_line_dst+1
		ADC		#1
		STA		_tlm_tmp_line_dst+1
locret_B0C1B:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_sub0A_msg_area_clear:
		JSR		_msg_row_clear
		BCC		locret_B0C27
		JMP		_draw_sub00_exit
locret_B0C27:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_sub0B_menu_wnd:
		LDA		#8
		STA		_nmi_ppu_tlm_draw_req
		JSR		sub_B0FB4
		JSR		_get_menu_wnd_frame_row
		INC		byte_40
		LDA		byte_40
		CMP		#$A
		BCC		locret_B0C4D
		LDA		#0
		STA		byte_60
		JSR		_menu_draw
		LDA		#0
		STA		byte_60
		STA		byte_3B8
		LDA		#_draw_sub0F_menu_items_fill_sidx
		STA		_draw_state_idx
locret_B0C4D:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
; the same as 06 TODO: optimize me!
_draw_sub0C_nt1_draw_area_clear:
		LDA		_nmi_ppu_draw_counter
		BNE		loc_B0C77
		LDA		#$F
		LDX		#4
loc_B0C56:
		STA		_pal_buf+4,X
		STA		_pal_buf+$14,X
		INX
		CPX		#$C
		BCC		loc_B0C56
		LDA		#$55
		LDX		#0
loc_B0C65:
		STA		_ppu_tmp_buf1,X
		INX
		CPX		#$20
		BCC		loc_B0C65
		LDA		#$C0
		STA		_ppu_tmp_buf1_dst
		LDA		#$27
		STA		_ppu_tmp_buf1_dst+1
loc_B0C77:
		LDA		_nmi_ppu_draw_counter
		CMP		#$10
		BCS		loc_B0C84
		LDA		#$24
		STA		_tmp_idxF
		JMP		_draw_area_row_clear
loc_B0C84:
		JMP		_draw_sub00_exit

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_sub0D_menu_draw:
		JSR		_msg_row_clear
		BCC		locret_B0C8F
		LDA		#_draw_sub0B_menu_wnd_sidx
		STA		_draw_state_idx
		LDA		#1
		STA		_menu_is_drawn_flag
		LDA		#0
		STA		byte_40
		STA		byte_34C
		STA		_scene_menu_pos
		STA		byte_3AB
locret_B0C8F:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_sub0E_exit_delay:
		LDA		_frames_counter
		AND		#3
		BNE		locret_B0C9E
		DEC		_msg_exit_delay_timer
		BNE		locret_B0C9E
		JMP		_draw_sub00_exit
locret_B0C9E:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_sub0F_menu_items_fill:
		JSR		sub_B10A0
		JSR		sub_B10B5
		LDA		#9
		STA		_nmi_ppu_tlm_draw_req
		LDA		#7
		STA		_nmi_ppu_tlm_draw_len
		INC		byte_60
		LDA		byte_60
		CMP		#8
		BCC		locret_B0CBA
		JMP		_draw_sub00_exit
locret_B0CBA:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_sub10_menu_scroll_up:
		JSR		_menu_cursor_draw
		LDA		byte_3B8
		BNE		loc_B0CE3
		JSR		sub_B1084
		JSR		sub_B10F9
		LDA		#9
		STA		_nmi_ppu_tlm_draw_req
		LDA		#7
		STA		_nmi_ppu_tlm_draw_len
		INC		byte_60
		LDA		byte_60
		CMP		#8
		BCC		locret_B0D03
		INC		byte_3B8
		LDA		#0
		STA		byte_60
		RTS
loc_B0CE3:
		JSR		sub_B1084
		JSR		sub_B10E8
		LDA		#9
		STA		_nmi_ppu_tlm_draw_req
		LDA		#7
		STA		_nmi_ppu_tlm_draw_len
		INC		byte_60
		LDA		byte_60
		CMP		#8
		BCC		locret_B0D03
		LDA		#0
		STA		byte_60
		LDA		#_draw_sub00_exit_sidx
		STA		_draw_state_idx
locret_B0D03:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_draw_sub11_menu_scroll_down:
		JSR		_menu_cursor_draw
		LDA		byte_3B8
		BNE		loc_B0D2C
		JSR		sub_B10A0
		JSR		sub_B10C6
		LDA		#9
		STA		_nmi_ppu_tlm_draw_req
		LDA		#7
		STA		_nmi_ppu_tlm_draw_len
		INC		byte_60
		LDA		byte_60
		CMP		#8
		BCC		locret_B0D4C
		INC		byte_3B8
		LDA		#0
		STA		byte_60
		RTS
loc_B0D2C:
		JSR		sub_B10A0
		JSR		sub_B10D7
		LDA		#9
		STA		_nmi_ppu_tlm_draw_req
		LDA		#7
		STA		_nmi_ppu_tlm_draw_len
		INC		byte_60
		LDA		byte_60
		CMP		#8
		BCC		locret_B0D4C
		LDA		#0
		STA		byte_60
		LDA		#_draw_sub00_exit_sidx
		STA		_draw_state_idx
locret_B0D4C:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_type_get_row:
#if LANGUAGE == JP_LANG
;-----------------------------------------------
; ORIGINAL JAPAN LINE POS CALC
;-----------------------------------------------
		LDA		_cur_msg_row					; calc up to 5 two-row lines
;loc_B0D4F:
;		CMP		#5								; check for extra line, but no message
;		BCC		loc_B0D59						; in this game uses more, but most of
;		SEC										; messages ends with ret/eol combo, so
;		SBC		#5								; it will try to draw an extra line
;		BCS		loc_B0D4F						; extra rets removed already
loc_B0D59:
		ASL
		TAX
		LDA		_msg_row_ppu_ofs_list,X
		CLC
		ADC		_cur_msg_col
		STA		_cur_msg_char_ppu_ofs
		LDA		_msg_row_ppu_ofs_list+1,X
		ADC		#0
		STA		_cur_msg_char_ppu_ofs+1
		LDA		#1
		STA		_cur_msg_pos_increment
		CLC
		ADC		_cur_msg_col
		STA		_cur_msg_col
		RTS
_msg_row_ppu_ofs_list:
		.WORD $2223
		.WORD $2263
		.WORD $22A3
		.WORD $22E3
		.WORD $2323
;-----------------------------------------------
#else
;-----------------------------------------------
; OTHER LANGS POS CALC
;-----------------------------------------------
		LDA		#0								; calc up to 10 lines of text
		STA		_cur_msg_char_ppu_ofs+1			; eng translation removed all rets
		LDA		_cur_msg_row
		ASL
		ASL
		ASL
		ASL
		ASL
		ROL		_cur_msg_char_ppu_ofs+1
		ORA		_cur_msg_col
		ADC		#$21
		STA		_cur_msg_char_ppu_ofs
		LDA		_cur_msg_char_ppu_ofs+1
		ADC		#$22
		STA		_cur_msg_char_ppu_ofs+1
		LDA		#1
		STA		_cur_msg_pos_increment
		CLC
		ADC		_cur_msg_col
		STA		_cur_msg_col
		RTS
;-----------------------------------------------
#endif
;-----------------------------------------------

;-------------S-U-B-R-O-U-T-I-N-E---------------
_type_char:
		JSR		_get_msg_block_prg_and_idx
		LDA		_dictionary_str_idx
		BEQ		_type_char_fetch
		ASL										; fetch dictionary string
		TAX
		LDA		_dictionary_lib,X
		STA		word_0
		LDA		_dictionary_lib+1,X
		STA		word_0+1
		LDY		_dictionary_char_pos
		LDA		(word_0),Y
		PHA
		INY
		LDA		(word_0),Y
		CMP		#$FF
		BNE		loc_B0E26
		LDA		#0
		STA		_dictionary_str_idx
loc_B0E26:
		PLA
		INC		_dictionary_char_pos
		JMP		_type_char_decode
_type_char_fetch:
		LDA		_cur_msg_ptr					; regular string fetch
		CLC
		ADC		_cur_msg_pos
		STA		word_0
		LDA		_cur_msg_ptr+1
		ADC		_cur_msg_pos+1
		STA		word_0+1
		LDA		_cur_msg_pos_increment
		CLC
		ADC		_cur_msg_pos
		STA		_cur_msg_pos
		LDA		#0
		ADC		_cur_msg_pos+1
		STA		_cur_msg_pos+1
		LDY		#0
		LDA		(word_0),Y
_type_char_decode:

#if LANGUAGE == JP_LANG
;-----------------------------------------------
		CMP		#_aof
		BEQ		_cmdB0_anim_off					; B0, special case
		CMP		#_an0
		BEQ		_cmdB1_anim0_on					; B1, special case
		CMP		#_an1
		BEQ		_cmdB2_anim1_on					; B2, special case
		CMP		#_an2
		BEQ		_cmdB3_anim2_on					; B3, special case
		CMP		#_num
		BEQ		_cmdB4_number					; B4, special case, overwrites N
		CMP		#$C0
		BCC		_chars_common					; 00-BF common single chars
		CMP		#$CF
		BCC		_charsC0_CE						; C0-CE hiragana nigori #1
		CMP		#$D4
		BCC		_charsCF_D3						; CF-D3 hiragana nigori #2
		CMP		#$D9
		BCC		_charsD4_D8						; D4-D8 hiragana panigori
		CMP		#$E0
		BCS		.cB
		JMP		_cmdD9_DF_dictionary			; D9-DF dictionary 01-07
.cB:
		CMP		#$F4
		BCC		_charsE0_F3						; E0-F3 katakana nigori
		CMP		#$F9
		BCC		_charsF4_F8						; F4-F8 katakana panigori
		CMP		#$FC
		BCS		.cF
		JMP		_cmdF9_FB_dictionary			; F9-FB dinctionary 08-0A
.cF:
		CMP		#_ret
		BEQ		_cmdFE_return					; FE return
		CMP		#_eol
		BEQ		_cmdFF_break					; FF eol
		LDA		#0								; if something goes wrong, never happened
		STA		_char_main_tile
		BEQ		_no_extra_tile

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdB0_anim_off:
		LDA		#0
		STA		_scene_anim_active
		STA		_scene_anim_active+1
		STA		_scene_anim_active+2
		JMP		_type_char_fetch

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdB1_anim0_on:
		LDA		#1
		STA		_scene_anim_active
		JMP		_type_char_fetch

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdB2_anim1_on:
		LDA		#1
		STA		_scene_anim_active+1
		JMP		_type_char_fetch

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdB3_anim2_on:
		LDA		#1
		STA		_scene_anim_active+2
		JMP		_type_char_fetch

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdB4_number:
		LDX		_msg_display_number
		LDA		_cmd94_num_list,X

;-------------S-U-B-R-O-U-T-I-N-E---------------
_chars_common:
		STA		_char_main_tile

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_no_extra_tile:
		LDA		#0
		STA		_char_extra_tile
		RTS

_cmd94_num_list:
		.BYTE _1,_2,_3,_4

;-------------S-U-B-R-O-U-T-I-N-E---------------
; ga-go, za-zo, da-do
;
_charsC0_CE:
		SEC
		SBC		#$B4

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_chars_extra_nigori:
		STA		_char_main_tile
		LDA		#_gg							; nigori
		STA		_char_extra_tile
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
; ba-bo
;
_charsCF_D3:
		SEC
		SBC		#$AF
		BCS		_chars_extra_nigori				; carry = 1 here always

;-------------S-U-B-R-O-U-T-I-N-E---------------
; pa-po
;
_charsD4_D8:
		SEC
		SBC		#$B4

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_chars_extra_panigori:
		STA		_char_main_tile
		LDA		#_pp							; panigori
		STA		_char_extra_tile
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
; PA-PO
;
_charsF4_F8:
		SEC
		SBC		#$A0
		BCS		_chars_extra_panigori			; carry = 1 here always

;-------------S-U-B-R-O-U-T-I-N-E---------------
; GA-GO, ZA-ZO, DA-DO, BA-BO
;
_charsE0_F3:
		SEC
		SBC		#$9B
		BCS		_chars_extra_nigori				; carry = 1 here always

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdFE_return:
		LDA		#0
		STA		_cur_msg_char_ppu_ofs+1
		STA		_cur_msg_col
		INC		_cur_msg_row
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdFF_break:
		LDA		#0
		STA		_cur_msg_char_ppu_ofs+1
		LDA		#_draw_sub02_wait_sidx
		STA		_draw_state_idx
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdD9_DF_dictionary:
		SEC
		SBC		#[$D9-1]						; 1 - first dict entry here
		BNE		_dictionary_str_set				; no zero values, no fallthrough

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdF9_FB_dictionary:
		SEC
		SBC		#[$F9-8]						; 8 - first dict entry here

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_dictionary_str_set:
		STA		_dictionary_str_idx
		LDA		#0
		STA		_dictionary_char_pos
		STA		_cur_msg_char_ppu_ofs+1
		DEC		_cur_msg_col
		RTS
;-----------------------------------------------
#endif

#if LANGUAGE == EN_LANG
;-----------------------------------------------
		CMP		#$80
		BCC		_chars_common					; 00-7F common chars
		CMP		#$A0
		BCC		_cmd80_9F_dictionary			; 80-9F dictionary 1
		CMP		#_aof
		BEQ		_cmdB0_anim_off					; B0, special case
		CMP		#_an0
		BEQ		_cmdB1_anim0_on					; B1, special case
		CMP		#_an1
		BEQ		_cmdB2_anim1_on					; B2, special case
		CMP		#_an2
		BEQ		_cmdB3_anim2_on					; B3, special case
		CMP		#_num
		BEQ		_cmdB4_number					; B4, special case, overwrites N
		CMP		#$C0
		BCC		_chars_common					; 00-BF other common chars
		CMP		#$FC
		BCC		_cmdC0_FB_dictionary			; C0-FB dinctionary 2
		CMP		#_ret
		BEQ		_cmdFE_return					; FE return
		CMP		#_eol
		BEQ		_cmdFF_break					; FF eol
		LDA		#0								; if something goes wrong, never happened
		STA		_char_main_tile
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdB0_anim_off:
		LDA		#0
		STA		_scene_anim_active
		STA		_scene_anim_active+1
		STA		_scene_anim_active+2
		JMP		_type_char_fetch

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdB1_anim0_on:
		LDA		#1
		STA		_scene_anim_active
		JMP		_type_char_fetch

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdB2_anim1_on:
		LDA		#1
		STA		_scene_anim_active+1
		JMP		_type_char_fetch

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdB3_anim2_on:
		LDA		#1
		STA		_scene_anim_active+2
		JMP		_type_char_fetch

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdB4_number:
		LDX		_msg_display_number
		LDA		_cmdB4_num_list,X

;-------------S-U-B-R-O-U-T-I-N-E---------------
_chars_common:
		STA		_char_main_tile
		RTS

_cmdB4_num_list:
		.BYTE _1,_2,_3,_4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdFE_return:
		LDA		#0
		STA		_cur_msg_char_ppu_ofs+1
		STA		_cur_msg_col
		INC		_cur_msg_row
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdFF_break:
		LDA		#0
		STA		_cur_msg_char_ppu_ofs+1
		LDA		#_draw_sub02_wait_sidx
		STA		_draw_state_idx
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmd80_9F_dictionary:
		SEC
		SBC		#[$80-$3D]						; $3D - first dict entry here
		BNE		_dictionary_str_set				; no zero values, no fallthrough

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdC0_FB_dictionary:
		SEC
		SBC		#[$C0-1]						; 1 - first dict entry here

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_dictionary_str_set:
		STA		_dictionary_str_idx
		LDA		#0
		STA		_dictionary_char_pos
		STA		_cur_msg_char_ppu_ofs+1
		DEC		_cur_msg_col
		RTS
;-----------------------------------------------
#endif

#if LANGUAGE == RU_LANG
;-----------------------------------------------
		CMP		#$70
		BCC		_chars_common					; 00-6F common chars
		CMP		#$B0
		BCC		_cmd70_AF_dictionary			; first part of dict entries
		CMP		#_aof
		BEQ		_cmdB0_anim_off					; B0, special case
		CMP		#_an0
		BEQ		_cmdB1_anim0_on					; B1, special case
		CMP		#_an1
		BEQ		_cmdB2_anim1_on					; B2, special case
		CMP		#_an2
		BEQ		_cmdB3_anim2_on					; B3, special case
		CMP		#_num
		BEQ		_cmdB4_number					; B4, special case, overwrites N

_cmd70_FA_dictionary

		CMP		#_password
		BEQ		_cmdFB_pass						; password dict special entry
		CMP		#_ret
		BEQ		_cmdFE_return					; FE return
		CMP		#_eol
		BEQ		_cmdFF_break					; FF eol
		LDA		#0								; if something goes wrong, never happened
		STA		_char_main_tile
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdB0_anim_off:
		LDA		#0
		STA		_scene_anim_active
		STA		_scene_anim_active+1
		STA		_scene_anim_active+2
		JMP		_type_char_fetch

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdB1_anim0_on:
		LDA		#1
		STA		_scene_anim_active
		JMP		_type_char_fetch

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdB2_anim1_on:
		LDA		#1
		STA		_scene_anim_active+1
		JMP		_type_char_fetch

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdB3_anim2_on:
		LDA		#1
		STA		_scene_anim_active+2
		JMP		_type_char_fetch

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdB4_number:
		LDX		_msg_display_number
		LDA		_cmdB4_num_list,X

;-------------S-U-B-R-O-U-T-I-N-E---------------
_chars_common:
		STA		_char_main_tile
		RTS

_cmdB4_num_list:
		.BYTE _1,_2,_3,_4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdFE_return:
		LDA		#0
		STA		_cur_msg_char_ppu_ofs+1
		STA		_cur_msg_col
		INC		_cur_msg_row
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdFF_break:
		LDA		#0
		STA		_cur_msg_char_ppu_ofs+1
		LDA		#_draw_sub02_wait_sidx
		STA		_draw_state_idx
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmdFB_pass:
		LDA		#1								; pass dict entry in my dictionary
		BNE		_dictionary_str_set				; no zero values, no fallthrough

;-------------S-U-B-R-O-U-T-I-N-E---------------
_cmd70_AF_dictionary:
		SEC
		SBC		#[$70-2]						; 2 - first dict entry here

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_dictionary_str_set:
		STA		_dictionary_str_idx
		LDA		#0
		STA		_dictionary_char_pos
		STA		_cur_msg_char_ppu_ofs+1
		DEC		_cur_msg_col
		RTS
;-----------------------------------------------
#endif

_dictionary_lib:
#if LANGUAGE == JP_LANG
;-----------------------------------------------
		INCLUDE "..\msg_jp\jp_dictionary.inc"
;-----------------------------------------------
#endif
#if LANGUAGE == EN_LANG
;-----------------------------------------------
		INCLUDE "..\msg_en\en_dictionary.inc"
;-----------------------------------------------
#endif
#if LANGUAGE == RU_LANG
;-----------------------------------------------
		INCLUDE "..\msg_ru\ru_dictionary.inc";
;-----------------------------------------------
#endif

;-------------S-U-B-R-O-U-T-I-N-E---------------
_msg_row_clear:
		LDA		#0
		STA		word_0
		LDA		byte_47
		ASL
		ROL		word_0
		ASL
		ROL		word_0
		ASL
		ROL		word_0
		ASL
		ROL		word_0
		ASL
		ROL		word_0
		CLC
		ADC		#$20
		STA		_ppu_tmp_buf0_dst
		LDA		word_0
		ADC		#$22
		STA		_ppu_tmp_buf0_dst+1
		LDA		#0
		TAX
loc_B0F93:
		STA		_ppu_tmp_buf0,X
		INX
		CPX		#$20
		BCC		loc_B0F93
		LDA		#6
		STA		_ppu_tmp_buf0
		LDA		#$3B
		STA		_ppu_tmp_buf0+$1F
		INC		byte_47
		LDA		byte_47
		CMP		#$A
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_B0FAC:
		LDX		byte_60
		INX
		STX		word_0+1
		JMP		sub_B0FB8

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_B0FB4:
		LDA		byte_40
		STA		word_0+1

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_B0FB8:
		LDA		#0
		STA		word_0
		LSR		word_0+1
		ROR		word_0
		LSR		word_0+1
		ROR		word_0
		LSR		word_0+1
		ROR		word_0
		LDA		word_0
		LDA		_scroll_x_shadow
		CLC
		ADC		#$A0
		STA		word_2
		LDA		_scroll_x_shadow+1
		ADC		#0
		STA		word_2+1
		LDA		word_2
		LSR
		LSR
		LSR
		AND		#$1E
		CLC
		ADC		#$80
		STA		word_320
		LDA		#0
		ADC		#$20
		STA		word_320+1
		LDA		word_320
		CLC
		ADC		word_0
		STA		word_320
		LDA		word_320+1
		ADC		word_0+1
		STA		word_320+1
		LDA		word_2+1
		LSR
		BCC		locret_B100A
		LDA		word_320+1
		CLC
		ADC		#4
		STA		word_320+1
locret_B100A:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_get_menu_wnd_frame_row:
		LDA		#<[_menu_wnd_frame_top]
		STA		word_0
		LDA		#>[_menu_wnd_frame_top]
		STA		word_0+1
		LDX		byte_40
		BEQ		loc_B102B
		LDA		#<[_menu_wnd_frame_bottom]
		STA		word_0
		LDA		#>[_menu_wnd_frame_bottom]
		STA		word_0+1
		CPX		#9
		BEQ		loc_B102B
		LDA		#<[_menu_wnd_frame_mid]
		STA		word_0
		LDA		#>[_menu_wnd_frame_mid]
		STA		word_0+1
loc_B102B:
		LDY		#0
loc_B102D:
		LDA		(word_0),Y
		STA		_menu_wnd_row_buf0,Y
		INY
		CPY		#$A
		BCC		loc_B102D
		INC		byte_40
		LDA		#<[_menu_wnd_frame_top]
		STA		word_0
		LDA		#>[_menu_wnd_frame_top]
		STA		word_0+1
		LDX		byte_40
		BEQ		loc_B1059
		LDA		#<[_menu_wnd_frame_bottom]
		STA		word_0
		LDA		#>[_menu_wnd_frame_bottom]
		STA		word_0+1
		CPX		#9
		BEQ		loc_B1059
		LDA		#<[_menu_wnd_frame_mid]
		STA		word_0
		LDA		#>[_menu_wnd_frame_mid]
		STA		word_0+1
loc_B1059:
		LDY		#0
loc_B105B:
		LDA		(word_0),Y
		STA		_menu_wnd_row_buf1,Y
		INY
		CPY		#$A
		BCC		loc_B105B
		RTS
_menu_wnd_frame_top:
		.BYTE   4,$3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F,  5
_menu_wnd_frame_mid:
		.BYTE   6,  0,  0,  0,  0,  0,  0,  0,  0,$3B
_menu_wnd_frame_bottom:
		.BYTE $6C,$3C,$3C,$3C,$3C,$3C,$3C,$3C,$3C,$6D

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_B1084:
		LDA		#8
		SEC
		SBC		byte_60
		STA		word_0+1
		JSR		sub_B0FB8
		LDA		word_320
		CLC
		ADC		#2
		STA		_tlm_tmp_line_dst
		LDA		word_320+1
		ADC		#0
		STA		_tlm_tmp_line_dst+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_B10A0:
		JSR		sub_B0FAC
		LDA		word_320
		CLC
		ADC		#2
		STA		_tlm_tmp_line_dst
		LDA		word_320+1
		ADC		#0
		STA		_tlm_tmp_line_dst+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_B10B5:
		LDX		byte_60
		LDA		byte_B10BE,X
		JMP		_msg_format_buf_send
byte_B10BE:
		.BYTE   0,  8,$10,$18,$20,$28,$30,$38

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_B10C6:
		LDX		byte_60
		LDA		byte_B10CF,X
		JMP		_msg_format_buf_send
byte_B10CF:
		.BYTE   8,$10,$18,$20,$28,$30,$38,$40

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_B10D7:
		LDX		byte_60
		LDA		byte_B10E0,X
		JMP		_msg_format_buf_send
byte_B10E0:
		.BYTE $10,$18,$20,$28,$30,$38,$40,$48

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_B10E8:
		LDX		byte_60
		LDA		byte_B10F1,X
		JMP		_msg_format_buf_send
byte_B10F1:
		.BYTE $38,$30,$28,$20,$18,$10,  8,  0

;-------------S-U-B-R-O-U-T-I-N-E---------------
sub_B10F9:
		LDX		byte_60
		LDA		byte_B1102,X
		JMP		_msg_format_buf_send
byte_B1102:
		.BYTE $40,$38,$30,$28,$20,$18,$10,  8

;-------------S-U-B-R-O-U-T-I-N-E---------------
_msg_format_buf_send:
		TAX
		LDY		#0
loc_B110D:
		LDA		_format_buf,X
		STA		_ppu_tmp_row_buf,Y
		INX
		INY
		CPY		#$10
		BCC		loc_B110D
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_menu_draw:
		LDY		#0
loc_B111C:
		TYA
		PHA
		JSR		_menu_row_draw
		PLA
		TAY
		LDX		#0
loc_B1125:
		LDA		_ppu_tmp_row_buf,X
		STA		_format_buf,Y
		INX
		INY
		CPX		#8
		BCC		loc_B1125
		INC		byte_60
		CPY		#$50
		BCC		loc_B111C
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_menu_row_draw:
		LDA		#0
		TAX
loc_B113B:
		STA		_ppu_tmp_row_buf,X
		INX
		CPX		#7
		BCC		loc_B113B
		LDA		_scene_menu_max_pos
		ASL
		TAX
		INX
		CPX		byte_60
		BCC		locret_B119A
		LDA		byte_60
		LSR
		CLC
		ADC		byte_3AB
		TAX
		LDA		_scene_menu_items,X
		ASL
		ASL
		TAY
		LDA		byte_60
		LSR
		BCC		loc_B1162
		INY
		INY
loc_B1162:
		TYA
		PHA
		LDA		_scene_idx
		ASL
		TAX
		LDA		_menu_data_lib,X
		STA		word_0
		LDA		_menu_data_lib+1,X
		STA		word_0+1
		LDA		_scene_menu_idx
		ASL
		TAY
		LDA		(word_0),Y
		STA		word_2
		INY
		LDA		(word_0),Y
		STA		word_2+1
		PLA
		TAY
		LDA		(word_2),Y
		STA		byte_4
		INY
		LDA		(word_2),Y
		STA		byte_5
		LDY		#0
loc_B118D:
		LDA		(byte_4),Y
		CMP		#$FF
		BEQ		locret_B119A
		STA		_ppu_tmp_row_buf,Y
		INY
		JMP		loc_B118D
locret_B119A:
		RTS

_menu_data_lib:
#if LANGUAGE == JP_LANG
;-----------------------------------------------
		INCLUDE "..\msg_jp\jp_menu_lib.inc"
;-----------------------------------------------
#endif
#if LANGUAGE == EN_LANG
;-----------------------------------------------
		INCLUDE "..\msg_en\en_menu_lib.inc"
;-----------------------------------------------
#endif
#if LANGUAGE == RU_LANG
;-----------------------------------------------
		INCLUDE "..\msg_ru\ru_menu_lib.inc"
;-----------------------------------------------
#endif

		SECTION_END 1A
