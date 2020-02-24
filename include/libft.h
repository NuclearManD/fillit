/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:23:55 by dbrophy           #+#    #+#             */
/*   Updated: 2020/02/21 14:23:55 by dbrophy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "string.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_atoi(char *str);
int				ft_atoi_base(char *str, char *base);
void			ft_bzero(void *s, size_t n);
int				ft_imax(int a, int b);
int				ft_imin(int a, int b);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
char			*ft_itoa(int n);
int				ft_logi(int base, int val);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(const void *content, size_t content_size);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(const char *s);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr(int nb);
void			ft_putnbr_base(int nb, char *base);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putstr(char *str);
void			ft_putstr_fd(const char *str, int fd);
long			ft_signature_s(char *str);
long			ft_signature_i(int val);
long			ft_signature_l(long val);
long			ft_signature_d(double val);
int				ft_str_is_alpha(char *str);
int				ft_str_is_lowercase(char *str);
int				ft_str_is_numeric(char *str);
int				ft_str_is_printable(char *str);
int				ft_str_is_uppercase(char *str);
char			*ft_strcapitalize(char *str);
char			*ft_strcat(char *dest, char *src);
char			*ft_strchr(char *s, int c);
int				ft_strchri(const char *s, char c);
void			ft_strclr(char *s);
int				ft_strcmp(char *s1, char *s2);
int				ft_strcnt(const char *s, char c);
int				ft_strcnt_norep(const char *s, char c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strcut(const char *s, char c);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s);
int				ft_strequ(const char *s1, const char *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(const char *s1, const char *s2);
unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int n);
size_t			ft_strlen(const char *str);
char			*ft_strlowcase(char *str);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *dest, const char *src, int nb);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
char			*ft_strncpy(char *dest, const char *src, unsigned int n);
int				ft_strnequ(const char *s1, const char *s2, size_t limit);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strrchr(char *s, int c);
char			**ft_strsplit(const char *s, char c);
char			*ft_strstr(char *str, const char *to_find);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s);
char			*ft_strupcase(char *str);
int				ft_tolower(int c);
int				ft_toupper(int c);

#endif
