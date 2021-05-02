/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 04:57:07 by magostin          #+#    #+#             */
/*   Updated: 2021/05/02 19:34:44 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "color.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct			s_list
{
	void				*content;
	struct s_list		*next;
	struct s_list		*prev;
}						t_list;

void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);

size_t					ft_strlen(const char *s);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);

char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t					ft_strlcat(char *dst, const char *src, size_t dstsize);
char					*ft_strnstr(const char *haystack, const char *needle,
size_t len);
int						ft_atoi(const char *str);

void					*ft_calloc(size_t count, size_t size);
char					*ft_strdup(const char *s1);

char					*ft_substr(char const *s,
unsigned int start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
void					ft_strjoin_to(char **dest, char *s2);
char					*ft_strtrim(char const *s1, char const *set);
char					**ft_split(char const *s, char c);
char					*ft_itoa(int n);
char					*ft_strmapi(char const *s,
char (*f)(unsigned int, char));

void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_putchar(char c);
void					ft_putstr(char *s);
void					ft_putendl(char *s);
void					ft_putnbr(int n);

t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **alst, t_list *new);
int						ft_lstsize(t_list *lst);
void					ft_lstlast(t_list **lst);
void					ft_lstadd_back(t_list **alst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del)(void*));
void					ft_lstclear(t_list **lst, void (*del)(void*));
void					ft_lstfirst(t_list **list);
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *));

int						ft_strcmp(const char *s1, const char *s2);
void					ft_free_tab(char **strs);
int						ft_strtrunc(char **line, int n);

void					ft_print_tab(char **strs);
void					ft_print_tab_fd(char **strs, int fd);
char					**ft_strs_to_tab(int n, ...);
int						ft_max(int a, int b);
int						ft_min(int a, int b);
int						ft_pow(int a, int b);
char					*ft_strndup(char *str, int start, int len);
void					ft_lstprint(t_list *lst);
void					ft_lstprint_fd(t_list *lst, int fd);
char					**ft_lst_to_tab(t_list *lst);
char					**ft_strs_rmi(char **strs, int size, int index);
int						ft_tablen(char **strs);
char					**ft_sort_strs(char **strs);
int						ft_strisint(char *str);
void					ft_sort_strs_to(char ***strs);

#endif
