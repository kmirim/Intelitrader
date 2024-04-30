#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

unsigned char rev_last_bits(unsigned char octet)
{
	return ((octet ^ 1 << 1) ^ 1 << 0);
}

unsigned char swap_bits(unsigned char octet)
{
	return ((octet << 4) | (octet >> 4));
}

void print_bits(unsigned char octet)
{
	int i = 8;
	while (--i >= 0)
	{
		if (octet & (1 << i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
}

void	message_descrypt(char *octet)
{
	static char	c = 0xFF;
	static int	i;
	int 		signal;

	while (*octet != '\0')
	{
		signal = *octet - 48;
		if (signal == 0)
			c = c ^ (128 >> i);
		else if (signal == 1)
			c = c | (128 >> i);
		if (++i == 8)
		{
			printf("%c", swap_bits(rev_last_bits(c)));
			i = 0;
			c = 0xFF;
		}
		octet++;
	}
}


int main (int count, char **value)
{
	if(count > 1)
	{
		int i = 1;
		while (i < count)
		{
			message_descrypt(value[i]);
			i++;
		}
	}
	else
		printf("Por favor, insira uma mensagem válida!");
	printf("\n");
}
