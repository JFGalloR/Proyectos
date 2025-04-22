ORG 0000H
	JMP PRINCIPAL

ORG 0003H
	JMP INT_0

;================================== PROGRAMA PRINCIPAL =======
PRINCIPAL:
	MOV IP, #0
	MOV IE, #10000001B

;-------------------------- Valores Iniciales ----------
	MOV R0, #0 ; Seg
	MOV R1, #0 ; U_Min
	MOV R2, #0 ; D_Min
	MOV R3, #1 ; U_Hor
	MOV R4, #0 ; D_Hor
	MOV B, #10

;------------------- Actualización de Salidas ----------
INICIO:
	CLR P3.0
	ACALL ACTUALIZAR

;------------------------------- Conteo Reloj ----------
CUENTA:
;<<<<<<<<<<<<<<< Conteo Segundos >>>>>>>>>>
	ACALL DELAY
	SETB P3.0
	ACALL DELAY
	INC R0
	MOV A, #60
	SUBB A, R0
	JNZ INICIO
	MOV R0, #0

;<<<<<<<<<<<<<<<< Conteo Minutos >>>>>>>>>>
	INC R1
	MOV A, #10
	SUBB A, R1
	JNZ INICIO
	MOV R1, #0

	INC R2
	MOV A, #6
	SUBB A, R2
	JNZ INICIO
	MOV R2, #0

;<<<<<<<<<<<<<< Conteo Horas >>>>>>>>>>
	INC R3
	MOV A, B
	SUBB A, R3
	JNZ INICIO
	MOV R3, #0

	INC R4
	MOV A, #2
	MOV B, #3
	SUBB A, R4
	JNZ INICIO
	MOV R3, #1
	MOV R4, #0
	MOV B, #10

	JMP INICIO

;======================================== INTERRUPCIÓN =======
INT_0:
	CLR P3.0
	MOV P0, #10001000B
	MOV P2, #10001000B
	ACALL PARPADEO
	ACALL ACTUALIZAR

;------------------------- Lectura de Botones ----------
MODIFICAR:
	JNB P3.3, HORAS
	JNB P3.4, MINUTOS
	JB P3.2, MODIFICAR
	ACALL PARPADEO

	MOV SP, #09

	RETI

;<<<<<<<<<<< Incrementar Horas >>>>>>>>>>
HORAS:
	INC R3
	MOV A, B
	SUBB A, R3
	JNZ FIN_H
	MOV R3, #0

	INC R4
	MOV A, #2
	MOV B, #3
	SUBB A, R4
	JNZ FIN_H
	MOV R3, #1
	MOV R4, #0
	MOV B, #10

FIN_H:	ACALL ACTUALIZAR

	MOV R7, #2
C3H: 	MOV R6, #140
C2H: 	MOV R5, #0FFH
C1H:	JB P3.3, MODIFICAR
	DJNZ R5, C1H
	DJNZ R6, C2H
	DJNZ R7, C3H

	JMP MODIFICAR

;<<<<<<<<< Incrementar Minutos >>>>>>>>>>
MINUTOS:
	INC R1
	MOV A, #10
	SUBB A, R1
	JNZ FIN_M
	MOV R1, #0

	INC R2
	MOV A, #6
	SUBB A, R2
	JNZ FIN_M
	MOV R2, #0

FIN_M:	ACALL ACTUALIZAR

	MOV R7, #2
C3M: 	MOV R6, #140
C2M: 	MOV R5, #0FFH
C1M:	JB P3.4, MODIFICAR
	DJNZ R5, C1M
	DJNZ R6, C2M
	DJNZ R7, C3M

	JMP MODIFICAR

;========================================== ACTUALIZAR =======
ACTUALIZAR:
;<<<<<<<<<<<< Actualizar Horas >>>>>>>>>>
	MOV A, R4
	RLC A
	RLC A
	RLC A
	RLC A
	ORL A, R3
	MOV P0, A

;<<<<<<<<<< Actualizar Minutos >>>>>>>>>>
	MOV A, R2
	RLC A
	RLC A
	RLC A
	RLC A
	ORL A, R1
	MOV P2, A
	RET

;=============================================== DELAY =======
DELAY:
	MOV R7, #3
C3: 	MOV R6, #0FFH
C2: 	MOV R5, #0FFH
C1: 	DJNZ R5, C1
	DJNZ R6, C2
	DJNZ R7, C3
	RET

;========================================= DELAY MEDIO =======
DELAY_P:
	MOV R7, #2
C3P: 	MOV R6, #140
C2P: 	MOV R5, #0FFH
C1P: 	DJNZ R5, C1P
	DJNZ R6, C2P
	DJNZ R7, C3P
	RET

;============================================ PARPADEO =======
PARPADEO:
	CLR P3.1
	ACALL DELAY_P
	SETB P3.1
	ACALL DELAY_P
	CLR P3.1
	ACALL DELAY_P
	SETB P3.1
	ACALL DELAY_P
	CLR P3.1
	ACALL DELAY_P
	SETB P3.1
	ACALL DELAY_P
	SETB P3.1
	RET
END
