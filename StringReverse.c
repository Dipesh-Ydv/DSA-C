#include<stdio.h>
#include<string.h>

void revStr(char *str) {
    int len = strlen(str);

    for (int i = 0; i < len/2; i++) {
        int temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

int main ()
{
    char *name[20];
    printf("Enter the Name : ");
    scanf("%s", name);

    printf("\nName before reversing : %s", name);

    revStr(name);
    printf("\n\nName after reversing : %s", name);
    return 0;
}