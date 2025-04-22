#lang racket
;================================== MÁXIMO COMÚN DIVISOR =====
;------------------------------------------------------------
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Función >>>
(define (MCD a b)
  (let loop ()
    (if (= b 0)
        a
        (begin
          (let ([temp b])
            (set! b (remainder a b))
            (set! a temp))
          (loop)))))

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Ejemplos de MCD >>>
(printf "\n=== Máximo Común Divisor (MCD) ========\n\n")
(display ">> MCD de 24 y 18:\t")  (MCD 24 18)
(display ">> MCD de 48 y 18:\t")  (MCD 48 18)
(display ">> MCD de 101 y 10:\t") (MCD 101 10)
(display ">> MCD de 56 y 98:\t")  (MCD 56 98)
(display ">> MCD de 100 y 25:\t") (MCD 100 25)
(display ">> MCD de 270 y 192:\t")(MCD 270 192)
(display ">> MCD de 49 y 7:\t")   (MCD 49 7)
(display ">> MCD de 81 y 27:\t")  (MCD 81 27)
(printf "\n===========================================")
