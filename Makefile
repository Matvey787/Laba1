all: out.exe

out.exe: c_files\main.o
	g++ c_files\main.o -o out 

c_files\main.o: c_files\main.c
	g++ -c c_files\main.c -o c_files\main.o 

clean:
	rm -rf c_files/*.o