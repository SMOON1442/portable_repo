#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

static char	f(unsigned int i, char c)
{
	return (i % 2) ? (char)toupper((unsigned char)c) : c;
}

int	main(void)
{
	char	*r;

	r = ft_strampi("abcdef", f);
	printf("basic : %s (expected aBcDeF)\n", r);
	free(r);

	r = ft_strampi("", f);
	printf("empty : \"%s\" (expected \"\")\n", r ? r : "NULL");
	free(r);

	r = ft_strampi("a", f);
	printf("single: %s (expected a)\n", r);
	free(r);


	return 0;
}
	/* printf("alpha : [%d]\n", ft_isalpha(av[1][0]));
	printf("digit : [%d]\n", ft_isdigit(av[1][0]));
	printf("alnum : [%d]\n", ft_isalnum(av[1][0]));
	printf("ascii : [%d]\n", ft_isascii(av[1][0]));
	printf("print : [%d]\n", ft_isprint(av[1][0]));
	*/
	/* printf("[%c] lower : [%c]\n", *av[1], ft_tolower(*av[1]));
	printf("[%c] upper : [%c]\n", *av[2], ft_toupper(*av[2]));
	 */
	/* char	*temp;

	temp = ft_strtrim("xxhixx", "x");
	printf("xxhixx, x : [%s]\n", temp);
	free(temp);
	
	temp = ft_strtrim("", "x");
	printf("'', x : [%s]\n", temp);
	free(temp);
	
	temp = ft_strtrim("xxx", "x");
	printf("xxx, x : [%s]\n", temp);
	free(temp);
	
	temp = ft_strtrim("hello", "");
	printf("hello, '' : [%s]\n", ft_strtrim("hello", ""));
	free(temp);
	
	temp = ft_strtrim("  hi  ", " ");
	printf("  hi  , ' ' : [%s]\n", temp);
	free(temp); */

	/*
	 char	**result;
	int		i;

	result = ft_split("  hello  world  ", ' ');
	if (!result)
		return (1);
	i = 0;
	while (result[i])
	{
		printf("result[%d] = \"%s\"\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	*/
