/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-florian.reynaud
** File description:
** my_str_isnum
*/

int my_char_isnum(char c)
{
    if (c >= '0' && c <= '9'){
        return (1);
    }
    return (0);
}

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (!my_char_isnum(str[i])){
            return (0);
        }
        i++;
    }
    return (1);
}
