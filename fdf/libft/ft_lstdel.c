#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void*, size_t))
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = (*alst);
	while ((*alst)->next != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		tmp = (*alst)->next;
		free((*alst));
		(*alst) = tmp;
	}
	ft_lstdelone(alst, del);
}
