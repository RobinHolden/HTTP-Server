MAIN = http-server
SRC_C = $(wildcard src/*.c)
CFLAGS = -Wall -g -O0
IFLAGS = -I api/libparser -I api/librequest-0.5/  -L api/libparser -L api/librequest-0.5/
LFLAGS = -lparser -lrequest

$(MAIN): $(SRC_C)
	gcc $^ -o $@ $(CLAGS) $(IFLAGS) $(LFLAGS)

run:
	export LD_LIBRARY_PATH=./api/libparser:./api/librequest-0.5
	./$(MAIN) &

clean:
	rm -rf $(MAIN) src/*~ src/*.swap