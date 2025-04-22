//============================================================ Variables Globales ==========//
//=========================================================================================//
var datos = {};
var datosEval = {};
var orden;
var grado;
var modelo;
var grafica;
var ddf = [];
var pd = 6;

//====================================== Función para validar los datos a agregar ==========//
//=========================================================================================//
function ValidarAgr() {
    let x = document.getElementById('x_in').value;
    let y = document.getElementById('y_in').value;

    if(x == '' || y == '') {
        alert('⚠️ Ingresa correctamente los campos ⚠️');
    } else {
        if(datos[parseFloat(x)] == undefined) {
            AgregarDato(parseFloat(x), parseFloat(y));
            alert('✅ Dato agregado correctamente ✅');
            document.getElementById('x_in').value = '';
            document.getElementById('y_in').value = ''
        } else {
            alert('❌ Ya existe una abscisa asiganada ❌');
        }
    }
}

//=========================== Función para agregar al diccionario un par de datos ==========//
//=========================================================================================//

function AgregarDato(x, y) {
    datos[x] = y;
    orden = Object.keys(datos).sort((a, b) => parseFloat(a) - parseFloat(b));
    ActualizarTabla();
    VerificarConfig();
}

//========================= Función para eliminar del diccionario un par de datos ==========//
//=========================================================================================//
function EliminarDato(x) {
    delete datos[x];
    orden = Object.keys(datos).sort((a, b) => parseFloat(a) - parseFloat(b));
    ActualizarTabla();
    VerificarConfig();
}

//============= Función para actualizar la tabla que contiene los datos agregados ==========//
//=========================================================================================//
function ActualizarTabla() {
    let tabla = document.getElementById('TablaIn');
    tabla.querySelector('tbody').innerHTML = '';
    if(Object.keys(datos).length === 0) {
        tabla.querySelector('tbody').innerHTML += `
            <tr>
                <td>- - -</td>
                <td>- - -</td>
                <td>- - -</td>
                <td>- - -</td>
                <td>- - -</td>
            </tr>`;
    } else {
        let i = 0;
        for(let x in orden) {
            let xi = Number(parseFloat(orden[x]).toFixed(8)).toString();
            let yi = Number(parseFloat(datos[orden[x]]).toFixed(8)).toString();
            i++;
            tabla.querySelector('tbody').innerHTML += `
            <tr>
                <td> x<sub>` + i + `</sub> </td>
                <td>` + xi + `</td>
                <td> f(x<sub>` + i + `</sub>) </td>
                <td>` + yi + `</td>
                <td><div><button onclick="EliminarDato(` + xi + `)">x</button></div></td>
            </tr>`;
        }
    }
}

//========= Función para cambiar el campo del grado del polinomio según los datos ==========//
//=========================================================================================//
function VerificarConfig() {
    let select = document.getElementById('Grado');
    let cant = Object.keys(datos).length;
    
    select.innerHTML = "";

    if(cant < 2) {
        select.disabled = true;
    } else {
        for (let i = 1; i < cant; i++) {
            let option = document.createElement('option');
            option.value = i;
            option.textContent = i;
            select.appendChild(option);
        }
        select.selectedIndex = cant - 2;
        select.disabled = false;
    }
}

//=============== Función para validar que haya suficientes datos para interpolar ==========//
//=========================================================================================//
function ValidarCalc() {
    let cant = Object.keys(datos).length;
    
    if(cant < 2) {
        alert('❌ No hay suficientes datos para calcular ❌');
    } else {
        let newt = document.getElementById('MetNew').checked;
        grado = parseInt(document.getElementById('Grado').value);
        modelo = (newt==true)? 'Newton' : 'Lagrange';
        CalcularPolinomio();
    }
}

//================================= Función para calcular el polinomio respectivo ==========//
//=========================================================================================//
function CalcularPolinomio() {
    let cont = document.querySelector('.Inter');
    let tit = document.querySelector('.TitInt');
    let tab = document.querySelector('.TablaOut');
    let gra = document.querySelector('.Grafica');

    document.getElementById('Contenedor').style.display = 'block';
    document.getElementById('Modelo').innerHTML = modelo;

    switch (modelo) {
        case 'Newton':
            tit.classList.remove('Lagrange');
            tab.querySelector('h3').classList.remove('Lagrange');
            gra.querySelector('h3').classList.remove('Lagrange');
            cont.classList.remove('ContLag');
            tab.classList.remove('ContLag');
            gra.classList.remove('ContLag');
            tit.classList.add('Newton');
            tab.querySelector('h3').classList.add('Newton');
            gra.querySelector('h3').classList.add('Newton');
            cont.classList.add('ContNew');
            tab.classList.add('ContNew');
            gra.classList.add('ContNew');
            em = '🔴';
            PolNewton();
            break;
        case 'Lagrange':
            tit.classList.remove('Newton');
            tab.querySelector('h3').classList.remove('Newton');
            gra.querySelector('h3').classList.remove('Newton');
            cont.classList.remove('ContNew');
            tab.classList.remove('ContNew');
            gra.classList.remove('ContNew');
            tit.classList.add('Lagrange');
            tab.querySelector('h3').classList.add('Lagrange');
            gra.querySelector('h3').classList.add('Lagrange');
            cont.classList.add('ContLag');
            tab.classList.add('ContLag');
            gra.classList.add('ContLag');
            em = '🔵';
            PolLagrange();
            break;
    }
    datosEval = {};
    ActualizarTablaAgr();
    SetGrafica();
    alert(em + ' Interpolación de ' + modelo + ' obtenida ' + em);
}

//============================================= Función para construir la gráfica ==========//
//=========================================================================================//
function SetGrafica() {
    let ctx = document.getElementById('GraficaInt');
    let color = (modelo=='Newton')? '#5d1717':'#171f5d';

    let dataSetInt = [];
    let dataSetSob = [];

    for (let i = 0; i <= grado; i++) {
        dataSetInt.push({ x: orden[i], y: datos[orden[i]] });
    }

    let data = {
        datasets: [
            {
                label: 'Interpolación Grado ' + grado.toString(),
                data: dataSetInt,
                borderColor: color,
                backgroundColor: color,
                showLine: true,
                pointRadius: 5,
                pointHoverRadius: 7,
                fill: false,
                tension: 0.4
            }
        ]
    };

    if(grado < orden.length - 1) {
        for (let i = grado + 1; i < orden.length; i++) {
            dataSetSob.push({ x: orden[i], y: datos[orden[i]] });
        }
        data.datasets.push(
            {
                label: 'Puntos sobrantes',
                data: dataSetSob,
                borderColor: color,
                pointRadius: 5,
                pointHoverRadius: 7,
                fill: false
            }
        );
    }

    let config = {
        type: 'scatter',
        data: data,
        options: {
            responsive: true,
            plugins: {
                title: {
                    display: true,
                    text: 'Interpolación de ' + modelo,
                    font: {
                        size: 18
                    }
                }
            },
            interaction: {
                intersect: false
            },
            scales: {
                x: {
                    display: true,
                    title: {
                        display: true,
                        text: 'xi',
                        font: {
                            size: 14
                        }
                    }
                },
                y: {
                    display: true,
                    title: {
                        display: true,
                        text: 'f(xi)',
                        font: {
                            size: 14
                        }
                    }
                }
            }
        }
    };

    if (typeof grafica !== 'undefined' && grafica !== 0) {
        grafica.destroy();
    }

    grafica = new Chart(ctx, config);
}

//================= Función para calcular el polinomio de interpolación de Newton ==========//
//=========================================================================================//
function PolNewton() {
    let a = 0;
    let pol = '';
    ddf = [];

    for(x in orden) {
        ddf[x] = new Array(grado + 2);
        ddf[x][0] = parseFloat(orden[x]);
        ddf[x][1] = parseFloat(datos[orden[x]]);
    }

    for (let i = 2; i < grado + 2; i++) {
        for (let j = 0; j < grado - a; j++) {
            ddf[j][i] = (ddf[j+1][i-1] - ddf[j][i-1])/(ddf[i+j-1][0] - ddf[j][0]);
        }
        a++;
    }

    for (let i = 0; i <= grado; i++) {
        if(i>0)
            pol += (ddf[0][i+1] < 0)? '' : '+';

        pol += Number(ddf[0][i+1].toFixed(pd)).toString()

        for (let j = 0; j < i; j++) {
            pol += '<span>(x' + 
            (ddf[j][0] < 0 ? 
                ('+' + Number((ddf[j][0] * -1).toFixed(pd)).toString()) : 
                ('-' + Number(ddf[j][0].toFixed(pd)).toString())) 
            + ')</span>';
        }
    }

    console.table(ddf);

    document.getElementById('GPol').innerHTML = grado.toString();
    document.getElementById('Pol').innerHTML = pol;
}

//=============== Función para calcular el polinomio de interpolación de Lagrange ==========//
//=========================================================================================//
function PolLagrange() {
    let pol = '';
    ddf = [];

    for(let i = 0; i <= grado; i++) {
        let xi = parseFloat(orden[i]);
        let yi = parseFloat(datos[orden[i]]);

        if(i!=0)
            pol += '+';

        for(let j = 0; j <= grado; j++) {
            if(j != i) {
                let x = parseFloat(orden[j]);
                let xj = (x<0)? ('+' + Number((x*-1).toFixed(pd)).toString()) : ('-' + Number(x.toFixed(pd)).toString());
                pol += '<span>(<span class="Div"><div>x' + xj + '</div><div>' 
                + Number(xi.toFixed(pd)).toString() + xj +'</div></span>)</span>';
            }
        }
        pol += '(' + Number(yi.toFixed(pd)).toString() +')';
    }

    document.getElementById('GPol').innerHTML = grado.toString();
    document.getElementById('Pol').innerHTML = pol;
}

//============================== Función para calcular la interpolación de Newton ==========//
//=========================================================================================//
function IntNewton(x) {
    let valor = 0;
    for (let i = 0; i <= grado; i++) {
        let prod = ddf[0][i+1];
        
        for (let j = 0; j < i; j++) {
            prod *= x-ddf[j][0];
        }
        valor += prod;
    }
    return valor;
}

//============================ Función para calcular la interpolación de Lagrange ==========//
//=========================================================================================//
function IntLagrange(x) {
    let valor = 0;
    for(let i = 0; i <= grado; i++) {
        let xi = parseFloat(orden[i]);
        let yi = parseFloat(datos[orden[i]]);
        let prod = yi;
        for(let j = 0; j <= grado; j++) {
            if(j != i) {
                let xj = parseFloat(orden[j]);
                prod *= (x - xj) / (xi - xj);
            }
        }
        valor += prod;
    }
    return valor;
}

//============================ Función para validar la entrada de datos a evaluar ==========//
//=========================================================================================//
function ValidarAgrEval() {
    let x = document.getElementById('x_ev').value;

    if(x == '') {
        alert('⚠️ Ingresa correctamente el campo ⚠️');
    } else {
        if(datosEval[parseFloat(x)] == undefined) {
            AgregarDatoEval(parseFloat(x));
            alert('✅ Dato evaluado correctamente ✅');
            document.getElementById('x_ev').value = '';
        } else {
            alert('❌ Ya existe esa abscisa evaluada ❌');
        }
    }
}

//======================================== Función para agregar un dato a evaluar ==========//
//=========================================================================================//
function AgregarDatoEval(x) {
    datosEval[x] = (modelo=='Newton')? IntNewton(x): IntLagrange(x);
    ActualizarTablaAgr();
    ActualizarGrafica();
}

//====================================== Función para eliminar un dato a evaluado ==========//
//=========================================================================================//
function EliminarDatoEval(x) {
    delete datosEval[x];
    ActualizarTablaAgr();
    ActualizarGrafica();
}

//=========================== Función para actualizar la tabla de datos evaluados ==========//
//=========================================================================================//
function ActualizarTablaAgr() {
    let tabla = document.getElementById('TablaEv');
    let ordenEval = Object.keys(datosEval).sort((a, b) => parseFloat(a) - parseFloat(b));
    tabla.querySelector('tbody').innerHTML = '';
    if(Object.keys(datosEval).length === 0) {
        tabla.querySelector('tbody').innerHTML += `
            <tr>
                <td>- - -</td>
                <td>- - -</td>
                <td>- - -</td>
                <td>- - -</td>
                <td>- - -</td>
            </tr>`;
    } else {
        let i = 0;
        for(let x in ordenEval) {
            let xi = Number(parseFloat(ordenEval[x]).toFixed(8)).toString();
            let yi = Number(parseFloat(datosEval[ordenEval[x]]).toFixed(8)).toString();
            i++;
            tabla.querySelector('tbody').innerHTML += `
            <tr>
                <td> x<sub>` + i + `</sub> </td>
                <td>` + xi + `</td>
                <td> f(x<sub>` + i + `</sub>) </td>
                <td>` + yi + `</td>
                <td><div><button onclick="EliminarDatoEval(` + xi + `)">x</button></div></td>
            </tr>`;
        }
    }
}

//========================= Función para actualizar la gráfica de datos evaluados ==========//
//=========================================================================================//
function ActualizarGrafica() {
    if(Object.keys(datosEval).length == 0) {
        SetGrafica();
    } else {
        let dataSetEval = [];
        for (let dato in datosEval) {
            dataSetEval.push({ x: parseFloat(dato), y: datosEval[dato] });
        }
        if(grafica.data.datasets[grafica.data.datasets.length - 1].label == 'Puntos evaluados') {
            grafica.data.datasets[grafica.data.datasets.length - 1] = 
                {
                    label: 'Puntos evaluados',
                    data: dataSetEval,
                    borderColor: '#000000',
                    pointRadius: 5,
                    pointHoverRadius: 7,
                    fill: true
                };
        } else {
            grafica.data.datasets.push(
                {
                    label: 'Puntos evaluados',
                    data: dataSetEval,
                    borderColor: '#000000',
                    pointRadius: 5,
                    pointHoverRadius: 7,
                    fill: true
                }
            );
        }
    }
    grafica.update();
}