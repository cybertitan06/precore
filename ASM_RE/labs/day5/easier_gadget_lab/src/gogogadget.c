#include <stdio.h>
#include <stdlib.h>


int pincheck(int pin)
{
    if (pin == 0x1234)
    {
        printf("You did it!\n");
        return 0;
    }
    return -1;
}

int get_user_input()
{
    char user_input[20] = { 0 };
    printf("Enter pin: ");
    scanf("%s", user_input);
    printf("User Input: %s\n", user_input);
    return atoi(user_input);
}

#ifdef ARCH_64
int random_function()
{
    asm("pop %rdi; ret\n");
}
#endif

int main()
{
    printf("Trying to authenticate...");
    int pin = get_user_input();
    // pincheck(pin);
    printf("Please present smart card certificate to authenticate\n");
    return 0;
}
