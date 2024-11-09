convert: convert.c conversion.c input_controller.c conversion.h input_controller.h
	gcc -o convert --coverage convert.c conversion.c input_controller.c


ctest: convert.c conversion.c input_controller.c conversion.h input_controller.h
	gcc -o ctest --coverage convert.c conversion.c input_controller.c

clean:
	rm -f *.o convert test *.gcda *.gcno *.gcov