<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "GymTrainingClub";

header('Content-Type: application/json');

// Crear conexión
$conn = new mysqli($servername, $username, $password, $dbname);

// Verificar conexión
if ($conn->connect_error) {
    die(json_encode(['error' => 'Conexión fallida: ' . $conn->connect_error]));
}

if (isset($_POST['Id']) && isset($_POST['Name']) && isset($_POST['LastName']) && isset($_POST['Inscripcion']) && isset($_POST['Validez'])) {
    $id = $_POST['Id'];
    $name = $_POST['Name'];
    $lastName = $_POST['LastName'];
    $inscripcion = $_POST['Inscripcion'];
    $validez = $_POST['Validez'];
    
    $sql = "UPDATE Miembros SET Nombre='$name', Apellidos='$lastName', Fecha_Ins='$inscripcion', Fecha_Val='$validez' WHERE Id='$id'";
    if ($conn->query($sql) === TRUE) {
        echo json_encode(['success' => '✅ Registro actualizado correctamente ✅']);
    } else {
        echo json_encode(['error' => '❌ Error actualizando el registro: ' . $conn->error]);
    }
}

$conn->close();
?>
