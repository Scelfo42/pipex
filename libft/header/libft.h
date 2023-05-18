/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:44:25 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/18 17:51:15 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct split_vars
{
	int		i;
	int		j;
	int		k;
	int		nb_str;
	char	*trim;
	char	**arr_p;
}	t_var;

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

/*			LIBFT			*/
/* STR */
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t		ft_strlcat(char *dst, char *src, size_t size);
size_t		ft_strlcpy(char *dst, char *src, size_t size);
size_t		ft_strlen(char *s);
char		*ft_strchr(char *s, char c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s);
char		*ft_strmapi(char *s, char (*f)(unsigned int, char));
char		*ft_strnstr(char *big, char *little, size_t len);
char		*ft_strrchr(char *s, int c);
char		*ft_strtrim(char *s1, char *set);
char		*ft_substr(char *s, unsigned int start, size_t len);
int			ft_strncmp(char *s1, char *s2, size_t n);
/* MEMORY */
void		ft_bzero(void *s, size_t n);
int			ft_memcmp(void *s1, void *s2, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(void *s, int c, size_t n);
void		*ft_memcpy(void *dest, void *src, size_t n);
void		*ft_memmove(void *dest, void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
/* PUT_FD */
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
/* LIST */
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void*));
int			ft_lstsize(t_list *lst);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));
/* IS_SOMETHING */
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
/* TO_SOMETHING */
int			ft_tolower(int c);
int			ft_toupper(int c);
/* SOMETHING INTO SOMETHING ELSE */
int			ft_atoi(char *str);
char		*ft_itoa(int n);
/* HELL */
char		**ft_split(char *s, char c);
/*			GET_NEXT_LINE			*/
/* GET IT */
char		*get_next_line(int fd);
/* MANAGE STRINGS */
char		*ft_gnl_cpy(char *dest, char *tmp, char *source, size_t start);
char		*join_buf_to_heap(char *dst, char *src, ssize_t byte, size_t q_mem);
char		*form_static(char *str);
char		*cut_to_line(char *str_to_cut, char *buf);
/* READ */
char		*read_add_to_heap(int fd, char *statica, ssize_t reader);
int			found_new_line(char *str);
/*			FT_PRINTF			*/
/* PUT */
int			ft_putchar(int c);
int			ft_putstr(char *str);
int			ft_putnbr(int n);
size_t		ft_put_u_nbr(long int n);
/* PRINT */
int			ft_print_hex(unsigned int n, char format);
int			ft_print_ptr(uintptr_t ptr);
int			ft_printf(char *str, ...); //variadic function
/*			EXTRA			*/
/* ATOI VARIATIONS */
double		ft_atof(char *str); //atoi float
long int	ft_atol(char *str); //atoi long
/* STRLEN VARIATION */
int			ft_matlen(char **mat); //matrix length
int			ft_countstr(char *s, char c); //for the split
/* FREE VARIATION */
void		*ft_free(void **ptr);
void		ft_free_stack(t_stack **stack);
void		ft_free_matrix(char **matrix);
/* STRCPY VARIATION */
int			*ft_arrcpy(int *arr, int size);
int			*ft_stack_to_arr(t_node *stack_top, int stack_size);
/* FIND IN STACK */
int			ft_smallest(t_node *top);
int			ft_biggest(t_node *top);
/* DEBUGGING MEMORY */
void		*ft_malloc(size_t size);

#endif
