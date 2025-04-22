#lang racket
;=============================== SERIE FIBONACCI EN LISP =====
;------------------------------------------------------------
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Función >>>
(define (Fibonacci valor)
  (if (= valor 0)
  0
  (if (= valor 1)
  1
  (+ (Fibonacci (- valor 1))(Fibonacci (- valor 2)))
  )))
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Serie de Fibonacci >>>
(printf "\n=== Serie de Fibonacci ====================\n\n")
(for ([i (in-range 0 10)])
  (printf "> Fibonacci para ~a: ~a\n" i (Fibonacci i)))
(printf "\n===========================================")