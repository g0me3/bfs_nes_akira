
		PROCESSOR 6502
		ORG	$0000

		INCLUDE	 "..\macroses.inc"

#if LANGUAGE == JP_LANG
;-----------------------------------------------
		INCBIN "..\chr\jp_akira0.chr"
		INCLUDE "..\tlm\tlm.inc"
		INCBIN "..\chr\jp_akira1.chr"
;-----------------------------------------------
#endif
#if LANGUAGE == EN_LANG
;-----------------------------------------------
		INCBIN "..\chr\en_akira0.chr"
		INCLUDE "..\tlm\tlm.inc"
		INCBIN "..\chr\en_akira1.chr"
;-----------------------------------------------
#endif
#if LANGUAGE == RU_LANG
;-----------------------------------------------
		INCBIN "..\chr\ru_akira0.chr"
		INCLUDE "..\tlm\tlm.inc"
		INCBIN "..\chr\ru_akira1.chr"
;-----------------------------------------------
#endif

		INCBIN