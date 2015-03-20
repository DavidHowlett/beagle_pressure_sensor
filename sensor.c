#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/i2c-dev.h>

int main(){
    printf("Program started\n");
    int file;
    char *filename = "/dev/i2c-0";
    if ((file = open(filename, O_RDWR)) < 0) {
        /* ERROR HANDLING: you can check errno to see what went wrong */
        perror("Failed to open the i2c bus\n");
        exit(1);
    }
    int addr = 0b00101001;          // The I2C address of the ADC
    if (ioctl(file, I2C_SLAVE, addr) < 0) {
        printf("Failed to acquire bus access and/or talk to slave.\n");
        /* ERROR HANDLING; you can check errno to see what went wrong */
        exit(1);
    }
    char buf[10] = {0};
    float data;
    char channel;
    
    for (int i = 0; i<4; i++) {
        // Using I2C Read
        if (read(file,buf,2) != 2) {
            /* ERROR HANDLING: i2c transaction failed */
            printf("Failed to read from the i2c bus.\n");
            printf(g_strerror(errno));
            printf("\n\n");
        } else {
            data = (float)((buf[0] & 0b00001111)<<8)+buf[1];
            data = data/4096*5;
            channel = ((buf[0] & 0b00110000)>>4);
            printf("Channel %02d Data:  %04f\n",channel,data);
        }
    }
    printf("Program finished\n");
}