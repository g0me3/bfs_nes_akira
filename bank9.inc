
		ORG	$A000

		BANK_START $39

#if LANGUAGE == JP_LANG
;-----------------------------------------------
		PTR_IDX _scene7_msg_lib
		PTR_IDX _scene8_msg_lib
		PTR_IDX _scene9_msg_lib
		PTR_IDX _sceneA_msg_lib
		PTR_IDX _sceneB_msg_lib
		PTR_IDX _sceneC_msg_lib
		PTR_IDX _sceneD_msg_lib
		PTR_IDX _sceneE_msg_lib
		PTR_IDX _sceneF_msg_lib

		INCLUDE "..\msg_jp\jp_sc7_msg.inc"
		INCLUDE "..\msg_jp\jp_sc8_msg.inc"
		INCLUDE "..\msg_jp\jp_sc9_msg.inc"
		INCLUDE "..\msg_jp\jp_scA_msg.inc"
		INCLUDE "..\msg_jp\jp_scB_msg.inc"
		INCLUDE "..\msg_jp\jp_scC_msg.inc"
		INCLUDE "..\msg_jp\jp_scD_msg.inc"
		INCLUDE "..\msg_jp\jp_scE_msg.inc"
		INCLUDE "..\msg_jp\jp_scF_msg.inc"
;-----------------------------------------------
#endif
#if LANGUAGE == EN_LANG
;-----------------------------------------------
		PTR_IDX _scene7_msg_lib
		PTR_IDX _scene8_msg_lib
		PTR_IDX _sceneA_msg_lib
		PTR_IDX _sceneB_msg_lib
		PTR_IDX _sceneC_msg_lib
		PTR_IDX _sceneD_msg_lib
		PTR_IDX _sceneF_msg_lib
		PTR_IDX _scene14_msg_lib

		INCLUDE "..\msg_en\en_sc7_msg.inc"
		INCLUDE "..\msg_en\en_sc8_msg.inc"
		INCLUDE "..\msg_en\en_scA_msg.inc"
		INCLUDE "..\msg_en\en_scB_msg.inc"
		INCLUDE "..\msg_en\en_scC_msg.inc"
		INCLUDE "..\msg_en\en_scD_msg.inc"
		INCLUDE "..\msg_en\en_scF_msg.inc"
		INCLUDE "..\msg_en\en_sc14_msg.inc"
;-----------------------------------------------
#endif
#if LANGUAGE == RU_LANG
;-----------------------------------------------
		PTR_IDX _scene7_msg_lib
		PTR_IDX _scene8_msg_lib
		PTR_IDX _scene9_msg_lib
		PTR_IDX _sceneA_msg_lib
		PTR_IDX _sceneB_msg_lib
		PTR_IDX _sceneC_msg_lib
;		PTR_IDX _sceneD_msg_lib
		PTR_IDX _sceneE_msg_lib
		PTR_IDX _sceneF_msg_lib

		INCLUDE "..\msg_ru\ru_sc7_msg.inc"
		INCLUDE "..\msg_ru\ru_sc8_msg.inc"
		INCLUDE "..\msg_ru\ru_sc9_msg.inc"
		INCLUDE "..\msg_ru\ru_scA_msg.inc"
		INCLUDE "..\msg_ru\ru_scB_msg.inc"
		INCLUDE "..\msg_ru\ru_scC_msg.inc"
;		INCLUDE "..\msg_ru\ru_scD_msg.inc"
		INCLUDE "..\msg_ru\ru_scE_msg.inc"
		INCLUDE "..\msg_ru\ru_scF_msg.inc"
;-----------------------------------------------
#endif

		BANK_END 9,$C000
