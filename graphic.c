#include "fdf.h"

int	pixel_limits(t_point *point)
{
	if (point->x < 1 || point->x > WIDTH - 1)
		return (0);
	if (point->y < 1 || point->y > HEIGHT - 1)
		return (0);
	return (1);
}

t_point	project_pt(t_point pt, t_fdf *fdf)
{
	int	x;
	int	y;
	
	x = pt.x;
	y = pt.y;
	pt.x = pt.x * fdf->cam->zoom - ((fdf->map->width * fdf->cam->zoom) / 2);
	pt.y = pt.y * fdf->cam->zoom - ((fdf->map->height * fdf->cam->zoom) / 2);
	pt.z = pt.z * fdf->cam->zoom / fdf->cam->z_scale;

	if (fdf->cam->projection == ISOMETRIC)
	{
		x = (pt.x - pt.y) * cos(M_PI / 6);
		y = (-pt.z + (pt.x + pt.y) * sin(M_PI / 6));
	}
	/*else
	{
		x = pt.x;
		y = pt.y;
	}*/
	pt.x = x + WIDTH / 2 + fdf->cam->offset_x;
	pt.y = y + HEIGHT / 2 + fdf->cam->offset_y;
	return (pt);
}
