/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:59:15 by trimize           #+#    #+#             */
/*   Updated: 2024/03/16 15:59:15 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_strjoin:
*	Allocates and returns a new string wich is s1 + s2
*/

char	*ft_strjoin_ex(char *s1)
{
	s1 = (char *)malloc(1 * sizeof(char));
	s1[0] = 0;
	if (!s1)
		return (NULL);
	return (s1);
}

char	*ft_strjoin(char *s1, char const *s2, int first)
{
	int		i;
	int		y;
	char	*cat;

	i = 0;
	y = 0;
	if (first)
		s1 = ft_strjoin_ex(s1);
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[y])
		y++;
	cat = (char *)malloc(((i + y) + 1) * sizeof(char));
	if (!cat)
		return (0);
	i = -1;
	while (s1[++i])
		cat[i] = s1[i];
	y = 0;
	while (s2[y])
		cat[i++] = s2[y++];
	return (free(s1), cat[i] = 0, cat);
}
