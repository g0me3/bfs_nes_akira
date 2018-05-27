
		ORG $8000

		BANK_START $33

		EXPORT _sceneB_subs

		EXPORT _sceneC_subs
			EXPORT _sC_tlm35_draw
			EXPORT _sC_spr_overlay2

		EXPORT _sceneD_subs

		EXPORT _sceneF_subs
			EXPORT _sF_tlm9C_draw
			EXPORT _sF_spr_overlay8
			EXPORT _sF_icon46_draw
			EXPORT _sF_spr_overlay7
			EXPORT _sF_tlm45_draw
			EXPORT _sF_spr_overlay5

		EXPORT _scene11_subs
			EXPORT _s11_tlm4E_draw

		INCLUDE "..\sceneB.inc"					; external: _s9_spr_overlay3
		INCLUDE "..\sceneC.inc"
		INCLUDE "..\sceneD.inc"					; external: _sF_spr_overlay8
												;			_sF_tlm9C_draw
		INCLUDE "..\sceneF.inc"
		INCLUDE "..\scene11.inc"				; external: _s6_spr_overlay4
												;			_s6_tlm88_draw
												;			_s6_tlmA1_draw
												;			_sF_spr_overlay8
												;			_sF_tlm9C_draw
												;			_s17_spr_overlay1_A
												;			_s11_spr_overlay5		; in scene 13

		BANK_END 3,$A000
