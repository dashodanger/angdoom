/* File: externs.h */

void vectorize();

void player_place(int y, int x);

void place_trap(int y, int x);

void place_gold(int y, int x);

void place_object(int y, int x, bool good, bool great);

bool place_monster(int y, int x, bool slp, bool grp);

bool alloc_monster(int dis, int slp);

s16b Rand_normal(int mean, int stand);

/*
 * Automatically generated "variable" declarations
 */

/* tables.c */
extern s16b ddd[9];
extern s16b ddx[10];
extern s16b ddy[10];
extern s16b ddx_ddd[9];
extern s16b ddy_ddd[9];
extern char hexsym[16];
extern byte adj_mag_study[];
extern byte adj_mag_mana[];
extern byte adj_mag_fail[];
extern byte adj_mag_stat[];
extern byte adj_chr_gold[];
extern byte adj_int_dev[];
extern byte adj_wis_sav[];
extern byte adj_dex_dis[];
extern byte adj_int_dis[];
extern byte adj_dex_ta[];
extern byte adj_str_td[];
extern byte adj_dex_th[];
extern byte adj_str_th[];
extern byte adj_str_wgt[];
extern byte adj_str_hold[];
extern byte adj_str_dig[];
extern byte adj_str_blow[];
extern byte adj_dex_blow[];
extern byte adj_dex_safe[];
extern byte adj_con_fix[];
extern byte adj_con_mhp[];
extern byte blows_table[12][12];
extern byte extract_energy[200];
extern s32b player_exp[PY_MAX_LEVEL];
extern u32b spell_flags[2][9][2];
extern cptr spell_names[2][64];
extern byte chest_traps[64];
extern cptr color_names[16];
extern cptr stat_names[6];
extern cptr stat_names_reduced[6];
extern cptr window_flag_desc[32];
extern cptr option_text[OPT_MAX];
extern cptr option_desc[OPT_MAX];
extern bool option_norm[OPT_MAX];
extern byte option_page[4][16];

/* variable.c */
extern cptr copyright[5];
extern byte version_major;
extern byte version_minor;
extern byte version_patch;
extern byte version_extra;
extern byte sf_major;
extern byte sf_minor;
extern byte sf_patch;
extern byte sf_extra;
extern u32b sf_xtra;
extern u32b sf_when;
extern u16b sf_lives;
extern u16b sf_saves;
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
extern s16b character_icky;
extern s16b character_xtra;
extern u32b seed_flavor;
extern u32b seed_town;
extern s16b num_repro;
extern s16b object_level;
extern s16b monster_level;
extern s32b turn;
extern s32b old_turn;
extern bool use_sound;
extern bool use_graphics;
extern s16b signal_count;
extern bool msg_flag;
extern bool inkey_base;
extern bool inkey_xtra;
extern bool inkey_scan;
extern bool inkey_flag;
extern s16b coin_type;
extern bool opening_chest;
extern bool shimmer_monsters;
extern bool shimmer_objects;
extern bool repair_mflag_born;
extern bool repair_mflag_nice;
extern bool repair_mflag_show;
extern bool repair_mflag_mark;
extern s16b o_max;
extern s16b o_cnt;
extern s16b m_max;
extern s16b m_cnt;
extern s16b feeling;
extern s16b rating;
extern bool good_item_flag;
extern bool closing_flag;
extern int player_uid;
extern int player_euid;
extern int player_egid;
extern char savefile[1024];
extern s16b macro__num;
extern cptr *macro__pat;
extern cptr *macro__act;
extern s16b quark__num;
extern cptr *quark__str;
extern u16b message__next;
extern u16b message__last;
extern u16b message__head;
extern u16b message__tail;
extern u16b *message__ptr;
extern char *message__buf;
extern char angband_term_name[8][16];
extern byte angband_color_table[256][4];
extern char angband_sound_name[SOUND_MAX][16];
extern sint view_n;
extern u16b *view_g;
extern sint temp_n;
extern u16b *temp_g;
extern byte *temp_y;
extern byte *temp_x;
extern byte cave_info[DUNGEON_HGT][256];
extern byte cave_feat[DUNGEON_HGT][DUNGEON_WID];
extern s16b cave_o_idx[DUNGEON_HGT][DUNGEON_WID];
extern s16b cave_m_idx[DUNGEON_HGT][DUNGEON_WID];
extern int cave_sector_map[DUNGEON_HGT][DUNGEON_WID];
extern int sector_counter;

extern s16b alloc_kind_size;
extern s16b alloc_race_size;
extern byte misc_to_attr[256];
extern char misc_to_char[256];
extern byte tval_to_attr[128];
extern char macro_buffer[1024];
extern cptr keymap_act[KEYMAP_MODES][256];

/*
 * Automatically generated "function declarations"
 */

/* birth.c */
extern void player_birth(void);

/* cave.c */
extern sint distance(int y1, int x1, int y2, int x2);
extern bool los(int y1, int x1, int y2, int x2);
extern bool no_lite(void);
extern bool cave_valid_bold(int y, int x);
extern void map_info(int y, int x, byte *ap, char *cp);
extern void move_cursor_relative(int y, int x);
extern void print_rel(char c, byte a, int y, int x);
extern void note_spot(int y, int x);
extern void lite_spot(int y, int x);
extern void prt_map(void);
extern void display_map(int *cy, int *cx);
extern void do_cmd_view_map(void);
extern errr vinfo_init(void);
extern void forget_view(void);
extern void update_view(void);
extern void forget_flow(void);
extern void update_flow(void);
extern void map_area(void);
extern void wiz_lite(void);
extern void wiz_dark(void);
extern void town_illuminate(bool daytime);
extern void cave_set_feat(int y, int x, int feat);
extern sint project_path(u16b *gp, int range, \
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


