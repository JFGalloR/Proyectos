#lang racket
;========================================== EJERCICIO #3 =====
;------------------------------------------------------------
; Elaborar una función recursiva para calcular factorial.
;------------------------------------------------------------

;*************** Función factorial.
(define factorial
  (lambda (n)
    (if (zero? n) 1
        (* n (factorial (sub1 n))))))

;*************** Ejemplos de factorial:
(factorial 20)
(factorial 0)
(factorial 100)

;=============================================================