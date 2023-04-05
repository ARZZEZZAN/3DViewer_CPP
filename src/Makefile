.PHONY: all install uninstall clean dvi dist tests build_tests open leaks style
CC = gcc
GCOV = -fprofile-arcs -ftest-coverage
CFLAGS = -lstdc++ -lgtest -std=c++17 -Wall -Werror -Wextra

EXE = unit_tests
TFN = Test/unit_tests.cc

all: uninstall clean install open

install:
	@make clean
	@cd View && qmake6 && make && make clean && rm Makefile && mv 3DViewer_v2-0.app $(HOME)/Desktop/

uninstall:
	@rm -rf $(HOME)/Desktop/3DViewer_v2-0.app
	
clean:
	@/bin/rm -rf **/*.o *.a build *.gcno *gcda report *.info main *.dSYM *.out gcov_report $(EXE) View/.qmake.stash View/3DViewer_v2-0.pro.user View/.qtc_clangd build-3DViewer_v2-0-Desktop_x86_darwin_generic_mach_o_64bit-Debug ../Archive_3DViewer_v2.0.tar.gz Archive_3DViewer_v2.0

dvi:
	open ./dvi.html
	
dist:
	@make clean
	@mkdir Archive_3DViewer_v2.0
	@cp -r Controller Model Test View dvi.html  main.cc Makefile Archive_3DViewer_v2.0
	@tar -cvzf Archive_3DViewer_v2.0.tar.gz Archive_3DViewer_v2.0
	@mv Archive_3DViewer_v2.0.tar.gz ../
	@rm -rf Archive_3DViewer_v2.0

tests: build_tests
	@./$(EXE)

build_tests: $(TFN)
	@${CC} $< Model/**/*.cc Controller/*.cc ${CFLAGS} -o $(EXE)

# sleep 1 - necessary for the correct opening of the application
open:
	@sleep 1 
	@open $(HOME)/Desktop/3DViewer_v2-0.app

style:
	@echo -------------------STYLE_TEST-------------------
	@cp ../materials/linters/.clang-format .
	clang-format -style=Google -n **/*.cc **/*.h
	@rm -rf .clang-format
