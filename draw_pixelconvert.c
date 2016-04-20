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

void			*draw_pixelsconvert(unsigned int *dest, const void *src,
		int bpp, size_t size)
{
	size_t					dpos;
	size_t					pos;
	unsigned int			pixel;
	const unsigned char		*p = (const unsigned char *)src;

	if (bpp == 4)
		return (ft_memcpy(dest, src, size * 4));
	if ((bpp > 4) || (bpp < 1))
		return (dest);
	draw_pixels_convert_init(&pos, &dpos, &pixel);
	while (dpos < size)
	{
		if (bpp == 1)
		{
			pixel = (unsigned int)p[pos];
			pixel |= pixel << 8 | pixel << 16;
		}
		else if (bpp == 2)
		{
			pixel = ((const unsigned short*)src)[pos];
			pixel |= pixel << 16;
		}
		//todo: fix this comportement: actualy this conversion is not ok
		else if (bpp == 3)
		{
			p = (const unsigned char *)((unsigned long)src + pos);
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
				pixel = (unsigned int)((p[0] << 16) | (p[1] << 8) | p[2]);
			else
				pixel = (unsigned int)(p[0] | (p[1] << 8) | (p[2] << 16));
		}
		dest[dpos++] = pixel;
		pos += (unsigned int)bpp;
	}
	return (dest);
}
