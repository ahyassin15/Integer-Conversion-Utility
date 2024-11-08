convert: convert.c conversion.c input_controller.c conversion.h input_controller.h
	gcc -o convert --coverage convert.c conversion.c input_controller.c
