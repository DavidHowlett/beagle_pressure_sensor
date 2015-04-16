#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <linux/i2c-dev.h>

int main(){
    int file;
    int adapter_nr = 1; /* probably dynamically determined */
    char filename[20];
    puts("This is a pressure sensor");
    sprintf(filename, "/dev/i2c-%d", adapter_nr);
    file = open(filename, O_RDWR);
    if (file < 0) {
        /* ERROR HANDLING; you can check errno to see what went wrong */
        puts("File opened incorrectly");
        exit(1);
    }
    int addr = 120; /* The I2C address */

    if (ioctl(file, I2C_SLAVE, addr) < 0) {
        /* ERROR HANDLING; you can check errno to see what went wrong */
        puts("Could not set address of the sensor");
        exit(1);
    }
    char buf[4];
    buf[2]=255;
    buf[3]=0;
    //int i;
    //for(i=0;i<100000;i++){
    while(1){
        read(file, buf, 2);
        printf(buf);
        
        
    
        //printf("%d\n",256*buf[0]+buf[1]);
        //usleep(10000);
    }
}
