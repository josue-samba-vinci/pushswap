
# include "push_swap.h"

int *extract(t_stack **stack)
{
	int size;
	int	i;
	int	*tab;
	t_stack	*current;

	i = 0;
	size = stack_size(*stack);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	current = *stack;
	while (current)
	{
		tab[i] = current->value;
		current = current->next;
		i++;
	}
	return (tab);
}

void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1 -i)
		{
			if (tab[j] > tab[j+1])
			{
				temp = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	index_stack(t_stack **stack)
{
	int *tab;
	int	size;
	int	i;
	t_stack	*current;

	i = 0;
	size = stack_size(*stack);
	tab = extract(stack);
	sort_tab(tab, size);
	current = *stack;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] == current->value)
			{
				current->value = i;
				break;
			}
			i++;
		}
		current = current->next;
	}
	free(tab);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while ((i + 1) * (i + 1) <= nb)
		i++;
	return (i);
}
static int	find_max_pos_b(t_stack *stack_b)
{
	int		max;
	int		pos;
	int		i;
	t_stack	*current;

	current = stack_b;
	max = current->value;
	i = 0;
	pos = 0;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	int size;
	int chunk_size;
	int chunk_min;
	int chunk_max;
	int index;
	int count;
	int pushed;
	int rotation;
	t_stack *current;

	size = stack_size(*stack_a);
	pushed = 0;
	chunk_size = ft_sqrt(size);
	chunk_min = 0;
	chunk_max = chunk_size;
	index = 0;
	count = 0;
	current = *stack_a;
	while (current)
	{
		if (current->value >= chunk_min && current->value < chunk_max)
		{
			rotation = size - index;
			if (index > size / 2)
			{
				while(rotation > 0)
				{
					reverse_rotate(stack_a, 'a');
					rotation--;
				}
			}
			else
			{
				while (index > 0)
				{
					rotate(stack_a, 'a');
					index--;
				}
			}
			push(stack_a, stack_b, 'b');
			pushed = 1;
			size = stack_size(*stack_a);
			count++;
			current = *stack_a;
			index = 0;
		}
		if (pushed == 0)
		{
			current = current->next;
			index++;
		}
		if (pushed == 1)
		{
			current = *stack_a;
			index = 0;
			pushed = 0;
		}
		if (count == chunk_size)
		{
			chunk_min += chunk_size;
			chunk_max += chunk_size;
			count = 0;
		}
	}
}
