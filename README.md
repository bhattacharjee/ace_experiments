# ace_experiments
Experiments to learn the ACE library

To run, execute the following commands:

1. Setup the environment
	source ./env.sh

2. Build the ACE library
	cd ACE_wrappers
	make -j10
	cd ..

3. Go to the experiments source folder
	cd src

4. Copy hello_ace to start off on your own project
	cp -r hello_ace my_own_project

5. Modify, make and get running
	cd my_own_project
	make
	./hello_ace

