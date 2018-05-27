;-------------C-O-N-S-T-A-N-T-S-----------------

EN_LANG			EQU		0
JP_LANG			EQU		1
RU_LANG			EQU		2

LANGUAGE		EQU		RU_LANG

FAR_SUB_START	EQU		$8001

STARTING_SCENE	EQU		$00

;-----------------F-O-N-T-S---------------------

#if LANGUAGE == JP_LANG
;-----------------------------------------------
		INCLUDE "..\msg_jp\jp_charset.inc"
;-----------------------------------------------
#endif
#if LANGUAGE == EN_LANG
;-----------------------------------------------
		INCLUDE "..\msg_en\en_charset.inc"
;-----------------------------------------------
#endif
#if LANGUAGE == RU_LANG
;-----------------------------------------------
		INCLUDE "..\msg_ru\ru_charset.inc"
;-----------------------------------------------
#endif

;---------------M-A-C-R-O-S-E-S-----------------

	MAC BANK_START
CUR_PRG_BANK	SET {1}
#if . == $8000
	.BYTE	{1}
#endif
CUR_BANK_START	SET .
	ECHO	"bank",{1},"start ["
	ENDM

	MAC	BANK_END
_bank{1}_free	SET	[{2}-.-1]
	#if ${1}==$0
_total_free	SET	_bank{1}_free
	#else
_total_free SET _total_free+_bank{1}_free
	#endif
	#if .>={2}
	ECHO	"]","exceeded by=",[1-_bank{1}_free]
	#else
	ECHO	"]","free =",_bank{1}_free
	#endif
	#if [${1} & $F0]!=$60]
	ORG		{2}-1
	.BYTE	$FF
	#endif
	ENDM

	MAC SECTION_START
_{1}_start	SET	.
	ENDM

	MAC SECTION_END
_{1}_end	SET .
	ECHO	" > section",${1},"size =",_{1}_end-_{1}_start
	ENDM

	MAC	LAST_BANK_END
_bank{1}_free	SET	[{2}-.-6]
_total_free SET _total_free+_bank{1}_free
	ECHO	"]","free =",_bank{1}_free
	ECHO	"-------------";
	ECHO	"total free =",_total_free
	ECHO	""
	ORG {2}-6
	.WORD _NMI
	.WORD _RESET
	.WORD _IRQ
	ENDM

	; simple pair of macroses, used for exporting the routine
	; from the external banks and unconditionally call it
	; use it when there are no options (always far)
	;
	MAC PTR_IDX
{1}_pidx	SET	[[. - CUR_BANK_START] >> 1]
{1}_bank	SET CUR_PRG_BANK
		.WORD	{1}
	ENDM

	; conditional set of macroses, first mark the routine
	; as external by setting its bank number, then check if any
	; far routine assigned, which is occurs on the second pass
	; when far routine detects that caller and its destination
	; are in different banks. if there is no _far* calls, then
	; we don't need this entry at all, discard.
	;
	MAC EXPORT
{1}_bank	SET CUR_PRG_BANK
	#ifconst _far{1}
{1}_pidx	SET	[[. - CUR_BANK_START] >> 1]
		.WORD	{1}
	#endif
	ENDM

	; ok, when we need an OFS for external routine,
	; we either need a direct link without a farcall
	; or link to the farcall code
	;
	MAC	EXOFS
{1}_sidx	SET	[[. - _SW_START] >> 1]
	#if	{1}_bank == CUR_PRG_BANK
{1}_ofs	SET	.
	.WORD {1}
	#else
	.WORD _far{1}
	#endif
	ENDM

	; when used in system bank, will always generate a far call
	; when used in external banks, may be used in direct jumps
	; which is selected based on the bank number of the destination
	;
	; may be used if caller uses a farcall only once in a
	; particular place
	;
	; if there is a direct not far call used for this farcall
	; we abandon JMP generating at all, so we automatically clear
	; unused code.
	;
	; there is an possible case, when you may use it as OFS and direct
	; jump at the same time, so you need to be aware, bacause in
	; local mode this may cause of disappearance of needed JMPs,
	; so maybe you need to use FJSR here or make the code manually
	;
	MAC	FJMP
	#if	{1}_bank == CUR_PRG_BANK
		#ifnconst {1}_ofs
		JMP		{1}
		#endif
	#else
_far{1}	SET .
		LDX		#{1}_bank
		LDY		#{1}_pidx
		JMP		_far_call
	#endif
	ENDM

	; used only in system banks once per call, _far* link actually
	; not needed, but kept here for compatibility with EXPORT
	; macros
	;
	MAC	FJSR
_far{1}	SET .
		LDX		#{1}_bank
		LDY		#{1}_pidx
		JSR		_far_call
	ENDM

	; sometimes we need to jump to already defined farcall in system bank
	; as a direct unconditional jump (when we know, this farcall used
	; more than once in different scenes)
	;
	MAC	EXJMP
		.BYTE	$4C		; JMP opcode
		EXOFS	{1}
	ENDM

	; used only in system bank to call manu draw handlers directly
	;
	MAC	EXJSR
		.BYTE	$20		; JSR opcode
		EXOFS	{1}
	ENDM

	; start of scene msg ptr table
	;
	MAC MSG_START
_MSG_START_OFS	SET	.
{1}		SET		.
	ENDM

	; enumerator for every ptr entryb in msg ptr table
	;
	MAC	MSG_IDX
{1}_midx	SET	[[. - _MSG_START_OFS] >> 1]
		.WORD	{1}
	ENDM

	; special enumerator for common msg library (scene 17)
	MAC	MSG_IDX_SP
{1}_midx	SET	[[[. - _MSG_START_OFS] >> 1]+$70]
		.WORD	{1}
	ENDM

	; single msg in code, no wait, auto _midx, _eol generate
	;
	MAC	MSG_1
		JSR		_msg_single_load_param
		.BYTE	{1}_midx
	ENDM

	; generic messages chain, auto pause between two messages
	; last message goes withut pause if _eof found
	;
	MAC	MSG_M
		JSR		_msg_list_load_param
	ENDM

	; msg list generic entry, _midx auto set
	MAC	MSG
		.BYTE	{1}_midx
	ENDM

	; msg list dummy placeholder to wait for the last message too
	MAC	MSG_WAIT
		.BYTE	_wait
	ENDM

	; _eol of message chain, should be set manually here, sorry
	;
	MAC	MSG_EOL
		.BYTE	_eol
	ENDM

_wait	EQU	$FE

	MAC SWITCH
		JSR		_switch
_SW_START	SET	.
	ENDM

	MAC	SW_PTR
{1}_sidx	SET	[[. - _SW_START] >> 1]
		.WORD	{1}
	ENDM

	MAC	SW_CUR
		LDA		#{1}_sidx
		STA		_scene_sub_cur
	ENDM

	MAC SW_NXT
		LDA		#{1}_sidx
		STA		_scene_sub_next
	ENDM

	MAC SW_RLD
		LDA		#{1}_sidx
		STA		_scene_sub_reload
	ENDM

	MAC SW_RET
		LDA		#{1}_sidx
		STA		_scene_sub_return
	ENDM

	MAC	SW_FADE
		LDA		#_fade_out_reload_scene_sidx
		STA		_scene_sub_next
		LDA		#{1}_sidx
		STA		_scene_sub_reload
	ENDM

	MAC	WARP
		LDA		#{1}
		LDX		#{2}_sidx
		JMP		_new_scene_ex
	ENDM

	MAC	CHRPAL
		LDX		#{1}
		LDY		#{2}
		JSR		_chr_pal_setup
	ENDM

	MAC	PARAM3
		LDX		#{1}
		LDY		#{2}
		LDA		#{3}
		JMP		{4}
	ENDM


	MAC	ICON0
		LDX		#{1}
		LDY		#{2}
		LDA		#{3}
		JMP		_icon0_draw
	ENDM

	MAC	ICON0EX
		LDA		#0
		LDX		#{1}
		JMP		_icon_draw
	ENDM

	MAC	ICON1
		LDX		#{1}
		LDY		#{2}
		LDA		#{3}
		JMP		_icon1_draw
	ENDM

	MAC	ICON1EX
		LDA		#1
		LDX		#{1}
		JMP		_icon_draw
	ENDM

	MAC	ICON1_CLEAR
		LDA		#1
		LDX		#$FF
		JMP		_icon_draw
	ENDM

	MAC	ICON2
		LDX		#{1}
		LDY		#{2}
		LDA		#{3}
		JMP		_icon2_draw
	ENDM

	MAC	ICON2EX
		LDA		#2
		LDX		#{1}
		JMP		_icon_draw
	ENDM

	MAC	TLM4
		LDX		#{1}
		LDY		#{2}
		LDA		#{3}
		JMP		_tlm_nt0_draw_mode4_chrpal_load
	ENDM

	MAC	TLM5
		LDX		#{1}
		LDY		#{2}
		LDA		#{3}
		JMP		_tlm_draw_mode5_chrpal_load
	ENDM

	MAC	TLM6
		LDX		#{1}
		LDY		#{2}
		LDA		#{3}
		JMP		_tlm_draw_mode6_chrpal_load
	ENDM

	MAC SPR0
		JSR		_spr_load0_param
		.WORD	{1}
		.BYTE	{2},{3}
	ENDM

	MAC SPR0J
		SPR0	{0}
		RTS
	ENDM

	MAC SPR0EX
		JSR		_spr_load0_param_ex
		.WORD	{1}
	ENDM

	MAC SPR1
		JSR		_spr_load1_param
		.WORD	{1}
	ENDM

	MAC SPRR
		JSR		_spr_load_raw_param
		.WORD	{1}
	ENDM

	MAC SPR0SW
		JSR		_spr_load0_param_sw
		.WORD	{1}
		.BYTE	{2},{3}
	ENDM

	MAC SPR0JSW
		SPR0SW	{0}
		RTS
	ENDM

	MAC SPR0SWEX
		JSR		_spr_load0_param_sw_ex
		.WORD	{1}
	ENDM

	MAC SPR1SW
		JSR		_spr_load1_param_sw_ex
		.WORD	{1}
	ENDM

	MAC SPRRSW
		JSR		_spr_load_raw_param_sw
		.WORD	{1}
	ENDM

	MAC	APU_L
{1}		SET	.
		JSR		_far_apu_load_param
	ENDM

	MAC	MITEM
#if LANGUAGE == JP_LANG
	.WORD	_m{2},_m_{1}
#else
	.WORD	_m_{1},_m{2}
#endif
	ENDM

