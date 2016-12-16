#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*prev;
	t_list	*new;
	t_list	*start;

	if (!(new = f(lst)))
		return (NULL);
	new->next = NULL;
	prev = new;
	start = new;
	lst = lst->next;
	while (lst != NULL)
	{
		if (!(new = f(lst)))
			return (NULL);
		new->next = NULL;
		prev->next = new;
		prev = new;
		lst = lst->next;
	}
	return (start);
}
