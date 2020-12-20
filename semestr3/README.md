## Семестр 3
Задачи описаны в файлах *.pdf.  
Спасибо за помощь в решении других вариантов: 
- Сергей Аристеев @SAristeev
- Сергей Федоров
- Дмитрий Ильин
- Антон Жебриков

Все задачи здесь компилируются с ключами:
```
g++ -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized \
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC $*
```
А также проверяются на утечки памяти на **valgrind**. 

Коллоквиум и ответы к нему лежат в директории `colloc`.  
Спасибо за помощь в составлении документа "kollokvium_po_EVM.docx":  
- Анна Павликова
- Сергей Федоров
- Айлина Юмагулова
- Никита Макаров  

Задачи с экзамена и вопросы (367) с краткими ответами лежат в директории `EXAM`.  
Спасибо за помощь в подготовке ответов ANSWERS.md:
- Сергей Аристеев @SAristeev
