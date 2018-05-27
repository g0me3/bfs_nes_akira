
		.WORD 0									; dummy, idx = 0 is off flag
		.WORD _dictD9
		.WORD _dictDA							; -unused-
		.WORD _dictDB
		.WORD _dictDC
		.WORD _dictDD
		.WORD _dictDE
		.WORD _dictDF
		.WORD _dictF9							; +8 index
		.WORD _dictFA
		.WORD _format_buf						; FB cmd

_dictD9:		.BYTE ___
_dictDA:		.BYTE ___
_dictDB:		.BYTE ___
_dictDC:		.BYTE ___
_dictDD:		.BYTE ___
_dictDE:		.BYTE ___
_dictDF:		.BYTE ___,___,$FF
_dictF9:		.BYTE _ka,_ne,_da,$FF
_dictFA:		.BYTE _TE,_TU,_O_,$FF
