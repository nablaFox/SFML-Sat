all: compile

compile:
	g++ SAT\main.cpp SAT\src\Application.cpp SAT\src\Box.cpp SAT\src\Collision.cpp \
	-I include -I SAT\include \
	-o SAT\bin\sat \
	-L include\SFML\lib -l sfml-window -l sfml-system -l sfml-graphics
	