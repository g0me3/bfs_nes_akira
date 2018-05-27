
		SECTION_START 7

;-----------------------------------------------
; SCENE 7
;-----------------------------------------------

; original interactive script:
; 1. inquire->kai->about army
; 2. inquire->yamagata->about kid
; 3. inquire->groupie->about akira
; 4. inquire->groupie->about tetsuo
; 5. look->terrorists x 2
; 6. check
; 7. inquire (move added)
; 8. move->[sector 2] (jump SCENE 8)
; 8.x move->[sector 4] (game over, restart SCENE 7)

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene7_subs:
		JSR		_s7_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_38038
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s7_sub00_clear
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_generic_menu_input
		SW_PTR	_s7_menu_handlers				; should be 4!
		SW_PTR	_s7_sub05_mall_draw
		SW_PTR	_s7_sub06_mall_msg0
		SW_PTR	_s7_sub08_clear
		SW_PTR	_s7_sub09_kaneda_icon1_draw
		SW_PTR	_s7_sub0A_kaneda_msgs
		SW_PTR	_s7_sub0B_mall_redraw
		SW_PTR	_s7_sub0C_mall_msg1
		SW_PTR	_s7_sub02_mall_menu_loop
		SW_PTR	_s7_sub10_explosion_init		; disable sprites first
		SW_PTR	_s7_sub10_explosion_snd_draw
		SW_PTR	_s7_sub11_explosion_msgs
		SW_PTR	_s7_sub16_explosion_menu_loop
		SW_PTR	_s7_sub18_army_chase_draw
		SW_PTR	_s7_sub19_army_chase_msg
		SW_PTR	_s7_sub14_fade_out
		SW_PTR	_s7_sub0D_clear
		SW_PTR	_s7_sub0E_kaneda_icon2_draw
		SW_PTR	_s7_sub13_girl_icon0_draw
		SW_PTR	_s7_sub0F_girl_kaneda_snd_msg
		SW_PTR	_s7_sub1C_area1_draw
		SW_PTR	_s7_sub20_area1_msg
		SW_PTR	_s7_sub1B_area_select_menu_loop
		SW_PTR	_s7_sub1D_area2_draw
		SW_PTR	_s7_sub1E_area3_draw
		SW_PTR	_s7_sub22_area3_msg
		SW_PTR	_s7_sub1F_area4_draw
		SW_PTR	_s7_sub23_area4_msg
		SW_PTR	_s7_sub21_final_msg
		SW_PTR	_s7_sub24_area4_game_over
		SW_PTR	_s7_sub25_explosion_redraw

locret_38038:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub00_clear:
		SW_NXT	_s7_sub05_mall_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub05_mall_draw:
		SW_NXT	_s7_sub06_mall_msg0
		LDA		#$6D
		JSR		_pal_lib_load
		LDA		#2
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_tlm20_draw:
		TLM5	$19,$10,$20

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub06_mall_msg0:
		JSR		_snd_walkway_noise				; strange noise
		SW_FADE	_s7_sub08_clear
		MSG_M
		MSG		_sc7_msgBB
		MSG		_sc7_msg28
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub08_clear:
		SW_NXT	_s7_sub09_kaneda_icon1_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub09_kaneda_icon1_draw:
		SW_NXT	_s7_sub0A_kaneda_msgs
		LDA		#1
		STA		_scene_spr_overlay_idx
		ICON1	$18,$11,$22

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub0A_kaneda_msgs:
		SW_FADE	_s7_sub0B_mall_redraw
		MSG_M
		MSG		_sc7_msgBC
		MSG		_sc7_msgBD
		MSG		_sc7_msg29
		MSG		_sc7_msg2A
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub0B_mall_redraw:
		SW_NXT	_s7_sub0C_mall_msg1
		LDA		#2
		STA		_scene_spr_overlay_idx
		JMP		_s7_tlm20_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub0C_mall_msg1:
		SW_NXT	_s7_sub02_mall_menu_loop
		MSG_M
		MSG		_sc7_msgBE
		MSG		_sc7_msg1F
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub02_mall_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_380A7
		SW_RET	_s7_sub02_mall_menu_loop
		LDA		#0
		JSR		_s7_menus_init
		JMP		_menu_draw_request
locret_380A7:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub10_explosion_init:
		JSR		_apu_reset						; dummy between two areas with
		LDA		#0								; overlays but different CHRs
		STA		_scene_spr_overlay_idx			; to avoid garbage displaying
		SW_NXT	_s7_sub10_explosion_snd_draw
		SW_CUR	_s7_sub10_explosion_snd_draw
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub10_explosion_snd_draw:
		JSR		_snd_walkway_explosion
		SW_NXT	_s7_sub11_explosion_msgs
		LDA		#4
		STA		_scene_spr_overlay_idx
		LDA		#0
		STA		_scene_anim_idx					; init explosion anim
		LDA		#$10
		STA		_tmp_cnt0
		LDA		#$6B
		JSR		_chr_lib_banks_load
		LDA		#6
		JMP		_delay							; animation delay

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub11_explosion_msgs:
		SW_NXT	_s7_sub16_explosion_menu_loop
		MSG_M
		MSG		_sc7_msg11
		MSG		_sc7_msg12
		MSG		_sc7_msg13
		MSG		_sc7_msg14
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub16_explosion_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_38209
		SW_RET	_s7_sub16_explosion_menu_loop
		LDA		#3
		JSR		_s7_menus_init
		JMP		_menu_draw_request
locret_38209:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub18_army_chase_draw:
		SW_NXT	_s7_sub19_army_chase_msg
		LDA		#0
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_tlm25_draw:
		TLM5	$1A,$12,$25

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub19_army_chase_msg:
		SW_NXT	_s7_sub16_explosion_menu_loop
		MSG_1	_sc7_msg19

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub14_fade_out:
		SW_NXT	_s7_sub0D_clear
		JMP		_fade_out_reqest

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub0D_clear:
		SW_NXT	_s7_sub0E_kaneda_icon2_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub0E_kaneda_icon2_draw:
		SW_NXT	_s7_sub13_girl_icon0_draw
		LDA		#3
		STA		_scene_spr_overlay_idx
		ICON2EX	$22								; kaneda icon withou setting CHR/PAL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub13_girl_icon0_draw:
		SW_NXT	_s7_sub0F_girl_kaneda_snd_msg
		ICON0	$18,$11,$23						; girl icon with setting CHR/PAL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub0F_girl_kaneda_snd_msg:
		JSR		_snd_girl_detected
		SW_NXT	_s7_sub16_explosion_menu_loop
		MSG_1	_sc7_msg17

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub1C_area1_draw:
		JSR		_snd_search_tetsuo_ambient
		SW_NXT	_s7_sub20_area1_msg
		FJMP	_s5_tlm1A_draw					; used once here

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub20_area1_msg:
		SW_NXT	_s7_sub1B_area_select_menu_loop
		MSG_1	_sc7_msg20

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub1B_area_select_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_3823C
		SW_RET	_s7_sub1B_area_select_menu_loop
		LDA		#5
		JSR		_s7_menus_init
		JMP		_menu_draw_request
locret_3823C:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub1D_area2_draw:
		JSR		_snd_search_tetsuo_ambient
		SW_NXT	_s7_sub21_final_msg
		LDA		#6
		STA		_scene_spr_overlay_idx
		FJMP	_s5_tlm1B_draw					; used once here

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub21_final_msg:
		SW_FADE	_next_scene
		MSG_M
		MSG		_sc7_msg21
		MSG		_sc7_msg22
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub1E_area3_draw:
		JSR		_snd_search_tetsuo_ambient
		SW_NXT	_s7_sub22_area3_msg
		LDA		#7
		STA		_scene_spr_overlay_idx
		FJMP	_s5_tlm1C_draw					; used once here

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub22_area3_msg:
		SW_NXT	_s7_sub1B_area_select_menu_loop
		MSG_M
		MSG		_sc7_msg23
		MSG		_sc7_msg24
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub1F_area4_draw:
		JSR		_snd_search_tetsuo_ambient
		SW_NXT	_s7_sub23_area4_msg
		LDA		#8
		STA		_scene_spr_overlay_idx
		FJMP	_s5_tlm1D_draw					; used once here

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub23_area4_msg:
		SW_FADE	_s7_sub24_area4_game_over
		MSG_M
		MSG		_sc7_msg25
		MSG		_sc7_msg26
		MSG		_sc7_msg27
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub24_area4_game_over:
		JSR		_scene_vars_init
		LDX		#7
		LDY		#_s7_sub25_explosion_redraw_sidx
		JMP		_game_over_dead_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_sub25_explosion_redraw:
		SW_NXT	_s7_sub10_explosion_init
		JMP		_s7_tlm20_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menus_init:
		STA		_scene_menu_idx
		SW_NXT	_generic_menu_input
		LDA		_scene_menu_idx
		SWITCH
		SW_PTR	_scene_menu_init_default1
		SW_PTR	_scene_menu_init_default3
		SW_PTR	_scene_menu_init_default4
		SW_PTR	_s7_menu_init3
		SW_PTR	_scene_menu_init_default3
		SW_PTR	_s7_menu_init5

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu_init3:
		LDA		_scene_flags+1
		AND		#8
		BEQ		locret_38347
		JMP		_scene_menu_init_default4
locret_38347:
		JMP		_scene_menu_init_default3

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu_init5:
		LDX		#1								; start from 2nd option, since first is hangoun
		LDY		#0								; and we don't need it here
loc_38353:
		CPX		_scene_area_idx_tmp
		BEQ		loc_3835D
		TXA
		STA		_scene_menu_items,Y
		INY
loc_3835D:
		INX
		CPX		#5
		BCC		loc_38353
		DEY
		STY		_scene_menu_max_pos
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu_handlers:
		JSR		_menu_switch
		.WORD _s7_menu0
		.WORD _s7_menu1
		.WORD _s7_menu2
		.WORD _s7_menu3
		.WORD _s7_menu4
		.WORD _s7_menu5
_s7_menu0:
		.WORD _s7_menu0_inquire
_s7_menu1:
		.WORD _s7_menu1_yamagata
		.WORD _s7_menu1_kai
		.WORD _s7_menu1_groupie
_s7_menu2:
		.WORD _s7_menu2_about_tetsuo
		.WORD _s7_menu2_about_army
		.WORD _s7_menu2_about_kid
		.WORD _s7_menu2_about_akira
_s7_menu3:
		.WORD _s7_menu3_inquire
		.WORD _s7_menu3_look
		.WORD _s7_menu3_check
		.WORD _s7_menu3_move
_s7_menu4:
		.WORD _s7_menu4_gang
		.WORD _s7_menu4_terrorist
		.WORD _s7_menu4_walkway
_s7_menu5:
		.WORD 0									; dummy, unused
		.WORD _s7_menu5_area1
		.WORD _s7_menu5_area2
		.WORD _s7_menu5_area3
		.WORD _s7_menu5_area4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu0_inquire:
		LDA		#1
		JSR		_s7_menus_init
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu1_yamagata:
		LDA		#0
		BEQ		_s7_menu1_item_commont			; no fallthroug

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu1_kai:
		LDA		#1
		BNE		_s7_menu1_item_commont			; no fallthrough

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu1_groupie:
		LDA		#2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu1_item_commont:
		STA		_scene_states
		LDA		#2
		JSR		_s7_menus_init
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu2_about_tetsuo:
		LDA		_scene_states
		SWITCH
		SW_PTR	_s7_menu2_yamagata_about_tetsuo
		SW_PTR	_s7_menu2_kai_about_tetsuo
		SW_PTR	_s7_menu2_groupie_about_tetsuo

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu2_yamagata_about_tetsuo:
		SW_NXT	_s7_sub02_mall_menu_loop
		MSG_1	_sc7_msg04

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu2_kai_about_tetsuo:
		SW_NXT	_s7_sub02_mall_menu_loop
		MSG_1	_sc7_msg09

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu2_groupie_about_tetsuo:
		LDA		_scene_flags
		AND		#7
		CMP		#7
		BEQ		loc_38426
		SW_NXT	_s7_sub02_mall_menu_loop
		MSG_1	_sc7_msg0E
loc_38426:
		SW_NXT	_s7_sub10_explosion_init
		MSG_M
		MSG		_sc7_msg1D
		MSG		_sc7_msg1E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu2_about_army:
		SW_NXT	_s7_sub02_mall_menu_loop
		LDA		_scene_states
		SWITCH
		SW_PTR	_s7_menu2_yamagata_about_army
		SW_PTR	_s7_menu2_kai_about_army
		SW_PTR	_s7_menu2_groupie_about_army

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu2_yamagata_about_army:
		MSG_1	_sc7_msg05

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu2_kai_about_army:
		LDA		_scene_flags
		AND		#1
		BNE		loc_38475
		LDA		_scene_flags
		ORA		#1
		STA		_scene_flags
		MSG_1	_sc7_msg0A
loc_38475:
		MSG_1	_sc7_msg0B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu2_groupie_about_army:
		MSG_1	_sc7_msg0E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu2_about_kid:
		SW_NXT	_s7_sub02_mall_menu_loop
		LDA		_scene_states
		SWITCH
		SW_PTR	_s7_menu2_yamagata_about_kid
		SW_PTR	_s7_menu2_kai_about_kid
		SW_PTR	_s7_menu2_groupie_about_kid

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu2_yamagata_about_kid:
		LDA		_scene_flags
		AND		#1
		BNE		loc_384B2
		MSG_1	_sc7_msg06
loc_384B2:
		LDA		_scene_flags
		ORA		#2
		STA		_scene_flags
		MSG_1	_sc7_msg07

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu2_kai_about_kid:
		MSG_1	_sc7_msg0C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu2_groupie_about_kid:
		MSG_1	_sc7_msg0E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu2_about_akira:
		SW_NXT	_s7_sub02_mall_menu_loop
		LDA		_scene_states
		SWITCH
		SW_PTR	_s7_menu2_yamagata_about_akira
		SW_PTR	_s7_menu2_kai_about_akira
		SW_PTR	_s7_menu2_groupie_about_akira

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu2_yamagata_about_akira:
		MSG_1	_sc7_msg08

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu2_kai_about_akira:
		MSG_1	_sc7_msg0D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu2_groupie_about_akira:
		LDA		_scene_flags
		ORA		#4
		STA		_scene_flags
		MSG_M
		MSG		_sc7_msg0F
		MSG		_sc7_msg10
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu3_inquire:
		SW_NXT	_s7_sub16_explosion_menu_loop
		LDA		_scene_flags+1
		AND		#4
		BNE		loc_38530
		MSG_1	_sc7_msg15
loc_38530:
		LDA		_scene_flags+1
		ORA		#8
		STA		_scene_flags+1
		MSG_M
		MSG		_sc7_msg1A
		MSG		_sc7_msg1B
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu3_look:
		LDA		#4
		JSR		_s7_menus_init
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu3_check:
		SW_NXT	_s7_sub16_explosion_menu_loop
		LDA		_scene_flags+1
		AND		#2
		BNE		loc_3855F
		MSG_1	_sc7_msg18
loc_3855F:
		LDA		_scene_flags+1
		AND		#4
		BNE		loc_38576
		LDA		_scene_flags+1
		ORA		#4
		STA		_scene_flags+1
		SW_NXT	_s7_sub18_army_chase_draw
		JMP		_fade_out_reqest
loc_38576:
		SW_NXT	_s7_sub19_army_chase_msg
		SW_CUR	_s7_sub19_army_chase_msg
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu3_move:
		LDA		#0
		STA		_scene_area_idx_tmp				; init to impossible value before init here
		SW_RET	_s7_sub16_explosion_menu_loop
		LDA		#5
		JSR		_s7_menus_init
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu4_gang:
		SW_NXT	_s7_sub16_explosion_menu_loop
		MSG_1	_sc7_msg15

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu4_terrorist:
		SW_NXT	_s7_sub16_explosion_menu_loop
		LDA		_scene_flags+1
		AND		#1
		BNE		loc_385B3
		LDA		_scene_flags+1
		ORA		#1
		STA		_scene_flags+1
		MSG_1	_sc7_msg16
loc_385B3:
		LDA		_scene_flags+1
		AND		#4
		BNE		loc_385D6
		LDA		_scene_flags+1
		AND		#2
		BNE		loc_385D1
		LDA		_scene_flags+1
		ORA		#2
		STA		_scene_flags+1
		SW_NXT	_s7_sub14_fade_out
		SW_CUR	_s7_sub14_fade_out
		RTS
loc_385D1:
		MSG_1	_sc7_msg17
loc_385D6:
		MSG_1	_sc7_msg1C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu4_walkway:
		SW_NXT	_s7_sub16_explosion_menu_loop
		MSG_1	_sc7_msg18

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu5_area1:
		LDX		#_s7_sub1C_area1_draw_sidx
		LDY		#1
		BNE		_s7_menu5_item_common

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu5_area2:
		LDX		#_s7_sub1D_area2_draw_sidx
		LDY		#2
		BNE		_s7_menu5_item_common

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu5_area3:
		LDX		#_s7_sub1E_area3_draw_sidx
		LDY		#3
		BNE		_s7_menu5_item_common

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu5_area4:
		LDX		#_s7_sub1F_area4_draw_sidx
		LDY		#4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_menu5_item_common:
		STX		_scene_sub_reload
		STY		_scene_area_idx_tmp
		SW_NXT	_fade_out_reload_scene
		SW_CUR	_fade_out_reload_scene
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s7_spr_overlay1
		SW_PTR	_s7_spr_overlay2
		SW_PTR	_s7_spr_overlay3
		SW_PTR	_s7_spr_overlay4
;		EXOFS	_s5_spr_overlay2				; unused, since the line is "no one here as usual"
		.WORD 0
		EXOFS	_s5_spr_overlay3				; area 2 from scene 5
		EXOFS	_s5_spr_overlay4				; area 3 from scene 5
		EXOFS	_s5_spr_overlay5				; area 4 from scene 5

;-------------S-U-B-R-O-U-T-I-N-E---------------
;		FJMP	_s5_spr_overlay2				; 1 time here as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s5_spr_overlay3				; 1 time here as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s5_spr_overlay4				; 1 time here as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s5_spr_overlay5				; 1 time here as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_spr_overlay1:
		SPR0	_spr_sc7_kaneda_dreaming_head,$48,$70
		LDA		_frames_counter					; lets animate it instead
		ROL
		ROL
		AND		#1
		SPR0JSW	off_38692,$48,$70
off_38692:
		.WORD _spr_sc7_kaneda_dreaming_eyes_left	; this left eyes show here only
		.WORD _spr_sc7_kaneda_dreaming_eyes_right	; reused

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_spr_overlay2:
		SPR0	_spr_sc7_groupie_body,$48,$40
		SPR0	_spr_sc7_yamagata_kai_bodies,$40,$88
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0SW	off_3876F,$48,$40
		JSR		_do_scene_anim1_pat0101
		LDA		_scene_anim_idx+1
		SPR0SW	off_38775,$40,$88
		JSR		_do_scene_anim2_pat0101
		LDA		_scene_anim_idx+2
		SPR0JSW	off_3877B,$40,$88
off_3876F:
		.WORD _spr_sc7_groupie_mouth_open
		.WORD _spr_sc7_groupie_mouth_closed
off_38775:
		.WORD _spr_sc7_kai_mouth_open
		.WORD _spr_sc7_kai_mouth_closed
off_3877B:
		.WORD _spr_sc7_yamagata_mouth_open
		.WORD _spr_sc7_yamagata_mouth_closed

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_spr_overlay3:
		SPR0	_spr_sc7_kaneda_dreaming_head,$18,$C0		; reused dreaming kaneda from prev scene
		SPR0	_spr_sc7_kaneda_dreaming_eyes_left,$18,$C0	; but in different location
		JSR		_get_anim_blink_idx
		SPR0JSW	off_386BB,$30,$20
off_386BB:
		.WORD _spr_sc7_girl_eyes0
		.WORD _spr_sc7_girl_eyes1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s7_spr_overlay4:
		LDA		_tmp_cnt0
		BEQ		loc_38656
		DEC		_tmp_cnt0
		BNE		loc_38656
		LDA		#1
		STA		_scene_anim_idx
loc_38656:
		LDA		_scene_anim_idx
		SPR0JSW	off_B003A,$30,$40
off_B003A:
		.WORD _spr_sc7_explosion0
		.WORD _spr_sc7_explosion1

_spr_sc7_explosion0:
		.BYTE   8,$EC,  1,  0
		.BYTE   8,$EB,  1,$10
		.BYTE   8,$EB,  1,$18
		.BYTE   8,$EC,  1,$20
		.BYTE $10,$E0,  1,$10
		.BYTE $10,$EE,  1,$18
		.BYTE $18,$EF,  1,$10
		.BYTE $18,$FF,  1,$18
		.BYTE $80
_spr_sc7_explosion1:
		.BYTE   0,$DE,  1,$10
		.BYTE   0,$DF,  1,$18
		.BYTE   8,$E2,  1,  0
		.BYTE   8,$E0,  1,$10
		.BYTE   8,$E1,  1,$18
		.BYTE   8,$E2,  1,$20
		.BYTE $10,$E5,  1,  0
		.BYTE $10,$E6,  1,  8
		.BYTE $10,$E3,  1,$10
		.BYTE $10,$E4,  1,$18
		.BYTE $10,$E5,  1,$20
		.BYTE $10,$E6,  1,$28
		.BYTE $18,$E7,  1,  0
		.BYTE $18,$E8,  1,  8
		.BYTE $18,$E4,$41,$10
		.BYTE $18,$E4,  1,$18
		.BYTE $18,$E7,  1,$20
		.BYTE $18,$E8,  1,$28
		.BYTE $20,$EB,  1,  0
		.BYTE $20,$DE,$C1,  8
		.BYTE $20,$E9,  1,$10
		.BYTE $20,$EA,  1,$18
		.BYTE $20,$EB,  1,$20
		.BYTE $20,$DE,$C1,$28
		.BYTE $80
_spr_sc7_kaneda_dreaming_head:
		.BYTE   0,$8B,  3,  0
		.BYTE   0,$8C,  3,  8
		.BYTE   0,$8D,  3,$10
		.BYTE   8,$8E,  3,$10
		.BYTE   8,$8F,  3,$18
		.BYTE   8,$90,  3,$20
		.BYTE $18,$93,  3,  8
		.BYTE $18,$94,  3,$10
		.BYTE $20,$95,  3,  8
		.BYTE $20,$96,  3,$10
		.BYTE $80
_spr_sc7_kaneda_dreaming_eyes_right:
		.BYTE $10,$97,  3,  8
		.BYTE $10,$98,  3,$10
		.BYTE $80
_spr_sc7_kaneda_dreaming_eyes_left:
		.BYTE $10,$91,  3,  8
		.BYTE $10,$92,  3,$10
		.BYTE $80
_spr_sc7_girl_eyes0:
		.BYTE   0,$84,  3,  0
		.BYTE   0,$85,  3,  8
		.BYTE   0,$86,  3,$10
		.BYTE   0,$87,  3,$18
		.BYTE   8,$88,  3,  8
		.BYTE   8,$89,  3,$10
		.BYTE $80
_spr_sc7_girl_eyes1:
		.BYTE   0,$80,  3,  0
		.BYTE   0,$8A,  3,  8
		.BYTE   0,$82,  3,$10
		.BYTE   0,$83,  3,$18
		.BYTE   8,$88,  3,  8
		.BYTE   8,$89,  3,$10
		.BYTE $80
_spr_sc7_groupie_body:
		.BYTE   0,$C0,  1,  0
		.BYTE   0,$C1,  1,  8
		.BYTE   8,$C2,  1,  0
		.BYTE   8,$C3,  1,  8
		.BYTE $18,$C6,  1,  0
		.BYTE $18,$C7,  2,  8
		.BYTE $20,$C8,  1,  0
		.BYTE $20,$DE,  2,  8
		.BYTE $80
_spr_sc7_yamagata_kai_bodies:
		.BYTE   0,$C9,  3,$20
		.BYTE   0,$CA,  3,$28
		.BYTE   0,$CB,  3,$30
		.BYTE   8,$CC,  3,  8
		.BYTE   8,$CD,  3,$10
		.BYTE   8,$CE,  3,$18
		.BYTE   8,$CF,  1,$20
		.BYTE   8,$D0,  1,$28
		.BYTE   8,$D1,  1,$30
		.BYTE $10,$D2,  1,  8
		.BYTE $10,$D3,  1,$10
		.BYTE $10,$D4,  3,$18
		.BYTE $10,$D5,  3,$20
		.BYTE $10,$D6,  3,$28
		.BYTE $18,$D8,  1,  8
		.BYTE $18,$DA,  3,$18
		.BYTE $18,$DB,  2,$20
		.BYTE $18,$DC,  2,$28
		.BYTE $18,$DD,  3,$30
		.BYTE $20,$DF,  2,  8
		.BYTE $20,$F5,  2,$10
		.BYTE $20,$F6,  2,$18
		.BYTE $20,$F7,  2,$20
		.BYTE $20,$F8,  2,$28
		.BYTE $20,$F9,  1,$30
		.BYTE $28,$FB,  2,  8
		.BYTE $28,$FC,  2,$10
		.BYTE $28,$F6,  2,$18
		.BYTE $28,$F6,  2,$20
		.BYTE $28,$FD,  2,$28
		.BYTE $80
_spr_sc7_groupie_mouth_closed:
		.BYTE $10,$C4,  1,  0
		.BYTE $10,$C4,$41,  8
		.BYTE $80
_spr_sc7_groupie_mouth_open:
		.BYTE $10,$C5,$41,  0
		.BYTE $10,$C5,  1,  8
		.BYTE $80
_spr_sc7_kai_mouth_closed:
		.BYTE $18,$D9,  1,$10
		.BYTE $80
_spr_sc7_kai_mouth_open:
		.BYTE $18,$FE,  1,$10
		.BYTE $80
_spr_sc7_yamagata_mouth_open:
		.BYTE $10,$D7,  3,$30
		.BYTE $80
_spr_sc7_yamagata_mouth_closed:
		.BYTE $10,$FF,  3,$30
		.BYTE $80

		SECTION_END 7
