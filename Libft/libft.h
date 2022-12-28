/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:21:13 by aanghel           #+#    #+#             */
/*   Updated: 2022/12/22 18:50:23 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define BUFFER_SIZE 8

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_lstsize(t_list *lst);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *s, int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *nd, size_t len);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_searchstrchr(char const *str, char **array);
char			*ft_strtrim2(char *str, char del);
char			*ft_strtrim3(char *str, char *del);
void			*ft_calloc(size_t count, size_t size);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			*ft_memdel(void *ptr);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_skip_spacenl(const char *str, int *i);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_print_lst(t_list *token);
void			ft_print_matrix(char **matrix);
void			ft_free_matrix(char **matrix);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *ls, void *(*f)(void *), void (*del)(void *));

//printf
int				ft_printf(const char *str, ...);
int				ft_char(int lett);
int				ft_u(unsigned int num);
int				ft_putnbr(int num);
int				ft_lenesa(uintptr_t nb);
int				ft_putesa(uintptr_t num);
unsigned int	ft_esa(unsigned int num, char lett);
unsigned int	ft_lenu(unsigned int num);

//gnl
char			*get_next_line(int fd);
char			*ft_read(int fd, char *str);
char			*ft_nline(char *str);
char			*ft_fline(char *str);
#endif