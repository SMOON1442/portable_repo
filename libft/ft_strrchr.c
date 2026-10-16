/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:41:39 by moboulah          #+#    #+#             */
/*   Updated: 2026/10/13 15:41:40 by moboulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i])
		i++;
	ptr = ((char *)s + i);
	while (ptr != s && *ptr != c)
		ptr--;
	if (*ptr == c)
		return (ptr);
	return (0);
}
