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

if (isset($_POST['Id'])) {
    $id = $_POST['Id'];
    
    $sql = "DELETE FROM Miembros WHERE Id='$id'";
    if ($conn->query($sql) === TRUE) {
        echo json_encode(['success' => '✅ Registro eliminado correctamente ✅']);
    } else {
        echo json_encode(['error' => '❌ Error eliminando el registro: ' . $conn->error]);
    }
}

$conn->close();
?>
