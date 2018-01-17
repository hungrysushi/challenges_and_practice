/*
 * Title: Interpreter
 * UVa id: 10033
 * Wrong Answer
 */

#include <stdio.h>

int interpret(int num_inst, int* ram, int* registers);

/* for debugging */
void print_registers(int* registers);

int main()
{
        int num_cases, num_inst;

        /* might have been easier for parsing to just store
         * RAM contents as chars, but this makes a bit simpler
         * to think about */
        int ram[1000];
        int registers[10];

        char buffer[5];
        char inst[3];

        fgets(buffer, 5, stdin);
        sscanf(buffer, "%d", &num_cases);
        fgets(buffer, 5, stdin);  /* discard empty line */

        int i;
        for (i = 0; i < num_cases; i++) {
                num_inst = 0;

                /* clear ram and registers */
                int j;
                for (j = 0; j < 1000; j++) {
                        ram[j] = 0;
                }
                for (j = 0; j < 10; j++) {
                        registers[j] = 0;
                }

                /* read in instructions until a blank line */
                while (fgets(buffer, 5, stdin) != NULL) {
                        if (sscanf(buffer, "%d", ram + num_inst) == 1) {
                                num_inst++;
                        } else {
                                break;
                        }
                }

                /* printf("%d\n", num_inst); */
                printf("%d\n\n",interpret(num_inst, ram, registers));
        }

        return 0;
}

int interpret(int num_inst, int* ram, int* registers) {
        int pc = 0, num_exec = 0;
        while (pc < num_inst) {  /* parse until halt instruction */
                num_exec++;

                int inst_type = ram[pc] / 100;  /* get the first digit */
                int arg_1 = (ram[pc] % 100) / 10;  /* get the first argument */
                int arg_2 = ram[pc] % 10;  /* get the last digit */

                /* print_registers(registers); */
                /* printf("processing inst %d\n", ram[pc]); */

                pc++;

                switch (inst_type) {
                        case 1:
                                /* halt */
                                pc = num_inst;
                                break;
                        case 2:
                                /* set dest register to literal */
                                registers[arg_1] = arg_2;
                                break;
                        case 3:
                                /* add literal to dest */
                                registers[arg_1] = (registers[arg_1] + arg_2) % 1000;
                                break;
                        case 4:
                                /* multiply register by literal */
                                registers[arg_1] = (registers[arg_1] * arg_2) % 1000;
                                break;
                        case 5:
                                /* set dest reg to value of source reg */
                                registers[arg_1] = registers[arg_2];
                                break;
                        case 6:
                                /* add source reg to dest */
                                registers[arg_1] = (registers[arg_1] + registers[arg_2]) % 1000;
                                break;
                        case 7:
                                /* multiply dest reg by source */
                                registers[arg_1] = (registers[arg_1] * registers[arg_2]) % 1000;
                                break;
                        case 8:
                                /* set dest to value in ram for the address in source */
                                registers[arg_1] = ram[registers[arg_2]];
                                break;
                        case 9:
                                /* set ram at address in arg 2 to value in source reg */
                                ram[registers[arg_2]] = registers[arg_1];
                                break;
                        case 0:
                                /* jump to ram location in register arg 1 */
                                if (registers[arg_2] != 0) {
                                        pc = registers[arg_1];
                                }
                        default:
                                break;
                }

        }

        return num_exec;
}

void print_registers(int* registers) {
        printf("registers[ ");
        int i;
        for (i = 0; i < 10; i++) {
                printf("%d ", registers[i]);
        }
        printf("]\n");
}
