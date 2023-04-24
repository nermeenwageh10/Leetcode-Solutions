int lengthOfLastWord(char *s)
{
    /*Calculate string size*/
    int str_size = 0;
    while (*(s + str_size++) != '\0')
        ;
    --str_size;

    int num_spaces = 0;
    while ((str_size - 1 - num_spaces) >= 0 && *(s + str_size - 1 - num_spaces) == ' ')
    {
        num_spaces++;
    }

    int len = 0;
    while ((str_size - 1 - num_spaces - len) >= 0 && *(s + str_size - 1 - num_spaces - len) != ' ')
    {
        len++;
    }
    return len;
}