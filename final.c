#include <stdio.h>
int main()
{
    printf("Any password is possible besides false\n");
    char pass[100];
    printf("Enter Password:\n");
    scanf("%c", pass);
    while (pass == 'false')
    {
        prnitf("Harap masukkan password\n");
        scanf("%c", pass);
    }
    
    return 0;
}