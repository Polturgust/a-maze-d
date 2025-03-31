/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** zljhzeui
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <dirent.h>
    #include <pwd.h>
    #include <grp.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <limits.h>
    #include <time.h>
typedef struct inf_frmt {
    char tab_inf[3][255];
    char ind_conv;
} inf_frmt_t;
char *get_file(char *path);
char *str_dupby(char *str, char *by, int less);
unsigned int size_wrd(char *str, int forward, char *separ);
void destroy_array(char **arr);
char *my_strndup(char *str, int n);
char **str_to_word_array(char *str, char *slice);
int my_arraylen(char **str);
int my_put_char_tab(char **arr);
char *str_merge(int nb, ...);
char *my_str_merge(char *str1, char *str2);
char *my_strdup(char *str);
int my_strcmp(char *str1, char *str2);
int my_strncmp(char *str1, char *str2, int nb);
char *my_strcpy(char *dest, char const *src);
void my_puterror_str(char *str);
void my_puterror_char(char c);
int str_is_alphanum(char *str);
int str_is_num(char *str);
int str_is_alpa(char *str);
int is_id_cnv(char, int);
int is_char_trb(char, int);
int is_prs(char, int);
int is_mod_lng(char, int);
int is_num(char c);
int is_alpha(char c);
int is_alphanum(char c);
int is_only(char *str, char *chara);
int is_exe(char *path);
int take_pres(va_list, char *, char);
int test_pres(int nb, char f);
void flag_i_d(va_list, inf_frmt_t, int *acc);
void flag_c(va_list, inf_frmt_t, int *acc);
void flag_s(va_list, inf_frmt_t, int *acc);
void flag_n(va_list, inf_frmt_t, int *acc);
void flag_x(va_list, inf_frmt_t, int *acc);
void flag_u(va_list, inf_frmt_t, int *acc);
void flag_f(va_list, inf_frmt_t, int *acc);
void flag_e(va_list, inf_frmt_t, int *acc);
void flag_o(va_list, inf_frmt_t, int *acc);
void flag_g(va_list, inf_frmt_t, int *acc);
void flag_p(va_list, inf_frmt_t, int *acc);
void flag_a(va_list, inf_frmt_t, int *acc);
void flag_amaj(va_list, inf_frmt_t, int *acc);
void flag_pr(char f, int *acc);
int my_put_uint(unsigned int nb, int *size, int);
int my_putchar(char);
int my_put_nbr(int, int *);
int my_put_llnbr(long, int *);
void my_put_nnbr(int nb, int *acc, int);
void my_put_llnnbr(long nb, int *acc, int);
int my_putstr(char *, int *);
void my_put_nstr(char *str, int n, int *acc);
int my_printf(const char *format, ...);
void test_flags(va_list list, const char *, int *acc, int *);
int my_strlen(char const *str);
unsigned long long my_compute_power_rec(int nb, int power);
int get_power(unsigned int nb, int base);
int get_lpower(unsigned long nb, int base);
void hexa_min(unsigned int n, int *count);
void hexa_maj(unsigned int n, int *count);
void hexa_minlong(unsigned long n, int *count);
void hexa_majlong(unsigned long n, int *count);
void put_nbr_base(unsigned int n, int base, int *count, int pres);
void my_put_float(double, int, int *);
void put_scemin(double n, int pres, int *count, char f);
void put_scemaj(double n, int pres, int *count, char f);
int verif_coma(int entier, int v);
int nbr_coma(double n);
int expo(int n, int *count);
int is_in(char, char *);
int is_file(char *path);
int is_dir(char *path);
void char_diez(const char *, int *, int *);
char *recup_format(const char *, char *);
void char_nbr(const char *, int *, int *);
int my_getnbr(char const *str);

#endif /* MY_H_ */
