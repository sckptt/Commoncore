#include <iostream>

void uppercasify(char *str)
{
	int i = -1;

	while (str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if (ac > 1)
	{
		while (av[++i])
		{
			uppercasify(av[i]);
			std::cout << av[i];
		}
	}
	std::cout << "\n";
}
