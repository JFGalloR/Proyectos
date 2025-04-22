;=========================== PUNTO DE INICIO ==============
INICIO:
	CLR C
	MOV A, P1
	MOV B, P3

	SUBB A, B

	JZ IGUAL

	JNC MAYOR_P1
	JC MAYOR_P3

;-------- Código cuando son iguales ------
IGUAL:
	MOV P2, #11111111B
	CALL DELAY
	MOV P2, #0
	CALL DELAY
	JMP INICIO

;-------- Código cuando P1 es mayor ------
MAYOR_P1:
	MOV P2, P1
	JMP INICIO

;-------- Código cuando P3 es mayor ------
MAYOR_P3:
	MOV P2, P3
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
