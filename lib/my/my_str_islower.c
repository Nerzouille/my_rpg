/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-florian.reynaud
** File description:
** my_str_islower
*/

static int char_islower(char c)
{
    if (c >= 'a' && c <= 'z'){
        return (1);
    }
    return (0);
}

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (!char_islower(str[i])){
            return (0);
        }
        i++;
    }
    return (1);
}
