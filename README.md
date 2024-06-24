# minitalk

**minitalk** es un proyecto de comunicación entre procesos que consta de un cliente y un servidor. Utiliza señales UNIX para enviar y recibir mensajes de texto.

## Características

### Parte obligatoria
- **Servidor**:
  - Se lanza primero y muestra su PID (Process ID).
  - Recibe y muestra mensajes de texto enviados por el cliente.
  - Puede recibir mensajes de varios clientes consecutivamente sin necesidad de reiniciar.
  - Muestra los mensajes de forma rápida (1 segundo para 100 caracteres es demasiado).

- **Cliente**:
  - Se lanza con dos parámetros: el PID del servidor y la cadena de texto a enviar.
  - Envía la cadena de texto al servidor utilizando señales UNIX (solo SIGUSR1 y SIGUSR2).

### Bonus
- El servidor confirma cada señal recibida enviando una señal al cliente.
- Soporte para caracteres Unicode.

### Notas
- Asegúrate de que las señales se envíen y reciban correctamente utilizando solo SIGUSR1 y SIGUSR2.
- Si el servidor no muestra los mensajes rápidamente, revisa tu implementación.
