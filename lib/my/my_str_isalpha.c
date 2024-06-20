/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-florian.reynaud
** File description:
** my_str_isalpha
*/

int my_char_isalpha(char c)
{
    if (c >= 'A' && c <= 'Z'){
        return (1);
    }
    if (c >= 'a' && c <= 'z'){
        return (1);
    }
    return (0);
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (!my_char_isalpha(str[i])){
            return (0);
        }
        i++;
    }
    return (1);
}
