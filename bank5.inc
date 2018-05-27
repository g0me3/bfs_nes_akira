
		ORG $8000

		BANK_START $35

		EXPORT _scene14_subs

		EXPORT _scene15_subs
			EXPORT _s15_spr_overlay6
			EXPORT _s15_tlm72_draw
			EXPORT _s15_tlm7A_draw
			EXPORT _s15_tlm9F_draw
;			EXPORT _s15_icon7D_draw				; unused anymore
			EXPORT _s15_spr_overlay5
			EXPORT _s15_tlm76_draw
			EXPORT _s15_tlm9E_draw

		EXPORT _scene16_subs
			EXPORT _s16_tlm85_draw
			EXPORT _s16_tlm93_draw
			EXPORT _s16_spr_overlayA

		INCLUDE "..\scene14.inc"				; external: _s12_spr_overlay1
		INCLUDE "..\scene15.inc"
		INCLUDE "..\scene16.inc"				; external: _s13_tlm63_draw
												;								;_s15_icon7D_draw
												;			_s15_spr_overlay5
												;			_s15_tlm76_draw
												;			_s15_tlm7A_draw
												;			_s15_tlm9E_draw
												;			_sF_spr_overlay8
												;			_sF_tlm9C_draw

		BANK_END 5,$A000
