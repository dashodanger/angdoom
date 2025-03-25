/* File: externs.h */

#pragma once

void vectorize();

void player_place(int y, int x);

void place_trap(int y, int x);

void place_gold(int y, int x);

void place_object(int y, int x, bool good, bool great);

bool place_monster(int y, int x, bool slp, bool grp);

bool alloc_monster(int dis, int slp);

int16_t Rand_normal(int mean, int stand);

/*
 * Automatically generated "variable" declarations
 */

/* tables.c */
extern int16_t ddd[9];
extern int16_t ddx[10];
extern int16_t ddy[10];
extern int16_t ddx_ddd[9];
extern int16_t ddy_ddd[9];
extern char hexsym[16];
extern uint8_t adj_mag_study[];
extern uint8_t adj_mag_mana[];
extern uint8_t adj_mag_fail[];
extern uint8_t adj_mag_stat[];
extern uint8_t adj_chr_gold[];
extern uint8_t adj_int_dev[];
extern uint8_t adj_wis_sav[];
extern uint8_t adj_dex_dis[];
extern uint8_t adj_int_dis[];
extern uint8_t adj_dex_ta[];
extern uint8_t adj_str_td[];
extern uint8_t adj_dex_th[];
extern uint8_t adj_str_th[];
extern uint8_t adj_str_wgt[];
extern uint8_t adj_str_hold[];
extern uint8_t adj_str_dig[];
extern uint8_t adj_str_blow[];
extern uint8_t adj_dex_blow[];
extern uint8_t adj_dex_safe[];
extern uint8_t adj_con_fix[];
extern uint8_t adj_con_mhp[];
extern uint8_t blows_table[12][12];
extern uint8_t extract_energy[200];
extern int32_t player_exp[PY_MAX_LEVEL];
extern uint32_t spell_flags[2][9][2];
extern const char * spell_names[2][64];
extern uint8_t chest_traps[64];
extern const char * color_names[16];
extern const char * stat_names[6];
extern const char * stat_names_reduced[6];
extern const char * window_flag_desc[32];
extern const char * option_text[OPT_MAX];
extern const char * option_desc[OPT_MAX];
extern bool option_norm[OPT_MAX];
extern uint8_t option_page[4][16];

/* variable.c */
extern const char * copyright[5];
extern uint8_t version_major;
extern uint8_t version_minor;
extern uint8_t version_patch;
extern uint8_t version_extra;
extern uint8_t sf_major;
extern uint8_t sf_minor;
extern uint8_t sf_patch;
extern uint8_t sf_extra;
extern uint32_t sf_xtra;
extern uint32_t sf_when;
extern uint16_t sf_lives;
extern uint16_t sf_saves;
extern bool arg_fiddle;
extern bool arg_wizard;
extern bool arg_sound;
extern bool arg_graphics;
extern bool arg_force_original;
extern bool arg_force_roguelike;
extern bool character_generated;
extern bool character_dungeon;
extern bool character_loaded;
extern bool character_saved;
extern int16_t character_icky;
extern int16_t character_xtra;
extern uint32_t seed_flavor;
extern uint32_t seed_town;
extern int16_t num_repro;
extern int16_t object_level;
extern int16_t monster_level;
extern int32_t turn;
extern int32_t old_turn;
extern bool use_sound;
extern bool use_graphics;
extern int16_t signal_count;
extern bool msg_flag;
extern bool inkey_base;
extern bool inkey_xtra;
extern bool inkey_scan;
extern bool inkey_flag;
extern int16_t coin_type;
extern bool opening_chest;
extern bool shimmer_monsters;
extern bool shimmer_objects;
extern bool repair_mflag_born;
extern bool repair_mflag_nice;
extern bool repair_mflag_show;
extern bool repair_mflag_mark;
extern int16_t o_max;
extern int16_t o_cnt;
extern int16_t m_max;
extern int16_t m_cnt;
extern int16_t feeling;
extern int16_t rating;
extern bool good_item_flag;
extern bool closing_flag;
extern int player_uid;
extern int player_euid;
extern int player_egid;
extern char savefile[1024];
extern int16_t macro__num;
extern const char * *macro__pat;
extern const char * *macro__act;
extern int16_t quark__num;
extern const char * *quark__str;
extern uint16_t message__next;
extern uint16_t message__last;
extern uint16_t message__head;
extern uint16_t message__tail;
extern uint16_t *message__ptr;
extern char *message__buf;
extern char angband_term_name[8][16];
extern uint8_t angband_color_table[256][4];
extern char angband_sound_name[SOUND_MAX][16];
extern int32_t view_n;
extern uint16_t *view_g;
extern int32_t temp_n;
extern uint16_t *temp_g;
extern uint8_t *temp_y;
extern uint8_t *temp_x;
extern uint8_t cave_info[DUNGEON_HGT][256];
extern uint8_t cave_feat[DUNGEON_HGT][DUNGEON_WID];
extern int16_t cave_o_idx[DUNGEON_HGT][DUNGEON_WID];
extern int16_t cave_m_idx[DUNGEON_HGT][DUNGEON_WID];
extern int cave_sector_map[DUNGEON_HGT][DUNGEON_WID];
extern int sector_counter;

extern int16_t alloc_kind_size;
extern int16_t alloc_race_size;
extern uint8_t misc_to_attr[256];
extern char misc_to_char[256];
extern uint8_t tval_to_attr[128];
extern char macro_buffer[1024];
extern const char * keymap_act[KEYMAP_MODES][256];

/*
 * Automatically generated "function declarations"
 */

/* birth.c */
extern void player_birth(void);

/* cave.c */
extern int32_t distance(int y1, int x1, int y2, int x2);
extern bool los(int y1, int x1, int y2, int x2);
extern bool no_lite(void);
extern bool cave_valid_bold(int y, int x);
extern void map_info(int y, int x, uint8_t *ap, char *cp);
extern void move_cursor_relative(int y, int x);
extern void print_rel(char c, uint8_t a, int y, int x);
extern void note_spot(int y, int x);
extern void lite_spot(int y, int x);
extern void prt_map(void);
extern void display_map(int *cy, int *cx);
extern void do_cmd_view_map(void);
extern int vinfo_init(void);
extern void forget_view(void);
extern void update_view(void);
extern void forget_flow(void);
extern void update_flow(void);
extern void map_area(void);
extern void wiz_lite(void);
extern void wiz_dark(void);
extern void town_illuminate(bool daytime);
extern void cave_set_feat(int y, int x, int feat);
extern int32_t project_path(uint16_t *gp, int range, \
                         int y1, int x1, int y2, int x2, int flg);
extern bool projectable(int y1, int x1, int y2, int x2);
extern void scatter(int *yp, int *xp, int y, int x, int d, int m);
extern void health_track(int m_idx);
extern void monster_race_track(int r_idx);
extern void object_kind_track(int k_idx);
extern void disturb(int stop_search, int unused_flag);
extern bool is_quest(int level);


/* generate.c */
extern void generate_cave(void);

/* main.c */
/* extern int main(int argc, char *argv[]); */


