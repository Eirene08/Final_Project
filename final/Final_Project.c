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
/**
 * @declare: long long int saldo
 * @declare: char Name[50], pin[10], NoPhone[30], Adress[200], year[5], month[15], day[3]
 */
typedef struct bankData {
    lli Saldo;
    char Name[50];
    char pin[10];
    struct clientData {
        char NoPhone[30];
        char Address[200];
    } person;
    struct  createdTime {
        char year[5];
        char month[15];
        char day[3];
    } times;
} bankData;

// declare function
// display team15 (NAMA KELOMPOK)
void team15();
// display features menu, jika user blm memiliki akun, jika user sudah memiliki akun
void display(char act);
// display features menu transaksi. Di menu no 2
void displayTransaction();
// membuat file dengan nama bank.txt
void createFileData();
void printall();
// fungsi untuk mengatur opsi yang dipilih user
int optionFeatures(char *act);
// membuat akun client dengan menginputkan data pribadi
void createAccount();
// fungsi untuk masuk ke dalam program dan memastikan user memiliki akun (LOGIN)
int validationUser(int hasil);
// fungsi untuk depo / withdraw
void transaction();
// fungsi untuk tutup akun
void closeAccount();
// fungsi untuk memeriksa akun sekarang(akun yang digunakan saat login)
void nowUser(char *pin, char *username);
// display data diri akun user
void accountInfo();

/**
 * @description: menjalankan main function
 * @declare: char action
 * @decalre: int count
 * @call: team15()
 * @output: tampilan berdasarkan inputan
 * @return int 
 * @author: Chrysant M
 */
int main() {

    // declare new variable
    char action;
    int count;
    
    do {
        team15();
        printf("\t\t     Do you Have Account?[Y/N]\n");
        printf("\t\t     Input: ");
        scanf("%c", &action);
        if((action != 'y') || (action != 'Y') || (action != 'N') || (action != 'n')) {
            printf("\n\n\t\t     ALERT: INCORRECT, PLEASE TRY AGAIN!");
            getchar();
        }
        if((action == 'y') || (action == 'Y') || (action == 'N') || (action == 'n')) {
            optionFeatures(&action);
        }
        system("cls");
    } while((action != 'y') || (action != 'Y') || (action != 'N') || (action != 'n'));    

    // return value 0
    getchar();
    return 0;
}

/**
 * @description: prosedur untuk menampilkan fitur menu berdasarkan inputan
 * @param: char act
 * @output: menampilkan fitur menu berdasarkan inputan
 * @author: Chrysant M
 */
void display(char act){
    if (act == 'y') {
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
    }else if (act == 'n') {
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
    
}

/**
 * @description: prosedur untuk  menampilkan data diri client
 * @objek: s ke bankData
 * @declare: int find
 * @declare: char pin[9] , username[50]
 * @call: team15(), 
 * @input: username dan pin client
 * @output: data diri client
 * @author: Chrysant M
 */
void accountInfo() {
    bankData s;
    FILE *stream;
    stream = fopen("bank.txt", "r");
    int find;
    char pin[9];
    char username[50];
    
    team15();
    printf("\n\n\t\t\t\t    ---------\n");
    printf("\t\t\t\t    | LOGIN |\n");
    printf("\t\t\t\t    ---------\n");

    fflush(stdin);
    printf("\n\t\t     NAME\t: ");
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

/**
 * @description: prosedur untuk memeriksa akun yang digunakan saat login
 * @objek: s1 ke bankData
 * @output: info dari data client
 * @author: Naufal Daffa
 */
void nowUser(char *pin, char *username) {
    bankData s1;
    FILE *stream;
    stream = fopen("bank.txt", "r");
    int n = 0, scale = 1;

    while(fread(&s1, sizeof(bankData), 1, stream)) {
        if((strcmp(s1.pin, pin) == 0) && (strcmp(s1.Name, username) == 0)) {
            printf("\n\t\t     _______________________________________\n");
            printf("\n\t\t        >> CARD NUMBER                ");
            printf("\n\n\t\t              **** **** **** ****\n");
            printf("\n\t\t        >> NAME");
            printf("\n\n\t\t              %s\n", s1.Name);
            printf("\n\t\t        >> WALLET(IDR)");
            while (s1.Saldo >= 1000) {
                n = n + scale * (s1.Saldo % 1000);
                s1.Saldo /= 1000;
                scale *= 1000;
            }
    
            printf ("\n\n\t\t              Rp%lld", s1.Saldo);
    
            while (scale != 1) {
                scale /= 1000;
                s1.Saldo = n / scale;
                n = n  % scale;
                printf (".%03lld", s1.Saldo);
            }
            printf("\n\t\t     _______________________________________\n");
        }
    } 
    
    fclose(stream);
}

/**
 * @description: prosedur melakukan deposit dan withdraw
 * @objek: s1 ke bankData
 * @input: username dan pin client, choose, option, idr
 * @call: team15(), nowUser(pin, username)
 * @output: jumlah uang setelah melakukan transaksi
 * @author: Naufal Daffa
 */ 
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
    printf("\n\t\t     NAME\t: ");
    scanf("%[^\n]s", username);

    fflush(stdin);
    printf("\t\t     PIN \t: ");
    scanf("%[^\n]s", pin);
    system("cls");
    team15();
    stream = fopen("bank.txt", "r");
    
    nowUser(pin, username);
    while(fread(&s1, sizeof(bankData), 1, stream)) {
        if((strcmp(s1.pin, pin) == 0) && (strcmp(s1.Name, username) == 0)) {
            if (s1.Saldo == 0) {
                printf("\n\t\t     ALERT: WALLET(IDR) NOW Rp%lld, TO MAKE A TRANSACTIOB. PLEASE MAKE A DEPOSIT!\n", s1.Saldo);
            }
        }
    } 
    fclose(stream);
   
    stream = fopen("bank.txt", "r");
    windowlog = fopen("windowlog.txt", "w");
    
    printf("\n\n\t\t     Do you want to make a transaction now? [y/n]");
    printf("\n\t\t     Input: ");
    scanf(" %c", &choose);
    
    system("cls");
    team15();
    nowUser(pin, username);
    
    if ((choose == 'y') || (choose == 'Y')) {
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
                    printf("\n\t\t     DEPOSIT AMOUNT: ");
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
                    printf("\n\t\t     WITHDRAW AMOUNT: ");
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
            getchar();
        } while (option != 0);
    }else if ((choose == 'n') || (choose == 'N')) {
        printf("\n\t\t     ALERT: RETURN TO THE MAIN PROGRAM\n");
        getchar();
    }else {
        printf("\n\t\t     ALERT: INCORRECT, PLEASE TRY AGAIN\n");
        getchar();
    }

    fclose(stream);
    fclose(windowlog);

    printf("\n\t\t     PRESS ENTER TO RETURN TO THE MAIN MENU!");
}

/**
 * @description: prosedur yang menutup akan user
 * @objek: datasets ke bankData
 * @declare: char pin[9], username[50], delete[7]
 * @decare: int found
 * @input: username dan pin client dan kata 'Delete' untuk menutup tabungan
 * @output: tampilan sukses jika berhasil dihapus dan tampilan sukses apabila tidak berhasil dihapus
 * @author: Naufal Daffa
 */ //BEDA
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


    while (fread(&s1, sizeof(bankData), 1, stream)) {
        if((strcmp(s1.pin, pin) == 0) && (strcmp(s1.Name, username) == 0)) {
            // printf("Hahaha");
            found = 1;
        }
        if((strcmp(s1.pin, pin) != 0) && (strcmp(s1.Name, username) != 0)) {
            fwrite(&s1, sizeof(bankData), 1, windowlog);
            continue;
        }
    }
    fclose(stream);
    fclose(windowlog);


        printf("\n\t\t     ALERT: WRITE \"Delete\" TO CONTINUE.\n");
        printf("\n\t\t     Input: ");
        scanf(" %[^\n]s", delete);
        if ((strcmp(delete, "Delete") != 0)) {
            found = 0;
        }else if ((strcmp(delete, "Delete") != 0)){
            found = 1;
        }

    
    if (found == 1) {
        windowlog = fopen("windowlog.txt", "r");
        stream = fopen("bank.txt", "w");

        while (fread(&s1, sizeof(bankData), 1, windowlog)) {
            fwrite (&s1, sizeof(bankData), 1, stream);
        }

        fclose(stream);
        fclose(windowlog);
        printf("\n\t\t     ALERT: ACCOUNT CLOSURE WAS SUCCESSFUL");
        getchar();
        printf("\n\t\t     ALERT: PRESS ENTER TO EXIT THE PROGRAM");
        getchar();
        exit(1);
    }else if (found == 0) {
        printf("\n\t\t     ALERT: ACCOUNT CLOSURE WAS NOT SUCCESSFUL");
    }
}

/**
 * @description: prosedur menampilkan info client
 * @objek: datasets ke bankData
 * @author: Chrysant M
 */ //BEDA
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

/**
 * @description: prosedur membuat akun disertai data client
 * @objek: pointer dataset ke struct bankData
 * @input: banyak akun yang dibuat(n)
 * @output: tampilkan sukses jika akun berhasil dibuat, serta gagal jika akun tidak berhasil dibuat
 * @author: Chrysant M
 */ //BEDA
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
    }

    if (stream) {
        printf("\n\t\t     ALERT: %d ACCOUNT CREATED SUCCESSFULLY.\n", n);
    } else if (stream == NULL) {
        printf("\n\t\t     ALERT: DATA FILE WAS NOT CREATED SUCCESSFULLY.\n");
    }

    getchar();
    fclose(stream);
}

/**
 * @description : prosedur untuk membuat file dengan nama bank.txt)
 * @objek typedef struct bankData --> *s
 * @objek FILE --> *stream
 * @stream --> open bank.txt
 * @stream --> write bank.txt
 * @output -- sesuai yang diprint
 * @close stream
 * @writer --> Ayasha
 */
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
}

/**
 * @description : fungsi untuk mengatur opsi yang dipilih user
 * @objek char -- *act
 * @objek int --> valid, option, success, count
 * @call team15(), display(), accountInfo(), transaction(), closeAccount(), createFileData(), createAccount()
 * @input option
 * @output sesuai yang diprint
 * @writer --> Naufal Daffa
 */
int optionFeatures(char *act) {
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
                    return(1);
                }
                valid = validationUser(0);
                printf("\n\t\t     ALERT: SORRY, YOUR PIN OR USERNAME WAS INCORRECT.\n");
                printf("\t\t            PLEASE DOUBLE-CHECK YOUR PASSWORD.\n");
            } while (valid==0);
            system("cls");

            do {
                team15();
                printf("\n\t\t     ALERT: CHOOSE FEATURES U WANNA USE!\n");
                // function calls

                display('y');
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
                        getchar();
                        break;
                    case 0:
                        // exit program
                        printf("\n\t\t     Output: Exit Program!\n");
                        exit(1);
                        break;
                    default:
                        // else condition
                        team15();
                        printf("\n\t\t     Output: INCORRECT, FEATURE NOT FOUND!\n");
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
                display('n');
                printf("\t\t     Input: ");
                scanf("%d", &option);

                // condition option of feature
                switch(option) {
                    case 1:
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
            } while(option != 0);
        }
    }while (1);
}

/**
 * @description : fungsi untuk masuk ke dalam program dan memastikan user memiliki akun (LOGIN))
 * @objek int --> hasil
 * @objek FILE --> *stream
 * @objek typedef struct bankData --> s
 * @objek char --> pin[9] , username[50]
 * @input username, pin
 * @stream --> open bank.txt
 * @stream --> read bank.txt
 * close stream 
 * output sesuai yang diprint
 * @writer --> Naufal Daffa
 */ 
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
    printf("\n\n\t\t\t\t    ---------\n");
    printf("\t\t\t\t    | LOGIN |\n");
    printf("\t\t\t\t    ---------\n");

    fflush(stdin);
    printf("\n\t\t     NAME\t: ");
    scanf("%[^\n]s", username);

    fflush(stdin);
    printf("\t\t     PIN \t: ");
    scanf("%[^\n]s", pin);
    
    // Validation
    while(fread(&s, sizeof(bankData), 1, stream)){
        if((strcmp(s.pin, pin) == 0) && (strcmp(s.Name, username) == 0)) {
            hasil = 1;
            return hasil;
        }else if ((strcmp(s.pin, pin) != 0) || (strcmp(s.Name, username) != 0)) {
            hasil = 0;
            continue;
        }
    }
        
    fclose(stream);
    return 0;
}

/**
 * @description: prosedur menampilkan fitur menu transaksi.
 * @writer: Chrysant
 */
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

/**
 * @description: prosedur untuk menampilkan "Team15
 * @writer: Chrysant
 */
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