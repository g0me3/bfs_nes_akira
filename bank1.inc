
		ORG $8000

		BANK_START $31

		EXPORT _scene5_subs
			EXPORT _s5_spr_overlay1
;			EXPORT _s5_spr_overlay2				; may remove it here
			EXPORT _s5_spr_overlay3
			EXPORT _s5_spr_overlay4
			EXPORT _s5_spr_overlay5
			EXPORT _s5_tlm1A_draw
			EXPORT _s5_tlm1B_draw
			EXPORT _s5_tlm1C_draw
			EXPORT _s5_tlm1D_draw
			EXPORT _s5_tlm1E_draw

		EXPORT _scene6_subs
			EXPORT _s6_tlmA1_draw
			EXPORT _s6_spr_overlay4
			EXPORT _s6_tlm88_draw

		EXPORT _scene7_subs
			EXPORT _s7_tlm25_draw

		EXPORT _scene17_subs_game_over
			EXPORT _s17_spr_overlay1_A			; shared overlay

		INCLUDE "..\scene5.inc"					; external: none
		INCLUDE "..\scene6.inc"					; external: _s15_tlm7A_draw
												;			_s17_spr_overlay1_A
		INCLUDE "..\scene7.inc"					; external: [_s5_spr_overlay2] unused actually
												;			_s5_spr_overlay3
												;			_s5_spr_overlay4
												;			_s5_spr_overlay5
												;			_s5_tlm1A_draw
												;			_s5_tlm1B_draw
												;			_s5_tlm1C_draw
												;			_s5_tlm1D_draw
		INCLUDE "..\scene17.inc"

		BANK_END 1,$A000
