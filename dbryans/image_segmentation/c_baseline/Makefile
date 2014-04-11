
CC = gcc

CFLAGS = -c -Wall
CC_OPT = -o3

INCLUDES =

LFLAGS = 

LIBS =

SRC_DIR	  = ./src/
OBJ_DIR	  = ./obj/
BIN_DIR	  = ./bin/
RESUL_DIR = ./out/

SRCS = $(wildcard $(SRC_DIR)*.c)

OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

EXECUTABLE = $(BIN_DIR)gms

.PHONY: depend clean

run:	all
		@echo "Executing ..."
		@./$(EXECUTABLE)

all:	$(EXECUTABLE)

$(EXECUTABLE): $(OBJS) 
			   @$(CC) $(OBJS) -o $(EXECUTABLE) $(INCLUDES) $(LFLAGS) $(LIBS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			   @echo "compiling $<"	
			   @$(CC) $(CC_OPT) $(CFLAGS) $< -o $@

clean:
		@echo "Cleaning object files"
		@rm -f $(OBJS)
		@echo "Cleaning Result"	
		@rm -f $(RESUL_DIR)*

depend: $(SRCS)
		makedepend $(INCLUDES) $^

