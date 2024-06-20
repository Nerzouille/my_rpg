/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-florian.reynaud
** File description:
** my_str_isprintable
*/

static int char_isprintable(char c)
{
    if (c >= 33 && c <= 126){
        return (1);
    }
    return (0);
}

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (!char_isprintable(str[i])){
            return (0);
        }
        i++;
    }
    return (1);
}
