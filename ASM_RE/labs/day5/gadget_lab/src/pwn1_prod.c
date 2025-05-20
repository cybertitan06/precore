#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* printf */

int smart_card_authentication(unsigned int pin);
int obtain_smart_card_certificate();
int encrypt_decrypt_rc4(unsigned char *key, unsigned char *data, unsigned char *encrypted_buffer);

int main () {

    obtain_smart_card_certificate();
    __asm__("leave; ret; pop rdi; ret; xor rdx, rdx; ret;");
}

int obtain_smart_card_certificate() {

    /*TRASH MAYBE USE LATER*/
    unsigned char s[256];
    int i = 0;
    for(; i < 256; i++) {
        s[i] = i;
    }

    int user_input_size = 256;
    char user_input[256] = { 0 };
    /* Credential Verification*/
    printf("Please enter your username:\n");
    if(fgets(user_input, user_input_size, stdin) != 0) {
        printf("Username stored at %p\n", user_input);
        printf("Thank you, ");
        printf(user_input);
        printf("\nPlease present your smart card token certificate in order to authenticate with our server\n");
    }
    else {
        printf("Please enter a valid username.");
    }
    return 0;

}

int smart_card_authentication(unsigned int pin) {

    
    if(pin != 0x42069) {
        exit(0);
    }
    else {
        /* RC4 decrypt flag with pin as the password*/
        /* flag{@uth3nt1c@t3d!} */
        unsigned char encrypted[26] = {0x37,0xc0,0x29,0x38,0x87,0xe4,0x13,0xc5,0x17,0xda,0x1c,0x8c,0x8e,0xac,0xc7,0xdc,0xe5,0x37,0x79,0xd8};
        unsigned char decrypted[26] = { 0 };
        encrypt_decrypt_rc4(&pin, encrypted, decrypted);
        int i = 0;
        printf("\n%s\n", decrypted);
    }
    
    exit(0);
}

int encrypt_decrypt_rc4(unsigned char *key, unsigned char *data, unsigned char *encrypted_buffer) {

    unsigned int key_len = strlen(key);
    unsigned int msg_len = strlen(data);
    
    unsigned char S[256];

    /* Key scheduling algorithm */
    int i = 0;
    for(; i < 256; i++) {
        S[i] = i;
    }

    int j = 0;
    i = 0;
    for(; i < 256; i++) {
        j = (j + S[i] + key[i % key_len]) % 256;
        unsigned char temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    /* Pseudo-random generation algorithm (PRGA)*/
    i = 0;
    j = 0;
    
    unsigned char key_stream[256];
    unsigned int key_counter = 0;
    int n = 0;
    for(; n < msg_len; n++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        unsigned char temp = S[i];
        S[i] = S[j];
        S[j] = temp;
        unsigned char t = (S[i] + S[j]) % 256;
        key_stream[n] = S[t];
    }

    /* XOR Key Stream with Plain Text */    


    i = 0;
    for(; i < msg_len; i++) {
        encrypted_buffer[i] = key_stream[i] ^ data[i];
    }
    return 0;
}
