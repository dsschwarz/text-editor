SHELL=C:/Window/System32/cmd.exe
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CC_FLAGS := -I"C:/SFML-master/include" -DSFML_DYNAMIC 
LD_FLAGS := -L"C:/SFML-2.0-custom/lib" -static-libstdc++ -static-libgcc -lsfml-graphics -lsfml-window -lsfml-system

main.exe: $(OBJ_FILES)
	g++ -o $@ $^ $(LD_FLAGS) 

obj/%.o: src/%.cpp
	g++ -c -o $@ $< $(CC_FLAGS) 

clean: 
	del obj\*.o

run:
	main.exe

