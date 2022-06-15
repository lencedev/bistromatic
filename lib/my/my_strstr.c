/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task05
*/

int compare_str_to_find(char *str, char const *to_find)
{
    int i;

    for (i = 0; to_find[i] != '\0'; i++) {
        if (str[i] != to_find[i])
            return 0;
    }
    return 1;
}

int verification(char *str, char const *to_find)
{
    int a = 0;

    if (str[0] == to_find[0])
        a = compare_str_to_find(str, to_find);
    return a;
}

char *my_strstr(char *str , char const *to_find)
{
    int i;
    int a;

    for (i = 0; str[i] != '\0'; i++) {
        a = verification(&str[i], to_find);
        if (a == 1)
            return (&str[i]);
    }
    return 0;
}
