#ifndef LIST_H
# define LIST_H

typedef struct s_list t_list;

struct s_list
{
	char	*str;
	struct s_list	*next;
};

t_list	*add_link(t_list *list, char *str);
void	print_list(t_list *list);

#endif