/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-florian.reynaud
** File description:
** my_strncmp
*/

static int test_endstr(char const *s1, char const *s2, int i)
{
    if (s1[i] == '\0' && s2[i] != '\0'){
        return (-1);
    } else if (s2[i] == '\0' && s1[i] != '\0'){
        return (1);
    } else {
        return (0);
    }
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && i < n){
        if (s1[i] > s2[i]){
            return (1);
        }
        if (s1[i] < s2[i]){
            return (-1);
        }
        i++;
    }
    if (i == n){
        i--;
    }
    return (test_endstr(s1, s2, i));
}
