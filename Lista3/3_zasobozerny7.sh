#!/bin/bash
# Autor: Paweł Niedziółka
#
# Aby zaobserwować działanie priorytetów na systemie Linuxowym należy:
#	Pierwsze co to wywołać skrypt ./3_zasobozerny7.sh &
#	Następnie można ustawić odpowiedni priorytet nice (można to zrobić też przy uruchamianiu skryptu!)
# 		poleceniem:    sudo renice -n [tu wpisujemy liczbe oznaczajaca priorytet] -p [tu wpisujemy PID]
#	Powtarzamy powyższe instrukcje jeszcze kilka razy i każdemu przypisujemy inny priorytet.
# 	Wyniki możemy zobaczyć wpisując polecenie htop oraz ustawiając filtry (F4 - wpisujemy "3_zasobozerny7.sh")

# !!!!!! UWAGA !!!!!! 
#	Niestety korzystając z systemu UNIXOWEGO MacOS nie zobaczyłem żadnych różnic w przydzielanych zasobach
#		dla poszczególnych priorytetów
# 		PLIK: 3_7a.png
#
#	Wykonując zadanie na systemie linuksowym zauważono jak system przydziela zasoby dla poszczególnych priorytetów
#		PLIK: 3_7b.png
#
# 	Być może to w jaki sposób jest stworzony system MacOS ma wpływ na to, dlaczego nie można zauważyć
#		różnicy przy różnych priorytetach i przydzieleniem zasobów.


i=55555555

while true; do
 a=$[i+1]
 b=$[i*i*i]
 c=$[i*i*i-i]
 d=$[i+i+i+i*i]
 e=$[i*i*i*i*i*i] 
 f=$[i*i*i]
 g=$[i*i*i-i]
 h=$[i+i+i+i*i]
 i=$[i*i*i*i*i*i] 
 j=$[i*i*i]
 k=$[i*i*i-i]
 l=$[i+i+i+i*i]
 m=$[i*i*i*i*i*i] 
 n=$[i*i*i]
 o=$[i*i*i-i]
 p=$[i+i+i+i*i]
 r=$[i*i*i*i*i*i] 
 s=$[i*i*i]
 t=$[i*i*i-i]
 w=$[i+i+i+i*i]
 aa=$[i*i*i*i*i*i] 
 bb=$[i*i*i]
 cc=$[i*i*i-i]
 dd=$[i+i+i+i*i]
 ee=$[i*i*i*i*i*i] 
 ff=$[i*i*i]
 gg=$[i*i*i-i]
 hh=$[i+i+i+i*i]
 ii=$[i*i*i*i*i*i] 
 jj=$[i*i*i]
 kk=$[i*i*i-i]
 ll=$[i+i+i+i*i]
 mm=$[i*i*i*i*i*i] 
 nn=$[i*i*i]
 oo=$[i*i*i-i]
 pp=$[i+i+i+i*i]
 rr=$[i*i*i*i*i*i] 
 ss=$[i*i*i]
 tt=$[i*i*i-i]
 uu=$[i+i+i+i*i]
 vv=$[i*i*i*i*i*i] 
 ww=$[i*i*i]
 xx=$[i*i*i-i]
 yy=$[i+i+i+i*i]
 zz=$[i*i*i*i*i*i] 
 aaa=$[i*i*i]
 bbb=$[i*i*i-i]
 ccc=$[i+i+i+i*i]
 ddd=$[i*i*i*i*i*i] 
 eee=$[i*i*i]
 fff=$[i*i*i-i]
 ggg=$[i+i+i+i*i]
 hhh=$[i*i*i*i*i*i] 
 iii=$[i*i*i]
 jjj=$[i*i*i-i]
 kkk=$[i+i+i+i*i]
 lll=$[i*i*i*i*i*i] 
 mmm=$[i*i*i]
 nnn=$[i*i*i-i]
 ooo=$[i+i+i+i*i]
 ppp=$[i*i*i*i*i*i] 
 rrr=$[i*i*i]
 sss=$[i*i*i-i]
 ttt=$[i+i+i+i*i]
 uuu=$[i*i*i*i*i*i] 
 vvv=$[i*i*i]
 xxx=$[i*i*i-i]
 yyy=$[i+i+i+i*i]
 zzz=$[i*i*i*i*i*i] 
 aaaa=$[i*i*i]
 bbbb=$[i*i*i-i]
 cccc=$[i+i+i+i*i]
 dddd=$[i*i*i*i*i*i] 
 eeee=$[i*i*i]
 ffff=$[i*i*i-i]
 gggg=$[i+i+i+i*i]
 hhhh=$[i*i*i*i*i*i] 
 iiii=$[i*i*i]
 jjjj=$[i*i*i-i]
 kkkk=$[i+i+i+i*i]
 llll=$[i*i*i*i*i*i] 
 
 
done
