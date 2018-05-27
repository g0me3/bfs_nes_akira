
		ORG	$A000

		BANK_START $38

#if LANGUAGE == JP_LANG
;-----------------------------------------------
		PTR_IDX _scene0_msg_lib					; common lib for intro and scene 1
		PTR_IDX _scene1_msg_lib
		PTR_IDX _scene2_msg_lib
		PTR_IDX _scene3_msg_lib
		PTR_IDX _scene4_msg_lib
		PTR_IDX _scene5_msg_lib
		PTR_IDX _scene6_msg_lib

		INCLUDE "..\msg_jp\jp_sc0_msg.inc"
		INCLUDE "..\msg_jp\jp_sc1_msg.inc"
		INCLUDE "..\msg_jp\jp_sc2_msg.inc"
		INCLUDE "..\msg_jp\jp_sc3_msg.inc"
		INCLUDE "..\msg_jp\jp_sc4_msg.inc"
		INCLUDE "..\msg_jp\jp_sc5_msg.inc"
		INCLUDE "..\msg_jp\jp_sc6_msg.inc"
;-----------------------------------------------
#endif
#if LANGUAGE == EN_LANG
;-----------------------------------------------
		PTR_IDX _scene0_msg_lib
		PTR_IDX _scene1_msg_lib
		PTR_IDX _scene2_msg_lib
		PTR_IDX _scene4_msg_lib
		PTR_IDX _scene5_msg_lib
		PTR_IDX _scene6_msg_lib
		PTR_IDX _sceneE_msg_lib

		INCLUDE "..\msg_en\en_sc0_msg.inc"
		INCLUDE "..\msg_en\en_sc1_msg.inc"
		INCLUDE "..\msg_en\en_sc2_msg.inc"
		INCLUDE "..\msg_en\en_sc4_msg.inc"
		INCLUDE "..\msg_en\en_sc5_msg.inc"
		INCLUDE "..\msg_en\en_sc6_msg.inc"
		INCLUDE "..\msg_en\en_scE_msg.inc"
;-----------------------------------------------
#endif
#if LANGUAGE == RU_LANG
;-----------------------------------------------
		PTR_IDX _scene2_msg_lib
		PTR_IDX _scene3_msg_lib
		PTR_IDX _scene4_msg_lib
		PTR_IDX _scene5_msg_lib
		PTR_IDX _scene6_msg_lib

		INCLUDE "..\msg_ru\ru_sc2_msg.inc"
		INCLUDE "..\msg_ru\ru_sc3_msg.inc"
		INCLUDE "..\msg_ru\ru_sc4_msg.inc"
		INCLUDE "..\msg_ru\ru_sc5_msg.inc"
		INCLUDE "..\msg_ru\ru_sc6_msg.inc"
;-----------------------------------------------
#endif

		BANK_END 8,$C000
