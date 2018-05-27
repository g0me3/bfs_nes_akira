
		SECTION_START E

;-----------------------------------------------
; SCENE E
;-----------------------------------------------

; no interactive events

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sceneE_subs:
		LDA		_draw_state_idx
		BNE		locret_98045
		LDA		_scene_sub_cur
		SWITCH
		SW_PTR	_sE_sub00_clear
		SW_PTR	_next_scene
		SW_PTR	_fade_out_reload_scene
		SW_PTR	_sE_sub05_hover_icon2_draw
		SW_PTR	_sE_sub06_hover_icon2_msg
		SW_PTR	_sE_sub09_hover_icon1_draw
		SW_PTR	_sE_sub0C_hover_icon0_draw
		SW_PTR	_sE_sub0D_hover_icon0_msg

locret_98045:
		RTS

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sE_sub00_clear:
		SW_NXT	_sE_sub05_hover_icon2_draw
		JMP		_clear_nt0

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sE_sub05_hover_icon2_draw:
		SW_NXT	_sE_sub06_hover_icon2_msg
		ICON2	$26,$23,$3C

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sE_sub06_hover_icon2_msg:
		JSR		_snd_fly_on_hover
		SW_FADE	_sE_sub09_hover_icon1_draw
		MSG_M
		MSG		_scE_msg00
		MSG		_scD_E_13_msg91
		MSG_EOL

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sE_sub09_hover_icon1_draw:
		JSR		_apu_reset
		JSR		_snd_hover_crushA
		SW_FADE	_sE_sub0C_hover_icon0_draw
		ICON1	$26,$23,$3D

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sE_sub0C_hover_icon0_draw:
		SW_NXT	_sE_sub0D_hover_icon0_msg
		ICON0	$26,$23,$3E

;-------------S-U-B-R-O-U-T-I-N-E---------------
_sE_sub0D_hover_icon0_msg:
		JSR		_snd_hover_crushB
		SW_FADE	_next_scene
		MSG_M
		MSG		_scE_msg02
		MSG		_scE_msg03
		MSG		_scE_msg04
		MSG_WAIT
		MSG_EOL

		SECTION_END E
