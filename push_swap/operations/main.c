#include "../algorithms/algorithms.h"
#include "operations.h"

int main(int ac, char **av)
{
	char	*str;
	int		n;
	int		i;
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	t_stack	*tmp;

	if (ac <= 3)
		return -1;
	i = 1;
	while (i < ac)
		ft_stack_addfront(&a, ft_stacknew(ft_atoi(av[i++])));
	sort_simple(&a);
	tmp = a;
	while (tmp)
	{
		ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}
