#!/bin/bash

# Autor: Paweł Niedziółka
# Źródło instrukcji getopts: https://docs.oracle.com/cd/E26502_01/html/E29030/getopts-1.html#scrolltoc

# Jeżeli istnieje zmienna środowiskowa należy ją najpierw zadekaklarować!
#								[  $NEW_TAR  |  $MODIFICATION_TIME  |  $MASK  ]
# Należy pamiętać aby podać nazwę archiwum z końcówka .tar 					np. archiwum.tar
# a nazwę rozszerzenia (jako parametr) w cudzysłowie '*.rozszerzenie'		np. '*.c' 

# program się wysypuje, kiedy brakuje jakiegoś argumentu w środku 
# ale zakładamy jak w zadaniu, że argumenty występują w parach ze słowem kluczowym
# 	bash-3.2$ 	./zadanie4.sh -a test3.tar -n -m '*.pdf'
#				Podaj rozszerzenie pliku bez cudzysłowia! np. *.c : 


while getopts ":a:n:m:" opt; do
	case ${opt} in
	a)
		new_tar=$OPTARG
		;;
	n)
		modification_time=$OPTARG
		;;
	m)
		mask=$OPTARG
		;;
	# Gdy opcja jest niepoprawna
	\?)
		echo "Nie ma takiego możliwego parametru! Możliwe parametry to -a -n -m"
		;;
	# Usunięcie default error
	:)
		echo "Błąd! Wybrany parametr ( $OPTARG ) wymaga argumentu!"
		;;
	esac
done

if [ ! $new_tar ]; then
	new_tar=$NEW_TAR
	if [ ! $NEW_TAR ]; then
		while [ ! $new_tar ]; do
			echo "Podaj nazwe archiwum do stworzenia :  "
			read new_tar;
			#if [ ${new_tar: -4} == ".tar" ] ???? 
		done
	fi
fi

if [ ! $modification_time ]; then
	modification_time=$MODIFICATION_TIME
	if [ ! $CREATED_TIME ]; then
		while [ ! $modification_time ]; do
			echo "Podaj ilość dni od modyfikacji pliku :  "
			read modification_time;
		done
	fi
fi

if [ ! "$mask" ]; then
	mask=$MASK
	if [ ! $MASK ]; then
		while [ ! "$mask" ]; do
			echo "Podaj rozszerzenie pliku bez cudzysłowia! "np. *.c" : "
			read mask;
		done
	fi
fi
	
tar cfv $new_tar `find . -name "$mask" -mtime -$modification_time`
exit





