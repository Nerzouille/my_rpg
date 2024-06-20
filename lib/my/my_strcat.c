/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday07-florian.reynaud
** File description:
** my_strcat
*/

static int my_strlen7(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen7(dest);
    int i = 0;

    while (src[i] != '\0'){
        dest[len] = src[i];
        i++;
        len++;
    }
    dest[len] = '\0';
    return (dest);
}
