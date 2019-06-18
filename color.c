/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:25:04 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/06/18 16:41:28 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int		main(int argc, char **argv)
{
	char *color[6];
	char *col;
	char *val;
	int i;

	i = 0;
	col = "Normal Colour";
	color[0] = "red";
	color[1] = "green";
	color[2] = "yellow";
	color[3] = "blue";
	color[4] = "magenta";
	color[5] = "cyan";
	//got segfault errors so i malloced the stuff
	val = malloc(sizeof(argv[1]));
	while (strlen(argv[1]) >= i)
	{
		//makes the input argument all lowercase for comparison in the if statements
		val[i] = tolower(argv[1][i]);
		i++;
	}
	if (argc >= 2 && argc <= 3)
	{
		//checks what colour second argument "./a.out (2nd arg) sentence" is equal to
		if (strcmp(val, color[0]) == 0)
		{
			//\033 is the escape sequence and [0;31m is the colour code for red
			//[1;31m is BOLD red
			//[0;31m is just normal red
			printf("\033[0;31m");
			col = "Red";
		}
		if (strcmp(val, color[1]) == 0)
		{
			printf("\033[0;32m");
			col = "Green";
		}
		if (strcmp(val, color[2]) == 0)
		{
			printf("\033[0;33m");
			col = "Yellow";
		}
		if (strcmp(val, color[3]) == 0)
		{
			printf("\033[0;34m");
			col = "Blue";
		}
		if (strcmp(val, color[4]) == 0)
		{
			printf("\033[0;35m");
			col = "Magenta";
		}
		if (strcmp(val, color[5]) == 0)
		{
			printf("\033[0;36m");
			col = "Cyan";
		}
		if (strcmp(val, "list") != 0)
			printf("%s\nWas Printed In %s\n", argv[2], col);
		if (strcmp(val, "list") == 0)
		{
			//[0m resets the colour to the default
			printf("\033[0mThe Availiable Colours Are\
					\nRed\nGreen\nYellow\nBlue\nMagenta\nCyan\n");
		}
	}
	return (0);
}
