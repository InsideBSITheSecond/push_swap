#include <stdio.h>
#include <unistd.h>
#include "libft/includes/ft_printf.h"

int main()
{
	ft_printf("%s %s\n %s %s", "hello", "from", "a cute", "little printf");
	write(1, "world\n", 6);
}
