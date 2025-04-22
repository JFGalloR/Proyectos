;=========================== PUNTO DE INICIO ==============
INICIO:
	CLR C
	MOV A, P1
	MOV B, P3

;----- Suma -----------------------------------------
	ADD A, B
	JC MAYOR

	MOV P2, A

	JMP INICIO

;----- Código cuando la suma es mayor a 8 bits ------
MAYOR:
	MOV P2, #11111111B
	CALL DELAY
	MOV P2, #0
	CALL DELAY
	JMP INICIO

;=========================== CÓDIGO PARA DELAY 1 SEG. =====
DELAY:
	MOV R2, #0FFH
CICLO3:	MOV R1, #0FFH
CICLO2: MOV R0, #4
CICLO1: DJNZ R0, CICLO1
	DJNZ R1, CICLO2
	DJNZ R2, CICLO3
	RET
END

