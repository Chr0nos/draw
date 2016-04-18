#include "draw.h"
#include "libft.h"
#include <string.h>

static void		draw_pixels_convert_init(size_t *pos, size_t *dpos,
		unsigned int *pixel)
{
	*pos = 0;
	*dpos = 0;
	*pixel = 0;
}

/*
** size is in pixels
*/
void	*draw_pixelsconvert(unsigned int *dest, const void *src, int bpp,
		size_t size)
{
	size_t			dpos;
	size_t			pos;
	unsigned int	pixel;

	if (bpp == 4)
		return (ft_memcpy(dest, src, size * 4));
	if ((bpp > 4) || (bpp < 1))
		return (dest);
	draw_pixels_convert_init(&pos, &dpos, &pixel);
	while (pos < size)
	{
		if (bpp == 1)
		{
			pixel = (unsigned int)(((const unsigned char *)src)[pos]);
			pixel |= pixel << 8 | pixel << 16;
		}
		else if (bpp == 2)
		{
			pixel = ((const unsigned short*)src)[pos];
			pixel |= pixel << 16;
		}
		dest[dpos++] = pixel;
		pos += (unsigned int)bpp;
	}
	return (dest);
}
