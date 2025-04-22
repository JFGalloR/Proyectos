'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    EJERCICIOS A21.
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
def suma1(num1, num2):
    print(num1 + num2)

def suma2(num1, num2):
    resultado = num1 + num2
    return resultado

def cambia(num):
    num += 1
    return num

print("\n*** Ejercicios A21: ********************\n")
print(">>> Funcion suma.")
suma1(5, 7)
print(">>> Funcion suma (return).")
print(suma2(5, 7))
print(">>> Funcion cambio valores.")
a, b = 3, 4
print(f"Valor de variables (inicio): a = {a} b = {b}")
a = cambia(a)
print(f"Valor de variables (cambio a \"a\"): a = {a} b = {b}")
b = cambia(b)
print(f"Valor de variables (cambio a \"b\"): a = {a} b = {b}")

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    EJERCICIOS A22.
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
def multiplica(num1, num2, num3):
    return num1 * num2 * num3

print("\n*** Ejercicios A22: ********************\n")
print(">>> Funcion multiplicacion.")
print(multiplica(1, 2, 3))
lista = ["Juan", "Francisco", "Pablo", "Diego", "Alejandro"]
print(">>> Lista y porcion de lista.")
print(lista)
print(lista[1:4])

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    EJERCICIOS A23.
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
print("\n*** Ejercicios A23: ********************\n")

print(">>> Append.")
lista.append("Miguel")
print(lista)
print(">>> Insert.")
lista.insert(2, "Gallo")
print(lista)
print(">>> Extend.")
lista.extend(["Pedro", "Luis", "Manuel"])
print(lista)
print(">>> Index.")
print(lista.index("Gallo"))
print(">>> In.")
print("Pablo" in lista)