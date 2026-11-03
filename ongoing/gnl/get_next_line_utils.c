#include "get_next_line.h"

char    *ft_strchr(const char *s, int c)
{
    if (!s)
        return (NULL);
    while (*s && *s != (unsigned char)c)
        s++;
    if (*s == (unsigned char)c)
        return ((char *)s);
    return (NULL);
}

char    *ft_strdup(const char *s)
{
    char    *dup;
    size_t    i;

    if (!s)
        return (NULL);
    i = 0;
    while (s[i])
        i++;
    dup = malloc(i + 1);
    if (!dup)
        return (NULL);
    i = 0;
    while (s[i])
        dup[i] = s[i], i++;
    dup[i] = '\0';
    return (dup);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    size_t    i;
    size_t    j;

    if (!s1 || !s2)
        return (NULL);
    i = 0;
    while (s1[i])
        i++;
    j = 0;
    while (s2[j])
        j++;
    str = malloc(i + j + 1);
    if (!str)
        return (NULL);
    str[i + j] = '\0';
    while (j--)
        str[i + j] = s2[j];
    while (i--)
        str[i] = s1[i];
    return (str);
}

int    ft_lstadd_back(t_list **lst, char *content)
{
    t_list    *new;
    t_list    *tmp;

    if (!lst || !content)
        return (0);
    new = malloc(sizeof(t_list));
    if (!new)
        return (0);
    new->content = content;
    new->next = NULL;
    if (!*lst)
        return (*lst = new, 1);
    tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    return (1);
}

void    ft_lstclear(t_list *lst)
{
    t_list    *tmp;

    while (lst)
    {
        tmp = lst->next;
        free(lst->content);
        free(lst);
        lst = tmp;
    }
}

char    *ft_lstjoin(t_list *lst)
{
    char    *str;
    char    *tmp;

    str = ft_strdup("");
    if (!str)
        return (NULL);
    while (lst)
    {
        tmp = ft_strjoin(str, lst->content);
        if (!tmp)
            return (free(str), NULL);
        free(str);
        str = tmp;
        lst = lst->next;
    }
    return (str);
}
