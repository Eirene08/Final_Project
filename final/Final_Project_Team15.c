/* 
FINAL PROJECT - BANK MANAGEMENT SYSTEM

DESCRIPTION:
    A program to manage several saving accounts. The program must have a feature to create new account and save its data. The new account will have
data about account’s owner name, contacts, its creation date, and its initial saving sum (in IDR).
The program also needs to have a feature to deposit and withdraw some value from an account.
There is a limit for deposit and withdraw that must be enforced by the program. The minimum
amount of deposit is Rp. 100.000. Any value below that limit should be responded by proper
error message. The maximum value of withdrawal is Rp. 5.000.000. Any value exceeds that
limit should be responded by proper error message. The program also needs to have a feature
to close an account. If this feature is chosen, the account data should be deleted from the
program.

LECTURER:
        - Dr. DANY EKA SAPUTRA, S.T., M.T. (D6407)
        - MARIA AULERIA (LB001)

TEAM 15:
        - CHRYSANT MAKMUR_2502025694
        - AYASHA KUNTUM AMARANTI_2502006133
        - NAUFAL DAFFA RYQUELME_2502012312      */

// file header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lli long long int
#define MAX_SIZE 1000

// Struct
typedef struct bankData {
    lli Saldo;
    char Name[50];
    char pin[10];
    struct clientData {
        char NoPhone[30];
        char Address[200];
    } person;
    struct  createdTime{
        char year[5];
        char month[15];
        char day[3];
    } times;
} bankData;

// declare function
void team15();
void displayFeaturesN();
void displayFeaturesY();
void displayTransaction();
void createFileData();
void printall();
int option1(char *act);
void createAccount();
int validationUser(int hasil);
void transaction();
void closeAccount();
void nowUser(char *pin, char *username);
void accountInfo();

/**
 * @brief 
 * 
 * @return int 
 */

// main function
int main() {
    // declare new variable
    char action;
    int count;

    // check user account

    // input validation account
    team15();
    printf("\t\t     Do you Have Account?[Y/N]\n");
    printf("\t\t     Input: ");
    scanf("%c", &action);
    option1(&action);
    printf("\n\t\t   ALERT: INCORRECT, PLEASE TRY AGAIN!");
    // return value 0
    getchar();
    return 0;
}

void accountInfo() {
    bankData s;
    FILE *stream;
    stream = fopen("bank.txt", "r");
    
    char pin[9];
    char username[50];
    
    team15();
    printf("\n\n\t\t\t\t    ---------\n");
    printf("\t\t\t\t    | LOGIN |\n");
    printf("\t\t\t\t    ---------\n");

    fflush(stdin);
    printf("\n\t\t     Name\t: ");
    scanf("%[^\n]s", username);

    fflush(stdin);
    printf("\t\t     PIN \t: ");
    scanf("%[^\n]s", pin);

    system("cls");
    team15();

    while(fread(&s, sizeof(bankData), 1, stream)) {
        if((strcmp(s.pin, pin) == 0) && (strcmp(s.Name, username) == 0)) {
            printf("\n\t\t\t\t\t\t    ACCOUNT INFO");
            printf("\n\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
            printf("\n\n\t\t      >>  NAMA");
            printf("\n\n\t\t            %s\n", s.Name);
            printf("\n\t\t      >>  PIN");
            printf("\n\n\t\t            *********\n");
            printf("\n\t\t      >>  NUMBER PHONE");
            printf("\n\n\t\t            %s\n", s.person.NoPhone);
            printf("\n\t\t      >>  ADRRESS");
            printf("\n\n\t\t             %s\n", s.person.Address);
            printf("\n\t\t      >>  TIME CREATED");
            printf("\n\n\t\t             %s/%s/%s\n", s.times.day, s.times.month, s.times.year);
            printf("\n\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
            printf("\n\t\t   PRESS ENTER TO RETURN TO THE MAIN MENU!");
            // getchar();
        }
    }

    fclose(stream);
}

void nowUser(char *pin, char *username) {
    bankData s1;
    FILE *stream;
    stream = fopen("bank.txt", "r");

    while(fread(&s1, sizeof(bankData), 1, stream)) {
        if((strcmp(s1.pin, pin) == 0) && (strcmp(s1.Name, username) == 0)) {
            printf("\n\t\t   _______________________________________\n");
            printf("\n\t\t    >> CARD NUMBER                ");
            printf("\n\n\t\t          **** **** **** ****\n");
            printf("\n\t\t    >> NAME");
            printf("\n\n\t\t          %s\n", s1.Name);
            printf("\n\t\t    >> WALLET(IDR)");
            int n = 0, scale = 1;
            while (s1.Saldo >= 1000) {
                n = n + scale * (s1.Saldo % 1000);
                s1.Saldo /= 1000;
                scale *= 1000;
            }
           
            printf ("\n\n\t\t          Rp%lld", s1.Saldo);
           
            while (scale != 1) {
                scale /= 1000;
                s1.Saldo = n / scale;
                n = n  % scale;
                printf (".%03lld", s1.Saldo);
            }
            printf("\n\t\t   _______________________________________\n");
        }
    } 
    
    fclose(stream);
}

void transaction() {
    bankData s1;
    FILE *stream, *windowlog;

    char pin[9], username[50], choose;
    lli idr;
    int find, option;

    printf("\n\n\t\t\t\t    ---------\n");
    printf("\t\t\t\t    | LOGIN |\n");
    printf("\t\t\t\t    ---------\n");

    fflush(stdin);
    printf("\n\t\t     Name\t: ");
    scanf("%[^\n]s", username);

    fflush(stdin);
    printf("\t\t     PIN \t: ");
    scanf("%[^\n]s", pin);
    system("cls");
    team15();
    stream = fopen("bank.txt", "r");
    
    while(fread(&s1, sizeof(bankData), 1, stream)) {
        if((strcmp(s1.pin, pin) == 0) && (strcmp(s1.Name, username) == 0)) {
            if (s1.Saldo == 0) {
                printf("\n\t\t     ALERT: WALLET(IDR) now Rp%lld, to make a transaction. Please make a deposit!\n", s1.Saldo);
            }
        }
    } 
    
    fclose(stream);
    nowUser(pin, username);
    
    stream = fopen("bank.txt", "r");
    windowlog = fopen("windowlog.txt", "w");
    
    printf("\n\n\t\t     Do you want to make a transaction now? [y/n]");
    printf("\n\t\t     Input: ");
    scanf(" %c", &choose);
    
    system("cls");
    team15();
    nowUser(pin, username);
    
    if (choose == 'y' || choose == 'Y') {
        do {
            system("cls");
            team15();
            nowUser(pin, username);
            printf("\n\t\t     ALERT: CHOOSE FEATURES U WANNA USE!\n");
            displayTransaction();
            printf("\t\t     Input: ");
            scanf("%d", &option);
            system("cls");
            
            switch(option) {
                case 1:
                    // system("cls");
                    nowUser(pin, username);
                    printf("\n\t\t     ALERT: MINIMUM DEPOSITE Rp100.000\n");
                    printf("\n\t\t     Deposit Amount: ");
                    scanf("%lld", &idr);
                    if (idr < 100000) {
                        printf("\n\t\t    ALERT: MINIMUM DEPOSITE Rp100.000\n");
                        idr = 0;
                    }

                    stream = fopen("bank.txt", "r");
                    windowlog = fopen("windowlog.txt", "w");
                    
                    while(fread(&s1, sizeof(bankData), 1, stream)) {
                        if((strcmp(s1.pin, pin) == 0) && (strcmp(s1.Name, username) == 0)) {
                            if(idr == 0) {
                                find = 0;
                            }else {
                                s1.Saldo = s1.Saldo + idr;
                                find = 1;
                            }
                        }
                        fwrite(&s1, sizeof(bankData), 1, windowlog);
                    }
                    
                    fclose(stream);
                    fclose(windowlog);
                    
                    if (find == 1) {
                        windowlog = fopen("windowlog.txt", "r");
                        stream = fopen("bank.txt", "w");
                        while (fread(&s1, sizeof(bankData), 1, windowlog)) {
                            fwrite (&s1, sizeof(bankData), 1, stream);
                        }
                        
                        fclose(stream);
                        fclose(windowlog);
                        printf("\n\t\t     ALERT: DEPOSIT AMOUNT: Rp%lld SUCCESSFULLY ADDED!\n", idr);
                    }else if (find == 0) {
                        printf("\n\t\t     ALERT: YOUR DEPOSIT WAS NOT SUCCESSFUL!\n");
                    }
                    getchar();
                    break;
                case 2:
                    system("cls");
                    nowUser(pin, username);
                    printf("\n\t\t     ALERT: MAXIMUM WITHDRAW Rp5.000.000\n");
                    printf("\n\t\t     Withdraw Amount: ");
                    scanf("%lld", &idr);
                    
                    if (idr > 5000000 || idr < 0) {
                        idr = 0;
                    }
                    
                    stream = fopen("bank.txt", "r");
                    windowlog = fopen("windowlog.txt", "w");
                    
                    while(fread(&s1, sizeof(bankData), 1, stream)) {
                        if((strcmp(s1.pin, pin) == 0) && (strcmp(s1.Name, username) == 0)) {
                            if (s1.Saldo < idr) {
                                find = 0;
                            }else if (s1.Saldo >= idr) {
                                s1.Saldo = s1.Saldo - idr;
                                find = 1;         
                            }
                        }
                        fwrite(&s1, sizeof(bankData), 1, windowlog);
                    }

                    fclose(stream);
                    fclose(windowlog);
                    
                    if (find == 1) {
                        windowlog = fopen("windowlog.txt", "r");
                        stream = fopen("bank.txt", "w");
                        
                        while (fread(&s1, sizeof(bankData), 1, windowlog)) {
                            fwrite (&s1, sizeof(bankData), 1, stream);
                        }
                        
                        fclose(stream);
                        fclose(windowlog);
                        
                        if (idr > 0 && idr <= 5000000) {
                            printf("\n\t\t     ALERT: WITHDRAW AMOUNT: Rp%lld SUCCESSFULLY!\n", idr);
                            getchar();
                        }
                    }else if (find == 0) {
                        printf("\n\t\t     ALERT: WITHDRAW WAS NOT SUCCESSFULLY! CHECK AGAIN!\n");
                        printf("\n\t\t     ALERT: YOUR WALLET IS NOT ENOUGH!\n");
                        printf("\n\t\t     ALERT: TRANSACTION FAILED!\n");
                    }
                    break;
                case 0:
                    printf("\n\t\t     ALERT: RETURN TO THE MAIN PROGRAM\n");
                    // getchar();
                    break;
                default:
                    printf("\n\t\t     ALERT: INCORRECT, PLEASE TRY AGAIN\n");
                    break;
            }
            // fclose(stream);
            // fclose(windowlog);
            // system("cls");
        } while (option != 0);
    }else {
        printf("\n\t\t     ALERT: INCORRECT, PLEASE TRY AGAIN\n");
    }

    fclose(stream);
    fclose(windowlog);

    printf("\n\t\t     PRESS ENTER TO RETURN TO THE MAIN MENU!");
    getchar();
}

void closeAccount() {
    bankData s1;
    FILE *stream, *windowlog;

    stream = fopen("bank.txt", "r");
    windowlog = fopen("windowlog.txt", "w");
    
    int found;
    char pin[9];
    char username[50];
    char delete[7];

    // input name & pin
    printf("\n\t\t\t\t     DELETE ACCOUNT");
    printf("\n\t\t     - - - - - - - - - - - - - - - - - - - - - -");
    fflush(stdin);
    printf("\n\t\t     ACCOUNT NAME : ");
    scanf("%[^\n]s", username);
    fflush(stdin);
    printf("\t\t     ACCOUNT PIN  : ");
    scanf("%[^\n]s", pin);
    printf("\t\t     - - - - - - - - - - - - - - - - - - - - - -\n");

    do {
        printf("\n\t\t     ALERT: Write \"Delete\" to continue.\n");
        printf("\n\t\t     Input: ");
        scanf(" %[^\n]s", delete);
        if ((strcmp(delete, "Delete!") < 0) || (strcmp(delete, "Delete!") > 0)) {
            printf("\n\t\t     ALERT: The input does not match the pattern.\n");
        }
    } while (strcmp(delete, "Delete!") == 0);

    while (fread(&s1, sizeof(bankData), 1, stream)) {
        if((strcmp(s1.pin, pin) == 0) && (strcmp(s1.Name, username) == 0)) {
            printf("Hahaha");
            found = 1;
        }else{
            fwrite(&s1, sizeof(bankData), 1, windowlog);
        }
    }

    fclose(stream);
    fclose(windowlog);
    
    if (found) {
        windowlog = fopen("windowlog.txt", "r");
        stream = fopen("bank.txt", "w");

        while (fread(&s1, sizeof(bankData), 1, windowlog)) {
            fwrite (&s1, sizeof(bankData), 1, stream);
        }

        fclose(stream);
        fclose(windowlog);
        printf("\n\t\t     ALERT: ACCOUNT CLOSURE WAS SUCCESSFUL");
    }else {
        printf("\n\t\t     ALERT: ACCOUNT WAS NOT FOUND");
    }
}

void printall() {
    bankData s1;
    FILE *stream;
    stream = fopen("bank.txt", "r");

    while(fread(&s1, sizeof(bankData), 1, stream)) {
        printf("\n\t\t     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("\n\t\t     Nama: %s\n", s1.Name);
        printf("\n\t\t     PIN: %s\n", s1.pin);
        printf("\n\t\t     No HP: %s\n", s1.person.NoPhone);
        printf("\n\t\t     Address: %s\n", s1.person.Address);
        printf("\n\t\t     Created: %s/%s/%s\n", s1.times.year, s1.times.month, s1.times.day);
        printf("\n\t\t     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    }
    fclose(stream);
    
}

void createAccount() {
    bankData *s;
    FILE *stream;
    stream = fopen("bank.txt", "a");
    int n, i;

    printf("\t\t     How many account u wanna create: ");
    scanf("%d", &n);

    s = (bankData*) calloc(n, sizeof(bankData));

    for (i = 0; i < n; i++) {
        printf("\n\t\t\t\t          ___________________________\n");
        printf("\n\t\t\t\t               CREATE ACCOUNT #%d", i+1);
        printf("\n\t\t\t\t          ___________________________\n");
        fflush(stdin);
        printf("\n\t\t     ____________________________________________________________________\n\n");
        printf("\n\t\t      >> NAME         : ");
        scanf("%[^\n]s", s[i].Name);

        fflush(stdin);
        printf("\n\t\t      >> NUMBER PHONE : ");
        scanf("%[^\n]s", s[i].person.NoPhone);

        fflush(stdin);
        printf("\n\t\t      >> ADDRESS      : ");
        scanf("%[^\n]s", s[i].person.Address);

        fflush(stdin);
        printf("\n\t\t      >> PIN          : ");
        scanf("%[^\n]s", s[i].pin);
        
        fflush(stdin);
        printf("\n\t\t      >> YEAR         : ");
        scanf("%[^\n]s", s[i].times.year);

        fflush(stdin);
        printf("\n\t\t      >> MONTH        : ");
        scanf("%[^\n]s", s[i].times.month);

        fflush(stdin);
        printf("\n\t\t      >> DAY          : ");
        scanf("%[^\n]s", s[i].times.day);

        fwrite(&s[i], sizeof(bankData), 1, stream);
        printf("\n\t\t     ALERT: ACCOUNT #%d CREATED SUCCESSFULLY.\n", i+1);
        printf("\n\t\t     ____________________________________________________________________\n\n");
        // getchar();
    }

    if (stream) {
        printf("\n\t\t     ALERT: %d ACCOUNT CREATED SUCCESSFULLY.\n", n);
    } else if (stream == NULL) {
        printf("\n\t\t     ALERT: DATA FILE WAS NOT CREATED SUCCESSFULLY.\n");
    }
    getchar();
    // system("cls");
    
    fclose(stream);
}

void createFileData() {
    bankData *s;
    FILE *stream;
    stream = fopen("bank.txt", "w");
    
    if (stream) {
        printf("\n\t\t     ALERT: DATA FILE CREATED SUCCESSFULLY.\n");
    } else {
        printf("\n\t\t     ALERT: DATA FILE WAS NOT CREATED SUCCESSFULLY.\n");
    }
    
    fclose(stream);
    getchar();
    // system("cls");

}

int option1(char *act) {
    int valid = 0, option, success, count = 5;
    do {
        if ((*act == 'y') || (*act == 'Y')) {        
            system("cls");
            team15();
            
            do {
                count--;
                if (count == 0) {
                    getchar();
                    printf("\n\t\t     ALERT: EXIT , YOU EXCEED THE MAXIMUM LIMIT!");
                    return(-1);

                }
                valid = validationUser(0);
                printf("\n\t\t     ALERT: Sorry, your pin or username was incorrect.\n");
                printf("\t\t            Please double-check your password.\n");
            } while (valid==0);
            system("cls");

            do {
                team15();
                printf("\n\t\t     ALERT: CHOOSE FEATURES U WANNA USE!\n");
                // function calls

                displayFeaturesY();
                printf("\t\t     Input: ");

                // input option
                scanf("%d", &option);
                system("cls");

                // condition option of feature
                switch(option) {
                    case 1:
                        // function create call
                        accountInfo();
                        getchar();
                        break;
                    case 2:
                        // function create call
                        team15();   
                        transaction(); 
                        break;
                    case 3:
                        // function deposite or withdraw call
                        closeAccount();
                        break;
                    case 0:
                        // exit program
                        printf("\n\t\t     Output: Exit Program!\n");
                        exit(1);
                        break;
                    default:
                        team15();
                        // else condition
                        printf("\n\t\t     Output: Incorrect, Feature Not Found!\n");
                        break;
                }
                getchar();
                system("cls");
            } while (option != 0);
        }else if (*act == 'n' || *act == 'N') {
            system("cls");
            team15();
            printf("\n\t\t     ALERT: PLEASE CREATE UR ACCOUNT FIRST!\n");
            do {
                
                // function calls
                displayFeaturesN();
                printf("\t\t     Input: ");
                scanf("%d", &option);

                // condition option of feature
                switch(option) {
                    case 1:
                        // function create call
                        // system("cls");
                        // team15();
                        createFileData();
                        
                        break;
                    case 2:
                        // function create call
                        system("cls");
                        team15();
                        createAccount();
                        success = 1;
                        break;
                    case 0:
                        // exit program
                        printf("\n\t\t     ALERT: MAIN PROGRAM!");
                        *act = 'y';
                        break;
                    default:
                        // else condition
                        printf("\n\t\t\t    Output: Incorrect, Feature Not Found!\n");
                        break;
                }
                printf("\n\t\t     PRESS ENTER TO CONTINUE!");
                getchar();
                system("cls");
                team15();
            } while (option != 0);
        }
    }while (1);
}

int validationUser(int hasil) {
    FILE *stream;
    bankData s;
    stream = fopen("bank.txt", "r");
    if (stream == NULL) {
        printf("\n\t\t     ALERT: FILE NOT FOUND\n");
        exit(1);
    }
    
    char pin[9];
    char username[50];
    hasil = 0;

    // input name & pin
    // printf("\n\t\t     - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\n\n\t\t\t\t    ---------\n");
    printf("\t\t\t\t    | LOGIN |\n");
    printf("\t\t\t\t    ---------\n");

    fflush(stdin);
    printf("\n\t\t     NAME\t: ");
    scanf("%[^\n]s", username);

    fflush(stdin);
    printf("\t\t     PIN \t: ");
    scanf("%[^\n]s", pin);
    // printf("\t\t     - - - - - - - - - - - - - - - - - - - - - -\n"); 
    
    // Validation
    while(fread(&s, sizeof(bankData), 1, stream)){
        if((strcmp(s.pin, pin) == 0) && (strcmp(s.Name, username) == 0)) {
            // printf("%s %s", s.Name, s.pin);
            hasil = 1;
            
            return hasil;
        }
        if ((strcmp(s.pin, pin) != 0) || (strcmp(s.Name, username) != 0)) {
            // printf("Not Found!\n");
            // printf("\n\t\t     ALERT: Sorry, your pin or username was incorrect.\n");
            hasil = 0;
            continue;
        }
    }
        
    fclose(stream);
    
    return 0;
}

void displayFeaturesY() {
    printf("\t\t     _________________________________________\n");
    printf("\t\t    |                                         |\n");
    printf("\t\t    |         - PROGRAM   FEATURES -          |\n");
    printf("\t\t    |                                         |\n");
    printf("\t\t    |                                         |\n");
    printf("\t\t    |   1 ->  ACCOUNT INFO                    |\n");
    printf("\t\t    |   2 ->  DEPOSIT / WITHDRAW CASH         |\n");
    printf("\t\t    |   3 ->  CLOSE ACCOUNT                   |\n");
    printf("\t\t    |   0 ->  EXIT                            |\n");
    printf("\t\t    |                                         |\n");
    printf("\t\t    |                                         |\n");
    printf("\t\t    |       - - -  W E    B A N K  - - -      |\n");
    printf("\t\t    |_________________________________________|\n");
}

void displayFeaturesN() {
    printf("\t\t     _________________________________________\n");
    printf("\t\t    |                                         |\n");
    printf("\t\t    |         - PROGRAM   FEATURES -          |\n");
    printf("\t\t    |                                         |\n");
    printf("\t\t    |   1 -> CREATE FILE DATA                 |\n");
    printf("\t\t    |   2 -> CREATE ACCOUNT                   |\n");
    printf("\t\t    |   0 -> MAIN PROGRAM                     |\n");
    printf("\t\t    |                                         |\n");
    printf("\t\t    |                                         |\n");
    printf("\t\t    |       - - -  W E    B A N K  - - -      |\n");
    printf("\t\t    |_________________________________________|\n");
    
}

void displayTransaction() {
    printf("\t\t     _________________________________________\n");
    printf("\t\t    |                                         |\n");
    printf("\t\t    |         - TRANSACTION   FEATURES -      |\n");
    printf("\t\t    |                                         |\n");
    printf("\t\t    |   1 -> DEPOSIT                          |\n");
    printf("\t\t    |   2 -> WITHDRAW                         |\n");
    printf("\t\t    |   0 -> MAIN PROGRAM                     |\n");
    printf("\t\t    |                                         |\n");
    printf("\t\t    |_________________________________________|\n");
}

void team15() {
    printf("\n\n");
    printf("\t\t __________ \t  _______ \t   ______ \t _____________  \t\n");
    printf("\t\t|___    ___|\t |   ____|\t /   _   \\\t|     ___     |\t\n");
    printf("\t\t    |  |    \t |  |____ \t|   ___   |\t|    +___+    |\t ====\n");
    printf("\t\t    |  |    \t |   ____|\t|  |   |  |\t|  |  | |  |  |\t\" 15 \"\n");
    printf("\t\t    |  |    \t |  |____ \t|  |   |  |\t|  |  | |  |  |\t ====\n");
    printf("\t\t    |__|    \t |_______|\t|__|   |__|\t|__|  |_|  |__|\t\n\n\n");
    printf("\t\t| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |\n\n\n");

}