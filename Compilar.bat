
#!/bin/bash
    clear
echo "<Inicion de analizador Sintactico>"
    flex -l Proyecto.l
    bison -dv Proyecto.y
    gcc -o main  Proyecto.tab.c lex.yy.c
echo "<Fin>"