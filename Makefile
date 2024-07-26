run:
	g++ -c src/main.cpp -o obj/main.o
	g++ -c src/Planetary.cpp -o obj/Planetary.o
	g++ -c src/EntityManager.cpp -o obj/EntityManager.o
	g++ -c src/Simulation.cpp -o obj/Simulation.o
	g++ obj/main.o obj/Planetary.o obj/EntityManager.o obj/Simulation.o -o bin/app -lsfml-graphics -lsfml-window -lsfml-system
	bin/app

run1:
	g++ -c src/Simulation.cpp -o obj/Simulation.o
	g++ obj/main.o obj/Planetary.o obj/EntityManager.o obj/Simulation.o -o bin/app -lsfml-graphics -lsfml-window -lsfml-system
	bin/app