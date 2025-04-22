#lang racket
;========================================== EJERCICIO #4 =====
;------------------------------------------------------------
;*************** Definición de la función.
(define (convert3 num1 num2 num3)
  (+ (* num3 100) (* num2 10) num1))
;*************** Ejemplos de la función:
(convert3 1 1 1)
(convert3 5 3 4)
;*************** a) Evaluar n^2 + 10:
(define (g n)
  (+ (* n n) 10))
; Ejemplos:
(g 2)
(g 5)
(g 9)
;*************** b) Evaluar (1/2)*n^2 + 20:
(define (h n)
  (+ (* (/ 1 2) (* n n)) 20))
; Ejemplos:
(h 2)
(h 5)
(h 9)
;*************** c) Evaluar 2 - (1/n):
(define (b n)
  (- 2 (/ 1 n)))
; Ejemplos:
(b 2)
(b 5)
(b 9)
;=============================================================