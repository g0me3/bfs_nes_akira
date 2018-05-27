
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
		MITEM	govo   ,_____rit	;Гово-  ,____рить
		MITEM	smot   ,_____ret	;Смот-  ,____реть
		MITEM	vzglya ,_____nut	;Взгля- ,____нуть
		MITEM	uznat  ,_			;Узнать ,_
		MITEM	smejt  ,______sa	;Смеять-,______ся
_sc1_menu1:
		MITEM	banda  ,_			;Банда  ,_
		MITEM	vibrat ,_			;Выбрать,_
_sc1_menu2:
		MITEM	voennyi,_			;Военный,_
		MITEM	stol   ,_			;Стол   ,_
		MITEM	spisok ,_			;Список ,_
_sc2_menu0:
		MITEM	uznat  ,_			;Узнать ,_
		MITEM	prove  ,_____rit	;Прове- ,____рить
		MITEM	prigla ,_____sit	;Пригла-,____сить
_sc2_menu1:
		MITEM	vokrug ,_			;Вокруг ,_
		MITEM	vibrat ,_			;Выбрать,_
_sc2_menu2:
		MITEM	krichat,_			;Кричать,_
		MITEM	paniko ,_____vat	;Панико-,____вать
		MITEM	pryg   ,_____nut	;Прыг-  ,____нуть
_sc2_menu3:
		MITEM	bejat  ,_			;Бежать ,_
		MITEM	shva   ,_____tit	;Схва-  ,____тить
		MITEM	ukryt  ,______sa	;Укрыть-,______ся
		MITEM	glazet ,_			;Глазеть,_
		MITEM	molit  ,______sa	;Молить-,______ся
_sc2_menu4:
		MITEM	vokrug ,_			;Вокруг ,_
		MITEM	girl   ,_			;Девушка,_
		MITEM	voennyi,_			;Военный,_
_sc2_menu5:
		MITEM	vernu  ,____tsya	;Верну- ,____ться
		MITEM	smot   ,_____ret	;Смот-  ,____реть
		MITEM	govo   ,_____rit	;Гово-  ,____рить
_sc5_menu0:
		MITEM	idti   ,_			;Идти   ,_
		MITEM	uznat  ,_			;Узнать ,_
		MITEM	vzglya ,_____nut	;Взгля- ,____нуть
		MITEM	pozlit ,_			;Позлить,_
		MITEM	vypit  ,_			;Выпить ,_
_sc5_menu1:
		MITEM	krichat,_			;Кричать,_
		MITEM	iskat  ,_			;Искать ,_
		MITEM	poka   ,_____zat	;Пока-  ,____зать
		MITEM	uznat  ,_			;Узнать ,_
		MITEM	idti   ,_			;Идти   ,_
_sc5_menu2:
		MITEM	bar    ,_			;Бар    ,_
		MITEM	1      ,_
		MITEM	2      ,_
		MITEM	3      ,_
		MITEM	4      ,_
_sc6_menu01:
		MITEM	bejat  ,_			;Бежать ,_
		MITEM	zapryg ,_____nut	;Запрыг-,____нуть
		MITEM	udarit ,_			;Ударить,_
		MITEM	prignu ,____tsya	;Пригну-,____ться
_sc6_menu2:
		MITEM	bejat  ,_			;Бежать ,_
		MITEM	razmysh,____lyat	;Размыш-,____лять
		MITEM	smot   ,_____ret	;Смот-  ,____реть
		MITEM	paniko ,_____vat	;Панико-,____вать
		MITEM	podbe  ,_____jat	;Подбе- ,____жать
_sc6_menu37:
		MITEM	mashina,_			;Машина ,_
		MITEM	pcu    ,_			;ПЦУ    ,_
		MITEM	tetsuo ,_			;Тэцуо  ,_
_sc6_menu4:
		MITEM	uznat  ,_			;Узнать ,_
		MITEM	razmysh,____lyat	;Размыш-,____лять
		MITEM	vzyat  ,_			;Взять  ,_
		MITEM	smot   ,_____ret	;Смот-  ,____реть
		MITEM	podbe  ,_____jat	;Подбе- ,____жать
_sc6_menu5:
		MITEM	otkryt ,_			;Открыть,_
		MITEM	uznat  ,_			;Узнать ,_
		MITEM	lstit  ,_			;Льстить,_
		MITEM	udarit ,_			;Ударить,_
		MITEM	krichat,_			;Кричать,_
		MITEM	smot   ,_____ret	;Смот-  ,____реть
_sc6_menu6:
		MITEM	krichat,_			;Кричать,_
		MITEM	udarit ,_			;Ударить,_
		MITEM	podbe  ,_____jat	;Подбе- ,____жать
_sc7_menu0:
		MITEM	uznat  ,_			;Узнать ,_
_sc7_menu1:
		MITEM	yamagat,_			;Ямагата,_
		MITEM	kai    ,_			;Кай    ,_
		MITEM	fanatka,_			;Фанатка,_
_sc7_menu2:
		MITEM	o_tecuo,_			;О_Тэцуо,_
		MITEM	o      ,_voennih	;О      ,_военных
		MITEM	o      ,_rebenke	;О      ,_ребёнке
		MITEM	ob     ,___akire	;Об     ,___Акире
_sc7_menu3:
		MITEM	uznat  ,_			;Узнать ,_
		MITEM	smot   ,_____ret	;Смот-  ,____реть
		MITEM	prove  ,_____rit	;Прове- ,____рить
		MITEM	idti   ,_			;Идти   ,_
_sc7_menu4:
		MITEM	banda  ,_			;Банда  ,_
		MITEM	terro  ,___risti	;Терро- ,___ристы
		MITEM	alleya ,_			;Аллея  ,_
_sc8_menu0:
		MITEM	prove  ,_____rit	;Прове- ,____рить
		MITEM	uznat  ,_			;Узнать ,_
		MITEM	vzglya ,_____nut	;Взгля- ,____нуть
_sc8_menu1:
		MITEM	govo   ,_____rit	;Гово-  ,____рить
		MITEM	prigla ,_____sit	;Пригла-,____сить
		MITEM	shumet ,_			;Шуметь ,_
		MITEM	pryata ,____tsya	;Прята- ,____ться
		MITEM	probra ,__ratsya	;Проб-  ,__раться
_sc8_menu2:
		MITEM	govo   ,_____rit	;Гово-  ,____рить
		MITEM	podnyat,____ruki	;Поднять,____руки
		MITEM	molit  ,______sa	;Молить-,______ся
		MITEM	zapryg ,_____nut	;Запрыг-,____нуть
		MITEM	ryvok  ,_			;Рывок  ,_
_sc8_menu3:
		MITEM	vklucit,__duraka	;Включить,__дурака
		MITEM	spolzti,_			;Сползти,_
		MITEM	pere   ,__vernut	;Пере-  ,_вернуть
		MITEM	nyrnut ,_			;Нырнуть,_
_sc9_menu0:
		MITEM	govo   ,_____rit	;Гово-  ,____рить
		MITEM	razmysh,____lyat	;Размыш-,____лять
		MITEM	prove  ,_____rit	;Прове- ,____рить
_sc9_menu1:
		MITEM	obyas  ,_____nit	;Объяс- ,____нить
		MITEM	pologit,__na_kei	;Спро-  ,сить_Кей		; rely on key
_sc9_menu2:
		MITEM	skazat ,__pravdu    ;Сказать,__правду
		MITEM	sovrat ,_			;Соврать,_
		MITEM	kriv   ,___lztsa	;Крив-  ,__ляться
_scA_menu0:
		MITEM	razmysh,____lyat	;Размыш-,____лять
		MITEM	prove  ,_____rit	;Прове- ,____рить
		MITEM	otkryt ,_			;Открыть,_
_scA_menu1:
		MITEM	o_ter  ,_rorista	;О_тер- ,_рористаx
		MITEM	o      ,_voennih	;О      ,_военных
		MITEM	o_tecuo,_			;О_Тэцуо,_
		MITEM	o_kei  ,_			;О_Кей  ,_
_scA_menu2:
		MITEM	dver   ,_			;Дверь  ,_
		MITEM	pivo   ,_			;Пиво   ,_
_scA_menu3:
		MITEM	bejat  ,_			;Бежать ,_
		MITEM	vypit  ,_			;Выпить ,_
		MITEM	vzglya ,_____nut	;Взгля- ,____нуть
_scA_menu4:
		MITEM	prove  ,_____rit	;Прове- ,____рить
		MITEM	dvi    ,___gatsa   	;Дви-   ,__гаться
_scA_menu56:
		MITEM	prove  ,_____rit	;Прове- ,____рить
		MITEM	uznat  ,_			;Узнать ,_
		MITEM	dvi    ,___gatsa   	;Дви-   ,__гаться
_scB_menu0:
		MITEM	govo   ,_____rit	;Гово-  ,____рить
_scB_menu1:
		MITEM	prosit ,_			;Просить,_
		MITEM	razmysh,____lyat	;Размыш-,____лять
		MITEM	uznat  ,_			;Узнать ,_
_scB_menu2:
		MITEM	vzyat  ,_			;Взять  ,_
		MITEM	prosit ,_			;Просить,_
		MITEM	razmysh,____lyat	;Размыш-,____лять
		MITEM	uznat  ,_			;Узнать ,_
_scB_menu3:
		MITEM	propusk,_			;Пропуск,_
		MITEM	foto   ,_			;Фото   ,_
_scB_menu45:
		MITEM	o      ,_voennih	;О      ,_военных
		MITEM	o_labo ,_ratorii	;О_лабо-,_ратории
		MITEM	o_ter  ,_rorista	;О_тер- ,_рористаx
_scC_menu0:
		MITEM	govo   ,_____rit	;Гово-  ,____рить
		MITEM	prodol ,_____jit	;Продол-,____жить
_scC_menu1:
		MITEM	bejat  ,_			;Бежать ,_
		MITEM	vzyat  ,_			;Взять  ,_
_scC_menu2:
		MITEM	bejat  ,_			;Бежать ,_
		MITEM	pryata ,____tsya	;Прята- ,____ться
		MITEM	uvernu ,__nutsya	;Увер-  ,__нуться
		MITEM	kinut  ,_			;Кинуть ,_
_scC_menu3:
		MITEM	bejat  ,_			;Бежать ,_
		MITEM	pryata ,____tsya	;Прята- ,____ться
		MITEM	zapryg ,_____nut	;Запрыг-,____нуть
_scF_menu0:
		MITEM	bejat  ,_			;Бежать ,_
		MITEM	pologit,__na_kei	;Спро-  ,сить_Кей		; rely on key
		MITEM	poka   ,_____zat	;Пока-  ,____зать
		MITEM	smot   ,_____ret	;Смот-  ,____реть
		MITEM	govo   ,_____rit	;Гово-  ,____рить
_scF_menu1:
		MITEM	karman ,_			;Карман ,_
		MITEM	propusk,_			;Пропуск,_
_scF_menu2:
		MITEM	masaru ,_			;Масару ,_
		MITEM	takashi,_			;Такаси ,_
		MITEM	kiyoko ,_			;Киёко  ,_
		MITEM	polkov ,_____nik	;Полков-,_____ник
		MITEM	tetsuo ,_			;Тэцуо  ,_
_sc10_menu0:
		MITEM	prove  ,_____rit	;Прове- ,____рить
		MITEM	uznat  ,_			;Узнать ,_
		MITEM	razmysh,____lyat	;Размыш-,____лять
		MITEM	pozvat ,_			;Позвать,_
_sc10_menu1:
		MITEM	bejat  ,_			;Бежать ,_
		MITEM	orat   ,_			;Орать  ,_
_sc10_menu2:
		MITEM	o      ,_voennih	;О      ,_военных
		MITEM	o_ter  ,_rorista	;О_тер- ,_рористаx
		MITEM	o_tecuo,_			;О_Тэцуо,_
		MITEM	ob     ,___akire	;Об     ,___Акире
_sc11_menu01:
		MITEM	smot   ,_____ret	;Смот-  ,____реть
		MITEM	prove  ,_____rit	;Прове- ,____рить
		MITEM	uznat  ,_			;Узнать ,_
		MITEM	podbe  ,_____jat	;Подбе- ,____жать
		MITEM	razmysh,____lyat	;Размыш-,____лять
_sc11_menu2:
		MITEM	gorod  ,_			;Город  ,_
		MITEM	shkola ,_			;Школа  ,_
_sc11_menu3:
		MITEM	podbe  ,_____jat	;Подбе- ,____жать
		MITEM	smot   ,_____ret	;Смот-  ,____реть
		MITEM	prove  ,_____rit	;Прове- ,____рить
		MITEM	uznat  ,_			;Узнать ,_
		MITEM	razmysh,____lyat	;Размыш-,____лять
		MITEM	idti   ,_			;Идти   ,_
_sc12_menu02:
		MITEM	idti   ,_			;Идти   ,_
_sc12_menu1:
		MITEM	shkola ,_			;Школа  ,_
_sc12_menu3:
		MITEM	gorod  ,_			;Город  ,_
		MITEM	stadion,_			;Стадион,_
_sc12_menu4:
		MITEM	uznat  ,_			;Узнать ,_
		MITEM	prove  ,_____rit	;Прове- ,____рить
		MITEM	prodol ,_____jit	;Продол-,____жить
_sc12_menu5:
		MITEM	prove  ,_____rit	;Прове- ,____рить
		MITEM	prodol ,_____jit	;Продол-,____жить
		MITEM	ostano ,__vitsya	;Остано-,__виться
_sc13_menu01:
		MITEM	uvernu ,__nutsya	;Увер-  ,__нуться
		MITEM	zapryg ,_____nut	;Запрыг-,____нуть
		MITEM	ispol  ,___zovat	;Исполь-,__зовать
_sc13_menu2:
		MITEM	pryata ,____tsya	;Прята- ,____ться
		MITEM	pover  ,_____nut	;Повер- ,____нуть
		MITEM	krichat,_			;Кричать,_
		MITEM	uznat  ,_			;Узнать ,_
		MITEM	smot   ,_____ret	;Смот-  ,____реть
_sc13_menu3:
		MITEM	krichat,_			;Кричать,_
		MITEM	pryg   ,_____nut	;Прыг-  ,____нуть
		MITEM	prigla ,_____sit	;Пригла-,____сить
		MITEM	smot   ,_____ret	;Смот-  ,____реть
_sc14_menu0:
		MITEM	glazet ,_			;Глазеть,_
		MITEM	razmysh,____lyat	;Размыш-,____лять
		MITEM	uznat  ,_			;Узнать ,_
		MITEM	vzglya ,_____nut	;Взгля- ,____нуть
_sc14_menu14:
		MITEM	kei    ,_			;Кей    ,_
		MITEM	kai    ,_			;Кай    ,_
		MITEM	laser  ,_			;Лазер  ,_
_sc14_menu23:
		MITEM	o_tecuo,_			;О_Тэцуо,_
		MITEM	stadion,_			;Стадион,_
		MITEM	o_baike,_			;О_байке,_
_sc15_menu0:
		MITEM	udarit ,_			;Ударить,_
		MITEM	ryvok  ,_			;Рывок  ,_
		MITEM	molit  ,______sa	;Молить-,______ся
		MITEM	kinut  ,_			;Кинуть ,_
		MITEM	smot   ,_____ret	;Смот-  ,____реть
		MITEM	razmysh,____lyat	;Размыш-,____лять
_sc15_menu1:
		MITEM	ryvok  ,_			;Рывок  ,_
		MITEM	vzyat  ,_			;Взять  ,_
		MITEM	prignu ,____tsya	;Пригну-,____ться
		MITEM	krichat,_			;Кричать,_
		MITEM	udarit ,_			;Ударить,_
_sc15_menu2:
		MITEM	right  ,_			;Направо,_
		MITEM	left   ,_			;Налево ,_
_sc15_menu3:
		MITEM	smot   ,_____ret	;Смот-  ,____реть
		MITEM	atako  ,_____vat	;Атако- ,____вать
_sc15_menu4:
		MITEM	pryg   ,_____nut	;Прыг-  ,____нуть
		MITEM	bejat  ,_			;Бежать ,_
		MITEM	udarit ,_			;Ударить,_

_m_:			.BYTE	_eol

_m_1:			.BYTE	_1,_eol
_m_2:			.BYTE	_2,_eol
_m_3:			.BYTE	_3,_eol
_m_4:			.BYTE	_4,_eol
_m_o:			.BYTE	_O,_eol

_m_ob:			.BYTE	_O,_b,_eol

_m_bar:			.BYTE	_B,_a,_r,_eol
_m_kai:			.BYTE	_K,_a,_j,_eol
_m_kei:			.BYTE	_K,_e,_j,_eol
_m_pcu:			.BYTE	_P,_C,_U,_eol

_m_dvi:			.BYTE	_D,_v,_i,_str,_eol
_m_foto:		.BYTE	_F,_o,_t,_o,_eol
_m_idti:		.BYTE	_I,_d,_t,_i,_eol
_m_stol:		.BYTE	_S,_t,_o,_l,_eol
_m_pivo:		.BYTE	_P,_i,_v,_o,_eol

_m_alleya:		.BYTE	_A,_l,_l,_e,_ja,_eol
_m_banda:		.BYTE	_B,_a,_n,_d,_a,_eol
_m_dver:		.BYTE	_D,_v,_e,_r,_mz,_eol
_m_gorod:		.BYTE	_G,_o,_r,_o,_d,_eol
_m_govo:		.BYTE	_G,_o,_v,_o,_str,_eol
_m_kiyoko:		.BYTE	_K,_i,_jo,_k,_o,_eol
_m_kriv:		.BYTE	_K,_r,_i,_v,_str,_eol
_m_laser:		.BYTE	_L,_a,_z,_e,_r,_eol
_m_o_kei:		.BYTE	_O,__,_K,_e,_j,_eol
_m_orat:		.BYTE	_O,_r,_a,_t,_mz,_eol
_m_pere:		.BYTE	_P,_e,_r,_e,_str,_eol
_m_poka:		.BYTE	_P,_o,_k,_a,_str,_eol
_m_probra:		.BYTE	_P,_r,_o,_b,_str,_eol
_m_pryg:		.BYTE	_P,_r,_ji,_g,_str,_eol
_m_ryvok:		.BYTE	_R,_ji,_v,_o,_k,_eol
_m_shkola:		.BYTE	_SH,_k,_o,_l,_a,_eol
_m_shva:		.BYTE	_S,_h,_v,_a,_str,_eol
_m_smot:		.BYTE	_S,_m,_o,_t,_str,_eol
_m_tetsuo:		.BYTE	_T,_je,_c,_u,_o,_eol
_m_uvernu:		.BYTE	_U,_v,_e,_r,_str,_eol
_m_vzyat:		.BYTE	_V,_z,_ja,_t,_mz,_eol

_m_atako:		.BYTE	_A,_t,_a,_k,_o,_str,_eol
_m_bejat:		.BYTE	_B,_e,_zh,_a,_t,_mz,_eol
_m_vzglya:		.BYTE	_V,_z,_g,_l,_ja,_str,_eol
_m_vypit:		.BYTE	_V,_ji,_p,_i,_t,_mz,_eol
_m_vokrug:		.BYTE	_V,_o,_k,_r,_u,_g,_eol
_m_iskat:		.BYTE	_I,_s,_k,_a,_t,_mz,_eol
_m_pryata:		.BYTE	_P,_r,_ja,_t,_a,_str,_eol
_m_karman:		.BYTE	_K,_a,_r,_m,_a,_n,_eol
_m_kinut:		.BYTE	_K,_i,_n,_u,_t,_mz,_eol
_m_vernu:		.BYTE	_V,_e,_r,_n,_u,_str,_eol
_m_left:		.BYTE	_N,_a,_l,_e,_v,_o,_eol
_m_uznat:		.BYTE	_U,_z,_n,_a,_t,_mz,_eol
_m_masaru:		.BYTE	_M,_a,_s,_a,_r,_u,_eol
_m_mashina:		.BYTE	_M,_a,_sh,_i,_n,_a,_eol
_m_shumet:		.BYTE	_SH,_u,_m,_e,_t,_mz,_eol
_m_pover:		.BYTE	_P,_o,_v,_e,_r,_str,_eol
_m_terro:		.BYTE	_T,_e,_r,_r,_o,_str,_eol
_m_pologit:		.BYTE	_S,_p,_r,_o,_str,_eol					; _P,_o,_l,_o,_zh,_dot,_eol
_m_takashi:		.BYTE	_T,_a,_k,_a,_s,_i,_eol
_m_o_ter:		.BYTE	_O,__,_t,_e,_r,_str,_eol
_m_obyas:		.BYTE	_O,_b,_tz,_ja,_s,_str,_eol
_m_podbe:		.BYTE	_P,_o,_d,_b,_e,_str,_eol
_m_spisok:		.BYTE	_S,_p,_i,_s,_o,_k,_eol
_m_prove:		.BYTE	_P,_r,_o,_v,_e,_str,_eol

_m_ostano:		.BYTE	_O,_s,_t,_a,_n,_o,_str,_eol
_m_smejt:		.BYTE	_S,_m,_e,_ja,_t,_mz,_str,_eol
_m_polkov:		.BYTE	_P,_o,_l,_k,_o,_v,_str,_eol
_m_o_labo:		.BYTE	_O,__,_l,_a,_b,_o,_str,_eol
_m_ukryt:		.BYTE	_U,_k,_r,_ji,_t,_mz,_str,_eol
_m_molit:		.BYTE	_M,_o,_l,_i,_t,_mz,_str,_eol
_m_zapryg:		.BYTE	_Z,_a,_p,_r,_ji,_g,_str,_eol
_m_prigla:		.BYTE	_P,_r,_i,_g,_l,_a,_str,_eol
_m_prignu:		.BYTE	_P,_r,_i,_g,_n,_u,_str,_eol
_m_prodol:		.BYTE	_P,_r,_o,_d,_o,_l,_str,_eol
_m_razmysh:		.BYTE	_R,_a,_z,_m,_ji,_sh,_str,_eol
_m_ispol:		.BYTE	_I,_s,_p,_o,_l,_mz,_str,_eol
_m_paniko:		.BYTE	_P,_a,_n,_i,_k,_o,_str,_eol
_m_fanatka:		.BYTE	_F,_a,_n,_a,_t,_k,_a,_eol
_m_girl:		.BYTE	_D,_e,_v,_u,_sh,_k,_a,_eol
_m_yamagat:		.BYTE	_JA,_m,_a,_g,_a,_t,_a,_eol
_m_o_baike:		.BYTE	_O,__,_b,_a,_j,_k,_e,_eol
_m_spolzti:		.BYTE	_S,_p,_o,_l,_z,_t,_i,_eol
_m_voennyi:		.BYTE	_V,_o,_e,_n,_n,_ji,_j,_eol
_m_propusk:		.BYTE	_P,_r,_o,_p,_u,_s,_k,_eol
_m_stadion:		.BYTE	_S,_t,_a,_d,_i,_o,_n,_eol
_m_o_tecuo:		.BYTE	_O,__,_T,_je,_c,_u,_o,_eol
_m_right:		.BYTE	_N,_a,_p,_r,_a,_v,_o,_eol
_m_sovrat:		.BYTE	_S,_o,_v,_r,_a,_t,_mz,_eol
_m_nyrnut:		.BYTE	_N,_ji,_r,_n,_u,_t,_mz,_eol
_m_lstit:		.BYTE	_L,_mz,_s,_t,_i,_t,_mz,_eol
_m_krichat:		.BYTE	_K,_r,_i,_ch,_a,_t,_mz,_eol
_m_vibrat:		.BYTE	_V,_ji,_b,_r,_a,_t,_mz,_eol
_m_pozlit:		.BYTE	_P,_o,_z,_l,_i,_t,_mz,_eol
_m_otkryt:		.BYTE	_O,_t,_k,_r,_ji,_t,_mz,_eol
_m_podnyat:		.BYTE	_P,_o,_d,_n,_ja,_t,_mz,_eol
_m_glazet:		.BYTE	_G,_l,_a,_z,_e,_t,_mz,_eol
_m_udarit:		.BYTE	_U,_d,_a,_r,_i,_t,_mz,_eol
_m_skazat:		.BYTE	_S,_k,_a,_z,_a,_t,_mz,_eol
_m_prosit:		.BYTE	_P,_r,_o,_s,_i,_t,_mz,_eol
_m_pozvat:		.BYTE	_P,_o,_z,_v,_a,_t,_mz,_eol

_m______sa:		.BYTE	__,__,__,__,__,_s,_ja,_eol
_m_____nik:		.BYTE	__,__,__,__,_n,_i,_k,_eol
_m_____vat:		.BYTE	__,__,__,_v,_a,_t,_mz,_eol
_m_____jat:		.BYTE	__,__,__,_zh,_a,_t,_mz,_eol
_m_____jit:		.BYTE	__,__,__,_zh,_i,_t,_mz,_eol
_m_____zat:		.BYTE	__,__,__,_z,_a,_t,_mz,_eol
_m____lyat:		.BYTE	__,__,__,_l,_ja,_t,_mz,_eol
_m_____nit:		.BYTE	__,__,__,_n,_i,_t,_mz,_eol
_m_____nut:		.BYTE	__,__,__,_n,_u,_t,_mz,_eol
_m_____ret:		.BYTE	__,__,__,_r,_e,_t,_mz,_eol
_m_____rit:		.BYTE	__,__,__,_r,_i,_t,_mz,_eol
_m____ruki:		.BYTE	__,__,__,_r,_u,_k,_i,_eol
_m_____sit:		.BYTE	__,__,__,_s,_i,_t,_mz,_eol
_m_____tit:		.BYTE	__,__,__,_t,_i,_t,_mz,_eol
_m____tsya:		.BYTE	__,__,__,_t,_mz,_s,_ja,_eol
_m___akire:		.BYTE	__,__,_A,_k,_i,_r,_e,_eol
_m___risti:		.BYTE	__,__,_r,_i,_s,_t,_ji,_eol
_m__vitsya:		.BYTE	__,_v,_i,_t,_mz,_s,_ja,_eol
_m___gatsa:		.BYTE	__,_g,_a,_t,_mz,_s,_ja,_eol
_m__duraka:		.BYTE	__,_d,_u,_r,_a,_k,_a,_eol
_m___zovat:		.BYTE	__,_z,_o,_v,_a,_t,_mz,_eol
_m___lztsa:		.BYTE	__,_l,_ja,_t,_mz,_s,_ja,_eol
_m__na_kei:		.BYTE	_s,_i,_t,_mz,_K,_e,_j,_eol			; FIX ME!
_m__nutsya:		.BYTE	__,_n,_u,_t,_mz,_s,_ja,_eol
_m__pravdu:		.BYTE	__,_p,_r,_a,_v,_d,_u,_eol
_m__ratsya:		.BYTE	__,_r,_a,_t,_mz,_s,_ja,_eol
_m__vernut:		.BYTE	_v,_e,_r,_n,_u,_t,_mz,_eol
_m_voennih:		.BYTE	_v,_o,_e,_n,_n,_ji,_h,_eol
_m_ratorii:		.BYTE	_r,_a,_t,_o,_r,_i,_i,_eol
_m_rebenke:		.BYTE	_r,_e,_b,_jo,_n,_k,_e,_eol

_m_vklucit:		.BYTE	$42,$43,$44,$45,$46,$47,$48,_eol		; _V,_k,_l,_ju,_ch,_i,_t,_eol
_m_rorista:		.BYTE	$49,$4A,$4B,$4C,$4D,$4E,$4F,_eol		; _r,_o,_r,_i,_s,_t,_a,_eol
