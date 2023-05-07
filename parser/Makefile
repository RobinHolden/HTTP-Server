MAIN = http-server
SRC_C = $(wildcard src/*.c)

$(MAIN): $(SRC_C)
	gcc $^ -o $@ -Wall -g -O0

clean:
	rm -rf $(MAIN) src/*~ src/*.swap

tests: clean $(MAIN)
	./test.sh
