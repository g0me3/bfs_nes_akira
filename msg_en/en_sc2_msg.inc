
		SECTION_START	F2

		MSG_START	_scene2_msg_lib
		MSG_IDX	_sc2_msg00
		MSG_IDX	_sc2_msg01
		MSG_IDX	_sc2_msg02
		MSG_IDX	_sc2_msg03
		MSG_IDX	_sc2_msg04
		MSG_IDX	_sc2_msg05
		MSG_IDX	_sc2_msg06
		MSG_IDX	_sc2_msg07
		MSG_IDX	_sc2_msg08
		MSG_IDX	_sc2_msg09
		MSG_IDX	_sc2_msg0A
		MSG_IDX	_sc2_msg0B
		MSG_IDX	_sc2_msg0C
		MSG_IDX	_sc2_msg0D
		MSG_IDX	_sc2_msg0E
		MSG_IDX	_sc2_msg0F
		MSG_IDX	_sc2_msg10
;		MSG_IDX	_sc2_msg11						; -unused-
		MSG_IDX	_sc2_msg12
		MSG_IDX	_sc2_msg13
		MSG_IDX	_sc2_msg14
		MSG_IDX	_sc2_msg15
		MSG_IDX	_sc2_msg16
		MSG_IDX	_sc2_msg17
		MSG_IDX	_sc2_msg18						; restored unused terrorist speech
		MSG_IDX	_sc2_msg19
		MSG_IDX	_sc2_msg1A
;		.WORD	0								; dummy unused copy of 1C. but english translators
		MSG_IDX	_sc2_msg1C						; for some reason mistakenly translated it as 1C,
		MSG_IDX	_sc2_msg1D						; then got all messages shifted so 1B turns 1C
		MSG_IDX	_sc2_msg1E						; and obviously unused and missed from the game
		MSG_IDX	_sc2_msg1F						; 1C turns 1D, first part of 1F gone to 1E, making
		MSG_IDX	_sc2_msg20						; the Army line start before he even appears
		MSG_IDX	_sc2_msg21						; fixed it here
		MSG_IDX	_sc2_msg22
		MSG_IDX	_sc2_msg23
		MSG_IDX	_sc2_msg24
		MSG_IDX	_sc2_msg25
		MSG_IDX	_sc2_msg26
		MSG_IDX	_sc2_msg27
		MSG_IDX	_sc2_msg28
		MSG_IDX	_sc2_msgA2						; scene 2 msg
		MSG_IDX	_sc2_msgBA						; scene 2 msg
;		MSG_IDX	_sc2_msg29						; -unused-
_sc2_msg00:
		.BYTE	_W,_e_,_were_,_b,_r,_ou,_g,_h,_t_,_ou,_t,_s,_id,_e,__the,_ret
		.BYTE	_en,_t,_r,_an,_c,_e_,_of,__the,__i,_n,_t,_er,_ro,_g,_at,_i,_on,_ret
		.BYTE	_ro,_o,_m,_dot,_ret
		.BYTE	_ret
		.BYTE	_Army,_ddt_,_J,_u,_st,__w,_a,_it,__,_her,_e,_dot_dot_dot,_ret
		.BYTE	_N,_e,_x,_t,_exc,__,_G,_e,_t,__i,_n,__,_her,_e,_exc,_eol
_sc2_msg01:
		.BYTE	_P,_ro,_t,_e,_st,_ing,__,_st,_u,_d,_en,_t,_s_,_and,_ret
		.BYTE	_Terrorist,_s_,_are,__,_c,_a,_u,_s,_ing,__a,_n,_ret
		.BYTE	_u,_p,_ro,_ar,_dot,_ret
		.BYTE	_ret
		.BYTE	_Yamagata,_ddt_,_The,_y,_apo,_re,__a,_c,_t,_ing,__,_l,_i,_k,_e,_ret
		.BYTE	_it,_apo_s,__a,__,_p,_i,_c,_n,_i,_c,_exc,_eol
_sc2_msg02:
		.BYTE	_L,_oo,_k,_s_,_l,_i,_k,_e,__the,_y,_apo,_re,__,_u,_s,_ing,_ret
		.BYTE	_t,_he,__g,_y,_m,__a,_s,__a,__,_m,_a,_k,_e,_s,_h,_i,_f,_t,_ret
		.BYTE	_in,_t,_er,_ro,_g,_at,_i,_on,__,_are,_a,_col,__,_c,_o,_m,_p,_le,_t,_e,_ret
		.BYTE	_with,__,_p,_l,_y,_w,_oo,_d_,_w,_a,_ll,_s,_dot,_eol
_sc2_msg03:
		.BYTE	_S,_o,__the,_n,__,_he,__s,_a,_id,_dot_dot_dot,_eol
_sc2_msg04:
		.BYTE	_O,_h,__,_y,_e,_a,_h,_que,__,_A,_n,_d,__the,_n,__w,_hat,_que,_eol
_sc2_msg05:
		.BYTE	_The,_re,_apo_s,__,_l,_o,_t,_s_,_of,__,_n,_o,_i,_se,__,_c,_o,_m,_ing,_ret
		.BYTE	_f,_ro,_m,__,_be,_h,_in,_d,__t,_hat,__,_d,_oo,_r,_dot,_eol
_sc2_msg06:
		.BYTE	_W,_e,_apo,_re,__,_f,_re,_ed,_o,_m,__,_f,_ight,_er,_s,_dot,_eol
_sc2_msg07:
		.BYTE	_I_,_n,_e,_ed,__a,__,_d,_o,_c,_t,_or,_exc,_eol
_sc2_msg08:
		.BYTE	_I_,_g,_o,_t,_t,_a,__,_p,_e,_e,_exc,_eol
_sc2_msg09:
		.BYTE	_I_apo,_m,__,_st,_ar,_v,_ing,_exc,_eol
_sc2_msg0A:
		.BYTE	_Kaneda,_ddt_,_H,_m,_m,_dot_dot_dot,__,_I_apo,_ve,__,_se,_en,__,_this,_ret
		.BYTE	_p,_er,_s,_on,__,_before,__s,_o,_me,_w,_her,_e,_dot_dot_dot,_eol
_sc2_msg0B:
		.BYTE	_Kaneda,_ddt_,_O,_h,_exc,__,_It_apo_s,__t,_hat,__g,_irl,_ret
		.BYTE	_f,_ro,_m,__,_before,_exc,__,_I_,_s,_h,_ou,_l,_d_,_a,_s,_k,__,_her,_ret
		.BYTE	_ou,_t_,_for,__a,__,_d,_r,_in,_k,_dot,_eol
_sc2_msg0C:
		.BYTE	_W,_h,_en,__,_I_,_t,_r,_i,_ed,__,_to_,_t,_a,_l,_k,__,_to_,_t,_he,_ret
		.BYTE	_g,_irl,_col,__a,__,_Terrorist,__,_st,_oo,_d_,_u,_p,__,_and,_ret
		.BYTE	_p,_u,_ll,_ed,__the,__,_p,_in,__,_on,__,_his,__g,_re,_n,_ad,_e,_exc,_eol
_sc2_msg0D:
		.BYTE	_The,__,_Army,__s,_o,_l,_d,_i,_er,_s_,_were_,_h,_o,_l,_d,_ing,_ret
		.BYTE	_t,_he,__,_Terrorist,_apo_s,__g,_re,_n,_ad,_e,_dot,_eol
_sc2_msg0E:
		.BYTE	_Kai,_ddt_,_S,_o,__,_it,__,_se,_e,_m,_s,__the,__,_Army,__i,_s,_ret
		.BYTE	_w,_or,_k,_ing,__,_with,__the,__,_p,_o,_l,_i,_c,_e_,_t,_o,_ret
		.BYTE	_h,_u,_n,_t_,_d,_ow,_n,__,_Terrorist,__g,_r,_ou,_p,_s,_dot,_ret
		.BYTE	_G,_re,_at,_dot,_eol
_sc2_msg0F:
		.BYTE	_The,__,_Akira,__,_N,_E,_S,__g,_a,_me,__i,_s_,_n,_ow,_ret
		.BYTE	_in,__,_E,_n,_g,_l,_i,_s,_h,_exc,_eol
_sc2_msg10:
		.BYTE	_Kaneda,_ddt_,_H,_e,_y,_col,__,_Yamagata,_exc,_ret
		.BYTE	_L,_e,_t,_apo_s,__,_r,_u,_n,__,_for,__,_it,_exc,_ret
		.BYTE	_ret
		.BYTE	_Yamagata,_ddt_,_Y,_e,_a,_h,_exc,_ret
		.BYTE	_L,_e,_t,_apo_s,__g,_o,_col,__g,_u,_y,_s,_exc,_ret
		.BYTE	_ret
		.BYTE	_Army,_ddt_,_H,_e,_y,__,_you,_exc,__,_S,_t,_o,_p,_exc,_ret
		.BYTE	_The,_y,_apo,_re,__,_e,_s,_c,_a,_p,_ing,_exc,_eol
_sc2_msg12:
		.BYTE	_Kaneda,_ddt_,_Y,_ou,__,_d,_u,_m,_b,__s,_on,__of,__a,_ret
		.BYTE	_b,_it,_c,_h,_exc,__,_H,_and,__t,_hat,__,_o,_ve,_r,_exc,_ret
		.BYTE	_ret
		.BYTE	_I_,_s,_p,_r,_u,_n,_g,__,_u,_p,_on,__,_h,_i,_m,_col,__t,_r,_y,_ing,__t,_o,_ret
		.BYTE	_st,_e,_a,_l,__,_his,__g,_re,_n,_ad,_e,_dot,_eol
_sc2_msg13:
		.BYTE	_But,__the,_n,__,_it,__,_e,_x,_p,_l,_o,_d,_ed,_dot_dot_dot,_eol
_sc2_msg14:
		.BYTE	_O,_h,_col,__w,_ow,_dot,__,_It_apo_s,__a,__,_c,_u,_t,_e_,_g,_irl,_exc,_ret
		.BYTE	_ret
		.BYTE	_I_,_s,_h,_ou,_l,_d,__t,_r,_y,__a,_s,_k,_ing,__,_her,__,_ou,_t,_exc,_eol
_sc2_msg15:
		.BYTE	_Kaneda,_ddt_,_E,_veryone,__t,_a,_k,_e_,_c,_o,_ve,_r,_exc,_ret
		.BYTE	_ret
		.BYTE	_H,_e,_ar,_ing,__,_m,_y,__s,_h,_ou,_t,_col,__,_m,_y,__,_c,_on,_f,_u,_s,_ed,_ret
		.BYTE	_f,_r,_i,_en,_d,_s,__t,_oo,_k,__,_c,_o,_ve,_r,__,_on,__the,_ret
		.BYTE	_g,_r,_ou,_n,_d_,_and,__w,_at,_c,_h,_ed,__,_to_,_se,_e_,_w,_hat,_ret
		.BYTE	_w,_ou,_l,_d_,_ha,_p,_p,_en,_dot,_eol
_sc2_msg16:
		.BYTE	_O,_n,__,_1,_2,_sla,_2,_5,_col,__the,_re,_apo_s,__a,__,_L,_i,_l,_y,_ret
		.BYTE	_M,_at,_s,_u,_z,_a,_k,_a,__,_c,_on,_c,_er,_t,_que,__,_I,_n,__the,__g,_y,_m,_que,_ret
		.BYTE	_W,_h,_o,__i,_s,__s,_he,__a,_n,_y,_w,_a,_y,_que,_eol
_sc2_msg17:
		.BYTE	_Army,_ddt_,_H,_e,_y,_exc,__,_You_apo_re,__i,_n,__the,__w,_a,_y,_exc,_ret
		.BYTE	_M,_o,_ve,__,_it,_exc,_eol
_sc2_msg18:
		.BYTE	_S,_t,_u,_d,_en,_t,_ddt_,_an0,_L,_on,_g,__,_l,_i,_ve,__the,_ret
		.BYTE	_F,_re,_ed,_o,_m,__,_R,_e,_v,_o,_l,_u,_t,_i,_on,_exc,__,_B,_an,_z,_a,_i,_exc,_aof,_ret
		.BYTE	_ret
		.BYTE	_T,_h,_i,_dot_dot_dot,_T,_his,__i,_s_,_b,_ad,_exc,_eol
_sc2_msg19:
		.BYTE	_Kaneda,_ddt_,_D,_on,_apo,_t_,_j,_u,_st,__,_st,_and,_ret
		.BYTE	_around,__,_with,__,_you,_r,__t,_h,_u,_m,_b,_s,__i,_n,_ret
		.BYTE	_you,_r,__a,_s,_se,_s,_exc,__,_E,_veryone,__t,_a,_k,_e,_ret
		.BYTE	_c,_o,_ve,_r,_exc,_eol
_sc2_msg1A:
		.BYTE	_Army,_ddt_,_Y,_ou,__,_m,_u,_st,__,_be,__,_on,_e_,_of,__t,_h,_o,_se,_ret
		.BYTE	_g,_u,_y,_s_,_f,_ro,_m,__t,_hat,__,_c,_r,_a,_z,_y,__,_n,_e,_w,__,_c,_u,_l,_t,_exc,_ret
		.BYTE	_You_apo_re,__,_c,_o,_m,_ing,__,_with,__,_u,_s,_exc,_eol
_sc2_msg1C:
		.BYTE	_Army,_ddt_,_It_apo_s,__a,__,_d,_u,_d,_exc,__,_G,_e,_t_,_h,_i,_m,_exc,_ret
		.BYTE	_ret
		.BYTE	_S,_t,_u,_d,_en,_t,_ddt_,_A,_h,_dot_dot_dot,_ret
		.BYTE	_I,_str,_str,_I_apo,_m,__s,_o,__s,_or,_r,_y,_exc,_ret
		.BYTE	_ret
		.BYTE	_The,__,_st,_u,_d,_en,_t_,_was,__s,_u,_r,_r,_ou,_n,_d,_ed,_dot,_eol
_sc2_msg1D:
		.BYTE	_T,_h,_u,_d,_exc,__,_O,_of,_exc,__,_S,_q,_u,_i,_s,_h,_exc,_ret
		.BYTE	_ret
		.BYTE	_Army,_ddt_,_T,_hat,_apo_s,__,_en,_ou,_g,_h,_dot,__,_B,_r,_ing,_ret
		.BYTE	_h,_i,_m,__,_with,__,_u,_s,_dot,__,_W,_e,_apo,_ll,__t,_e,_a,_c,_h,__,_h,_i,_m,_ret
		.BYTE	_a,__,_le,_s,_s,_on,_dot,_eol
_sc2_msg1E:
		.BYTE	_Yamagata,_ddt_,_Y,_ou,__,_d,_u,_m,_b,_a,_s,_s,_exc,__,_I,_f,__,_you,_ret
		.BYTE	_w,_an,_t_,_to_,_d,_i,_e,_col,__w,_h,_y,__,_d,_on,_apo,_t_,_you,_ret
		.BYTE	_h,_an,_g,__,_you,_r,_se,_l,_f,_exc,_eol
_sc2_msg1F:
		.BYTE	_Army,_ddt_,_an0,_Y,_ou,__g,_u,_y,_s_,_are,__,_f,_re,_e_,_t,_o,_ret
		.BYTE	_le,_a,_ve,_dot,__,_W,_e,_apo,_ve,__,_c,_on,_t,_a,_c,_t,_ed,__,_you,_r,_ret
		.BYTE	_s,_c,_h,_oo,_l,_dot,_aof,_eol
		.BYTE	_ret
		.BYTE	_W,_on,_d,_er,__i,_f,__the,_re,_apo_s,__a,__w,_a,_y,__t,_o,_ret
		.BYTE	_f,_re,_e_,_t,_hat,__g,_irl,_col,__t,_oo,_dot_dot_dot,_eol
_sc2_msg20:
		.BYTE	_A,_ll,__of,__a,__s,_u,_d,_d,_en,_col,__the,__g,_re,_n,_ad,_e,_ret
		.BYTE	_I_,_t,_h,_ou,_g,_h,_t_,_was,__a,__,_d,_u,_d_,_e,_x,_p,_l,_o,_d,_ed,_exc,_eol
_sc2_msg21:
		.BYTE	_Kaneda,_ddt_,_U,_h,_str,_o,_h,_dot_dot_dot,__,_H,_er,__t,_u,_r,_n,_apo_s,_ret
		.BYTE	_p,_ro,_b,_a,_b,_l,_y,__,_c,_o,_m,_ing,__,_u,_p,_dot,_eol
_sc2_msg22:
		.BYTE	_S,_he,__,_se,_e,_m,_s_,_n,_er,_v,_ou,_s,_dot,_ret
		.BYTE	_A,_w,_w,_col,__,_and,__,_it,__,_l,_oo,_k,_s_,_l,_i,_k,_e_,_s,_he,_apo_s,_ret
		.BYTE	_a,_b,_ou,_t_,_to_,_c,_r,_y,_dot_dot_dot,_eol
_sc2_msg23:
		.BYTE	_E,_veryone,__,_se,_e,_m,_s,__i,_m,_p,_at,_i,_en,_t,_dot,_ret
		.BYTE	_It_apo_s,__a,_l,_m,_o,_st,__t,_hat,__g,_irl,_apo_s,__t,_u,_r,_n,_dot,_ret
		.BYTE	_I_,_w,_an,_t_,_to_,_g,_e,_t_,_her,__,_ou,_t,__s,_o,_me,_h,_ow,_dot,_eol
_sc2_msg24:
		.BYTE	_Kaneda,_ddt_,_H,_e,_y,__g,_r,_a,_m,_p,_s,_exc,__,_S,_he,_apo_s,__,_on,_e,_ret
		.BYTE	_of,__,_m,_y,__,_b,_u,_d,_d,_i,_e,_s,_col,__t,_oo,_dot,__,_I_,_c,_an,_apo,_t,_ret
		.BYTE	_le,_a,_ve,__a,__,_f,_r,_i,_en,_d_,_be,_h,_in,_d,_dot,_ret
		.BYTE	_ret
		.BYTE	_Army,_ddt_,_an0,_W,_hat,_que,_exc,_aof,_eol
_sc2_msg25:
		.BYTE	_Army,_ddt_,_an0,_W,_h,_o,__,_are,__,_you,__,_c,_a,_ll,_ing,_ret
		.BYTE	_g,_r,_a,_m,_p,_s,_col,__,_you,__,_l,_it,_t,_le,__s,_h,_it,_exc,_ret
		.BYTE	_L,_i,_st,_en,__,_her,_e,_col,__,_k,_id,_dot,__,_I_apo,_m,__,_on,_l,_y,__,_2,_5,_col,_ret
		.BYTE	_and,__,_I_apo,_m,__,_n,_o,_t_,_e,_ve,_n,__,_m,_ar,_r,_i,_ed,__,_y,_e,_t,_exc,_ret
		.BYTE	_S,_o,__w,_at,_c,_h,__,_you,_r,__,_d,_a,_m,_n,__,_m,_ou,_t,_h,_exc,_aof,_eol
_sc2_msg26:
		.BYTE	_Army,_ddt_,_an0,_G,_e,_t_,_ou,_t_,_of,__,_her,_e,_col,__,_and,_ret
		.BYTE	_t,_a,_k,_e_,_you,_r,__,_f,_r,_i,_en,_d_,_with,__,_you,_exc,_aof,_eol
_sc2_msg27:
		.BYTE	_A,_ll,__,_r,_ight,_exc,__,_W,_e_,_c,_an,__,_le,_a,_ve,__the,_ret
		.BYTE	_g,_y,_m,__,_n,_ow,_dot,__,_A,_n,_d_,_w,_e,_apo,_ve,__g,_o,_t_,_her,_ret
		.BYTE	_with,__,_u,_s,__t,_oo,_exc,_eol
_sc2_msg28:
		.BYTE	_Kaneda,_ddt_,_I,_s,__s,_he,__,_p,_l,_an,_n,_ing,__,_on,_ret
		.BYTE	_st,_a,_y,_ing,__,_her,_e,_que,_eol
_sc2_msgA2:
		.BYTE	_Kaneda,_ddt_,_M,_str,_m,_o,_m,_m,_y,_col,__s,_a,_ve,__,_me,_exc,_eol
_sc2_msgBA:
		.BYTE	_S,_t,_u,_d,_en,_t,_ddt_,_dot_dot_dot,_dot,_H,_u,_h,_que,_eol

;_sc2_msg11:
;		.BYTE	_The,__,_Army,__,_c,_a,_p,_t,_u,_r,_ed,__,_Kaneda,__,_and,_ret
;		.BYTE	_his,__,_f,_r,_i,_en,_d,_s,_dot,_ret
;		.BYTE	_ret
;		.BYTE	_The,_y,__,_were_,_s,_en,_t_,_to_,_a,__,_re,_for,_m,_ret
;		.BYTE	_s,_c,_h,_oo,_l,_dot,_eol
;_sc2_msg29:
;		.BYTE	_Kaneda,_ddt_,_H,_e,_he,_col,__s,_or,_r,_y,_exc,_eol

		SECTION_END		F2
