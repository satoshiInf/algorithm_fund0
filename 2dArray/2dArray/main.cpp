
#include <cstdio>

int main(void)
{
    //配列　↓　→で構成
    char a[][6] = {
        "Super", "X", "TRY"
    };
    
    /*
     a[0] = {'S', 'u', 'p', 'e', 'r', '\0'}
     a[1] = {'X', '\0', ???, ???, ???, ???}
     a[2] = {'T', 'R', 'Y', '\0', ???, ???}
     */
    


    for (int i = 0; i < 3; i++)
        printf("%s\n", a[i]);
    
    char *p[] =
    {
        "Super", "X", "TRY"
    };

    for (int i = 0; i < 3; i++)
        printf("%s\n", p[i]);


    return 0;
}
