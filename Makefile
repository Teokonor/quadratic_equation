default_target: compile

compile:
	cd build; cmake ../src; make; cd ..

check: compile
	cd tests/build; cmake ../src; make; ./testing_quadratic_equation; cd ../..

clean:
	cd build; rm -rf *; touch emptyfile; cd ../tests/build; rm -rf *; touch emptyfile; cd ../../example/build ; rm -rf *; touch emptyfile; cd ../.. 