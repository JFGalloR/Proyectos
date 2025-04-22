/*===========================================================================
    Script Segunda Sección Proyecto Final:
 << ACEPTADOR DE EXORESIÓNES ARITMÉTICAS CON AUTÓMATAS NPDA >>>>>>>>>>>>>>>
============================================================================
    Código encargado de tomar la cadena ingresada en el input, para ser 
    procesada por un autómata NPDA y determinar si es aceptada o no, para 
    después calcular el resultado de la misma. 
----------------------------------------------------------------------------
    • Asignatura:
      Autómatas I
    • Profesor:
      Israel de la Parra González
    • Alumno:
      Juan Francisco Gallo Ramírez
============================================================================
    I.C.I. 5to Semestre.
    Diciembre 2024.
=============================================================================*/

//___________________________________ Inicialización de eventos en inputs ___
//===========================================================================
document.addEventListener('DOMContentLoaded', initElements)

//===========================================================================
// :::::::::::::::::::::::::::::::::::::::::: FUNCIÓN DE INICIALIZACIÓN :::
//===========================================================================
function initElements() {
    let input = document.querySelector('#Expresion')

    //_______________________________________________ Evento de escritura ___
    input.addEventListener('input', (e) => {
        let cadena = e.target.value
        let contInput = document.querySelector('.Input')
        let contRes = document.querySelector('#Resultado')
        let resultado = document.querySelector('#Valor')
        let msg = document.querySelector('#Error')

        //__________________________ Validación de la cadena para latitud ___
        //_ En NPDA recibe cadena como parámetro y la pila inicia con 'Z' ___
        if(aceptadorNPDA(cadena, ['Z'])) {
            //___________________________________ Evaluación de expresión ___
            let valor = math.evaluate(cadena.replace(/[\[{]/g, '(').replace(/[\]}]/g, ')'))
            
            contInput.classList.remove('Invalido')
            contRes.style.display = 'block';
            resultado.textContent = Number(valor.toFixed(6)).toLocaleString('en-US');
            console.log(typeof valor)
            math.evaluate(cadena.replace(/[\[{]/g, '(').replace(/[\]}]/g, ')'))
            msg.style.display = 'none';
        }
        else {
            contInput.classList.add('Invalido')
            contRes.style.display = 'none';
            resultado.textContent = ''
            msg.style.display = 'block';
        }

    })
}

//===========================================================================
// :::::::::::::::::::::::::: FUNCIÓN RAÍZ PARA VALIDACIÓN CON AUTÓMATA :::
//===========================================================================
function aceptadorNPDA(cadena, pila) {
    //_________________________________________________ Se comienza en q0 ___
    return q0(cadena, [...pila])
}

//===========================================================================
// ::::::::::::::::::::::::::::::::::: ESTADOS CORRESPONDIENTES AL NPDA :::
//===========================================================================
//_______________________________________________ Estado q0 para autómata ___
//===========================================================================
function q0(cadena, pila) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let topePila = pila.pop()
    let transicion = false

    //________________________________________________________ Transición ___
    if(/^[0-9]$/.test(caracter) && topePila === 'Z') {
        transicion = q1(nuevaCadena, [...pila].concat('Z', 'E'))
    }
    if(caracter === '.' && topePila === 'Z') {
        transicion = q1(nuevaCadena, [...pila].concat('Z', 'P'))
    }
    if(/^[+-]$/.test(caracter) && topePila === 'Z') {
        transicion = q1(nuevaCadena, [...pila].concat('Z', 'S'))
    }
    if(caracter === '(' && topePila === 'Z') {
        transicion = q1(nuevaCadena, [...pila].concat('Z', '('))
    }
    if(caracter === '[' && topePila === 'Z') {
        transicion = q1(nuevaCadena, [...pila].concat('Z', '['))
    }
    if(caracter === '{' && topePila === 'Z') {
        transicion = q1(nuevaCadena, [...pila].concat('Z', '{'))
    }

    return transicion
}
//_______________________________________________ Estado q1 para autómata ___
//===========================================================================
function q1(cadena, pila) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let topePila = pila.pop()
    let transicion = false
    let transicionLambda = false

    //_________________________________________________ Transición lambda ___
    if(/^[ED]$/.test(topePila)) {
        transicionLambda = q2(cadena, [...pila])
    }

    //________________________________________________________ Transición ___
    if(/^[0-9]$/.test(caracter)) {
        if(topePila === 'E') {
            transicion = q1(nuevaCadena, [...pila].concat('E'))
        }
        if(topePila === 'P') {
            transicion = q1(nuevaCadena, [...pila].concat('D'))
        }
        if(topePila === 'Q') {
            transicion = q1(nuevaCadena, [...pila].concat('D'))
        }
        if(topePila === 'D') {
            transicion = q1(nuevaCadena, [...pila].concat('D'))
        }
        if(topePila === 'S') {
            transicion = q1(nuevaCadena, [...pila].concat('E'))
        }
        if(topePila === 'O') {
            transicion = q1(nuevaCadena, [...pila].concat('E'))
        }
        if(topePila === '(') {
            transicion = q1(nuevaCadena, [...pila].concat('(', 'E'))
        }
        if(topePila === '[') {
            transicion = q1(nuevaCadena, [...pila].concat('[', 'E'))
        }
        if(topePila === '{') {
            transicion = q1(nuevaCadena, [...pila].concat('{', 'E'))
        }
    }
    if(caracter === '.') {
        if(topePila === 'E') {
            transicion = q1(nuevaCadena, [...pila].concat('Q'))
        }
        if(topePila === 'S') {
            transicion = q1(nuevaCadena, [...pila].concat('P'))
        }
        if(topePila === 'O') {
            transicion = q1(nuevaCadena, [...pila].concat('P'))
        }
        if(topePila === '(') {
            transicion = q1(nuevaCadena, [...pila].concat('(', 'P'))
        }
        if(topePila === '[') {
            transicion = q1(nuevaCadena, [...pila].concat('[', 'P'))
        }
        if(topePila === '{') {
            transicion = q1(nuevaCadena, [...pila].concat('{', 'P'))
        }
    }
    if(/^[+-]$/.test(caracter)) {
        if(topePila === 'E') {
            transicion = q1(nuevaCadena, [...pila].concat('S'))
        }
        if(topePila === 'D') {
            transicion = q1(nuevaCadena, [...pila].concat('S'))
        }
        if(topePila === 'S') {
            transicion = q1(nuevaCadena, [...pila].concat('S'))
        }
        if(topePila === 'O') {
            transicion = q1(nuevaCadena, [...pila].concat('S'))
        }
        if(topePila === '(') {
            transicion = q1(nuevaCadena, [...pila].concat('(', 'S'))
        }
        if(topePila === '[') {
            transicion = q1(nuevaCadena, [...pila].concat('[', 'S'))
        }
        if(topePila === '{') {
            transicion = q1(nuevaCadena, [...pila].concat('{', 'S'))
        }
    }
    if(/^[*/÷^√]$/.test(caracter)) {
        if(topePila === 'E') {
            transicion = q1(nuevaCadena, [...pila].concat('O'))
        }
        if(topePila === 'D') {
            transicion = q1(nuevaCadena, [...pila].concat('O'))
        }
    }
    if(caracter === '(') {
        if(topePila === 'E') {
            transicion = q1(nuevaCadena, [...pila].concat('('))
        }
        if(topePila === 'D') {
            transicion = q1(nuevaCadena, [...pila].concat('('))
        }
        if(topePila === 'S') {
            transicion = q1(nuevaCadena, [...pila].concat('('))
        }
        if(topePila === 'O') {
            transicion = q1(nuevaCadena, [...pila].concat('('))
        }
        if(topePila === '(') {
            transicion = q1(nuevaCadena, [...pila].concat('(', '('))
        }
        if(topePila === '[') {
            transicion = q1(nuevaCadena, [...pila].concat('[', '('))
        }
        if(topePila === '{') {
            transicion = q1(nuevaCadena, [...pila].concat('{', '('))
        }
    }
    if(caracter === '[') {
        if(topePila === 'E') {
            transicion = q1(nuevaCadena, [...pila].concat('['))
        }
        if(topePila === 'D') {
            transicion = q1(nuevaCadena, [...pila].concat('['))
        }
        if(topePila === 'S') {
            transicion = q1(nuevaCadena, [...pila].concat('['))
        }
        if(topePila === 'O') {
            transicion = q1(nuevaCadena, [...pila].concat('['))
        }
        if(topePila === '(') {
            transicion = q1(nuevaCadena, [...pila].concat('(', '['))
        }
        if(topePila === '[') {
            transicion = q1(nuevaCadena, [...pila].concat('[', '['))
        }
        if(topePila === '{') {
            transicion = q1(nuevaCadena, [...pila].concat('{', '['))
        }
    }
    if(caracter === '{') {
        if(topePila === 'E') {
            transicion = q1(nuevaCadena, [...pila].concat('{'))
        }
        if(topePila === 'D') {
            transicion = q1(nuevaCadena, [...pila].concat('{'))
        }
        if(topePila === 'S') {
            transicion = q1(nuevaCadena, [...pila].concat('{'))
        }
        if(topePila === 'O') {
            transicion = q1(nuevaCadena, [...pila].concat('{'))
        }
        if(topePila === '(') {
            transicion = q1(nuevaCadena, [...pila].concat('(', '{'))
        }
        if(topePila === '[') {
            transicion = q1(nuevaCadena, [...pila].concat('[', '{'))
        }
        if(topePila === '{') {
            transicion = q1(nuevaCadena, [...pila].concat('{', '{'))
        }
    }
    if(caracter === ')' && /^[ED]$/.test(topePila)) {
        transicion = q3(nuevaCadena, [...pila])
    }
    if(caracter === ']' && /^[ED]$/.test(topePila)) {
        transicion = q4(nuevaCadena, [...pila])
    }
    if(caracter === '}' && /^[ED]$/.test(topePila)) {
        transicion = q5(nuevaCadena, [...pila])
    }

    return transicion || transicionLambda
}
//_______________________________________________ Estado q2 para autómata ___
//===========================================================================
function q2(cadena, pila) {
    let topePila = pila.pop()
    let transicion = false
    let transicionLambda = false

    //_________________________________________________ Transición lambda ___
    if(topePila === 'Z') {
        transicionLambda = q7(cadena, [...pila])
    }

    return transicion || transicionLambda
}
//_______________________________________________ Estado q3 para autómata ___
//===========================================================================
function q3(cadena, pila) {
    let topePila = pila.pop()
    let transicion = false
    let transicionLambda = false

    //_________________________________________________ Transición lambda ___
    if(topePila === '(') {
        transicionLambda = q6(cadena, [...pila])
    }

    return transicion || transicionLambda
}
//_______________________________________________ Estado q4 para autómata ___
//===========================================================================
function q4(cadena, pila) {
    let topePila = pila.pop()
    let transicion = false
    let transicionLambda = false

    //_________________________________________________ Transición lambda ___
    if(topePila === '[') {
        transicionLambda = q6(cadena, [...pila])
    }

    return transicion || transicionLambda
}
//_______________________________________________ Estado q5 para autómata ___
//===========================================================================
function q5(cadena, pila) {
    let topePila = pila.pop()
    let transicion = false
    let transicionLambda = false

    //_________________________________________________ Transición lambda ___
    if(topePila === '{') {
        transicionLambda = q6(cadena, [...pila])
    }

    return transicion || transicionLambda
}
//_______________________________________________ Estado q6 para autómata ___
//===========================================================================
function q6(cadena, pila) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let topePila = pila.pop()
    let transicion = false
    let transicionLambda1 = false
    let transicionLambda2 = false

    //___________________________________________ Transición lambda 1 y 2 ___
    if(topePila === 'Z') {
        transicionLambda1 = q1(cadena, [...pila].concat('Z', 'E'))
        transicionLambda2 = q7(cadena, [...pila])
    }

    //_______________________________________________ Transición lambda 1 ___
    if(topePila === '(') {
        transicionLambda1 = q1(cadena, [...pila].concat('Z', '('))
    }
    if(topePila === '[') {
        transicionLambda1 = q1(cadena, [...pila].concat('Z', '['))
    }
    if(topePila === '{') {
        transicionLambda1 = q1(cadena, [...pila].concat('Z', '{'))
    }

    //________________________________________________________ Transición ___
    if(caracter === ')' && topePila === '(') {
        transicion = q6(nuevaCadena, [...pila])
    }
    if(caracter === ']' && topePila === '[') {
        transicion = q6(nuevaCadena, [...pila])
    }
    if(caracter === '}' && topePila === '{') {
        transicion = q6(nuevaCadena, [...pila])
    }


    return transicion || transicionLambda1 || transicionLambda2
}
//_______________________________________________ Estado q7 para autómata ___
//===========================================================================
function q7(cadena, pila) {
    let transicion = true

    //________________________________________________________ Transición ___
    if(cadena !== '') {
        transicion = false
    }

    return transicion
}


