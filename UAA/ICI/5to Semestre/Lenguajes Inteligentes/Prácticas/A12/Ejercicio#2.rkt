#lang racket
;========================================== EJERCICIO #2 =====
;------------------------------------------------------------
; Desarrolle el programa para hallar el volumen de un cilindro.
; El programa utiliza como datos el radio de la base del
; cilindro y su altura, retornando el volumen del cilindro.
;------------------------------------------------------------

;*************** Definicion de PI.
(define PI 3.14)

;*************** Definicion de la función.
(define (volumen_cilindro radio altura)
  (* PI (* (* radio radio)altura)))

;*************** Ejemplos:
(volumen_cilindro 3 2)
(volumen_cilindro 5 3)
(volumen_cilindro 4 8)

;=============================================================