#! /bin/bash

VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes"
SEP="===================================================="

execValid() {

	echo $VALGRIND ./cub3d maps/valid/$1
	$VALGRIND ./cub3d maps/valid/$1
	echo $SEP
	sleep 1;
}

make

execValid itachi.cub
execValid horror.cub
execValid mario.cub
execValid horror2.cub
execValid maze.cub
execValid wolfenstein.cub
