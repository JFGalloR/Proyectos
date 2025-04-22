var req = 1;
var max = 14;

function Req(num) {

    if(num != req){
        let tit, desc;
        let aer = [true, true, true];

        document.querySelector('.Ant').style.display = 'block';
        document.querySelector('.Sig').style.display = 'block';

        switch(num){
            case 1:
                tit = 'Categorización de \n Usuarios';
                desc = 'Los usuarios se dividirán en tres categorías: escritores, revisores y un administrador único, cada uno con roles y privilegios ' + 
                'específicos y estos quedarán regiustrados en la base de datos, lo que garantiza un adecuado control de acceso y gestión de permisos y actividades.';
                document.querySelector('.Ant').style.display = 'none';
                break;
            case 2:
                tit = 'Sign Up de \n Usuario';
                desc = 'Se debe permitir el registro de cada tipo de usuario único (escritores, revisores y administrador único) mediante un formulario ' +
                'que solicite un nombre de usuario y una contraseña con verificación para su alta en la base de datos, garantizando la creación de cuentas ' +
                'individuales y seguras.';
                '\n\nExiste la particularidad de que una vez registrado un administrador, ya no se puede permitir registrar otro.';
                break;
            case 3:
                tit = 'Log In de \n Usuario';
                desc = 'Se requiere la autenticación segura que permita el ingreso de usuarios al sistema mediante un nombre de usuario y una contraseña ' + 
                'válidos, asegurando la privacidad y la protección de la información.' +
                '<br> Al ingresar, el sistema detectará el tipo de usuario que ingresa gracias al acceso en la base de datos.';
                break;
            case 4:
                tit = 'Subir y Descargar \n Archivos';
                desc = 'Todos los usuarios deben tener la capacidad de subir y descargar archivos dentro del sistema, para facilitar el intercambio de ' + 
                'información para revisión. <br> Tanto el autor al publicar su artículo, como el administrador y revisores para retoalimentar el documento.';
                break;
            case 5:
                tit = 'Asignación de Revisores \n a Artículos';
                desc = 'El administrador debe tener la capacidad de asignar revisores a los artículos publicados mediante un espacio donde se muestran todos ' + 
                'los artículos pendientes de revisar, asegurando una evaluación exhaustiva y objetiva de los trabajos por parte de expertos en el campo.';
                aer = [true, false, false];
                break;
            case 6:
                tit = 'Límite de Revisores \n por Artículo';
                desc = 'Al administrador se le debe establecer un límite máximo de tres revisores al momento de asignarlos a cada artículo presentado mediante un selector, ' +
                'garantizando una revisión equilibrada y representativa de los trabajos por parte de la comunidad académica. <br> Además debe contemplarse que al asignar, el sistema ' + 
                'no debe permitir que se asigne un revisor a un artículo de autoría del mismo. <br> Al realizarse la asignación, a lo revisores correspondientes les aparecerá dichas ' + 
                'revisionas a realizar.';
                aer = [true, false, false];
                break;
            case 7:
                tit = 'Selección de Artículos \n para Congreso';
                desc = 'El administrador debe tener la capacidad de seleccionar los artículos aprobados y revisados para ser presentados en congresos mediante la sección de artículos evaluados, ' +
                'asegurando la calidad y relevancia de los trabajos presentados en eventos académicos importantes.';
                aer = [true, false, false];
                break;
            case 8:
                tit = 'Posibilidad de \n ser Escritor';
                desc = 'El usuario administrador y el revisor tienen la opción de ser autores para contribuir con artículos sin tener la capacidad ' + 
                'de revisarlos, lo que promueve la participación activa de la comunidad académica en la plataforma.';
                aer = [true, false, true];
                break;
            case 9:
                tit = 'Límite de Artículos \n por Autor';
                desc = 'Los autores solo pueden presentar un máximo de tres artículos para ser considerados en el congreso, asegurando una representación ' +
                'equitativa de los trabajos presentados por cada autor.';
                aer = [false, true, false];
                break;
            case 10:
                tit = 'Publicación de \n Artículos';
                desc = 'El escritor será capaz de publicar sus artículos. Al realizar la captura del artículo a publicar se debe considerar: ' + 
                '<ul class="Lista"><li>Capturar el título del artículo.</li>' +
                '<li>Capturar el abstract de máximo 250 palabras.</li>' +
                '<li>Capturar tres keywords.</li>' +
                '<li>Capturar nombre, correo, intritución y teléfono de autor principal y coautores.</li>' +
                '<li>Se deberá especificar la categoría del artículo.</li>' +
                '<li>El espacio y botón para subir el archivo.</li></ul>' +
                'Recordando que se debe impedir que un autor o coautor tenga más de tres artículos colaborando y que solo se deba permitir el ingreso de tres en ambos casos al publicar el artículo.' +
                '<br><br>';
                aer = [false, true, false];
                break;
            case 11:
                tit = 'Categorización de \n Artículos por Tema';
                desc = 'Los artículos deben ser categorizados según su tema de estudio para facilitar su búsqueda y organización, lo que permite una gestión ' + 
                'eficiente de la información en la plataforma.';
                aer = [false, true, false];
                break;
            case 12:
                tit = 'Posibilidad de \n ser Revisor';
                desc = 'Los autores tienen la opción de registrarse como revisores para evaluar los artículos presentados por otros autores, promoviendo la ' +
                'colaboración y el intercambio de conocimientos entre la comunidad académica.';
                aer = [false, true, false];
                break;
            case 13:
                tit = 'Evaluación de \n de Artículos';
                desc = 'El revisor será capaz de revisar los artículos que se le hayan asignado. La evaluación del artículo será en una escala del 1 al 5 ' + 
                '(1 calificación alta, 5 calificación baja) y deberá responder:' +
                '<ol class="Lista"><li>¿Hay claridad en el propósito u objetivo de la investigación o del texto?</li>' +
                '<li>¿Se presentan datos de forma clara y ordenada, se informa su origen y se evidencia su relación con el texto?</li>' +
                '<li>En caso de que el texto incluya hipótesis, ¿éstas se encuentran explicitadas de manera clara y articuladas con la introducción y la teoría?</li>' +
                '<li>¿Hay precisión de las definiciones conceptuales? ¿Se evidencia rigor en la recolección de los datos? (sistematización).</li>' +
                '<li>¿Los resultados aportan conceptualización o contribuyen a resolver un problema?</li>' +
                '<li>¿El articulo sigue el formato APA?</li></ol>' +
                'Se deberá incluir un espacio de observaciones en cada punto para después mostrar el promedio de dicha evaluación. Además el resultado de ' +
                'la evaluación será regida por la siguiente correspondecia:<br><br>' +
                '<div class="Lista">( 1 ) Aceptado sin modificaciones <br>' +
                '( 2 ) Aceptado con modificaciones básicas <br>' +
                '( 3 ) Aceptado con modificaciones básicas y algunas de estructura <br>' +
                '( 4 ) Evaluar, reescribir contenidos y presentar a una próxima convocatoria para nueva evaluación <br>' +
                '( 5 ) No Aceptado <br><br></div>' +
                'Recordando que cada artículo solo puede revisarse un máximo de dos veces.' +
                '<br><br>';
                aer = [false, false, true];
                break;
            case 14:
                tit = 'Restricción para Revisar \n Artículos Propios';
                desc = 'Los revisores no pueden revisar los artículos que han presentado como autores, asegurando la imparcialidad y la objetividad en el ' + 
                'proceso de revisión de los trabajos.';
                aer = [false, false, true];
                document.querySelector('.Sig').style.display = 'none';
                break;
        }
        
        document.querySelector('.NumReq').innerText = num;
        document.querySelector('.TituloReq').innerText = tit;
        document.querySelector('.DescReq').innerHTML = desc;
        document.querySelector('.Admin').style.display = aer[0]? 'block' : 'none';
        document.querySelector('.Esc').style.display = aer[1]? 'block' : 'none';
        document.querySelector('.Rev').style.display = aer[2]? 'block' : 'none';
        document.querySelector('.Img').src = 'Imagenes/' + num + '.png';
        req = num;
    }

}

function Anterior() {
    if(req > 1) {
        Req(req - 1);
    }
}

function Siguiente() {
    if(req < max) {
        Req(req + 1);
    }
}