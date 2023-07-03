COMPILER = g++
OBJS = ./build/*.o
APPNAME = SpaceInvaders
TARGET_TESTS = program_tests

CFLAGS = -std=c++11 -Wall --coverage
SFML = -L-Isfml/src/lib -lsfml-graphics -lsfml-window -lsfml-system

BUILD_DIR = ./build
INCLUDE_DIR = ./include
SRC_DIR = ./src
TEST_DIR = ./tests
THIRD_DIR = ./third_party
COVERAGE_DIR = ./coverage

all: ${BUILD_DIR}/${APPNAME}

${BUILD_DIR}/${APPNAME}: ${BUILD_DIR}/GameEngine.o ${BUILD_DIR}/ObjetoJogo.o ${BUILD_DIR}/GerenciadorEstados.o ${BUILD_DIR}/VariaveisGlobais.o ${BUILD_DIR}/Tiro.o ${BUILD_DIR}/Inimigo.o ${BUILD_DIR}/LinhaInimigos.o ${BUILD_DIR}/BlocoInimigos.o ${BUILD_DIR}/Player.o ${BUILD_DIR}/Tela.o ${BUILD_DIR}/main.o
	${COMPILER} ${CFLAGS} ${OBJS} -o ${BUILD_DIR}/${APPNAME} ${SFML}

${BUILD_DIR}/VariaveisGlobais.o: ${INCLUDE_DIR}/VariaveisGlobais.h ${SRC_DIR}/VariaveisGlobais.cpp
	${COMPILER} ${CFLAGS} -I ${INCLUDE_DIR}/ -Isfml/src/include -c ${SRC_DIR}/VariaveisGlobais.cpp -o ${BUILD_DIR}/VariaveisGlobais.o -DSFML_STATIC

${BUILD_DIR}/GameEngine.o: ${INCLUDE_DIR}/GameEngine.h ${INCLUDE_DIR}/BlocoInimigos.h ${INCLUDE_DIR}/GerenciadorEstados.h ${INCLUDE_DIR}/LinhaInimigos.h ${INCLUDE_DIR}/Player.h ${INCLUDE_DIR}/Inimigo.h ${INCLUDE_DIR}/Tiro.h ${SRC_DIR}/GameEngine.cpp
	${COMPILER} ${CFLAGS} -I ${INCLUDE_DIR}/ -Isfml/src/include -c ${SRC_DIR}/GameEngine.cpp -o ${BUILD_DIR}/GameEngine.o -DSFML_STATIC

${BUILD_DIR}/ObjetoJogo.o: ${INCLUDE_DIR}/ObjetoJogo.h ${SRC_DIR}/ObjetoJogo.cpp
	${COMPILER} ${CFLAGS} -I ${INCLUDE_DIR}/ -Isfml/src/include -c ${SRC_DIR}/ObjetoJogo.cpp -o ${BUILD_DIR}/ObjetoJogo.o -DSFML_STATIC

${BUILD_DIR}/GerenciadorEstados.o: ${INCLUDE_DIR}/GerenciadorEstados.h ${INCLUDE_DIR}/Estados.h ${SRC_DIR}/GerenciadorEstados.cpp
	${COMPILER} ${CFLAGS} -I ${INCLUDE_DIR}/ -Isfml/src/include -c ${SRC_DIR}/GerenciadorEstados.cpp -o ${BUILD_DIR}/GerenciadorEstados.o -DSFML_STATIC

${BUILD_DIR}/Tiro.o: ${INCLUDE_DIR}/Tiro.h ${INCLUDE_DIR}/VariaveisGlobais.h ${INCLUDE_DIR}/ObjetoJogo.h ${SRC_DIR}/Tiro.cpp
	${COMPILER} ${CFLAGS} -I ${INCLUDE_DIR}/ -Isfml/src/include -c ${SRC_DIR}/Tiro.cpp -o ${BUILD_DIR}/Tiro.o -DSFML_STATIC

${BUILD_DIR}/Inimigo.o: ${INCLUDE_DIR}/Inimigo.h ${INCLUDE_DIR}/VariaveisGlobais.h ${INCLUDE_DIR}/ObjetoJogo.h ${INCLUDE_DIR}/Tiro.h ${SRC_DIR}/Inimigo.cpp
	${COMPILER} ${CFLAGS} -I ${INCLUDE_DIR}/ -Isfml/src/include -c ${SRC_DIR}/Inimigo.cpp -o ${BUILD_DIR}/Inimigo.o -DSFML_STATIC

${BUILD_DIR}/LinhaInimigos.o: ${INCLUDE_DIR}/LinhaInimigos.h ${INCLUDE_DIR}/VariaveisGlobais.h ${INCLUDE_DIR}/ObjetoJogo.h ${INCLUDE_DIR}/Inimigo.h ${SRC_DIR}/LinhaInimigos.cpp
	${COMPILER} ${CFLAGS} -I ${INCLUDE_DIR}/ -Isfml/src/include -c ${SRC_DIR}/LinhaInimigos.cpp -o ${BUILD_DIR}/LinhaInimigos.o -DSFML_STATIC

${BUILD_DIR}/BlocoInimigos.o: ${INCLUDE_DIR}/BlocoInimigos.h ${INCLUDE_DIR}/ObjetoJogo.h ${INCLUDE_DIR}/LinhaInimigos.h ${INCLUDE_DIR}/Inimigo.h ${SRC_DIR}/BlocoInimigos.cpp
	${COMPILER} ${CFLAGS} -I ${INCLUDE_DIR}/ -Isfml/src/include -c ${SRC_DIR}/BlocoInimigos.cpp -o ${BUILD_DIR}/BlocoInimigos.o -DSFML_STATIC

${BUILD_DIR}/Player.o: ${INCLUDE_DIR}/Player.h ${INCLUDE_DIR}/VariaveisGlobais.h ${INCLUDE_DIR}/Tiro.h ${INCLUDE_DIR}/ObjetoJogo.h ${SRC_DIR}/Player.cpp
	${COMPILER} ${CFLAGS} -I ${INCLUDE_DIR}/ -Isfml/src/include -c ${SRC_DIR}/Player.cpp -o ${BUILD_DIR}/Player.o -DSFML_STATIC

${BUILD_DIR}/Tela.o: ${INCLUDE_DIR}/Tela.h ${INCLUDE_DIR}/VariaveisGlobais.h ${INCLUDE_DIR}/GameEngine.h ${INCLUDE_DIR}/Player.h ${INCLUDE_DIR}/Inimigo.h ${INCLUDE_DIR}/Tiro.h ${SRC_DIR}/Tela.cpp
	${COMPILER} ${CFLAGS} -I ${INCLUDE_DIR}/ -Isfml/src/include -c ${SRC_DIR}/Tela.cpp -o ${BUILD_DIR}/Tela.o -DSFML_STATIC

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Tela.h ${INCLUDE_DIR}/VariaveisGlobais.h ${SRC_DIR}/main.cpp
	${COMPILER} ${CFLAGS} -I ${INCLUDE_DIR}/ -Isfml/src/include -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o -DSFML_STATIC

${TEST_DIR}/TestesEstados.o: ${TEST_DIR}/estados/TestesEstados.cpp
	${COMPILER} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR}/ -Isfml/src/include -c ${TEST_DIR}/estados/TestesEstados.cpp -o ${TEST_DIR}/TestesEstados.o

${TEST_DIR}/TestesTela.o: ${TEST_DIR}/tela/TestesTela.cpp
	${COMPILER} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR}/ -Isfml/src/include -c ${TEST_DIR}/tela/TestesTela.cpp -o ${TEST_DIR}/TestesTela.o

${TEST_DIR}/TestesEngine.o: ${TEST_DIR}/engine/TestesEngine.cpp
	${COMPILER} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR}/ -Isfml/src/include -c ${TEST_DIR}/engine/TestesEngine.cpp -o ${TEST_DIR}/TestesEngine.o

${TEST_DIR}/TestesInimigos.o: ${TEST_DIR}/objetos/TestesInimigos.cpp
	${COMPILER} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR}/ -Isfml/src/include -c ${TEST_DIR}/objetos/TestesInimigos.cpp -o ${TEST_DIR}/TestesInimigos.o

${TEST_DIR}/MainTestes.o: ${TEST_DIR}/MainTestes.cpp
	${COMPILER} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR}/ -Isfml/src/include -c ${TEST_DIR}/MainTestes.cpp -o ${TEST_DIR}/MainTestes.o

tests: all ${TEST_DIR}/TestesEngine.o ${TEST_DIR}/TestesEstados.o ${TEST_DIR}/TestesTela.o ${TEST_DIR}/TestesInimigos.o ${TEST_DIR}/MainTestes.o
	${COMPILER} ${CFLAGS} -o ${TEST_DIR}/${TARGET_TESTS} ${BUILD_DIR}/GameEngine.o ${BUILD_DIR}/ObjetoJogo.o ${BUILD_DIR}/GerenciadorEstados.o ${BUILD_DIR}/VariaveisGlobais.o ${BUILD_DIR}/Tiro.o ${BUILD_DIR}/Inimigo.o ${BUILD_DIR}/LinhaInimigos.o ${BUILD_DIR}/BlocoInimigos.o ${BUILD_DIR}/Player.o ${BUILD_DIR}/Tela.o ${TEST_DIR}/*.o ${SFML}

run_tests: tests
	./${TEST_DIR}/${TARGET_TESTS}

coverage: run_tests
	gcovr -r . --exclude="third_party/doctest.h"
	gcovr -r . --exclude="third_party/doctest.h" -b	

html_coverage: run_tests
	gcovr -r . --exclude="third_party/doctest.h" --html --html-details -o ${COVERAGE_DIR}/relatorio.html

run: all
	./${BUILD_DIR}/${APPNAME}

documentation:
	doxygen Doxyfile

clean:
	rm -f ${BUILD_DIR}/*
	rm -f ${TEST_DIR}/*.o ${TEST_DIR}/*.gcda ${TEST_DIR}/*.gcno ${TEST_DIR}/${TARGET_TESTS}
	rm -f ${COVERAGE_DIR}/*
	rm -rf ./doc/*