
		INCLUDE		"..\macroses.inc"

;--------------------R-A-M----------------------

		ORG $0000

word_0:
		.BYTE   0,0
word_2:
		.BYTE   0,0
byte_4:
		.BYTE   0
byte_5:
		.BYTE   0
byte_6:
		.BYTE   0
byte_7:
		.BYTE   0
byte_9:
		.BYTE   0
byte_A:
		.BYTE   0
_spr_y_clip_flag:
		.BYTE   0
_tmp_idxF:
		.BYTE   0
word_11:
		.BYTE   0,0
_prg_bank_8000:
		.BYTE   0
_prg_bank_A000:
		.BYTE   0
_chr_bank01:
		.BYTE   0
_chr_bank23:
		.BYTE   0
_chr_bank4:
		.BYTE   0
_chr_bank5:
		.BYTE   0
_chr_bank6:
		.BYTE   0
_chr_bank7:
		.BYTE   0
_nmi_tmp_ptr:
		.BYTE   0,0
_ring0_tmp_ptr:
		.BYTE   0,0
_main_sub_idx:
		.BYTE   0
_nmi_mode_idx:
		.BYTE   0
_nmi_busy:
		.BYTE   0
_spr_buf_pos:
		.BYTE   0
_ppu_ctrl_shadow:
		.BYTE   0
_ppu_mask_shadow:
		.BYTE   0
_pads:
		.BYTE   0,0,0,0
_scroll_y_shadow:
		.BYTE   0,0
_scroll_x_shadow:
		.BYTE   0,0
_frames_counter:
		.BYTE   0,0
_rand:
		.BYTE   0
_intro0_pal_pos:
		.BYTE   0
_intro0_pal_cnt:
		.BYTE   0
byte_40:
		.BYTE   0
_cur_msg_col:
		.BYTE   0
_cur_msg_row:
		.BYTE   0
byte_47:
		.BYTE   0
_draw_state_idx:
		.BYTE   0
_scroll_y_adjust:
		.BYTE   0
_scene_idx:
		.BYTE   0
_scene_sub_cur:
		.BYTE   0
_nmi_ppu_draw_counter:
		.BYTE   0
_icon_tlm_idx:
		.BYTE   0
_icon_position_idx:
		.BYTE   0
_icon_cur_col_pos:
		.BYTE   0
byte_5C:
		.BYTE   0
_dictionary_str_idx:
		.BYTE   0
_dictionary_char_pos:
		.BYTE   0
_spr0_overflow_mode_flag:
		.BYTE   0
byte_60:
		.BYTE   0
_staff_scr_line_idx:
		.BYTE   0
_staff_screen_idx:
		.BYTE   0
_msg_wnd_scroll_y_shadow:
		.BYTE   0
_msg_wnd_scroll_x_shadow:
		.BYTE   0,0
_apu_tmp_ptr:
		.BYTE   0,0
_scene_sub_next:
		.BYTE   0
_scene_sub_reload:
		.BYTE   0
_scene_menu_idx:
		.BYTE   0
_scene_spr_overlay_idx:
		.BYTE   0
_scene_menu_max_pos:
		.BYTE   0
_scene_area_idx_tmp:
		.BYTE   0
_msg_display_number:
		.BYTE   0
_starting_area_num:
		.BYTE   0
_scene_sub_idx_pass:
		.BYTE   0
_scene_idx_pass:
		.BYTE   0
_retry_scene_sub_cur:
		.BYTE   0
_retry_scene_idx:
		.BYTE   0
_scene_states:
		.BYTE   0,0,0,0,0						; all used, only 4 saved in pass
_scene_flags:
		.BYTE   0,0,0,0,0						; only 3 used and saved in pass
_scene_anim_idx:
		.BYTE   0,0,0,0,0						; used 3, 4 saved in pass
_scene_anim_counter:
		.BYTE   0,0,0,0,0						; used 4, not saved in pass
_scene_anim_active:
		.BYTE   0,0,0,0							; only 3 used
_game_global_flags0:
		.BYTE   0
_game_global_flags1:
		.BYTE   0								; another global flag, never used in game, but saved restored in pass as 0
_scene_menu_items:
		.BYTE   0,0,0,0,0,0,0,0
_tmp_x_pos:
		.BYTE   0,0
_tmp_y_pos:
		.BYTE   0
_tmp_cnt0:
		.BYTE   0
_tmp_cnt1:
		.BYTE   0
word_320:
		.BYTE   0,0
_tlm_ptr:
		.BYTE   0,0
_tlm_tmp_line_dst:
		.BYTE   0,0

_sgame_shoot_enable:
		.BYTE   0
_sgame_turn_around_flag:
		.BYTE   0
_sgame_kaneda_bullet_active:
		.BYTE   0
_sgame_face_direction:
		.BYTE   0
_sgame_attack_direction:
		.BYTE   0
_sgame_behind_us_counter:
		.BYTE   0
_sgame_enemy_active_flag:
		.BYTE   0
_sgame_enemy_bullet_active:
		.BYTE   0
_sgame_enemy_main_timer:
		.BYTE   0
_sgame_enemy_bullet_main_timer:
		.BYTE   0
_sgame_enemy_y_pos:
		.BYTE   0
_sgame_enemy_x_pos:
		.BYTE   0
_sgame_enemy_bullet_y_pos:
		.BYTE   0
_sgame_enemy_bullet_x_pos:
		.BYTE   0
_sgame_kaneda_hidden_flag:
		.BYTE   0
_sgame_kaneda_bullet_y_dst:
		.BYTE   0
_sgame_kaneda_bullet_dir_x:
		.BYTE   0,0
_sgame_kaneda_bullet_dir_y:
		.BYTE   0,0
_sgame_kaneda_bullet_timer:
		.BYTE   0
_sgame_kaneda_bullet_delta_y:
		.BYTE   0,0
_sgame_kaneda_bullet_delta_x:
		.BYTE   0,0
_sgame_kaneda_bullet_y_pos:
		.BYTE   0
_sgame_kaneda_bullet_x_pos:
		.BYTE   0

_tmp_direction_x0:
		.BYTE   0,0
_tmp_direction_y0:
		.BYTE   0,0
_tmp_direction_x1:
		.BYTE   0,0
_tmp_direction_y1:
		.BYTE   0,0
_tmp_delta_y1:
		.BYTE   0,0
_tmp_delta_x1:
		.BYTE   0,0


_apu_test_idx:
		.BYTE	0
_apu_test_enable:
		.BYTE	0

_debug_tmp0:
		.BYTE	0

		ECHO "-------------"
		ECHO "zero ram free:",[$100-.]
		ECHO "-------------"

		ORG	$200

_spr_buf:
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

		ORG	$300

_pal_buf:
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
;word_320:										; moved to zero ram
		.BYTE   0,0
_ppu_tmp_buf1_dst:
		.BYTE   0,0
byte_324:
		.BYTE   0,0
_ppu_tmp_buf0_dst:
		.BYTE   0,0
_icon_col_dst:
		.BYTE   0,0
;_tlm_ptr:										; moved to zero ram
		.BYTE   0,0
;_tlm_tmp_line_dst:
		.BYTE   0,0
_cur_msg_char_ppu_ofs:
		.BYTE   0,0
_cur_msg_pos_increment:
		.BYTE   0
		.BYTE   0								; unused
		.BYTE   0								; unused
		.BYTE   0								; unused
		.BYTE   0								; unused
		.BYTE   0								; unused
		.BYTE   0								; unused
		.BYTE   0								; unused
		.BYTE   0
_cur_msg_pos:
		.BYTE   0,0
_cur_msg_ptr:
		.BYTE   0,0
_scene_menu_pos:
		.BYTE   0
_cur_msg_list_buf_pos:
		.BYTE   0
_screen_cursor_y:
		.BYTE   0,0
_screen_cursor_x:
		.BYTE   0,0
		.BYTE   0								; unused
_nmi_ppu_icon_draw_req:
		.BYTE   0
byte_345:
		.BYTE   0
		.BYTE   0								; unused
_type_fastforward:
		.BYTE   0
_nmi_ppu_draw0_req:
		.BYTE   0
_s1_gang_view_delay_counter:
		.BYTE   0
_active_areas_list_idx:
		.BYTE   0
byte_34B:
		.BYTE   0
byte_34C:
		.BYTE   0
_menu_is_drawn_flag:
		.BYTE   0
byte_34E:
		.BYTE   0
_scene_sub_return:
		.BYTE   0
byte_350:
		.BYTE   0
_tlm_draw_cur_lib_idx:
		.BYTE   0
_menu_attr_backup_line0_00:
		.BYTE   0
_menu_attr_backup_line0_01:
		.BYTE   0
_menu_attr_backup_line0_02:
		.BYTE   0
_menu_attr_backup_line1_00:
		.BYTE   0
_menu_attr_backup_line1_01:
		.BYTE   0
_menu_attr_backup_line1_02:
		.BYTE   0
_menu_attr_backup_line2_00:
		.BYTE   0
_menu_attr_backup_line2_01:
		.BYTE   0
_menu_attr_backup_line2_02:
		.BYTE   0
_unused_var0:
		.BYTE   0
_tlm_chr_col_draw_req:
		.BYTE   0
byte_35D:
		.BYTE   0
byte_35E:
		.BYTE   0
_menu_restore_tlm_idx_list:
		.BYTE   0,0
byte_361:
		.BYTE   0
byte_362:
		.BYTE   0
byte_363:
		.BYTE   0
byte_364:
		.BYTE   0
byte_365:
		.BYTE   0
byte_366:
		.BYTE   0
byte_367:
		.BYTE   0
word_368:
		.BYTE   0,0
_menu_attr_backup_line0_lo_ofs:
		.BYTE   0
_menu_attr_backup_line0_hi_ofs:
		.BYTE   0
_menu_attr_backup_line1_lo_ofs:
		.BYTE   0
_menu_attr_backup_line1_hi_ofs:
		.BYTE   0
_menu_attr_backup_line2_lo_ofs:
		.BYTE   0
_menu_attr_backup_line2_hi_ofs:
		.BYTE   0
		.BYTE   0
_menu_attr_backup_line0_A0:
		.BYTE   0
_menu_attr_backup_line0_A1:
		.BYTE   0
_menu_attr_backup_line0_A2:
		.BYTE   0
_menu_attr_backup_line1_A0:
		.BYTE   0
_menu_attr_backup_line1_A1:
		.BYTE   0
_menu_attr_backup_line1_A2:
		.BYTE   0
_menu_attr_backup_line2_A0:
		.BYTE   0
_menu_attr_backup_line2_A1:
		.BYTE   0
_menu_attr_backup_line2_A2:
		.BYTE   0
		.BYTE   0
_tlm_bank:
		.BYTE   0
_tlm_idx:
		.BYTE   0
_nmi_ppu_sgame_head_draw_req:
		.BYTE   0
_sgame_kaneda_hidden_delay:
		.BYTE   0
;_sgame_shoot_enable:
		.BYTE   0
;_sgame_turn_around_flag:
		.BYTE   0
;_sgame_enemy_active_flag:
		.BYTE   0
;_sgame_enemy_bullet_active:
		.BYTE   0
;_sgame_kaneda_bullet_active:
		.BYTE   0
;_sgame_face_direction:
		.BYTE   0
;_sgame_attack_direction:
		.BYTE   0
;_sgame_behind_us_counter:
		.BYTE   0
		.BYTE   0
_cur_msg_idx:
		.BYTE   0
_cur_msg_list_buf:
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
;_tmp_cnt0:
		.BYTE   0
_tmp_cnt2:
		.BYTE   0
		.BYTE   0
_msg_exit_delay_timer:
		.BYTE   0
		.BYTE   0
;_tmp_cnt1:
		.BYTE   0
_nmi_ppu_tlm_draw_req:
		.BYTE   0
_pass_char_pos_x:
		.BYTE   0
_pass_char_pos_y:
		.BYTE   0
		.BYTE   0
_pass_input_pos:
		.BYTE   0
_nmi_ppu_tlm_draw_len:
		.BYTE   0
		.BYTE   0								; unused
		.BYTE   0								; unused
		.BYTE   0								; unused
		.BYTE   0								; unused
_spr0_trigger_delay:
		.BYTE   0
		.BYTE   0
byte_3AB:
		.BYTE   0
_cur_scene_menu_pos:
		.BYTE   0
_forbid_sub_cur_backup_trigger:
		.BYTE   0
;_game_global_flags1:
		.BYTE   0
		.BYTE   0
_menu_attr_backup_line0_A_ofs:
		.BYTE   0
		.BYTE   0
_menu_attr_backup_line1_A_ofs:
		.BYTE   0
		.BYTE   0
_menu_attr_backup_line2_A_ofs:
		.BYTE   0
_bad_ending_flag:
		.BYTE   0
byte_3B6:
		.BYTE   0
_text_typing_snd_disable:
		.BYTE   0
byte_3B8:
		.BYTE   0
;_sgame_kaneda_hidden_flag:
;		.BYTE   0
;_sgame_kaneda_bullet_y_dst:
;		.BYTE   0
		.BYTE   0
		.BYTE   0
byte_3BD:
		.BYTE   0
_keep_tetsuo_overlay_for_ending_flag:
		.BYTE   0
		.BYTE   0
_scene_sub_save_pass:
		.BYTE   0
_forbid_ending_overlays_flag:
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0	; unused
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0
_ppu_tmp_row_buf:
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
_ppu_tmp_buf0:
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_ppu_tmp_buf1:
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_char_extra_tile:
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
_menu_wnd_row_buf1:
		.BYTE   0,0,0,0,0,0,0,0,0,0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
_char_main_tile:
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
_tlm_col_buf:
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_menu_wnd_row_buf0:
		.BYTE   0,0,0,0,0,0,0,0,0,0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0,0,0,0,0,0,0,0					; unused
_icon_col_buf:
		.BYTE   0,0,0,0,0,0,0,0
		.BYTE   0
		.BYTE   0,0								; unused
		.BYTE   0								; unused
		.BYTE   0								; unused
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
;_tmp_direction_x0:
		.BYTE   0,0
		.BYTE   0
;_tmp_direction_y0:
		.BYTE   0,0
		.BYTE   0
;_sgame_enemy_main_timer:
		.BYTE   0
byte_529:
		.BYTE   0
;_tmp_direction_x1:
		.BYTE   0,0
byte_52C:
		.BYTE   0
;_tmp_direction_y1:
		.BYTE   0,0
byte_52F:
		.BYTE   0
		.BYTE   0
;_sgame_enemy_bullet_main_timer:
		.BYTE   0
;byte_532:										; unused
		.BYTE   0
;_sgame_kaneda_bullet_dir_x:
		.BYTE   0,0
;byte_535:										; unused
		.BYTE   0
;_sgame_kaneda_bullet_dir_y:
		.BYTE   0,0
;byte_538:										; unused
		.BYTE   0
		.BYTE   0
;_sgame_kaneda_bullet_timer:
		.BYTE   0
byte_53B:
		.BYTE   0
		.BYTE   0,0,0,0,0,0,0,0					; unused
		.BYTE   0,0,0,0,0,0,0,0					; unused
		.BYTE   0,0,0,0,0,0,0,0					; unused
		.BYTE   0,0,0,0,0,0,0,0					; unused
		.BYTE   0,0,0,0,0,0,0,0					; unused
;_tmp_delta_y1:
		.BYTE   0,0
;_tmp_delta_x1:
		.BYTE   0,0
;_sgame_kaneda_bullet_delta_y:
		.BYTE   0,0
;_sgame_kaneda_bullet_delta_x:
		.BYTE   0,0
;_sgame_enemy_y_pos:
		.BYTE   0
;_sgame_enemy_x_pos:
		.BYTE   0
;_sgame_enemy_bullet_y_pos:
		.BYTE   0
;_sgame_enemy_bullet_x_pos:
		.BYTE   0
;_sgame_kaneda_bullet_y_pos:
		.BYTE   0
;_sgame_kaneda_bullet_x_pos:
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
		.BYTE   0
_pass_tmp:
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0
		.BYTE   0
_format_buf:
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0

		ORG	$600

_apu_bufs:
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE   0,0
byte_6D2:
		.BYTE   0
byte_6D3:
		.BYTE   0
byte_6D4:
		.BYTE   0
byte_6D5:
		.BYTE   0
_apu_status_mask:
		.BYTE   0
byte_6D7:
		.BYTE   0
byte_6D8:
		.BYTE   0
byte_6D9:
		.BYTE   0
byte_6DA:
		.BYTE   0

		ORG	$7FF
_end_of_RAM:
		.BYTE   0

		ORG $2000

_PPU_CTRL:
		.BYTE 0
_PPU_MASK:
		.BYTE 0
_PPU_STATUS:
		.BYTE 0
_PPU_OAM_ADDR:
		.BYTE 0
_PPU_OAM_DATA:
		.BYTE 0
_PPU_SCROLL:
		.BYTE 0
_PPU_ADDR:
		.BYTE 0
_PPU_DATA:
		.BYTE 0

		ORG $4000

_APU_PULSE1_ENV:
		.BYTE 0
_APU_PULSE1_SWEEP:
		.BYTE	0
_APU_PULSE1_TIME:
		.BYTE 0
_APU_PULSE1_LEN:
		.BYTE 0
_APU_PULSE2_ENV:
		.BYTE 0
_APU_PULSE2_SWEEP:
		.BYTE	0
_APU_PULSE2_TIME:
		.BYTE 0
_APU_PULSE2_LEN:
		.BYTE 0
_APU_TRI_COUNT:
		.BYTE 0
_APU_TRI_UNUSED:
		.BYTE 0
_APU_TRI_TIME:
		.BYTE 0
_APU_TRI_LEN:
		.BYTE 0
_APU_NOISE_ENV:
		.BYTE 0
_APU_NOISE_UNUSED:
		.BYTE 0
_APU_NOISE_LOOP:
		.BYTE 0
_APU_NOISE_LEN:
		.BYTE 0
_APU_DMC_FREQ:
		.BYTE 0
_APU_DMC_LOAD:
		.BYTE 0
_APU_DMC_ADDR:
		.BYTE 0
_APU_DMC_LEN:
		.BYTE 0
_PPU_OAM_DMA:
		.BYTE 0
_APU_STATUS:
		.BYTE 0
_PAD0_REG:
		.BYTE 0
_PAD1_REG:
		.BYTE 0

;--------------------C-H-R----------------------
; virtual CHR data to get proper indexes of tilemaps
;
		ORG $6000

		INCLUDE "..\tlm\tlm.inc"
