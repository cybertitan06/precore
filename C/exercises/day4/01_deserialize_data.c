/**
 * Your goal is to unpack the entire structure into a instance of 'StudentInfo'.
 * @file ex73.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

typedef struct {
    char name[100];
    short age;
    char grade;
    char schoolName[100];

} StudentInfo;

// Here is a serialized buffer. The data is padded to the full size of each member, so deserializing
// it is trivial. The data is packed with the name first, age second, grade third, and finally the
// schoolName.
char cBuffer[300] = {   0x54,0x61,0x70,0x69,0x6f,0x63,0x61,0x00,    // 8            Name for first 7 bytes
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 16
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 24
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 32
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 40
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 48
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 56
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 64
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 72
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 80
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 88
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 96
                        0x00,0x00,0x00,0x00,0x00,0x11,0x0b,0x48,    // 104          Age for bytes 6 & 7, Grade is on byte 8
                        0x61,0x63,0x6b,0x65,0x72,0x20,0x55,0x6e,    // 112          School name is next 16 bytes
                        0x69,0x76,0x65,0x72,0x73,0x69,0x74,0x79,    // 120
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 128
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 136
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 144
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 152
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 160
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 168
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 176
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 184
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 192
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 200
                        0x00,0x00,0x00  };                          // 203

// Do not modify the 'CheckData' function for this exercise.
int check_data(StudentInfo* pData){
    if(strncmp("Tapioca", pData->name, 100)) return 0;
    if(pData->age != 17) return 0;
    if(pData->grade != 11) return 0;
    if(strncmp("Hacker University", pData->schoolName, 100)) return 0;
    return 1;
}

// Create a few deserializing functions
// ---- Start new functions
int deserialize_short(int iOffset, char *pSourceBuffer, short *pOut){
    memcpy(pOut, pSourceBuffer + iOffset, sizeof(short));
    *pOut = ntohs(*pOut);
    return sizeof(short);
}

int deserialize_char(int iOffset, char *pSourceBuffer, char *pOut){
    memcpy(pOut, pSourceBuffer + iOffset, sizeof(char));
    return sizeof(char);
}

int deserialize_byteArray(int iOffset, char *pSourceBuffer, char *pOut, int iLength){
    memcpy(pOut, pSourceBuffer + iOffset, iLength);
    return (sizeof(char) * iLength);

}
// ---- End new functions

int main(int argc, char** argv) {
    char printMessage[100] = "Hello World!";
    int iBufferOffset = 0;
    char *pcBuffer = NULL;

    // Fill this structure with the deserialized data
    StudentInfo deserializedData = {0};
    pcBuffer = cBuffer;

    iBufferOffset += deserialize_byteArray(iBufferOffset, pcBuffer, deserializedData.name, (sizeof(char)*100));
    iBufferOffset += deserialize_short(iBufferOffset, pcBuffer, &deserializedData.age);
    iBufferOffset += deserialize_char(iBufferOffset, pcBuffer, &deserializedData.grade);
    iBufferOffset += deserialize_byteArray(iBufferOffset, pcBuffer, deserializedData.schoolName, (sizeof(char)*100));

    printf("cBuffer ptr is %c\n", *(pcBuffer + iBufferOffset));
    printf("iBufferOffset is %d\n", iBufferOffset);
    printf("Name: %s\nAge: %d\nGrade: %c\nSchool: %s\n",
        deserializedData.name,
        deserializedData.age,
        deserializedData.grade,
        deserializedData.schoolName);
    fflush(stdout);

    // Try not to modify the checks.
    if(check_data(&deserializedData)){
        printf("Results: %s\n", printMessage);
    } else {
        printf("Results: No dice!\n");
    }
    
    return 0;
}
