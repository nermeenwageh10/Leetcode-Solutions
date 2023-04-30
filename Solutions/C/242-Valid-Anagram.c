bool isAnagram(char * s, char * t){
    bool retVal = true;
    int *s_map = (int*)calloc(26,sizeof(int));
    int *t_map = (int*)calloc(26,sizeof(int));
    if(strlen(s) == strlen(t))
    {
        for(int i = 0 ; i <strlen(s) ; i++)
        {
            s_map[(s[i]-'a')]++;
            t_map[(t[i]-'a')]++;
        }
        for(int i = 0 ; i < 26 ; i++)
        {
            if(s_map[i] != t_map[i])
            {
                retVal = false;
            }

        }

    }
    else
    {
        retVal = false;
    }
    return retVal;
}