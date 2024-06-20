/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-florian.reynaud
** File description:
** my_strstr
*/

static int test_same_str(char *str, int i, char const *to_find)
{
    int j = 0;

    while (to_find[j] == '\0' || str[i + j] == to_find[j]){
        if (to_find[j] == '\0'){
            return (1);
        }
        j++;
    }
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    while (str[i] != '\0') {
        if (test_same_str(str, i, to_find)){
            return (&str[i]);
        }
        i++;
    }
    return (0);
}
