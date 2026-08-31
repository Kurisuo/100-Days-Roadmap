//Fetch - Decode - Execute

//35 Opcodes - 2 Bytes Long
unsigned short opcode;

//4k memory
unsigned char memory[4096];

//16 8-bit data registers named V0 to VF.
unsigned char V[16];

//Program Counter
unsigned short PC;

//12 bit register for memory address
unsigned short I;