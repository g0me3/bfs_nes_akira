
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
		MITEM	peek   ,__g
		MITEM	inquire,_
		MITEM	laugh  ,_
_sc1_menu1:
		MITEM	gang   ,_
		MITEM	pick   ,_g
;		MITEM	army   ,_					; -unused-
;		MITEM	kaneda ,___g				; -unused-
;		MITEM	license,_					; -unused-
;		MITEM	list   ,_					; -unused-
_sc1_menu2:
		MITEM	army   ,_
		MITEM	desk   ,_
		MITEM	list   ,_
_sc2_menu0:
		MITEM	inquire,_
		MITEM	check  ,___g
		MITEM	ask_out,_
_sc2_menu1:
		MITEM	nearby ,_
		MITEM	pick   ,_g
_sc2_menu2:
		MITEM	yell   ,___g
		MITEM	panic  ,_
		MITEM	jump   ,__g
_sc2_menu3:
		MITEM	run    ,__g
		MITEM	jump_on,__g					; "tackle" for eng version
		MITEM	cover  ,_					; "take cover" for eng version
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
		MITEM	move   ,_g___g
		MITEM	inquire,_
		MITEM	peek   ,__g
		MITEM	tease  ,_					; actual "tease" here both in eng and japan
		MITEM	drink  ,_g
_sc5_menu1:
		MITEM	yell   ,___g
		MITEM	search ,__g
		MITEM	show   ,_
		MITEM	inquire,_
		MITEM	move   ,_g___g
_sc5_menu2:
		MITEM	hangout,_
		MITEM	1      ,_
		MITEM	2      ,_
		MITEM	3      ,_
		MITEM	4      ,_
_sc6_menu01:
		MITEM	run    ,__g
		MITEM	jump_on,__g
		MITEM	hit    ,__g
		MITEM	crouch ,__g
_sc6_menu2:
		MITEM	run    ,__g
		MITEM	ponder ,___g
		MITEM	look   ,_
		MITEM	panic  ,_
		MITEM	run_to ,_
_sc6_menu37:
		MITEM	car    ,_
		MITEM	crc    ,_
		MITEM	tetsuo ,_
_sc6_menu4:
		MITEM	inquire,_
		MITEM	ponder ,___g
		MITEM	take   ,_
		MITEM	look   ,_
		MITEM	run_to ,_
_sc6_menu5:
		MITEM	open   ,_
		MITEM	inquire,_
		MITEM	flatter,__g
		MITEM	hit    ,__g
		MITEM	yell   ,___g
		MITEM	look   ,_
_sc6_menu6:
		MITEM	yell   ,___g
		MITEM	hit    ,__g
		MITEM	run_to ,_
_sc7_menu0:
		MITEM	inquire,_
_sc7_menu1:
		MITEM	yamagat,___g
		MITEM	kai    ,_
		MITEM	groupie,_g__p
_sc7_menu2:
		MITEM	about_tetsuo,_
		MITEM	about_army,_
		MITEM	about_kid,_g
		MITEM	about_akira,_
_sc7_menu3:
		MITEM	inquire,_
		MITEM	look   ,_
		MITEM	check  ,___g
		MITEM	move   ,_g___g
_sc7_menu4:
		MITEM	gang   ,_
		MITEM	terrori,_
		MITEM	walkway,_p____g
_sc8_menu0:
		MITEM	check  ,___g
		MITEM	inquire,_
		MITEM	peek   ,__g
_sc8_menu1:
		MITEM	talk   ,_
		MITEM	ask_out,_
		MITEM	make_noise,___g
		MITEM	hide   ,_
		MITEM	sneak  ,___g
_sc8_menu2:
		MITEM	talk   ,_
		MITEM	raise_hands,____g
		MITEM	pray   ,_
		MITEM	jump_on,__g
		MITEM	dash   ,_g
_sc8_menu3:
		MITEM	play_dumb,__g
		MITEM	slide  ,__g
		MITEM	flip   ,_g
		MITEM	dive   ,_g_g_g
_sc9_menu0:
		MITEM	talk   ,_
		MITEM	ponder ,___g
		MITEM	check  ,___g
_sc9_menu1:
		MITEM	explain,_
		MITEM	rely_on_kei,_____g
_sc9_menu2:
		MITEM	truth  ,___g
		MITEM	lie    ,_
		MITEM	joke   ,_g__g				; "tease" in eng version
_scA_menu0:
		MITEM	ponder ,___g
		MITEM	check  ,___g
		MITEM	open   ,_
_scA_menu1:
		MITEM	about_terrori,_g
		MITEM	about_army,_
		MITEM	about_tetsuo,_
		MITEM	about_kei,_
_scA_menu2:
		MITEM	door   ,_g
		MITEM	beer   ,_g
_scA_menu3:
		MITEM	run    ,__g
		MITEM	drink  ,_g
		MITEM	peek   ,__g
_scA_menu4:
		MITEM	check  ,___g
		MITEM	go_on  ,_
_scA_menu56:
		MITEM	check  ,___g
		MITEM	inquire,_
		MITEM	go_on  ,_
_scB_menu0:
		MITEM	talk   ,_
_scB_menu1:
		MITEM	beg    ,_
		MITEM	ponder ,___g
		MITEM	inquire,_
_scB_menu2:
		MITEM	take   ,_
		MITEM	beg    ,_
		MITEM	ponder ,___g
		MITEM	inquire,_
_scB_menu3:
		MITEM	lab_id ,__g__p
		MITEM	photo  ,_
_scB_menu45:
		MITEM	about_army,_
		MITEM	about_lab,__g
		MITEM	about_terrori,_g
_scC_menu0:
		MITEM	talk   ,_
		MITEM	go_on  ,_
_scC_menu1:
		MITEM	run    ,__g
		MITEM	take   ,_
_scC_menu2:
		MITEM	run    ,__g
		MITEM	cover  ,_
		MITEM	dodge  ,_
		MITEM	throw  ,__g
_scC_menu3:
		MITEM	run    ,__g
		MITEM	cover  ,_
		MITEM	jump_at,__g
_scF_menu0:
		MITEM	run    ,__g
		MITEM	rely_on_kei,_____g
		MITEM	show   ,_
		MITEM	look   ,_
		MITEM	talk   ,_
_scF_menu1:
		MITEM	pocket ,_p
		MITEM	lab_id ,__g__p
_scF_menu2:
		MITEM	masaru ,_
		MITEM	takashi,_
		MITEM	kiyoko ,_
		MITEM	colonel,_
		MITEM	tetsuo ,_
_sc10_menu0:
		MITEM	check  ,___g
		MITEM	inquire,_
		MITEM	ponder ,___g
		MITEM	call   ,__g
_sc10_menu1:
		MITEM	run    ,__g
		MITEM	shout  ,_
_sc10_menu2:
		MITEM	about_army,_
		MITEM	about_terrori,_g
		MITEM	about_tetsuo,_
		MITEM	about_akira,_
_sc11_menu01:
		MITEM	look   ,_
		MITEM	check  ,___g
		MITEM	inquire,_
		MITEM	run_to ,_
		MITEM	ponder ,___g
_sc11_menu2:
		MITEM	town   ,_
		MITEM	school ,_g
_sc11_menu3:
		MITEM	run_to ,_
		MITEM	look   ,_
		MITEM	check  ,___g
		MITEM	inquire,_
		MITEM	ponder ,___g
		MITEM	move   ,_g___g
_sc12_menu02:
		MITEM	move   ,_g___g
_sc12_menu1:
		MITEM	school ,_g
_sc12_menu3:
		MITEM	town   ,_
		MITEM	site   ,_
_sc12_menu4:
		MITEM	inquire,_
		MITEM	check  ,___g
		MITEM	go_on  ,_
_sc12_menu5:
		MITEM	look   ,_
		MITEM	go_on  ,_
		MITEM	stop   ,_
_sc13_menu01:
		MITEM	dodge  ,_
		MITEM	jump_on,__g
		MITEM	use    ,_
_sc13_menu2:
		MITEM	cover  ,_
		MITEM	turn   ,_
		MITEM	yell   ,___g
		MITEM	inquire,_
		MITEM	look   ,_
_sc13_menu3:
		MITEM	yell   ,___g
		MITEM	jump   ,__g
		MITEM	ask_out,_
		MITEM	look   ,_
_sc14_menu0:
		MITEM	stare  ,_
		MITEM	ponder ,___g
		MITEM	inquire,_
		MITEM	peek   ,__g
_sc14_menu14:
		MITEM	kei    ,_
		MITEM	kai    ,_
		MITEM	laser  ,___g
_sc14_menu23:
		MITEM	about_tetsuo,_
		MITEM	stadium,___g
		MITEM	about_bike,_g
_sc15_menu0:
		MITEM	attack ,_
		MITEM	dash   ,_g
		MITEM	pray   ,_
		MITEM	throw  ,__g
		MITEM	look   ,_
		MITEM	ponder ,___g
_sc15_menu1:
		MITEM	dash   ,_g
		MITEM	take   ,_
		MITEM	crouch ,__g
		MITEM	yell   ,___g
		MITEM	attack ,_
_sc15_menu2:
		MITEM	right  ,__g
		MITEM	left   ,__g
_sc15_menu3:
		MITEM	look   ,_
		MITEM	attack ,_
_sc15_menu4:
		MITEM	jump   ,_					; why _m_talk were here? seems one more bug
		MITEM	run    ,__g
		MITEM	hit    ,__g

_m_:				.BYTE _eol
_m_1:				.BYTE _1,_KU,_eol
_m_2:				.BYTE _2,_KU,_eol
_m_3:				.BYTE _3,_KU,_eol
_m_4:				.BYTE _4,_KU,_eol
_m_army:			.BYTE _A_,_str,_MI,_str,_eol
_m_ask_out:			.BYTE _o_,_ti,_yy,_ni,_sa,_so,_u_,_eol
_m_attack:			.BYTE _u_,_tu,_eol
_m_beer:			.BYTE _HI,_str,_RU,_eol
_m_beg:				.BYTE _ta,_no,_mu,_eol
_m_call:			.BYTE _yo,_hu,_eol						; "to call, to invite"
_m_car:				.BYTE _ku,_ru,_ma,_eol
_m_check:			.BYTE _si,_ra,_he,_ru,_eol
_m_colonel:			.BYTE _ta,_i_,_sa,_eol
_m_cover:			.BYTE _hu,_se,_ru,_eol					; "to hide, to lay down, to cover"
_m_crc:				.BYTE _C,_dot,_R,_dot,_C,_eol
_m_crouch:			.BYTE _ka,_ka,_mu,_eol					; "lean over"
_m_dash:			.BYTE _TA,_TT,_SI,_UU,_su,_ru,_eol
_m_desk:			.BYTE _tu,_ku,_e_,_no,_si,_ta,_eol		; "under the desk"
_m_dive:			.BYTE _TA,_I_,_HI,_N_,_KU,_su,_ru,_eol
_m_dodge:			.BYTE _ka,_wa,_su,_eol
_m_door:			.BYTE _TO,_A_,_eol
_m_drink:			.BYTE _HI,_str,_RU,_wo,_no,_mu,_eol		; "drink beer" to be honest
_m_explain:			.BYTE _se,_tu,_me,_i_,_su,_ru,_eol
_m_flatter:			.BYTE _ko,_hi,_wo,_u_,_ru,_eol
_m_flip:			.BYTE _HA,_KU,_te,_n_,_su,_ru,_eol
_m_gang:			.BYTE _na,_ka,_ma,_eol
_m_girl:			.BYTE _o_,_n_,_na,_no,_ko,_eol
_m_go_back:			.BYTE _ka,_e_,_ru,_eol
_m_go_on:			.BYTE _su,_su,_mu,_eol
_m_groupie:			.BYTE _KU,_RU,_str,_HI,_str,_eol
_m_hangout:			.BYTE _ha,_ru,_ki,_ya,_eol				; "Harukiya" snack bar name, "hangout"
_m_hide:			.BYTE _ka,_ku,_re,_ru,_eol				; actual "to hide, to be hidden"
_m_hit:				.BYTE _na,_ku,_ru,_eol
_m_inquire:			.BYTE _ki,_ku,_eol
_m_joke:			.BYTE _si,_oo,_u_,_ta,_n_,_eol
_m_jump:			.BYTE _o_,_to,_ru,_eol
_m_jump_at:			.BYTE _to,_hi,_tu,_ku,_eol				; "jump at"
_m_jump_on:			.BYTE _to,_hi,_ka,_ka,_ru,_eol			; "to spring upon"
_m_kai:				.BYTE _ka,_i_,_eol
_m_kei:				.BYTE _KE,_I_,_eol
_m_kiyoko:			.BYTE _KI,_YO,_KO,_eol
_m_lab_id:			.BYTE _RA,_HO,_no,_HA,_SU,_eol
_m_laser:			.BYTE _RE,_str,_SA,_str,_eol
_m_laugh:			.BYTE _wa,_ra,_u_,_eol
_m_left:			.BYTE _hi,_ta,_ri,_eol
_m_lie:				.BYTE _u_,_so,_eol
_m_list:			.BYTE _RI,_SU,_TO,_eol
_m_look:			.BYTE _mi,_ru,_eol
_m_make_noise:		.BYTE _sa,_wa,_ku,_eol
_m_masaru:			.BYTE _MA,_SA,_RU,_eol
_m_move:			.BYTE _ha,_si,_oo,_i_,_to,_u_,_eol		; "change location"
_m_nearby:			.BYTE _a_,_ta,_ri,_eol
_m_open:			.BYTE _a_,_ke,_ru,_eol
_m_panic:			.BYTE _a_,_wa,_te,_ru,_eol
_m_peek:			.BYTE _no,_so,_ku,_eol
_m_photo:			.BYTE _si,_yy,_si,_n_,_eol
_m_pick:			.BYTE _to,_ko,_eol						; "what place, where"
_m_play_dumb:		.BYTE _to,_ho,_ke,_ru,_eol
_m_pocket:			.BYTE _HO,_KE,_TT,_TO,_eol
_m_ponder:			.BYTE _ka,_n_,_ka,_e_,_ru,_eol
_m_pray:			.BYTE _i_,_no,_ru,_eol
_m_raise_hands:		.BYTE _te,_wo,_a_,_ke,_ru,_eol
_m_rely_on_kei:		.BYTE _KE,_I_,_ni,_su,_ka,_ru,_eol
_m_right:			.BYTE _mi,_ki,_eol
_m_run:				.BYTE _ni,_ke,_ru,_eol
_m_run_to:			.BYTE _ka,_ke,_yo,_ru,_eol
_m_school:			.BYTE _ka,_tt,_ko,_u_,_eol
_m_search:			.BYTE _sa,_ka,_su,_eol
_m_shout:			.BYTE _si,_me,_ru,_eol					; "to constrict", odd
_m_show:			.BYTE _mi,_se,_ru,_eol
_m_site:			.BYTE _yo,_te,_i_,_ti,_eol				; "construction [site]"
_m_slide:			.BYTE _su,_he,_ri,_ko,_mu,_eol
_m_sneak:			.BYTE _ti,_ka,_tu,_ku,_eol				; "to approach, to get closer"
_m_stadium:			.BYTE _SU,_TA,_SI,_A_,_MU,_eol			; ;actual "stadium" in japanese
_m_stare:			.BYTE _mi,_tu,_me,_ru,_eol
_m_stop:			.BYTE _to,_ma,_ru,_eol
_m_takashi:			.BYTE _TA,_KA,_SI,_eol
_m_take:			.BYTE _to,_ru,_eol
_m_talk:			.BYTE _ha,_na,_su,_eol
_m_tease:			.BYTE _ka,_ra,_ka,_u_,_eol
_m_terrori:			.BYTE _TE,_RO,_RI,_SU,_TO,_eol
_m_tetsuo:			.BYTE _TE,_TU,_O_,_eol
_m_throw:			.BYTE _na,_ke,_ru,_eol
_m_town:			.BYTE _ma,_ti,_eol
_m_truth:			.BYTE _si,_n_,_si,_tu,_eol
_m_turn:			.BYTE _hu,_ri,_mu,_ku,_eol				; "turn around"
_m_use:				.BYTE _tu,_ka,_u_,_eol
_m_walkway:			.BYTE _HU,_RO,_MU,_NA,_str,_TO,_eol		; "promenade"
_m_yamagat:			.BYTE _ya,_ma,_ka,_ta,_eol
_m_yell:			.BYTE _sa,_ke,_hu,_eol

_m_about_akira:		.BYTE _A_,_KI,_RA,_no,_KO,_TO,_eol
_m_about_army:		.BYTE _A_,_str,_MI,_str,_no,_KO,_TO,_eol
_m_about_bike:		.BYTE _HA,_I_,_KU,_no,_KO,_TO,_eol
_m_about_kei:		.BYTE _KE,_I_,_no,_KO,_TO,_eol
_m_about_kid:		.BYTE _KA,_KI,_no,_KO,_TO,_eol
_m_about_lab:		.BYTE _RA,_HO,_no,_KO,_TO,_eol
_m_about_terrori:	.BYTE _KE,_RI,_RA,_no,_KO,_TO,_eol
_m_about_tetsuo:	.BYTE _TE,_TU,_O_,_no,_KO,_TO,_eol

_m_g:				.BYTE _gg,_eol
_m__g:				.BYTE ___,_gg,_eol
_m___g:				.BYTE ___,___,_gg,_eol
_m____g:			.BYTE ___,___,___,_gg,_eol
_m_____g:			.BYTE ___,___,___,___,_gg,_eol
_m_g__g:			.BYTE _gg,___,___,_gg,_eol
_m_g___g:			.BYTE _gg,___,___,___,_gg,_eol
_m_g_g_g:			.BYTE _gg,___,_gg,___,_gg,_eol
_m__g__p:			.BYTE ___,_gg,___,_pp,_eol
_m_g__p:			.BYTE _gg,___,___,_pp,_eol
_m_p:				.BYTE _pp,_eol
_m_p____g:			.BYTE _pp,___,___,___,___,_gg,_eol

;_m_divider:		.BYTE _str,_str,_str,_str,_str,_str,_str,_eol	; -unused-
;_m_kaneda:			.BYTE _ka,_ne,_ta,_eol							; -unused-
;_m_license:		.BYTE _me,_n_,_ki,_oo,_eol						; -unused-
