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
    int pilih;
    printf("1. Write a diary\n");
    printf("2. Read diary entry\n");
    printf("3. Delete an entry\n");
    scanf("%d", &pilih);
    while(pilih != 1 && pilih != 2 && pilih != 3)
    {
        printf("Please enter a number based on the choice given\n");
    }
    if(pilih == 1)
    {
        printf("Write your diary\n");
        printf("Enter 000 to mark the end of passage\n");
        
    }
    return 0;
}