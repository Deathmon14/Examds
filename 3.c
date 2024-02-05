#include <stdio.h>

/* strcat() */
void strcat_custom(char *s1, const char *s2)
{
    while (*s1 != '\0')
        s1++;

    while (*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

/* strcmp() */
int strcmp_custom(const char *s1, const char *s2)
{
    while (*s1 != '\0' || *s2 != '\0')
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return 0; /* strings are equal */
}

/* strcat() */
void strcat_custom(char *s1, const char *s2)
{
    while (*s1 != '\0')
        s1++;

    while (*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

void strreverse(char *s1)
{
    int i = 0, j, k = 0;
    char s3[50];

    while (*s1)
    {
        s1++, k++;
    }

    for (i = 0, j = k - 1; j >= 0; j--, i++)
    {
        --s1;
        s3[i] = *s1;
    }
    s3[i] = '\0';
    strcat_custom(s1, s3);
}

int main()
{
    char s1[80], s2[80], t1[80];
    int choice, result;

    printf("Enter 2 strings:\n");
    fgets(s1, sizeof(s1), stdin);
    fgets(s2, sizeof(s2), stdin);

    // Remove newline characters from fgets
    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';

    strcat_custom(t1, s1);

    printf("---MENU---\n");
    printf("1. strcmp\n2. strcat\n3. strconcat\n4. String reverse\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            strcat_custom(s1, t1);
            result = strcmp_custom(s1, s2);
            if (result > 0)
                printf("%s is greater than %s\n", s1, s2);
            else if (result < 0)
                printf("%s is greater than %s\n", s2, s1);
            else
                printf("Strings are equal\n");
            break;
        case 2:
            strcat_custom(s1, t1);
            printf("Strings before concatenation: s1=%s, s2=%s\n", t1, s2);
            strcat_custom(t1, s2);
            printf("After concatenation: s1=%s, s2=%s\n", t1, s2);
            break;
        case 3:
            strcat_custom(s1, t1);
            printf("Strings before concatenation: s1=%s, s2=%s\n", t1, s2);
            strcat_custom(t1, s2);
            printf("After concatenation: s1=%s, s2=%s\n", t1, s2);
            break;
        case 4:
            strcat_custom(s1, t1);
            printf("Strings before reversing: s1=%s, s2=%s\n", t1, s2);
            printf("Strings after reversing:\n");
            strreverse(t1);
            break;
        default:
            return 0;
        }
        printf("s1=%s\n", s1);
        strcat_custom(s1, s2);
        strreverse(s1);
        printf("s2=%s\n", s1);
    }

    return 0;
}
