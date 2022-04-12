# Porównanie szybkości programów w Javie i C++

## Środowisko
  * Linux 5.10.0-13-amd64 x86_64
## Wersje języków programowania
  * Java 11.0.14
  * C++ (Debian 10.2.1-6) 10.2.1 20210110
## Opis działania programu
  Najpierw program generuje tablicę wskazującą czy dana liczba jest pierwsza używając sita Eratostenesa.
  
  Potem generuje N losowych parzystych liczb z przedziału [6, M] i dla każdej znajduje podział na dwie liczby pierwsze,
  które się do niej sumują. 

  Pełny opis zadania (na którym bazowałem się pisząc ten program) znajduje się w pliku goldbachs_conjecture.pdf.
## Opcje kompilacji
  * javac Main.java
  * g++ main.cpp -o main
  * g++ -O3 main.cpp -o main

## Wyniki dla liczb losowych generowanych na bieżąco
|  Komenda wywołania   | N = 500<br/>M = 1000                                        | N = 10000000<br/>M = 1000                                      | N = 500 <br/>M = 1000000000                                  | N = 10000000<br/>M = 1000000000                               |
|:--------------------:|:------------------------------------------------------------|:---------------------------------------------------------------|:-------------------------------------------------------------|:--------------------------------------------------------------|
|    time java Main    | real    0m0,132s<br/>user    0m0,201s <br/>sys     0m0,118s | real    1m30,243s<br/>user    0m15,157s <br/>sys     0m41,539s | real    0m21,702s<br/>user    0m21,324s<br/>sys     0m1,080s | real    3m24,198s<br/>user    0m40,684s<br/>sys     0m47,853s |
| time java -Xint Main | real    0m0,145s<br/>user    0m0,083s <br/>sys     0m0,067s | real    6m17,703s<br/>user    4m51,954s <br/>sys     1m24,141s | real    1m1,280s<br/>user    1m0,936s<br/>sys     0m0,933s   | real    8m34,907s<br/>user    5m43,199s<br/>sys     1m46,850s |
|     time ./main      | real    0m0,009s<br/>user    0m0,010s <br/>sys     0m0,000s | real    1m23,643s<br/>user    0m4,831s <br/>sys     0m22,103s  | real    0m34,478s<br/>user    0m33,637s<br/>sys     0m0,820s | real    2m41,622s<br/>user    0m42,556s<br/>sys     0m26,395s |
| time ./main (z -O3)  | real    0m0,009s<br/>user    0m0,000s <br/>sys     0m0,009s | real    0m52,290s<br/>user    0m4,187s <br/>sys     0m20,896s  | real    0m20,445s<br/>user    0m19,884s<br/>sys     0m0,556s | real    3m12,623s<br/>user    0m28,195s<br/>sys     0m24,683s |


