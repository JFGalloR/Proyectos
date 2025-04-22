#lang racket
;========================================== EJERCICIO #1 =====
;------------------------------------------------------------
; Desarrolle el programa para hallar el área de un cilindro.
; El programa utiliza como datos el radio de la base del
; cilindro y su altura, retornando el área del cilindro.
;------------------------------------------------------------

;*************** Definicion de PI.
(define PI 3.14)

;*************** Definicion de la función.
(define (area_cilindro radio altura)
  (+ (* 2 PI radio altura)
     (* 2 PI (* radio radio))))

;*************** Ejemplos:
(area_cilindro 3 2)
(area_cilindro 4 6)
(area_cilindro 6 3)

;=============================================================