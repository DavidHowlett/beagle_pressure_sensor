/* Hello World program */

#include<stdio.h>

main() {
	//ch := make(chan int,1000)
	//go sender(ch)
	int i = 0;
	for (; i < 100000; i++) {
		//ch <- i
		printf("%d\n",i);
	}
	//close(ch)
}