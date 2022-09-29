#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int j;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		j = 0;
		while (argv[i])
		{
			while (argv[i][j] != '\0')
			{
				argv[i][j] = toupper(argv[i][j]);
				j++;
			}
			std::cout << argv[i];
			j = 0;
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
