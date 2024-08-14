#include <stdio.h>
#include "ft_point.h"

void set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}
int main(void)
{
	t_point point;
	t_point *ptr;
	ptr = &point;
	printf("point.x = %i\npoint.y = %i\n", ptr->x = 42, ptr->y = 21);
	set_point(&point);
	return (0);
}
