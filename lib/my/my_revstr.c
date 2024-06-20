/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-florian.reynaud
** File description:
** my_revstr
*/

static int my_strlen2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

static void my_swap2(char *a, char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int len = my_strlen2(str);
    int range = len / 2;
    int i = 0;
    char *ptr1;
    char *ptr2;

    len -= 1;
    while (i < range){
        ptr1 = &str[i];
        ptr2 = &str[len - i];
        my_swap2(ptr1, ptr2);
        i++;
    }
    return (str);
}
