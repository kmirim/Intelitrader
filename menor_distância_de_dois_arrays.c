#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*Mensagem de error: */
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write (fd, &*s++, 1);
}

/* Função para identificar os inputs de número: */
char	*next_nbr(char *arr)
{	
	int i = 0;
	int flag = 0;
	while(arr[i])
	{
		if ((arr[i] >= '0' && arr[i] <= '9') || (arr[i] == '-'))
		{
			if (flag == 1)
				return(&arr[i]);
			while ((arr[i] >= '0' && arr[i] <= '9') || (arr[i] == '-'))
				i++;
			flag++;
		}
		i++;
	}
	if (flag == 1 && arr[i] == '\0')
	{
		ft_putstr_fd("Uso: \"[num1, num2]\" \"[num1, num2]\"\n", 2);
		exit(2);
	}
	return (NULL);
}

char *find_nbr(char *arr)
{	
	int i = 0;
	while(arr[i])
	{
		if ((arr[i] >= '0' && arr[i] <= '9') || (arr[i] == '-'))
			return(&arr[i]);
		i++;
	}
	ft_putstr_fd("Uso: \"[num1, num2]\" \"[num1, num2]\"\n", 2);
	exit(2);
	return (NULL);
}

/* Função para criar e preencher um array com valores de start até end */
int *arr(int s_arr, int e_arr, int size)
{
	int	*ret;
	int	i;

	ret = (int *)malloc(sizeof(int) * size);
	if (!ret)
	{
        	ft_putstr_fd("Erro ao alocar memória.\n", 2);
        	return (NULL);
    	}
	i = 0;
	if (s_arr <= e_arr)
	{	
		while (i <= size)
		{
			ret[i] = s_arr;
			s_arr++;
			i++;
		}
	}
	else
	{
		while(i <= size)
		{
			ret[i] = e_arr;
			e_arr++;
			i++;
		}
	}
   	return (ret);
}

/* Função para calcular a menor diferença entre os elementos de dois arrays */
void distance(int *arr1, int *arr2, int size1, int size2)
{
	int	i; 
    	int	j;
	int	min_value = abs(arr1[0] - arr2[0]);
	int	current_value;

    	for (i = 0; i < size1; i++)
    	{
        	for (j = 0; j < size2; j++)
        	{
            		current_value = abs(arr1[i] - arr2[j]);
            		if (current_value < min_value)
                		min_value = current_value;
        	}
		if (arr1[i] == arr2[j])
		{
			ft_putstr_fd("A menor distância entre os dois arrays é de 0.\n", 1);
    			return ;
		}
	}
   	printf("A menor diferença entre os dois arrays é: %d\n", min_value);
}

int main(int count, char **value)
{
    if (count == 3)
    {
        /* Converter de char para int */
        int s_arr1 = atoi(find_nbr(value[1]));
        int e_arr1 = atoi(next_nbr(value[1]));
        int s_arr2 = atoi(find_nbr(value[2]));
        int e_arr2 = atoi(next_nbr(value[2]));
	
        /* Tamanho do array */
        int size1 = abs(e_arr1 - s_arr1) + 1;
        int size2 = abs(e_arr2 - s_arr2) + 1;
	
	/* Ponteiro para os arrays de inteiros */
        int *arr1 = arr(s_arr1, e_arr1, size1);
        int *arr2 = arr(s_arr2, e_arr2, size2);

        /* Função principal que calcula a distância */
        distance(arr1, arr2, size1, size2);

        /* Libera a memória alocada para os arrays */
        free(arr1);
        free(arr2);
    }
    else
        ft_putstr_fd("Uso: \"[num1, num2]\" \"[num1, num2]\"\n", 2);
    return (0);
}
