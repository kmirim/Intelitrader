#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*Ordenar o arr */
int	*sort(int *arr, int size)
{
	int i = 0;
	int j = 0;
	int min = 0;
	int swap = 0;

	while (i < size - 1)
	{
		min = i;
		j = i + 1; 
		while(j < size)
		{
			if (arr[j] < arr[min])
				min = j;
			j++; 
		}
		swap = arr[min];
		arr[min] = arr[i];
		arr[i] = swap;
		i++;
	}
	i = 0;
		return(arr);
}

/*Verificar menor distancia*/
int	distance(int *arr1, int *arr2, int size1, int size2)
{
	int i = 0;
	int j = 0;
	int min_value = abs(arr1[0] - arr2[0]);
	int curr_value = 0;

	while (i < size1)
	{
		j = 0;
		while (j < size2)
		{
			curr_value = abs(arr1[i] - arr2[j]);
			if (curr_value < min_value)
				min_value = curr_value;
			j++;
		}
		if (arr1[i] == arr2[j])
		{
			printf("A menor diferença entre os dois arrays é: %d\n", min_value);
			return (0);
                j = 0;
                j = 0;
		}
		i++;
	}
	return (min_value);
}

int main (void)
{
	/*Arrays:*/	
	int	arr1[] = {1, 4, 15, 12, 80, 26, 10, 100, 21, 42};
	int	arr2[] = {65, 25, 13, 22, 11};

	/*Tamanho do Arr*/
	int 	size1 = sizeof(arr1)/sizeof(arr1[0]);
	int 	size2 = sizeof(arr2)/sizeof(arr2[0]);
	
	/*Ordenar - Sort_Selection*/
	int	*sort_arr1 = sort(arr1, size1);
	int	*sort_arr2 = sort(arr2, size2);
	
	/*Verificar e exibir menor distancia*/
	int	ret = distance(sort_arr1, sort_arr2, size1, size2);
	printf("A menor distância entre os arrays é de: %i\n", ret);
}
