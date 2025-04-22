#lang racket
;========================================== EJERCICIO #2 =====
;------------------------------------------------------------
; Convertir una cantidad de dólar a euros.
;------------------------------------------------------------

;*************** Función para convertir:
(define (Dolar-Euro cantidad_dolar)
  (/ (* cantidad_dolar 20) 25))

;*************** Ejemplos de conversión:
(Dolar-Euro 10)
(Dolar-Euro 5)
(Dolar-Euro 20)
(Dolar-Euro 22)
(Dolar-Euro 35)

;=============================================================