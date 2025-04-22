#lang racket
;==================================== CONVERSIÓN DE BASE =====
;------------------------------------------------------------
;>>>>>>>>>>>>>>>>>>>>>>>>>>>> Función de cambio de base >>>
(define (Convertir_Base n b)
  (if (< n b)
      (list n) 
      (append (Convertir_Base (quotient n b) b)
              (list (remainder n b)))))

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Función Decimal-Binario >>>
(define (Base_Decimal_Binario n)
  (Convertir_Base n 2))

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Función Decimal-Octal >>>
(define (Base_Decimal_Octal n)
  (Convertir_Base n 8))

;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Ejemplos de conversión >>>
(printf "\n=== Conversión de Decimal a Binario ========\n\n")
(display ">> 15  base 10 a base 2:\t") (Base_Decimal_Binario 15)
(display ">> 893 base 10 a base 2:\t") (Base_Decimal_Binario 893)
(display ">> 135 base 10 a base 2:\t") (Base_Decimal_Binario 135)
(display ">> 41  base 10 a base 2:\t") (Base_Decimal_Binario 41)
(display ">> 473 base 10 a base 2:\t") (Base_Decimal_Binario 473)
(printf "\n=== Conversión de Decimal a Octal   ========\n\n")
(display ">> 15  base 10 a base 8:\t") (Base_Decimal_Octal 15)
(display ">> 893 base 10 a base 8:\t") (Base_Decimal_Octal 893)
(display ">> 135 base 10 a base 8:\t") (Base_Decimal_Octal 135)
(display ">> 41  base 10 a base 8:\t") (Base_Decimal_Octal 41)
(display ">> 473 base 10 a base 8:\t") (Base_Decimal_Octal 473)
(printf "\n===========================================")
