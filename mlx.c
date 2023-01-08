/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:53:01 by pcatapan          #+#    #+#             */
/*   Updated: 2023/01/08 00:33:32 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "mlx/mlx.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int x;
  int y;
  int z;
} Point;

typedef struct
{
  Point center;
  int radius;
  int color[3];
} Sphere;

void draw_sphere(void *mlx, void *win, Sphere sphere)
{
  int x, y, z;
  int color;
  int window_width = 640;
  int window_height = 480;
  
  x = window_width / 2;
  y = window_height / 2;
  z = sphere.center.z;
  
  int r = sphere.color[0];
  int g = sphere.color[1];
  int b = sphere.color[2];
  
  int color_int = (r << 16) | (g << 8) | b;
  
  color = mlx_get_color_value(mlx, color_int);
  
  for (int i = -sphere.radius; i <= sphere.radius; i++)
  {
    for (int j = -sphere.radius; j <= sphere.radius; j++)
    {
      for (int k = -sphere.radius; k <= sphere.radius; k++)
      {
        if (i * i + j * j + k * k <= sphere.radius * sphere.radius)
        {
          mlx_pixel_put(mlx, win, x + i, y + j, color);
        }
      }
    }
  }
}

int main(int argc, char **argv)
{
  void *mlx;
  void *win;
  Sphere sphere;
  
  mlx = mlx_init();
  win = mlx_new_window(mlx, 640, 480, "Sphere");
  
  sphere.center.x = 0;
  sphere.center.y = 0;
  sphere.center.z = 20;
  sphere.radius = 20;
  sphere.color[0] = 255;
  sphere.color[1] = 0;
  sphere.color[2] = 0;
  
  draw_sphere(mlx, win, sphere);
  
  mlx_loop(mlx);
  
  return 0;
}