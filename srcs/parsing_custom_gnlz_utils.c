#include "../inc/cub3d.h"

int	ft_strlenz(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchrz(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdupz(char *str)
{
	char	*ptr;
	size_t	i;
	size_t	n;

	n = ft_strlenz(str);
	ptr = (char *) malloc(sizeof(char) * (n + 1));
	if (!ptr)
		return (NULL);
	ptr[n] = '\0';
	i = 0;
	while (i < n)
	{
			ptr[i] = str[i];
			i++;
	}
	return (ptr);
}

char	*ft_strjoinz(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL)
		s1 = ft_strdupz("");
	if (s2 == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlenz(s1) + ft_strlenz(s2)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
