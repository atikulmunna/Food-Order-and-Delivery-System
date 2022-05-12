#include <stdio.h>
#include <string.h>


struct credentials
{
    int age;
    char username[100], password[100], email[100], mobile[10];
}credential_var[100];

struct restaurants
{
    int first, second, third, fourth, fifth, sixth, seventh;
    char restaurant[100]; // Restaurants
    char Choice1[50], Choice2[50], Choice3[50], Choice4[50];
    char Choice5[50], Choice6[50], Choice7[50], Choice8[50];
}foodmenuvar[10];


int validate();
void registration();
void existing_account_check();
void login();
void cart();
void search_by_restaurants();
void search_by_food();
void food_order(int food);
void restaurant_initialize();
void restaurants(int restaurant_choice);

int flag=1, i, j=0, count=0, uppercase=0, lowercase=0, special=0, numbers=0, success=0, x, choice;
int n, ch, food, temp_age, total=0, food_choice, restaurant_choice, search_choice, restaurant_id, confirm;
char temp_name[100], temp_password1[100], temp_password2[100], temp_email[100], temp_mobile[100];

int main()
{
    system("COLOR B0");
    printf("\n\t\tPROJECT GROUP:   ESCAPE SEQUENCE\n\n");
    printf("\t\tGROUP MEMBERS:  AZMAIN IQTIDAR ARNOB\n\t\t\t\tATIKUL ISLAM MUNNA\n\t\t\t\t\AUNGGON CHOWDHURY\n\n\n\n\n");

    printf("\t\t||||||||||||   |||||||||||   ||||||||||||| \n");
    printf("\t\t|||                    |||   |||           \n");
    printf("\t\t|||                    |||   |||           \n");
    printf("\t\t|||||||OOD             |TO   |||||OODIES   \n");
    printf("\t\t|||            |||||||||||   |||           \n");
    printf("\t\t|||            |||           |||           \n");
    printf("\t\t|||            |||           |||           \n");
    printf("\t\t|||            |||           |||           \n");
    printf("\t\t|||            |||||||||||   |||           \n");

    while (1)
    {
        printf("\nWelcome to {FOOD 2 FOODIES} food order system\n\n");
        printf("1.SIGNUP\n");
        printf("2.LOGIN\n");
        printf("3.EXIT\n\n");

        printf("Type '1' to be registered as a new user;\n");
        printf("Type '2' if you already have an account;\n");
        printf("Type '3' to exit the program;\n----> ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                registration();
                break;
            }
            case 2:
            {
                login();
                break;
            }
            case 3:
            {
                return 0;
            }
            default:
            {
                printf("\nERROR!!\nPlease choose among 1/2/3");
                break;
            }
        }
    }
}

void registration()
{
    printf("\n\nPlease provide the informations below to create a new account\n\n");

    printf("Name(Nickname) => ");
    fflush(stdin);
    gets(temp_name);
    for (i = 0; temp_name[i] != '\0'; i++)
    {
        if (!((temp_name[i] >= 'a' && temp_name[i] <= 'z')
                || (temp_name[i] >= 'A' && temp_name[i] <= 'Z')))
        {
            printf("Please Enter a valid name(Just Nickname)\n");
            printf("Name(Nickname) => ");
            fflush(stdin);
            gets(temp_name);
        }
    }


    printf("Age => ");
    scanf("%d", &temp_age);
    while(temp_age <= 0){
        printf("\nPlease enter your valid age.\n");
        printf("\nAge => ");
        scanf("%d", &temp_age);
    }

    printf("\n[Note that your email must consist '@' and '.']\n");
    printf("\nEmail => ");
    fflush(stdin);
    gets(temp_email);


    printf("\n[Note that your password length must be between 8-32 characters.\n");
    printf("Including at least one Uppercase letter, one Lowercase letter.\n one Number and one Special character]\n\n");
    printf("Choose a Password   => ");
    fflush(stdin);
    gets(temp_password1);




    printf("Confirm Your Password => ");
    scanf("%s", temp_password2);

    printf("[Plz Give the 10 Digit contact number]\n");
    printf("Contact Number (BD)   => +880 ");
    scanf("%s", temp_mobile);

    x = validate();
    if (x == 1)
    {
        existing_account_check();
    }
}

int validate()
{
    for (i = 0; temp_name[i] != '\0'; i++)
    {
        if (!((temp_name[i] >= 'a' && temp_name[i] <= 'z')
                || (temp_name[i] >= 'A' && temp_name[i] <= 'Z')))
        {
            printf("\nPlease Enter a valid name(Just Nickname)");
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        count = 0;
        for (i = 0; temp_email[i] != '\0'; i++)
        {
            if (temp_email[i] == '@'|| temp_email[i] == '.')
                count++;
        }
        if (count >= 2 && strlen(temp_email) >= 5)
        {
            if (!strcmp(temp_password1,temp_password2))
            {
                if (strlen(temp_password1) >= 8 || strlen(temp_password1) <= 32)
                {
                    uppercase = 0;
                    lowercase = 0;
                    numbers = 0;
                    special = 0;

                    for (i = 0; temp_password1[i] != '\0'; i++)
                    {
                        if (temp_password1[i] >= 'A' && temp_password1[i] <= 'Z')
                        {
                            uppercase++;
                        }
                        else if (temp_password1[i] >= 'a' && temp_password1[i] <= 'z')
                        {
                            lowercase++;
                        }
                        else if (temp_password1[i] >= '0' && temp_password1[i] <= '9')
                        {
                            numbers++;
                        }
                        else if (temp_password1[i] == '@' || temp_password1[i] == '&' ||
                                 temp_password1[i] == '#' || temp_password1[i] == '*')
                        {
                            special++;
                        }
                    }

                    if (uppercase >= 1 && lowercase >= 1 && numbers >= 1 && special >= 1)
                    {
                        if (temp_age != 0 && temp_age > 0)
                        {
                            if (strlen(temp_mobile) == 10)
                            {
                                for (i = 0; i < 10; i++)
                                {
                                    if (temp_mobile[i] >= '0' && temp_mobile[i] <= '10')
                                    {
                                        success = 1;
                                    }
                                    else
                                    {
                                        printf("\n\nPlease Enter a valid mobile number");
                                        return 0;
                                        break;
                                    }
                                }

                                if (success == 1)
                                {
                                    return 1;
                                }
                            }
                            else
                            {
                                printf("\n\nPlease Enter a 11 digit mobile number");
                                return 0;
                            }
                        }
                        else
                        {
                            printf("\n\nPlease enter your valid age to get age-friendly recommendations.");
                            return 0;
                        }
                    }
                    else
                    {
                        printf("\n\nPlease Enter a STRONG password\n");
                        printf("\n\n");
                        return 0;
                    }
                }
                else
                {
                    printf("\nYour Password length much be between 8 and 12 digits.\n\n");
                    return 0;
                }
            }
            else
            {
                printf("\nPasswords does not match!\n\n");
                return 0;
            }
        }
        else
        {
            printf("\nPlease enter a valid email address. Do not use temporary email addresses to keep your data safe.\n\n");
            return 0;
        }
    }
}

void existing_account_check()
{
    for (i = 0; i < 100; i++)
    {
        if (!(strcmp(temp_email, credential_var[i].email) && strcmp(temp_password1, credential_var[i].password)))
        {
            printf("\n\nAn account with this email is already registered. Please log-in or provide a different email to create a new account.\n\n");
            main();
            break;
        }
    }
    if (i == 100)
    {
        strcpy(credential_var[j].username, temp_name);
        credential_var[j].age = temp_age;
        strcpy(credential_var[j].password, temp_password1);
        strcpy(credential_var[j].email, temp_email);
        strcpy(credential_var[j].mobile, temp_mobile);

        j=j+1;

        printf("\n\n\n-----Congratulations! Registration successful!-----\n\n");
    }
}

void login()
{
    printf("\n\nProvide your account credentials\n\n\n");
    printf("Email   : ");
    scanf("%s", temp_email);
    printf("Password: ");
    scanf("%s", temp_password1);

    for (i=0; i<100; i++)
    {
        if (!strcmp(credential_var[i].email, temp_email))
        {
            if (!strcmp(credential_var[i].password, temp_password1))
            {
                printf("\n\nWelcome %s, ", credential_var[i].username);
                printf("Your are successfully logged into your account\n\n");
                printf("Kindly choose the method you want to follow to order foods \n");
                printf("1. Search By Restaurants\n");
                printf("2. Search by Menu\n");
                printf("3. Exit\n");

                printf("\nEnter the number representing your preferred choice: ");
                scanf("%d", &search_choice);

                switch (search_choice)
                {
                case 1:
                {
                    search_by_restaurants();
                    break;
                }
                case 2:
                {
                    search_by_food();
                    break;
                }
                case 3:
                {
                    return;
                }
                default:
                {
                    printf("Please Enter a valid choice.\n\n");
                    break;
                }
                }
                break;
            }
            else
            {
                printf("\n\nInvalid Password!");
                printf("Contact our customer care in case you forgot your password\n\n");
                main();
                break;
            }
        }
        else
        {
            printf("\n\nAccount with this email does not exist in our database. You have to register first.\n\n ");
            main();
            break;
        }
    }
}

void restaurant_initialize()
{
    strcpy(foodmenuvar[1].restaurant, "Chillox");

    strcpy(foodmenuvar[1].Choice1, "Chicken Smoky BBQ Cheese Burger ");
    strcpy(foodmenuvar[1].Choice2, "Chicken Cheese Blast            ");
    strcpy(foodmenuvar[1].Choice3, "Double Decker Chicken           ");
    strcpy(foodmenuvar[1].Choice4, "Giganto Chicken                 ");
    strcpy(foodmenuvar[1].Choice5, "Binge Chicken                   ");
    strcpy(foodmenuvar[1].Choice6, "Chicken Signature               ");
    strcpy(foodmenuvar[1].Choice7, "Regular Chicken Burger          ");

    foodmenuvar[1].first  = 225;
    foodmenuvar[1].second = 320;
    foodmenuvar[1].third  = 300;
    foodmenuvar[1].fourth = 430;
    foodmenuvar[1].fifth  = 680;
    foodmenuvar[1].sixth  = 380;
    foodmenuvar[1].seventh= 180;


    strcpy(foodmenuvar[2].restaurant, "7 Dayz");

    strcpy(foodmenuvar[2].Choice1, "Whole Roast Chicken Polao          ");
    strcpy(foodmenuvar[2].Choice2, "Special Mutton Kacchi              ");
    strcpy(foodmenuvar[2].Choice3, "Chicken Dum Biriyani (Basmati)     ");
    strcpy(foodmenuvar[2].Choice4, "Chicken Dum Biriyani (Chinighura)  ");
    strcpy(foodmenuvar[2].Choice5, "Mejbani Beef Akhni                 ");
    strcpy(foodmenuvar[2].Choice6, "Vuna Khichuri                      ");
    strcpy(foodmenuvar[2].Choice7, "Vegetable & Egg Khichuri           ");

    foodmenuvar[2].first  = 220;
    foodmenuvar[2].second = 282;
    foodmenuvar[2].third  = 148;
    foodmenuvar[2].fourth = 135;
    foodmenuvar[2].fifth  = 135;
    foodmenuvar[2].sixth  = 110;
    foodmenuvar[2].seventh= 120;

    strcpy(foodmenuvar[3].restaurant, "Barcode Cafe");

    strcpy(foodmenuvar[3].Choice1, "Chicken Vegetable Clear Soup         ");
    strcpy(foodmenuvar[3].Choice2, "Thai Soup                            ");
    strcpy(foodmenuvar[3].Choice3, "Mexican Salad                        ");
    strcpy(foodmenuvar[3].Choice4, "Barcode Special Chicken Cream Pasta  ");
    strcpy(foodmenuvar[3].Choice5, "Pasta with Chicken Bolognese         ");
    strcpy(foodmenuvar[3].Choice6, "Pasta with Beef Bolognese            ");
    strcpy(foodmenuvar[3].Choice7, "Calamary with Linguene Pasta         ");

    foodmenuvar[3].first  = 230;
    foodmenuvar[3].second = 195;
    foodmenuvar[3].third  = 310;
    foodmenuvar[3].fourth = 360;
    foodmenuvar[3].fifth  = 370;
    foodmenuvar[3].sixth  = 375;
    foodmenuvar[3].seventh= 470;

    strcpy(foodmenuvar[4].restaurant, "CoffeeLime Juice & Smoothie Corner");

    strcpy(foodmenuvar[4].Choice1, "Mint Lemonade      ");
    strcpy(foodmenuvar[4].Choice2, "Orange Lemonade    ");
    strcpy(foodmenuvar[4].Choice3, "Pineapple Mojito   ");
    strcpy(foodmenuvar[4].Choice4, "Watermelon Mojito  ");
    strcpy(foodmenuvar[4].Choice5, "Green Mango Juice  ");
    strcpy(foodmenuvar[4].Choice6, "Faluda             ");
    strcpy(foodmenuvar[4].Choice7, "Malai Kulfi        ");

    foodmenuvar[4].first  = 50;
    foodmenuvar[4].second = 50;
    foodmenuvar[4].third  = 120;
    foodmenuvar[4].fourth = 60;
    foodmenuvar[4].fifth  = 140;
    foodmenuvar[4].sixth  = 140;
    foodmenuvar[4].seventh= 80;

    strcpy(foodmenuvar[5].restaurant, "Tasty Treat");

    strcpy(foodmenuvar[5].Choice1, "Chocolate Fudge Cake (800gm)    ");
    strcpy(foodmenuvar[5].Choice2, "Porabari Chamcham (1Kg)         ");
    strcpy(foodmenuvar[5].Choice3, "Tasty Treat Sweet Curd (850 gm) ");
    strcpy(foodmenuvar[5].Choice4, "Fudge Brownie Pastry (120gm)    ");
    strcpy(foodmenuvar[5].Choice5, "Baked Yogur (80gm)              ");
    strcpy(foodmenuvar[5].Choice6, "Black Forest Pastry             ");
    strcpy(foodmenuvar[5].Choice7, "Chocolate Donut                 ");

    foodmenuvar[5].first  = 1125;
    foodmenuvar[5].second = 495;
    foodmenuvar[5].third  = 325;
    foodmenuvar[5].fourth = 130;
    foodmenuvar[5].fifth  = 60;
    foodmenuvar[5].sixth  = 80;
    foodmenuvar[5].seventh= 70;
}

void search_by_restaurants()
{
    restaurant_initialize();
    printf("Choose a restaurant from- \n\n 1. %s\n 2. %s\n 3. %s\n 4. %s\n 5. %s\n", foodmenuvar[1].restaurant, foodmenuvar[2].restaurant, foodmenuvar[3].restaurant, foodmenuvar[4].restaurant, foodmenuvar[5].restaurant);
    printf("\n6. Exit\n\n");

    printf("Please select the restaurant: ");
    scanf("%d", &restaurant_choice);

    if (restaurant_choice > 6)
    {
        printf("Please Enter a valid choice.\n\n");
        search_by_restaurants();
    }
    else if (restaurant_choice == 6)
    {
        login();

    }
    else
    {
        restaurants(restaurant_choice);
    }

}

void restaurants(int restaurant_choice)
{
    total = 0;
    while (1)
    {
        printf("\n\nList of foods available for delivery right now in %s\n\n", foodmenuvar[restaurant_choice].restaurant);

        printf("1. %s \t-------->\t %d TK\n", foodmenuvar[restaurant_choice].Choice1, foodmenuvar[restaurant_choice].first);
        printf("2. %s \t-------->\t %d TK\n", foodmenuvar[restaurant_choice].Choice2, foodmenuvar[restaurant_choice].second);
        printf("3. %s \t-------->\t %d TK\n", foodmenuvar[restaurant_choice].Choice3, foodmenuvar[restaurant_choice].third);
        printf("4. %s \t-------->\t %d TK\n", foodmenuvar[restaurant_choice].Choice4, foodmenuvar[restaurant_choice].fourth);
        printf("5. %s \t-------->\t %d TK\n", foodmenuvar[restaurant_choice].Choice5, foodmenuvar[restaurant_choice].fifth);
        printf("6. %s \t-------->\t %d TK\n", foodmenuvar[restaurant_choice].Choice6, foodmenuvar[restaurant_choice].sixth);
        printf("7. %s \t-------->\t %d TK\n\n", foodmenuvar[restaurant_choice].Choice7, foodmenuvar[restaurant_choice].seventh);
        printf("8. Cart\n");
        printf("9. Exit\n\n");

        printf("Please Enter Your Choice\t");
        scanf("%d", &food_choice);

        if (food_choice == 1)
        {
            printf("Please Enter the Count of %s: ", foodmenuvar[restaurant_choice].Choice1);
            scanf("%d", &n);

            total = total + (n * foodmenuvar[restaurant_choice].first);
        }
        else if (food_choice == 2)
        {
            printf("Please Enter the Count of %s: ", foodmenuvar[restaurant_choice].Choice2);
            scanf("%d", &n);

            total = total + (n * foodmenuvar[restaurant_choice].second);
        }
        else if (food_choice == 3)
        {
            printf("Please Enter the Count of %s: ", foodmenuvar[restaurant_choice].Choice3);
            scanf("%d", &n);

            total = total + (n * foodmenuvar[restaurant_choice].third);
        }
        else if (food_choice == 4)
        {
            printf("Please Enter the Count of %s: ", foodmenuvar[restaurant_choice].Choice4);
            scanf("%d", &n);

            total = total + (n * foodmenuvar[restaurant_choice].fourth);
        }
        else if (food_choice == 5)
        {
            printf("Please Enter the Count of %s: ", foodmenuvar[restaurant_choice].Choice5);
            scanf("%d", &n);

            total = total + (n * foodmenuvar[restaurant_choice].fifth);
        }
        else if (food_choice == 6)
        {
            printf("Please Enter the Count of %s: ", foodmenuvar[restaurant_choice].Choice6);
            scanf("%d", &n);

            total = total + (n * foodmenuvar[restaurant_choice].sixth);
        }
        else if (food_choice == 7)
        {
            printf("Please Enter the Count of %s: ", foodmenuvar[restaurant_choice].Choice7);
            scanf("%d", &n);

            total = total + (n * foodmenuvar[restaurant_choice].seventh);
        }
        else if (food_choice == 8)
        {
            cart();
        }
        else if (food_choice == 9)
        {
            search_by_restaurants();
        }
        else
        {
            printf("Please Enter a valid choice.\n\n");
        }
    }
}

void search_by_food()
{
    total = 0;

    restaurant_initialize();
    while (1)
    {
        printf("\n\nPlease choose the items you would like to order\n");
        printf("\n\nKINGDOM OF BURGERS>>>>\n\n");
        printf("\n 1. %s -----> %d\n",foodmenuvar[1].Choice1, foodmenuvar[1].first);
        printf("\n 2. %s -----> %d\n",foodmenuvar[1].Choice2, foodmenuvar[1].second);
        printf("\n 3. %s -----> %d\n",foodmenuvar[1].Choice3, foodmenuvar[1].third);
        printf("\n 4. %s -----> %d\n",foodmenuvar[1].Choice4, foodmenuvar[1].fourth);
        printf("\n 5. %s -----> %d\n",foodmenuvar[1].Choice5, foodmenuvar[1].fifth);


        printf("\n\nUB-CONTINENTAL RICE MAGIC>>>>\n");
        printf("\n 6. %s -----> %d\n",foodmenuvar[2].Choice1, foodmenuvar[2].first);
        printf("\n 7. %s -----> %d\n",foodmenuvar[2].Choice2, foodmenuvar[2].second);
        printf("\n 8. %s -----> %d\n",foodmenuvar[2].Choice3, foodmenuvar[2].third);
        printf("\n 9. %s -----> %d\n",foodmenuvar[2].Choice4, foodmenuvar[2].fourth);
        printf("\n10. %s -----> %d\n",foodmenuvar[2].Choice5, foodmenuvar[2].fifth);


        printf("\n\nSOUP & PASTA>>>>\n");
        printf("\n11. %s -----> %d\n",foodmenuvar[3].Choice1, foodmenuvar[3].first);
        printf("\n12. %s -----> %d\n",foodmenuvar[3].Choice2, foodmenuvar[3].second);
        printf("\n13. %s -----> %d\n",foodmenuvar[3].Choice3, foodmenuvar[3].third);
        printf("\n14. %s -----> %d\n",foodmenuvar[3].Choice4, foodmenuvar[3].fourth);
        printf("\n15. %s -----> %d\n",foodmenuvar[3].Choice5, foodmenuvar[3].fifth);


        printf("\n\nFRESH JUICE & REFRESHMENT DRINKS>>>>\n");
        printf("\n16. %s -----> %d\n",foodmenuvar[4].Choice1, foodmenuvar[4].first);
        printf("\n17. %s -----> %d\n",foodmenuvar[4].Choice2, foodmenuvar[4].second);
        printf("\n18. %s -----> %d\n",foodmenuvar[4].Choice3, foodmenuvar[4].third);
        printf("\n19. %s -----> %d\n",foodmenuvar[4].Choice4, foodmenuvar[4].fourth);
        printf("\n20. %s -----> %d\n",foodmenuvar[4].Choice5, foodmenuvar[4].fifth);

        printf("\n\nDESSERT & SWEETS>>>>\n");
        printf("\n21. %s -----> %d\n",foodmenuvar[5].Choice1, foodmenuvar[5].first);
        printf("\n22. %s -----> %d\n",foodmenuvar[5].Choice2, foodmenuvar[5].second);
        printf("\n23. %s -----> %d\n",foodmenuvar[5].Choice3, foodmenuvar[5].third);
        printf("\n24. %s -----> %d\n",foodmenuvar[5].Choice4, foodmenuvar[5].fourth);
        printf("\n25. %s -----> %d\n",foodmenuvar[5].Choice5, foodmenuvar[5].fifth);


        printf("\n\n26. Cart\n");
        printf("\n27. Exit");

        printf("\n\nPlease Enter Your Choice: ");
        scanf("%d", &food);

        if (food > 27)
        {
            printf("Please Enter a valid choice.\n\n ");
            search_by_food();
        }
        else if (food == 26)
        {
            cart();
        }
        else if(food == 27)
        {
            login() ;
        }
        else
        {
            food_order(food);
        }
    }
}

void food_order(int food)
{
    if (food >= 1 && food <= 5){
        restaurant_id = 1;
    }
    else if (food >= 6 && food <= 10){
        restaurant_id = 2;
    }
    else if (food >= 11 && food <= 15){
        restaurant_id = 3;
    }
    else if (food >= 16 && food <= 20){
        restaurant_id = 4;
    }
    else if (food >= 21 && food <= 25){
        restaurant_id = 5;
    }
    else{
        printf("Please input a valid choise.");
    }



    if((food % 5) == 1)
    {
        printf("How many of the scrumptious %s do you want? :", foodmenuvar[restaurant_id].Choice1);
        scanf("%d", &n);

        total = total + (n * foodmenuvar[restaurant_id].first);
    }
    else if ((food % 5) == 2)
    {
        printf("How many of the delicious  %s do you want?\t", foodmenuvar[restaurant_id].Choice2);
        scanf("%d", &n);

        total = total + (n * foodmenuvar[restaurant_id].second);
    }
    else if ((food % 5) == 3)
    {
        printf("How many of the scrumptious %s do you want?\t", foodmenuvar[restaurant_id].Choice3);
        scanf("%d", &n);

        total = total + (n * foodmenuvar[restaurant_id].third);
    }
    else if ((food % 5) == 4)
    {
        printf("How many of the delicious  %s do you want?\t", foodmenuvar[restaurant_id].Choice4);
        scanf("%d", &n);

        total = total + (n * foodmenuvar[restaurant_id].fourth);
    }
    else if ((food % 5) == 0)
    {
        printf("How many of the delicious  %s do you want?\t", foodmenuvar[restaurant_id].Choice5);
        scanf("%d", &n);

        total = total + (n * foodmenuvar[restaurant_id].fifth);
    }
}

void cart()
{
    printf("\n\n\n------------------/------Your Food Cart------\-------------------");

    printf("\nYour Total Bill (incl. VAT): %d\n", total);
    printf("\n\nDo You wish to confirm the order?\nType '1' for YES & '0' for NO: ");
    scanf("%d", &ch);

    if (ch == 1)
    {
        printf("\n\nTHANK YOU FOR THE ORDER.\n Sit tight! Your rider will be knocking on the door soon!\n\n");
        int compliment,C;

        printf("Do you have time to give us a compliment?Tap 1) for yes 0 for no");
        scanf("%d",&C);
        if(C==1){
            printf("Rating: ");
            scanf("%d",&compliment);
            if(compliment==1)
            {
                printf("Thanks for your suppport.");
                login();
            }
            else if(compliment==2)
            {
               printf("Thanks for your suppport.");
               login();
            }
            else if(compliment==3)
            {
               printf("Thanks for your suppport.");
              login();
            }
            else if(compliment==3)
            {
               printf("Thanks for your suppport.");
               login();
            }
            else if(compliment==4)
            {
               printf("Thanks for your suppport.");
               login();
            }
            else if(compliment==5)
            {
               printf("Thanks for your suppport.");
               login();
            }
            else
            {
               printf("Sorry! For disappointing you.");
            }

        }
    else if (ch == 0)
    {
        printf("Exit the program? (Type 1)");
        printf("Go back? (Type 0)");
        scanf("%d", &confirm);

        if (confirm == 1)
        {
            printf("\n\nSorry to disappoint. Your order is cancelled :(\n\n");
            return 0;
        }
        else
        {
            printf("\n\nTHANK YOU!!\n\n");

            return 0;
        }
    }
    else
    {
        printf("\n\nPlease Enter a valid choice.\n\n");
        cart();
    }
}
}
