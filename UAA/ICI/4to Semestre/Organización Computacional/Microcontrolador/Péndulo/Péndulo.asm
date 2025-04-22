;=========================== PUNTO DE INICIO ==============
INICIO:
	MOV A, #10000000B
	MOV P2, A
	MOV R4, #7
;-------------- Recorrida a derecha ------
DERECHA:
	CALL DELAY
	RR A
	MOV P2, A
	DJNZ R4, DERECHA

	MOV R4, #7
;-------------- Recorrida a izquierda ----
IZQUIERDA:
	CALL DELAY
	RL A
	MOV P2, A
	DJNZ R4, IZQUIERDA

	JMP INICIO
;=========================== CÓDIGO PARA DELAY 1 SEG. =====
DELAY:
	MOV R2, #0FFH
CICLO3:	MOV R1, #0FFH
CICLO2: MOV R0, #8
CICLO1: DJNZ R0, CICLO1
	DJNZ R1, CICLO2
	DJNZ R2, CICLO3
	RET
END