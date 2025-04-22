#lang racket
;========================================== EJERCICIO #5 =====
;------------------------------------------------------------
; Definir el programa der suma-monedas. Consume cuatro
; números: el número de monedas de $1, $2, $5 y $10 en la
; bolsa. Produce la cantidad de dinero en la bolsa.
;------------------------------------------------------------

;*************** Definición de la función.
(define (suma_monedas m1 m2 m3 m4)
  (+ (* m1 1) (* m2 2) (* m3 5) (* m4 10) ))

;*************** Ejemplos de la función:
(suma_monedas 100 40 30 20)
(suma_monedas 23 40 200 10)

;=============================================================