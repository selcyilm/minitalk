/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strlen.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/08 14:18:15 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/08 14:18:18 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
