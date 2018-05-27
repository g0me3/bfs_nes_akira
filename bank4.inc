
		ORG $8000

		BANK_START $34

		EXPORT _scene10_subs

		EXPORT _scene12_subs
			EXPORT _s12_spr_overlay1
			EXPORT _s12_spr_overlay4
			EXPORT _s12_tlmA0_draw

		EXPORT _scene13_subs
			EXPORT _s13_tlm63_draw
			EXPORT _s11_spr_overlay5			; for scene 11

		EXPORT _intro_handlers

		INCLUDE "..\scene10.inc"
		INCLUDE "..\scene12.inc"				; external: _sF_icon46_draw
												;			_sF_spr_overlay7
		INCLUDE "..\scene13.inc"				; external:	_sF_icon46_draw
												;			_sF_spr_overlay7
												;			_sF_spr_overlay8
												;			_sF_tlm9C_draw
												;			_s12_spr_overlay4
												;			_s12_tlmA0_draw
		INCLUDE "..\intro.inc"

		BANK_END 4,$A000
