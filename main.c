#include "libftasm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>


void    is_ok(int ok)
{
    ok ? printf("\033[0;32m\033[1m.\033[0m") : printf("\033[0;31m\033[1mF\033[0m");
}

int	check_is(int ret, int (*mine)(int c), int c, int (*real)(int c))
{    
    if (mine(c) == real(c) || (mine(c) == 1 && real(c) != 0))
    {
        is_ok(1);
        return (ret);
    }
    else
    {        
        is_ok(0);
        printf("(%i != %i)", mine(c),  real(c));
        return (ret + 1);
    }
}

int iter_check_is(char *title, char *str, int ret, int (*mine)(int c), int (*real)(int c))
{
    int i = 0;

    printf("\n\n%s\n", title);
    for (i = 0 ; i < strlen(str) ; i++)
        ret = check_is(ret, ft_isalpha, str[i], isalpha);
    return (ret);
}


int is_to_something(int ret)
{
    char str[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~ \t\n\r\x0b\x0c";

    ret = iter_check_is("ft_isalpha", str, ret, ft_isalpha, isalpha);
    ret = iter_check_is("ft_isdigit", str, ret, ft_isdigit, isdigit);
    ret = iter_check_is("ft_isalnum", str, ret, ft_isalnum, isalnum);
    ret = iter_check_is("ft_isblank", str, ret, ft_isblank, isblank);
    ret = iter_check_is("ft_isascii", str, ret, ft_isascii, isascii);
    ret = iter_check_is("ft_isprint", str, ret, ft_isprint, isprint);
    ret = iter_check_is("ft_islower", str, ret, ft_islower, islower);
    ret = iter_check_is("ft_isupper", str, ret, ft_isupper, isupper);
    ret = iter_check_is("ft_toupper", str, ret, ft_toupper, toupper);
    ret = iter_check_is("ft_tolower", str, ret, ft_tolower, tolower);
    return (ret);
}

int strlen_arg(int ret, char *str)
{
    if (ft_strlen(str) == strlen(str))
    {
        is_ok(1);
        return (ret);
    }
    else
    {
        is_ok(0);
        return (1 + ret);
    }
}

int check_strlen(int ret)
{
    printf("\n\nft_strlen\n");
    ret = strlen_arg(ret, "123");
    ret = strlen_arg(ret, "");
    ret = strlen_arg(ret, "1234567890");
    return (ret);
}

int check_bzero(int ret)
{
    char *ptr;
    int i = 50;
    
    ptr = NULL;
    printf("\n\nft_bzero\n");    
    ptr = (char *)malloc(sizeof(char) * i);
    ft_bzero(ptr, i);
    while (--i >= 0)
    {
        if (ptr[i] == 0)
            is_ok(1);
        else
        {
            is_ok(0);
            ret++;
        }
    }    
    return (ret);
}

int check_memset(int ret)
{
    char *ptr = NULL;
    int i = 50;

    printf("\n\nft_memset\n");
    ptr = (char *)malloc(sizeof(char) * i);
    ft_memset(ptr, 0, i);
    while (--i >= 0)
    {
        if (ptr[i] == 0)
            is_ok(1);
        else
        {
            is_ok(0);
            ret++;
        }
    }    
    return (ret);
}

int check_memalloc(int ret)
{
    char *ptr = NULL;
    int i = 50;
    int j = 0;

    printf("\n\nft_memalloc\n");
    ptr = ft_memalloc(i);
    while (j < i)
    {
        if (ptr[j] == 0)
            is_ok(1);
        else
        {
            is_ok(0);
            ret++;
        }
        j++;
    }
    return (ret);
}

int check_strcat(int ret)
{
    char *src;
    char *dest;
    int i = 5;
    int j = 0;
    
    printf("\nft_strcat\n");
    src = (char *)malloc(sizeof(char) * i);
    dest = (char *)malloc(sizeof(char) * (i * 2));
    while (j < i)
    {
        src[j] = 'z';
        dest[j] = 'a';
        j++;
    }
    dest = ft_strcat(dest, src);
    j = 0;
    while (j < i * 2)
    {
        if (j < i && dest[j] == 'a')
            is_ok(1);
        else if (dest[j] == 'z')
            is_ok(1);
        else
        {
            is_ok(0);
            ret++;
        }
        j++;
    }
    return (ret);
}

int check_memcpy(int ret)
{
    char src[] = "abc";
    char dest[] = "rst";
    int i = 0;
    
    printf("\n\nft_memcpy\n");
    ft_memcpy(dest, src, ft_strlen(src));
    while (i < ft_strlen(src))
    {
        if (dest[i] == src[i])
            is_ok(1);
        else
        {
            is_ok(0);
            ret++;
        }
        i++;
    }
    return (ret);
}

int check_strdup(int ret)
{
    char *src;
    char *dest;
    int i = 3;
    int j = 0;
    
    src = (char *)malloc(sizeof(char) * i);
    while (j < i)
    {
        src[j] = 'a';
        j++;
    }
    dest = NULL;
    printf("\n\nft_strdup\n");
    dest = ft_strdup(src);
    j = 0;
    while (j < i)
    {
        if (dest[j] == src[j])
            is_ok(1);
        else
        {
            is_ok(0);
            ret++;
        }
        j++;
    }
    return (ret);
}

void check_puts(void)
{
    printf("\n\nft_puts\n");
    ft_puts("\nPUTS\n");
    ft_puts(NULL);
    printf("(null) == OK\n");
}

void call_cat(void)
 {
    int fd = 0;
    
    printf("\n\nft_cat\nHello World !");
    fd = open("hello.world", O_RDONLY);
    ft_cat(fd);    
 }
 
int check_power(int ret)
{
    int i = 5;
    int j = 0;
    
    printf("\n\nft_square\n");
    j = ft_square(i);
    if (j == (i * i))
        is_ok(1);
    else
    {
        is_ok(0);
        ret++;
    }
    return (ret);
}

int main(void)
{
    int ret;    

    ret = 0;
    printf("Start testing :");
    ret = is_to_something(ret);
    ret = check_strlen(ret);
    ret = check_bzero(ret);
    ret = check_memset(ret);
    ret = check_memalloc(ret);
    check_puts();
    ret = check_strcat(ret);
    ret = check_memcpy(ret);
    ret = check_strdup(ret);
    call_cat();
    check_power(ret);
    printf("\n\nfailed: %i\n", ret);
    return (ret > 0 ? 1 : 0);
}