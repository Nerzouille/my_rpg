/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-florian.reynaud
** File description:
** my_str_isupper
*/

static int char_isupper(char c)
{
    if (c >= 'A' && c <= 'Z'){
        return (1);
    }
    return (0);
}

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (!char_isupper(str[i])){
            return (0);
        }
        i++;
    }
    return (1);
}
