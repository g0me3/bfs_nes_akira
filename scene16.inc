
		SECTION_START 16

;-----------------------------------------------
; SCENE 16 (ENDINGS)
;-----------------------------------------------

; no interactive events

;-------------S-U-B-R-O-U-T-I-N-E---------------
_scene16_subs:
		JSR		_s16_spr_overlay_set
		LDA		_draw_state_idx
		BEQ		loc_80F08
		RTS
loc_80F08:
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_s16_sub00_clear				; ENDING F
		SW_PTR	_s16_sub05_kai_key_at_looboth_draw
		SW_PTR	_s16_sub06_kai_kei_at_toolbooth_msg
		SW_PTR	_s16_sub08_old_town_erode_draw
		SW_PTR	_s16_sub09_old_town_erode_mst
		SW_PTR	_s16_sub0A_kaneda_falling_draw
		SW_PTR	_s16_sub0B_kaneda_falling_msg
		SW_PTR	_s16_sub0C_clear
		SW_PTR	_s16_sub0D_kaneda_flying_icon2_draw
		SW_PTR	_s16_sub0E_kaneda_flying_icon2_msg
		SW_PTR	_s16_sub0F_kaneda_face_icon1_draw
		SW_PTR	_s16_sub10_kaneda_face_icon1_msg
		SW_PTR	_s16_sub11_kaneda_flying_icon0_draw
		SW_PTR	_s16_sub12_kaneda_flying_icon0_msg
		SW_PTR	_s16_sub13_kiyoko_draw
		SW_PTR	_s16_sub14_kiyoko_msg
		SW_PTR	_s16_sub15_clear
		SW_PTR	_s16_sub16_kaneda_flying_icon0_draw
		SW_PTR	_s16_sub17_kaneda_face_icon1_draw
		SW_PTR	_s16_sub18_kaneda_flying_icon2_draw
		SW_PTR	_s16_sub19_kaneda_flying_icon2_msg
		SW_PTR	_s16_sub1A_black_hole_draw
		SW_PTR	_s16_sub1B_black_hole_msg
		SW_PTR	_s16_sub1C_building_flooded_small_draw
		SW_PTR	_s16_sub1D_building_flooded_small_msg
		SW_PTR	_s16_sub1E_building_small_draw
		SW_PTR	_s16_sub1F_building_small_msg
		SW_PTR	_s16_sub20_tokyo_from_stadium_draw
		SW_PTR	_s16_sub21_tokyo_from_stadium_msg
		SW_PTR	_s16_sub22_clear
		SW_PTR	_s16_sub23_kaneda_marble_icon0_draw
		SW_PTR	_s16_sub24_kaneda_marble_icon0_msg
		SW_PTR	_s16_sub25_kaneda_marble_icon2_draw
		SW_PTR	_s16_sub26_kaneda_marble_icon2_msg
		SW_PTR	_s16_sub27_clear
		SW_PTR	_s16_sub28_kaneda_marble_icon1_draw
		SW_PTR	_s16_sub29_kaneda_marble_icon1_msg
		SW_PTR	_s16_sub2A_kei_kai_alive_draw
		SW_PTR	_s16_sub2B_kei_kai_alive_msg
		SW_PTR	_s16_sub2C_on_bikes_to_neotokyo_draw
		SW_PTR	_s16_sub2D_on_bikes_to_neotokyo_msg
		SW_PTR	_s16_sub30_emptines0_draw
		SW_PTR	_s16_sub31_emptines0_msg
		SW_PTR	_s16_sub32_emptines1_draw
		SW_PTR	_s16_sub33_emptines1_msg
		SW_PTR	_s16_sub34_universe_draw
		SW_PTR	_s16_sub35_universe_msg
		SW_PTR	_s16_sub36_good_ending_warp

		SW_PTR	_s16_sub41_tetsuo_attaked_msg	; ENDING C
;		SW_PTR	_s16_sub41_tetsuo_attaked_msg
		SW_PTR	_s16_sub42_kids_pray_draw
		SW_PTR	_s16_sub43_kids_pray_msg
		SW_PTR	_s16_sub44_building_flooded_small_draw
		SW_PTR	_s16_sub45_building_flooded_small_msg
		SW_PTR	_s16_sub46_building_small_draw
		SW_PTR	_s16_sub47_building_small_msg
		SW_PTR	_s16_sub48_tokyo_from_stadium_draw
		SW_PTR	_s16_sub47_tokyo_from_stadium_msg

		SW_PTR	_s16_sub50_clear				; ENDING D
		SW_PTR	_s16_sub64_big_light_icon1_draw0
		SW_PTR	_s16_sub51_big_light_icon1_msg0
		SW_PTR	_s16_sub52_big_light_icon1_draw1
		SW_PTR	_s16_sub53_big_light_icon1_msg1
		SW_PTR	_s16_sub54_kai_key_at_toolbooth_draw
		SW_PTR	_s16_sub55_kei_kai_at_toolbooth_msg
		SW_PTR	_s16_sub56_old_town_erode_draw
		SW_PTR	_s16_sub57_old_town_erode_msg
		SW_PTR	_s16_sub58_black_hole_draw
		SW_PTR	_s16_sub59_black_hole_msg
		SW_PTR	_s16_sub5A_building_flooded_small_draw
		SW_PTR	_s16_sub5B_building_flooded_small_msg
		SW_PTR	_s16_sub5C_building_small_draw
		SW_PTR	_s16_sub5D_building_small_msg
		SW_PTR	_s16_sub5E_tokyo_from_stadium_draw
		SW_PTR	_s16_sub5F_tokyo_from_stadium_msg
		SW_PTR	_s16_sub60_kei_kai_alive_draw
		SW_PTR	_s16_sub61_kei_kai_alive_msg
		SW_PTR	_s16_sub62_akira_and_tetsuo_draw
		SW_PTR	_s16_sub63_akira_and_tetsuo_msg

		SW_PTR	_s16_sub66_safe_town_draw		; ENDING A
		SW_PTR	_s16_sub67_fase_town_msg

		SW_PTR	_s16_sub70_kaneda_jump_into_light_draw	; ENDING E
		SW_PTR	_s16_sub71_kaneda_jump_into_light_msg
		SW_PTR	_s16_sub72_clear
		SW_PTR	_s16_sub73_big_light_icon1_draw0
		SW_PTR	_s16_sub75_big_light_icon1_msg0
		SW_PTR	_s16_sub76_big_light_icon1_draw1
		SW_PTR	_s16_sub77_big_light_icon1_msg1
		SW_PTR	_s16_sub78_kei_kai_at_toolbooth_draw
		SW_PTR	_s16_sub79_kei_kai_at_toolbooth_msg
		SW_PTR	_s16_sub7A_old_town_erode_draw
		SW_PTR	_s16_sub7B_old_town_erode_msg
		SW_PTR	_s16_sub7C_kaneda_falling_draw
		SW_PTR	_s16_sub7D_kaneda_falling_msg
		SW_PTR	_s16_sub7E_clear
		SW_PTR	_s16_sub7F_kaneda_flying_icon0_draw
		SW_PTR	_s16_sub81_kaneda_flying_icon0_msg
		SW_PTR	_s16_sub82_kaneda_flying_icon2_draw
		SW_PTR	_s16_sub83_kaneda_flying_icon2_msg
		SW_PTR	_s16_sub84_kaneda_face_icon1_draw
		SW_PTR	_s16_sub85_kaneda_face_icon1_msg
		SW_PTR	_s16_sub86_black_hole_draw
		SW_PTR	_s16_sub87_black_hole_msg
		SW_PTR	_s16_sub88_building_flooded_small_draw
		SW_PTR	_s16_sub89_building_flooded_small_msg
		SW_PTR	_s16_sub8A_building_small_draw
		SW_PTR	_s16_sub8B_building_small_msg
		SW_PTR	_s16_sub8C_tokyo_from_stadium_draw
		SW_PTR	_s16_sub8D_tokyo_from_stadium_msg
		SW_PTR	_s16_sub8E_akira_and_tetsuo_draw
		SW_PTR	_s16_sub8F_akira_and_tetsuo_msg

		SW_PTR	_s16_sub90_orbital_laser_shot_draw	; ENDING B
		SW_PTR	_s16_sub91_orbital_laser_shot_msg
		SW_PTR	_s16_sub92_akira_draw
		SW_PTR	_s16_sub93_akira_msg
		SW_PTR	_s16_sub94_clear
		SW_PTR	_s16_sub95_big_light_icon1_draw0
		SW_PTR	_s16_sub96_big_light_icon1_msg0
		SW_PTR	_s16_sub97_big_light_icon1_draw1
		SW_PTR	_s16_sub98_big_light_icon1_msg1
		SW_PTR	_s16_sub99_building_flooded_small_draw
		SW_PTR	_s16_sub9A_building_flooded_small_msg
		SW_PTR	_s16_sub9B_building_small_draw
		SW_PTR	_s16_sub9C_building_small_msg
		SW_PTR	_s16_sub9D_tokyo_from_stadium_draw
		SW_PTR	_s16_sub9E_tokyo_from_stadium_msg
		SW_PTR	_s16_sub9F_bad_ending_warp

		SW_PTR	_fade_out_reload_scene

;-----------------------------------------------
; ENDING F
;-----------------------------------------------

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub00_clear:
		SW_NXT	_s16_sub05_kai_key_at_looboth_draw	; ENDING F
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub05_kai_key_at_looboth_draw:
		SW_NXT	_s16_sub06_kai_kei_at_toolbooth_msg

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_tlm7F_draw:
		LDA		#1
		STA		_text_typing_snd_disable
		STA		_scene_spr_overlay_idx
		STA		_scene_anim_idx
		STA		_scene_anim_idx+1
		TLM4	$49,$49,$7F

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub06_kai_kei_at_toolbooth_msg:
		JSR		_snd_hard_noise
		SW_FADE	_s16_sub08_old_town_erode_draw
		MSG_M
		MSG		_sc16_msgD9
		MSG		_sc16_msg7C
		MSG		_sc16_msgDA
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub08_old_town_erode_draw:
		SW_NXT	_s16_sub09_old_town_erode_mst

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_tlm80_draw:
		LDA		#0
		STA		_scene_spr_overlay_idx
		TLM4	$4A,$4A,$80

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub09_old_town_erode_mst:
		SW_FADE	_s16_sub0A_kaneda_falling_draw
		MSG_M
		MSG		_sc16_msgDB
		MSG		_sc16_msgDC
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub0A_kaneda_falling_draw:
		SW_NXT	_s16_sub0B_kaneda_falling_msg
;		LDA		#5								; this is overlay for flying debris, totally
;		STA		_scene_spr_overlay_idx			; wrong used here, no CHR or animation settings at all!

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_tlm81_draw:
		TLM5	$4B,$4B,$81

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub0B_kaneda_falling_msg:
		JSR		_apu_reset
		JSR		_snd_kiyoko_psychodelic
		SW_FADE	_s16_sub0C_clear
		MSG_M
		MSG		_sc16_msgDD
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub0C_clear:
		LDA		#0
		STA		_scene_spr_overlay_idx
		SW_NXT	_s16_sub0D_kaneda_flying_icon2_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub0D_kaneda_flying_icon2_draw:
		SW_NXT	_s16_sub0E_kaneda_flying_icon2_msg

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_icon84_draw:
		ICON2	$4B,$4B,$84

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub0E_kaneda_flying_icon2_msg:
		SW_FADE	_s16_sub0F_kaneda_face_icon1_draw
		MSG_M
		MSG		_sc16_msgDE
		MSG		_sc16_msgDF
		MSG		_sc16_msgE0
		MSG		_sc16_msgE1
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub0F_kaneda_face_icon1_draw:
		SW_NXT	_s16_sub10_kaneda_face_icon1_msg
		LDA		#2
		STA		_scene_spr_overlay_idx

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_icon83_draw:
		CHRPAL	$4B,$4B

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_icon83_draw_ex:
		ICON1EX	$83

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub10_kaneda_face_icon1_msg:
		SW_FADE	_s16_sub11_kaneda_flying_icon0_draw
		MSG_M
		MSG		_sc16_msgE2
		MSG		_sc16_msgE3
		MSG		_sc16_msgE4
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub11_kaneda_flying_icon0_draw:
		SW_NXT	_s16_sub12_kaneda_flying_icon0_msg

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_icon82_draw:
		CHRPAL	$4B,$4B

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_icon82_draw_ex:
		ICON0EX	$82

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub12_kaneda_flying_icon0_msg:
		SW_FADE	_s16_sub13_kiyoko_draw
		MSG_M
		MSG		_sc16_msgE5
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub13_kiyoko_draw:
		SW_NXT	_s16_sub14_kiyoko_msg
		LDA		#6								; clear overlay first
		STA		_scene_spr_overlay_idx
		EXJMP	_sF_tlm9C_draw					; defined in system bank

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub14_kiyoko_msg:
		JSR		_snd_kiyoko_psychodelic
		SW_FADE	_s16_sub15_clear
		MSG_M
		MSG		_sc16_msg0D
		MSG		_sc16_msg0E
		MSG		_sc16_msg0F
		MSG		_sc16_msg10
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub15_clear:
		SW_NXT	_s16_sub16_kaneda_flying_icon0_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub16_kaneda_flying_icon0_draw:
		SW_NXT	_s16_sub17_kaneda_face_icon1_draw
		JMP		_s16_icon82_draw_ex

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub17_kaneda_face_icon1_draw:
		SW_NXT	_s16_sub18_kaneda_flying_icon2_draw
		JMP		_s16_icon83_draw_ex

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub18_kaneda_flying_icon2_draw:
		SW_NXT	_s16_sub19_kaneda_flying_icon2_msg
		LDA		#2
		STA		_scene_spr_overlay_idx
		JMP		_s16_icon84_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub19_kaneda_flying_icon2_msg:
		SW_FADE	_s16_sub1A_black_hole_draw
		MSG_M
		MSG		_sc16_msg11
		MSG		_sc16_msgE7
		MSG		_sc16_msg14
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub1A_black_hole_draw:
		SW_NXT	_s16_sub1B_black_hole_msg

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_tlm85_draw:
		LDA		#0
		STA		_scene_spr_overlay_idx
		TLM4	$4C,$4C,$85

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub1B_black_hole_msg:
		JSR		_snd_black_hole_theme
		SW_FADE	_s16_sub1C_building_flooded_small_draw
		MSG_M
		MSG		_sc16_msgE6
		MSG		_sc16_msgE8
		MSG		_sc16_msgE9
		MSG		_sc16_msgEA
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub1C_building_flooded_small_draw:
		SW_NXT	_s16_sub1D_building_flooded_small_msg

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_tlm86_draw:
		TLM5	$4D,$4D,$86

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub1D_building_flooded_small_msg:
		SW_FADE	_s16_sub1E_building_small_draw
		MSG_M
		MSG		_sc16_msgEB
		MSG		_sc16_msgEC
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub1E_building_small_draw:
		SW_NXT	_s16_sub1F_building_small_msg

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_tlm89_draw:
		TLM5	$4E,$4E,$89

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub1F_building_small_msg:
		JSR		_apu_reset
		JSR		_snd_water_flood_recide
		SW_FADE	_s16_sub20_tokyo_from_stadium_draw
		MSG_M
		MSG		_sc16_msgED
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub20_tokyo_from_stadium_draw:
		SW_NXT	_s16_sub21_tokyo_from_stadium_msg

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_tlm8A_draw:
		TLM4	$4F,$4F,$8A

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub21_tokyo_from_stadium_msg:
		SW_FADE	_s16_sub22_clear
		MSG_M
		MSG		_sc16_msgEE
		MSG		_sc16_msg1D
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub22_clear:
		SW_NXT	_s16_sub23_kaneda_marble_icon0_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub23_kaneda_marble_icon0_draw:
		SW_NXT	_s16_sub24_kaneda_marble_icon0_msg
		LDA		#4
		STA		_scene_spr_overlay_idx
		LDA		#$20
		STA		_tmp_y_pos
		LDA		#$28
		STA		_tmp_x_pos
		ICON0	$4F,$50,$8B

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub24_kaneda_marble_icon0_msg:
		JSR		_snd_marble_descent
		SW_FADE	_s16_sub25_kaneda_marble_icon2_draw
		MSG_M
		MSG		_sc16_msg1E
		MSG		_sc16_msg00
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub25_kaneda_marble_icon2_draw:
		SW_NXT	_s16_sub26_kaneda_marble_icon2_msg
		LDA		#7
		STA		_scene_spr_overlay_idx
		ICON2	$4F,$50,$8C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub26_kaneda_marble_icon2_msg:
		SW_FADE	_s16_sub27_clear
		MSG_M
		MSG		_sc16_msg1F
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub27_clear:
		JSR		_apu_reset
		SW_NXT	_s16_sub28_kaneda_marble_icon1_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub28_kaneda_marble_icon1_draw:
		SW_NXT	_s16_sub29_kaneda_marble_icon1_msg
		LDA		#0
		STA		_scene_spr_overlay_idx
		ICON1	$4F,$50,$8D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub29_kaneda_marble_icon1_msg:
		SW_FADE	_s16_sub2A_kei_kai_alive_draw
		MSG_M
		MSG		_sc16_msg20
		MSG		_sc16_msg21
		MSG		_sc16_msg01
		MSG		_sc16_msg22
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub2A_kei_kai_alive_draw:
		SW_NXT	_s16_sub2B_kei_kai_alive_msg

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_tlm8E_draw:
		LDA		#3
		STA		_scene_spr_overlay_idx
		TLM4	$50,$51,$8E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub2B_kei_kai_alive_msg:
		SW_FADE	_s16_sub2C_on_bikes_to_neotokyo_draw
		MSG_M
		MSG		_sc16_msgEF
		MSG		_sc16_msg2B
		MSG		_sc16_msg24
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub2C_on_bikes_to_neotokyo_draw:
		SW_NXT	_s16_sub2D_on_bikes_to_neotokyo_msg
		LDA		#9
		STA		_scene_spr_overlay_idx
		TLM5	$6F,$72,$A5

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub2D_on_bikes_to_neotokyo_msg:
		JSR		_snd_bike_ride
		SW_FADE	_s16_sub30_emptines0_draw
		MSG_M
		MSG		_sc16_msg25
		MSG		_sc16_msg26
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub30_emptines0_draw:
		JSR		_apu_reset
		SW_NXT	_s16_sub31_emptines0_msg
		LDA		#0
		STA		_scene_spr_overlay_idx
		TLM4	$53,$55,$92

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub31_emptines0_msg:
		SW_FADE	_s16_sub32_emptines1_draw
		MSG_M
		MSG		_sc16_msg27
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub32_emptines1_draw:
		SW_NXT	_s16_sub33_emptines1_msg
		TLM4	$53,$54,$91

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub33_emptines1_msg:
		SW_FADE	_s16_sub34_universe_draw
		MSG_M
		MSG		_sc16_msg28
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub34_universe_draw:
		SW_NXT	_s16_sub35_universe_msg

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_tlm93_draw:
		TLM4	$53,$56,$93

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub35_universe_msg:
		SW_FADE	_s16_sub36_good_ending_warp
		MSG_M
		MSG		_sc16_msg29
		MSG		_sc16_msg2A
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub36_good_ending_warp:
		LDA		#0
		STA		_staff_screen_idx
		STA		_bad_ending_flag
		STA		_text_typing_snd_disable
		WARP	$18,_s18_sub00_ending

;-----------------------------------------------
; ENDING C
;-----------------------------------------------

_s16_sub41_tetsuo_attaked_msg:
		SW_FADE	_s16_sub42_kids_pray_draw
		LDA		#8
		STA		_scene_spr_overlay_idx
		MSG_M
		MSG		_sc15_16_msgC5
		MSG		_sc15_16_msgC6
		MSG		_sc15_16_msgC7
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub42_kids_pray_draw:
		SW_NXT	_s16_sub43_kids_pray_msg
		FJMP	_s15_tlm76_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub43_kids_pray_msg:
		SW_FADE	_s16_sub44_building_flooded_small_draw
		MSG_M
		MSG		_sc15_16_msgC8
		MSG		_sc16_msgCC
		MSG		_sc16_msgCD
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub44_building_flooded_small_draw:
		SW_NXT	_s16_sub45_building_flooded_small_msg
		JMP		_s16_tlm86_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub45_building_flooded_small_msg:
		JSR		_snd_bad_ending_theme
		SW_FADE	_s16_sub46_building_small_draw
		MSG_M
		MSG		_sc16_msgCE
		MSG		_sc16_msgCF
		MSG		_sc16_msgEC
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub46_building_small_draw:
		SW_NXT	_s16_sub47_building_small_msg
		JMP		_s16_tlm89_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub47_building_small_msg:
		SW_FADE	_s16_sub48_tokyo_from_stadium_draw
		MSG_M
		MSG		_sc16_msgED
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub48_tokyo_from_stadium_draw:
		SW_NXT	_s16_sub47_tokyo_from_stadium_msg
		JMP		_s16_tlm8A_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub47_tokyo_from_stadium_msg:
		LDA		#0
		STA		_keep_tetsuo_overlay_for_ending_flag	; bad ending has only one overlay
		SW_NXT	_s16_sub9F_bad_ending_warp		; which is not this place
		MSG_M
		MSG		_sc16_msgD0
		MSG_WAIT
		MSG_EOL

;-----------------------------------------------
; ENDING D
;-----------------------------------------------

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub50_clear:
		SW_NXT	_s16_sub64_big_light_icon1_draw0
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub64_big_light_icon1_draw0:
		SW_NXT	_s16_sub51_big_light_icon1_msg0
;		ICON2	$48,$48,$7D						; seems the same shit as in SCENE 15 ending
		ICON1	$48,$48,$7C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub51_big_light_icon1_msg0:
		JSR		_snd_bad_ending_theme
		SW_FADE	_s16_sub52_big_light_icon1_draw1
		MSG_M
		MSG		_sc15_16_msgC9
		MSG		_sc16_msgD1
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub52_big_light_icon1_draw1:
		SW_NXT	_s16_sub53_big_light_icon1_msg1

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_icon7E_draw:
;		ICON0	$48,$48,$7E						; sync the same scene as for SCENE 15 ending
		ICON1	$48,$48,$7E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub53_big_light_icon1_msg1:
		SW_FADE	_s16_sub54_kai_key_at_toolbooth_draw
		MSG_M
		MSG		_sc15_16_msgCA
		MSG		_sc15_16_msgCB
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub54_kai_key_at_toolbooth_draw:
		SW_NXT	_s16_sub55_kei_kai_at_toolbooth_msg
		JMP		_s16_tlm7F_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub55_kei_kai_at_toolbooth_msg:
		SW_FADE	_s16_sub56_old_town_erode_draw
		MSG_M
		MSG		_sc16_msgD9
		MSG		_sc16_msg7C
		MSG		_sc16_msgDA
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub56_old_town_erode_draw:
		SW_NXT	_s16_sub57_old_town_erode_msg
		JMP		_s16_tlm80_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub57_old_town_erode_msg:
		SW_FADE	_s16_sub58_black_hole_draw
		MSG_M
		MSG		_sc16_msgDB
		MSG		_sc16_msgDC
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub58_black_hole_draw:
		SW_NXT	_s16_sub59_black_hole_msg
		JMP		_s16_tlm85_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub59_black_hole_msg:
		SW_FADE	_s16_sub5A_building_flooded_small_draw
		MSG_M
		MSG		_sc16_msgE6
		MSG		_sc16_msgE8
		MSG		_sc16_msgE9
		MSG		_sc16_msgEA
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub5A_building_flooded_small_draw:
		SW_NXT	_s16_sub5B_building_flooded_small_msg
		JMP		_s16_tlm86_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub5B_building_flooded_small_msg:
		SW_FADE	_s16_sub5C_building_small_draw
		MSG_M
		MSG		_sc16_msgEB
		MSG		_sc16_msgEC
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub5C_building_small_draw:
		SW_NXT	_s16_sub5D_building_small_msg
		JMP		_s16_tlm89_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub5D_building_small_msg:
		SW_FADE	_s16_sub5E_tokyo_from_stadium_draw
		MSG_M
		MSG		_sc16_msgED
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub5E_tokyo_from_stadium_draw:
		SW_NXT	_s16_sub5F_tokyo_from_stadium_msg
		JMP		_s16_tlm8A_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub5F_tokyo_from_stadium_msg:
		SW_FADE	_s16_sub60_kei_kai_alive_draw
		MSG_M
		MSG		_sc16_msgEE
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub60_kei_kai_alive_draw:
		SW_NXT	_s16_sub61_kei_kai_alive_msg
		JMP		_s16_tlm8E_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub61_kei_kai_alive_msg:
		SW_FADE	_s16_sub62_akira_and_tetsuo_draw
		MSG_M
		MSG		_sc16_msgD2
		MSG		_sc16_msgEF
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub62_akira_and_tetsuo_draw:
		SW_NXT	_s16_sub63_akira_and_tetsuo_msg

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_tlm87_draw:
		LDA		#$A
		STA		_scene_spr_overlay_idx
		LDA		#1
		STA		_forbid_ending_overlays_flag
		TLM4	$64,$65,$87

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub63_akira_and_tetsuo_msg:
		LDA		#1
		STA		_keep_tetsuo_overlay_for_ending_flag	; bad ending with tetsuo!
		SW_NXT	_s16_sub9F_bad_ending_warp
		MSG_M
		MSG		_sc16_msgD4
		MSG		_sc16_msgD5
		MSG_WAIT
		MSG_EOL

;-----------------------------------------------
; ENDING A
;-----------------------------------------------

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub66_safe_town_draw:
		SW_NXT	_s16_sub67_fase_town_msg
		TLM4	$65,$71,$A4

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub67_fase_town_msg:
		LDA		#0
		STA		_keep_tetsuo_overlay_for_ending_flag
		SW_NXT	_s16_sub9F_bad_ending_warp
		MSG_M
		MSG		_sc16_msg9C
		MSG_WAIT
		MSG_EOL

;-----------------------------------------------
; ENDING E
;-----------------------------------------------

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub70_kaneda_jump_into_light_draw:
		SW_NXT	_s16_sub71_kaneda_jump_into_light_msg
		FJMP	_s15_tlm9E_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub71_kaneda_jump_into_light_msg:
		SW_FADE	_s16_sub72_clear
		MSG_M
		MSG		_sc2_13_15_16_msg82
		MSG		_sc16_msgD6
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub72_clear:
		SW_NXT	_s16_sub73_big_light_icon1_draw0
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub73_big_light_icon1_draw0:
		SW_NXT	_s16_sub75_big_light_icon1_msg0
;		ICON2	$48,$48,$7C						; this damn scene is the same, but
		ICON1	$48,$48,$7C						; has three different icon layouts, all WRONG!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub75_big_light_icon1_msg0:
		JSR		_snd_bad_ending_theme
		SW_FADE	_s16_sub76_big_light_icon1_draw1
		MSG_M
		MSG		_sc15_16_msgC9
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub76_big_light_icon1_draw1:
		SW_NXT	_s16_sub77_big_light_icon1_msg1
;		FJMP	_s15_icon7D_draw				; again wrong
		JMP		_s16_icon7E_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub77_big_light_icon1_msg1:
		SW_FADE	_s16_sub78_kei_kai_at_toolbooth_draw
		MSG_M
		MSG		_sc15_16_msgCA
		MSG		_sc15_16_msgCB
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub78_kei_kai_at_toolbooth_draw:
		SW_NXT	_s16_sub79_kei_kai_at_toolbooth_msg
		JMP		_s16_tlm7F_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub79_kei_kai_at_toolbooth_msg:
		SW_FADE	_s16_sub7A_old_town_erode_draw
		MSG_M
		MSG		_sc16_msgD9
		MSG		_sc16_msg7C
		MSG		_sc16_msgDA
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub7A_old_town_erode_draw:
		SW_NXT	_s16_sub7B_old_town_erode_msg
		JMP		_s16_tlm80_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub7B_old_town_erode_msg:
		SW_FADE	_s16_sub7C_kaneda_falling_draw
		MSG_M
		MSG		_sc16_msgDB
		MSG		_sc16_msgDC
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub7C_kaneda_falling_draw:
		SW_NXT	_s16_sub7D_kaneda_falling_msg
		JMP		_s16_tlm81_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub7D_kaneda_falling_msg:
		SW_FADE	_s16_sub7E_clear
		MSG_M
		MSG		_sc16_msgDD
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub7E_clear:
		SW_NXT	_s16_sub7F_kaneda_flying_icon0_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub7F_kaneda_flying_icon0_draw:
		SW_NXT	_s16_sub81_kaneda_flying_icon0_msg
		JMP		_s16_icon82_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub81_kaneda_flying_icon0_msg:
		SW_FADE	_s16_sub82_kaneda_flying_icon2_draw
		MSG_M
		MSG		_sc16_msgDE
		MSG		_sc16_msgDF
		MSG		_sc16_msgE0
		MSG		_sc16_msgE1
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub82_kaneda_flying_icon2_draw:
		SW_NXT	_s16_sub83_kaneda_flying_icon2_msg
		JMP		_s16_icon84_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub83_kaneda_flying_icon2_msg:
		SW_FADE	_s16_sub84_kaneda_face_icon1_draw
		MSG_M
		MSG		_sc16_msgE2
		MSG		_sc16_msgE3
		MSG		_sc16_msgE4
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub84_kaneda_face_icon1_draw:
		SW_NXT	_s16_sub85_kaneda_face_icon1_msg
		LDA		#2
		STA		_scene_spr_overlay_idx
		JMP		_s16_icon83_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub85_kaneda_face_icon1_msg:
		SW_FADE	_s16_sub86_black_hole_draw
		MSG_M
		MSG		_sc16_msgE5
		MSG		_sc16_msgE7
		MSG		_scC_D_13_16_msg90
		MSG		_sc16_msgD7
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub86_black_hole_draw:
		SW_NXT	_s16_sub87_black_hole_msg
		JMP		_s16_tlm85_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub87_black_hole_msg:
		SW_FADE	_s16_sub88_building_flooded_small_draw
		MSG_M
		MSG		_sc16_msgE6
		MSG		_sc16_msgE8
		MSG		_sc16_msgE9
		MSG		_sc16_msgEA
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub88_building_flooded_small_draw:
		SW_NXT	_s16_sub89_building_flooded_small_msg
		JMP		_s16_tlm86_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub89_building_flooded_small_msg:
		SW_FADE	_s16_sub8A_building_small_draw
		MSG_M
		MSG		_sc16_msgEB
		MSG		_sc16_msgEC
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub8A_building_small_draw:
		SW_NXT	_s16_sub8B_building_small_msg
		JMP		_s16_tlm89_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub8B_building_small_msg:
		SW_FADE	_s16_sub8C_tokyo_from_stadium_draw
		MSG_M
		MSG		_sc16_msgED
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub8C_tokyo_from_stadium_draw:
		SW_NXT	_s16_sub8D_tokyo_from_stadium_msg
		JMP		_s16_tlm8A_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub8D_tokyo_from_stadium_msg:
		SW_FADE	_s16_sub8E_akira_and_tetsuo_draw
		MSG_M
		MSG		_sc16_msgD8
		MSG		_sc16_msgD3
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub8E_akira_and_tetsuo_draw:
		SW_NXT	_s16_sub8F_akira_and_tetsuo_msg
		JMP		_s16_tlm87_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub8F_akira_and_tetsuo_msg:
		LDA		#1
		STA		_keep_tetsuo_overlay_for_ending_flag
		SW_NXT	_s16_sub9F_bad_ending_warp
		MSG_M
		MSG		_sc16_msgD4
		MSG		_sc16_msgD5
		MSG_WAIT
		MSG_EOL

;-----------------------------------------------
; ENDING B
;-----------------------------------------------

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub90_orbital_laser_shot_draw:
		SW_NXT	_s16_sub91_orbital_laser_shot_msg
		FJMP	_s13_tlm63_draw					; 1 time here

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub91_orbital_laser_shot_msg:
		JSR		_snd_orbital_laser_shot
		SW_FADE	_s16_sub92_akira_draw
		MSG_M
		MSG		_sc16_msgC0
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub92_akira_draw:
		SW_NXT	_s16_sub93_akira_msg
		EXJMP	_s15_tlm7A_draw					; defined in system bank

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub93_akira_msg:
		JSR		_apu_reset
		JSR		_snd_akira_flashback_suddenly
		SW_FADE	_s16_sub94_clear
		MSG_M
		MSG		_sc16_msgE5
		MSG		_sc16_msgC2
		MSG		_sc16_msgC3
		MSG		_sc2_13_15_16_msg82
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub94_clear:
		SW_NXT	_s16_sub95_big_light_icon1_draw0
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub95_big_light_icon1_draw0:
		SW_NXT	_s16_sub96_big_light_icon1_msg0
;		ICON0	$48,$48,$7D
		ICON1	$48,$48,$7C						; and again?!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub96_big_light_icon1_msg0:
		JSR		_apu_reset
		JSR		_snd_bad_ending_theme
		SW_FADE	_s16_sub97_big_light_icon1_draw1
		MSG_M
		MSG		_sc15_16_msgC9
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub97_big_light_icon1_draw1:
		SW_NXT	_s16_sub98_big_light_icon1_msg1
;		ICON2	$48,$48,$7E
		ICON1	$48,$48,$7E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub98_big_light_icon1_msg1:
		SW_FADE	_s16_sub99_building_flooded_small_draw
		MSG_M
		MSG		_sc15_16_msgCA
		MSG		_sc15_16_msgCB
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub99_building_flooded_small_draw:
		SW_NXT	_s16_sub9A_building_flooded_small_msg
		JMP		_s16_tlm86_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub9A_building_flooded_small_msg:
		SW_FADE	_s16_sub9B_building_small_draw
		MSG_M
		MSG		_sc16_msgEB
		MSG		_sc16_msgEC
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub9B_building_small_draw:
		SW_NXT	_s16_sub9C_building_small_msg
		JMP		_s16_tlm89_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub9C_building_small_msg:
		SW_FADE	_s16_sub9D_tokyo_from_stadium_draw
		MSG_M
		MSG		_sc16_msgED
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub9D_tokyo_from_stadium_draw:
		SW_NXT	_s16_sub9E_tokyo_from_stadium_msg
		JMP		_s16_tlm8A_draw

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub9E_tokyo_from_stadium_msg:
		LDA		#0
		STA		_keep_tetsuo_overlay_for_ending_flag
		SW_NXT	_s16_sub9F_bad_ending_warp
		MSG_M
		MSG		_sc16_msgC4
		MSG		_sc16_msg7E
		MSG		_sc16_msg7D
		MSG_WAIT
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_sub9F_bad_ending_warp:
		LDA		#0
		STA		_staff_screen_idx
		LDA		#1
		STA		_bad_ending_flag
		WARP	$18,_s18_sub00_ending

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_spr_overlay_set:
		LDA		_scene_spr_overlay_idx
		SWITCH
		SW_PTR	_nullsub
		SW_PTR	_s16_spr_overlay1
		SW_PTR	_s16_spr_overlay2
		SW_PTR	_s16_spr_overlay3
		SW_PTR	_s16_spr_overlay4
		SW_PTR	_nullsub						; _s16_spr_overlay5 wrong overlay, from unknown place
		EXOFS	_sF_spr_overlay8				; defined in system bank
		SW_PTR	_s16_spr_overlay7
		EXOFS	_s15_spr_overlay5
		SW_PTR	_s16_spr_overlay9
		SW_PTR	_s16_spr_overlayA

;-------------S-U-B-R-O-U-T-I-N-E---------------
		FJMP	_s15_spr_overlay5				; 1 time here as OFS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_spr_overlay1:
		JSR		_get_anim_blink_idx				; split eyes blink animations
		PHA
		SPR0SW	off_81A47,$32,$60
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0SW	off_81A4D,$3B,$5F
		PLA										; use the same blink anin
		SPR0SW	off_81A89,$58,$C8
		JSR		_do_scene_anim1_pat0101
		LDA		_scene_anim_idx+1
		SPR0JSW	off_81A8F,$68,$C8
off_81A89:
		.WORD _spr_sc16_kai_eyes0
		.WORD _spr_sc16_kai_eyes1
off_81A8F:
		.WORD _spr_sc16_kai_mouth0
		.WORD _spr_sc16_kai_mouth1
off_81A47:
		.WORD _spr_sc16_kei_eyes0
		.WORD _spr_sc16_kei_eyes1
off_81A4D:
		.WORD _spr_sc16_kei_mouth1
		.WORD _spr_sc16_kei_mouth0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_spr_overlay2:
		JSR		_get_anim_blink_idx
		SPR0SW	off_81ACC,$58,$70
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0JSW	off_81AD2,$68,$78
off_81ACC:
		.WORD _spr_sc16_kaneda_face_eyes0
		.WORD _spr_sc16_kaneda_face_eyes1
off_81AD2:
		.WORD _spr_sc16_kaneda_face_mouth0
		.WORD _spr_sc16_kaneda_face_mouth1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_spr_overlay3:
		JSR		_get_anim_blink_idx
		SPR0SW	off_81B0F,$58,$A8
		JSR		_do_scene_anim1_pat0101
		LDA		_scene_anim_idx+1
		SPR0SW	off_81B15,$60,$B0
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx
		SPR0SW	off_81B52,$68,$38
		JSR		_get_anim_blink_idx
		SPR0JSW	off_81B58,$58,$30
off_81B52:
		.WORD _spr_sc16_kai_mouth2
		.WORD _spr_sc16_kai_mouth3
off_81B58:
		.WORD _spr_sc16_kai_eyes2
		.WORD _spr_sc16_kai_eyes3
off_81B0F:
		.WORD _spr_sc16_kei_eyes2
		.WORD _spr_sc16_kei_eyes3
off_81B15:
		.WORD _spr_sc16_kei_mouth2
		.WORD _spr_sc16_kei_mouth3


;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_spr_overlay4:
		JSR		_s16_spr_overlay4_A

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_spr_overlay4_B:
		JSR		_do_scene_anim0_pat0101
		LDA		_scene_anim_idx					; only 1 used, no speech there
		SPR0JSW	off_81B78,$30,$28
off_81B78:
		.WORD _spr_sc16_kaneda_marble_mouth0
		.WORD _spr_sc16_kaneda_marble_mouth1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_spr_overlay4_A:
		LDA		_frames_counter
		AND		#$7
		BNE		.skip_anim
		LDA		_tmp_y_pos
		CMP		#$40
		BEQ		.skip_anim
		CLC
		ADC		#1
		STA		_tmp_y_pos
.skip_anim:
		LDA		_tmp_y_pos
		STA		word_2
		LDA		_tmp_x_pos
		STA		word_2+1
		LDA		_frames_counter
		LSR
		LSR
		LSR
		LSR
		AND		#1
		SPR0SWEX	off_81BB7
		RTS

off_81BB7:
		.WORD _spr_sc16_small_marble0
		.WORD _spr_sc16_small_marble1

;-------------S-U-B-R-O-U-T-I-N-E---------------
;_s16_spr_overlay5:
;		LDA		_tmp_y_pos
;		STA		word_2
;		LDA		_tmp_x_pos
;		STA		word_2+1
;		JSR		_s16_spr_overlay5_A
;		LDA		_tmp_direction_y0
;		STA		word_2
;		LDA		_tmp_direction_x0
;		STA		word_2+1
;		JSR		_s16_spr_overlay5_A
;		LDA		_tmp_direction_y1+1
;		STA		word_2
;		LDA		_tmp_direction_x1+1
;		STA		word_2+1
;		JSR		_s16_spr_overlay5_A
;		LDA		_sgame_kaneda_bullet_dir_y+1
;		STA		word_2
;		LDA		_sgame_kaneda_bullet_dir_x+1
;		STA		word_2+1

; !FALLTHROUGH!

;-------------S-U-B-R-O-U-T-I-N-E---------------
;_s16_spr_overlay5_A:
;		LDA		_scene_anim_idx
;		SPR0SWEX	off_81B8E
;		RTS
;off_81B8E:
;		.WORD byte_81D59
;		.WORD byte_81D5E
;		.WORD byte_81D63
;		.WORD byte_81D68

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_spr_overlay7:
		JSR		_s16_spr_overlay4_A				; note, that position here is inited in prev overlay!
		JSR		_s16_spr_overlay4_B
		LDA		#$30
		STA		_tmp_direction_y0
		STA		word_2
		LDA		#$D0
		STA		_tmp_direction_x0
		STA		word_2+1
		LDA		_frames_counter
		LSR
		LSR
		LSR
		LSR
		AND		#1
		SPR0SWEX	off_81BDC
		RTS

off_81BDC:
		.WORD _spr_sc16_large_marble0
		.WORD _spr_sc16_large_marble1

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_spr_overlay9:
		SPR0	_spr_sc16_tokyo_bike0,$38,$40
		SPR0J	_spr_sc16_tokyo_bike1,$58,$88

;-------------S-U-B-R-O-U-T-I-N-E---------------
_s16_spr_overlayA:
		SPR0J	_spr_sc16_tetsuo_in_other_world,$20,$A8

_spr_sc16_tetsuo_in_other_world:
		.BYTE   0,$80,  1,$18
		.BYTE   0,$82,  1,$20
		.BYTE   0,$83,  1,$28
		.BYTE   0,$84,  1,$30
		.BYTE   8,$85,  1,$18
		.BYTE   8,$86,  1,$20
		.BYTE   8,  3,  1,$28
		.BYTE   8,$87,  1,$30
		.BYTE $10,$88,  1,$18
		.BYTE $10,$89,  2,$20
		.BYTE $10,$8A,  1,$28
		.BYTE $10,$8B,  3,$30
		.BYTE $18,$8C,  1,$18
		.BYTE $18,$8D,  1,$20
		.BYTE $18,$8E,  1,$28
		.BYTE $18,$8F,  3,$30
		.BYTE $18,$90,  3,$38
		.BYTE $20,$91,  3,$20
		.BYTE $20,$92,  3,$28
		.BYTE $20,$93,  3,$38
		.BYTE $28,$94,  3,$18
		.BYTE $28,$95,  3,$20
		.BYTE $28,$96,  3,$28
		.BYTE $28,$97,  3,$38
		.BYTE $30,$98,  3,$18
		.BYTE $30,$99,  3,$20
		.BYTE $30,$9A,  3,$38
		.BYTE $38,$9B,  3,$10
		.BYTE $38,$9C,  3,$18
		.BYTE $38,$9D,  3,$30
		.BYTE $38,$9E,  3,$38
		.BYTE $40,$9F,  3,$10
		.BYTE $40,$A0,  3,$18
		.BYTE $40,$A1,  3,$30
		.BYTE $40,$A2,  3,$38
		.BYTE $48,$A3,  3,  8
		.BYTE $48,$A4,  3,$10
		.BYTE $48,$A5,  3,$18
		.BYTE $48,$A6,  3,$30
		.BYTE $50,$9B,  3,  0
		.BYTE $50,$A7,  3,  8
		.BYTE $50,$A8,  3,$10
		.BYTE $50,$A9,  3,$18
		.BYTE $50,$AA,  3,$30
		.BYTE $58,$AB,  3,  0
		.BYTE $58,$AC,  3,  8
		.BYTE $58,$AD,  3,$10
		.BYTE $58,$AE,  3,$18
		.BYTE $58,$AA,  3,$30
		.BYTE $80
_spr_sc16_kei_eyes0:
		.BYTE   0,$ED,  1,  0
		.BYTE $80
_spr_sc16_kei_eyes1:
		.BYTE   0,$EE,  1,  0
		.BYTE $80
_spr_sc16_kei_mouth0:
		.BYTE   0,$EF,  1,  0
		.BYTE $80
_spr_sc16_kei_mouth1:
		.BYTE   0,$F0,  0,  0
		.BYTE $80
_spr_sc16_kai_mouth0:
		.BYTE   0,$F8,  1,  7
		.BYTE $80
_spr_sc16_kai_mouth1:
		.BYTE   0,$F5,  1,  7
		.BYTE $80
_spr_sc16_kai_eyes0:
		.BYTE   0,$F1,  1,  0
		.BYTE   0,$F2,  1,  9
		.BYTE   8,$F3,  1,  0
		.BYTE   8,$F4,  1,  9
		.BYTE $80
_spr_sc16_kai_eyes1:
		.BYTE   0,$F1,  1,  0
		.BYTE   0,$F2,  1,  9
		.BYTE   8,$F6,  1,  0
		.BYTE   8,$F7,  1,  9
		.BYTE $80
_spr_sc16_kaneda_face_eyes0:
		.BYTE   0,$99,  1,  0
		.BYTE   0,$9A,  1,  8
		.BYTE   0,$9B,  1,$10
		.BYTE   0,$9C,  1,$18
		.BYTE $80
_spr_sc16_kaneda_face_eyes1:
		.BYTE   0,$9D,  1,  0
		.BYTE   0,$9E,  1,  8
		.BYTE   0,$9F,  1,$10
		.BYTE   0,$A0,  1,$18
		.BYTE $80
_spr_sc16_kaneda_face_mouth1:
		.BYTE   0,$A5,  1,  0
		.BYTE   0,$A6,  1,  8
		.BYTE $80
_spr_sc16_kaneda_face_mouth0:
		.BYTE   0,$A1,  1,  0
		.BYTE   0,$A2,  1,  8
		.BYTE   8,$A3,  1,  0
		.BYTE   8,$A4,  1,  8
		.BYTE $80
_spr_sc16_kei_eyes2:
		.BYTE   0,$E8,  1,  0
		.BYTE   0,$E9,  1,  8
		.BYTE   0,$EA,  1,$10
		.BYTE $80
_spr_sc16_kei_eyes3:
		.BYTE   0,$EC,  1,  0
		.BYTE   0,$ED,  1,  8
		.BYTE   0,$EE,  1,$10
		.BYTE $80
_spr_sc16_kei_mouth3:
		.BYTE   0,$EB,  1,  0
		.BYTE $80
_spr_sc16_kei_mouth2:
		.BYTE   0,$EF,  1,  0
		.BYTE $80
_spr_sc16_kai_mouth3:
		.BYTE   0,$E6,  1,  0
		.BYTE   0,$E7,  1,  8
		.BYTE $80
_spr_sc16_kai_mouth2:
		.BYTE   0,$E2,  1,  0
		.BYTE   0,$E3,  1,  8
		.BYTE $80
_spr_sc16_kai_eyes2:
		.BYTE   8,$E0,  1,  8
		.BYTE   8,$E1,  1,$10
		.BYTE $80
_spr_sc16_kai_eyes3:
		.BYTE   8,$E4,  1,  8
		.BYTE   8,$E5,  1,$10
		.BYTE $80
_spr_sc16_kaneda_marble_mouth0:
		.BYTE   0,$F0,  1,  0
		.BYTE   0,$F1,  1,  8
		.BYTE $18,$BC,  1,$F8
		.BYTE $18,$BD,  1,$18
		.BYTE $80
_spr_sc16_kaneda_marble_mouth1:
		.BYTE   0,$F2,  1,  0
		.BYTE   0,$F3,  1,  8
		.BYTE $18,$BC,  1,$F8
		.BYTE $18,$BD,  1,$18
		.BYTE $80
_spr_sc16_small_marble0:
		.BYTE   0,$BF,  1,  0
		.BYTE $80
_spr_sc16_small_marble1:
		.BYTE   0,$BF,  2,  0
		.BYTE $80
_spr_sc16_large_marble0:
		.BYTE   0,$C0,  2,  0
		.BYTE $80
_spr_sc16_large_marble1:
		.BYTE   0,$C1,  2,  0
		.BYTE $80
;byte_81D59:
;		.BYTE   0,$FB,  2,  0
;		.BYTE $80
;byte_81D5E:
;		.BYTE   0,$FC,  2,  0
;		.BYTE $80
;byte_81D63:
;		.BYTE   0,$FD,  2,  0
;		.BYTE $80
;byte_81D68:
;		.BYTE   0,$FE,  2,  0
;		.BYTE $80
_spr_sc16_tokyo_bike0:
		.BYTE   0,$DA,  2,  0
		.BYTE   0,$DB,  2,  8
		.BYTE   8,$DC,  2,  0
		.BYTE   8,$DD,  2,  8
		.BYTE   8,$DE,  2,$10
		.BYTE $10,$DF,  2,  0
		.BYTE $10,$E0,  2,  8
		.BYTE $10,$E1,  2,$10
		.BYTE $10,$E2,  3,$18
		.BYTE $10,$E3,  3,$20
		.BYTE $18,$E4,  2,  0
		.BYTE $18,$E5,  2,  8
		.BYTE $18,$E6,  3,$10
		.BYTE $18,$E7,  3,$18
		.BYTE $18,$E8,  3,$20
		.BYTE $20,$E9,  2,  0
		.BYTE $20,$EA,  3,  8
		.BYTE $20,$EB,  3,$10
		.BYTE $20,$EC,  3,$18
		.BYTE $20,$ED,  3,$20
		.BYTE $28,$EE,  2,  0
		.BYTE $28,$EF,  3,  8
		.BYTE $28,$F0,  3,$10
		.BYTE $28,$F1,  3,$18
		.BYTE $80
_spr_sc16_tokyo_bike1:
		.BYTE   5,$F2,  1,  0
		.BYTE   0,$F3,  1,  8
		.BYTE   8,$F4,  1,  8
		.BYTE $80

		SECTION_END 16
