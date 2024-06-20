/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-florian.reynaud
** File description:
** my_strcapitalize
*/

static int is_lowcase(char c)
{
    if (c >= 'a' && c <= 'z'){
        return (1);
    } else {
        return (0);
    }
}

static int is_upcase(char c)
{
    if (c >= 'A' && c <= 'Z'){
        return (1);
    } else {
        return (0);
    }
}

static int is_number(char c)
{
    if (c >= '0' && c <= '9'){
        return (1);
    } else {
        return (0);
    }
}

static int is_word_charachter(char c)
{
    if (is_lowcase(c)){
        return (1);
    }
    if (is_upcase(c)){
        return (1);
    }
    if (is_number(c)){
        return (1);
    }
    return (0);
}

static char transform_upcase(char c)
{
    if (c >= 'a' && c <= 'z'){
        return (c - 32);
    }
    return (c);
}

static char transform_lowcase(char c)
{
    if (c >= 'A' && c <= 'Z'){
        return (c + 32);
    }
    return (c);
}

char *my_strcapitalize(char *str)
{
    int in_word = 0;
    int i = 0;

    while (str[i] != '\0'){
        if (in_word && is_word_charachter(str[i])) {
            str[i] = transform_lowcase(str[i]);
        }
        if (!in_word && is_word_charachter(str[i])) {
            str[i] = transform_upcase(str[i]);
            in_word = 1;
        }
        if (!is_word_charachter(str[i])) {
            in_word = 0;
        }
        i++;
    }
}
