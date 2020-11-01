#!/bin/bash
# Autor: Paweł Niedziółka
# 
#	Ustawiono limit na 100 procesów (ulimit -u 100) i uruchomiono skrypt w tej samej powłoce.
#	Po zapełnieniu wolnych miejsc wyskoczył komunikat o braku miejsca dla kolejnych tworzonych procesów.
#	
#	Dzięki zmniejszonemu limitowi można było zabić proces (polecenie kill all) - basha i kontynuować dalszą pracę.
#	
#	Jeżeli chodzi o systemu UNIXOWE np. MacOS, tam wywołanie tej funkcji powoduje niemożność
#		odpalenia jakiegokolwiek programu i tymczasowe "zbrickowanie" systemu. Pomaga wówczas
#		jedynie restart systemu - nie można wtedy nawet uruchomić nowego terminala!


while true; do
	./3_8.sh
done