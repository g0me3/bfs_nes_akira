
		ORG $8000

		BANK_START $32

		EXPORT _scene8_subs
		EXPORT _scene9_subs
			EXPORT	_s9_spr_overlay3
		EXPORT _sceneA_subs

		EXPORT _draw_handlers
		EXPORT _menu_draw						; one of drawing extarnals

		INCLUDE "..\scene8.inc"
		INCLUDE "..\scene9.inc"
		INCLUDE "..\sceneA.inc"
		INCLUDE "..\draw_engine.inc"

		BANK_END 2,$A000
