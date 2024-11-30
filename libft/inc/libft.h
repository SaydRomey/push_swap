/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:49:30 by cdumais           #+#    #+#             */
/*   Updated: 2024/11/29 21:45:32 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

# define BINARY "01"
# define OCTAL "01234567"
# define DECIMAL "0123456789"
# define HEX_LO "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_OPEN 10240

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# define TRUE 1
# define FALSE 0
# define ERROR -1

# define SAME 0

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//
// Libc functions
//
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str); //atoi_parse and atoi_incr
//
// Additional functions
//
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char *str, int fd);
size_t	ft_putendl_fd(char *s, int fd);
size_t	ft_putnbr_fd(int n, int fd);
//
// Bonus functions
//
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//
// get_next_line
//
char	*get_next_line(int fd);
//
// ft_printf
//
int		ft_printf(const char *format, ...);
int		ft_intlen(int n);
size_t	ft_putnbr_base_fd(size_t n, int fd, char const *base_format);
//
// pushwap
// 
void	ft_swap(int *a, int *b);
// 
#endif
