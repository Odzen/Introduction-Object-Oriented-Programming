Observen que:
- El algortimo está en la clase MiAlgoritmo. La parte gráfica está en la clase MainWindow.
- MiAlgoritmo debe heredar de QThread y debe tener una función void run() donde esté el desarrollo del algoritmo. O sea, MiAlgoritmo es el Tablero y en run() se pone toda la lógica del juego de tetris.
- La sincronización entre el algoritmo y los gráficos se hace usando un QWaitCondition y un QMutex, como se indica en el código.
- Es importante que desde la clase que hereda QThread no modifiquen nada visual en Qt, porque de lo contrario se corrompe la memoria. O sea, no pueden imprimir directamente el tablero. Hay que hacerlo indirectamente. Ver el ejemplo.






  
