#include "inc/cub3d.h"

static bool	check_if_ascii(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isascii(line[i]))
		    return (false);
		i++;
	}
	return (true);;
}

static char	*read_fdz(int fd, char *buffer)
{
	char	tmp[50 + 1];
	int		size;

	size = 1;
	while (ft_strchrz(buffer) == NULL && size != 0)
	{
		size = read(fd, tmp, 50);
		if (size < 0)
			return (NULL);
		tmp[size] = '\0';
		buffer = ft_strjoinz(buffer, tmp);
		if (check_if_ascii(buffer) == false)
			return (free(buffer), NULL);
	}
	if (ft_strlenz(buffer) > 4024)
		return (free(buffer), NULL);
	return (buffer);
}


static char	*get_the_linez(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_bufferz(char *buffer)
{
	int		n;
	int		m;
	int		i;
	char	*new_buffer;

	n = 0;
	m = ft_strlenz(buffer);
	while (buffer[n] && buffer[n] != '\n')
		n++;
	if (buffer[n] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(sizeof(char) * (m - n + 1));
	if (new_buffer == NULL)
		return (NULL);
	i = 0;
	while (buffer[n++])
		new_buffer[i++] = buffer[n];
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*custom_gnl(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0)
		return (NULL);
	buffer = read_fdz(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = get_the_linez(buffer);
	buffer = new_bufferz(buffer);
	return (line);
}
