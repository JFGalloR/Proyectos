moment.locale('es');

mostrarHoraYFecha();

setInterval(mostrarHoraYFecha, 1000);

function mostrarHoraYFecha() {

    document.getElementById('Hour').textContent = moment().format('hh:mm a');
    document.getElementById('Date').textContent = moment().format('D MMMM YYYY');

}