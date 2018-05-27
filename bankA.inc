
		ORG	$A000

		BANK_START $3A

#if LANGUAGE == JP_LANG
;-----------------------------------------------
		PTR_IDX _scene10_msg_lib
		PTR_IDX _scene11_msg_lib
		PTR_IDX _scene12_msg_lib
		PTR_IDX _scene13_msg_lib
		PTR_IDX _scene14_msg_lib

		INCLUDE "..\msg_jp\jp_sc10_msg.inc"
		INCLUDE "..\msg_jp\jp_sc11_msg.inc"
		INCLUDE "..\msg_jp\jp_sc12_msg.inc"
		INCLUDE "..\msg_jp\jp_sc13_msg.inc"
		INCLUDE "..\msg_jp\jp_sc14_msg.inc"
;-----------------------------------------------
#endif
#if LANGUAGE == EN_LANG
;-----------------------------------------------
		PTR_IDX _scene3_msg_lib
		PTR_IDX _scene10_msg_lib
		PTR_IDX _scene11_msg_lib
		PTR_IDX _scene12_msg_lib
		PTR_IDX _scene13_msg_lib

		INCLUDE "..\msg_en\en_sc3_msg.inc"
		INCLUDE "..\msg_en\en_sc10_msg.inc"
		INCLUDE "..\msg_en\en_sc11_msg.inc"
		INCLUDE "..\msg_en\en_sc12_msg.inc"
		INCLUDE "..\msg_en\en_sc13_msg.inc"
;-----------------------------------------------
#endif
#if LANGUAGE == RU_LANG
;-----------------------------------------------
		PTR_IDX _scene10_msg_lib
		PTR_IDX _scene11_msg_lib
		PTR_IDX _scene12_msg_lib
		PTR_IDX _scene13_msg_lib
;		PTR_IDX _scene14_msg_lib

		INCLUDE "..\msg_ru\ru_sc10_msg.inc"
		INCLUDE "..\msg_ru\ru_sc11_msg.inc"
		INCLUDE "..\msg_ru\ru_sc12_msg.inc"
		INCLUDE "..\msg_ru\ru_sc13_msg.inc"
;		INCLUDE "..\msg_ru\ru_sc14_msg.inc"
;-----------------------------------------------
#endif

		BANK_END A,$C000
