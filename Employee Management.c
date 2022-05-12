#include<stdio.h>
struct employee
{
    int serialNO, availability;
    char DeliveryMan[50];
} delivery;

void insert()
{
    FILE *fp;
    fp = fopen("Record", "a");
    printf("Enter the Serial Number           : ");
    scanf("%d", &delivery.serialNO);
    printf("Name of the delivery man          : ");
    scanf("%s", &delivery.DeliveryMan);
    printf("Enter the Availability Status(0/1): ");
    scanf("%d", &delivery.availability);
    fwrite(&delivery, sizeof(delivery), 1, fp);
    fclose(fp);
}

void disp()
{
    FILE *fp1;
    fp1 = fopen("Record", "r");
    printf("\nSerial Number\tName\tAvailability Status\n\n");
    while (fread(&delivery, sizeof(delivery), 1, fp1))
        printf(" %d\t\t%s\t%d\n", delivery.serialNO, delivery.DeliveryMan, delivery.availability);
    fclose(fp1);
}
void search()
{
    FILE *fp2;
    int r, s, avl;
    printf("\nEnter the Serial no. you want to search  :");
    scanf("%d", &r);
    avl = avlserialNO(r);
    if (avl == 0)
        printf("Serial No. %d is not available in the file\n",r);
    else
    {
        fp2 = fopen("Record", "r");
        while (fread(&delivery, sizeof(delivery), 1, fp2))
        {
            s = delivery.serialNO;
            if (s == r)
            {
                printf("\nSerial No    : %d", delivery.serialNO);
                printf("\nName         : %s", delivery.DeliveryMan);
                printf("\nAvailability : %d\n", delivery.availability);
            }
        }
        fclose(fp2);
    }
}


void deletefile()
{
    FILE *fpo;
    FILE *fpt;
    int r, s;
    printf("Enter the Serial no. you want to delete :");
    scanf("%d", &r);
    if (avlserialNO(r) == 0)
        printf("Serial no. %d is not available in the file\n", r);
    else
    {
        fpo = fopen("Record", "r");
        fpt = fopen("TempFile", "w");
        while (fread(&delivery, sizeof(delivery), 1, fpo))
        {
            s = delivery.serialNO;
            if (s != r)
                fwrite(&delivery, sizeof(delivery), 1, fpt);
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("Record", "w");
        fpt = fopen("TempFile", "r");
        while (fread(&delivery, sizeof(delivery), 1, fpt))
            fwrite(&delivery, sizeof(delivery), 1, fpo);
        printf("\nRECORD DELETED SUCCESSFULLY.\nNo going back now!\n");
        fclose(fpo);
        fclose(fpt);
    }

}
void update()
{
    int avl;
    FILE *fpt;
    FILE *fpo;
    int s, r, ch;
    printf("Enter Serial No. you want to update:");
    scanf("%d", &r);
    avl = avlserialNO(r);
    if (avl == 0)
    {
        printf("Serial No. %d is not Available in the file", r);
    }
    else
    {
        fpo = fopen("Record", "r");
        fpt = fopen("TempFile", "w");
        while (fread(&delivery, sizeof(delivery), 1, fpo))
        {
            s = delivery.serialNO;
            if (s != r)
                fwrite(&delivery, sizeof(delivery), 1, fpt);
            else
            {
                printf("\n\t1. Update Name of Serial No. %d", r);
                printf("\n\t2. Update Availability Status of Serial No. %d", r);
                printf("\n\t3. Update both Name and Availability Status of Serial No. %d", r);
                printf("\nEnter your choice:");
                scanf("%d", &ch);
                switch (ch)
                {
                case 1:
                    printf("Enter Name: ");
                    scanf("%s", &delivery.DeliveryMan);
                    break;
                case 2:
                    printf("Enter Availability Status: ");
                    scanf("%d", &delivery.availability);
                    break;
                case 3:
                    printf("Enter Name               : ");
                    scanf("%s", &delivery.DeliveryMan);
                    printf("Enter Availability Status: ");
                    scanf("%d", &delivery.availability);
                    break;
                default:
                    printf("Invalid Selection");
                    break;
                }
                fwrite(&delivery, sizeof(delivery), 1, fpt);
            }
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("Record", "w");
        fpt = fopen("TempFile", "r");
        while (fread(&delivery, sizeof(delivery), 1, fpt))
        {
            fwrite(&delivery, sizeof(delivery), 1, fpo);
        }
        fclose(fpo);
        fclose(fpt);
        printf("RECORD UPDATED");
    }
}
void sort()
{
    int a[20], count = 0, i, j, t, c;
    FILE *fpo;
    fpo = fopen("Record", "r");
    while (fread(&delivery, sizeof(delivery), 1, fpo))
    {
        a[count] = delivery.serialNO;
        count++;
    }
    c = count;
    for (i = 0; i<count - 1; i++)
    {
        for (j = i + 1; j<count; j++)
        {
            if (a[i]>a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    printf("Serial No.\tName\t\tAvailability Status\n\n");
    count = c;
    for (i = 0; i<count; i++)
    {
        rewind(fpo);
        while (fread(&delivery, sizeof(delivery), 1, fpo))
        {
            if (a[i] == delivery.serialNO)
                printf("\n %d\t\t %s \t\t %d",delivery.serialNO, delivery.DeliveryMan, delivery.availability);
        }

    }
}

int avlserialNO(int rno)
{
    FILE *fp;
    int c = 0;
    fp = fopen("Record", "r");
    while (!feof(fp))
    {
        fread(&delivery, sizeof(delivery), 1, fp);

        if (rno == delivery.serialNO)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int empty()
{
    int c = 0;
    FILE *fp;
    fp = fopen("Record", "r");
    while (fread(&delivery, sizeof(delivery), 1, fp))
        c = 1;
    fclose(fp);
    return c;
}
void main()
{
    int c, emp;
    do
    {
        printf("\n\t\t\t1. Insert new data\n");
        printf("\t\t\t2. Display existing data\n");
        printf("\t\t\t3. Search the database\n");
        printf("\t\t\t4. DELETE an entry! (authorized personnel only)\n");
        printf("\t\t\t5. UPDATE an entry! (authorized personnel only)\n");
        printf("\t\t\t6. Sort\n");
        printf("\t\t\t7. EXIT");

        printf("\n\nEnter your choice:");
        scanf("%d", &c);
        printf("\n");
        switch (c)
        {
        case 1:
            insert();
            break;
        case 2:
            emp = empty();
            if (emp == 0)
                printf("\nThe file is EMPTY\n");
            else
                disp();
            break;
        case 3:
            search();
            break;
        case 4:
            deletefile();
            break;
        case 5:
            update();
            break;
        case 6:
            emp = empty();
            if (emp == 0)
                printf("\n The file is EMPTY\n");
            else
                sort();
            break;
        case 7:
            exit(1);
            break;
        default:
            printf("\nPlease enter a valid choice\n");
            break;

        }
    }
    while (c != 7);
}
