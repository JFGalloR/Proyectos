<?php
// Configuración de la base de datos
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "GymTrainingClub";

// Crear conexión
$conn = new mysqli($servername, $username, $password, $dbname);

// Verificar conexión
if ($conn->connect_error) {
    die("Conexión fallida: " . $conn->connect_error);
}

// Consultar la tabla de miembros
$sql = "SELECT Id, Nombre, Apellidos, Fecha_Ins, Fecha_Val FROM Miembros";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // Salida de cada fila
    while($row = $result->fetch_assoc()) {
        echo "<tr>
                <td>" . $row["Id"] . "</td>
                <td>" . $row["Nombre"] . "</td>
                <td>" . $row["Apellidos"] . "</td>
                <td>" . $row["Fecha_Ins"] . "</td>
                <td>" . $row["Fecha_Val"] . "</td>
              </tr>";
    }
} else {
    // No output here, we will handle empty response in JavaScript
}

// Cerrar conexión
$conn->close();
?>
