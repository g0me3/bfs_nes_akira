
		SECTION_START 5

;-----------------------------------------------
; SCENE 5
;-----------------------------------------------

; original interactive script:
; 1. peek (inquire added)
; 2. inquire (got [sector N], move added)
; 3. move->[sector N] (if [sector 4] then jump 6.)
; 4. inquire (got next [sector N])
; 5. move->[sector N] (jump 4. until [sector 4])
; 6. show x 2
; 7. inquire (jump SCENE 6)

; modified interactive script:
; OPTION A {
; 	1. tease (tease replaced with inquire)
; 	2. inquire (got [sector N], move added)
; 	3. move->[sector N] (if [sector 4] then jump 6.)
; 	4. inquire (got [sector N])
; 	5. move->[sector N] (jump 4. until [sector 4], else jump 6.)
; 	6. yell
; 	7. move->hangout
; 	8. peek
; 	9. move->[sector 4]
; 	10. show
; 	11. inquire (jump SCENE 6)
; }
; OPTION B {
; 	1. tease (tease replaced with inquire)
; 	2. drink
; 	3. inquire
; 	3. move->[sectors 1-3]
; 	4.x yell or show (game over, restart SCENE 5)
; }

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene5_subs:
		JSR		_s5_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_20579
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s5_sub00_clear
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_generic_menu_input
		SW_PTR	_s5_menu_handlers
		SW_PTR	_s5_sub05_bar_draw
		SW_PTR	_s5_sub06_bar_start_message
		SW_PTR	_s5_sub02_bar_main_loop
		SW_PTR	_s5_sub08_area1_draw
		SW_PTR	_s5_sub09_area2_draw
		SW_PTR	_s5_sub0A_area3_draw
		SW_PTR	_s5_sub0B_area4_draw
		SW_PTR	_s5_sub0F_area_arrival_msg
		SW_PTR	_s5_sub0C_area_check_loop
		SW_PTR	_s5_sub10_game_over_msg
		SW_PTR	_s5_sub0D_game_over_prizon

locret_20579:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_sub00_clear:
		LDA		#0
		STA		_scroll_x_shadow+1
		SW_NXT	_s5_sub05_bar_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_sub02_bar_main_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_205CB
		SW_RET	_s5_sub02_bar_main_loop
		SW_NXT	_generic_menu_input
		LDA		#0
		STA		_scene_menu_idx
		STA		_scene_anim_idx+2				; reset owner's hand by default
		JSR		_s5_menu_init0
		JMP		_menu_draw_request
locret_205CB:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_sub05_bar_draw:
		SW_NXT	_s5_sub06_bar_start_message
		LDA		#1
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_tlm1E_draw:
		LDA		#0
		STA		_scene_area_idx_tmp
		TLM4	$15,$34,$1E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_sub06_bar_start_message:
		JSR		_snd_hideout_ambient
		SW_NXT	_s5_sub02_bar_main_loop
		LDA		_scene_flags
		AND		#1
		BNE		loc_20631
		MSG_1	_sc5_msg00						; owner starting message
loc_20631:
		MSG_1	_sc5_msg01						; owner return message

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_sub08_area1_draw:
		JSR		_snd_area_mus_reset_start
		SW_NXT	_s5_sub0F_area_arrival_msg
		LDA		#0
		STA		_msg_display_number
		LDA		#2
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_tlm1A_draw:
		LDA		#1
		STA		_scene_area_idx_tmp
		TLM4	$11,$F,$1A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_sub09_area2_draw:
		JSR		_snd_area_mus_reset_start
		SW_NXT	_s5_sub0F_area_arrival_msg
		LDA		#1
		STA		_msg_display_number
		LDA		#3
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_tlm1B_draw:
		LDA		#2
		STA		_scene_area_idx_tmp
		TLM4	$12,$F,$1B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_sub0A_area3_draw:
		JSR		_snd_area_mus_reset_start
		SW_NXT	_s5_sub0F_area_arrival_msg
		LDA		#2
		STA		_msg_display_number
		LDA		#4
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_tlm1C_draw:
		LDA		#3
		STA		_scene_area_idx_tmp
		TLM4	$13,$F,$1C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_sub0B_area4_draw:
		JSR		_snd_area_mus_reset_start
		SW_NXT	_s5_sub0F_area_arrival_msg
		LDA		#3
		STA		_msg_display_number
		LDA		#5
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_tlm1D_draw:
		LDA		#4
		STA		_scene_area_idx_tmp
		TLM4	$14,$F,$1D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_sub0C_area_check_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_206B6
		SW_RET	_s5_sub0C_area_check_loop
		SW_NXT	_generic_menu_input
		LDA		#1
		STA		_scene_menu_idx
		JSR		_scene_menu_init_default5
		JMP		_menu_draw_request
locret_206B6:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_sub0F_area_arrival_msg:
		SW_NXT	_s5_sub0C_area_check_loop
		MSG_1	_sc5_msg03

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_sub10_game_over_msg:
		JSR		_snd_police_sirens
		SW_FADE	_s5_sub0D_game_over_prizon
		MSG_M
		MSG		_sc5_msg17
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_sub0D_game_over_prizon:
		JSR		_scene_vars_init
		LDX		#5
		LDY		#0								; start from the beginning, let it be just zero here
		JMP		_game_over_prison_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_snd_area_mus_reset_start:
		JSR		_apu_reset
		JMP		_snd_search_tetsuo_ambient

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu_init0:
		LDX		#0
		LDA		_scene_flags
		AND		#1
		BNE		loc_2074E
		LDA		_scene_flags					; inquired for kaneda before go
		AND		#8
		BEQ		loc_2072D
		LDA		#0
		STA		_scene_menu_items,X
		INX
loc_2072D:
		LDA		_scene_flags					; why inquire enabled by peek?
;		AND		#2								; should be enabled by tease!
		AND		#4
		BEQ		loc_2073B
		LDA		#1
		STA		_scene_menu_items,X				; replace tease with inquire
		INX
		BNE		loc_2073A
loc_2073B:
		LDA		#3
		STA		_scene_menu_items,X				; tease only once
		INX
loc_2073A:
		LDA		#2
		STA		_scene_menu_items,X
		INX
		LDA		#4
		STA		_scene_menu_items,X
		BNE		loc_20766
loc_2074E:
		LDA		_scene_flags					; we already inquiring for kaneda
		AND		#8								; let's enable move here then by default
		BEQ		loc_2075B
		LDA		#0
		STA		_scene_menu_items,X
		INX
loc_2075B:
		LDA		#1
		STA		_scene_menu_items,X				; in case we forgot the area, we can ask again
		INX
		LDA		#2
		STA		_scene_menu_items,X
		INX
		LDA		#4								; why drink is not an option, when we return back?
		STA		_scene_menu_items,X
loc_20766:
		STX		_scene_menu_max_pos
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu_init2:
		LDX		#0
		LDY		#0
loc_20775:
		CPX		_scene_area_idx_tmp
		BEQ		loc_2077F
		TXA
		STA		_scene_menu_items,Y
		INY
loc_2077F:
		INX
		CPX		#5
		BCC		loc_20775
		DEY
		STY		_scene_menu_max_pos
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu_handlers:
		JSR		_menu_switch
		.WORD _s5_menu0
		.WORD _s5_menu1
		.WORD _s5_menu2
_s5_menu0:
		.WORD _s5_menu0_move
		.WORD _s5_menu0_inquire
		.WORD _s5_menu0_peek
		.WORD _s5_menu0_tease
		.WORD _s5_menu0_drink
_s5_menu1:
		.WORD _s5_menu1_yell
		.WORD _s5_menu1_search
		.WORD _s5_menu1_show
		.WORD _s5_menu1_inquire
		.WORD _s5_menu1_move
_s5_menu2:
		.WORD _s5_menu2_hangout
		.WORD _s5_menu2_1_area
		.WORD _s5_menu2_2_area
		.WORD _s5_menu2_3_area
		.WORD _s5_menu2_4_area

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu0_move:
		SW_RET	_s5_sub02_bar_main_loop

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu2_move_start:
		SW_NXT	_generic_menu_input
		LDA		#2
		STA		_scene_menu_idx
		JSR		_s5_menu_init2
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu0_inquire:
		SW_NXT	_s5_sub02_bar_main_loop
		LDA		_scene_flags					; we have 1 here only if 8 already were set
		AND		#1
		BNE		loc_2081E
		LDA		_scene_flags
		AND		#8
		BNE		loc_20803
		LDA		_rand
		AND		#3
		STA		_starting_area_num
loc_20803:
		LDA		_scene_flags					; inquiring for kaneda, area selected
		ORA		#8
		STA		_scene_flags
		JSR		_s5_inquire_init_start
		LDA		_starting_area_num
		STA		_msg_display_number
		MSG_1	_sc5_msgB3						; initial "headed toward" message
loc_2081E:
		JSR		_s5_inquire_init_continue
		LDA		_starting_area_num
		STA		_msg_display_number
		MSG_1	_sc5_msg14						; simple "headed toward" message

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_inquire_init_start:
		LDA		#2
		STA		_scene_states
		STA		_scene_states+1
		STA		_scene_states+2
		STA		_scene_states+3
		LDA		_starting_area_num
		CLC
		ADC		#1
		AND		#3
		TAX
		LDA		#0
		STA		_scene_states,X
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_inquire_init_continue:
		LDA		_starting_area_num
		SWITCH
		SW_PTR	_s5_area1_inquire_init_continue
		SW_PTR	_s5_area2_inquire_init_continue
		SW_PTR	_s5_area3_inquire_init_continue
		SW_PTR	_s5_area4_inquire_init_continue

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu0_peek:
		SW_NXT	_s5_sub02_bar_main_loop
		LDA		_scene_flags
;		AND		#1								; maybe the error is here too? shouldn't it be 2?
		AND		#2
		BNE		loc_2084D
		LDA		_scene_flags					; now you can't get pills by default, you must know
		AND		#$40							; you need them
		BEQ		.3434
		LDA		#1
		STA		_scene_anim_idx+2				; raise owner's hand
		LDA		_scene_flags					; we don't need to enable inquire here (it's 4 now)
		ORA		#2								; instead we just have the pills flag
		STA		_scene_flags
		MSG_M
		MSG		_sc5_msg12						; let's make use the unused line, as if kaneda
		MSG		_sc5_msg18						; actually stolen those pills
		MSG		_sc5_msg02
		MSG_EOL
.3434:
		MSG_1	_sc5_msg12						; "hiding pills"
loc_2084D:
		MSG_1	_sc5_msg13						; "i don't have anymore"

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu0_tease:
		LDA		_scene_flags					; let's use 4 flag to enable inquire only if tease used
		ORA		#4
		STA		_scene_flags
		SW_NXT	_s5_sub02_bar_main_loop
		MSG_M
		MSG		_sc5_msg10
		MSG		_sc5_msg11
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu0_drink:
		SW_NXT	_s5_sub02_bar_main_loop
		LDA		_scene_flags					; drink flag
;		ORA		#$1								; it seems we have error here!
		ORA		#$10							; actual drink flag!
		STA		_scene_flags
		MSG_1	_sc5_A_msg7F

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu1_yell:
		SW_NXT	_s5_sub0C_area_check_loop
		LDX		_scene_area_idx_tmp
		DEX
		TXA
		SWITCH
		SW_PTR	_s5_area123_yell
		SW_PTR	_s5_area123_yell
		SW_PTR	_s5_area123_yell
		SW_PTR	_s5_area4_yell

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area123_yell:
		LDA		_scene_flags					; add more drunk gameovers here
		AND		#$10
		BNE		_s5_drink_game_over
		MSG_1	_sc5_6_15_msgAB

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area4_yell:
		LDA		_scene_flags					; let's make it more difficult
		ORA		#$40							; to bring a pills
		STA		_scene_flags
		MSG_M
		MSG		_sc5_6_15_msgAB
		MSG		_sc5_msg0B
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu1_search:
		SW_NXT	_s5_sub0C_area_check_loop
		LDX		_scene_area_idx_tmp
		DEX
		TXA
		SWITCH
		SW_PTR	_s5_area1_search
		SW_PTR	_s5_area2_search
		SW_PTR	_s5_area3_search
		SW_PTR	_s5_area4_search

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area1_search:
		MSG_1	_sc5_msg04

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area2_search:
		MSG_M
		MSG		_sc5_msg0D
		MSG		_sc5_msg15
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area3_search:
		MSG_M
		MSG		_sc5_msg0E
		MSG		_sc5_msg15
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area4_search:
		MSG_M
		MSG		_sc5_msg0F
		MSG		_sc5_msg15
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu1_show:
		SW_NXT	_s5_sub0C_area_check_loop
		LDX		_scene_area_idx_tmp
		DEX
		TXA
		SWITCH
		SW_PTR	_s5_area13_show
		SW_PTR	_s5_area2_show
		SW_PTR	_s5_area13_show
		SW_PTR	_s5_area4_show

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area13_show:
		LDA		_scene_flags					; add more drunk gameovers here
		AND		#$10
		BNE		_s5_drink_game_over

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_show_default_msg:
		MSG_1	_sc5_msg06						; "jerks are way too loud"

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_drink_game_over:
		SW_NXT	_s5_sub10_game_over_msg			; never used before
		MSG_M
		MSG		_sc5_msg16
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area2_show:
		LDA		_scene_flags					; add more drunk gameovers here
		AND		#$10
		BNE		_s5_drink_game_over
		MSG_1	_sc5_msg09						; "what is your rush"

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area4_show:
		LDA		_scene_states					; sector 4 menu
		SWITCH
		SW_PTR	_s5_area4_show_A
		SW_PTR	_s5_show_default_msg
		SW_PTR	_s5_show_default_msg
		SW_PTR	_s5_area4_show_A
		SW_PTR	_s5_area4_show_A
		SW_PTR	_s5_show_default_msg
		SW_PTR	_s5_area4_show_B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area4_show_A:
		LDA		_scene_flags
		AND		#2								; check if we really have a pills now
		BEQ		.2133
		LDA		#6
		STA		_scene_states
		LDA		_scene_flags					; got pills finally
		ORA		#$20
		STA		_scene_flags
		MSG_M
		MSG		_sc5_msg1A
		MSG		_sc5_msg0C						; "so you brought me some pills?"
		MSG_EOL
.2133:
		JMP		_s5_show_default_msg

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area4_show_B:
		MSG_1	_sc5_msg0C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu1_inquire:
		SW_NXT	_s5_sub0C_area_check_loop
		LDX		_scene_area_idx_tmp
		DEX
		TXA
		SWITCH
		SW_PTR	_s5_menu1_area1_inquire
		SW_PTR	_s5_menu1_area2_inquire
		SW_PTR	_s5_menu1_area3_inquire
		SW_PTR	_s5_menu1_area4_inquire

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu1_area1_inquire:
		LDA		_scene_states+1
		SWITCH
		SW_PTR	_s5_menu1_area1_inquire_A
		SW_PTR	_s5_msgA4
		SW_PTR	_s5_msgA4
		SW_PTR	_s5_msgA4
		SW_PTR	_s5_msg05
		SW_PTR	_s5_msgA4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu1_area1_inquire_A:
		LDA		#3
		STA		_scene_states+1
		LDA		#3
		STA		_scene_states+2

; !FALLTHROUGH!
;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_msg05:
		MSG_1	_sc5_msg05

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_msgA4:
		MSG_1	_sc5_6_msgA4					; "man ..."

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu1_area2_inquire:
		LDA		_scene_states+2
		SWITCH
		SW_PTR	_s5_menu1_area2_inquire_A
		SW_PTR	_s5_show_default_msg
		SW_PTR	_s5_show_default_msg
		SW_PTR	_s5_menu1_area2_inquire_A
		SW_PTR	_s5_show_default_msg
		SW_PTR	_s5_menu1_area2_inquire_A
		SW_PTR	_s5_show_default_msg

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu1_area2_inquire_A:
		LDA		#4
		STA		_scene_states+2
		LDA		#3
		STA		_scene_states+3
		MSG_1	_sc5_msg08

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu1_area3_inquire:
		LDA		_scene_states+3
		SWITCH
		SW_PTR	_s5_menu1_area3_inquire_A
		SW_PTR	_s5_msgA4
		SW_PTR	_s5_msgA4
		SW_PTR	_s5_menu1_area3_inquire_A
		SW_PTR	_s5_msgA4
		SW_PTR	_s5_menu1_area3_inquire_A
		SW_PTR	_s5_msgA4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu1_area3_inquire_A:
		LDA		#4
		STA		_scene_states+3
		LDA		#3
		STA		_scene_states
		MSG_1	_sc5_msg0A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu1_area4_inquire:
		LDA		_scene_flags
		AND		#$20
		BNE		loc_20ADC
		JMP		_s5_msgA4
loc_20ADC:
		SW_FADE	_next_scene
		MSG_M
		MSG		_sc5_msg19
		MSG_WAIT								; "tetsuo toward factory"
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu1_move:
		SW_RET	_s5_sub0C_area_check_loop
		JMP		_s5_menu2_move_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu2_hangout:
		LDA		_scene_flags					; return to hangout flag
		ORA		#1
		STA		_scene_flags
		SW_NXT	_s5_sub00_clear
		JMP		_fade_out_reqest

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu2_1_area:
		SW_NXT	_s5_sub08_area1_draw			; may be optimized if not using macroses ;(
		BNE		_s5_menu2_area_selected			; SW_NXT is non zero here, be careful!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu2_2_area:
		SW_NXT	_s5_sub09_area2_draw
		BNE		_s5_menu2_area_selected

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu2_3_area:
		SW_NXT	_s5_sub0A_area3_draw
		BNE		_s5_menu2_area_selected

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu2_4_area:
		SW_NXT	_s5_sub0B_area4_draw

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_menu2_area_selected:
		JSR		_s5_area_flags_setup
		JMP		_fade_out_reqest

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area_flags_setup:
		LDA		_scene_flags
		AND		#1
		BNE		loc_20C0C
		LDX		_cur_scene_menu_pos
		LDA		_scene_menu_items,X
		TAX
		DEX
		CPX		_starting_area_num
		BEQ		locret_20BC6
		LDA		_starting_area_num
		SWITCH
		SW_PTR	_s5_area1_flags_start
		SW_PTR	_s5_area2_flags_start
		SW_PTR	_s5_area3_flags_start
		SW_PTR	_s5_area4_flags_start
loc_20C0C:
		LDX		_cur_scene_menu_pos
		LDA		_scene_menu_items,X
		TAX
		DEX
		CPX		_starting_area_num
		BEQ		locret_20BC6
		LDA		_starting_area_num
		SWITCH
		SW_PTR	_s5_area1_flags_continue
		SW_PTR	_s5_area2_flags_continue
		SW_PTR	_s5_area3_flags_continue
		SW_PTR	_s5_area4_flags_continue
locret_20BC6:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area4_flags_start:
		LDA		#1
		BNE		_scene_state0_set

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area4_inquire_init_continue:
		LDA		#4
		BNE		_scene_state0_set

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area4_flags_continue:
		LDA		#5

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene_state0_set:
		STA		_scene_states
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area1_flags_start:
		LDA		#1
		BNE		_scene_state1_set

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area1_inquire_init_continue:
		LDA		#4
		BNE		_scene_state1_set

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area1_flags_continue:
		LDA		#5

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene_state1_set:
		STA		_scene_states+1
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area2_flags_start:
		LDA		#1
		BNE		_scene_state2_set

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area2_inquire_init_continue:
		LDA		#5
		BNE		_scene_state2_set

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area2_flags_continue:
		LDA		#6

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene_state2_set:
		STA		_scene_states+2
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area3_flags_start:
		LDA		#1
		BNE		_scene_state3_set

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area3_inquire_init_continue:
		LDA		#5
		BNE		_scene_state3_set

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_area3_flags_continue:
		LDA		#6

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene_state3_set:
		STA		_scene_states+3
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s5_spr_overlay1
		SW_PTR	_s5_spr_overlay2
		SW_PTR	_s5_spr_overlay3
		SW_PTR	_s5_spr_overlay4
		SW_PTR	_s5_spr_overlay5

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_spr_overlay1:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0SW	off_20CD0,$30,$78
		JSR		_get_anim_blink_idx
		SPR0SW	off_20CD6,$30,$78				; 1,2 eyes blink
		LDA		_scene_anim_idx+2				; 0,1 here
		SPR0JSW	off_20CDC,$30,$78
off_20CD0:
		.WORD byte_20DF9
		.WORD byte_20DF0
off_20CD6:
		.WORD byte_20E02
		.WORD byte_20E0B
off_20CDC:
		.WORD byte_20E14
		.WORD byte_20E31

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_spr_overlay2:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0SW	off_20D12,$40,$20
		SPR0J	byte_20E5A,$40,$20
off_20D12:
		.WORD byte_20EB8
		.WORD byte_20EB3

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_spr_overlay3:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0SW	off_20D48,$48,$50
		SPR0J	byte_20EBD,$48,$50
off_20D48:
		.WORD byte_20F1F
		.WORD byte_20F16

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_spr_overlay4:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0SW	off_20DAE,$3C,$38
		SPR0	byte_20F28,$3C,$38
		JSR		_do_scene_anim1_pat0101
		LDA		_scene_anim_idx+1
		SPR0SW	off_20DB4,$54,$60
		SPR0J	byte_20F5F,$54,$60
off_20DAE:
		.WORD byte_20F5A
		.WORD byte_20F55
off_20DB4:
		.WORD byte_20F85
		.WORD byte_20F80

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s5_spr_overlay5:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0SW	off_20DEA,$50,$60
		SPR0J	byte_20F8A,$50,$60
off_20DEA:
		.WORD byte_20FD0
		.WORD byte_20FC7

byte_20DF0:
		.BYTE   8,$EC,  1,  0
		.BYTE   8,$ED,  1,  8
		.BYTE $80
byte_20DF9:
		.BYTE   8,$EE,  1,  0
		.BYTE   8,$EF,  1,  8
		.BYTE $80
byte_20E02:
		.BYTE   0,$E8,  1,  0
		.BYTE   0,$E9,  1,  8
		.BYTE $80
byte_20E0B:
		.BYTE   0,$EA,  1,  0
		.BYTE   0,$EB,  1,  8
		.BYTE $80
byte_20E14:
		.BYTE $18,$D7,  1,$20
		.BYTE $20,$D9,  1,$28
		.BYTE $28,$DC,  1,$28
		.BYTE $30,$E0,  1,$20
		.BYTE $30,$E1,  1,$28
		.BYTE $38,$E2,  1,$20
		.BYTE $38,$E3,  1,$28
		.BYTE $80
byte_20E31:
		.BYTE $10,$D8,  1,$18
		.BYTE $18,$DA,  1,$18
		.BYTE $18,$DB,  1,$20
		.BYTE $20,$DD,  1,$10
		.BYTE $20,$DE,  1,$18
		.BYTE $20,$DF,  1,$20
		.BYTE $28,$E4,  1,$18
		.BYTE $28,$E5,  1,$20
		.BYTE $30,$E6,  1,$18
		.BYTE $30,$E7,  1,$20
		.BYTE $80
byte_20E5A:
		.BYTE   0,$B0,  1,  8
		.BYTE   0,$B1,  1,$10
		.BYTE   8,$B3,  1,$10
		.BYTE $10,$B4,  1,  0
		.BYTE $10,$B5,  1,  8
		.BYTE $10,$B6,  1,$10
		.BYTE $10,$B7,  1,$18
		.BYTE $18,$B8,  1,  0
		.BYTE $18,$B9,  1,  8
		.BYTE $18,$BA,  1,$10
		.BYTE $18,$BB,  1,$18
		.BYTE $20,$BC,  1,  0
		.BYTE $20,$BD,  1,  8
		.BYTE $20,$BE,  1,$10
		.BYTE $20,$BF,  1,$18
		.BYTE $28,$C0,  1,  8
		.BYTE $28,$C1,  1,$10
		.BYTE $28,$C2,  1,$18
		.BYTE $30,$C3,  1,$10
		.BYTE $30,$C4,  1,$18
		.BYTE $38,$C5,  1,$10
		.BYTE $38,$C6,  1,$18
		.BYTE $80
byte_20EB3:
		.BYTE   8,$B2,  1,  8
		.BYTE $80
byte_20EB8:
		.BYTE   8,$A7,  1,  8
		.BYTE $80
byte_20EBD:
		.BYTE   0,$EC,  1,  8
		.BYTE   0,$ED,  1,$10
		.BYTE   8,$EE,  1,  8
		.BYTE   8,$EF,  1,$10
		.BYTE $10,$F0,  1,  0
		.BYTE $10,$F3,  1,$18
		.BYTE $18,$F4,  1,  0
		.BYTE $18,$F5,  1,  8
		.BYTE $18,$F6,  1,$10
		.BYTE $18,$F7,  1,$18
		.BYTE $20,$F8,  1,  0
		.BYTE $20,$F9,  1,  8
		.BYTE $20,$FA,  1,$10
		.BYTE $20,$FB,  1,$18
		.BYTE $28,$FC,  1,  0
		.BYTE $28,$FD,  1,  8
		.BYTE $28,$FE,  1,$10
		.BYTE $28,$FF,  1,$18
		.BYTE $30,$A3,  1,  0
		.BYTE $30,$A4,  1,  8
		.BYTE $30,$A5,  1,$10
		.BYTE $30,$A6,  1,$18
		.BYTE $80
byte_20F16:
		.BYTE $10,$F1,  1,  8
		.BYTE $10,$F2,  1,$10
		.BYTE $80
byte_20F1F:
		.BYTE $10,$AD,  1,  8
		.BYTE $10,$AE,  1,$10
		.BYTE $80
byte_20F28:
		.BYTE   0,$C7,  3,  8
		.BYTE   8,$C8,  3,  0
		.BYTE   8,$CA,  3,$10
		.BYTE $10,$CB,  3,  8
		.BYTE $10,$CC,  3,$10
		.BYTE $18,$CD,  3,  8
		.BYTE $18,$CE,  3,$10
		.BYTE $20,$CF,  3,  8
		.BYTE $20,$D0,  3,$10
		.BYTE $28,$D1,  3,  8
		.BYTE $28,$D2,  3,$10
		.BYTE $80
byte_20F55:
		.BYTE   8,$C9,  3,  8
		.BYTE $80
byte_20F5A:
		.BYTE   8,$A9,  3,  8
		.BYTE $80
byte_20F5F:
		.BYTE   0,$D3,  1,  0
		.BYTE   0,$D4,  1,  8
		.BYTE   0,$D3,$41,$10
		.BYTE   8,$D5,  1,  0
		.BYTE   8,$D7,  1,$10
		.BYTE $10,$D8,  1,  0
		.BYTE $10,$D9,  1,  8
		.BYTE $10,$DA,  1,$10
		.BYTE $80
byte_20F80:
		.BYTE   8,$D6,  1,  8
		.BYTE $80
byte_20F85:
		.BYTE   8,$AA,  1,  8
		.BYTE $80
byte_20F8A:
		.BYTE   0,$DB,  3,  0
		.BYTE   0,$DC,  3,  8
		.BYTE   8,$DF,  3,$10
		.BYTE $10,$E0,  3,  0
		.BYTE $10,$E1,  3,  8
		.BYTE $10,$E2,  3,$10
		.BYTE $18,$E3,  3,  0
		.BYTE $18,$E4,  3,  8
		.BYTE $18,$E5,  3,$10
		.BYTE $20,$E6,  3,  0
		.BYTE $20,$E7,  3,  8
		.BYTE $20,$E8,  3,$10
		.BYTE $28,$E9,  3,  0
		.BYTE $28,$EA,  3,  8
		.BYTE $28,$EB,  3,$10
		.BYTE $80
byte_20FC7:
		.BYTE   8,$DD,  3,  0
		.BYTE   8,$DE,  3,  8
		.BYTE $80
byte_20FD0:
		.BYTE   8,$AB,  3,  0
		.BYTE   8,$AC,  3,  8
		.BYTE $80

		SECTION_END 5
