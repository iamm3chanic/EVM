## Семестр 4
Задачи описаны в файлах *.pdf.  
Спасибо за помощь в решении других вариантов: 
- Сергей Аристеев @SAristeev
- Сергей Федоров

Все задачи здесь компилируются с ключами:
```
g++ -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized -fno-elide-constructors -fopenmp \
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC $*
```
Ключ `-fopenmp` опционально для третьей задачи.
А также проверяются на утечки памяти на **valgrind**. 

Задачи с двух контрольных лежат в директории `TEST`.  
