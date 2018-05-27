
		ORG	$A000

		BANK_START $3B

#if LANGUAGE == JP_LANG
;-----------------------------------------------
		PTR_IDX _scene15_msg_lib
		PTR_IDX _scene16_msg_lib
		PTR_IDX _scene17_msg_lib

		INCLUDE "..\msg_jp\jp_sc15_msg.inc"
		INCLUDE "..\msg_jp\jp_sc16_msg.inc"
		INCLUDE "..\msg_jp\jp_sc17_msg.inc"
;-----------------------------------------------
#endif
#if LANGUAGE == EN_LANG
;-----------------------------------------------
		PTR_IDX _scene9_msg_lib
		PTR_IDX _scene15_msg_lib
		PTR_IDX _scene16_msg_lib
		PTR_IDX _scene17_msg_lib

		INCLUDE "..\msg_en\en_sc9_msg.inc"
		INCLUDE "..\msg_en\en_sc15_msg.inc"
		INCLUDE "..\msg_en\en_sc16_msg.inc"
		INCLUDE "..\msg_en\en_sc17_msg.inc"
;-----------------------------------------------
#endif
#if LANGUAGE == RU_LANG
;-----------------------------------------------
		PTR_IDX _scene15_msg_lib
		PTR_IDX _scene16_msg_lib
		PTR_IDX _scene17_msg_lib

		INCLUDE "..\msg_ru\ru_sc15_msg.inc"
		INCLUDE "..\msg_ru\ru_sc16_msg.inc"
		INCLUDE "..\msg_ru\ru_sc17_msg.inc"
;-----------------------------------------------
#endif

		BANK_END B,$C000
