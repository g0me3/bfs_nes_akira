
		.WORD 0	;	_scene1_menus						; 0 dummy
		.WORD _scene1_menus
		.WORD _scene2_menus
		.WORD 0	;	_scene5_menus						; 3 dummy
		.WORD 0	;	_scene5_menus						; 4 dummy
		.WORD _scene5_menus
		.WORD _scene6_menus
		.WORD _scene7_menus
		.WORD _scene8_menus
		.WORD _scene9_menus
		.WORD _sceneA_menus
		.WORD _sceneB_menus
		.WORD _sceneC_menus
		.WORD 0	;	_sceneF_menus						; D dummy
		.WORD 0	;	_sceneF_menus						; E dummy
		.WORD _sceneF_menus
		.WORD _scene10_menus
		.WORD _scene11_menus
		.WORD _scene12_menus
		.WORD _scene13_menus
		.WORD _scene14_menus
		.WORD _scene15_menus
_scene1_menus:
		.WORD _sc1_menu0
		.WORD _sc1_menu1
		.WORD _sc1_menu2
_scene2_menus:
		.WORD _sc2_menu0
		.WORD _sc2_menu1
		.WORD _sc2_menu2
		.WORD _sc2_menu3
		.WORD _sc2_menu4
		.WORD _sc2_menu5
_scene5_menus:
		.WORD _sc5_menu0
		.WORD _sc5_menu1
		.WORD _sc5_menu2
_scene6_menus:
		.WORD _sc6_menu01
		.WORD _sc6_menu01
		.WORD _sc6_menu2
		.WORD _sc6_menu37
		.WORD _sc6_menu4
		.WORD _sc6_menu5
		.WORD _sc6_menu6
		.WORD _sc6_menu37
_scene7_menus:
		.WORD _sc7_menu0
		.WORD _sc7_menu1
		.WORD _sc7_menu2
		.WORD _sc7_menu3
		.WORD _sc7_menu4
		.WORD _sc5_menu2
_scene8_menus:
		.WORD _sc8_menu0
		.WORD _sc8_menu1
		.WORD _sc8_menu2
		.WORD _sc8_menu3
_scene9_menus:
		.WORD _sc9_menu0
		.WORD _sc9_menu1
		.WORD _sc9_menu2
_sceneA_menus:
		.WORD _scA_menu0
		.WORD _scA_menu1
		.WORD _scA_menu2
		.WORD _scA_menu3
		.WORD _scA_menu4
		.WORD _scA_menu56
		.WORD _scA_menu56
_sceneB_menus:
		.WORD _scB_menu0
		.WORD _scB_menu1
		.WORD _scB_menu2
		.WORD _scB_menu3
		.WORD _scB_menu45
		.WORD _scB_menu45
_sceneC_menus:
		.WORD _scC_menu0
		.WORD _scC_menu1
		.WORD _scC_menu2
		.WORD _scC_menu3
_sceneF_menus:
		.WORD _scF_menu0
		.WORD _scF_menu1
		.WORD _scF_menu2
_scene10_menus:
		.WORD _sc10_menu0
		.WORD _sc10_menu1
		.WORD _sc10_menu2
_scene11_menus:
		.WORD _sc11_menu01
		.WORD _sc11_menu01
		.WORD _sc11_menu2
		.WORD _sc11_menu3
_scene12_menus:
		.WORD _sc12_menu02
		.WORD _sc12_menu1
		.WORD _sc12_menu02
		.WORD _sc12_menu3
		.WORD _sc12_menu4
		.WORD _sc12_menu5
_scene13_menus:
		.WORD _sc13_menu01
		.WORD _sc13_menu01
		.WORD _sc13_menu2
		.WORD _sc13_menu3
_scene14_menus:
		.WORD _sc14_menu0
		.WORD _sc14_menu14
		.WORD _sc14_menu23
		.WORD _sc14_menu23
		.WORD _sc14_menu14
_scene15_menus:
		.WORD _sc15_menu0
		.WORD _sc15_menu1
		.WORD _sc15_menu2
		.WORD _sc15_menu3
		.WORD _sc15_menu4

_sc1_menu0:
		MITEM	talk   ,_
		MITEM	look   ,_
		MITEM	peek   ,_
		MITEM	inquire,_
		MITEM	laugh  ,_
_sc1_menu1:
		MITEM	gang   ,_
		MITEM	pick   ,_
;		MITEM	army   ,_					; -unused-
;		MITEM	kaneda ,_					; -unused-
;		MITEM	license,_					; -unused-
;		MITEM	list   ,_					; -unused-
_sc1_menu2:
		MITEM	army   ,_
		MITEM	desk   ,_
		MITEM	list   ,_
_sc2_menu0:
		MITEM	inquire,_
		MITEM	check  ,_
		MITEM	ask_out,_
_sc2_menu1:
		MITEM	nearby ,_
		MITEM	pick   ,_
_sc2_menu2:
		MITEM	yell   ,_
		MITEM	panic  ,_
		MITEM	jump   ,_
_sc2_menu3:
		MITEM	run    ,_
		MITEM	tackle ,_					; regular "jump on" in japan version
		MITEM	take   ,___cover			; regular "hide" in japan version
		MITEM	stare  ,_
		MITEM	pray   ,_
_sc2_menu4:
		MITEM	nearby ,_
		MITEM	girl   ,_
		MITEM	army   ,_
_sc2_menu5:
		MITEM	go_back,_
		MITEM	look   ,_
		MITEM	talk   ,_
_sc5_menu0:
		MITEM	move   ,_
		MITEM	inquire,_
		MITEM	peek   ,_
		MITEM	tease  ,_
		MITEM	drink  ,_
_sc5_menu1:
		MITEM	yell   ,_
		MITEM	search ,_
		MITEM	show   ,_
		MITEM	inquire,_
		MITEM	move   ,_
_sc5_menu2:
		MITEM	hangout,_
		MITEM	1      ,_
		MITEM	2      ,_
		MITEM	3      ,_
		MITEM	4      ,_
_sc6_menu01:
		MITEM	run    ,_
		MITEM	jump_on,_
		MITEM	hit    ,_
		MITEM	crouch ,_
_sc6_menu2:
		MITEM	run    ,_
		MITEM	ponder ,_
		MITEM	look   ,_
		MITEM	panic  ,_
		MITEM	run_to ,_
_sc6_menu37:
		MITEM	car    ,_
		MITEM	crc    ,_
		MITEM	tetsuo ,_
_sc6_menu4:
		MITEM	inquire,_
		MITEM	ponder ,_
		MITEM	take   ,_
		MITEM	look   ,_
		MITEM	run_to ,_
_sc6_menu5:
		MITEM	open   ,_
		MITEM	inquire,_
		MITEM	flatter,_
		MITEM	hit    ,_
		MITEM	yell   ,_
		MITEM	look   ,_
_sc6_menu6:
		MITEM	yell   ,_
		MITEM	hit    ,_
		MITEM	run_to ,_
_sc7_menu0:
		MITEM	inquire,_
_sc7_menu1:
		MITEM	yamagat,_
		MITEM	kai    ,_
		MITEM	groupie,_
_sc7_menu2:
		MITEM	about  ,__tetsuo
		MITEM	about  ,____army
		MITEM	about  ,_____kid
		MITEM	about  ,___akira
_sc7_menu3:
		MITEM	inquire,_
		MITEM	look   ,_
		MITEM	check  ,_
		MITEM	move   ,_
_sc7_menu4:
		MITEM	gang   ,_
		MITEM	terrori,_
		MITEM	walkway,_
_sc8_menu0:
		MITEM	check  ,_
		MITEM	inquire,_
		MITEM	peek   ,_
_sc8_menu1:
		MITEM	talk   ,_
		MITEM	ask_out,_
		MITEM	make   ,___noise
		MITEM	hide   ,_
		MITEM	sneak  ,_
_sc8_menu2:
		MITEM	talk   ,_
		MITEM	raise  ,___hands
		MITEM	pray   ,_
		MITEM	jump_on,_
		MITEM	dash   ,_
_sc8_menu3:
		MITEM	play   ,____dumb
		MITEM	slide  ,_
		MITEM	flip   ,_
		MITEM	dive   ,_
_sc9_menu0:
		MITEM	talk   ,_
		MITEM	ponder ,_
		MITEM	check  ,_
_sc9_menu1:
		MITEM	explain,_
		MITEM	rely_on,_____kei
_sc9_menu2:
		MITEM	truth  ,_
		MITEM	lie    ,_
		MITEM	tease  ,_					; a different word "joke" in japanese
_scA_menu0:
		MITEM	ponder ,_
		MITEM	check  ,_
		MITEM	open   ,_
_scA_menu1:
		MITEM	about  ,_terrori
		MITEM	about  ,____army
		MITEM	about  ,__tetsuo
		MITEM	about  ,_____kei
_scA_menu2:
		MITEM	door   ,_
		MITEM	beer   ,_
_scA_menu3:
		MITEM	run    ,_
		MITEM	drink  ,_
		MITEM	peek   ,_
_scA_menu4:
		MITEM	check  ,_
		MITEM	go_on  ,_
_scA_menu56:
		MITEM	check  ,_
		MITEM	inquire,_
		MITEM	go_on  ,_
_scB_menu0:
		MITEM	talk   ,_
_scB_menu1:
		MITEM	beg    ,_
		MITEM	ponder ,_
		MITEM	inquire,_
_scB_menu2:
		MITEM	take   ,_
		MITEM	beg    ,_
		MITEM	ponder ,_
		MITEM	inquire,_
_scB_menu3:
		MITEM	lab_id ,_
		MITEM	photo  ,_
_scB_menu45:
		MITEM	about  ,____army
		MITEM	about  ,_____lab
		MITEM	about  ,_terrori
_scC_menu0:
		MITEM	talk   ,_
		MITEM	go_on  ,_
_scC_menu1:
		MITEM	run    ,_
		MITEM	take   ,_
_scC_menu2:
		MITEM	run    ,_
		MITEM	hide   ,_					; a different word "cover" in japanese
		MITEM	dodge  ,_
		MITEM	throw  ,_
_scC_menu3:
		MITEM	run    ,_
		MITEM	hide   ,_
		MITEM	jump_on,_					; also diff word in japanese "jump at" literally
_scF_menu0:
		MITEM	run    ,_
		MITEM	rely_on,_____kei
		MITEM	show   ,_
		MITEM	look   ,_
		MITEM	talk   ,_
_scF_menu1:
		MITEM	pocket ,_
		MITEM	lab_id ,_
_scF_menu2:
		MITEM	masaru ,_
		MITEM	takashi,_
		MITEM	kiyoko ,_
		MITEM	colonel,_
		MITEM	tetsuo ,_
_sc10_menu0:
		MITEM	check  ,_
		MITEM	inquire,_
		MITEM	ponder ,_
		MITEM	call   ,_
_sc10_menu1:
		MITEM	run    ,_
		MITEM	shout  ,_					; oddly, japanese has another word here, but why?
_sc10_menu2:
		MITEM	about  ,____army
		MITEM	about  ,_terrori
		MITEM	about  ,__tetsuo
		MITEM	about  ,___akira
_sc11_menu01:
		MITEM	look   ,_
		MITEM	check  ,_
		MITEM	inquire,_
		MITEM	run_to ,_
		MITEM	ponder ,_
_sc11_menu2:
		MITEM	town   ,_
		MITEM	school ,_
_sc11_menu3:
		MITEM	run_to ,_
		MITEM	look   ,_
		MITEM	check  ,_
		MITEM	inquire,_
		MITEM	ponder ,_
		MITEM	move   ,_
_sc12_menu02:
		MITEM	move   ,_
_sc12_menu1:
		MITEM	school ,_
_sc12_menu3:
		MITEM	town   ,_
		MITEM	stadium,_				; "move" previously, originally "construction [site]"
_sc12_menu4:
		MITEM	inquire,_
		MITEM	check  ,_
		MITEM	go_on  ,_
_sc12_menu5:
		MITEM	check  ,_				; regular "look" in japanese
		MITEM	go_on  ,_
		MITEM	stop   ,_
_sc13_menu01:
		MITEM	dodge  ,_
		MITEM	jump_on,_
		MITEM	use    ,_
_sc13_menu2:
		MITEM	hide   ,_				; regular "cover" here in japanese
		MITEM	turn   ,_
		MITEM	yell   ,_
		MITEM	inquire,_
		MITEM	look   ,_
_sc13_menu3:
		MITEM	yell   ,_
		MITEM	jump   ,_
		MITEM	ask_out,_
		MITEM	look   ,_
_sc14_menu0:
		MITEM	stare  ,_
		MITEM	ponder ,_
		MITEM	inquire,_
		MITEM	peek   ,_
_sc14_menu14:
		MITEM	kei    ,_
		MITEM	kai    ,_
		MITEM	laser  ,_
_sc14_menu23:
		MITEM	about  ,__tetsuo
		MITEM	stadium,_
		MITEM	about  ,____bike
_sc15_menu0:
		MITEM	hit    ,_				; a different world "attack" here in japanese
		MITEM	dash   ,_
		MITEM	pray   ,_
		MITEM	throw  ,_
		MITEM	look   ,_
		MITEM	ponder ,_
_sc15_menu1:
		MITEM	dash   ,_
		MITEM	take   ,_
		MITEM	crouch ,_
		MITEM	yell   ,_
		MITEM	hit    ,_				;... and here
_sc15_menu2:
		MITEM	right  ,_
		MITEM	left   ,_
_sc15_menu3:
		MITEM	look   ,_
		MITEM	attack ,_
_sc15_menu4:
		MITEM	jump   ,_				; eng translators fixed "talk" to "jump"
		MITEM	run    ,_
		MITEM	hit    ,_

_m_:			.BYTE _eol
_m_1:			.BYTE _1,_eol
_m_2:			.BYTE _2,_eol
_m_3:			.BYTE _3,_eol
_m_4:			.BYTE _4,_eol
_m_army:		.BYTE _A,_r,_m,_y,_eol
_m_ask_out:		.BYTE _A,_s,_k,__,_o,_u,_t,_eol
_m_attack:		.BYTE _A,_t,_t,_a,_c,_k,_eol
_m_beer:		.BYTE _B,_e,_e,_r,_eol
_m_beg:			.BYTE _B,_e,_g,_eol
_m_call:		.BYTE _C,_a,_l,_l,_eol
_m_car:			.BYTE _C,_a,_r,_eol
_m_check:		.BYTE _C,_h,_e,_c,_k,_eol
_m_colonel:		.BYTE _C,_o,_l,_o,_n,_e,_l,_eol
_m_crc:			.BYTE _C,_R,_C,_eol
_m_crouch:		.BYTE _C,_r,_o,_u,_c,_h,_eol
_m_dash:		.BYTE _D,_a,_s,_h,_eol
_m_desk:		.BYTE _D,_e,_s,_k,_eol
_m_dive:		.BYTE _D,_i,_v,_e,_eol
_m_dodge:		.BYTE _D,_o,_d,_g,_e,_eol
_m_door:		.BYTE _D,_o,_o,_r,_eol
_m_drink:		.BYTE _D,_r,_i,_n,_k,_eol
_m_explain:		.BYTE _E,_x,_p,_l,_a,_i,_n,_eol
_m_flatter:		.BYTE _F,_l,_a,_t,_t,_e,_r,_eol
_m_flip:		.BYTE _F,_l,_i,_p,_eol
_m_gang:		.BYTE _G,_a,_n,_g,_eol
_m_girl:		.BYTE _G,_i,_r,_l,_eol
_m_go_back:		.BYTE _G,_o,__,_b,_a,_c,_k,_eol
_m_go_on:		.BYTE _G,_o,__,_o,_n,_eol
_m_groupie:		.BYTE _G,_r,_o,_u,_p,_i,_e,_eol
_m_hangout:		.BYTE _H,_a,_n,_g,_o,_u,_t,_eol
_m_hide:		.BYTE _H,_i,_d,_e,_eol
_m_hit:			.BYTE _H,_i,_t,_eol
_m_inquire:		.BYTE _I,_n,_q,_u,_i,_r,_e,_eol
_m_jump:		.BYTE _J,_u,_m,_p,_eol
_m_jump_on:		.BYTE _J,_u,_m,_p,__,_o,_n,_eol
_m_kai:			.BYTE _K,_a,_i,_eol
_m_kei:			.BYTE _K,_e,_i,_eol
_m_kiyoko:		.BYTE _K,_i,_y,_o,_k,_o,_eol
_m_lab:			.BYTE _L,_a,_b,_eol
_m_lab_id:		.BYTE _L,_a,_b,__,_I,_D,_eol
_m_laser:		.BYTE _L,_a,_s,_e,_r,_eol
_m_laugh:		.BYTE _L,_a,_u,_g,_h,_eol
_m_left:		.BYTE _L,_e,_f,_t,_eol
_m_lie:			.BYTE _L,_i,_e,_eol
_m_list:		.BYTE _L,_i,_s,_t,_eol
_m_look:		.BYTE _L,_o,_o,_k,_eol
_m_make:		.BYTE _M,_a,_k,_e,_eol
_m_masaru:		.BYTE _M,_a,_s,_a,_r,_u,_eol
_m_move:		.BYTE _M,_o,_v,_e,_eol
_m_nearby:		.BYTE _N,_e,_a,_r,_b,_y,_eol
_m_open:		.BYTE _O,_p,_e,_n,_eol
_m_panic:		.BYTE _P,_a,_n,_i,_c,_eol
_m_peek:		.BYTE _P,_e,_e,_k,_eol
_m_photo:		.BYTE _P,_h,_o,_t,_o,_eol
_m_pick:		.BYTE _P,_i,_c,_k,_eol
_m_play:		.BYTE _P,_l,_a,_y,_eol
_m_pocket:		.BYTE _P,_o,_c,_k,_e,_t,_eol
_m_ponder:		.BYTE _P,_o,_n,_d,_e,_r,_eol
_m_pray:		.BYTE _P,_r,_a,_y,_eol
_m_raise:		.BYTE _R,_a,_i,_s,_e,_eol
_m_rely_on:		.BYTE _R,_e,_l,_y,__,_o,_n,_eol
_m_right:		.BYTE _R,_i,_g,_h,_t,_eol
_m_run:			.BYTE _R,_u,_n,_eol
_m_run_to:		.BYTE _R,_u,_n,__,_t,_o,_eol
_m_school:		.BYTE _S,_c,_h,_o,_o,_l,_eol
_m_search:		.BYTE _S,_e,_a,_r,_c,_h,_eol
_m_shout:		.BYTE _S,_h,_u,_t,_eol
_m_show:		.BYTE _S,_h,_o,_w,_eol
_m_slide:		.BYTE _S,_l,_i,_d,_e,_eol
_m_sneak:		.BYTE _S,_n,_e,_a,_k,_eol
_m_stadium:		.BYTE _S,_t,_a,_d,_i,_u,_m,_eol
_m_stare:		.BYTE _S,_t,_a,_r,_e,_eol
_m_stop:		.BYTE _S,_t,_o,_p,_eol
_m_tackle:		.BYTE _T,_a,_c,_k,_l,_e,_eol
_m_takashi:		.BYTE _T,_a,_k,_a,_s,_h,_i,_eol
_m_take:		.BYTE _T,_a,_k,_e,_eol
_m_talk:		.BYTE _T,_a,_l,_k,_eol
_m_tease:		.BYTE _T,_e,_a,_s,_e,_eol
_m_terrori:		.BYTE $49,$4A,$4B,$4C,$4D,$4E,$4F,_eol
_m_tetsuo:		.BYTE _T,_e,_t,_s,_u,_o,_eol
_m_throw:		.BYTE _T,_h,_r,_o,_w,_eol
_m_town:		.BYTE _T,_o,_w,_n,_eol
_m_truth:		.BYTE _T,_r,_u,_t,_h,_eol
_m_turn:		.BYTE _T,_u,_r,_n,_eol
_m_use:			.BYTE _U,_s,_e,_eol
_m_walkway:		.BYTE _W,_a,_l,_k,_w,_a,_y,_eol
_m_yamagat:		.BYTE $42,$43,$44,$45,$46,$47,$48,_eol
_m_yell:		.BYTE _Y,_e,_l,_l,_eol

_m_about:		.BYTE _A,_b,_o,_u,_t,_eol
_m_____kei:		.BYTE __,__,__,__,_K,_e,_i,_eol
_m_____kid:		.BYTE __,__,__,__,_K,_i,_d,_eol
_m_____lab:		.BYTE __,__,__,__,_l,_a,_b,_eol
_m____army:		.BYTE __,__,__,_A,_r,_m,_y,_eol
_m____bike:		.BYTE __,__,__,_b,_i,_k,_e,_eol
_m____dumb:		.BYTE __,__,__,_d,_u,_m,_b,_eol
_m___akira:		.BYTE __,__,_A,_k,_i,_r,_a,_eol
_m___cover:		.BYTE __,__,_c,_o,_v,_e,_r,_eol
_m___hands:		.BYTE __,__,_h,_a,_n,_d,_s,_eol
_m___noise:		.BYTE __,__,_n,_o,_i,_s,_e,_eol
_m__tetsuo:		.BYTE __,_T,_e,_t,_s,_u,_o,_eol

;_m_kaneda:		.BYTE _K,_a,_n,_e,_d,_a,_eol			; -unused-
;_m_license:	.BYTE _L,_i,_c,_e,_n,_s,_e,_eol			; -unused-
