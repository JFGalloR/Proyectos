#lang racket
;==================================== EJERCICIOS EN LISP =====
;------------------------------------------------------------

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Función condicional >>>
; Realiza los ejercicios e indica los resultados de las
; siguientes funciones
;------------------------------------------------------------
(define (Funcion_Cond valor)
  (cond
    [(<= valor 1000) (* 0.040 1000)]
    [(<= valor 5000) (+ (* 1000 0.040)
                        (* (- valor 1000) 0.045))]
    [else (+ (* 1000 0.040)
             (* 4000 0.045)
             (* (- valor 10000) 0.055))]))

(displayln "\n=== Resultados =====================\n")

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Ejercicio a) >>>
; valor = 500
(display "Ejercicio a) ")
(Funcion_Cond 500)

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Ejercicio b) >>>
; valor = 2800
(display "Ejercicio b) ")
(Funcion_Cond 2800)

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Ejercicio c) >>>
(display "Ejercicio c) ")
(Funcion_Cond 15000)

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Ejercicio d) >>>
; Determinar cuando "n" es una solución a la ecuación:
; 4n^2 + 6n + 2 = 462.
;------------------------------------------------------------
(define (ec3 n)
  (= (+ (* 4 (* n n)) (* 6 n) 2) 462))

; Ejemplo #1:
(display "\nEjercicio d) Ejemplo #1: ")
(ec3 10)

; Ejemplo #2:
(display "Ejercicio d) Ejemplo #2: ")
(ec3 12)

; Ejemplo #3:
(display "Ejercicio d) Ejemplo #3: ")
(ec3 14)

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Ejercicio e) >>>
; Determinar cuando "n" es una solución a la ecuación:
; 2n^2 = 102.
;------------------------------------------------------------
(define (ec2 n)
  (= (* 2 (* n n)) 102.00000000000001))

; Ejemplo #1:
(display "\nEjercicio e) Ejemplo #1: ")
(ec2 7)

; Ejemplo #2:
(display "Ejercicio e) Ejemplo #2: ")
(ec2 10)

; Ejemplo #3:
(display "Ejercicio e) Ejemplo #3: ")
(ec2 7.14142842854284999799939981136731)