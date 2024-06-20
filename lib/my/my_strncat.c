/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday07-florian.reynaud
** File description:
** my_strncat
*/

static int my_strlen8(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strncat(char *dest, char const *src, int n)
{
    int len = my_strlen8(dest) - my_strlen8(src) + n;
    int i = 0;

    while (src[i] != '\0' && n != 0){
        dest[len] = src[i];
        i++;
        len++;
        n--;
    }
}
