const reqDisp = 12;
const reqUsab = 6;

document.addEventListener('DOMContentLoaded', (event) => {
    const form = document.getElementById('Form');
    const mapa = document.getElementById('BMapa');
    form.addEventListener('submit', function(event) {
        event.preventDefault();
        PrepararMapa();
        GenerarMapa();
        form.reset();
        form.scrollIntoView({ behavior: 'auto', block: 'start' });
        MostrarOcultarCuestionario();
        MostrarMapa();
        mapa.scrollIntoView({ behavior: 'smooth', block: 'start' });
    });
    AjustarMedidor();
    HoverTacticas();
});


function AjustarMedidor() {
    const inputs = document.querySelectorAll('input');

    for (const input of inputs) {
        input.addEventListener('change', (event) => {
            const form = document.getElementById('Form');
            const inputs = form.elements;
            let med = 0;
            let enf = '';
            let color = '';
            let pct = 0;
            let totD = 0;
            let totU = 0;
            let tot = 0;

            for (const input of inputs) {
                if (input.tagName === 'INPUT' && input.checked) {
                    tot++;
                    if(input.classList.contains('OpcDisp')) {
                        totD++;
                        med += parseFloat(parseInt(input.value) * 50 / (reqDisp * 5));
                    } 
                    else if(input.classList.contains('OpcUsab')) {
                        totU++;
                        med -= parseFloat(parseInt(input.value) * 50 / (reqUsab * 5));
                    }
                }
            }

            pct = Number((med * 2).toFixed(2));

            if(pct > 0) {
                enf = 'Disponibilidad';
                color = '#ce1a41';
            }
            else if(pct < 0) {
                enf = 'Usabilidad';
                color = '#3114b2';
            }
            else {
                enf = 'Neutro';
                color = '#000000';
            }

            document.getElementById('Bar').style.transform = 'translateX(' + med + '%)';
            document.getElementById('Enf').innerHTML = enf;
            document.getElementById('Enf').style.color = color;
            document.getElementById('PctEnf').innerHTML = '(' + Math.abs(pct) + '%)';
            document.getElementById('PDisp').innerHTML = totD + '/12';
            document.getElementById('PUsab').innerHTML = totU + '/6';
            document.getElementById('PTot').innerHTML = tot + '/19';

        });
    }
}

function HoverTacticas() {
    const tacticas = document.querySelectorAll('.Tac');
    tacticas.forEach( tac => {
        tac.addEventListener('mouseenter', function() {
            document.querySelector('.DescTactica h1').innerHTML = ObtenerTactica(tac.id);
            document.querySelector('.DescTactica p').innerHTML = ObtenerDescTactica(tac.id);
        });
    });
}

function MostrarOcultarCuestionario() {
    const form = document.getElementById('Cuestionario');
    form.style.display = (form.style.display == 'flex')? 'none' : 'flex';
}

function MostrarMapa() {
    const mapa = document.getElementById('BMapa');
    mapa.style.display = 'flex';
}

function PrepararMapa() {
    const tacticas = document.querySelectorAll('.Tac');
    tacticas.forEach( tac => {
        tac.style.display = 'none';
    });
    document.querySelector('.DescTactica h1').innerHTML = '';
    document.querySelector('.DescTactica p').innerHTML = '';
}

function GenerarMapa() {
    let maxDisp = 0;
    let maxUsab = 0;

    const enfoque = document.querySelector('input[name="Enfoque"]:checked').value;
    const desc = document.querySelector('h1.Descripcion');
    let opcD;
    let opcU;


    switch(parseInt(enfoque)) {
        case 1:
            maxDisp = 9;
            maxUsab = 2;
            desc.innerHTML = "El enfoque elegido fue uno orientado a Disponibilidad.";
            break;
        case 2:
            maxDisp = 6;
            maxUsab = 3;
            desc.innerHTML = "El enfoque elegido fue uno orientado al balance del Trade-off.";
            break;
        case 3:
            maxDisp = 3;
            maxUsab = 5;
            desc.innerHTML = "El enfoque elegido fue uno orientado a Usabilidad.";
            break;
    }

    opcD = document.querySelectorAll('input:checked.OpcDisp[value="5"]');
    for(let i = 0; i < opcD.length; i++) {
        const input = opcD[i];
        document.getElementById(input.name).style.display = 'flex';
        maxDisp--;
        if(maxDisp == 0) {
            break;
        }
    }
    if(maxDisp > 0) {
        opcD = document.querySelectorAll('input:checked.OpcDisp[value="3"]');
        for(let i = 0; i < opcD.length; i++) {
            const input = opcD[i];
            document.getElementById(input.name).style.display = 'flex';
            maxDisp--;
            if(maxDisp == 0) {
                break;
            }
        }
    }
    if(maxDisp > 0) {
        opcD = document.querySelectorAll('input:checked.OpcDisp[value="1"]');
        for(let i = 0; i < opcD.length; i++) {
            const input = opcD[i];
            document.getElementById(input.name).style.display = 'flex';
            maxDisp--;
            if(maxDisp == 0) {
                break;
            }
        }
    }

    opcU = document.querySelectorAll('input:checked.OpcUsab[value="5"]');
    for(let i = 0; i < opcU.length; i++) {
        const input = opcU[i];
        document.getElementById(input.name).style.display = 'flex';
        maxUsab--;
        if(maxUsab == 0) {
            break;
        }
    }
    if(maxUsab > 0) {
        opcU = document.querySelectorAll('input:checked.OpcUsab[value="3"]');
        for(let i = 0; i < opcU.length; i++) {
            const input = opcU[i];
            document.getElementById(input.name).style.display = 'flex';
            maxUsab--;
            if(maxUsab == 0) {
                break;
            }
        }
    }
    if(maxUsab > 0) {
        opcU = document.querySelectorAll('input:checked.OpcUsab[value="1"]');
        for(let i = 0; i < opcU.length; i++) {
            const input = opcU[i];
            document.getElementById(input.name).style.display = 'flex';
            maxUsab--;
            if(maxUsab == 0) {
                break;
            }
        }
    }

}

function ObtenerTactica(id) {
    let tactica = '';
    switch(id) {
        case 'Disp1': tactica = "Ping / Echo"; break;
        case 'Disp2': tactica = "Monitor"; break;
        case 'Disp3': tactica = "Heartbeat"; break;
        case 'Disp4': tactica = "Time Stamp"; break;
        case 'Disp5': tactica = "Sanity Cheking"; break;
        case 'Disp6': tactica = "Exception Handling"; break;
        case 'Disp7': tactica = "Hardware Upgrade"; break;
        case 'Disp8': tactica = "Software Upgrade"; break;
        case 'Disp9': tactica = "Reconfiguration"; break;
        case 'Disp10': tactica = "Escalating Restart"; break;
        case 'Disp11': tactica = "Removal from Service"; break;
        case 'Disp12': tactica = "Predictive Model"; break;
        case 'Usab1': tactica = "Undo"; break;
        case 'Usab2': tactica = "Pause / Resume"; break;
        case 'Usab3': tactica = "Aggregate"; break;
        case 'Usab4': tactica = "Mantain Task Model"; break;
        case 'Usab5': tactica = "Mantain User Model"; break;
        case 'Usab6': tactica = "Mantain System Model"; break;
    }
    return tactica;
}


function ObtenerDescTactica(id) {
    let desc = '';
    switch(id) {
        case 'Disp1': 
            desc = "Consiste en realizar pruebas para verificar si los nodos de una red están activos y responden correctamente. Se mide el tiempo que tarda un mensaje en viajar entre nodos, lo que ayuda a evaluar la conectividad y el rendimiento de la red. Se utilizan programas para asegurarse de que los nodos estén disponibles y funcionando."; 
            break;
        case 'Disp2': 
            desc = "Es un sistema que supervisa el estado de diversas partes de un sistema, como la CPU, procesos, memoria, y entradas/salidas. Su objetivo es detectar problemas o congestiones, ejecutar auto-pruebas y detectar anomalías en el sistema."; 
            break;
        case 'Disp3': 
            desc = "Utiliza mensajes periódicos enviados por un sistema o componente para verificar si está funcionando correctamente. Permite detectar fallas a través de la ausencia de estos mensajes."; 
            break;
        case 'Disp4': 
            desc = "Utilizada para detectar secuencias de eventos incorrectas en sistemas de envío de mensajes distribuidos. Cada evento tiene un sello de tiempo asignado inmediatamente después de ocurrir, lo que permite ordenar y verificar la secuencia de eventos y detectar inconsistencias."; 
            break;
        case 'Disp5': 
            desc = "Consiste en verificar la validez lógica de operaciones específicas o salidas de un componente. Se utiliza principalmente en interfaces para asegurar que el flujo de información sea correcto, basándose en el conocimiento del diseño interno o el estado del sistema."; 
            break;
        case 'Disp6': 
            desc = "Se refiere al manejo de condiciones que alteran el flujo normal de ejecución del sistema. Cuando ocurre una excepción, el sistema detecta la falla y toma acciones correctivas, como enmascarar el error y restaurar la operación, para continuar con el proceso sin interrumpir su funcionamiento."; 
            break;
        case 'Disp7': 
            desc = "Implica la actualización o reemplazo de componentes de hardware dentro de un sistema para mejorar su rendimiento, capacidad o confiabilidad. Esta actualización se realiza para mitigar fallas, mejorar la eficiencia del sistema o cumplir con nuevas necesidades sin interrumpir significativamente las operaciones del sistema."; 
            break;
        case 'Disp8': 
            desc = "Consiste en actualizar el software de un sistema para mejorar sus funcionalidades, corregir errores, o mejorar la seguridad, sin interrumpir el funcionamiento general del sistema. Esto permite asegurar así una alta disponibilidad y continuidad operativa."; 
            break;
        case 'Disp9': 
            desc = "Consiste en redistribuir las funciones o responsabilidades dentro de un sistema cuando un componente falla, reasignando tareas a otros componentes funcionales para mantener el sistema en operación. Permite mejorar la resiliencia y la disponibilidad sin necesidad de interrumpir el servicio o realizar un reinicio completo."; 
            break;
        case 'Disp10': 
            desc = "Se basa en reiniciar componentes del sistema de forma progresiva, comenzando con los más pequeños o menos críticos, para minimizar el impacto y restaurar el servicio gradualmente."; 
            break;
        case 'Disp11': 
            desc = "Consiste en deshabilitar temporalmente un componente del sistema para corregir errores o prevenir fallas, asegurando que no afecte el funcionamiento general del sistema mientras se realizan ajustes."; 
            break;
        case 'Disp12': 
            desc = "Utiliza modelos predictivos junto con monitoreo del sistema para anticipar problemas y mantener el sistema dentro de parámetros de operación saludables, como el rendimiento de servidores o el uso de recursos."; 
            break;
        case 'Usab1': 
            desc = "Permite revertir una acción realizada, restaurando el sistema a su estado anterior. El sistema debe mantener suficiente información para realizar esta operación de manera eficiente."; 
            break;
        case 'Usab2': 
            desc = "Permite al usuario pausar una tarea larga y reanudarla más tarde, optimizando el uso de recursos mientras la tarea está en pausa."; 
            break;
        case 'Usab3': 
            desc = "Permite realizar operaciones en bloque sobre múltiples elementos a la vez, como aplicar un cambio a varios ítems simultáneamente, mejorando la eficiencia en tareas repetitivas."; 
            break;
        case 'Usab4': 
            desc = "El sistema mantiene un modelo del contexto de las tareas, lo que le permite actuar de manera adecuada y predecir las acciones o necesidades del usuario durante su interacción."; 
            break;
        case 'Usab5': 
            desc = "El sistema mantiene un modelo del usuario que refleja su conocimiento, comportamiento y preferencias, lo que permite personalizar la experiencia y ofrecer retroalimentación o sugerencias adaptadas a sus necesidades."; 
            break;
        case 'Usab6': 
            desc = "El sistema mantiene un modelo de sí mismo que le permite predecir el tiempo necesario para completar tareas y ajustarse según el comportamiento del usuario, proporcionando retroalimentación o sugerencias cuando sea necesario."; 
            break;
    }
    return desc;
}