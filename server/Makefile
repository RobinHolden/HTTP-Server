MAIN = http-server
SRC_C = $(wildcard src/*.c)
CFLAGS = -Wall -g -O0 -fsanitize=address
IFLAGS = -I api/libparser -I api/librequest-0.5/
LFLAGS = -L api/libparser -L api/librequest-0.5/ -lparser -lrequest -lm

$(MAIN): $(SRC_C)
	gcc $^ -o $@ $(CFLAGS) $(IFLAGS) $(LFLAGS)

run:
	export LD_LIBRARY_PATH=./api/libparser:./api/librequest-0.5 && \
	./$(MAIN) &

stop:
	@echo "Stopping HTTP server..."
	pkill http-server
	@echo "Done"

re: clean $(MAIN) run

clean:
	rm -rf $(MAIN) src/*~ src/*.swap
