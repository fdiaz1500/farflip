
#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    unsigned char buffer[10];
    unsigned char finalbuffer[10];
    FILE *infileptr;
    FILE *outfileptr;

    infileptr = fopen("test.in","rb");  // r for read, b for binary

    fread(buffer,sizeof(buffer),1,infileptr); // read 10 bytes to our buffer 
    for(int i = 0; i<10; i++)
    {
        finalbuffer[i] = buffer[i]^1;
        printf("Value: %04x\tXOR: %04x\n", buffer[i], (buffer[i]^1));     
    }
    
    
    if ((outfileptr = fopen("test.out", "wb")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }
    fwrite(finalbuffer, sizeof(finalbuffer), 1, outfileptr);


    fclose(outfileptr);
}
