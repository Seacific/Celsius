RaycastEngine: src/main.c
	gcc src/main.c -LDependencies/lib/ -lSDL2 -o RaycastRenderer -IDependencies/include/ -g
	./RaycastRenderer
