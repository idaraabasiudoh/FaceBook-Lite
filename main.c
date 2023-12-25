/********* main.c ********
    Student Name 	= Idara-Abasi Udoh
    Student Number	= 101244376
*/

// Includes go here
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "a2_nodes.h"
#include "a2_functions.h"

int main()
{
    /******** DONT MODIFY THIS PART OF THE CODE ********/
    /* THIS CODE WILL LOAD THE DATABASE OF USERS FROM THE FILE 
       AND GENERATE THE STARTING LINKED LIST.
    */
    FILE *csv_file = fopen("user_details.csv", "r");
    if (csv_file == NULL)
    {
        perror("Error opening the CSV file");
        return 1;
    }
    // Parse CSV data and create users
    user_t *users = read_CSV_and_create_users(csv_file, 50);

    fclose(csv_file);
    /******** DONT MODIFY THIS PART OF THE CODE ********/
    
    /* IMPORTANT: You must use the users linked list created in the code above. 
                  Any new users should be added to that linked list.
    */

    // Your solution goes here
    printf("**********************************************\n");
    printf("\tWelcome to Text-Based Facebook\n");
    printf("**********************************************\n");
    print_menu();
    int choice;
    scanf("%d", &choice);

    while (choice < 1 || choice > 6 ){
        printf("Invalid choice. Please try again.\n");
        print_menu();
        scanf("%d", &choice);
    }

    while (choice != 6){
    if(choice == 1){
        char username[30];
        char password[20];
        printf("\nEnter a username: ");
        scanf("%s", username);
        printf("Enter an upto 15 character password: ");
        scanf("%s", password);

        add_user(users , username, password);
        printf("\n**** User Added! ****\n");

        print_menu();
        scanf("%d", &choice);
        while (choice < 1 || choice > 6 ){
            printf("Invalid choice. Please try again.\n");
            print_menu();
            scanf("%d", &choice);
            }
        }

    if (choice == 2){
        char username[30];
        char password[20];

        printf("\nEnter the username to update their password: ");
        scanf("%s", username);
        
        if (find_user(users, username) != NULL){
            printf("\nEnter a new password that is upto 15 characters: ");
            scanf("%s", password);

            printf("**** Password changed! ****");
        }

        if (find_user(users, username) == NULL){
            printf("\n----------------------------------------------------------\n");
            printf("\t\tUser not found.\n");
            printf("----------------------------------------------------------\n");
            
        }

        print_menu();
        scanf("%d", &choice);
        while (choice < 1 || choice > 6 ){
            printf("Invalid choice. Please try again.\n");
            print_menu();
            scanf("%d", &choice);
            }
        
        }

    if (choice == 3){
        char username[30];

        printf("\nEnter the username to manage their posts: ");
        scanf("%s", username);
        
        if (find_user(users, username) == NULL){
            printf("\n----------------------------------------------------------\n");
            printf("\t\tUser not found.\n");
            printf("----------------------------------------------------------\n");
        }


        if (find_user(users, username) != NULL){
            printf("\n----------------------------------------------------------\n");
            printf("\t\t%s's posts\n", username);
            display_user_posts(find_user(users, username));
            printf("----------------------------------------------------------\n");

            int response;
            printf("\n1. Add a new user post\n");
            printf("2. Remove a users post\n");
            printf("3. Return to main menu\n");
            printf("\n\nYour choice: ");
            scanf("%d", &response);

            while (response != 3){
                if (response == 1){
                    char text[250];
                    printf("Enter your post content: ");
                    scanf(" %[^\n]", text);
                    add_post(find_user(users, username), text);
                    printf("Post added to your profile.");
                    }

                if (response == 2){

                    int post_to_delete;
                    printf("Which post do you want to delete? ");
                    scanf("%d", &post_to_delete);
                    delete_post(find_user(users, username), post_to_delete);
                    }


                printf("\n----------------------------------------------------------\n");
                printf("\t\t%s's posts\n", username);
                display_user_posts(find_user(users, username));
                printf("----------------------------------------------------------\n");
                printf("\n1. Add a new user post\n");
                printf("2. Remove a users post\n");
                printf("3. Return to main menu\n");
                printf("\n\nYour choice: ");
                scanf("%d", &response);
            }

        }
        print_menu();
        scanf("%d", &choice);
        while (choice < 1 || choice > 6 ){
            printf("Invalid choice. Please try again.\n");
            print_menu();
            scanf("%d", &choice);
            }

    }


    if (choice == 4){
        char username[50];
        printf("\nEnter the username to manage their friends: ");
        scanf("%s", username);

        if (find_user(users, username) == NULL){
            printf("\n----------------------------------------------------------\n");
            printf("\t\tUser not found.\n");
            printf("----------------------------------------------------------\n");
        }

        if (find_user(users, username) != NULL){
            int response;
            printf("\n----------------------------------------------------------\n");
            printf("\t\t%s's friends\n", username);
            printf("----------------------------------------------------------\n");
            printf("\n1. Display all user's friends\n");
            printf("2. Add a new friend\n");
            printf("3. Delete a friend\n");
            printf("4. Return to main menu\n");
            printf("\n\nYour choice: ");
            scanf("%d", &response);


            while (response != 4){
                if (response == 1){
                    display_user_friends(find_user(users, username));
                }
                if (response == 2){
                    char friend_name[50];
                    printf("\n\nEnter a new friend's name: ");
                    scanf("%s", friend_name);
                    add_friend(find_user(users, username), friend_name);
                    printf("Friend aaded to the list\n");
                }
                if (response == 3){
                    char friend_name[50];
                    display_user_friends(find_user(users, username));
                    printf("\n\nEnter a friend's name to be deleted: ");
                    scanf("%s", friend_name);
                    delete_friend(find_user(users, username), friend_name);
                    
                }


                printf("\n----------------------------------------------------------\n");
                printf("\t\t%s's friends\n", username);
                printf("----------------------------------------------------------\n");
                printf("\n1. Display all user's friends\n");
                printf("2. Add a new friend\n");
                printf("3. Delete a friend\n");
                printf("4. Return to main menu\n");
                printf("\n\nYour choice: ");
                scanf("%d", &response);
                }


            
        }
        print_menu();
            scanf("%d", &choice);
            while (choice < 1 || choice > 6 ){
                printf("Invalid choice. Please try again.\n");
                print_menu();
                scanf("%d", &choice);
                }


    }

    if (choice == 5){
        display_all_posts(users);
        print_menu();
            scanf("%d", &choice);
            while (choice < 1 || choice > 6 ){
                printf("Invalid choice. Please try again.\n");
                print_menu();
                scanf("%d", &choice);
                }
    }

    






    }

    teardown(users);
    printf("*********************************************\n");
    printf("Thank you for using Text-Based Facebook\n");
    printf("\t\tGoodbye!\n");
    printf("*********************************************\n");


    return 0;

}