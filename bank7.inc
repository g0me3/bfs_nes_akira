
#if LANGUAGE == RU_LANG
;-----------------------------------------------
		ORG $A000

		BANK_START $37

		PTR_IDX _scene0_msg_lib
		PTR_IDX _scene1_msg_lib
		PTR_IDX _sceneD_msg_lib
		PTR_IDX _scene14_msg_lib

		INCLUDE "..\msg_ru\ru_sc0_msg.inc"
		INCLUDE "..\msg_ru\ru_sc1_msg.inc"
		INCLUDE "..\msg_ru\ru_scD_msg.inc"
		INCLUDE "..\msg_ru\ru_sc14_msg.inc"

		BANK_END 7,$C000
;-----------------------------------------------
#else
;-----------------------------------------------
		ORG $8000

		BANK_START $37

		BANK_END 7,$A000
;-----------------------------------------------
#endif

