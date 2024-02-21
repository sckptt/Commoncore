#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

void add_i(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

char upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

int main(void)
{
	printf("Atoi test: %d\n", ft_atoi("  +5736283"));
	printf("Orig atoi: %d\n", atoi("  +5736283"));

	write(1, "\n", 1);

	printf("Isalnum test: %d\n", ft_isalnum('b'));
	printf("%d\n", ft_isalnum('9'));
	printf("%d\n", ft_isalnum(48));
	printf("Orig isalnum: %d\n", isalnum('b'));
	printf("%d\n", isalnum('9'));
	printf("%d\n", isalnum(48));

	write(1, "\n", 1);

	printf("Isalpha test: %d\n", ft_isalpha('S'));
	printf("%d\n", ft_isalpha(88));
	printf("%d\n", ft_isalpha('='));
	printf("Orig isalpha: %d\n", isalpha('S'));
	printf("%d\n", isalpha(88));
	printf("%d\n", isalpha('='));

	write(1, "\n", 1);

	printf("Isascii test: %d\n", ft_isascii('~'));
	printf("%d\n", ft_isascii('8'));
	printf("%d\n", ft_isascii(130));
	printf("Orig isascii: %d\n", isascii('~'));
	printf("%d\n", isascii('8'));
	printf("%d\n", isascii(130));

	write(1, "\n", 1);

	printf("Isdigit test: %d\n", ft_isdigit('1'));
	printf("%d\n", ft_isdigit('8'));
	printf("%d\n", ft_isdigit('='));
	printf("Orig isdigit: %d\n", isdigit('1'));
	printf("%d\n", isdigit('8'));
	printf("%d\n", isdigit('='));

	write(1, "\n", 1);

	printf("Isprint test: %d\n", ft_isprint('S'));
	printf("%d\n", ft_isprint(1));
	printf("%d\n", ft_isprint('\n'));
	printf("Orig isprint: %d\n", isprint('S'));
	printf("%d\n", isprint(1));
	printf("%d\n", isprint('\n'));

	write(1, "\n", 1);

	printf("Itoa test: %s\n", ft_itoa(-1234));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-5555555));
	printf("Orig itoa: %d\n", itoa(-1234));
	printf("%d\n", itoa(0));
	printf("%d\n", itoa(-5555555));

	write(1, "\n", 1);

	printf("Memchr test: %s\n", (char *)ft_memchr("voracious", 'c', sizeof("voracious")));
	printf("%s\n", (char *)ft_memchr("voracious", 'l', sizeof("voracious")));
	printf("Orig memchr: %s\n", (char *)memchr("voracious", 'c', sizeof("voracious")));
	printf("%s\n", (char *)memchr("voracious", 'l', sizeof("voracious")));

	write(1, "\n", 1);

	printf("Memcmp test: %d\n", ft_memcmp("Emrakul", "Emrakul", 7));
	printf("%d\n", ft_memcmp("Emrakul", "Ulamog", 4));
	printf("%d\n", ft_memcmp("Hello", "Hellz", 4));
	printf("%d\n", ft_memcmp("Hello", "Hellz", 6));
	printf("Orig memcmp: %d\n", memcmp("Emrakul", "Emrakul", 7));
	printf("%d\n", memcmp("Emrakul", "Ulamog", 4));
	printf("%d\n", memcmp("Hello", "Hellz", 4));
	printf("%d\n", memcmp("Hello", "Hellz", 6));

	write(1, "\n", 1);

	char source[20] = "I'm source string";
	char destination1[20] = "I'm dest";
	char destination2[20] = "I'm dest";

	printf("Memcpy test:\n");
	printf("Before: %s\n", destination1);
	memcpy(destination1, source, sizeof(source));
	printf("After: %s\n", destination1);
	printf("Orig memcpy:\n");
	printf("Before: %s\n", destination2);
	ft_memcpy(destination2, source, sizeof(source));
	printf("After: %s\n", destination2);

	write(1, "\n", 1);

	char string[20];
	char string1[20];

	ft_memset(string1, 'x', 7);
	printf("Memset test: %s\n", string1);
	memset(string, '*', 5);
	printf("Orig memset: %s\n", string);

	write(1, "\n", 1);

	printf("Putchar test:\n");
	ft_putnbr_fd(12345, 1);
	printf("%c", '\n');
	ft_putnbr_fd(-785748934, 1);
	printf("%c", '\n');
	ft_putnbr_fd(-2147483648, 1);
	printf("%c", '\n');

	write(1, "\n", 1);

	printf("Putendl test:\n");
	ft_putstr_fd("The age of Shadows has begun", 1);

	write(1, "\n", 1);

	printf("Strchar test: %s\n", ft_strchr("hello", 'l'));
	printf("%s\n", ft_strchr("hello", '.'));
	printf("Orig strchar: %s\n", strchr("hello", 'l'));
	printf("%s\n", strchr("hello", '.'));

	write(1, "\n", 1);

	char test[] = "Oh no its zzz";
	ft_striteri(test, add_i);
	printf("Striteri test: %s\n", test);

	write(1, "\n", 1);

	char *test1 = ft_strjoin("I'm s1, ", "I'm s2.");
	printf("Strjoin test: %s\n", test1);

	write(1, "\n", 1);

	char source1[] = "of Eldraine!";
	char destination3[10] = "Wilds ";
	size_t len;

	printf("Strlcat test:\n");
	printf("Dest before: %s\n", destination3);
	printf("Length of dest: %lu\n", strlen(destination3));
	len = ft_strlcat(destination3, source1, sizeof(destination3));
	printf("Dest after: %s\n", destination3);
	printf("Length of dest: %zu\n", len);

	write(1, "\n", 1);

	char source2[] = "I'm source string";
	char destination4[] = "I'm hyperdestinative destination";
	size_t len1;

	printf("Strlcpy test:\n");
	printf("Dest before: %s\n", destination4);
	printf("Length of dest: %lu\n", strlen(destination4));
	len1 = ft_strlcpy(destination4, source2, sizeof(source2));
	printf("Dest after: %s\n", destination4);
	printf("Length of dest: %zu\n", len);

	write(1, "\n", 1);

	printf("Strlen test: %zu\n", ft_strlen("I see a red door and I want it painted black"));
	printf("Orig strlen: %lu\n", strlen("I see a red door and I want it painted black"));

	write(1, "\n", 1);
	
	char *test2 = ft_strmapi("Hello", upper);
	printf("Strmapi test: %s\n", test2);

	write(1, "\n", 1);

	printf("Strncmp test: %d\n", ft_strncmp("Emrakul", "Emrakul", 7));
	printf("%d\n", ft_strncmp("Emrakul", "Ulamog", 4));
	printf("%d\n", ft_strncmp("Hello", "Hellz", 4));
	printf("%d\n", ft_strncmp("Hello", "Hellz", 6));
	printf("Orig strncmp: %d\n", strncmp("Emrakul", "Emrakul", 7));
	printf("%d\n", strncmp("Emrakul", "Ulamog", 4));
	printf("%d\n", strncmp("Hello", "Hellz", 4));
	printf("%d\n", strncmp("Hello", "Hellz", 6));

	write(1, "\n", 1);

	char *test3 = "I see a red door and I want it painted black";
	char *test4 = ft_strdup(test3);
	printf("Strdup test: %s\n", test4);
	free(test4);

	write(1, "\n", 1);

	printf("Strnstr test: %s\n", ft_strnstr("hello my friend", " my", sizeof("hello my friend")));
	printf("%s\n", ft_strnstr("hello my friend", "", sizeof("hello my friend")));
	printf("Orig strnstr: %d\n", strnstr("hello my friend", " my", sizeof("hello my friend")));
	printf("%d\n", strnstr("hello my friend", "", sizeof("hello my friend")));

	write(1, "\n", 1);

	printf("Strrchar test: %s\n", ft_strrchr("religious/desicious", 'l'));
	printf("%s\n", ft_strrchr("religious/desicious", 'i'));
	printf("Orig strrchar: %s\n", strrchr("religious/desicious", 'l'));
	printf("%s\n", strrchr("religious/desicious", 'i'));

	write(1, "\n", 1);

	printf("Strtrim test: %s\n", ft_strtrim("   Hello World   ", " .!"));
	printf("%s\n", ft_strtrim("    Hello   world    ", " "));
	printf("%s\n", ft_strtrim("~*/ Hello world /*~", "~*/"));

	write(1, "\n", 1);

	printf("Substr test: %s\n", ft_substr("Hello World", 6, 5));
	printf("%s\n", ft_substr("Hello World", 20, 5));
	printf("%s\n", ft_substr("Hello World", 6, 0));
	// printf("%s\n", substr(s, 6, 5));

	write(1, "\n", 1);

    printf("Tolower test: %c\n", ft_tolower('Z'));
	printf("%c\n", ft_tolower('y'));
    printf("%c\n", ft_tolower('+'));
    printf("Orig tolower: %c\n", tolower('Z'));
    printf("%c\n", tolower('y'));
	printf("%c\n", tolower('+'));

	write(1, "\n", 1);

	printf("Toupper test: %c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper('b'));
	printf("%c\n", ft_toupper('9'));
	printf("Orig toupper: %c\n", toupper('a'));
	printf("%c\n", toupper('b'));

	return (0);
}
