#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
    char            *content;
    struct s_list    *next;
}    t_list;

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_lstadd_back(t_list **lst, char *content);
void	ft_lstclear(t_list *lst);
char	*ft_lstjoin(t_list *lst);
char	*get_next_line(int fd);

#endif
