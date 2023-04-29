/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    *returnColumnSizes = (int*)calloc(numRows, sizeof(int));
    if(*returnColumnSizes == NULL)
    {
        return NULL;
    }
    /*1-Create an array of arrays*/
    int **arrOfArrs = (int **)calloc(numRows,sizeof(int *));
    if(NULL == arrOfArrs)
    {
        return NULL;
    }
    else
    {
        int NULL_FLAG = 0;
        for(int i = 0 ; i < numRows ; i++)
        {
            arrOfArrs[i] = (int*)calloc(i+1,sizeof(int));
            (*returnColumnSizes)[i] = i+1;
            if(NULL == arrOfArrs[i])
            {
                NULL_FLAG = 1;
                break;
            }
        }
        if(!NULL_FLAG)
        {
            (arrOfArrs[0])[0] = 1; /* 1 */
            for(int i = 1 ; i <(numRows) ; i++)
            {   

                /*Always the 1st and last elements in onw row equal to 1*/
                (arrOfArrs[i])[0] = 1;
                (arrOfArrs[i])[i] = 1;

                for(int j = 1 ; j < i ; j++)
                {
                    (arrOfArrs[i])[j] = (arrOfArrs[i-1])[j] + (arrOfArrs[i-1])[j-1];
                }
            }
        }
        else
        {
            return NULL;
        }  
    }
    return arrOfArrs;
}