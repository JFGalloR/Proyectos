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
    $sql = "SELECT * FROM Miembros WHERE id='$id'";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        $member = $result->fetch_assoc();
        echo json_encode($member);
    } else {
        echo json_encode(['error' => '❌ Miembro no encontrado ❌']);
    }
}

$conn->close();
?>
