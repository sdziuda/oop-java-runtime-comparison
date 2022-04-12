# Porównanie szybkości programów w Javie i C++

## Środowisko
  * Linux 5.10.0-13-amd64 x86_64
## Wersje języków programowania
  * Java 11.0.14
  * C++ (Debian 10.2.1-6) 10.2.1 20210110
## Opis działania programu
  Najpierw program generuje tablicę wskazującą czy dana liczba z przedziału [2, M] jest pierwsza używając sita Eratostenesa.
  
  Potem pobiera N liczb (które powinny być parzyste, z przedziału [6, M]) i dla każdej znajduje podział na dwie liczby pierwsze,
  które się do niej sumują. 

  Pełny opis zadania (na którym bazowałem się pisząc ten program) znajduje się w pliku <a href="https://github.com/sdziuda/oop-java-runtime-comparison/blob/main/goldbachs_conjecture.pdf">goldbachs_conjecture.pdf</a>.
## Opcje kompilacji
  * javac Main.java
  * g++ main.cpp -o main
  * g++ -O3 main.cpp -o main

## Generowanie pliku testowego
  * bash generate.sh N M

## Uruchamianie programu
  * Najpierw należy zmienić N i M w pliku Main.java i main.cpp na takie jakie nas interesują (w kolejnym kroku odpowiednio ($1) i ($2)).
  * Następnie wywołać program za pomocą:
    * time java (-Xint) Main < ../test_files/N($1)_M($2).in
    * time ./main < ../test_files/N($1)_M($2).in

## Wyniki dla liczb z plików testowych
|  Komenda wywołania   | N = 500<br/>M = 1000                                        | N = 1000000<br/>M = 1000                                      | N = 500 <br/>M = 1000000000                                   | N = 1000000<br/>M = 1000000000                                |
|:--------------------:|:------------------------------------------------------------|:--------------------------------------------------------------|:--------------------------------------------------------------|:--------------------------------------------------------------|
|    time java Main    | real    0m0,168s<br/>user    0m0,306s <br/>sys     0m0,100s | real    0m11,564s<br/>user    0m3,170s <br/>sys     0m5,307s  | real    0m17,710s<br/>user    0m17,824s <br/>sys     0m0,696s | real    0m37,027s<br/>user    0m20,124s <br/>sys     0m6,092s |
| time java -Xint Main | real    0m0,195s<br/>user    0m0,143s <br/>sys     0m0,053s | real    1m23,930s<br/>user    1m15,478s <br/>sys     0m9,131s | real    0m52,942s<br/>user    0m52,758s <br/>sys     0m0,742s | real    2m35,835s<br/>user    2m28,040s <br/>sys     0m9,689s |
|     time ./main      | real    0m0,010s<br/>user    0m0,001s <br/>sys     0m0,009s | real    0m5,980s<br/>user    0m0,652s <br/>sys     0m2,352s   | real    0m36,567s<br/>user    0m36,200s <br/>sys     0m0,353s | real    0m46,267s<br/>user    0m37,868s <br/>sys     0m3,388s |
| time ./main (z -O3)  | real    0m0,009s<br/>user    0m0,004s <br/>sys     0m0,005s | real    0m4,785s<br/>user    0m0,534s <br/>sys     0m3,009s   | real    0m17,003s<br/>user    0m16,629s <br/>sys     0m0,372s | real    0m27,463s<br/>user    0m16,692s <br/>sys     0m2,870s |


## Wyniki dla liczb losowych generowanych na bieżąco
  Raczej jako ciekawostka niż coś, co faktycznie pokazuje porównanie obu języków.

|  Komenda wywołania   | N = 500<br/>M = 1000                                        | N = 1000000<br/>M = 1000                                      | N = 500 <br/>M = 1000000000                                  | N = 1000000<br/>M = 1000000000                                 |
|:--------------------:|:------------------------------------------------------------|:--------------------------------------------------------------|:-------------------------------------------------------------|:---------------------------------------------------------------|
|    time java Main    | real    0m0,132s<br/>user    0m0,201s <br/>sys     0m0,118s | real    0m12,973s<br/>user    0m2,325s <br/>sys     0m3,801s  | real    0m21,702s<br/>user    0m21,324s<br/>sys     0m1,080s | real    0m35,335s<br/>user    0m18,799s <br/>sys     0m5,431s  |
| time java -Xint Main | real    0m0,145s<br/>user    0m0,083s <br/>sys     0m0,067s | real    0m37,115s<br/>user    0m29,414s <br/>sys     0m8,450s | real    1m1,280s<br/>user    1m0,936s<br/>sys     0m0,933s   | real    1m33,749s<br/>user    1m24,089s <br/>sys     0m10,614s |
|     time ./main      | real    0m0,009s<br/>user    0m0,010s <br/>sys     0m0,000s | real    0m4,898s<br/>user    0m0,476s <br/>sys     0m2,488s   | real    0m34,478s<br/>user    0m33,637s<br/>sys     0m0,820s | real    0m47,087s<br/>user    0m36,420s <br/>sys     0m3,363s  |
| time ./main (z -O3)  | real    0m0,009s<br/>user    0m0,000s <br/>sys     0m0,009s | real    0m7,536s<br/>user    0m0,429s <br/>sys     0m2,694s   | real    0m20,445s<br/>user    0m19,884s<br/>sys     0m0,556s | real    0m26,703s<br/>user    0m16,403s <br/>sys     0m2,943s  |


