/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-florian.reynaud
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0'){
        if (s1[i] > s2[i]){
            return (1);
        }
        if (s1[i] < s2[i]){
            return (-1);
        }
        i++;
    }
    if (s1[i] == '\0' && s2[i] != '\0'){
        return (-1);
    } else if (s2[i] == '\0' && s1[i] != '\0'){
        return (1);
    } else {
        return (0);
    }
}
