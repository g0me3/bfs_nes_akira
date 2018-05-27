
		ORG $8000

		ECHO "PROGRAM BEGIN"
		ECHO "-------------"

		BANK_START $30

		EXPORT _scene0_subs
			EXPORT	_s0_spr_overlay2
			EXPORT	_s0_tlm00_draw
			EXPORT	_s0_tlm01_draw
		EXPORT _scene1_subs
		EXPORT _scene2_subs
		EXPORT _scene3_subs
		EXPORT _scene4_subs
		EXPORT _sceneE_subs
		EXPORT _scene18_subs_ending

		INCLUDE "..\scene0.inc"					; external: none
		INCLUDE "..\scene1.inc"					; external: none
		INCLUDE "..\scene2.inc"					; external: none
		INCLUDE "..\scene3.inc"					; external: none
		INCLUDE "..\scene4.inc"					; external: none
		INCLUDE "..\sceneE.inc"					; external: none
		INCLUDE "..\scene18.inc"				; external: _s0_spr_overlay2
												;			_s0_tlm00_draw
												;			_s0_tlm01_draw
												;			_s5_spr_overlay1
												;			_s5_tlm1E_draw
												;			_s6_spr_overlay4
												;			_s6_tlmA1_draw
												;			_s7_tlm25_draw
												;			_sC_spr_overlay2
												;			_sC_tlm35_draw
												;			_sF_spr_overlay5
												;			_sF_tlm45_draw
												;			_s11_tlm4E_draw
												;			_s15_spr_overlay6
												;			_s15_tlm72_draw
												;			_s15_tlm7A_draw
												;			_s15_tlm9F_draw
												;			_s16_spr_overlayA
												;			_s16_tlm85_draw
												;			_s16_tlm93_draw


		BANK_END 0,$A000
