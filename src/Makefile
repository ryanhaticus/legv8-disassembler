all: disasm

disasm: b_instruction.o cb_instruction.o d_instruction.o i_instruction.o iw_instruction.o r_instruction.o register.o immediate.o label.o main.o
	g++ b_instruction.o cb_instruction.o d_instruction.o i_instruction.o iw_instruction.o r_instruction.o register.o immediate.o label.o main.o -o ../disasm -Wall -Werror

b_instruction.o: ./lib/b_instruction/b_instruction.cpp ./lib/b_instruction/b_instruction.h
	g++ -c ./lib/b_instruction/b_instruction.cpp -o b_instruction.o -Wall -Werror

cb_instruction.o: ./lib/cb_instruction/cb_instruction.cpp ./lib/cb_instruction/cb_instruction.h
	g++ -c ./lib/cb_instruction/cb_instruction.cpp -o cb_instruction.o -Wall -Werror

d_instruction.o: ./lib/d_instruction/d_instruction.cpp ./lib/d_instruction/d_instruction.h
	g++ -c ./lib/d_instruction/d_instruction.cpp -o d_instruction.o -Wall -Werror

i_instruction.o: ./lib/i_instruction/i_instruction.cpp ./lib/i_instruction/i_instruction.h
	g++ -c ./lib/i_instruction/i_instruction.cpp -o i_instruction.o -Wall -Werror

iw_instruction.o: ./lib/iw_instruction/iw_instruction.cpp ./lib/iw_instruction/iw_instruction.h
	g++ -c ./lib/iw_instruction/iw_instruction.cpp -o iw_instruction.o -Wall -Werror

r_instruction.o: ./lib/r_instruction/r_instruction.cpp ./lib/r_instruction/r_instruction.h
	g++ -c ./lib/r_instruction/r_instruction.cpp -o r_instruction.o -Wall -Werror

register.o: ./lib/register/register.cpp ./lib/register/register.h
	g++ -c ./lib/register/register.cpp -o register.o -Wall -Werror

immediate.o: ./lib/immediate/immediate.cpp ./lib/immediate/immediate.h
	g++ -c ./lib/immediate/immediate.cpp -o immediate.o -Wall -Werror

label.o: ./lib/label/label.cpp ./lib/label/label.h
	g++ -c ./lib/label/label.cpp -o label.o -Wall -Werror

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -o main.o -Wall -Werror

clean:
	rm -rf main *.o *.dSYM *.txt