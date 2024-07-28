run:
	g++ -c src/main.cpp -o obj/main.o -I"C:\SFML-2.6.0\include"
	g++ -c src/Planetary.cpp -o obj/Planetary.o -I"C:\SFML-2.6.0\include"
	g++ -c src/EntityManager.cpp -o obj/EntityManager.o -I"C:\SFML-2.6.0\include"
	g++ -c src/Simulation.cpp -o obj/Simulation.o -I"C:\SFML-2.6.0\include"
	g++ obj/main.o obj/Planetary.o obj/EntityManager.o obj/Simulation.o -o bin/app.exe -L"C:\SFML-2.6.0\lib" -lsfml-graphics -lsfml-window -lsfml-system
	bin/app.exe

run1:
	g++ -c src/Simulation.cpp -o obj/Simulation.o -I"C:\SFML-2.6.0\include"
	g++ obj/main.o obj/Planetary.o obj/EntityManager.o obj/Simulation.o -o bin/app.exe -L"C:\SFML-2.6.0\lib" -lsfml-graphics -lsfml-window -lsfml-system
	bin/app.exe

run2:
	g++ -c src/main.cpp -o obj/main.o -I"C:\SFML-2.6.0\include"
	g++ obj/main.o obj/Planetary.o obj/EntityManager.o obj/Simulation.o -o bin/app.exe -L"C:\SFML-2.6.0\lib" -lsfml-graphics -lsfml-window -lsfml-system
	bin/app.exe