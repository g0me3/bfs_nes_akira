		SECTION_START 6

;-----------------------------------------------
; SCENE 6
;-----------------------------------------------

; original interactive script:
; 1. crouch
; 1.x any other (game over, restart SCENE 6)
; 2. run
; 2.x any other (game over, restart SCENE 6)
; 3. look->car
; 4. look->crc (run to added)
; 5. run to
; 6. look->car
; 7. look->tetsuo
; 8. inquire x 2 (run to added)
; 9. run to
; 10. look x 2
; OPTION A {
; 	1. yell (message, jump SCENE 7)
; }
; OPTION B {
; 	2. hit/run to (no message, jump SCENE 7)
; }

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene6_subs:
		JSR		_s6_spr_overlay_set
		LDA		_draw_state_idx
		BNE		locret_21037
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s6_sub00_clear
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_generic_menu_input
		SW_PTR	_s6_menu_handlers				; should be 4!
		SW_PTR	_s6_sub05_bike_draw
		SW_PTR	_s6_sub06_bike_msg
		SW_PTR	_s6_sub08_clown_draw
		SW_PTR	_s6_sub02_clown_fight_menu0_loop
		SW_PTR	_s6_sub16_clown_fight_menu1_loop
		SW_PTR	_s6_sub09_clown_beaten_draw
		SW_PTR	_s6_sub0B_clown_beaten_snd_msg
		SW_PTR	_s6_sub0C_after_clown_beaten_draw
		SW_PTR	_s6_sub0D_after_clown_beaten_msg
		SW_PTR	_s6_sub1F_clown_beat_closeup_draw
		SW_PTR	_s6_sub2F_clown_beat_closeup_msg
		SW_PTR	_s6_sub19_clear
		SW_PTR	_s6_sub1A_kaneda_icon2_draw
		SW_PTR	_s6_sub1B_kaneda_msg0
		SW_PTR	_s6_sub1D_tetsuo_icon0_draw
		SW_PTR	_s6_sub1E_tetsuo_kaneda_msgs
		SW_PTR	_s6_sub1E_tetsuo_kaneda_final_msg	; new event
		SW_PTR	_s6_sub21_tetsuo_headache_draw
		SW_PTR	_s6_sub22_tetsuo_headache_msg0
		SW_PTR	_s6_sub2E_sound_AKIRA_msg
		SW_PTR	_s6_sub31_sound_tetsuo_akira_msg
		SW_PTR	_s6_sub27_akira_flash_draw
		SW_PTR	_s6_sub28_sound_AKIRAAA_msg
		SW_PTR	_s6_sub29_tetsuo_headache_redraw
		SW_PTR	_s6_sub2B_tetsuo_headache_msg1
		SW_PTR	_s6_sub2C_akira_flash_draw
		SW_PTR	_s6_sub2D_sound_AKIRAAA_msg
		SW_PTR	_s6_sub24_tetsuo_collapsed_draw
		SW_PTR	_s6_sub25_tetsuo_collapsed_msg
		SW_PTR	_s6_sub26_music_crc_arrived_msg
		SW_PTR	_s6_sub2A_delay
		SW_PTR	_s6_sub33_start_music
		SW_PTR	_s6_sub11_crc_menu_loop
		SW_PTR	_s6_sub0E_medics_surrounded_msg
		SW_PTR	_s6_sub0F_medics_more_msgs
		SW_PTR	_s6_sub10_medics_menu_loop
		SW_PTR	_s6_sub12_security_msg
		SW_PTR	_s6_sub13_security_menu0_loop
		SW_PTR	_s6_sub14_security_menu1_loop
		SW_PTR	_s6_sub32_kaneda_knock_down_snd_msg
		SW_PTR	_s6_sub17_clear
		SW_PTR	_s6_sub18_kaneda_large_face_draw
		SW_PTR	_s6_sub15_kaneda_large_face_msg
		SW_PTR	_s6_sub1C_game_over_dead
		SW_PTR	_s6_sub20_game_over_dead
		SW_PTR	_s6_sub30_game_over_prizon

locret_21037:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub00_clear:
		SW_NXT	_s6_sub05_bike_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub05_bike_draw:
		SW_NXT	_s6_sub06_bike_msg
		LDA		#1
		STA		_scene_spr_overlay_idx
		TLM4	9,8,9

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub06_bike_msg:
		JSR		_snd_bike_ride
		SW_FADE	_s6_sub08_clown_draw
		MSG_M
		MSG		_sc6_msg00
		MSG		_sc6_msg01
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub08_clown_draw:
		JSR		_apu_reset
		JSR		_snd_clown_fight
		SW_NXT	_s6_sub02_clown_fight_menu0_loop
		LDA		#0
		STA		_scene_spr_overlay_idx
		TLM5	$A,9,$A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub02_clown_fight_menu0_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_210C6
		SW_RET	_s6_sub02_clown_fight_menu0_loop
		LDA		#0
		JSR		_s6_menu_inits
		JMP		_menu_draw_request
locret_210C6:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub09_clown_beaten_draw:
		SW_NXT	_s6_sub0B_clown_beaten_snd_msg
		TLM5	$B,$A,$B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub0B_clown_beaten_snd_msg:
		JSR		_snd_clown_punch
		SW_FADE	_s6_sub0C_after_clown_beaten_draw
		MSG_M
		MSG		_sc6_msg05
		MSG_WAIT								; "kai's iron pipe smash clown's head"
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub0C_after_clown_beaten_draw:
		SW_NXT	_s6_sub0D_after_clown_beaten_msg
		LDA		#2
		STA		_scene_spr_overlay_idx
		TLM4	$C,$B,$C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub0D_after_clown_beaten_msg:
		SW_FADE	_s6_sub1F_clown_beat_closeup_draw
		MSG_M
		MSG		_sc6_msg06
		MSG_WAIT								; "we save tetsuo and surrounded the clowns"
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub1F_clown_beat_closeup_draw:
		SW_NXT	_s6_sub2F_clown_beat_closeup_msg
		LDA		#$C
		STA		_scene_spr_overlay_idx
		TLM5	$58,$58,$99

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub2F_clown_beat_closeup_msg:
		SW_FADE	_s6_sub19_clear
		MSG_M
		MSG		_sc6_msg07
		MSG_WAIT								; "tetsuo became furious"
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub19_clear:
		SW_NXT	_s6_sub1A_kaneda_icon2_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub1A_kaneda_icon2_draw:
		SW_NXT	_s6_sub1B_kaneda_msg0
		LDA		#3
		STA		_scene_spr_overlay_idx
		ICON2	$D,$C,$51

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub1B_kaneda_msg0:
		SW_FADE	_s6_sub1D_tetsuo_icon0_draw
		MSG_M
		MSG		_sc6_msg08
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub1D_tetsuo_icon0_draw:
		SW_NXT	_s6_sub1E_tetsuo_kaneda_msgs
		LDA		#9
		STA		_scene_spr_overlay_idx
		ICON0	$D,$C,$D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub1E_tetsuo_kaneda_msgs:
		SW_NXT	_s6_sub1E_tetsuo_kaneda_final_msg	; new scene inserted
		MSG_M
		MSG		_sc6_msg09
		MSG		_sc6_msg2C
		MSG		_sc6_msg0A
		MSG		_sc6_msg2D
		MSG		_sc6_msg0B
		MSG		_sc6_msg0C
		MSG_WAIT								; just a little message split here
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub1E_tetsuo_kaneda_final_msg:
		LDA		#5
		STA		_scene_spr_overlay_idx			; draw unused overlay
		SW_FADE	_s6_sub21_tetsuo_headache_draw	; final headache message
		MSG_M
		MSG		_sc6_msg0D
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub21_tetsuo_headache_draw:
		SW_NXT	_s6_sub22_tetsuo_headache_msg0	; continue regular script
		LDA		#4
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_tlmA1_draw:
		TLM5	$6A,$6A,$A1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub22_tetsuo_headache_msg0:
		SW_NXT	_s6_sub2E_sound_AKIRA_msg
		MSG_M
		MSG		_sc5_6_15_msgAB
		MSG		_sc6_msg2E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub2E_sound_AKIRA_msg:
		JSR		_snd_akira_flashback_suddenly
		SW_NXT	_s6_sub31_sound_tetsuo_akira_msg
		MSG_M
		MSG		_sc6_msg0F
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub31_sound_tetsuo_akira_msg:
		JSR		_snd_noisy_silent_ambient
		SW_FADE	_s6_sub27_akira_flash_draw
		MSG_M
		MSG		_sc6_msg0E
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub27_akira_flash_draw:
		LDA		#0
		STA		_scene_spr_overlay_idx
		SW_NXT	_s6_sub28_sound_AKIRAAA_msg
		EXJMP	_s15_tlm7A_draw					; defined in system bank

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub28_sound_AKIRAAA_msg:
		JSR		_snd_akira_flashback_suddenly
		SW_FADE	_s6_sub29_tetsuo_headache_redraw
		MSG_1	_sc6_msgAD

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub29_tetsuo_headache_redraw:
		SW_NXT	_s6_sub2B_tetsuo_headache_msg1
		LDA		#4
		STA		_scene_spr_overlay_idx
		JMP		_s6_tlmA1_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub2B_tetsuo_headache_msg1:
		SW_FADE	_s6_sub2C_akira_flash_draw
		MSG_M
		MSG		_sc6_15_msg88
		MSG		_sc6_15_msg89
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub2C_akira_flash_draw:
		LDA		#0
		STA		_scene_spr_overlay_idx
		SW_NXT	_s6_sub2D_sound_AKIRAAA_msg
		EXJMP	_s15_tlm7A_draw					; defined in system bank

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub2D_sound_AKIRAAA_msg:
		JSR		_snd_akira_flashback_suddenly
		SW_FADE	_s6_sub24_tetsuo_collapsed_draw
		MSG_1	_sc6_msgAD

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub24_tetsuo_collapsed_draw:
		SW_NXT	_s6_sub25_tetsuo_collapsed_msg
		LDA		#6
		STA		_scene_spr_overlay_idx
		LDA		#0
		STA		_scene_anim_idx
		TLM5	$16,$2E,$1F

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub25_tetsuo_collapsed_msg:
		JSR		_snd_noisy_silent_ambient
		SW_NXT	_s6_sub26_music_crc_arrived_msg
		MSG_M
		MSG		_sc6_msg10
		MSG_WAIT								; "tetsuo began to tremble"
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub26_music_crc_arrived_msg:
		JSR		_apu_reset
		JSR		_snd_crc_and_car_arrival
		LDA		#7
		STA		_scene_spr_overlay_idx
		SW_NXT	_s6_sub2A_delay
		MSG_1	_sc6_msg11						; "crc and car arrived"

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub2A_delay:
		SW_NXT	_s6_sub33_start_music
		LDA		#$10
		JMP		_delay

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub33_start_music:
		JSR		_apu_reset
		SW_NXT	_s6_sub11_crc_menu_loop
		JMP		_snd_energic_something_happening_pulse

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub11_crc_menu_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_211E1
		SW_RET	_s6_sub11_crc_menu_loop
		LDA		#2
		JSR		_s6_menu_inits
		JMP		_menu_draw_request
locret_211E1:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub0E_medics_surrounded_msg:
		LDA		#1
		STA		_scene_anim_idx
		SW_NXT	_s6_sub0F_medics_more_msgs
		MSG_1	_sc6_msg15

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub0F_medics_more_msgs:
		SW_NXT	_s6_sub10_medics_menu_loop
		MSG_M
		MSG		_sc6_msg16
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub10_medics_menu_loop:
		LDA		#2
		STA		_scene_anim_idx
		LDA		_pads+1
		AND		#1
		BEQ		locret_211CD
		SW_RET	_s6_sub10_medics_menu_loop
		LDA		#4
		JSR		_s6_menu_inits
		JMP		_menu_draw_request
locret_211CD:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub12_security_msg:
		SW_NXT	_s6_sub13_security_menu0_loop
		MSG_1	_sc6_msg1C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub13_security_menu0_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_211FF
		SW_RET	_s6_sub13_security_menu0_loop
		LDA		#5
		JSR		_s6_menu_inits
		JMP		_menu_draw_request
locret_211FF:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub14_security_menu1_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_21213
		SW_RET	_s6_sub14_security_menu1_loop
		LDA		#6
		JSR		_s6_menu_inits
		JMP		_menu_draw_request
locret_21213:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub32_kaneda_knock_down_snd_msg:
		JSR		_snd_punch1
		SW_FADE	_s6_sub17_clear
		MSG_1	_sc6_msg25

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub17_clear:
		SW_NXT	_s6_sub18_kaneda_large_face_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub18_kaneda_large_face_draw:
		SW_NXT	_s6_sub15_kaneda_large_face_msg
		LDA		#8
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_tlm88_draw:
		TLM5	$5D,$5D,$88

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub15_kaneda_large_face_msg:
		SW_FADE	_next_scene
		MSG_M
		MSG		_sc6_msg27
		MSG		_sc6_msg26
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub16_clown_fight_menu1_loop:
		LDA		_pads+1
		AND		#1
		BEQ		locret_21240
		SW_RET	_s6_sub16_clown_fight_menu1_loop
		LDA		#1
		JSR		_s6_menu_inits
		JMP		_menu_draw_request
locret_21240:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub1C_game_over_dead:
		LDY		#0								; start from the beginning, let it be zero then
		BEQ		_s6_game_over_dead_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub20_game_over_dead:
		LDY		#_s6_sub24_tetsuo_collapsed_draw_sidx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_game_over_dead_start:
		JSR		_scene_vars_init
		LDX		#6
		JMP		_game_over_dead_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_sub30_game_over_prizon:
		JSR		_scene_vars_init
		LDX		#6
		LDY		#_s6_sub24_tetsuo_collapsed_draw_sidx
		JMP		_game_over_prison_start

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu_inits:
		STA		_scene_menu_idx
		SW_NXT	_generic_menu_input
		LDA		_scene_menu_idx
		SWITCH
		SW_PTR	_scene_menu_init_default4
		SW_PTR	_scene_menu_init_default4
		SW_PTR	_s6_menus_init2
		SW_PTR	_scene_menu_init_default3
		SW_PTR	_s6_menus_init4
		SW_PTR	_scene_menu_init_default6
		SW_PTR	_scene_menu_init_default3
		SW_PTR	_scene_menu_init_default3

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menus_init2:
		LDA		_scene_flags+2
		AND		#3
		CMP		#3
		BNE		locret_214A6
		JMP		_scene_menu_init_default5
locret_214A6:
		JMP		_scene_menu_init_default4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menus_init4:
		LDA		_scene_flags
		AND		#$F
		CMP		#$F
		BNE		locret_214BC
;		LDA		#4								; BUG? where is the item index?! it seems it works
;		STA		_scene_menu_max_pos				; just because the leftover from previous menus
		JMP		_scene_menu_init_default5
locret_214BC:
		JMP		_scene_menu_init_default4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu_handlers:
		JSR		_menu_switch
		.WORD _s6_menu0
		.WORD _s6_menu1
		.WORD _s6_menu2
		.WORD _s6_menu3
		.WORD _s6_menu4
		.WORD _s6_menu5
		.WORD _s6_menu6
		.WORD _s6_menu7
_s6_menu0:
		.WORD _s6_menu0_wrong_decision
		.WORD _s6_menu0_wrong_decision
		.WORD _s6_menu0_wrong_decision
		.WORD _s6_menu0_crouch
_s6_menu1:
		.WORD _s6_menu1_run
		.WORD _s6_menu0_wrong_decision
		.WORD _s6_menu0_wrong_decision
		.WORD _s6_menu0_wrong_decision
_s6_menu2:
		.WORD _s6_menu2_run
		.WORD _s6_menu2_ponder
		.WORD _s6_menu2_look
		.WORD _s6_menu2_panic
		.WORD _s6_menu2_run_to
_s6_menu3:
		.WORD _s6_menu3_car
		.WORD _s6_menu3_crc
		.WORD _s6_menu3_tetsuo
_s6_menu4:
		.WORD _s6_menu4_inquire
		.WORD _s6_menu4_ponder
		.WORD _s6_menu4_take
		.WORD _s6_menu4_look
		.WORD _s6_menu4_run_to
_s6_menu5:
		.WORD _s6_menu5_open
		.WORD _s6_menu5_inquire
		.WORD _s6_menu5_flatter
		.WORD _s6_menu5_hit
		.WORD _s6_menu5_yell
		.WORD _s6_menu5_look
_s6_menu6:
		.WORD _s6_menu6_yell
		.WORD _s6_menu6_hit_run_to
		.WORD _s6_menu6_hit_run_to
_s6_menu7:
		.WORD _s6_menu7_car
		.WORD _s6_menu7_crc
		.WORD _s6_menu7_tetsuo

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu0_wrong_decision:
		JSR		_snd_clown_punch
		SW_FADE	_s6_sub1C_game_over_dead
		MSG_M
		MSG		_sc6_msg02
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu0_crouch:
		SW_NXT	_s6_sub16_clown_fight_menu1_loop
		MSG_1	_sc6_msg03

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu1_run:
		SW_FADE	_s6_sub09_clown_beaten_draw
		MSG_M
		MSG		_sc6_msg87
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu2_run:
		SW_NXT	_s6_sub11_crc_menu_loop
		MSG_1	_sc6_msg04

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu2_ponder:
		SW_NXT	_s6_sub11_crc_menu_loop
		MSG_1	_sc6_msg1E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu2_look:
		LDA		#3
		JSR		_s6_menu_inits
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu2_panic:
		SW_NXT	_s6_sub11_crc_menu_loop
		MSG_1	_sc2_6_msg83

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu2_run_to:
		SW_NXT	_s6_sub0E_medics_surrounded_msg
		MSG_M
		MSG		_sc6_msg14
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu3_car:
		LDA		_scene_flags+2
		ORA		#1
		STA		_scene_flags+2
		SW_NXT	_s6_sub11_crc_menu_loop
		MSG_1	_sc6_msg12

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu3_crc:
		LDA		_scene_flags+2
		ORA		#2
		STA		_scene_flags+2
		SW_NXT	_s6_sub11_crc_menu_loop
		MSG_1	_sc6_msg13

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu3_tetsuo:
		SW_NXT	_s6_sub11_crc_menu_loop
		MSG_1	_sc5_6_15_msgAB

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu4_inquire:
		SW_NXT	_s6_sub10_medics_menu_loop
		LDA		_scene_flags
		AND		#7
		CMP		#7
		BEQ		loc_2160E
		LDA		_scene_flags
		ORA		#1
		STA		_scene_flags
		MSG_1	_sc6_msg1A
loc_2160E:
		LDA		_scene_flags
		ORA		#8
		STA		_scene_flags
		MSG_1	_sc6_msg28

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu4_ponder:
		SW_NXT	_s6_sub10_medics_menu_loop
		MSG_1	_sc6_msg18

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu4_take:
		SW_NXT	_s6_sub10_medics_menu_loop
		MSG_1	_sc6_msg19

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu4_look:
		LDA		#7
		JSR		_s6_menu_inits
		JMP		_menu_draw_msg_modeF

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu4_run_to:
		SW_NXT	_s6_sub12_security_msg
		LDA		#$A
		STA		_scene_spr_overlay_idx
		MSG_M
		MSG		_sc5_6_15_msgAB
		MSG		_sc6_msg1B
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu5_open:
		LDA		_scene_flags+1
		AND		#1
		BNE		loc_2167E
		LDA		_scene_flags+1
		ORA		#1
		STA		_scene_flags+1
		SW_NXT	_s6_sub13_security_menu0_loop
		MSG_1	_sc6_msg1D
loc_2167E:
		SW_NXT	_s6_sub20_game_over_dead
		MSG_M
		MSG		_sc6_msg1F
		MSG		_sc6_msg20
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu5_inquire:
		LDA		_scene_flags+1
		AND		#2
		BNE		loc_216AA
		LDA		_scene_flags+1
		ORA		#2
		STA		_scene_flags+1
		SW_NXT	_s6_sub13_security_menu0_loop
		MSG_1	_sc5_6_msgA4
loc_216AA:
		SW_NXT	_s6_sub30_game_over_prizon
		MSG_1	_sc6_msg2B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu5_flatter:
		LDA		_scene_flags+1
		AND		#4
		BNE		loc_216CD
		LDA		_scene_flags+1
		ORA		#4
		STA		_scene_flags+1
		SW_NXT	_s6_sub13_security_menu0_loop
		MSG_1	_sc5_6_msgA4
loc_216CD:
		SW_NXT	_s6_sub30_game_over_prizon
		MSG_1	_sc6_msg2B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu5_hit:
		SW_NXT	_s6_sub20_game_over_dead
		MSG_M
		MSG		_sc6_msg1F
		MSG		_sc6_msg20
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu5_yell:
		SW_NXT	_s6_sub13_security_menu0_loop
		MSG_1	_sc6_msg21

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu5_look:
		LDA		_scene_flags+1
		AND		#8
		BNE		loc_21717
		LDA		_scene_flags+1
		ORA		#8
		STA		_scene_flags+1
		SW_NXT	_s6_sub13_security_menu0_loop
		MSG_M
		MSG		_sc6_msg22
		MSG		_sc5_6_msgA4
		MSG_EOL
loc_21717:
		SW_NXT	_s6_sub14_security_menu1_loop
		MSG_1	_sc6_msg23

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu6_yell:
		SW_NXT	_s6_sub32_kaneda_knock_down_snd_msg
		MSG_M
		MSG		_sc6_msg24
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu6_hit_run_to:
		SW_NXT	_s6_sub32_kaneda_knock_down_snd_msg
		SW_CUR	_s6_sub32_kaneda_knock_down_snd_msg
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu7_car:
		LDA		_scene_flags
		ORA		#4
		STA		_scene_flags
		SW_NXT	_s6_sub10_medics_menu_loop
		MSG_1	_sc6_msg29

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu7_crc:
		SW_NXT	_s6_sub10_medics_menu_loop
		MSG_1	_sc6_msg2A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_menu7_tetsuo:
		LDA		_scene_flags
		ORA		#2
		STA		_scene_flags
		SW_NXT	_s6_sub10_medics_menu_loop
		MSG_1	_sc6_msg17

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s6_spr_overlay1
		SW_PTR	_s6_spr_overlay2
		SW_PTR	_s6_spr_overlay3
		SW_PTR	_s6_spr_overlay4
		SW_PTR	_s6_spr_overlay5				; reused as an extra scene
		SW_PTR	_s6_spr_overlay6
		SW_PTR	_s6_spr_overlay7
		EXOFS	_s17_spr_overlay1_A				; defined in system bank
		SW_PTR	_s6_spr_overlay9
		SW_PTR	_s6_spr_overlayA
		.WORD 0
		SW_PTR	_s6_spr_overlayC

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_spr_overlay1:
		SPR0	_spr_sc6_on_bike_yamagata_head,$28,$48
		JSR		_do_scene_anim0_pat0121
		LDA		_scene_anim_idx
		SPR0SW	off_2188F,$28,$48				; there is no yamagata line in this scene
		JSR		_get_anim_blink_idx
		STA		_scene_anim_idx+2				; save for next anim
		SPR0SW	off_21897,$28,$48
		LDA		_frames_counter
		LSR
		LSR
		AND		#1
		PHA										; the same
		SPR0SW	off_2189D,$28,$48
		SPR0	_spr_sc6_on_bike_kaneda_head,$28,$70
		JSR		_do_scene_anim1_pat0121
		LDA		_scene_anim_idx+1
		SPR0SW	off_2190E,$28,$70				; kaneda has only one word, but no msg anim flag
		LDA		_scene_anim_idx+2
		SPR0SW	off_21916,$28,$70
		PLA										; the same
		SPR0JSW	off_2191C,$28,$70
off_2188F:
		.WORD _spr_sc6_on_bike_yamaga_mouth_open
		.WORD _spr_sc6_on_bike_yamaga_mouth_shut
		.WORD _spr_sc6_on_bike_yamaga_mouth_unused
off_21897:
		.WORD _spr_sc6_on_bike_yamaga_eyes1
		.WORD _spr_sc6_on_bike_yamaga_eyes2
off_2189D:
		.WORD _spr_sc6_on_bike_yamaga_hair0
		.WORD _spr_sc6_on_bike_yamaga_hair1
off_2190E:
		.WORD _spr_sc6_on_bike_kaneda_mouth_open
		.WORD _spr_sc6_on_bike_kaneda_mouth_shut
		.WORD _spr_sc6_on_bike_kaneda_mouth_open_small
off_21916:
		.WORD _spr_sc6_on_bike_kaneda_eyes1
		.WORD _spr_sc6_on_bike_kaneda_eyes2
off_2191C:
		.WORD _spr_sc6_on_bike_kaneda_hair0
		.WORD _spr_sc6_on_bike_kaneda_hair1

;-------------S-U-B-R-O-U-T-I-N-E---------------
; what?! again an error?!
; this screen should show the clown
; beaten by kaneda at the wall!
; but instead it freeses when punch has
; landed!
;
; too complex behaviour previously just to
; turn one head after a while once
;
; anyway, if you try to restore animation
; with original code, punches will be
; too short, almost invisible, so it seems
; they don't have much time to polish it
; let's try to animate it properly
; just sync it with punch sound
;
_s6_spr_overlay2:
		JSR		_s6_apu_select
		LDA		_scene_anim_idx+2
		BEQ		loc_2193B
		DEC		_scene_anim_idx+2
		SPR0J	_spr_sc6_tetsuo_beat_clown1,$60,$68
loc_2193B:
		SPR0J	_spr_sc6_tetsuo_beat_clown0,$60,$68

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_spr_overlay7:
		JSR		_s6_spr_overlay6				; for tetsuo

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_spr_overlay7_CRC_car:
		SPR0	_spr_sc6_CRC,$20,$78
		SPR0J	_spr_sc6_black_car,$30,$B0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_spr_overlayA:
		SPR0	_spr_sc6_security,$38,$50
		JSR		_do_scene_anim1_pat0101
		LDA		_scene_anim_idx+1
		SPR0SW	off_21AC2,$38,$50
		JMP		_s6_spr_overlay7_CRC_car		; for CRC and car
off_21AC2:
		.WORD _spr_sc6_security_mouth_open
		.WORD _spr_sc6_security_mouth_closed

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_spr_overlayC:
		JSR		_s6_apu_select
		SPR0J	_spr_sc6_clowns_blood,$28,$70

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_spr_overlay4:
		JSR		_do_scene_anim1_pat0101
		LDA		_scene_anim_idx+1
		SPR0JSW	off_2181C,$50,$68
off_2181C:
		.WORD _spr_sc6_tetsuo_headache_mouth0
		.WORD _spr_sc6_tetsuo_headache_mouth1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_spr_overlay3:
		JSR		_do_scene_anim0_pat0121			; mouth
		LDA		_scene_anim_idx
		SPR0SW	off_21997,$30,$C8
		JSR		_get_anim_blink_idx				; 1,2 eyes
		SPR0JSW	off_2199F,$20,$C8
off_21997:
		.WORD _spr_sc6_kaneda_mouth_open_wide
		.WORD _spr_sc6_kaneda_mouth_shut
		.WORD _spr_sc6_kaneda_mouth_open_small	; reused third mouth spr with new anim pattern
off_2199F:
		.WORD _spr_sc6_kaneda_eyes1
		.WORD _spr_sc6_kaneda_eyes2

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_spr_overlay9:
		JSR		_s6_spr_overlay3				; for kaneda icon
		SPR0	_spr_sc6_tetsuo_eyes,$38,$10
		JSR		_do_scene_anim1_pat0101
		LDA		_scene_anim_idx+1
		SPR0JSW	off_219C4,$38,$10
off_219C4:
		.WORD _spr_sc6_tetsuo_mouth_open
		.WORD _spr_sc6_tetsuo_mouth_close

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_spr_overlay5:
		SPR0	_spr_sc6_kaneda_mouth_open_wide,$30,$C8	; draw "mad" kaneda
		SPR0	_spr_sc6_kaneda_eyes_mad_unused,$20,$C8
		JSR		_get_anim_blink_idx				; draw starting to get mad "tetsuo"
		SPR0SW	ofs_21A5C,$38,$10				; blinking
		SPR0	_spr_sc6_unk_people0,$68,$60	; and two unused people sprites
		SPR0J	_spr_sc6_unk_people1,$60,$88
ofs_21A5C:
		.WORD	_spr_sc6_tetsuo_eyes_mad1		; reused unused tiles
		.WORD	_spr_sc6_tetsuo_eyes_mad0		; reused unused sprite

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_spr_overlay6:
		LDA		_scene_anim_idx
		SPR0JSW	off_21A5B,$40,$58
off_21A5B:
		.WORD _spr_sc6_testsuo_collapsed
		.WORD _spr_sc6_tetsuo_medics0
		.WORD _spr_sc6_tetsuo_medics1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s6_apu_select:
		LDA		_frames_counter
		AND		#$F
		BNE		locret_217DA
		LDA		_rand
		LSR
		BCC		locret_217DA
		AND		#3
		STA		_scene_anim_idx+2
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_snd_punch0
		SW_PTR	_snd_punch1
		SW_PTR	_snd_punch2

locret_217DA:
		RTS

_spr_sc6_on_bike_yamagata_head:
		.BYTE   0,$B3,  1,  8
		.BYTE   0,$B4,  1,$10
		.BYTE   0,$B5,  1,$18
		.BYTE   8,$B7,  1,  0
		.BYTE   8,$A0,  1,  8
		.BYTE   8,$A0,  1,$10
		.BYTE   8,$B8,  1,$18
		.BYTE $10,$BD,  1,$18
		.BYTE $18,$C1,  1,  0
		.BYTE $18,$C2,  1,  8
		.BYTE $18,$C3,  1,$10
		.BYTE $18,$C4,  2,$18
		.BYTE $20,$FE,  2,$10
		.BYTE $80
_spr_sc6_on_bike_yamaga_hair0:
		.BYTE   0,$B2,  1,  0
		.BYTE $80
_spr_sc6_on_bike_yamaga_hair1:
		.BYTE   0,$B6,  1,  0
		.BYTE $80
_spr_sc6_on_bike_yamaga_mouth_shut:
		.BYTE $20,$C7,  2,  8
		.BYTE $80
_spr_sc6_on_bike_yamaga_mouth_open:
		.BYTE $20,$FF,  2,  8
		.BYTE $80
_spr_sc6_on_bike_yamaga_mouth_unused:
		.BYTE $20,$AA,  2,  8
		.BYTE $80
_spr_sc6_on_bike_yamaga_eyes1:
		.BYTE $10,$BA,  1,  0
		.BYTE $10,$BB,  1,  8
		.BYTE $10,$BC,  1,$10
		.BYTE $80
_spr_sc6_on_bike_yamaga_eyes2:
		.BYTE $10,$BE,  1,  0
		.BYTE $10,$BF,  1,  8
		.BYTE $10,$C0,  1,$10
		.BYTE $80
_spr_sc6_on_bike_kaneda_head:
		.BYTE   0,$9B,  1,$10
		.BYTE   0,$9C,  1,$18
		.BYTE   8,$9F,  1,  0
		.BYTE   8,$A0,  1,  8
		.BYTE   8,$A0,  1,$10
		.BYTE   8,$A1,  1,$18
		.BYTE $10,$A4,  1,$10
		.BYTE $10,$A5,  1,$18
		.BYTE $18,$A9,  1,  0
		.BYTE $18,$AC,  1,$10
		.BYTE $18,$AD,  1,$18
		.BYTE $20,$B0,  1,$10
		.BYTE $80
_spr_sc6_on_bike_kaneda_hair0:
		.BYTE   0,$99,  1,  0
		.BYTE   0,$9A,  1,  8
		.BYTE $80
_spr_sc6_on_bike_kaneda_hair1:
		.BYTE   0,$9D,  1,  0
		.BYTE   0,$9E,  1,  8
		.BYTE $80
_spr_sc6_on_bike_kaneda_mouth_shut:
		.BYTE $18,$A8,  1,  8
		.BYTE $20,$AF,  1,  8
		.BYTE $80
_spr_sc6_on_bike_kaneda_mouth_open:
		.BYTE $18,$AB,  1,  8
		.BYTE $20,$AF,  1,  8
		.BYTE $80
_spr_sc6_on_bike_kaneda_mouth_open_small:
		.BYTE $18,$AE,  1,  8
		.BYTE $20,$B1,  1,  8
		.BYTE $80
_spr_sc6_on_bike_kaneda_eyes1:
		.BYTE $10,$A2,  1,  0
		.BYTE $10,$A3,  1,  8
		.BYTE $80
_spr_sc6_on_bike_kaneda_eyes2:
		.BYTE $10,$A6,  1,  0
		.BYTE $10,$A7,  1,  8
		.BYTE $80
_spr_sc6_tetsuo_beat_clown1:
		.BYTE   0,$80,  1,  8
		.BYTE   0,$82,  1,$10
		.BYTE   8,$83,  1,  0
		.BYTE   8,$84,  1,  8
		.BYTE   8,$85,  1,$10
		.BYTE   8,$86,  1,$18
		.BYTE $10,$87,  1,  0
		.BYTE $10,$88,  1,  8
		.BYTE $10,$89,  1,$10
		.BYTE $10,$8A,  1,$18
		.BYTE $10,$8B,  1,$20
		.BYTE $18,$8C,  1,  0
		.BYTE $18,$8D,  1,  8
		.BYTE $18,$8E,  1,$10
		.BYTE $18,$8F,  1,$18
		.BYTE $18,$90,  1,$20
		.BYTE $80
_spr_sc6_tetsuo_beat_clown0:
		.BYTE   0,$82,$41,  0
		.BYTE   0,$91,  1,  8
		.BYTE   0,$92,  1,$10
		.BYTE   8,$93,  1,  0
		.BYTE   8,$94,  1,  8
		.BYTE   8,$95,  1,$10
		.BYTE   8,$96,  1,$18
		.BYTE $10,$87,  1,  0
		.BYTE $10,$88,  1,  8
		.BYTE $10,$89,  1,$10
		.BYTE $10,$97,  1,$18
		.BYTE $10,$98,  1,$20
		.BYTE $18,$8C,  1,  0
		.BYTE $18,$8D,  1,  8
		.BYTE $18,$8E,  1,$10
		.BYTE $18,$8F,  1,$18
		.BYTE $18,$90,  1,$20
		.BYTE $80
_spr_sc6_kaneda_eyes1:
		.BYTE   0,$89,  1,  0
		.BYTE   0,$8A,  1,  8
		.BYTE   8,$88,  1,  2
		.BYTE $80
_spr_sc6_kaneda_eyes2:
		.BYTE   0,$8B,  1,  0
		.BYTE   0,$8C,  1,  8
		.BYTE   8,$8D,  1,  2
		.BYTE $80
_spr_sc6_kaneda_eyes_mad_unused:
		.BYTE   0,$86,  1,  0
		.BYTE   0,$87,  1,  8
		.BYTE   8,$88,  1,  2
		.BYTE $80
_spr_sc6_kaneda_mouth_open_wide:
		.BYTE   0,$82,  1,  0
		.BYTE   0,$D5,  1,  8
		.BYTE   8,$84,  1,  0
		.BYTE   8,$D6,  1,  8
		.BYTE $80
_spr_sc6_kaneda_mouth_shut:
		.BYTE   0,$80,  1,  3
		.BYTE $80
_spr_sc6_kaneda_mouth_open_small:
		.BYTE   0,$82,  1,  0
		.BYTE   0,$83,  1,  8
		.BYTE   8,$84,  1,  0
		.BYTE   8,$85,  1,  8
		.BYTE $80
_spr_sc6_tetsuo_mouth_close:
		.BYTE $10,$9C,  1,  8					; only mouth here is animated
		.BYTE $80
_spr_sc6_tetsuo_mouth_open:
		.BYTE $10,$9D,  1,  0
		.BYTE $10,$9E,  1,  8
		.BYTE $80
_spr_sc6_tetsuo_eyes:							; small opt here, split common sprites as separate overlay
		.BYTE   0,$96,  1,  8
		.BYTE   0,$97,  1,$10
		.BYTE   0,$98,  1,$18
		.BYTE   8,$99,  1,  8
		.BYTE   8,$9A,  1,$10
		.BYTE   8,$9B,  1,$18
		.BYTE	$80
_spr_sc6_tetsuo_eyes_mad0:
		.BYTE   0,$9F,  1,  8
		.BYTE   0,$A0,  1,$10
		.BYTE   0,$A1,  1,$18
		.BYTE   8,$A2,  1,  8
		.BYTE   8,$A3,  1,$10
		.BYTE   8,$A4,  1,$18
		.BYTE $10,$A5,  1,  8
		.BYTE $80
_spr_sc6_tetsuo_eyes_mad1:
		.BYTE   0,$8F,  1,  8
		.BYTE   0,$90,  1,$10
		.BYTE   0,$91,  1,$18
		.BYTE   8,$92,  1,  8
		.BYTE   8,$93,  1,$10
		.BYTE   8,$94,  1,$18
		.BYTE $10,$95,  1,  8
		.BYTE $80
_spr_sc6_unk_people0:
		.BYTE   0,$A6,  1,  0
		.BYTE   0,$A7,  1,  8
		.BYTE   8,$A8,  1,  0
		.BYTE   8,$A9,  1,  8
		.BYTE   8,$AA,  1,$10
		.BYTE $10,$AB,  1,  0
		.BYTE $10,$AC,  1,  8
		.BYTE $80
_spr_sc6_unk_people1:
		.BYTE   0,$AD,  1,  0
		.BYTE   0,$AD,$41,  8
		.BYTE   8,$AE,  1,  0
		.BYTE   8,$AE,$41,  8
		.BYTE $10,$AF,  1,  0
		.BYTE $10,$AF,$41,  8
		.BYTE $18,$B0,  1,  0
		.BYTE $18,$B1,  1,  8
		.BYTE $80
_spr_sc6_testsuo_collapsed:
		.BYTE $10,$80,  1,  0
		.BYTE $10,$82,  1,  8
		.BYTE $18,$83,  1,  0
		.BYTE $18,$84,  1,  8
		.BYTE $20,$85,  1,  0
		.BYTE $20,$86,  1,  8
		.BYTE $80
_spr_sc6_tetsuo_medics0:
		.BYTE   8,$D0,  1,  0
		.BYTE   8,$D0,$41,  8
		.BYTE $10,$8B,  1,  0
		.BYTE $10,$8C,  1,  8
		.BYTE $10,$8D,  1,$10
		.BYTE $10,$8E,  1,$18
		.BYTE $18,$8F,  1,  0
		.BYTE $18,$90,  1,  8
		.BYTE $18,$91,  1,$10
		.BYTE $18,$92,  1,$18
		.BYTE $20,$93,  2,  0
		.BYTE $20,$94,  2,  8
		.BYTE $20,$95,  2,$10
		.BYTE $20,$96,  2,$18
		.BYTE $80
_spr_sc6_tetsuo_medics1:
		.BYTE   0,$97,  1,  8
		.BYTE   0,$98,  1,$10
		.BYTE   0,$99,  1,$20
		.BYTE   8,$9A,  1,  0
		.BYTE   8,$9B,  1,  8
		.BYTE   8,$9C,  1,$10
		.BYTE   8,$9D,  1,$18
		.BYTE   8,$9E,  1,$20
		.BYTE   8,$9F,  1,$28
		.BYTE $10,$A0,  1,  0
		.BYTE $10,$A1,  1,  8
		.BYTE $10,$A2,  1,$10
		.BYTE $10,$A3,  1,$18
		.BYTE $10,$A4,  1,$20
		.BYTE $10,$A5,  1,$28
		.BYTE $18,$A6,  2,  0
		.BYTE $18,$A7,  2,  8
		.BYTE $18,$A8,  2,$10
		.BYTE $18,$A9,  2,$18
		.BYTE $18,$AA,  2,$20
		.BYTE $18,$AB,  2,$28
		.BYTE $20,$AC,  2,  0
		.BYTE $20,$AD,  2,  8
		.BYTE $20,$AE,  2,$10
		.BYTE $20,$AF,  2,$18
		.BYTE $20,$B0,  2,$20
		.BYTE $20,$B1,  2,$28
		.BYTE $80
_spr_sc6_CRC:
		.BYTE   0,$D1,  2,  0
		.BYTE   0,$C1,  2,  8
		.BYTE   0,$C2,  2,$10
		.BYTE   0,$C3,  2,$18
		.BYTE   8,$C4,  2,  8
		.BYTE   8,$C5,  2,$10
		.BYTE   8,$C6,  2,$18
		.BYTE $10,$C7,  2,  8
		.BYTE $10,$C8,  2,$10
		.BYTE $10,$C9,  2,$18
		.BYTE $18,$CA,  2,  8
		.BYTE $18,$CB,  2,$10
		.BYTE $18,$CC,  2,$18
		.BYTE $20,$CD,  2,  8
		.BYTE $20,$CE,  2,$10
		.BYTE $20,$CF,  2,$18
		.BYTE $80
_spr_sc6_black_car:
		.BYTE   8,$87,  2,  0
		.BYTE   8,$88,  2,  8
		.BYTE $10,$89,  2,  0
		.BYTE $10,$8A,  2,  8
		.BYTE $80
_spr_sc6_security:
		.BYTE   0,$B2,  1,$10
		.BYTE   0,$B3,  1,$18
		.BYTE   8,$B4,  1,$10
		.BYTE   8,$B4,$41,$18
		.BYTE $10,$B5,  2,  8
		.BYTE $10,$B5,$42,$20
		.BYTE $18,$B7,  2,  0
		.BYTE $18,$B8,  2,  8
		.BYTE $18,$B9,  2,$10
		.BYTE $18,$B9,$42,$18
		.BYTE $18,$B8,$42,$20
		.BYTE $18,$B7,$42,$28
		.BYTE $20,$BA,  2,  0
		.BYTE $20,$BF,  2,  8
		.BYTE $20,$BB,  2,$10
		.BYTE $20,$BB,$42,$18
		.BYTE $20,$BF,$42,$20
		.BYTE $20,$BA,$42,$28
		.BYTE $28,$BC,  2,  0
		.BYTE $28,$BF,  2,  8
		.BYTE $28,$BD,  2,$10
		.BYTE $28,$BD,$42,$18
		.BYTE $28,$BF,$42,$20
		.BYTE $28,$BC,$42,$28
		.BYTE $30,$BE,  2,  0
		.BYTE $30,$BF,  2,  8
		.BYTE $30,$BF,  2,$10
		.BYTE $30,$BF,$42,$18
		.BYTE $30,$BF,$42,$20
		.BYTE $30,$BE,$42,$28
		.BYTE $80
_spr_sc6_security_mouth_closed:
		.BYTE $10,$B6,  1,$10
		.BYTE $10,$B6,$41,$18
		.BYTE $80
_spr_sc6_security_mouth_open:
		.BYTE $10,$C0,  1,$10
		.BYTE $10,$C0,$41,$18
		.BYTE $80
_spr_sc6_clowns_blood:
		.BYTE   0,$FA,  1,$10
		.BYTE   0,$FB,  1,$18
		.BYTE   0,$FC,  1,$20
		.BYTE   8,$FD,  1,  8
		.BYTE   8,$FB,  1,$10
		.BYTE   8,$FC,$81,$18
		.BYTE $10,$FA,$41,  0
		.BYTE $10,$FD,$81,  8
		.BYTE $80
_spr_sc6_tetsuo_headache_mouth1:
		.BYTE   0,$E3,  1,$10
		.BYTE   0,$E4,  1,$18
		.BYTE   8,$E5,  1,  0
		.BYTE   8,$E6,  1,  8
		.BYTE   8,$E7,  1,$10
		.BYTE   8,$E8,  1,$18
		.BYTE $10,$E9,  1,  0
		.BYTE $10,$EA,  1,  8
		.BYTE $10,$EB,  1,$10
		.BYTE $80
_spr_sc6_tetsuo_headache_mouth0:
		.BYTE   0,$EC,  1,$10
		.BYTE   0,$E4,  1,$18
		.BYTE   8,$EE,  1,  0
		.BYTE   8,$EF,  1,  8
		.BYTE   8,$F0,  1,$10
		.BYTE   8,$F1,  1,$18
		.BYTE $10,$F2,  1,  0
		.BYTE $10,$F3,  1,  8
		.BYTE $10,$F4,  1,$10
		.BYTE $80

		SECTION_END 6
