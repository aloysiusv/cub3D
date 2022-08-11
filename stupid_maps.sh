#! /bin/bash

VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes"
SEP="===================================================="

execMandatory() {

	echo $VALGRIND ./cub3d maps/tests/$1
	$VALGRIND ./cub3d maps/tests/$1
	echo $SEP
	sleep 3
}

make

# execMandatory map.cbu
# execMandatory emptymap.cub
execMandatory closed.cub
execMandatory emptymap.cub
execMandatory errormap.cub
execMandatory errormap2.cub
execMandatory errormap3.cub
execMandatory errormap4.cub
execMandatory errormap5.cub
execMandatory errormap6.cub
execMandatory errormap7.cub
execMandatory errormap8.cub
execMandatory errormap9.cub
execMandatory missing_Crgb.cub
execMandatory missing_Frgb.cub
execMandatory missingC.cub
execMandatory missingF.cub
execMandatory missingNO.cub
execMandatory missingSO.cub
execMandatory missingWE.cub
execMandatory multiplayer.cub
execMandatory multipleC.cub
execMandatory multipleF.cub
execMandatory multipleEA.cub
execMandatory multipleNO.cub
execMandatory multipleSO.cub
execMandatory multipleWE.cub
execMandatory non_closed_map.cub
execMandatory non_closed_map2.cub
execMandatory non_closed_map3.cub
execMandatory non_closed_map4.cub
execMandatory non_closed_map5.cub
execMandatory non_closed_map6.cub
execMandatory non_closed_map7.cub
execMandatory non_closed_map8.cub
execMandatory noplayer.cub
execMandatory over_Crgb.cub
execMandatory over_Frgb.cub
execMandatory rgb_error.cub
execMandatory rgb_error2.cub
execMandatory rgb_error3.cub
execMandatory rgb_error4.cub
execMandatory rgb_error5.cub
execMandatory rgb_error6.cub
execMandatory rgb_error7.cub
execMandatory rgb_error8.cub
execMandatory rgb_error9.cub
execMandatory splitted_map.cub
execMandatory too_big_north_texture.cub
execMandatory too_big_west_texture.cub
