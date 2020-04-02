/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jdiaz-co.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-co <jdiaz-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 04:56:47 by jdiaz-co          #+#    #+#             */
/*   Updated: 2020/04/02 07:41:21 by jdiaz-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int     i;
	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i) && i < (int)n - 1)
		i++;
	if (n)
		return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
	return (0);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t  i;
	char    *substr;
	i = 0;
	if (!(substr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*dst;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	dst = malloc(sizeof(dst) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	while (*s1)
	{
		dst[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		dst[i] = *s2;
		i++;
		s2++;
	}
	dst[i] = '\0';
	return (dst);
}

int		hv_necklace(char *s1, char *s2)
{
	char	*temp;
	char	*temp2;
	int		i;
	int		j;
	
	i = 0;	
	j = 0;
	if ((i = ft_strlen(s1)) != (j = ft_strlen(s2)))
		return(0);
	if (ft_strlen(s1) == 0)
		return (1);
	else if (ft_strlen(s1) == ft_strlen(s2))
	{
		temp = (char*)malloc(sizeof(*s1) * (i + 1));
		temp2 = (char*)malloc(sizeof(*s1) * (i + 1));
		while (i >= 0)
		{
			if (ft_strncmp(s1,s2, ft_strlen(s1)) == 0)
				return (1);
			temp[0] = s2[j - 1];
			temp2 = ft_substr(s2, 0, s2[j - 2]);
			s2 = ft_strjoin(temp, temp2);
			i--;
		}
		free(temp);
		free(temp2);
	}
	return (0);
}
