AUTEURS = HOLDEN_TALEB
MAIN = http-server
SRC_C = $(wildcard src/*.c)

$(MAIN): $(SRC_C)
	gcc $^ -o $@ -Wall -g -O0

clean:
	rm -rf $(MAIN) src/*~ src/*.swap .vscode gdb.txt

# Tapez "make tar" pour faire une archive du dossier avant chaque rendu.

tar: clean
	@ dir=$$(basename "$$PWD") && cd .. && tar cvfz $(AUTEURS).tgz  "$$dir"
	@ echo "==="; echo "Created ../$(AUTEURS).tgz"
