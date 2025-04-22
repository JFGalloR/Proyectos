#lang racket
;==================================== EJERCICIOS EN LISP =====
;------------------------------------------------------------
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Ejercicio #1 >>>
; Definir una función que calcule el valor de:
; F=1/(ax^2+bx^2+c)^(1/2)
;---------------------------------------------------------
(define (Funcion_1 a b c x)
  (/ 1 (sqrt (+ (* a x x) (* b x x) c))))

(displayln "\n=== Salida del ejercicio #1 ==========")
(Funcion_1 -1.5 1.6 0.9 1)
(Funcion_1 5 6 9 1)

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Ejercicio #2 >>>
; Definir una función que devuelva la longitus de una
; circunferencia, dando como parámetro el radio R de la
; misma siendo: L=2πR
;---------------------------------------------------------
(define PI 3.14159265359)
(define (Circunferencia radio)
  (* 2 PI radio))

(displayln "\n=== Salida del ejercicio #2 ==========")
(Circunferencia 5)
(Circunferencia 1.5)

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Ejercicio #3 >>>
; Definir una función que pase de grados centígrados a
; grados Fahrenheit, sabiendo que:
; F=(c+40)*1.8-40
;---------------------------------------------------------
(define (Celsius_Fahrenheit celsius)
  (- (* (+ celsius 40) 1.8) 40))

(displayln "\n=== Salida del ejercicio #3 ==========")
(Celsius_Fahrenheit 67)
(Celsius_Fahrenheit 0)

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Ejercicio #4 >>>
; Definir una función que, dados tres argumentos
; numéricos, devuelva cuál es el mediano, utilizando MAX
; y MIN.
;---------------------------------------------------------
(define (Mediano a b c)
  (max (min a b) (min a c) (min b c)))

(displayln "\n=== Salida del ejercicio #4 ==========")
(Mediano 5 10 3)
(Mediano 1 2 3)

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Ejercicio #5 >>>
; Definir un predicado que dados A, B y C como argumentos
; devuelva T si B^2+4AC es menor que cero.
;---------------------------------------------------------
(define (Funcion_2 a b c)
  (< (- (* b b) (* 4 b c)) 0))

(displayln "\n=== Salida del ejercicio #5 ==========")
(Funcion_2 1 2 3)
(Funcion_2 4 2 0)


;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Ejercicio #6 >>>
; Definir un predicado que devuelva T si alguno de sus
; dos primeros argumentos es menor que el tercero y mayor
; que el cuarto.
;---------------------------------------------------------
(define (Funcion_3 a b c d)
  (or (and (< a c)(> a d)) (and (< b c)(> b d))))

(displayln "\n=== Salida del ejercicio #6 ==========")
(Funcion_3 0 1 4 0)
(Funcion_3 1 2 3 4)

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Ejercicio #7 >>>
; Definir una función que calcule la entropía de un
; suceso aleatoria que representa k modos de realización
; de probabilidades P1, P2, P3, ..., Pk, cuyo valor viene
; dado por la expresión:
;---------------------------------------------------------
(define (Entropia probabilidades)
  (define suma 0)
  (for ([p probabilidades])
    (when (> p 0)
      (set! suma (+ suma (* p (log p 2))))))
  (* -1 suma))

(displayln "\n=== Salida del ejercicio #7 ==========")
(Entropia '(0.2 0.3 0.5))
(Entropia '(0.1 0.15 0.2 0.25 0.3 0.75 0.64))