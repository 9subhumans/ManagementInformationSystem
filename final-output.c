#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <conio.h> 
    #define CLEAR_SCREEN "cls"
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #include <Windows.h>
#else
    #define CLEAR_SCREEN "clear"
#endif

#define MAX_NAME_LENGTH 50
#define MAX_NAMES 100

void headerTop() {
    printf("University Of Cebu\n");
    printf("College of Computer Studies\n");
    printf("Management Information System\n");


}

int authenticateUser(const char username[], const char password[], const char storedUsername[], const char storedPassword[]) {
    return strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0;
}

void hideInput(char *str) {
    char ch;
    int i = 0;
    while (1) {
        ch = _getch();  
        if (ch == '\r' || ch == '\n') {
            break;
        } else if (ch == 8 && i > 0) { 
            printf("\b \b");
            i--;
        } else {
            str[i] = ch;
            printf("*");
            i++;
        }
    }
    str[i] = '\0';
}

int main() {
    char username[50];
    char password[50];
    const char storedUsername[] = "Admin";
    const char storedPassword[] = "password123";
    char strArray[MAX_NAMES][MAX_NAME_LENGTH];
    char option[3];
    int nOption;

    do{
        system(CLEAR_SCREEN);
        headerTop();
        printf("Enter username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = 0;

        printf("Enter password: ");
        hideInput(password);
        system(CLEAR_SCREEN);

            if(authenticateUser(username, password, storedUsername, storedPassword)) {
                printf("LOGIN SUCCESSFULLY\n");
                printf("please press enter to enter");
                    getchar();
                do{
                    system(CLEAR_SCREEN);
                        printf("MAIN MENU\n");

                        printf("\nOptions to Perform:\n");
                            printf("\nPress [1] - ADD Record\n");
                            printf("Press [2] - DELETE Record\n");
                            printf("Press [3] - SEARCH Record\n");
                            printf("Press [4] - MODIFY Record\n");
                            printf("Press [5] - DISPLAY ALL Record\n");
                            printf("Press [6] - UPDATE PASSWORD\n");
                            printf("Press [7] - Exit\n");

                        printf("\nSelection Option: ");
                        scanf("%s", option);

                            if(strcmp(option, "1") == 0) {
                                do{
                                    system(CLEAR_SCREEN);
                                        printf("\n===== ADD RECORD =====\n");
                                        printf("\nEnter the preferred number of record to input: ");
                                        scanf("%d", &nOption);

                                        printf("Input %d name to be added in the array\n\n", nOption);
                                        for (int i = 0; i < nOption; i++) {
                                        printf("Names[%d]: ", i + 1);
                                        scanf("%s", strArray[i]);
                                      }
                                        printf("Would you like to add another record?\n");

                                        printf("\n\nWould you like to continue?");
                                        printf("\n---[Y/y] - yes, [N/n] - no---");
                                        printf("\n\nSelect option: ");
                                        scanf("%s", option);

                                    } while (strcmp(option, "y") == 0 || strcmp(option, "Y") == 0);
                                        
                            }

                } while (1);
            }

    } while (1);

}