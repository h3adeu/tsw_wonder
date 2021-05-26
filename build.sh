cc -c -g -I. main.c
cc -c -g -I. task1.c
cc -c -g -I. task2.c
cc -c -g context_switch.s
cc -c -g context_init.c
cc -o test1 main.o task1.o task2.o context_switch.o context_init.o
