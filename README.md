# ArgenC

El lenguaje de programación estructurada **argenC**, es un lenguaje debilmente tipado y con tipado dinámico diseñado para ser utilizado en el sistema de educación secundaria Argentino. 
Este lenguajes es simple y su sintaxis es en el idioma Español. 
Utiliza lenguaje cotidiano, como si se programara en seudocódigo.

## Ejemplos

| Número de Ejemplo  | Nombre de Ejemplo  | Descripción de Ejemplo  |
|--------------------|--------------------|-------------------------|
| 1                  | primos             |calcula los primos anteriores a un primo ingresado.| 
| 2                  | fibonacci          |calcula los n primeros terminos de fibonnaci siendo n un parametro.|
| 3                  | factorial          |calcula el factorial de un numero entero ingresado.|
| 4                  | foreachtest        |itera una lista usando el "foreach" y muestra el pasaje a mayuscula de un string.|
| 5                  | estadisticas       |realiza funciones de estadistica.|
| 6                  | adivinador         | prueba los numeros random.|


**NOTA:** la extención definida para los archivos de código fuente de lenguaje **argenC** es **.arg**.

## Compilación y Ejecución
- Para compilar el compilador **argenCC** se debe realizar **make all** en la carpeta principal.
- Para la ejcución de los ejemplos se debe ejecutar : como prerequisito haber compilado exitosamente el compilador y luego **cd ejemplos** seguido de **./exampleRunner.sh "nombreDelEjemploACompilarYEjecutar"** (Ej: "./exampleRunner.sh primos").

## Documentación
En la carpeta **docs** se encuentran los siguientes archivos:
- **producciones.txt** con las producciones generadas en la definición de la gramática del lenguaje **argeC**
- **Informe TPE ATLC - EQUIPO S.A.B.pdf** es el informe del trabajo práctico especial.