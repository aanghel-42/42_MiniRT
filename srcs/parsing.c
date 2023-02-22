#include "../includes/minirt.h"

//check that there are only allowed characters in the file
//for each obj call every single obj-specific function
void	ft_fill_obj_tab(char **info, t_main *m)
{
	static int	i = -1;

	i++;
	if (!ft_strncmp(info[0], "A", 1) && ft_strlen(info[0]) == 1)
		ft_fill_obj_a(info, m, i);
	else if (!ft_strncmp(info[0], "C", 1) && ft_strlen(info[0]) == 1)
		ft_fill_obj_c(info, m, i);
	else if (!ft_strncmp(info[0], "L", 1) && ft_strlen(info[0]) == 1)
		ft_fill_obj_l(info, m, i);
	else if (!ft_strncmp(info[0], "sp", 2) && ft_strlen(info[0]) == 2)
		ft_fill_obj_sp(info, m, i);   
	else if (!ft_strncmp(info[0], "pl", 2) && ft_strlen(info[0]) == 2)
		ft_fill_obj_pl(info, m, i);
	else if (!ft_strncmp(info[0], "cy", 2) && ft_strlen(info[0]) == 2)
		ft_fill_obj_cy(info, m, i);
	else
	{
		printf("(%s)\n", info[0]);
		exit_error_free("Invalid input : ID\n", m->scn.obj);
	}
}

//creazione di una matrice info con all'interno tutti gli obj tramite la funzione fill_obj_tab
void	ft_get_scn(char *f_path, t_main *m)
{
	int		fd;
	char	*line;
	char	**info;

	fd = open(f_path, O_RDONLY);
	if (fd == -1)
		perror_exit("Problem opening file");
	line = get_next_line(fd);
	while (line)
	{
		if (line && ft_strcmp_case(line, "\n"))
		{
			line = ft_trim_free(line, "\n");
			info = ft_split(line, ' ');
			ft_fill_obj_tab(info, m);
			ft_tab_free((void **)info);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

//check on the args
//initialize the scn, obj structs
//check if the values present in the file respect the formatting required by the subject
void	ft_parse(int argc, char **argv, t_main *m)
{
	ft_check_args(argc, argv);
	ft_init_scn(&m->scn);
	ft_count_obj(argv[1], m);
	ft_init_obj(m);
	ft_get_scn(argv[1], m);
}
