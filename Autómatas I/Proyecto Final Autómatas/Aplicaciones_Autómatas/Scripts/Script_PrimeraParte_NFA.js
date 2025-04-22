/*===========================================================================
    Script Primer Sección Proyecto Final:
 << ACEPTADOR DE COORDENADAS CON AUTÓMATAS NFA >>>>>>>>>>>>>>>>>>>>>>>>>>>>
============================================================================
    Código encargado de tomar la cadena ingresada en el input, tanto para 
    las coordenadas de latitud (números de -90 a +90) como longitud (números 
    de -180 a +180), y por medio de una implementación de autómatas NFA 
    definir si la cadena es aceptada o no, para lozalizar el punto en mapa. 
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

//===========================================================================
// ::::::::::::::::::::::::::::::::::::::::::::::::: VARIABLES GLOBALES :::
//===========================================================================
var valLat = false
var valLon = false
var map = null

//___________________________________ Inicialización de eventos en inputs ___
//===========================================================================
document.addEventListener('DOMContentLoaded', initElements)

//===========================================================================
// :::::::::::::::::::::::::::::::::::::::::: FUNCIÓN DE INICIALIZACIÓN :::
//===========================================================================
function initElements() {
    let inputLat = document.querySelector('#Latitud')
    let inputLon = document.querySelector('#Longitud')
    let msgLat = document.querySelector('#ErrorLat')
    let msgLon = document.querySelector('#ErrorLon')
    let btn = document.querySelector('#Localizar')
    let mapa = document.querySelector('#Mapa')

    //___________________________________________ Inicialización deL mapa ___
    map = L.map(mapa).setView([0, 0], 5);

    L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
        attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
    }).addTo(map);

    //_______________________________________________ Evento de escritura ___
    inputLat.addEventListener('input', (e) => {
        let cadena =  e.target.value

        //__________________________ Validación de la cadena para latitud ___
        //________________________ En NFA recibe la cadena como parámetro ___
        if(aceptadorNFA_Latitud(cadena)) {
            inputLat.classList.remove('Invalido')
            msgLat.style.display = 'none';
            valLat = true
        }
        else {
            inputLat.classList.add('Invalido')
            msgLat.style.display = 'block';
            valLat = false
        }

        btn.disabled = !(valLat && valLon)
    })
    
    //_______________________________________________ Evento de escritura ___
    inputLon.addEventListener('input', (e) => {
        let cadena =  e.target.value

        //_________________________ Validación de la cadena para longitud ___
        //________________________ En NFA recibe la cadena como parámetro ___
        if(aceptadorNFA_Longitud(cadena)) {
            inputLon.classList.remove('Invalido')
            msgLon.style.display = 'none';
            valLon = true
        }
        else {
            inputLon.classList.add('Invalido')
            msgLon.style.display = 'block';
            valLon = false
        }

        btn.disabled = !(valLat && valLon)
    })
}

//===========================================================================
// :::::::::::::::::::::::::::::: FUNCIÓN PARA UBICACIÓN DE COORDENADAS :::
//===========================================================================
function localizarCoordenadas() {
    let inputLat = document.querySelector('#Latitud')
    let inputLon = document.querySelector('#Longitud')
    let initMap = document.querySelector('.InitMapa')
    let mapa = document.querySelector('#Mapa')
    let latitud = null;
    let longitud = null;

    initMap.style.display = 'none'
    mapa.style.display = 'block'

    latitud = parseFloat(inputLat.value);
    longitud = parseFloat(inputLon.value);

    map.invalidateSize();

    //______________________________________ Posicionamiento del marcador ___
    L.marker([latitud, longitud]).addTo(map)
        .bindPopup('Latitud: ' + inputLat.value + '° | Longitud: ' + inputLon.value + '°')
        .openPopup();
}

//===========================================================================
// :::::::::::::::: FUNCIÓN RAÍZ PARA VALIDACIÓN CON AUTÓMATA (LATITUD) :::
//===========================================================================
function aceptadorNFA_Latitud(cadena) {
    //_________________________________________________ Se comienza en q0 ___
    return q0_Lat(cadena)
}

//===========================================================================
// ::::::::::::::: FUNCIÓN RAÍZ PARA VALIDACIÓN CON AUTÓMATA (LONGITUD) :::
//===========================================================================
function aceptadorNFA_Longitud(cadena) {
    //_________________________________________________ Se comienza en q0 ___
    return q0_Lon(cadena)
}

//===========================================================================
// ::::::::::::::::::::::::: ESTADOS CORRESPONDIENTES AL NFA DE LATITUD :::
//===========================================================================
//____________________________________ Estado q0 para autómata de latitud ___
//===========================================================================
function q0_Lat(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = false
    let transicionLambda = false

    //_________________________________________________ Transición lambda ___
    transicionLambda = q1_Lat(cadena)

    //________________________________________________________ Transición ___
    if(/^[+-]$/.test(caracter)) {
        transicion = q1_Lat(nuevaCadena)
    }

    return transicion || transicionLambda
}
//____________________________________ Estado q1 para autómata de latitud ___
//===========================================================================
function q1_Lat(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion1 = false
    let transicion2 = false

    //_________________________________________________ Primer transición ___
    if(caracter === '0') {
        transicion1 = q1_Lat(nuevaCadena)
    }

    //________________________________________________ Segunda transición ___
    if(/^[0-8]$/.test(caracter)) {
        transicion2 = q2_Lat(nuevaCadena)
    }
    if(caracter === '9') {
        transicion2 = q6_Lat(nuevaCadena)
    }
    if(caracter === '.') {
        transicion2 = q5_Lat(nuevaCadena)
    }

    return transicion1 || transicion2
}
//____________________________________ Estado q2 para autómata de latitud ___
//===========================================================================
function q2_Lat(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = true

    //________________________________________________________ Transición ___
    if(cadena !== '') {
        transicion = false
    }
    if(/^[0-9]$/.test(caracter)) {
        transicion = q3_Lat(nuevaCadena)
    }
    if(caracter === '.') {
        transicion = q4_Lat(nuevaCadena)
    }
    
    return transicion
}
//____________________________________ Estado q3 para autómata de latitud ___
//===========================================================================
function q3_Lat(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = true

    //________________________________________________________ Transición ___
    if(cadena !== '') {
        transicion = false
    }
    if(caracter === '.') {
        transicion = q4_Lat(nuevaCadena)
    }

    return transicion
}
//____________________________________ Estado q4 para autómata de latitud ___
//===========================================================================
function q4_Lat(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = true

    //________________________________________________________ Transición ___
    if(cadena !== '') {
        transicion = false
    }
    if(/^[0-9]$/.test(caracter)) {
        transicion = q4_Lat(nuevaCadena)
    }

    return transicion
}
//____________________________________ Estado q5 para autómata de latitud ___
//===========================================================================
function q5_Lat(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = false

    //________________________________________________________ Transición ___
    if(/^[0-9]$/.test(caracter)) {
        transicion = q4_Lat(nuevaCadena)
    }

    return transicion
}
//____________________________________ Estado q6 para autómata de latitud ___
//===========================================================================
function q6_Lat(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = true

    //________________________________________________________ Transición ___
    if(cadena !== '') {
        transicion = false
    }
    if(caracter === '0') {
        transicion = q7_Lat(nuevaCadena)
    }
    if(caracter === '.') {
        transicion = q5_Lat(nuevaCadena)
    }

    return transicion
}
//____________________________________ Estado q7 para autómata de latitud ___
//===========================================================================
function q7_Lat(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = true

    //________________________________________________________ Transición ___
    if(cadena !== '') {
        transicion = false
    }
    if(caracter === '.') {
        transicion = q8_Lat(nuevaCadena)
    }

    return transicion
}
//____________________________________ Estado q8 para autómata de latitud ___
//===========================================================================
function q8_Lat(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = true

    //________________________________________________________ Transición ___
    if(cadena !== '') {
        transicion = false
    }
    if(caracter === '0') {
        transicion = q8_Lat(nuevaCadena)
    }

    return transicion
}

//===========================================================================
// :::::::::::::::::::::::: ESTADOS CORRESPONDIENTES AL NFA DE LONGITUD :::
//===========================================================================
//___________________________________ Estado q0 para autómata de longitud ___
//===========================================================================
function q0_Lon(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = false
    let transicionLambda = false

    //_________________________________________________ Transición lambda ___
    transicionLambda = q1_Lon(cadena)

    //________________________________________________________ Transición ___
    if(/^[+-]$/.test(caracter)) {
        transicion = q1_Lon(nuevaCadena)
    }

    return transicion || transicionLambda
}
//___________________________________ Estado q1 para autómata de longitud ___
//===========================================================================
function q1_Lon(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion1 = false
    let transicion2 = false

    //_________________________________________________ Primer transición ___
    if(caracter === '0') {
        transicion1 = q1_Lon(nuevaCadena)
    }
    if(caracter === '1') {
        transicion1 = q6_Lon(nuevaCadena)
    }

    //________________________________________________ Segunda transición ___
    if(/^[0-9]$/.test(caracter)) {
        transicion2 = q2_Lon(nuevaCadena)
    }
    if(caracter === '.') {
        transicion2 = q5_Lon(nuevaCadena)
    }

    return transicion1 || transicion2
}
//___________________________________ Estado q2 para autómata de longitud ___
//===========================================================================
function q2_Lon(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = true

    //________________________________________________________ Transición ___
    if(cadena !== '') {
        transicion = false
    }
    if(/^[0-9]$/.test(caracter)) {
        transicion = q3_Lon(nuevaCadena)
    }
    if(caracter === '.') {
        transicion = q4_Lon(nuevaCadena)
    }
    
    return transicion
}
//___________________________________ Estado q3 para autómata de longitud ___
//===========================================================================
function q3_Lon(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = true

    //________________________________________________________ Transición ___
    if(cadena !== '') {
        transicion = false
    }
    if(caracter === '.') {
        transicion = q4_Lon(nuevaCadena)
    }

    return transicion
}
//___________________________________ Estado q4 para autómata de longitud ___
//===========================================================================
function q4_Lon(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = true

    //________________________________________________________ Transición ___
    if(cadena !== '') {
        transicion = false
    }
    if(/^[0-9]$/.test(caracter)) {
        transicion = q4_Lon(nuevaCadena)
    }

    return transicion
}
//___________________________________ Estado q5 para autómata de longitud ___
//===========================================================================
function q5_Lon(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = false

    //________________________________________________________ Transición ___
    if(/^[0-9]$/.test(caracter)) {
        transicion = q4_Lon(nuevaCadena)
    }

    return transicion
}
//___________________________________ Estado q6 para autómata de longitud ___
//===========================================================================
function q6_Lon(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = false

    //________________________________________________________ Transición ___
    if(caracter === '8') {
        transicion = q7_Lon(nuevaCadena)
    }
    if(/^[0-7]$/.test(caracter)) {
        transicion = q2_Lon(nuevaCadena)
    }

    return transicion
}
//___________________________________ Estado q7 para autómata de longitud ___
//===========================================================================
function q7_Lon(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = false

    //________________________________________________________ Transición ___
    if(caracter === '0') {
        transicion = q8_Lon(nuevaCadena)
    }

    return transicion
}
//___________________________________ Estado q8 para autómata de longitud ___
//===========================================================================
function q8_Lon(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = true

    //________________________________________________________ Transición ___
    if(cadena !== '') {
        transicion = false
    }
    if(caracter === '.') {
        transicion = q9_Lon(nuevaCadena)
    }

    return transicion
}
//___________________________________ Estado q9 para autómata de longitud ___
//===========================================================================
function q9_Lon(cadena) {
    let caracter = cadena[0]
    let nuevaCadena = cadena.slice(1)
    let transicion = true

    //________________________________________________________ Transición ___
    if(cadena !== '') {
        transicion = false
    }
    if(caracter === '0') {
        transicion = q9_Lon(nuevaCadena)
    }

    return transicion
}